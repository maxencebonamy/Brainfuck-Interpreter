#include "interpreter.hpp"


Interpreter::Interpreter(std::string instructions) noexcept :
    _instructions(std::move(instructions))
{}


bool Interpreter::checkInstructionsValidity() const noexcept {
    // Variable that will count the scopes formed by the brackets
    int scopesCount { 0 };

    for (char c : _instructions) {
        // Increase the variable when a scope is open
        if (c == '[') {
            scopesCount++;
        }
        // Decrease the variable when a scope is closed
        else if (c == ']') {
            scopesCount--;
        }
        // If the variable is negative, it means that a non-existing scope has been closed,
        // so the program is not valid
        if (scopesCount < 0) {
            return false;
        }
    }

    // The program is valid only if the number of scopes still open is 0
    return scopesCount == 0;
}


void Interpreter::run() {
    // Variable that will store the index of the insctruction to execute (program counter)
    std::size_t pc { 0 };

    // The program is executed as long as this variable has not yet reached the end
    while (pc != _instructions.size()) {
        // Retrieval of the instruction corresponding to the program counter
        char instruction = _instructions[pc];

        // Left shift
        if (instruction == '<') {
            _table.leftShift();
        }
        // Right Shift
        else if (instruction == '>') {
            _table.rightShift();
        }
        // Decrementation
        else if (instruction == '-') {
            _table.decrement();
        }
        // Incrementation
        else if (instruction == '+') {
            _table.increment();
        }
        // Print
        else if (instruction == '.') {
            _table.print();
        }
        // Input
        else if (instruction == ',') {
            _table.input();
        }
        // Start of a scope
        else if (instruction == '[') {
            _stack.push(pc);
        }
        // End of a scope
        else if (instruction == ']') {
            if (_table.isNull()) {
                // End of the scope
                _stack.pop();
            }
            else {
                // Back to the beginning of the scope
                pc = _stack.top();
            }
        }

        // Incrementation of the program counter
        ++pc;
    }
}