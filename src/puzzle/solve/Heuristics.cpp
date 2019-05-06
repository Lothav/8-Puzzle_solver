#include "Heuristics.hpp"

namespace puzzle
{
    namespace solve
    {
        uint32_t Heuristics::ManhattanDistanceToFinalState(const std::array<std::array<char, 3>, 3>& state)
        {
            uint32_t distance = 0;
            for (ushort i = 0; i < 3; i++)
            {
                for (ushort j = 0; j < 3; j++)
                {
                    char number_str = state[i][j];
                    if(number_str == ' ') {
                        distance += std::abs(2 - i) + std::abs(2 - j);
                        continue;
                    }

                    char* pEnd;
                    int cell_number = static_cast<int>(std::strtol(&number_str, &pEnd, 10));

                    std::array<int, 2> pos = {(cell_number - 1) / 3, (cell_number - 1) % 3};

                    distance += std::abs(pos[0] - i) + std::abs(pos[1] - j);
                }
            }

            return distance;
        }

        uint32_t Heuristics::TilesOutOfPlace(const std::array<std::array<char, 3>, 3>& state)
        {
            uint32_t distance = 0;
            for (ushort i = 0; i < 3; i++)
            {
                for (ushort j = 0; j < 3; j++)
                {
                    char number_str = state[i][j];
                    if(i == 2 && j == 2)
                    {
                        if(number_str != ' ') {
                            distance++;
                        }
                        break;
                    }

                    if(number_str == ' ') {
                        distance++;
                        continue;
                    }

                    char* pEnd;
                    int cell_number = static_cast<int>(std::strtol(&number_str, &pEnd, 10));

                    std::array<int, 2> pos = {(cell_number - 1) / 3, (cell_number - 1) % 3};

                    distance += pos[0] != i || pos[1] != j ? 1 : 0;
                }
            }

            return distance;
        }
    }
}