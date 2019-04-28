#ifndef INC_8_PUZZLE_SOLVER_FACTORYTABLE_HPP
#define INC_8_PUZZLE_SOLVER_FACTORYTABLE_HPP

#include "Board.hpp"
#include <memory>

namespace puzzle
{
    class FactoryBoard
    {
    public:

        static std::unique_ptr<Board> create(const std::array<std::array<char, 3>, 3>& state);

    private:

        static uint32_t manhattanDistanceToFinalState(const std::array<std::array<char, 3>, 3>& state);
        static std::array<ushort, 2> getEmptyPosition(const std::array<std::array<char, 3>, 3>& state);
        static bool checkBoardIsSolved(const std::array<std::array<char, 3>, 3>& state);
    };
}


#endif //INC_8_PUZZLE_SOLVER_FACTORYTABLE_HPP
