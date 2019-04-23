#include <cstdlib>
#include <memory>

#include <FactoryBoard.hpp>
#include <BreadthFirstSearch.hpp>

int main(int argc, char* argv[])
{
    {
        std::array<std::array<char, 3>, 3> initial_state = {
            std::array<char, 3>({'1','2','3'}),
            std::array<char, 3>({'5','4','6'}),
            std::array<char, 3>({'7',' ','8'})
        };

        auto board = puzzle::FactoryBoard::create(initial_state);

        puzzle::BreadthFirstSearch::solve(std::move(board));
    }

    return EXIT_SUCCESS;
}