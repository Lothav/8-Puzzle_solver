#include "WithInformation.hpp"
#include "Heuristics.hpp"
#include <algorithm>
#include <FactoryBoard.hpp>

namespace puzzle
{
    namespace solve
    {
        void WithInformation::GreedyBestFirstSearch(const std::array<std::array<char, 3>, 3>& initial_state)
        {
            std::unique_ptr<Board> initial_board = FactoryBoard::create(initial_state, HeuristicsFlags::TILES_OUT_OF_PLACE);

            std::cout << "============= GreedyBestFirstSearch started =============" << std::endl;

            std::vector<MoveCost> v = {};
            uint32_t iterations = 0;
            uint32_t exp_nodes = 0;

            uint32_t h = initial_board->getHeuristicValue(HeuristicsFlags::TILES_OUT_OF_PLACE);
            MoveCost node = {
                .board = std::move(initial_board),
                .cost  = h
            };

            v.push_back(std::move(node));
            std::make_heap(v.begin(), v.end(), CmpGreater());

            while (!v.empty()) {

                iterations++;

                std::pop_heap(v.begin(), v.end(), CmpGreater());
                MoveCost front = std::move(v.back());
                v.pop_back();

                if (front.board->isFinalState()) {
                    std::cout << "GreedyBestFirstSearch found solution!" << std::endl;
                    std::cout << "Iterations: " << std::to_string(iterations) << std::endl;
                    std::cout << "Total Expanded Nodes: " << std::to_string(exp_nodes) << std::endl;
                    return;
                }

                std::vector<std::unique_ptr<Board>> allowed_ms = front.board->getAllowedMoves();
                exp_nodes += allowed_ms.size();

                for (auto &allowed_m: allowed_ms) {

                    h = allowed_m->getHeuristicValue(HeuristicsFlags::TILES_OUT_OF_PLACE);

                    node = {
                        .board = std::move(allowed_m),
                        .cost  = h,
                    };

                    v.push_back(std::move(node));
                    std::push_heap(v.begin(), v.end(), CmpGreater());
                }
            }
        }

        void WithInformation::AStarSearch(const std::array<std::array<char, 3>, 3>& initial_state)
        {
            std::unique_ptr<Board> initial_board = FactoryBoard::create(initial_state, HeuristicsFlags::MANHATTAN_DISTANCE_TO_FINAL_STATE);

            std::cout << "============= AStarSearch started =============" << std::endl;

            uint32_t g = 0;
            uint32_t h = initial_board->getHeuristicValue(HeuristicsFlags::MANHATTAN_DISTANCE_TO_FINAL_STATE);

            std::vector<MoveCost> v = {};
            uint32_t iterations = 0;
            uint32_t exp_nodes = 0;

            MoveCost node = {
                .board = std::move(initial_board),
                .cost  = g + h
            };

            v.push_back(std::move(node));
            std::make_heap(v.begin(), v.end(), CmpGreater());

            while (!v.empty()) {

                iterations++;

                std::pop_heap(v.begin(), v.end(), CmpGreater());
                MoveCost front = std::move(v.back());
                v.pop_back();

                if (front.board->isFinalState()) {
                    std::cout << "AStarSearch found solution!" << std::endl;
                    std::cout << "Iterations: " << std::to_string(iterations) << std::endl;
                    std::cout << "Total Expanded Nodes: " << std::to_string(exp_nodes) << std::endl;
                    return;
                }

                g++;

                std::vector<std::unique_ptr<Board>> allowed_ms = front.board->getAllowedMoves();
                exp_nodes += allowed_ms.size();

                for (auto &allowed_m: allowed_ms) {

                    h = allowed_m->getHeuristicValue(HeuristicsFlags::MANHATTAN_DISTANCE_TO_FINAL_STATE);

                    node = {
                        .board = std::move(allowed_m),
                        .cost  = g + h
                    };

                    v.push_back(std::move(node));
                    std::push_heap(v.begin(), v.end(), CmpGreater());
                }
            }
        }
    }
}