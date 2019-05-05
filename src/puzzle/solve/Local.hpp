#ifndef INC_8_PUZZLE_SOLVER_LOCAL_HPP
#define INC_8_PUZZLE_SOLVER_LOCAL_HPP

#include <array>
#include <Board.hpp>
#include <FactoryBoard.hpp>

namespace puzzle
{
    namespace solve
    {
        class Local
        {

        public:

            static void HillClimbing(std::array<std::array<char, 3>, 3> initial_state, uint32_t k = 8);

        };
    }
}

#endif //INC_8_PUZZLE_SOLVER_LOCAL_HPP
