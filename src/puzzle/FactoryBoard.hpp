#ifndef INC_8_PUZZLE_SOLVER_FACTORYTABLE_HPP
#define INC_8_PUZZLE_SOLVER_FACTORYTABLE_HPP

#include <memory>
#include "Board.hpp"
#include "solve/Heuristics.hpp"

namespace puzzle
{
    class FactoryBoard
    {
    public:

        FactoryBoard() = delete;

        static std::unique_ptr<Board> create(const std::array<std::array<char, 3>, 3>& state, uint32_t flags = 0);

    private:

        static std::array<ushort, 2> getEmptyPosition(const std::array<std::array<char, 3>, 3>& state);
        static bool checkBoardIsSolved(const std::array<std::array<char, 3>, 3>& state);
    };
}


#endif //INC_8_PUZZLE_SOLVER_FACTORYTABLE_HPP
