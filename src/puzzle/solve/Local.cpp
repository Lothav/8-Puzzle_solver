#include "Local.hpp"
namespace puzzle
{
    namespace solve
    {
        void Local::HillClimbing(std::array<std::array<char, 3>, 3> initial_state, uint32_t k)
        {
            std::unique_ptr<Board> next_node = FactoryBoard::create(initial_state, HeuristicsFlags::MANHATTAN_DISTANCE_TO_FINAL_STATE);

            std::cout << "============= HillClimbing started =============" << std::endl;
//            std::cout << next_node->toString("Initial Board") << std::endl;

            uint32_t current_k = k;
            uint32_t iterations = 0;
            uint32_t exp_nodes = 0;

            while (true)
            {
                iterations++;

                uint32_t current_eval = next_node->getHeuristicValue(HeuristicsFlags::MANHATTAN_DISTANCE_TO_FINAL_STATE);
                if (current_eval == 0) {
                    std::cout << "HillClimbing found solution!" << std::endl;
                    std::cout << "Iterations: " << std::to_string(iterations) << std::endl;
                    std::cout << "Total Expanded Nodes: " << std::to_string(exp_nodes) << std::endl;
                    return;
                }

                std::vector<std::unique_ptr<Board>> moves = next_node->getAllowedMoves();
                exp_nodes += moves.size();

                uint32_t next_eval = UINT32_MAX;

                for (auto &move: moves) {
                    uint32_t u_m = move->getHeuristicValue(HeuristicsFlags::MANHATTAN_DISTANCE_TO_FINAL_STATE);
                    if (u_m < next_eval) {
                        next_node = std::move(move);
                        next_eval = u_m;
                    }
                }

                current_k = current_eval == next_eval ? current_k - 1 : k;

                if (current_eval < next_eval || current_k == 0) {
                    std::cerr << "HillClimbing cannot find a solution!" << std::endl;
                    return;
                }
            }
        }
    }
}