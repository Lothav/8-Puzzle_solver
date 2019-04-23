
#include "Solve.hpp"

namespace puzzle
{
    void Solve::BreadthFirstSearch(std::unique_ptr<Board> initial_board)
    {
        std::cout << "BreadthFirstSearch" << std::endl;
        std::cout << initial_board->toString("Initial Board") << std::endl;

        std::queue<std::unique_ptr<Board>> q = {};
        q.push(std::move(initial_board));

        while (!q.empty())
        {
            std::unique_ptr<Board> front = std::move(q.front());
            q.pop();

            if(front->isFinalState()) {
                std::cout << "BreadthFirstSearch found solution!" << std::endl;
                return;
            }

            std::vector<std::unique_ptr<Board>> allowed_ms = front->getAllowedMoves();
            for (auto& allowed_m: allowed_ms) {
                q.push(std::move(allowed_m));
            }
        }
    }

    void Solve::IterativeDeepeningSearch(std::unique_ptr<Board> initial_board)
    {
        std::cout << "IterativeDeepeningSearch"<< std::endl;
        std::cout << initial_board->toString("Initial Board") << std::endl;

        uint32_t depth = 0;

        std::shared_ptr<Board> root = std::move(initial_board);

        while(true)
        {
            auto [found, remaining] = depthLimitedSearch(root, depth);
            if(found != nullptr) {
                std::cout << "IterativeDeepeningSearch found solution!" << std::endl;
                return;
            } else if(!remaining) {
                std::cout << "Not Remaining!" << std::endl;
                return;
            }

            depth++;
        }
    }

    std::pair<std::shared_ptr<Board>, bool> Solve::depthLimitedSearch(std::shared_ptr<Board> node, uint32_t depth)
    {
        if(depth == 0) {

            if(node->isFinalState())
                return {node, true};

            return {nullptr, true};

        } else {

            std::vector<std::unique_ptr<Board>> allowed_ms = node->getAllowedMoves();

            bool any_remaining = false;
            for (auto& allowed_m: allowed_ms) {

                auto [found, remaining] = depthLimitedSearch(std::move(allowed_m), depth - 1);

                if(found != nullptr)
                    return {found, true};

                any_remaining = any_remaining || remaining;
            }

            return {nullptr, any_remaining};
        }
    }

}
