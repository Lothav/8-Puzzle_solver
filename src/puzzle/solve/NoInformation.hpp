#ifndef INC_8_PUZZLE_SOLVER_BREADTHFIRSTSEARCH_HPP
#define INC_8_PUZZLE_SOLVER_BREADTHFIRSTSEARCH_HPP

#include "Board.hpp"
#include <queue>

namespace puzzle
{
    namespace solve
    {
        class NoInformation
        {

        public:

            NoInformation() = delete;

            static void BreadthFirstSearch(const std::array<std::array<char, 3>, 3>& initial_state);

            static void IterativeDeepeningSearch(const std::array<std::array<char, 3>, 3>& initial_state);

            static void UniformCostSearch(const std::array<std::array<char, 3>, 3>& initial_state);

        private:

            struct MoveCost
            {
                std::unique_ptr<Board> board;
                uint32_t cost;
            };

            struct CmpGreater
            {
                bool operator()(const MoveCost& a, const MoveCost& b) const
                {
                    return a.cost > b.cost;
                }
            };

            static std::pair<std::shared_ptr<Board>, bool> depthLimitedSearch(std::shared_ptr<Board> node, uint32_t depth);

        };
    }
}

#endif //INC_8_PUZZLE_SOLVER_BREADTHFIRSTSEARCH_HPP
