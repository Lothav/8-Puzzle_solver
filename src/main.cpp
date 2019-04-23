#include <cstdlib>
#include <memory>

#include <FactoryBoard.hpp>
#include <Solve.hpp>

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
            puzzle::Solve::BreadthFirstSearch(std::move(board));
        }

        {
            auto board = puzzle::FactoryBoard::create(initial_state);
            puzzle::Solve::IterativeDeepeningSearch(std::move(board));
        }
    }

    return EXIT_SUCCESS;
}