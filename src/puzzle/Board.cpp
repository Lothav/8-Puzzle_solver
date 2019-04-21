//
// Created by luiz0tavio on 4/20/19.
//

#include "Board.hpp"
#include <FactoryBoard.hpp>

namespace puzzle
{
    std::vector<std::unique_ptr<Board>> Board::getAllowedMoves() const
    {
        std::vector<std::unique_ptr<Board>> moves = {};

        bool allowed_up = empty_pos_[0] != 0;
        if (allowed_up)
        {
            auto state_cpy = state_;

            // Swap empty pos with next val;
            auto val = state_cpy[empty_pos_[0] - 1][empty_pos_[1]];
            state_cpy[empty_pos_[0]][empty_pos_[1]] = val;
            state_cpy[empty_pos_[0] - 1][empty_pos_[1]] = ' ';

            moves.push_back(FactoryBoard::create(state_cpy));
        }

        bool allowed_down = empty_pos_[0] != 2;
        if (allowed_down)
        {
            auto state_cpy = state_;

            // Swap empty pos with next val;
            auto val = state_cpy[empty_pos_[0] + 1][empty_pos_[1]];
            state_cpy[empty_pos_[0]][empty_pos_[1]] = val;
            state_cpy[empty_pos_[0] + 1][empty_pos_[1]] = ' ';

            moves.push_back(FactoryBoard::create(state_cpy));
        }

        bool allowed_left = empty_pos_[1] != 0;
        if (allowed_left)
        {
            auto state_cpy = state_;

            // Swap empty pos with next val;
            auto val = state_cpy[empty_pos_[0]][empty_pos_[1] + 1];
            state_cpy[empty_pos_[0]][empty_pos_[1]] = val;
            state_cpy[empty_pos_[0]][empty_pos_[1] + 1] = ' ';

            moves.push_back(FactoryBoard::create(state_cpy));
        }

        bool allowed_right = empty_pos_[1] != 2;
        if (allowed_right)
        {
            auto state_cpy = state_;

            // Swap empty pos with next val;
            auto val = state_cpy[empty_pos_[0]][empty_pos_[1] - 1];
            state_cpy[empty_pos_[0]][empty_pos_[1]] = val;
            state_cpy[empty_pos_[0]][empty_pos_[1] - 1] = ' ';

            moves.push_back(FactoryBoard::create(state_cpy));
        }

        return moves;
    }
}