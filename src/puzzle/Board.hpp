#ifndef INC_8_PUZZLE_SOLVER_BOARD_HPP
#define INC_8_PUZZLE_SOLVER_BOARD_HPP

#include <vector>
#include <memory>
#include <memancpp/Pool.hpp>
#include <unordered_map>
#include "solve/Heuristics.hpp"
#include <sstream>

namespace puzzle
{
    class Board
    {

    private:

        static std::unique_ptr<mem::Pool<Board>> pool_;

        std::array<std::array<char, 3>, 3> state_ = {};
        std::array<ushort, 2> empty_pos_ = {0, 0};
        bool is_final_state_ = false;

        std::unordered_map<solve::HeuristicsFlags, uint32_t> heuristics_ = {};

    public:

        Board(const std::array<std::array<char, 3>, 3>& state,
            std::array<ushort, 2> empty_pos,
            bool is_final_state,
            std::unordered_map<solve::HeuristicsFlags, uint32_t>&& heuristics
        ) : state_(state), empty_pos_(empty_pos), is_final_state_(is_final_state), heuristics_(std::move(heuristics)) {};

        void* operator new(std::size_t size);
        void operator delete(void* ptr);

        bool isFinalState() const;
        uint32_t getHeuristicsFlags() const;
        uint32_t getHeuristicValue(solve::HeuristicsFlags flag) const;

        std::string toString(const std::string& id = "") const;
        std::vector<std::unique_ptr<Board>> getAllowedMoves() const;
    };
}

#endif //INC_8_PUZZLE_SOLVER_BOARD_HPP
