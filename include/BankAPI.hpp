/**
 * @file BankAPI.hpp
 * @author Geonhee Lee (gunhee6392@gamil.com)
 * @brief BANK API Class
 * @version 0.1
 * @date 2026-08-02
 * @copyright Apache License(c) 2026
 */

#pragma once

#include <iostream>
#include <string>

/** Base API  class 
* Abstract the virtual functions to inherit the each bank company
**/
class BankAPI{

    public:
        BankAPI() = default;
        virtual ~BankAPI() = default;

        virtual void insertCard(int card_number) = 0;
        virtual void respondPINNumber(const int pin_number) = 0;
        virtual void selectAccount(int account) = 0;
        virtual int showBalance() = 0;
        virtual int deposit(int amount) = 0;
        virtual int withdraw(int amount) = 0;

    protected:
        int card_number_ = 0;
        int selected_account_ = 0;
};