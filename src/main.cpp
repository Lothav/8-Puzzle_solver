#include <cstdlib>
#include "Provider.hpp"

int main(int argc, char* argv[])
{
    mem::Provider::initPool(1024 * 1024);



    mem::Provider::destroyPool();
    return EXIT_SUCCESS;
}