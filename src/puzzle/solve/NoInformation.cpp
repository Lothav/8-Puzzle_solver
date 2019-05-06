
#include <FactoryBoard.hpp>
#include "NoInformation.hpp"

namespace puzzle
{
    namespace solve
    {
        void NoInformation::BreadthFirstSearch(const std::array<std::array<char, 3>, 3>& initial_state)
        {
            auto initial_board = puzzle::FactoryBoard::create(initial_state);

            std::cout << "============= BreadthFirstSearch started =============" << std::endl;
//            std::cout << initial_board->toString("Initial Board") << std::endl;

            std::queue<std::unique_ptr<Board>> q = {};
            q.push(std::move(initial_board));

            uint32_t iterations = 0;
            uint32_t exp_nodes = 0;

            while (!q.empty()) {

                iterations++;

                std::unique_ptr<Board> front = std::move(q.front());
                q.pop();

                if (front->isFinalState()) {
                    std::cout << "BreadthFirstSearch found solution!" << std::endl;
                    std::cout << "Iterations: " << std::to_string(iterations) << std::endl;
                    std::cout << "Total Expanded Nodes: " << std::to_string(exp_nodes) << std::endl;
                    return;
                }

                std::vector<std::unique_ptr<Board>> allowed_ms = front->getAllowedMoves();
                exp_nodes += allowed_ms.size();

                for (auto &allowed_m: allowed_ms) {
                    q.push(std::move(allowed_m));
                }
            }
        }

        void NoInformation::IterativeDeepeningSearch(const std::array<std::array<char, 3>, 3>& initial_state)
        {
            auto initial_board = puzzle::FactoryBoard::create(initial_state);

            std::cout << "============= IterativeDeepeningSearch started =============" << std::endl;
//            std::cout << initial_board->toString("Initial Board") << std::endl;

            uint32_t depth = 0;
            uint32_t iterations = 0;

            std::shared_ptr<Board> root = std::move(initial_board);

            while (true)
            {
                auto [found, remaining] = depthLimitedSearch(root, depth, &iterations);
                if (found != nullptr) {
                    std::cout << "IterativeDeepeningSearch found solution!" << std::endl;
                    std::cout << "Iterations: " << std::to_string(iterations) << std::endl;
                    return;
                } else if (!remaining) {
                    std::cout << "IterativeDeepeningSearch cannot find a solution!" << std::endl;
                    return;
                }

                depth++;
            }
        }

        void NoInformation::UniformCostSearch(const std::array<std::array<char, 3>, 3>& initial_state)
        {
            auto initial_board = puzzle::FactoryBoard::create(initial_state);

            std::cout << "============= UniformCostSearch =============" << std::endl;
//            std::cout << initial_board->toString("Initial Board") << std::endl;

            uint32_t iterations = 0;
            uint32_t exp_nodes = 0;

            std::vector<MoveCost> v = {};

            MoveCost root = {
                .board = std::move(initial_board),
                .cost  = 1
            };
            v.push_back(std::move(root));

            std::make_heap(v.begin(), v.end(), CmpGreater());

            while (!v.empty()) {

                iterations++;

                MoveCost front = std::move(v.front());
                std::pop_heap(v.begin(), v.end(), CmpGreater());
                v.pop_back();

                if (front.board->isFinalState()) {
                    std::cout << "UniformCostSearch found solution!" << std::endl;
                    std::cout << "Iterations: " << std::to_string(iterations) << std::endl;
                    std::cout << "Total Expanded Nodes: " << std::to_string(exp_nodes) << std::endl;
                    return;
                }

                std::vector<std::unique_ptr<Board>> allowed_ms = front.board->getAllowedMoves();
                exp_nodes += allowed_ms.size();

                for (auto &allowed_m: allowed_ms) {

                    MoveCost child = {
                        .board = std::move(allowed_m),
                        .cost  = 1
                    };

                    v.push_back(std::move(child));
                }

                std::sort_heap(v.begin(), v.end(), CmpGreater());
            }
        }

        std::pair<std::shared_ptr<Board>, bool> NoInformation::depthLimitedSearch(std::shared_ptr<Board> node, uint32_t depth, uint32_t* iterations)
        {
            (*iterations)++;

            if (depth == 0) {

                if (node->isFinalState())
                    return {node, true};

                return {nullptr, true};

            } else {

                std::vector<std::unique_ptr<Board>> allowed_ms = node->getAllowedMoves();

                bool any_remaining = false;
                for (auto &allowed_m: allowed_ms) {

                    auto[found, remaining] = depthLimitedSearch(std::move(allowed_m), depth - 1, iterations);

                    if (found != nullptr)
                        return {found, true};

                    any_remaining = any_remaining || remaining;
                }

                return {nullptr, any_remaining};
            }
        }
    }
}
