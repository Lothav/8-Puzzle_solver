#include <cstdlib>
#include <memory>

#include <FactoryBoard.hpp>

int main(int argc, char* argv[])
{
    {
        std::array<std::array<char, 3>, 3> initial_state = {
            std::array<char, 3>({'1','2','3'}),
            std::array<char, 3>({'4','5','6'}),
            std::array<char, 3>({'7','8',' '})
        };

        auto board = puzzle::FactoryBoard::create(initial_state);
        board->isSolved();

        std::cout << board->toString() << std::endl;

        auto as = board->getAllowedMoves();
        for (auto& a : as)
        {
            std::cout << a->toString() << std::endl;
        }
    }

    return EXIT_SUCCESS;
}