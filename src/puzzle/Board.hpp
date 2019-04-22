#ifndef INC_8_PUZZLE_SOLVER_BOARD_HPP
#define INC_8_PUZZLE_SOLVER_BOARD_HPP

#include <vector>
#include <memory>
#include <memancpp/Pool.hpp>
#include <sstream>

namespace puzzle
{
    class Board
    {

    private:

        static std::unique_ptr<mem::Pool<Board>> pool_;

        std::array<std::array<char, 3>, 3> state_ = {};
        bool is_solved_ = false;
        std::array<ushort, 2> empty_pos_ = {0, 0};

    public:

        Board(const std::array<std::array<char, 3>, 3>& state, bool is_solved, std::array<ushort, 2> empty_pos)
            : state_(state), is_solved_(is_solved), empty_pos_(empty_pos) {};

        void* operator new(std::size_t size);
        void operator delete(void* ptr);

        bool isSolved() const;
        std::string toString(const std::string& id = "") const;
        std::vector<std::unique_ptr<Board>> getAllowedMoves() const;
    };
}

#endif //INC_8_PUZZLE_SOLVER_BOARD_HPP
