#pragma once

#include <string>
#include <fstream>
#include <iostream>
#include <stack>


class Parser {

public:
    /**
     * @brief Constructor
     * @param filePath Path of the file containing the brainfuck program
     */
    explicit Parser(std::string filePath) noexcept;

    // No copying or moving -> Rule of fives
    Parser(const Parser&) = delete;
    Parser(Parser&&) = delete;
    Parser& operator=(const Parser&) = delete;
    Parser& operator=(Parser&&) = delete;
    ~Parser() = default;

    /**
     * @brief Loading the file and injecting the instructions in the corresponding attribute
     * @return True only if the file has been opened, so false in case of error
     * @post The instructions have been loaded correctly
     */
    bool load();

    /**
     * @brief Returns the instructions that make up the pogram
     * @return The instructions of the program in string form
     * @pre The instructions must be loaded correctly, otherwise they will be empty
     */
    const std::string& getInstructions() const noexcept;

private:
    /**
     * @brief Check if a character matches a brainfuck instruction
     * @param c Char that will be checked
     * @return True only if the character corresponds to a brainfuck instruction
     */
    static bool _isInstruction(char c) noexcept ;

    // All possible instructions in brainfuck
    static const std::string ALL_INSTRUCTIONS;

    // Path to the file containing the brainfuck program
    std::string _filePath;

    // Instructions that make up the program
    std::string _instructions;

};
