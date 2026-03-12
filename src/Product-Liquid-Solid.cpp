
#include "Product-Liquid-Solid.h"
#include <iostream>
#include <stdexcept>

int Product::GetPrice() const {
    return price;
}

int Product::GetId() const {
    return id;
}

Product::Product(const std::string& name, int id, int price, char size)
    : name(name), id(id), price(price), size(size) {}

std::string Product::GetName() const {
    return name;
}

char Product::GetSize() const {
    return size;
}

void Product::ChangePrice(int NewPrice) {
    if (NewPrice < 0) {
        throw std::invalid_argument("Ошибка: цена не может быть отрицательной");
    }
    price = NewPrice;
}

void Product::give() const {}



LiquidProduct::LiquidProduct(const std::string& name, int id, int price, char size,
                             int V, bool Sprkl)
    : Product(name, id, price, size), VolumeML(V), IsSparkling(Sprkl) {
    if (V <= 0) {
        throw std::invalid_argument("Ошибка: объем должен быть положительным");
    }
}

void LiquidProduct::ChangeVolume(int NewVolume) {
    if (NewVolume <= 0) {
        throw std::invalid_argument("Ошибка: объем должен быть положительным");
    }
    VolumeML = NewVolume;
}

int LiquidProduct::GetVolumeML() const {
    return VolumeML;
}

bool LiquidProduct::GetIsSparkling() const {
    return IsSparkling;
}






SolidProduct::SolidProduct(const std::string& name, int id, int price, char size,
                           int M, bool CrflDsp)
    : Product(name, id, price, size), MassGR(M), CarefulDisp(CrflDsp) {
    if (M <= 0) {
        throw std::invalid_argument("Ошибка: масса должна быть положительной");
    }
}

void SolidProduct::ChangeMass(int NewMass) {
    if (NewMass <= 0) {
        throw std::invalid_argument("Ошибка: масса должна быть положительной");
    }
    MassGR = NewMass;
}

int SolidProduct::GetMass() const {
    return MassGR;
}

bool SolidProduct::GetCarefulDisp() const {
    return CarefulDisp;
}
