#include <cstdlib>
#include <memory>

#include <FactoryBoard.hpp>
#include <solve/NoInformation.hpp>
#include <solve/WithInformation.hpp>
#include <solve/Local.hpp>

int main(int argc, char* argv[])
{
    {
        std::array<std::array<char, 3>, 3> initial_state = {
            std::array<char, 3>({'1','2','3'}),
            std::array<char, 3>({'4','5','6'}),
            std::array<char, 3>({'7',' ','8'})
        };

        {
            puzzle::solve::NoInformation::BreadthFirstSearch(initial_state);
        }

        {
            puzzle::solve::NoInformation::IterativeDeepeningSearch(initial_state);
        }

        {
            puzzle::solve::NoInformation::UniformCostSearch(initial_state);
        }

        {
            puzzle::solve::WithInformation::AStarSearch(initial_state);
        }

        {
            puzzle::solve::WithInformation::GreedyBestFirstSearch(initial_state);
        }

        {
            puzzle::solve::Local::HillClimbing(initial_state);
        }
    }

    return EXIT_SUCCESS;
}