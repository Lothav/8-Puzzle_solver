//
// Created by luiz0tavio on 4/20/19.
//

#include "Board.hpp"
#include <FactoryBoard.hpp>

namespace puzzle
{
    std::unique_ptr<mem::Pool<Board>> Board::pool_ = std::make_unique<mem::Pool<Board>>(10);

    void* Board::operator new(std::size_t size)
    {
        return Board::pool_->get();
    }

    void Board::operator delete(void* ptr)
    {
        Board::pool_->free(ptr);
    }

    bool Board::isSolved() const
    {
        return is_solved_;
    }

    std::string Board::toString(const std::string& id) const
    {
        std::stringstream str;

        str << "============= " << id << " =============" << std::endl;
        str << "|---|---|---|" << std::endl;
        for (ushort i = 0; i < 3; i++)
        {
            str << "| ";
            for (ushort j = 0; j < 3; j++)
            {
                str << state_[i][j] << " | ";
            }
            str << std::endl << "|---|---|---|" << std::endl;
        }

        return str.str();
    }

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
            auto val = state_cpy[empty_pos_[0]][empty_pos_[1] - 1];
            state_cpy[empty_pos_[0]][empty_pos_[1]] = val;
            state_cpy[empty_pos_[0]][empty_pos_[1] - 1] = ' ';

            moves.push_back(FactoryBoard::create(state_cpy));
        }

        bool allowed_right = empty_pos_[1] != 2;
        if (allowed_right)
        {
            auto state_cpy = state_;

            // Swap empty pos with next val;
            auto val = state_cpy[empty_pos_[0]][empty_pos_[1] + 1];
            state_cpy[empty_pos_[0]][empty_pos_[1]] = val;
            state_cpy[empty_pos_[0]][empty_pos_[1] + 1] = ' ';

            moves.push_back(FactoryBoard::create(state_cpy));
        }

        return moves;
    }
}