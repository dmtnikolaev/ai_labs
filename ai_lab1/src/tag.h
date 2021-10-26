#ifndef AI_LAB1_TAG_H
#define AI_LAB1_TAG_H

#include <array>
#include <vector>
#include <string>

constexpr static int kFieldSize = 3;
constexpr static int kNextStatesMax = 4;
using field_t = std::array<std::array<int, kFieldSize>, kFieldSize>;

struct CellAddr {
    int row;
    int col;
};

class TagState {
public:
    TagState(const field_t& field, CellAddr empty_cell_address);
    [[nodiscard]] std::vector<TagState> NextStates() const;
    bool operator==(const TagState& rhs) const;
    [[nodiscard]] std::string ToString() const;
private:
    field_t field_{};
    CellAddr empty_cell_addr_;
    [[nodiscard]] TagState SwapCell(CellAddr addr) const;
};

#endif //AI_LAB1_TAG_H
