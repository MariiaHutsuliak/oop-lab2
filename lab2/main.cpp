#include <iostream>
using namespace std;
#include <memory>
#include <fstream>
#include "Menu.h"
#include "Bar.h"
#include "Delivery.h"
#include "LuxuryBar.h"
#include "HealthyMenu.h"
#include "ShoppingCart.h"
#include "CartItem.h"

void saveMenuToFile(const vector<shared_ptr<Menu>>& menu) {
    ofstream file("menu1.txt", ios::app);
    if (!file.is_open()) {
        cerr << "Error: Unable to open file." << endl;
        return;
    }
    for (const auto& item : menu) {
        file << item->name << " " << item->price << " " << item->weight << endl;
    }
}
void loadMenuFromFile(vector<shared_ptr<Menu>>& menu) {
    ifstream file("menu1.txt");
    if (!file.is_open()) {
        cerr << "Error: Unable to open file." << endl;
        return;
    }
    menu.clear();
    string name;
    double price, weight;
    while (file >> name >> price >> weight) {
        menu.push_back(make_unique<Menu>(name, price, weight));
    }
}

void saveHealthyMenuToFile(const vector<shared_ptr<HealthyMenu>>& menu) {
    ofstream file("healthyMenu.txt", ios::app);
    if (!file.is_open()) {
        cerr << "Error: Unable to open file." << endl;
        return;
    }
    for (const auto& item : menu) {
        file << item->name << " " << item->price << " " << item->weight << " " << item->calories << " " << item->fatContent << endl;
    }
}
void loadHealthyMenuFromFile(vector<shared_ptr<HealthyMenu>>& menu) {
    ifstream file("healthyMenu.txt");
    if (!file.is_open()) {
        cerr << "Error: Unable to open file." << endl;
        return;
    }
    menu.clear();
    string name;
    double price, weight, calories, fatContent;
    while (file >> name >> price >> weight >> calories >> fatContent) {
        menu.push_back(make_unique<HealthyMenu>(name, price, weight, calories, fatContent));
    }
}

void saveBarToFile(const vector<shared_ptr<Bar>>& barMenu) {
    ofstream file("bar_menu.txt", ios::app);
    if (!file.is_open()) {
        cerr << "Error: Unable to open file." << endl;
        return;
    }

    for (const auto& item : barMenu) {
        file << item->name << " " << item->price << " " << item->special << endl;
    }
}
void loadBarFromFile(vector<shared_ptr<Bar>>& barMenu) {
    ifstream file("bar_menu.txt");
    if (!file.is_open()) {
        cerr << "Error: Unable to open file." << endl;
        return;
    }
    barMenu.clear();
    string name, special;
    double price;
    while (file >> name >> price >> special) {
        barMenu.push_back(make_unique<Bar>(name, price, special));
    }
}

void saveLuxuryBarToFile(const vector<shared_ptr<LuxuryBar>>& luxuryBarMenu) {
    ofstream file("luxury_bar_menu.txt", ios::app);
    if (!file.is_open()) {
        cerr << "Error: Unable to open file." << endl;
        return;
    }
    for (const auto& item : luxuryBarMenu) {
        file << item->name << " " << item->price << " " << item->special << " " << item->premiumQuality << " " << item->origin << endl;
    }
}

void loadLuxuryBarFromFile(vector<shared_ptr<LuxuryBar>>& luxuryBarMenu) {
    ifstream file("luxury_bar_menu.txt");
    if (!file.is_open()) {
        cerr << "Error: Unable to open file." << endl;
        return;
    }
    luxuryBarMenu.clear();
    string name, special, origin;
    double price;
    bool premiumQuality;
    while (file >> name >> price >> special >> premiumQuality >> origin) {
        luxuryBarMenu.push_back(make_unique<LuxuryBar>(name, price, special, premiumQuality, origin));
    }
}

int main() {
    vector<shared_ptr<Menu>> menu;
    vector<shared_ptr<HealthyMenu>> healthyMenu;
    vector<shared_ptr<Bar>> barMenu;
    vector<shared_ptr<LuxuryBar>> luxuryBarMenu;
    Menu menu_obj;
    HealthyMenu healthyMenu_obj;
    Bar bar_obj;
    LuxuryBar luxuryBar_obj;
    Delivery delivery;
    int userType;
    ShoppingCart cart;
    cout << "Are you an admin or a regular user? (1 for admin, 2 for user): ";
    cin >> userType;
    if (userType == 1) {
        string password;
        cout << "Enter password: ";
        cin >> password;
        if (password == "admin123") {
            cout << "Admin logged in.\n";
            cout << "1. Display Menu\n";
            cout << "2. Add dish\n";
            cout << "3. Display Healthy Menu\n";
            cout << "4. Add healthy dish\n";
            cout << "5. Display Bar\n";
            cout << "6. Add cocktail\n";
            cout << "7. Display Luxury Bar\n";
            cout << "8. Add luxury drink\n";
            cout << "9. Exit\n";
            cout << "Enter your choice: ";
            try {
                int choice;
                cout << "Enter your choice: ";
                cin >> choice;
                if (choice < 1 || choice > 9) {
                    throw runtime_error("Invalid choice. Please enter a number between 1 and 9.");
                }
            switch (choice){
                case 1: {
                    loadMenuFromFile(menu);
                    menu_obj.displayMenu(menu);
                    break;
                }
                case 2 : {
                    menu_obj.addMenuItem(menu);
                    saveMenuToFile(menu);
                    break;
                }
                case 3: {
                    loadHealthyMenuFromFile(healthyMenu);
                    healthyMenu_obj.displayHealthyMenu(healthyMenu);
                    break;
                }
                case 4: {
                    healthyMenu_obj.addHealthyMenuItem(healthyMenu);
                    saveHealthyMenuToFile(healthyMenu);
                    break;
                }
                case 5: {
                    loadBarFromFile(barMenu);
                    bar_obj.displayBar(barMenu);
                    break;
                }
                case 6: {
                    bar_obj.addBarItem(barMenu);
                    saveBarToFile(barMenu);
                    break;
                }
                case 7: {
                    loadLuxuryBarFromFile(luxuryBarMenu);
                    luxuryBar_obj.displayLuxuryBar(luxuryBarMenu);
                    break;
                }
                case 8: {
                    luxuryBar_obj.addLuxuryBarItem(luxuryBarMenu);
                    saveLuxuryBarToFile(luxuryBarMenu);
                    break;
                }
                case 9:
                    cout << "Exiting...";
                    break;
            }

            }
                catch (const exception& e) {
                    cerr << e.what() << endl;
                }
        } else {
            cout << "Incorrect password. Exiting...\n";
            return 0;
        }
    } else if (userType == 2) {
            M:
            cout << "Choose category:\n";
            cout << "1. Menu:\n";
            cout << "2. Healthy menu:\n";
            cout << "3. Bar:\n";
            cout << "4. Luxury bar:\n";
            cout << "5. Delivery:\n";
            cout << "6. View Cart and Checkout\n";
            cout << "7. Exit\n";
            cout << "Enter your choice: ";
            int command;
            cin >> command;
        try {
            if (command < 1 || command > 7) {
                throw runtime_error("Invalid choice! Please enter a number between 1 to 7.");
            }
            if (command == 1) {
                loadMenuFromFile(menu);
                menu_obj.displayMenu(menu);
                cout << "Enter menu item number to add to cart:";
                int menuItemChoice;
                cin >> menuItemChoice;
                if (menuItemChoice <= menu.size() && menuItemChoice >= 1){
                    cart.addItem(menu[menuItemChoice-1]->name,menu[menuItemChoice-1]->price);
                }
                goto M;
            }
            else if (command == 2){
                loadHealthyMenuFromFile(healthyMenu);
                healthyMenu_obj.displayHealthyMenu(healthyMenu);
                cout << "Enter healthy menu item number to add to cart:";
                int healthyItemChoice;
                cin >> healthyItemChoice;
                if (healthyItemChoice <= menu.size() && healthyItemChoice >= 1){
                    cart.addItem(menu[healthyItemChoice-1]->name,menu[healthyItemChoice-1]->price);
                }
                goto M;
            }
            else if (command == 3){
                loadBarFromFile(barMenu);
                bar_obj.displayBar(barMenu);
                cout << "Enter bar item number to add to cart:";
                int barItemChoice;
                cin >> barItemChoice;
                if (barItemChoice <= barMenu.size() && barItemChoice >= 1) {
                    cart.addItem(barMenu[barItemChoice-1]->name,barMenu[barItemChoice-1]->price);
                }
                goto M;
            }
            else if (command == 4){
                loadLuxuryBarFromFile(luxuryBarMenu);
                luxuryBar_obj.displayLuxuryBar(luxuryBarMenu);
                cout << "Enter luxury bar item to add to cart:";
                int luxuryItemChoice;
                cin >> luxuryItemChoice;
                if (luxuryItemChoice <= luxuryBarMenu.size() && luxuryItemChoice >= 1){
                    cart.addItem(luxuryBarMenu[luxuryItemChoice-1]->name,luxuryBarMenu[luxuryItemChoice-1]->price);
                }
                goto M;
            }
            else if (command == 5){
                delivery.display();
                goto M;
            }
            else if (command == 6){
                cart.displayCart();
            }
            else if (command == 7){
                cout << "Exiting...";
            }
        } catch (const runtime_error& e) {
                cerr << "Error: " << e.what() << endl;
                goto M;
    }
    }else {
        cout << "Invalid user type." << endl;
    }
    return 0;
}



