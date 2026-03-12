#include <vector>
#include <string>

struct ProductInfo {
    size_t id;
    std::string name;
    double price;
    int stock;
    bool low_stock() const { return stock < 3; }
};

class InventoryReport {
public:
    InventoryReport() = default;

    static constexpr int MAX_STOCK_PER_ID = 15;
    
    void addProduct(const ProductInfo& info);
    bool refill(size_t id, int quantity); 
    bool setPrice(size_t id, double price); 
    bool addNew(const ProductInfo& info); 
    bool consume(size_t id);               

    std::string formatConsole() const;
    std::string formatAdmin() const;
    size_t totalProducts() const { return products_.size(); }
    
private:
    std::vector<ProductInfo> products_;
};
