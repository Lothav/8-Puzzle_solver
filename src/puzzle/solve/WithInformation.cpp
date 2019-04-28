#include "WithInformation.hpp"
#include <algorithm>
#include <FactoryBoard.hpp>

namespace puzzle
{
    namespace solve
    {
        void WithInformation::AStarSearch(std::array<std::array<char, 3>, 3> initial_state)
        {
            std::unique_ptr<Board> initial_board = FactoryBoard::create(initial_state, true);

            std::cout << "AStarSearch" << std::endl;
            std::cout << initial_board->toString("Initial Board") << std::endl;

            uint32_t g = 0;
            uint32_t h = initial_board->getDistanceToFinalState();

            std::vector<MoveCost> v = {};

            MoveCost root = {
                .board = std::move(initial_board),
                .cost  = g + h
            };
            v.push_back(std::move(root));

            std::make_heap(v.begin(), v.end(), CmpGreater());

            while (!v.empty()) {

                MoveCost front = std::move(v.front());
                std::pop_heap(v.begin(), v.end(), CmpGreater());

                if (front.board->isFinalState()) {
                    std::cout << "AStarSearch found solution!" << std::endl;
                    return;
                }

                g++;
                h = front.board->getDistanceToFinalState();

                std::vector<std::unique_ptr<Board>> allowed_ms = front.board->getAllowedMoves();
                for (auto &allowed_m: allowed_ms) {

                    MoveCost child = {
                        .board = std::move(allowed_m),
                        .cost  = g + h
                    };

                    v.push_back(std::move(child));
                }

                std::sort_heap(v.begin(), v.end(), CmpGreater());
            }
        }
    }
}