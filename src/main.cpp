#include "parser.hpp"
#include "interpreter.hpp"


int main(int argc, char* argv[]) {
    // Case where no file has been specified
    if (argc == 1) {
        std::cout << "Error: You must specify the program file.\n";
        return 1;
    }

    // Case where too many arguments have been specified
    if (argc > 2) {
        std::cout << "Error: You must specify only one program file.\n";
        return 1;
    }

    // Creation of the parser
    Parser parser { argv[1] };

    // Verification of file opening
    if (!parser.load()) {
        std::cout << "Error: Failed to open this file.\n";
        return 1;
    }

    // Creation of the interpreter
    Interpreter interpreter { parser.getInstructions() };

    // Checking the validity of the program
    if (!interpreter.checkInstructionsValidity()) {
        std::cout << "Error: Program is not correct.\n";
        return 1;
    }

    // Launching the program when it is correct
    interpreter.run();

    return 0;
}
