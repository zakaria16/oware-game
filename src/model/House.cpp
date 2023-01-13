//
// Created by Zakaria on 14/12/2022.
//

#include "House.hpp"

using oware::House;

House House::getHoleFromIndex(uint8_t index) {
    if (index >= ROW_COUNT * COL_COUNT) {
        return {};
    }
    if (index < COL_COUNT) {
        return {0, index};
    } else {
        return {1, static_cast<uint8_t>(index - COL_COUNT)};
    }
}

uint8_t House::getIndex() const {
    return y + x * COL_COUNT;
}
