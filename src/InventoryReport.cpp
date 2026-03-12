#include "InventoryReport.h"
#include <iomanip>
#include <sstream>

void InventoryReport::addProduct(const ProductInfo& info) {
    ProductInfo clamped = info;
    if (clamped.stock > MAX_STOCK_PER_ID) {
        clamped.stock = MAX_STOCK_PER_ID;
    }
    products_.push_back(clamped);
}

bool InventoryReport::addNew(const ProductInfo& info) {
    for (const auto& p : products_) {
        if (p.id == info.id) {
            return false;
        }
    }
    if (products_.size() >= 60) {
        return false;
    }
    ProductInfo clamped = info;
    if (clamped.stock > MAX_STOCK_PER_ID) {
        clamped.stock = MAX_STOCK_PER_ID;
    }
    products_.push_back(clamped);
    return true;
}

bool InventoryReport::refill(size_t id, int quantity) {
    for (auto& p : products_) {
        if (p.id == id) {
            p.stock += quantity;
            if (p.stock > MAX_STOCK_PER_ID) {
                p.stock = MAX_STOCK_PER_ID;
            }
            return true;
        }
    }
    return false;
}

bool InventoryReport::setPrice(size_t id, double price) {
    for (auto& p : products_) {
        if (p.id == id) {
            p.price = price;
            return true;
        }
    }
    return false;
}

bool InventoryReport::consume(size_t id) {
    for (auto& p : products_) {
        if (p.id == id) {
            if (p.stock > 0) {
                --p.stock;
                return true;
            }
            return false;
        }
    }
    return false;
}

// вывод в консоль товаров 
std::string InventoryReport::formatConsole() const {
    std::ostringstream oss;
    oss << "ИНВЕНТАРЬ\n";
    for (const auto& p : products_) {
        oss << " " << p.id << ": " << p.name 
            << " " << p.price << "₽ [" << p.stock << "/" << MAX_STOCK_PER_ID << "]";
        if (p.low_stock()) oss << " ⚠️";
        oss << "\n";
    }
    return oss.str();
}

// тоже самое, но для админа
std::string InventoryReport::formatAdmin() const {
    std::ostringstream oss;
    oss << "🔧 АДМИН ОТЧЁТ:\n";
    for (const auto& p : products_) {
        oss << "ID:" << p.id << " | " << p.name 
            << " | " << p.price << "₽ | Запас: " << p.stock << "\n";
    }
    return oss.str();
}
