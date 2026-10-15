#include<bits/stdc++.h>
#include "user.cpp"
using namespace std;

int main() {
    Money wallet(1676767676);
    cout << wallet << "\n";

    User mrA("M123", "Mr. A", wallet, Time(1, 2, 3));

    cout << mrA;
}