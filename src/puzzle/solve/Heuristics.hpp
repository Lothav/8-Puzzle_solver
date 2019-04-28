#ifndef INC_8_PUZZLE_SOLVER_HEURISTICS_HPP
#define INC_8_PUZZLE_SOLVER_HEURISTICS_HPP

#include <array>

namespace puzzle
{
    namespace solve
    {
        enum HeuristicsFlags
        {
            MANHATTAN_DISTANCE_TO_FINAL_STATE = 1 << 0,
            TILES_OUT_OF_PLACE                = 1 << 1,
        };

        class Heuristics
        {

        public:

            static uint32_t ManhattanDistanceToFinalState(const std::array<std::array<char, 3>, 3>& state);
            static uint32_t TilesOutOfPlace(const std::array<std::array<char, 3>, 3>& state);
        };
    }
}

#endif //INC_8_PUZZLE_SOLVER_HEURISTICS_HPP
