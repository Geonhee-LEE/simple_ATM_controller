#include "KoreaBank.hpp"

#include <iostream>

KoreaBank::KoreaBank(){
}


void KoreaBank::insertCard(const int card_number){
    std::lock_guard<std::mutex> lock(mtx_);

    if(custom_data_.validateUser(card_number)){
        current_card_info_ = custom_data_.getUserInformation(card_number);
        respondPINNumber(card_number);
    }
    else{
        cout << "No information" << "\n";
    }

}


void KoreaBank::respondPINNumber(const int card_number){
    cout << ">> Current card's pin num: " << current_card_info_.pin_number << "\n";
    showAccounts();
}


void KoreaBank::showAccounts(){
    cout << "================================" << "\n";
    for(uint i = 0; i < current_card_info_.account_name.size(); i++){
        cout << "[" << i << "]" << " Account name: " << current_card_info_.account_name[i] << "\n";
        cout << "[" << i << "]" << " Account num: " << current_card_info_.account_number[i] << "\n";
    }
    cout << "================================" << "\n";

}

void KoreaBank::selectAccount(const int account){

    std::lock_guard<std::mutex> lock(mtx_);

    if(account > current_card_info_.account_name.size()){
        cout << "You should select the number of account" << "\n";
        return;
    }

    selected_account_ = account;
    /*
    
    std::string pin_number;

    std::vector<std::string> account_name;
    std::vector<long long> account_number;
    std::vector<long long> amount;
    */

    //current_card_info_ = custom_data_.getUserInformation(account);



    cout << "pin num: " << current_card_info_.pin_number << "\n";
    cout << "account_name.size(): " << current_card_info_.account_name.size() << "\n";
    cout << "account_number: " << current_card_info_.account_number.size() << "\n";
    cout << "amount: " << current_card_info_.amount.size() << "\n";


}


int KoreaBank::showBalance(){
    std::lock_guard<std::mutex> lock(mtx_);
    return current_card_info_.amount[selected_account_];
}


int KoreaBank::deposit(int amount){
    std::lock_guard<std::mutex> lock(mtx_);
    current_card_info_.amount[selected_account_] += amount;
    return current_card_info_.amount[selected_account_];
}


int KoreaBank::withdraw(int amount){
    std::lock_guard<std::mutex> lock(mtx_);
    if(current_card_info_.amount[selected_account_] - amount < 0)
        cout << "Unable to withdraw due to enough balance. Please check again." << "\n";
    else
        current_card_info_.amount[selected_account_] -= amount;

     
    return current_card_info_.amount[selected_account_];
}