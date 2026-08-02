/**
 * @file CustomerData.hpp
 * @author Geonhee Lee (gunhee6392@gamil.com)
 * @brief Virtual Database server dummy file to protect and provide the user information
 * @version 0.1
 * @date 2026-08-02
 * @copyright Apache License(c) 2026
 */

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <mutex>

struct Card{
    std::string pin_number;
    std::string account_name;
    long long account_number;
    long long amount;
};

class CustomerData{

    public:
        CustomerData(){
            loadExistingAccounts();
        }
        ~CustomerData() = default;

        void createAccounts(long long card_num, std::string pin_number, std::string account_name, long long account_number, long long amount){
            std::lock_guard<std::mutex> lock(mtx_);
            cards_[card_num] = Card{pin_number, account_name, account_number, amount};
        }

        bool validateUserUnlocked(long long card_num) const{
            return cards_.find(card_num) != cards_.end();
        }

        bool validateUser(long long card_num){
            std::lock_guard<std::mutex> lock(mtx_);
            return validateUserUnlocked(card_num);
        }

        Card getUserInformation(long long card_num){
            std::lock_guard<std::mutex> lock(mtx_);

            if(!validateUserUnlocked(card_num)){
                std::cout << "Invalid card number!" << "\n";
                return Card{};
            }

            return cards_[card_num];
        }

    private:

        // A bank API wouldn't give the ATM the PIN number, but it can tell you if the PIN number is correct or not
        std::mutex mtx_;
        std::map<long long, Card> cards_;

        void loadExistingAccounts(){
            std::lock_guard<std::mutex> lock(mtx_);

            // Load the (dummy) user information
            cards_[11111111] = Card{"1111", "Geonhee", 1001, 10000};
            cards_[22222222] = Card{"2222", "John",    1002, 10000};
            cards_[33333333] = Card{"3333", "James",   1003, 10000};

        }

};
