//Simple Bank Project from scratch, to re-familiarize myself with OOP

#include <string>
#include <vector>
#include <iostream>

class Bank {
    private:
        float balance, withdrawl, deposit;

    public:

    Bank (float newBalance){
       balance = newBalance;

    }

    float getBalance(){
        return balance;
    }

    float getWithdral(){
        return withdrawl;
    }

    float getDeposit(){
        return deposit;
    }

    void setBalance(float newBalance){
        this->balance = newBalance;
    }

};

class Person {
    private:
        float accountNumber;
        std::string name;

    public:

    Person (float newAccountNumber, std::string newName){
        accountNumber = newAccountNumber;
        name = newName;
    }

    float getAccountNumber(){
        return accountNumber;
    }


    float actionWithdral (float withdrawl, Bank& balance){

        if (withdrawl <= balance.getBalance()){
            float newBalance = balance.getBalance() - withdrawl;
            balance.setBalance(newBalance);
            return newBalance;

        }
        else{
            std::cout << "\nError: Trying to withdrawl with no balance\n";
            exit(1);
        }

    }

    float actionDeposit (float deposit, Bank& balance){

        if (deposit > 0 ){
            float newBalance = balance.getBalance() + deposit;
            balance.setBalance(newBalance);
            return newBalance;
        }
        else{
            std::cout << "\nError: Invalid Deposit, must be greater than zero\n";
            exit(1);
        }
    }

    float checkBalance  (Bank balance){

        return balance.getBalance();
    }


};

    void menuScreen(){

    std::cout << "\n\t1. Set your balance" << std::endl;
    std::cout << "\t2. Check your balance" << std::endl;
    std::cout << "\t3. Withrawl balance" << std::endl;
    std::cout << "\t4. Deposit money" << std::endl;
    std::cout << "\t5. End the game" << std::endl;

}







int main(){

    std::cout << "\t----------------------------------------" << std::endl;
    std::cout << "\t-------- BANK BALANCE SYSTEM -----------" << std::endl;
    std::cout << "\t----------------------------------------" << std::endl;

    //create main variables
    int choice, accountNum;
    float balance, withdrawl, deposit, newBalance;

    std::string name = "Nick";

    //create objects
    Person person(accountNum, name);
    Bank bank(balance);

    while (choice != 5){

    menuScreen();

    std::cin >> choice;
    switch (choice)
    {
    case 1:
        std::cout << "Enter your balance" << std::endl;
        std::cin >> balance;
        bank.setBalance(balance);
        break;

    case 2:
        std::cout << "Your Balance: " << bank.getBalance() << std::endl;
        break;

    case 3:
        std::cout << "Enter your amount to withdrawl" << std::endl;
        std::cin >> withdrawl;
        newBalance = person.actionWithdral(withdrawl, bank);
        std::cout << "\nThank you for withdrawling\nYour updated balance: " << newBalance << std::endl;
        break;

    case 4:
        std::cout << "Enter the amount of money to deposit" << std::endl;
        std::cin >> deposit;
        newBalance = person.actionDeposit(deposit, bank);
        std::cout << "\nThanks for your deposit\nYour updated balance: " << newBalance << std::endl;
        break;

    case 5:
        std::cout << "Thank you for choosing our banking program\n";
        return 0;
        break;

    default:
        std::cout << "Invalid Operation";
        return 0;
    }
    }






    return 0;
}