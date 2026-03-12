
#include "Inventory.h"


bool Inventory::AddProduct(std::unique_ptr<Product> product) {
    if (!product) {
        return false;
    }
    if (products.size() >= MAX_UNIQUE_IDS) {
        return false;
    }
    if (IdExists(product->GetId())) {
        return false;
    }
    products.push_back(std::move(product));
    return true;
}

void Inventory::AddLiquidProduct(int id, const std::string& name, int price, char size, int volume, bool sparkling) {
    if (products.size() >= MAX_UNIQUE_IDS) {
        throw std::runtime_error("Достигнут лимит уникальных товаров ");
    }
    if (IdExists(id)) {
        throw std::invalid_argument("Товар с таким ID уже существует");
    }
    std::unique_ptr<Product> product = std::make_unique<LiquidProduct>(name, id, price, size, volume, sparkling);
    products.push_back(std::move(product));
}

void Inventory::AddSolidProduct(int id, const std::string& name, int price, char size, int mass, bool careful) {
    if (products.size() >= MAX_UNIQUE_IDS) {
        throw std::runtime_error("Достигнут лимит уникальных товаров");
    }
    if (IdExists(id)) {
        throw std::invalid_argument("Товар с таким ID уже существует");
    }
    std::unique_ptr<Product> product = std::make_unique<SolidProduct>(name, id, price, size, mass, careful);
    products.push_back(std::move(product));
}




Product* Inventory::FindById (int id) const {
    for (size_t i = 0; i < products.size(); ++i) {
        if (products[i]->GetId() == id) {
            return products[i].get();
        }
    }
    throw std::invalid_argument("Товара с таким ID нет");
}

bool Inventory::IdExists(int id) const {
    for (size_t i = 0; i < products.size(); ++i) {
        if (products[i]->GetId() == id) {
            return true;
        }
    }
    return false;
}

bool Inventory::GiveProduct(int id) {
    Product* product = FindById(id);
    if (!product) {
        return false;
    }

    product->give();
    return true;
}

size_t Inventory::GetCount() const {
    return products.size();
}

bool Inventory::IsEmpty() const {
    return products.empty();
}

