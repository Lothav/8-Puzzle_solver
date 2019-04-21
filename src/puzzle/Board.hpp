//
// Created by luiz0tavio on 4/20/19.
//

#ifndef INC_8_PUZZLE_SOLVER_BOARD_HPP
#define INC_8_PUZZLE_SOLVER_BOARD_HPP

#include <vector>
#include <memory>
#include <memancpp/Provider.hpp>

namespace puzzle
{
    class Board
    {

    private:

        std::array<std::array<char, 3>, 3> state_ = {};
        bool is_solved_ = false;
        std::array<ushort, 2> empty_pos_ = {0, 0};

    public:

        Board(const std::array<std::array<char, 3>, 3>& state, bool is_solved, std::array<ushort, 2> empty_pos)
            : state_(state), is_solved_(is_solved), empty_pos_(empty_pos) {};

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

        std::vector<std::unique_ptr<Board>> getAllowedMoves() const;

    };
}

#endif //INC_8_PUZZLE_SOLVER_BOARD_HPP
