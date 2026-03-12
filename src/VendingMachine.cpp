#include "VendingMachine.h"
#include <fstream>
#include <iostream>

VendingMachine::VendingMachine()
    : inventory(),
      money(std::make_unique<MoneyHandler>()),
      calculator(std::make_shared<ChangeCalculator>()),
      selectedId(std::nullopt) {}

void VendingMachine::selectProduct(size_t id) {
    Product* p = inventory.FindById(static_cast<int>(id));
    if (!p) {
        throw VendingException("Товара с таким ID не существует");
    }
    selectedId = static_cast<int>(id);
    std::cout << "Товар выбран: " << p->GetName()
              << " за " << p->GetPrice() << "₽\n";
}

void VendingMachine::insertMoney(std::variant<double, std::string> payment) {
    money->deposit(std::move(payment));
    std::cout << "Баланс: " << money->getBalance() << "₽\n";
}

void VendingMachine::purchase() {
    if (!selectedId.has_value()) {
        throw VendingException("Сначала выберите товар командой 'select N'");
    }

    const int id = *selectedId;
    Product* p = inventory.FindById(id);
    if (!p) {
        throw VendingException("Выбранный товар недоступен");
    }

    const double price = static_cast<double>(p->GetPrice());
    if (!money->canAfford(price)) {
        throw VendingException("Недостаточно средств. Цена: " + std::to_string(price) + "₽");
    }

    money->spend(price);
    inventory.GiveProduct(id);

    const double changeAmount = money->getBalance();
    if (changeAmount > 0.0) {
        const auto notes = calculator->calculate(changeAmount);
        std::cout << "Сдача (" << changeAmount << "₽): ";
        for (int n : notes) {
            std::cout << n << "₽ ";
        }
        std::cout << "\n";
    }

    money->reset();
    selectedId.reset();
}

void VendingMachine::loadFromFile(const std::string& path) {
    std::ifstream file(path);
    if (!file.is_open()) {
        throw VendingException("Не удалось открыть файл: " + path);
    }
    std::cout << "Инвентарь загружен из файла: " << path << " (RAII)\n";
}

void VendingMachine::addProduct(std::unique_ptr<Product> p) {
    inventory.AddProduct(std::move(p));
}

std::optional<int> VendingMachine::getSelectedProductId() const {
    return selectedId;
}

bool VendingMachine::setPriceById(size_t id, double newPrice) {
    Product* p = inventory.FindById(static_cast<int>(id));
    if (!p) return false;
    p->ChangePrice(static_cast<int>(newPrice));
    std::cout << "Цена товара #" << id << " изменена на " << newPrice << "₽\n";
    return true;
}
