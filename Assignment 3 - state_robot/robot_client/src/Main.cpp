#include <iostream>

#include <string.h>   //strlen 
#include <stdlib.h> 
#include <errno.h> 
#include <unistd.h>   //close 
#include <arpa/inet.h>    //close 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <netinet/in.h> 
#include <sys/time.h> //FD_SET, FD_ISSET, FD_ZERO macros 

#include <chrono>
#include <cstdint>

#include "Message.h"

#define TRUE   1 
#define FALSE  0 
#define PORT 8888 
    
uint64_t timeSinceEpochMillisec()
{
    using namespace std::chrono;
    return duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
}

int main(int argc, char const* argv[])
{

    small_world :: SM_Event sm1;

    sm1.set_event_type("tick");
    sm1.set_event_time(timeSinceEpochMillisec());

    std :: string binary;
    sm1.SerializeToString(&binary);


    int status, valread, client_fd;
    struct sockaddr_in serv_addr;
    std::string hello("Hello from client");

    char buffer[1024] = { 0 };
    if ((client_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
	    std::cout << "\n Socket creation error \n" << std::endl;
        return -1;
    }
  
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
  
    // Convert IPv4 and IPv6 addresses from text to binary
    // form
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)
        <= 0) {
        std::cout <<  
            "\nInvalid address/ Address not supported \n" << std::endl;
        return -1;
    }
  
    if ((status
         = connect(client_fd, (struct sockaddr*)&serv_addr,
                   sizeof(serv_addr)))
        < 0) {
	    std::cout << "\nConnection Failed \n" << std::endl;
        return -1;
    }
    send(client_fd, hello.c_str(), hello.length(), 0);
    std::cout << "Hello message sent\n" << std::endl;
    valread = read(client_fd, buffer, 1024);
    std::cout << "%s\n" << buffer << std::endl;

    while(true)
    {
        usleep(500000);
        send(client_fd, binary.c_str(), binary.length(), 0);
        sm1.set_event_time(timeSinceEpochMillisec());
        sm1.SerializeToString(&binary);
    }
    
    // closing the connected socket
    close(client_fd);

    std::cout << "not connected anymore" << std::endl;

    return 0;
}
