
#include "Solve.hpp"

namespace puzzle
{
    void Solve::BreadthFirstSearch(std::unique_ptr<Board> initial_board)
    {
        std::cout << initial_board->toString("Initial Board") << std::endl;

        std::queue<std::unique_ptr<Board>> q = {};
        q.push(std::move(initial_board));

        while (!q.empty())
        {
            std::unique_ptr<Board> front = std::move(q.front());
            q.pop();

            std::cout << front->toString() << std::endl;

            if(front->isSolved()) {
                std::cout << "Finish!" << std::endl;
                return;
            }

            std::vector<std::unique_ptr<Board>> allowed_ms = front->getAllowedMoves();
            for (auto& allowed_m: allowed_ms) {
                q.push(std::move(allowed_m));
            }
        }
    }
}
