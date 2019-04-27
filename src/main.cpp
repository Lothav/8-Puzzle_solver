#include <cstdlib>
#include <memory>

#include <FactoryBoard.hpp>
#include <solve/NoInformation.hpp>

int main(int argc, char* argv[])
{
    {
        std::array<std::array<char, 3>, 3> initial_state = {
            std::array<char, 3>({'1','2','3'}),
            std::array<char, 3>({'4','5','6'}),
            std::array<char, 3>({'7',' ','8'})
        };

        {
            auto board = puzzle::FactoryBoard::create(initial_state);
            puzzle::solve::NoInformation::BreadthFirstSearch(std::move(board));
        }

        {
            auto board = puzzle::FactoryBoard::create(initial_state);
            puzzle::solve::NoInformation::IterativeDeepeningSearch(std::move(board));
        }

        {
            auto board = puzzle::FactoryBoard::create(initial_state);
            puzzle::solve::NoInformation::UniformCostSearch(std::move(board));
        }
    }

    return EXIT_SUCCESS;
}