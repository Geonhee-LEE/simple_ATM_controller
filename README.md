# Overview
- Implement the simple ATM controller


# Features
- The simple ATM controller is based on abstract BankAPI class which is consisted of virtual functions. The Korean bank class inherit the BankAPI and overide the functions. Also, you can extend the new bank class easily like USA Bank, Swiss Bank, etc and customize it. 
- After running the program, You can choice the mode like "[1] see balance, [2] Deposit, [3] Withdraw, [4] Exit". This program assume the particular card number since the existing card number are saved on the Customer Database (Dummy DB Server). If you want to change the card number, you can change the argument of `main.cpp- insertCard()` which is already commented for the another card numbers.

# Requirements
- Ubuntu 24.04 LTS
- `sudo apt update && sudo apt install cmake`

# How to configure and build 
```
git clone https://github.com/Geonhee-LEE/simple_ATM_controller
cd simple_ATM_controller
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build -j
```

# How to test and run
```
./build/seoul_atm
```
