#include<iostream>
#include<iomanip>
#include<vector>
using namespace std;

class Menuitem {
    string name, id;
    int price, stock;
    public:
    Menuitem(string, string, int, int);
    void getID() const { cout << id << endl; }
    void getName() const { cout << name << endl; }
    void getPrice() const { cout << price << endl; }
    void getStock() const { cout << stock << endl; }
    friend ostream& operator << (ostream& out, const Menuitem& M) {
        out << left << setw(10) << M.id << setw(20) << M.name << setw(10) << fixed << setprecision(0) << M.price << "VND\n";
        return out;
    }
    void updateStock(int);
};

Menuitem::Menuitem(string id, string name, int price, int stock) : id(id), name(name), price(price), stock(stock) {}

void Menuitem::updateStock(int newStock) {
    this->stock += newStock;
}

class Menu {
    vector<Menuitem> items;
    public:
    void addItem(Menuitem);
    void displayMenu() const;
    
};

void Menu::addItem(Menuitem item) {
    items.push_back(item);
}

void Menu::displayMenu() const {
    cout << left << setw(10) << "ID" << setw(20) << "Name" << setw(10) << "Price" <<endl;
    int n=items.size();
    for (int i=0; i<n; i++) {
        cout << items[i];
    }
}