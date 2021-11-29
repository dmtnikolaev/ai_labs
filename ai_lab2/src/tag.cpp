#include "tag.h"

#include <string>

TagState::TagState(const field_t& field, CellAddr empty_cell_addr) :
    field_(field), empty_cell_addr_(empty_cell_addr) {}

std::vector<TagState> TagState::NextStates() const {
    std::vector<TagState> next_states;
    next_states.reserve(kNextStatesMax);

    auto erow = empty_cell_addr_.row;
    auto ecol = empty_cell_addr_.col;
    std::array<CellAddr, kNextStatesMax> potential_swaps{{
        {erow - 1, ecol},
        {erow, ecol - 1},
        {erow + 1, ecol},
        {erow, ecol + 1}
    }};

    for (auto addr : potential_swaps) {
        if (addr.row < 0 || addr.row > 2 ||
            addr.col < 0 || addr.col > 2) {
            continue;
        }
        next_states.push_back(SwapCell(addr));
    }

    return next_states;
}

bool TagState::operator==(const TagState& rhs) const {
    return field_ == rhs.field_;
}

TagState TagState::SwapCell(CellAddr addr) const {
    auto new_state = TagState(*this);
    new_state.field_[empty_cell_addr_.row][empty_cell_addr_.col] =
        new_state.field_[addr.row][addr.col];
    new_state.field_[addr.row][addr.col] = 0;
    new_state.empty_cell_addr_ = addr;
    return new_state;
}

std::string TagState::ToString() const {
    std::string str;

    for (auto i = 0; i < kFieldSize; ++i) {
        str += " | ";

        for (auto j = 0; j < kFieldSize; ++j) {
            if (this->field_[i][j] == 0) {
                str += "  ";
                continue;
            }
            str += std::to_string(this->field_[i][j]);
            str += " ";
        }

        str += "| \n";
    }

    return str;
}



