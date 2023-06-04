#include "Wallet.h"
#include <iostream>

int main() {
    Wallet wallet{};
    wallet.insertCurrency("BTC", 1.5);
    std::cout << "Wallet should contain 1.5 BTC now" << std::endl;
    std::cout << wallet.toString() << std::endl;
    
    bool result = wallet.containsCurrency("BTC", 1.5);
    std::cout << "Result should be true: " << std::boolalpha << result << std::endl;
    
    result = wallet.removeCurrency("BTC", 2.0);
    std::cout << "Result should be false: " << std::boolalpha << result << std::endl;
    
    result = wallet.removeCurrency("BTC", 1.0);
    std::cout << "Result should be true: " << std::boolalpha << result << std::endl;
    
    return 0;
}

Wallet::Wallet() {}

void Wallet::insertCurrency(const std::string& type, double amount) {
    currencies[type] += amount;
}

bool Wallet::removeCurrency(const std::string& type, double amount) {
    auto iter = currencies.find(type);
    if (iter != currencies.end()) {
        double& balance = iter->second;
        if (balance >= amount) {
            balance -= amount;
            return true;
        }
    }
    return false;
}

bool Wallet::containsCurrency(const std::string& type, double amount) {
    auto iter = currencies.find(type);
    if (iter != currencies.end()) {
        double& balance = iter->second;
        return (balance >= amount);
    }
    return false;
}

std::string Wallet::toString() {
    std::string result;
    for (const auto& currency : currencies) {
        result += currency.first + ": " + std::to_string(currency.second) + "\n";
    }
    return result;
}

