#include "Board.hpp"
#include <FactoryBoard.hpp>

namespace puzzle
{
    std::unique_ptr<mem::Pool<Board>> Board::pool_ = std::make_unique<mem::Pool<Board>>(100000);

    void* Board::operator new(std::size_t size)
    {
        return Board::pool_->get();
    }

    void Board::operator delete(void* ptr)
    {
        Board::pool_->free(ptr);
    }

    bool Board::isFinalState() const
    {
        return is_final_state_;
    }

    uint32_t Board::getHeuristicsFlags() const
    {
        uint32_t flags = 0;

        for (auto &heuristic : heuristics_) {
            flags |= heuristic.first;
        }

        return flags;
    }

    uint32_t Board::getHeuristicValue(solve::HeuristicsFlags flag)
    {
        if(heuristics_.count(flag)) {
            return heuristics_[flag];
        }

        throw "Requested Heuristic is not calculated!";
    }

    std::vector<std::unique_ptr<Board>> Board::getAllowedMoves() const
    {
        std::vector<std::array<ushort, 2>> moves = {};

        // Allowed move up
        if (empty_pos_[0] != 0)
            moves.push_back({(ushort)(empty_pos_[0] - 1), empty_pos_[1]});

        // Allowed move down
        if (empty_pos_[0] != 2)
            moves.push_back({(ushort)(empty_pos_[0] + 1), empty_pos_[1]});

        // Allowed move left
        if (empty_pos_[1] != 0)
            moves.push_back({empty_pos_[0], (ushort)(empty_pos_[1] - 1)});

        // Allowed move right
        if (empty_pos_[1] != 2)
            moves.push_back({empty_pos_[0], (ushort)(empty_pos_[1] + 1)});

        std::vector<std::unique_ptr<Board>> allowed_moves = {};

        // Fill allowed_moves vector
        for (auto& move : moves)
        {
            // Create a root state copy so we can modify it
            auto state_cpy = state_;

            // Swap empty pos with move value
            auto val = state_cpy[move[0]][move[1]];
            state_cpy[empty_pos_[0]][empty_pos_[1]] = val;
            state_cpy[move[0]][move[1]] = ' ';

            // Create new board with the new state
            allowed_moves.push_back(FactoryBoard::create(state_cpy, getHeuristicsFlags()));
        }

        return allowed_moves;
    }

    std::string Board::toString(const std::string& id) const
    {
        std::stringstream str;

        str << "-------------" << std::endl;
        for (ushort i = 0; i < 3; i++)
        {
            str << "| ";
            for (ushort j = 0; j < 3; j++)
                str << state_[i][j] << " | ";

            if(i == 1) str << "\t" << id;

            str << std::endl << "-------------" << std::endl;
        }

        return str.str();
    }
}