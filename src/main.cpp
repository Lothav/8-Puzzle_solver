#include <cstdlib>
#include <memory>

#include <Table.hpp>
#include "Provider.hpp"

int main(int argc, char* argv[])
{
    mem::Provider::initPool(1024 * 1024);

    std::array<std::array<char, 3>, 3> initial_state = {
        std::array<char, 3>({'1','2','3'}),
        std::array<char, 3>({'4','5','6'}),
        std::array<char, 3>({'7','8','9'})
    };

    auto table = std::make_unique<solver::Table>(std::move(initial_state));
    table->isSolved();

    mem::Provider::destroyPool();
    return EXIT_SUCCESS;
}