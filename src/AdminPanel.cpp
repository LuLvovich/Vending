#include "AdminPanel.h"
#include <iostream>

AdminPanel::AdminPanel() {
    std::cout << "[AdminPanel] Инициализация\n";
}

AdminPanel::~AdminPanel() {
    std::cout << "[AdminPanel] Закрытие сессии\n";
}

// войти в режим админа
void AdminPanel::enterAdminMode(const std::string& password) {
    if (password == admin_password_) {
        admin_mode_ = true;
        std::cout << "[ADMIN] Режим администратора активирован\n";
    } else {
        std::cout << "[ADMIN] Неверный пароль\n";
    }
}

// выйти из режима админа
void AdminPanel::exitAdminMode() {
    admin_mode_ = false;
    std::cout << "[ADMIN] Режим администратора деактивирован\n";
}

// пополнить товар по ID
void AdminPanel::refillProduct(size_t id, int quantity) {
    if (!admin_mode_) {
        std::cout << "[ERROR] Требуется админ-доступ\n";
        return;
    }
    std::cout << "[ADMIN] Пополнение товара #" << id << " на " << quantity << " шт\n";
}

// изменить цену товара по ID
void AdminPanel::setProductPrice(size_t id, double price) {
    if (!admin_mode_) {
        std::cout << "[ERROR] Требуется админ-доступ\n";
        return;
    }
    std::cout << "[ADMIN] Цена товара #" << id << " = " << price << "₽\n";
}

