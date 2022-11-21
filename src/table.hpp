#pragma once

#include <array>
#include <memory>
#include <iostream>


class Table {

public:
    /**
     * @brief Default Constructor
     */
    Table() noexcept;

    // No copying or moving -> Rule of fives
    Table(const Table&) = delete;
    Table(Table&&) = delete;
    Table& operator=(const Table&) = delete;
    Table& operator=(Table&&) = delete;
    ~Table() = default;

    /**
     * @brief Shift the pointer to the left (back to the last cell if necessary)
     */
    void leftShift() noexcept;

    /**
     * @brief Shift the pointer to the right (back to the first cell if necessary)
     */
    void rightShift() noexcept;

    /**
     * @brief Decrements the value stored in the cell pointed to by the pointer
     */
    void decrement() noexcept;

    /**
     * @brief Increments the value stored in the cell pointed to by the pointer
     */
    void increment() noexcept;

    /**
     * @brief Displays the ASCII character stored in the cell pointed to by the pointer
     */
    void print() noexcept;

    /**
     * @brief Stores the ASCII character entered by the user in the cell pointed to by the pointer
     */
    void input();

    /**
     * @brief Check if the value in the cell pointed by the pointer is null
     * @return True only if the value is equal to 0
     */
    bool isNull() noexcept;

private:
    // Table of 30,000 cells (Represents the memory)
    std::array<std::uint8_t, 30'000> _table;

    // Pointer to the current cell in the table
    std::uint8_t* _ptr;

};
