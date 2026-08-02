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

bool selectMode(KoreaBank& bank, int mode){
    int money;

    switch(mode){
        case 1:
            money = bank.showBalance();
            cout << ">> current balance: " << money << "\n";
            return true;
        case 2:
            cout << ">> Please the deposit you want" << "\n";
            std::cin >> money;
            money = bank.deposit(money); 
            cout << ">> current balance: " << money << "\n";
            return true;
        case 3:
            cout << ">> Please the deposit you want" << "\n";
            std::cin >> money;
            money = bank.withdraw(money);
            cout << ">> current balance: " << money << "\n";
            return true;
        case 4:
            return false;
        default:
            return false;
    }
}

void showProcess(){
    cout << "==============================================" << "\n";
    cout << "| How can I help you? Please enter a number" << "\n";
    cout << "| >> [1] SEE balance" << "\n";
    cout << "| >> [2] Deposit" << "\n";
    cout << "| >> [3] Withdraw" << "\n";
    cout << "| >> [4] Exit" << "\n";
    cout << "==============================================" << "\n";

}


int main(){
    KoreaBank bank;

    std::cout << "Please insert the card: \n";
    bank.insertCard(11111111); // Existing User = [11111111, 22222222, 33333333] 
    std::cout << "Please select the account: \n";
    int pin, mode;
    std::cin >> pin;
    bank.selectAccount(pin);

    
    while(bank.checkDiagnosis()){
        showProcess();
        std::cin >> mode;
        if(!selectMode(bank, mode))
            break;
    }

    return 0;
}
