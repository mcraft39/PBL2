#include<bits/stdc++.h>
using namespace std;

class Money {
    private:
        int balance;
    public:
    Money(int m = 0) : balance(m) {};

    friend ostream& operator << (ostream&, const Money&);
    Money operator += (int amount) { return (balance += amount); };
    Money operator -= (int amount) { return (balance -= amount); };
    void set(int amount) { balance = amount; };
    int get() { return balance; };
};  

ostream& operator << (ostream& out, const Money& M) {
    int amount = M.balance;
    string num;
    int cnt = 0;
    if (amount < 0) cout << "-";
    do {
        num.push_back(amount % 10 + '0');
        amount /= 10, ++cnt;
        if (amount > 0 && cnt % 3 == 0) num.push_back(',');
    } while (amount != 0);

    reverse(num.begin(), num.end());
    // cout << "So tien: ";s
    out << num << " VND";
    return out;
}   
/*

32,305
*/