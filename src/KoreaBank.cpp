#include "KoreaBank.hpp"

#include <iostream>

KoreaBank::KoreaBank(){
}


void KoreaBank::insertCard(const int card_number){
    std::lock_guard<std::mutex> lock(mtx_);

    if(custom_data_.validateUser(card_number)){

        cout << "Found the user" << "\n";
        current_card_info_ = custom_data_.getUserInformation(card_number);
    }
    else{
        cout << "No information" << "\n";
    }

}


void KoreaBank::respondPINNumber(const std::string& pin_number){
    std::lock_guard<std::mutex> lock(mtx_);

    cout << "pin num: " << current_card_info_.pin_number << "\n";
}


void KoreaBank::selectAccount(const int account){
}


int KoreaBank::showBalance(){
    return -1;
}


int KoreaBank::deposit(int amount){
    return -1;
}


int KoreaBank::withdraw(int amount){
    return -1;
}