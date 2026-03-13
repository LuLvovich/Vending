
#ifndef PRODUCT_LIQUID_SOLID_H
#define PRODUCT_LIQUID_SOLID_H

#include <string>

class Product{
protected:
    std::string name;
    int id;
    int price;
    char size;
public:
    Product()=delete;
    virtual ~Product() = default;
    Product(const std::string& name, int id, int price, char size);

    int GetPrice() const;
    int GetId() const;
    std::string GetName() const;
    char GetSize() const;

    void ChangePrice(int NewPrice);

    virtual void give() const;

    std::string getName() const;
    double getPrice() const;
};

class LiquidProduct: public Product{
protected:
    int VolumeML;
    bool IsSparkling;

public:
    LiquidProduct(const std::string& name, int id, int price, char size, int V, bool Sprkl);
    void ChangeVolume(int NewVolume);
    int GetVolumeML() const;
    bool GetIsSparkling() const;
	~LiquidProduct() = default;
};

class SolidProduct: public Product{
protected:
    int MassGR;
    bool CarefulDisp;
public:
    SolidProduct(const std::string& name, int id, int price, char size, int M, bool CrflDsp);
    void ChangeMass(int NewMass);
    int GetMass() const;
    bool GetCarefulDisp() const;
    ~SolidProduct() = default;
};

#endif