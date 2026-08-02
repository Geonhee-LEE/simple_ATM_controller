#pragma once


#include "BackAPI.hpp"
#include "CustomerData.hpp"


class KoreaBank : public BankAPI{
    public:
        KoreaBank();
        ~KoreaBank() override = default;

        void insertCard(int card_number) override;
        void respondPINNumber(const std::string& pin_number) override;
        void selectAccount(int account) override;
        int showBalance() override;
        int deposit(int amount) override;
        int withdraw(int amount) override;


    private:
};