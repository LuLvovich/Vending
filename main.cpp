#include "CLIParser.h"
#include "AdminPanel.h"
#include "InventoryReport.h"
#include "VendingMachine.h"
#include "Product-Liquid-Solid.h"
#include <iostream>
#include <string>
#include <memory>
#include <sstream>

int main() {
    CLIParser parser;
    AdminPanel admin;
    InventoryReport report;
    VendingMachine machine;

    // Товары для демонстрации на защите
    machine.addProduct(std::make_unique<LiquidProduct>("Кола",   1, 50,  'M', 330, true));
    machine.addProduct(std::make_unique<SolidProduct> ("Чипсы",  2, 80,  'S', 90,  false));
    machine.addProduct(std::make_unique<LiquidProduct>("Спрайт", 3, 55,  'M', 330, true));
    machine.addProduct(std::make_unique<SolidProduct> ("Орешки", 4, 90,  'S', 70,  true));


    int stock_default = 10;
    int stock_low = 2;
    report.addProduct({1, "Кола",   50.0, stock_default - 1});
    report.addProduct({2, "Чипсы",  80.0, stock_low});
    report.addProduct({3, "Спрайт", 55.0, stock_default});
    report.addProduct({4, "Орешки", 90.0, stock_default});

    std::cout << "Вендинговый автомат запущен\n";
    std::cout << "Команды: inventory, select N, deposit X, buy, admin, "
                 "refill ID QTY, price ID VALUE, add, quit, exitadmin\n> ";

    // обработки команд
    std::string line;
    while (std::getline(std::cin, line)) {
        auto result = parser.parse(line);

        try {
            switch (result.cmd) {
                case CLIParser::Command::SELECT: {
                    if (!result.product_id) {
                        std::cout << "Укажите номер товара: select N\n";
                        break;
                    }
                    machine.selectProduct(*result.product_id);
                    break;
                }

                case CLIParser::Command::DEPOSIT: {
                    if (!result.amount) {
                        std::cout << "Укажите сумму: deposit X\n";
                        break;
                    }
                    machine.insertMoney(*result.amount);
                    break;
                }

                case CLIParser::Command::BUY: {
                    auto selectedId = machine.getSelectedProductId();
                    machine.purchase();
                    if (selectedId) {
                        if (!report.consume(static_cast<size_t>(*selectedId))) {
                            std::cout << "Не удалось уменьшить остаток товара ID "
                                      << *selectedId << " (в отчёте не найден или уже 0)\n";
                        }
                    }
                    break;
                }

                case CLIParser::Command::INVENTORY: {
                    std::cout << report.formatConsole() << "\n";
                    break;
                }
                case CLIParser::Command::ADMIN: {
                    std::string pwd;
                    std::cout << "Пароль: ";
                    std::getline(std::cin, pwd);
                    admin.enterAdminMode(pwd);
                    if (admin.isAdmin()) {
                        std::cout << report.formatAdmin() << "\n";
                    }
                    break;
                }

                case CLIParser::Command::EXITADMIN: {
                    admin.exitAdminMode();
                    break;
                }

                case CLIParser::Command::REFILL: {
                    if (!admin.isAdmin()) {
                        std::cout << "[ERROR] Сначала войдите в режим admin\n";
                        break;
                    }
                    if (!result.product_id || !result.amount) {
                        std::cout << "Использование: refill ID QTY\n";
                        break;
                    }
                    const auto id = *result.product_id;
                    const int qty = static_cast<int>(*result.amount);
                    admin.refillProduct(id, qty);
                    if (report.refill(id, qty)) {
                        std::cout << "Товар #" << id << " пополнен на " << qty << " шт\n";
                    } else {
                        std::cout << "Товар с ID " << id << " не найден в отчёте\n";
                    }
                    break;
                }

                case CLIParser::Command::PRICE: {
                    if (!admin.isAdmin()) {
                        std::cout << "[ERROR] Сначала войдите в режим admin\n";
                        break;
                    }
                    if (!result.product_id || !result.amount) {
                        std::cout << "Использование: price ID VALUE\n";
                        break;
                    }
                    const auto id = *result.product_id;
                    const double newPrice = *result.amount;
                    admin.setProductPrice(id, newPrice);
                    if (report.setPrice(id, newPrice)) {
                        std::cout << "Цена товара #" << id << " изменена на " << newPrice << "₽\n";
                    } else {
                        std::cout << "Товар с ID " << id << " не найден в отчёте\n";
                    }
                    if (!machine.setPriceById(id, newPrice)) {
                        std::cout << "Товар с ID " << id << " не найден в автомате\n";
                    }
                    break;
                }

                case CLIParser::Command::ADD: {
                    if (!admin.isAdmin()) {
                        std::cout << "[ERROR] Сначала войдите в режим admin\n";
                        break;
                    }
                    std::cout << "Введите ID, КОЛИЧЕСТВО, цену и имя товара:\n";
                    std::cout << "Пример: 5 20 45 НоваяКола\n> ";
                    std::string lineAdd;
                    if (!std::getline(std::cin, lineAdd)) {
                        break;
                    }
                    std::istringstream iss(lineAdd);
                    size_t id;
                    int count;
                    double price;
                    std::string name;
                    if (!(iss >> id >> count >> price)) {
                        std::cout << "Формат: ID COUNT PRICE NAME\n";
                        break;
                    }
                    std::getline(iss, name);
                    if (!name.empty() && name.front() == ' ') {
                        name.erase(0, 1);
                    }
                    if (name.empty()) {
                        std::cout << "Нужно указать имя товара\n";
                        break;
                    }
                    auto p = std::make_unique<SolidProduct>(
                        name,
                        static_cast<int>(id),
                        static_cast<int>(price),
                        'S',
                        100,
                        false
                    );
                    machine.addProduct(std::move(p));

                    ProductInfo info{ id, name, price, count };
                    if (report.addNew(info)) {
                        std::cout << "🆕 Добавлен новый товар ID " << id
                                  << " (" << name << ") с ценой " << price << "₽\n";
                    } else {
                        std::cout << "Товар с таким ID уже существует в отчёте\n";
                    }
                    break;
                }

                case CLIParser::Command::QUIT: {
                    std::cout << "Автомат выключен\n";
                    return 0;
                }

                default: {
                    std::cout << "Команды: inventory, select N, deposit X, buy, admin, "
                                 "refill ID QTY, price ID VALUE, add, quit, exitadmin\n";
                    break;
                }
            }
        } catch (const VendingException& ex) {
            std::cout << "Ошибка автомата: " << ex.what() << "\n";
        } catch (const std::exception& ex) {
            std::cout << "Ошибка: " << ex.what() << "\n";
        }

        std::cout << "> ";
    }
    return 0;
}