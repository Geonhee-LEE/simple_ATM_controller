#include <iostream>

class BankAPI{

    public:
        BankAPI();
        ~BankAPI(){};

    private:
        virtual void respondPINNumber();
}