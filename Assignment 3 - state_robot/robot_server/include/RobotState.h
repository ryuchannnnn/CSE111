#pragma once

#include <cstring>
#include <stdexcept>
#include <string>
#include <vector>
#include <algorithm> 
#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

using namespace std;
#include "Message.h"

class RobotState;

class Tickable
{
    uint64_t lastTickTime;
    public:
        virtual void tick(const small_world :: SM_Event &event);
};


class StateMachine : public Tickable
{
    std :: shared_ptr <RobotState> current_state;
    public: 
        virtual void tick(const small_world :: SM_Event &event);
        virtual void set_current_state(std :: shared_ptr<RobotState> cs);
};

class RobotState
{
    public: 
        uint64_t initial_time = 0;
        uint64_t current_time = 0;
        std :: map <std :: string, std:: shared_ptr <RobotState>> next_states;
        std::shared_ptr<StateMachine> owner;
        uint64_t get_elapsed();
        void set_next_state(const std :: string & state_name, std::shared_ptr<RobotState> state);
        std::shared_ptr<RobotState> get_next_state(const std :: string &transition_name);
        virtual void tick(const small_world :: SM_Event &e);
        void decide_action(uint64_t duration);

        // time state
        std :: string done_name;
        std :: string state_name;
        std :: string verb_name;
        uint64_t time_to_wait = 30000;

        // make func 
        void set_name(std :: string name);
        void set_verb(std :: string verb);
        void set_done(std :: string done);
        void set_owner(std :: shared_ptr<StateMachine> newOwner);

};