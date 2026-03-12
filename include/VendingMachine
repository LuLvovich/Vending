#ifndef UNTITLED7_VENDINGMACHINE_H
#define UNTITLED7_VENDINGMACHINE_H

#include <vector>
#include <memory>
#include <optional>
#include <string>
#include <stdexcept>
#include "Product-Liquid-Solid.h"
#include "Inventory.h"
#include "MoneyHandler.h"
#include "ChangeCalculator.h"

class VendingException : public std::runtime_error {
public:
    explicit VendingException(const std::string& msg) : std::runtime_error(msg) {}
};

class VendingMachine {
public:
    VendingMachine();
    ~VendingMachine() = default;

    void selectProduct(size_t id);// выбираем товар по ID
    void insertMoney(std::variant<double, std::string> payment);// потом деньги
    void purchase();// потом покупка
    void loadFromFile(const std::string& path);

    void addProduct(std::unique_ptr<Product> p);

    std::optional<int> getSelectedProductId() const;// ID выбранного товара
    bool setPriceById(size_t id, double newPrice);// изменить цену товара по ID

private:
    Inventory inventory;
    std::unique_ptr<MoneyHandler> money;
    std::shared_ptr<ChangeCalculator> calculator;

    std::optional<int> selectedId;
};


#endif //UNTITLED7_VENDINGMACHINE_H
