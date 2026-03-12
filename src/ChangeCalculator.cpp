#include "ChangeCalculator.h"
#include <cmath>

std::vector<int> ChangeCalculator::calculate(double amount) const {
    std::vector<int> notes;

    int remaining = static_cast<int>(std::round(amount));

    for (int denom : DENOMINATIONS) {
        while (remaining >= denom) {
            notes.push_back(denom);
            remaining -= denom;
        }
    }

    return notes;
}
