#include "parser.hpp"


Parser::Parser(std::string filePath) noexcept :
    _filePath(std::move(filePath))
{}

bool Parser::load() {
    // Stream that will be used to open the file
    std::ifstream file;

    // Opening the file containing the program
    file.open(_filePath);

    if (file.is_open() ) {
        char c;
        // Loop that runs through the file
        while (file) {
            c = static_cast<char>(file.get());
            // Adds the character to the instructions after checking that it is indeed an instruction
            if (_isInstruction(c)) {
                _instructions += c;
            }
        }
        return true;
    }

    // If the file could not be opened, returns false
    return false;
}

const std::string& Parser::getInstructions() const {
    return _instructions;
}

bool Parser::_isInstruction(char c) {
    // If the character is not in the string of instructions,
    // this results in the index found being the constant std::string::npos
    return ALL_INSTRUCTIONS.find(c) != std::string::npos;
}

// All possible instructions in brainfuck
const std::string Parser::ALL_INSTRUCTIONS { "<>-+.,[]" };