/**
 * @file BackAPI.hpp
 * @author Geonhee Lee (email@example.com)
 * @brief BANK API Class
 * @version 0.1
 * @date 2026-08-02
 * @copyright Apache License(c) 2026
 */

#include <iostream>
#include <string>

using namespace std;

/** Base API  class 
* Abstract the virtual functions to inherit the each bank company
**/
class BankAPI{

    public:
        BankAPI();
        ~BankAPI(){};

    private:
        int selected_account_; 
        int amount_; 
        int card_number_; 

        virtual void insertCard(int card_number) = 0;
        virtual constexpr void respondPINNumber(string pin_number) = 0;
        virtual void selectAccount(int account) = 0;
        virtual constexpr int showBalance() = 0;
        virtual int deposit() = 0;
        virtual int withdraw() = 0;

};