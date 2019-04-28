#ifndef INC_8_PUZZLE_SOLVER_WITHINFORMATION_HPP
#define INC_8_PUZZLE_SOLVER_WITHINFORMATION_HPP

#include <memory>
#include "Board.hpp"

namespace puzzle
{
    namespace solve
    {
        class WithInformation
        {

        public:

            static void AStarSearch(std::unique_ptr<Board> initial_board);

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

        };
    }
}

#endif //INC_8_PUZZLE_SOLVER_WITHINFORMATION_HPP
