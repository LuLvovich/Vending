#include <string>
#include <vector>

class AdminPanel {
public:
    AdminPanel();
    ~AdminPanel();
    
    void enterAdminMode(const std::string& password);
    void exitAdminMode();
    
    void refillProduct(size_t id, int quantity);
    void setProductPrice(size_t id, double price);
    std::string generateReport() const;
    
    bool isAdmin() const { return admin_mode_; }

private:
    std::vector<int> product_stocks_; 
    bool admin_mode_ = false;
    std::string admin_password_ = "admin123";
};
