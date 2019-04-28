#include "FactoryBoard.hpp"

namespace puzzle
{
    std::unique_ptr<Board> FactoryBoard::create(const std::array<std::array<char, 3>, 3>& state, uint32_t heuristics_flags)
    {
        std::unordered_map<solve::HeuristicsFlags, uint32_t> heuristics = {};

        bool solve_set = false;
        bool is_solved = false;

        if(heuristics_flags & solve::HeuristicsFlags::MANHATTAN_DISTANCE_TO_FINAL_STATE) {
            uint32_t h = solve::Heuristics::ManhattanDistanceToFinalState(state);
            is_solved = h == 0;
            solve_set = true;

            heuristics[solve::HeuristicsFlags::MANHATTAN_DISTANCE_TO_FINAL_STATE] = h;
        }

        if(heuristics_flags & solve::HeuristicsFlags::TILES_OUT_OF_PLACE) {
            uint32_t h = solve::Heuristics::TilesOutOfPlace(state);
            is_solved = h == 0;
            solve_set = true;

            heuristics[solve::HeuristicsFlags::TILES_OUT_OF_PLACE] = h;
        }

        is_solved = solve_set ? is_solved : FactoryBoard::checkBoardIsSolved(state);

        return std::make_unique<Board>(state, getEmptyPosition(state), is_solved, std::move(heuristics));
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

}
