//
// Created by luiz0tavio on 4/20/19.
//

#ifndef INC_8_PUZZLE_SOLVER_TABLE_HPP
#define INC_8_PUZZLE_SOLVER_TABLE_HPP

#include <array>
#include <memancpp/Provider.hpp>

namespace solver
{
    class Table
    {

    private:

        std::array<std::array<char, 3>, 3> state_;

    public:

        explicit Table(std::array<std::array<char, 3>, 3>&& initial_state) : state_(initial_state) {}

        void* operator new(std::size_t size)
        {
            return mem::Provider::getMemory(size);
        }

        void operator delete(void* ptr)
        {
            // Do not free memory here!
        }

        bool isSolved()
        {
            for (int i = 0; i < 3; ++i)
                for (int j = 0; j < 3; ++j)
                {
                    // Check last character.
                    if(i == 2 && j == 2 && state_[i][j] != ' ')
                        return false;

                    // Check 1 to 8 numbers in table.
                    auto step_number = (char)('0' + (i*3) + j + 1);
                    if(state_[i][j] != step_number)
                        return false;
                }

            // Table is solved.
            return true;
        }

    };
}

#endif //INC_8_PUZZLE_SOLVER_TABLE_HPP
