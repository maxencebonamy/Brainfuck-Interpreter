#include "table.hpp"


Table::Table() noexcept :
    _table(),
    _ptr(_table.data())
{
    // Initialization of the cells to 0
    for (std::size_t i { 0 }; i < _table.size(); ++i) {
        _table[i] = 0;
    }
}


void Table::leftShift() noexcept {
    // If the pointer points to the first cell, it will point to the last one
    if (_ptr == _table.data()) {
        _ptr += _table.size() - 1;
    }
    // Shifting the pointer to the left
    else {
        --_ptr;
    }
}


void Table::rightShift() noexcept {
    // If the pointer points to the last cell, it will point to the first one
    if (_ptr == _table.data() + _table.size() - 1) {
        _ptr = _table.data();
    }
    // Shifting the pointer to the right
    else {
        ++_ptr;
    }
}

void Table::decrement() noexcept {
    --(*_ptr);
}

void Table::increment() noexcept {
    ++(*_ptr);
}

void Table::print() noexcept {
    // Displays the character associated with the value stored in the current cell in relation to the ASCII table
    std::cout << static_cast<char>(*_ptr);
}

void Table::input() {
    std::cout << "\n>>> ";
    std::cin.clear();
    std::string content;
    std::cin >> content;

    // Displays an error as long as the player has not entered a single character
    if (content.size() != 1) {
        std::cout << "Error: Input must contain one single character.\n";
        input();
    }
    else {
        *_ptr = static_cast<std::uint8_t>(content[0]);
    }
}

bool Table::isNull() noexcept {
    return *_ptr == 0;
}
