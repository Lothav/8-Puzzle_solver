#include <cstdlib>
#include <memory>
#include <chrono>

#include <FactoryBoard.hpp>
#include <solve/NoInformation.hpp>
#include <solve/WithInformation.hpp>
#include <solve/Local.hpp>
#include <fstream>


#define CALC_TIME_SPENT(fn)                                                             		               \
{                                                                                               		       \
    auto start_cf = std::chrono::high_resolution_clock::now();                                  		       \
    fn;                                                                                                        \
    auto end_cf = std::chrono::high_resolution_clock::now();                                    		       \
    auto duration_cf = std::chrono::duration<double, std::milli>(end_cf - start_cf).count();    		       \
    std::cout << "Took " << std::to_string(duration_cf) << "ms to execute " << std::string(#fn) << std::endl;  \
}

int main(int argc, char* argv[])
{
    {
        if(argc < 2) {
            std::cerr << "File input path must be passes as first param!" << std::endl;
            return EXIT_FAILURE;
        }

        std::ifstream infile(argv[1]);

        if(!infile.is_open()){
            std::cerr << "Cannot open file " <<  argv[1] << std::endl;
            return EXIT_FAILURE;
        }

        std::array<std::array<char, 3>, 3> initial_state = {};

        {
            char n1, n2, n3;

            for (int i = 0; i < 3; ++i) {
                infile >> n1 >> n2 >> n3;
                char c1 = n1 == '0' ? ' ' : n1;
                char c2 = n2 == '0' ? ' ' : n2;
                char c3 = n3 == '0' ? ' ' : n3;

                initial_state[i] = {c1, c2, c3};
            }
        }

        std::string m_mask = std::string(argc >= 3 ? argv[2] : "biuagh");

        if(m_mask.find('b'))
            CALC_TIME_SPENT(puzzle::solve::NoInformation::BreadthFirstSearch(initial_state));

        if(m_mask.find('i'))
            CALC_TIME_SPENT(puzzle::solve::NoInformation::IterativeDeepeningSearch(initial_state));

        if(m_mask.find('u'))
            CALC_TIME_SPENT(puzzle::solve::NoInformation::UniformCostSearch(initial_state));

        if(m_mask.find('a'))
            CALC_TIME_SPENT(puzzle::solve::WithInformation::AStarSearch(initial_state));

        if(m_mask.find('g'))
            CALC_TIME_SPENT(puzzle::solve::WithInformation::GreedyBestFirstSearch(initial_state));

        if(m_mask.find('h'))
            CALC_TIME_SPENT(puzzle::solve::Local::HillClimbing(initial_state));
    }

    return EXIT_SUCCESS;
}