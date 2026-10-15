#include<bits/stdc++.h>
using namespace std;

class Bill {
    private:
        int balance;
    public:
    Bill(int m = 0) : balance(m) {};

    friend ostream& operator << (ostream&, const Bill&);
    Bill operator += (int amount) { return (balance += amount); };
    Bill operator -= (int amount) { return (balance -= amount); };


    void set(int amount) { balance = amount; };
    int get() { return balance; };
};  

ostream& operator << (ostream& out, const Bill& M) {
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
    cout << "So tien: ";
    out << num << " VND";
    return out;
}   
/*

ABCD
DCBA
1,005,000
1,234,
765,432,1
567



32,305
*/