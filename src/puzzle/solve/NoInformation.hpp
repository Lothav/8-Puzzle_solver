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

            static void BreadthFirstSearch(std::unique_ptr<Board> initial_board);

            static void IterativeDeepeningSearch(std::unique_ptr<Board> initial_board);

            static void UniformCostSearch(std::unique_ptr<Board> initial_board);

        private:

            struct MoveCost
            {
                std::unique_ptr<Board> board;
                uint cost;
            };

            struct CmpGreater
            {
                bool operator()(const MoveCost& a,const MoveCost& b) const
                {
                    return a.cost > b.cost;
                }
            };

            static std::pair<std::shared_ptr<Board>, bool> depthLimitedSearch(std::shared_ptr<Board> node, uint32_t depth);

        };
    }
}

#endif //INC_8_PUZZLE_SOLVER_BREADTHFIRSTSEARCH_HPP
