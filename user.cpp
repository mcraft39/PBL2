#include<bits/stdc++.h>
using namespace std;
#include "time.cpp"
#include "money.cpp"
#include "bill.cpp"

const int Debt = 1'000'000;

int credit;

class User {
    string User_ID;
    string username;

    protected:
    Money wallet; // -> balance;
    Time dateJoined, lastJoined;

    public:
    User(string, string, Money, Time);
    friend ostream& operator << (ostream& out, const User &me) ;
    bool Transaction(User, int);
};

User::User(string ID, string name, Money Wallet, Time firstTime) 
    : User_ID(ID), username(name) { wallet = Wallet; dateJoined = lastJoined = firstTime; }


ostream& operator << (ostream& out, const User &me) {
    out << "Ten: " << me.username << "\nSo tien hien tai: " << me.wallet << "\nNgay tham gia: " << me.dateJoined;
    return out;
}  

bool User::Transaction(User reciever, int amount) {
    Money recieverWallet = reciever.wallet;

    wallet -= amount;
    recieverWallet += amount;

    bool saveBill = 0;
    if (saveBill) {
        return 0;
    }

    return 1;
}


