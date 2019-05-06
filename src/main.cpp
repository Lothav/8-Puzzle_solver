#include <cstdlib>
#include <memory>
#include <chrono>

#include <FactoryBoard.hpp>
#include <solve/NoInformation.hpp>
#include <solve/WithInformation.hpp>
#include <solve/Local.hpp>


#define CALC_TIME_SPENT(fn)                                                             		                \
{                                                                                               		        \
    auto start_cf = std::chrono::high_resolution_clock::now();                                  		        \
    fn;                                                                                                         \
    auto end_cf = std::chrono::high_resolution_clock::now();                                    		        \
    auto duration_cf = std::chrono::duration<double, std::milli>(end_cf - start_cf).count();    		        \
    std::cout << "Took " << std::to_string(duration_cf) << "ms to execute " << std::string(#fn) << std::endl;  \
}

int main(int argc, char* argv[])
{
    {
        std::array<std::array<char, 3>, 3> initial_state = {
            std::array<char, 3>({'1','2','3'}),
            std::array<char, 3>({'4','5','6'}),
            std::array<char, 3>({'7',' ','8'})
        };

        CALC_TIME_SPENT(puzzle::solve::NoInformation::BreadthFirstSearch(initial_state));
        CALC_TIME_SPENT(puzzle::solve::NoInformation::IterativeDeepeningSearch(initial_state));
        CALC_TIME_SPENT(puzzle::solve::NoInformation::UniformCostSearch(initial_state));
        CALC_TIME_SPENT(puzzle::solve::WithInformation::AStarSearch(initial_state));
        CALC_TIME_SPENT(puzzle::solve::WithInformation::GreedyBestFirstSearch(initial_state));
        CALC_TIME_SPENT(puzzle::solve::Local::HillClimbing(initial_state));
    }

    return EXIT_SUCCESS;
}