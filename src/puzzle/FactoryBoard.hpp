//
// Created by luiz0tavio on 4/20/19.
//

#ifndef INC_8_PUZZLE_SOLVER_FACTORYTABLE_HPP
#define INC_8_PUZZLE_SOLVER_FACTORYTABLE_HPP

#include "Board.hpp"
#include <memory>

namespace puzzle
{
    class FactoryBoard
    {
        static std::unique_ptr<Board> create(std::array<std::array<char, 3>, 3>&& state)
        {
            bool solved = true;

            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
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

            return std::make_unique<Board>(std::move(state), solved);
        }
    };
}


#endif //INC_8_PUZZLE_SOLVER_FACTORYTABLE_HPP
