#ifndef UNTITLED7_CHANGECALCULATOR_H
#define UNTITLED7_CHANGECALCULATOR_H
#include <array>
#include <vector>

class ChangeCalculator {
public:
    constexpr static std::array<int, 9> DENOMINATIONS{1000, 500, 200, 100, 50, 10, 5, 2, 1};

    std::vector<int> calculate(double amount) const;
};


#endif //UNTITLED7_CHANGECALCULATOR_H
