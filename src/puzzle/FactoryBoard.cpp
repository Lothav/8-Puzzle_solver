#include "FactoryBoard.hpp"

namespace puzzle
{
    bool FactoryBoard::checkBoardIsSolved(const std::array<std::array<char, 3>, 3>& state)
    {
        bool solved = true;

        for (ushort i = 0; i < 3; i++)
        {
            for (ushort j = 0; j < 3; j++)
            {
                // Check last character.
                if(i == 2 && j == 2)
                {
                    solved = state[i][j] == ' ';
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

    std::array<ushort, 2> FactoryBoard::getEmptyPosition(const std::array<std::array<char, 3>, 3>& state)
    {
        for (ushort i = 0; i < 3; i++)
            for (ushort j = 0; j < 3; j++)
                if(state[i][j] == ' ')
                    return std::array<ushort, 2>{i, j};

        throw "Board has no empty tile!";
    }

    std::unique_ptr<Board> FactoryBoard::create(const std::array<std::array<char, 3>, 3>& state)
    {
        return std::make_unique<Board>(state, checkBoardIsSolved(state), getEmptyPosition(state));
    }
}
