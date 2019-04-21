//
// Created by luiz0tavio on 4/20/19.
//

#ifndef INC_8_PUZZLE_SOLVER_BOARD_HPP
#define INC_8_PUZZLE_SOLVER_BOARD_HPP

#include <array>
#include <memancpp/Provider.hpp>

namespace puzzle
{
    class Board
    {

    private:

        std::array<std::array<char, 3>, 3> state_ = {};
        bool is_solved_ = false;

    public:

        Board(const std::array<std::array<char, 3>, 3>& state, bool is_solved) : state_(state), is_solved_(is_solved) {};

        void* operator new(std::size_t size)
        {
            return mem::Provider::getMemory(size);
        }

        void operator delete(void* ptr)
        {
            // Do not free memory here!
        }

        bool isSolved() const
        {
            return is_solved_;
        }

    };
}

#endif //INC_8_PUZZLE_SOLVER_BOARD_HPP
