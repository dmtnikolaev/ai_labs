#include "assessment.h"
#include <cmath>

int NotInPlace::GetEval(const TagState &state) {
    int eval = 0;
    for (auto i = 0; i < kFieldSize; ++i) {
        for (auto j = 0; j < kFieldSize; ++j) {
            if (state.field_[i][j] != target_.field_[i][j]) {
                eval++;
            }
        }
    }

    return eval;
}

int Manhattan::GetEval(const TagState &state) {
    int eval = 0;
    for (auto i = 0; i < kFieldSize; ++i) {
        for (auto j = 0; j < kFieldSize; ++j) {
            for (auto p = 0; p < kFieldSize; ++p) {
                for (auto q = 0; q < kFieldSize; ++q) {
                    if (state.field_[i][j] == target_.field_[p][q]) {
                        eval += (abs(p - i) + abs(q - j));
                    }
                }
            }
        }
    }

    return eval;
}
