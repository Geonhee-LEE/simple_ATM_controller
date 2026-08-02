#pragma once


#include "BankAPI.hpp"
#include "CustomerData.hpp"

using namespace std;

class KoreaBank : public BankAPI{
    public:
        KoreaBank();
        ~KoreaBank() override = default;

        void insertCard(const int card_number) override;
        void respondPINNumber(const int pin_number) override;
        void selectAccount(const int account) override;
        int showBalance() override;
        int deposit(int amount) override;
        int withdraw(int amount) override;

        void showAccounts();


    private:
        std::mutex mtx_;
        bool is_connected_;
        CustomerData custom_data_;
        Card current_card_info_;
};