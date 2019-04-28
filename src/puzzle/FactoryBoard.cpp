#include "FactoryBoard.hpp"

namespace puzzle
{
    std::unique_ptr<Board> FactoryBoard::create(const std::array<std::array<char, 3>, 3>& state, bool calc_dist_to_final_state)
    {
        auto a = tilesOutOfPlace(state);

        if(calc_dist_to_final_state) {
            uint32_t distance = manhattanDistanceToFinalState(state);
            return std::make_unique<Board>(state, getEmptyPosition(state), distance);
        } else {
            bool is_solved = checkBoardIsSolved(state);
            return std::make_unique<Board>(state, getEmptyPosition(state), is_solved ? 0 : -1);
        }
    }

    bool FactoryBoard::checkBoardIsSolved(const std::array<std::array<char, 3>, 3>& state)
    {
        bool solved = true;

        for (ushort i = 0; i < 3; i++)
        {
            for (ushort j = 0; j < 3; j++)
            {
                // Check last character.
                if(i == 2 && j == 2)
                {
                    solved = state[i][j] == ' ';
                    break;
                }

                // Check 1 to 8 numbers in table.
                auto step_number = (char)('0' + (i*3) + j + 1);
                if(state[i][j] != step_number)
                {
                    solved = false;
                    break;
                }
            }

            if(!solved) break;
        }

        return solved;
    }

    std::array<ushort, 2> FactoryBoard::getEmptyPosition(const std::array<std::array<char, 3>, 3>& state)
    {
        for (ushort i = 0; i < 3; i++)
            for (ushort j = 0; j < 3; j++)
                if(state[i][j] == ' ')
                    return std::array<ushort, 2>{i, j};

        throw "Board has no empty tile!";
    }

    uint32_t FactoryBoard::manhattanDistanceToFinalState(const std::array<std::array<char, 3>, 3>& state)
    {
        uint32_t distance = 0;
        for (ushort i = 0; i < 3; i++)
        {
            for (ushort j = 0; j < 3; j++)
            {
                char number_str = state[i][j];
                if(number_str == ' ') continue;

                char* pEnd;
                int cell_number = static_cast<int>(std::strtol(&number_str, &pEnd, 10));

                std::array<int, 2> pos = {(cell_number - 1) / 3, (cell_number - 1) % 3};

                distance += std::abs(pos[0] - i) + std::abs(pos[1] - j);
            }
        }

        return distance;
    }

    uint32_t FactoryBoard::tilesOutOfPlace(const std::array<std::array<char, 3>, 3>& state)
    {
        uint32_t distance = 0;
        for (ushort i = 0; i < 3; i++)
        {
            for (ushort j = 0; j < 3; j++)
            {
                char number_str = state[i][j];
                if(number_str == ' ') continue;

                char* pEnd;
                int cell_number = static_cast<int>(std::strtol(&number_str, &pEnd, 10));

                std::array<int, 2> pos = {(cell_number - 1) / 3, (cell_number - 1) % 3};

                distance += pos[0] != i || pos[1] != j ? 1 : 0;
            }
        }

        return distance;
    }
}
