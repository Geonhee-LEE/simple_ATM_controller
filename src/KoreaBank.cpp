#include "KoreaBank.hpp"

#include <iostream>

/**
 * @brief Constructor
 */
KoreaBank::KoreaBank(){
    is_connected_ = false;
}

/**
 * @brief Insert the card and Validated the card for user database. 
 * @param card_number selected card
 */
void KoreaBank::insertCard(const int card_number){
    std::lock_guard<std::mutex> lock(mtx_);

    if(custom_data_.validateUser(card_number)){
        cout << "================================" << "\n";
        cout << "Welcome to the Korea Bank!" << "\n";
        current_card_info_ = custom_data_.getUserInformation(card_number);
        respondPINNumber(card_number);
        showAccounts();
    }
    else{
        cout << "[Wrong information] Please check the card again!" << "\n";
    }

}


/**
 * @brief Respond the pin number for input card number
 * @param card_number selected card
 */
void KoreaBank::respondPINNumber(const int card_number){
    cout << "The card's pin num: " << current_card_info_.pin_number << "\n";
}


/**
 * @brief Show the accounts info
 */
void KoreaBank::showAccounts(){
    for(uint i = 0; i < current_card_info_.account_name.size(); i++){
        cout << ">>> [" << i << "]" << " Account name: " << current_card_info_.account_name[i] << "\n";
        cout << ">>> [" << i << "]" << " Account num: " << current_card_info_.account_number[i] << "\n";
        cout << "----------------------" << "\n";
    }
    cout << "================================" << "\n";

}

/**
 * @brief Check the atm connection status
 */
bool KoreaBank::checkDiagnosis(){
    if(!is_connected_)
        return false;
    else
        return true;
}


/**
 * @brief Select the account of the saved card 
 * @param account selected account
 */
void KoreaBank::selectAccount(const int account){

    std::lock_guard<std::mutex> lock(mtx_);

    if(account >= current_card_info_.account_name.size()){
        cout << "You should select the number of account!! Retry again!" << "\n";
        return;
    }
    else{
        selected_account_ = account;
        cout << "Hi! " << current_card_info_.account_name[selected_account_] << "\n";
        is_connected_ = true;
    }

    // Updated the selected account

}


/**
 * @brief Show the balance about the account 
 * @return current amount
 */
int KoreaBank::showBalance(){
    std::lock_guard<std::mutex> lock(mtx_);
    if(!is_connected_){
        cout << "Please retry again!" << "\n";
        return false;
    }

    return current_card_info_.amount[selected_account_];
}


/**
 * @brief Plus the money for current balance 
 * @param amount input money 
 * @return current amount after deposit
 */
int KoreaBank::deposit(int amount){
    std::lock_guard<std::mutex> lock(mtx_);
    if(!is_connected_){
        cout << "Please retry again!" << "\n";
        return false;
    }
    
    current_card_info_.amount[selected_account_] += amount;
    return current_card_info_.amount[selected_account_];
}


/**
 * @brief Substract the money for current balance 
 * @param amount input money 
 * @return current amount after withdraw
 */
int KoreaBank::withdraw(int amount){
    std::lock_guard<std::mutex> lock(mtx_);
    if(!is_connected_){
        cout << "Please retry again!" << "\n";
        return false;
    }
    
    if(current_card_info_.amount[selected_account_] - amount < 0)
        cout << "Unable to withdraw due to enough balance. Please check again." << "\n";
    else
        current_card_info_.amount[selected_account_] -= amount;

     
    return current_card_info_.amount[selected_account_];
}