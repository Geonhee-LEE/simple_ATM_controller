/**
 * @file main.cpp
 * @author Geonhee Lee (gunhee6392@gamil.com)
 * @brief Simple entry point to exercise the bank API
 * @version 0.1
 * @date 2026-08-02
 * @copyright Apache License(c) 2026
 */

#include "KoreaBank.hpp"

#include <iostream>

int main(){
    KoreaBank bank;

    bank.insertCard(11111111); // Existing User = [11111111, 22222222, 33333333] 
    
    
    bank.selectAccount(3);

    std::cout << "balance : " << bank.showBalance() << "\n";
    std::cout << "deposit : " << bank.deposit(50000) << "\n";
    std::cout << "withdraw: " << bank.withdraw(3000000) << "\n";

    return 0;
}
