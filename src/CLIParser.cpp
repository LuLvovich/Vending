#include "CLIParser.h"
#include <sstream>
#include <algorithm>
#include <cctype>

CLIParser::ParseResult CLIParser::parse(const std::string& input) {
    last_input_ = input;
    std::istringstream iss(input);
    std::string token;
    iss >> token;
    
    std::transform(token.begin(), token.end(), token.begin(), [](unsigned char c){ 
        return std::toupper(c); 
    });


    // обработки команд

    if (token == "SELECT" || token == "S") {
        size_t id;
        if (iss >> id) return {Command::SELECT, id, std::nullopt};
    }
    else if (token == "DEPOSIT" || token == "D") {
        double amount;
        if (iss >> amount) return {Command::DEPOSIT, std::nullopt, amount};
    }
    else if (token == "BUY" || token == "B") {
        size_t id;
        if (iss >> id) {
            return {Command::BUY, id, std::nullopt};
        }
        return {Command::BUY, std::nullopt, std::nullopt};
    }
    else if (token == "INVENTORY" || token == "I") {
        return {Command::INVENTORY, std::nullopt, std::nullopt};
    }
    else if (token == "ADMIN" || token == "A") {
        return {Command::ADMIN, std::nullopt, std::nullopt};
    }
    else if (token == "EXITADMIN" || token == "E") {
        return {Command::EXITADMIN, std::nullopt, std::nullopt};
    }
    else if (token == "REFILL" || token == "R") {
        size_t id;
        double qty;
        if (iss >> id >> qty) {
            return {Command::REFILL, id, qty};
        }
    }
    else if (token == "PRICE" || token == "P") {
        size_t id;
        double newPrice;
        if (iss >> id >> newPrice) {
            return {Command::PRICE, id, newPrice};
        }
    }
    else if (token == "ADD") {
        return {Command::ADD, std::nullopt, std::nullopt};
    }
    else if (token == "QUIT" || token == "Q") {
        return {Command::QUIT, std::nullopt, std::nullopt};
    }
    
    return {Command::UNKNOWN, std::nullopt, std::nullopt};
}