#ifndef INC_8_PUZZLE_SOLVER_BREADTHFIRSTSEARCH_HPP
#define INC_8_PUZZLE_SOLVER_BREADTHFIRSTSEARCH_HPP

#include "Board.hpp"
#include <queue>

namespace puzzle
{
    class BreadthFirstSearch
    {

    public:

        static void solve(std::unique_ptr<Board> initial_board);
    };
}

#endif //INC_8_PUZZLE_SOLVER_BREADTHFIRSTSEARCH_HPP