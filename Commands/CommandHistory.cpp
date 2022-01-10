#include "CommandHistory.h"

CommandHistory::CommandHistory() {

}

void CommandHistory::push(Command* command) {
    s.push(command);
}

void CommandHistory::pop() {
    if (s.empty()) {
        return;
    }

    Command* command = s.top();
    s.pop();
    command->unexecute();
}

void CommandHistory::reset() {
    while(!s.empty()) {
        s.pop();
    }
}
