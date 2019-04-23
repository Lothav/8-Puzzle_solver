#ifndef INC_8_PUZZLE_SOLVER_BREADTHFIRSTSEARCH_HPP
#define INC_8_PUZZLE_SOLVER_BREADTHFIRSTSEARCH_HPP

#include "Board.hpp"
#include <queue>

namespace puzzle
{
    class Solve
    {

    public:

        static void BreadthFirstSearch(std::unique_ptr<Board> initial_board);

        static void IterativeDeepeningSearch(std::unique_ptr<Board> initial_board);

    private:

        static std::pair<std::shared_ptr<Board>, bool> depthLimitedSearch(std::shared_ptr<Board> node, uint32_t depth);

    };
}

#endif //INC_8_PUZZLE_SOLVER_BREADTHFIRSTSEARCH_HPP
