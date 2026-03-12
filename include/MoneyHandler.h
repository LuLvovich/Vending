#ifndef UNTITLED7_MONEYHANDLER_H
#define UNTITLED7_MONEYHANDLER_H
#include <variant>
#include <string>


class MoneyHandler {
private:
    double balance = 0;
public:
    void deposit(std::variant<double, std::string> payment);
    double getBalance() const;
    void spend(double amount);
    bool canAfford(double amount) const;
    void reset();
};


#endif //UNTITLED7_MONEYHANDLER_H
