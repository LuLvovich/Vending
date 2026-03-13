
#ifndef INVENTORY_H
#define INVENTORY_H

#include "Product-Liquid-Solid.h"
#include <vector>

class Inventory {
private:
    std::vector<std::unique_ptr<Product>> products;

    static constexpr std::size_t MAX_UNIQUE_IDS = 60;

public:
    Inventory() = default;
    ~Inventory() = default;


    Inventory(const Inventory&) = delete;
    Inventory& operator=(const Inventory&) = delete;


    Inventory(Inventory&&) = delete;
    Inventory& operator=(Inventory&&) = default;


    void AddLiquidProduct(int id, const std::string& name, int price, char size, int volume, bool sparkling);
    void AddSolidProduct(int id, const std::string& name, int price, char size, int mass, bool careful);
    bool AddProduct(std::unique_ptr<Product> product);


    Product* FindById(int id) const;


    bool GiveProduct(int id);


    bool IdExists(int id) const;
    size_t GetCount() const;
    bool IsEmpty() const;
    void DisplayAll(std::ostream& os) const;
};

#endif