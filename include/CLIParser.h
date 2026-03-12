#include <string>
#include <optional>

class CLIParser {
public:
    enum class Command { 
        UNKNOWN,
        SELECT, // выбрать товар по ID
        DEPOSIT, // внести деньги в автомат
        BUY, // купить выбранный товар
        INVENTORY, // показать список товаров в автомате
        ADMIN, // войти в режим админа
        REFILL, // пополнить товар по ID
        PRICE,    // изменить цену товара по ID
        ADD,     // добавить новый товар
        QUIT, // выключить автомат
        EXITADMIN // выйти из режима админа
    };
    
    struct ParseResult {
        Command cmd;  
        std::optional<size_t> product_id;  
        std::optional<double> amount;     
    };
    
    CLIParser() = default;
    ParseResult parse(const std::string& input);
    std::string getLastCommand() const { return last_input_; }

private:
    std::string last_input_;
};

