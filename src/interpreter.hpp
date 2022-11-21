#pragma once

#include "table.hpp"
#include <stack>


class Interpreter {

public:
    /**
     * @brief Constructor
     * @param instructions Instructions that make up the program in string form
     */
    explicit Interpreter(std::string instructions) noexcept;

    // No copying or moving -> Rule of fives
    Interpreter(const Interpreter&) = delete;
    Interpreter(Interpreter&&) = delete;
    Interpreter& operator=(const Interpreter&) = delete;
    Interpreter& operator=(Interpreter&&) = delete;
    ~Interpreter() = default;

    /**
     * @brief Checks if the program is correct
     * @return True only if the program is correct
     * @post The program can be started without an error being thrown
     */
    bool checkInstructionsValidity() const noexcept;

    /**
     * @brief Run the program
     * @pre The program must be correct
     */
    void run();

private:
    // Instructions thet make up the program (1 char = 1 instruction)
    std::string _instructions;

    // Table that represents the memory
    Table _table;

    // Stack of the scopes created by the brackets
    std::stack<std::size_t> _stack;

};
