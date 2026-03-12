#include "MoneyHandler.h"
#include <iostream>
#include <variant>
#include <type_traits>

void MoneyHandler::deposit(std::variant<double, std::string> payment) {
    std::visit([this](auto&& a) {
        using T = std::decay_t<decltype(a)>;
        if constexpr (std::is_same_v<T, double>) {
            balance += a;
        } else if constexpr (std::is_same_v<T, std::string>) {
            std::cout << "Строковый платёж не поддерживается напрямую, игнорируем: " << a << "\n";
        }
    }, payment);
}

double MoneyHandler::getBalance() const {
    return balance;
}

void MoneyHandler::spend(double amount) {
    balance -= amount;
}

bool MoneyHandler::canAfford(double amount) const {
    return balance >= amount;
}

void MoneyHandler::reset() {
    balance = 0;
}
