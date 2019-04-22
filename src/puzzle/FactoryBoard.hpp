#ifndef INC_8_PUZZLE_SOLVER_FACTORYTABLE_HPP
#define INC_8_PUZZLE_SOLVER_FACTORYTABLE_HPP

#include "Board.hpp"
#include <memory>

namespace puzzle
{
    class FactoryBoard
    {
    public:

        static std::unique_ptr<Board> create(const std::array<std::array<char, 3>, 3>& state)
        {
            return std::make_unique<Board>(state, checkBoardIsSolved(state), getEmptyPosition(state));
        }

    private:

        static std::array<ushort, 2> getEmptyPosition(const std::array<std::array<char, 3>, 3>& state)
        {
            for (ushort i = 0; i < 3; i++)
                for (ushort j = 0; j < 3; j++)
                    if(state[i][j] == ' ')
                        return std::array<ushort, 2>{i, j};

            throw "Board has no empty tile!";
        }

        static bool checkBoardIsSolved(const std::array<std::array<char, 3>, 3>& state)
        {
            bool solved = true;

            for (ushort i = 0; i < 3; i++)
            {
                for (ushort j = 0; j < 3; j++)
                {
                    // Check last character.
                    if(i == 2 && j == 2 && state[i][j] != ' ')
                    {
                        solved = false;
                        break;
                    }

                    // Check 1 to 8 numbers in table.
                    auto step_number = (char)('0' + (i*3) + j + 1);
                    if(state[i][j] != step_number)
                    {
                        solved = false;
                        break;
                    }
                }

                if(!solved) break;
            }

            return solved;
        }

    };
}


#endif //INC_8_PUZZLE_SOLVER_FACTORYTABLE_HPP
