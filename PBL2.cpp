#include<iostream>
#include "food.cpp"
using namespace std;

int main() {
    Menu menu;

    menu.addItem(Menuitem("F01", "Instant Noodles", 25000, 50));
    menu.addItem(Menuitem("F02", "Fried Rice", 40000, 20));
    menu.addItem(Menuitem("D01", "Iced Coffee", 20000, 30));
    menu.addItem(Menuitem("D02", "Milk Tea", 30000, 25));

    menu.displayMenu();

}