
#include <iostream>
#include <fstream>
#include <string>  

#include <stdlib.h> 
#include <errno.h> 
#include <unistd.h>    

#include <arpa/inet.h>     
#include <sys/types.h> 
#include <sys/socket.h> 
#include <netinet/in.h> 
#include <sys/time.h> //FD_SET, FD_ISSET, FD_ZERO macros 

#include <chrono>
#include <cstdint>

#include "Message.h"
#include "RobotState.h"

#define PORT 8888 

uint64_t timeSinceEpochMillisec()
{
    using namespace std::chrono;
    return duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
}

int main(int argc, char * argv[]) {
	// use these strings to indicate the state transitions
	// the robot progresses through.  Do not modify these strings

	std::string robot_waiting = "The robot is waiting";
	std::string robot_moving = "The robot is moving";

	std::string robot_finished_waiting = "The robot finished waiting";
	std::string robot_finished_moving = "The robot finished moving";

	std::string robot_began_waiting = "The robot began waiting";
	std::string robot_began_moving = "The robot began moving";

    std :: shared_ptr<StateMachine> sm (new StateMachine);

    std:: shared_ptr<RobotState> s0 = std :: make_shared<RobotState>();

    s0->set_name(robot_began_waiting);
    s0->set_verb(robot_waiting);
    s0->set_owner(sm);
    s0->set_done(robot_finished_waiting);

    std:: shared_ptr<RobotState> s1 = std :: make_shared<RobotState>();

    s1->set_name(robot_began_moving);
    s1->set_verb(robot_moving);
    s1->set_owner(sm);
    s1->set_done(robot_finished_moving);

    s0->set_next_state("done", s1);
    s1->set_next_state("done", s0);

    sm->set_current_state(s0);

    small_world :: SM_Event sm2; 
    std :: string binary;

	int opt = true;
    int master_socket, addrlen, new_socket, client_socket[30], 
          max_clients = 30, activity, valread, sd;  
    int max_sd;  
    struct sockaddr_in address;  
         
    char buffer[1025];  //data buffer of 1K + one byte for a NUL terminator  
        
    std::cout << "robot server running on port : " << PORT << std::endl;
    // std::cout << "Use telnet localhost " << PORT << " to connect" << std::endl;
    // std::cout << "If connecting from outside the VM, you will need another port fwd" << std::endl;

    // set of socket descriptors 
    fd_set readfds;  
         
    std::string message = "Hello from robot server";  
     
    // initialise all of the client_socket[] array to 0 (not checked) 
    for (size_t i = 0; i < max_clients; i++)  
    {  
        client_socket[i] = 0;  
    }  
         
    //create a master socket 
    if( (master_socket = socket(AF_INET , SOCK_STREAM , 0)) == 0)  
    {  
	std::cerr << "socket failed" << std::endl;  
        exit(EXIT_FAILURE);  
    }  
     
    //set master socket to allow multiple connections , 
    //this is just a good habit, it will work without this 
    if( setsockopt(master_socket, SOL_SOCKET, SO_REUSEADDR, (char *)&opt, 
          sizeof(opt)) < 0 )  
    {  
	std::cerr << "setsockopt" << std::endl;  
        exit(EXIT_FAILURE);  
    }  
     
    //type of socket created 
    address.sin_family = AF_INET;  
    address.sin_addr.s_addr = INADDR_ANY;  
    address.sin_port = htons( PORT );  
         
    //bind the socket to localhost port 8888 
    if (bind(master_socket, (struct sockaddr *)&address, sizeof(address))<0)  
    {  
	std::cerr << "bind failed" << std::endl;  
        exit(EXIT_FAILURE);  
    }  
    
    std::cout << "Listener on port : " << PORT << std::endl;  
         
    // specify a maximum of 3 pending connections for the master socket 
    if (listen(master_socket, 3) < 0)  
    {  
	std::cerr << "error listening" << std::endl;  
        exit(EXIT_FAILURE);  
    }  
         
    addrlen = sizeof(address);  
    std::cout << "Waiting for connections ..." << std::endl;  
         
    while(true)  
    {  
        //clear the socket set 
        FD_ZERO(&readfds);  
     
        //add master socket to set 
        FD_SET(master_socket, &readfds);  
        max_sd = master_socket;  
             
        //add child sockets to set 
        for (size_t i = 0 ; i < max_clients ; i++)  
        {  
            //socket descriptor 
            sd = client_socket[i];  
                 
            //if valid socket descriptor then add to read list 
            if(sd > 0)  
                FD_SET( sd , &readfds);  
                 
            //highest file descriptor number, need it for the select function 
            if(sd > max_sd)  
                max_sd = sd;  
        }  
     
        //wait for an activity on one of the sockets , timeout is NULL , 
        //so wait indefinitely 
        activity = select( max_sd + 1 , &readfds , NULL , NULL , NULL);  
       
        if ((activity < 0) && (errno!=EINTR))  
        {  
		std::cout << "select error" << std::endl;
        }  
             
        // If something happened on the master socket , 
        // then its an incoming connection 
        if (FD_ISSET(master_socket, &readfds))  
        {  
            if ((new_socket = accept(master_socket, 
                    (struct sockaddr *)&address, (socklen_t*)&addrlen))<0)  
            {  
		std::cout << "accept error" << std::endl;  
                exit(EXIT_FAILURE);  
            }  
             
            //inform user of socket number - used in send and receive commands 
	    std::cout << "New connection , socket fd, ip port " 
                  << new_socket  << "," << inet_ntoa(address.sin_addr)  << ntohs(address.sin_port) << std::endl;  
          
	    // convert std::string to char * 
	    char * cstr = message.data();

            //send new connection greeting message 
            if( send(new_socket, cstr, message.size(), 0) != message.size() )  
            {  
                std::cout << " error sending" << std::endl;  
            }  
                 
	    std::cout << "Welcome message sent successfully" << std::endl;  
                 
            //add new socket to array of sockets 
            for (size_t i = 0; i < max_clients; i++)  
            {  
                //if position is empty 
                if( client_socket[i] == 0 )  
                {  
                    client_socket[i] = new_socket;  
		    std::cout << "Adding to list of sockets as : " << i << std::endl;
                    break;  
                }  
            }  
        }  
             
        // It is some sort of IO operation on some other socket
        for (size_t i = 0; i < max_clients; i++)  
        {  
            sd = client_socket[i];  
                 
            if (FD_ISSET( sd , &readfds))  
            {  
                // Check if it was closing and also read the incoming message 
                if ((valread = read( sd , buffer, 1024)) == 0)  
                {  
                    //Somebody disconnected, get their details and print 
                    getpeername(sd , (struct sockaddr*)&address , \
                        (socklen_t*)&addrlen);  
		    std::cout << "Host disconnected :"  
                          << inet_ntoa(address.sin_addr) << "," << ntohs(address.sin_port) << std::endl;    
            
                    // Close the socket and mark as 0 in list for reuse 
                    close( sd );  
                    client_socket[i] = 0;  
                }
                binary = buffer;
                sm2.ParseFromString(binary);
                // std :: cout << sm2.event_time() << std :: endl;
                sm->tick(sm2);
            }  
        }  
    }  
         
    return EXIT_SUCCESS;  
}

