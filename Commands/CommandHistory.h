#ifndef COMMANDHISTORY_H
#define COMMANDHISTORY_H

#include <stack>

#include "Command.h"

class CommandHistory {
    private:
        std::stack<Command*> s;

    public:
        CommandHistory();
        void push(Command* command);
        void pop();
        void reset();
};

#endif
