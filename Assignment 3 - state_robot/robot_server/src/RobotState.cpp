#include <cstring>
#include <stdexcept>
#include <string>
#include <vector>
#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <algorithm> 
#include <unistd.h>

#include "RobotState.h"
#include "Message.h"

void :: Tickable :: tick(const small_world :: SM_Event &event)
{
    uint64_t lastTickTime = event.event_time();
    
}

void :: StateMachine :: tick(const small_world :: SM_Event &event)
{
    Tickable :: tick(event);
    if(current_state != nullptr) current_state->tick(event);
}

void :: StateMachine :: set_current_state(std :: shared_ptr<RobotState> cs)
{    
    current_state = cs;
}

uint64_t :: RobotState :: get_elapsed()
{
    return current_time - initial_time;
}

void :: RobotState :: set_next_state(const std :: string & state_name, std :: shared_ptr<RobotState> state)
{
    next_states[state_name] = state;
}

std::shared_ptr<RobotState> RobotState::get_next_state(const std::string & transition_name)
{
    std::map<std::string, std::shared_ptr<RobotState>>::iterator it = next_states.find(transition_name);
    if (it == next_states.end()) return nullptr;
    return it->second;
}

void :: RobotState :: tick(const small_world :: SM_Event & e)
{
    if(initial_time == 0)
    {
        initial_time = e.event_time();
    }
    current_time = e.event_time();
    decide_action(get_elapsed());
}

void :: RobotState :: decide_action(uint64_t duration)
{
    if(duration < time_to_wait)
    {
        std :: cout << verb_name << std :: endl;
        return;
    }
    std :: shared_ptr <RobotState> next = get_next_state("done");
    initial_time = 0;
    std :: cout << done_name << std :: endl;
    if(next == nullptr)
    {
        std :: cout << "Can't get a next state to go to" << std :: endl;
        return;
    }
    std :: cout << next->state_name << std :: endl;
    owner->set_current_state(next);
}

void :: RobotState :: set_name(std :: string name)
{
    state_name = name;
}

void :: RobotState :: set_verb(std :: string verb)
{
    verb_name = verb;
}

void :: RobotState :: set_done(std :: string done)
{
    done_name = done;
}   

void :: RobotState :: set_owner(std :: shared_ptr<StateMachine> newOwner)
{
    owner = newOwner; 
}