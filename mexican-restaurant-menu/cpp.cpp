#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Main class : Food. 
class Food {
protected:
    string name;
    double price;

public:
    Food(const string& name, double price) : name(name), price(price) {}
    //We initiliaze the data members of the class. 

    virtual void display() {
        cout << name << "\t\tTL" << price << endl;
    }

    double getPrice() const {
        return price;
    }
    string getName() {
        return name;
    }
};


// First derived class is drink: 
class Drink : public Food {
private:
    string size;

public:
    Drink(const string& name, double price, const string& size) : Food(name, price), size(size) {}

    virtual void display() {
        cout << name << " (" << size << ")\tTL" << price << endl;
    }
};

// Second derived class: Dish.
class Dish : public Food {
private:
    string ingredients;

public:
    Dish(const string& name, double price, const string& ingredients) : Food(name, price), ingredients(ingredients) {}

    virtual void display() {
        cout << name << " (" << ingredients << ")\tTL" << price << endl;
    }
};

// Third derived class: Dessert.
class Desserts : public Food {
private:
    string contents;
public:
    Desserts(const string& name, double price, const string& contents) : Food(name, price), contents(contents) {}

    virtual  void display() {
        cout << name << " (" << contents << ")\tTL" << price << endl;
    }
};


int main() {
    const int MENU_SIZE = 6;
    Food* menu[MENU_SIZE];

    // We used arrays in this part. 
    menu[0] = new Dish("fajita", 90, "guacamole sauce, grilled meat, tortilla");
    menu[1] = new Dish("tortilla", 30, "type of flatbread and lavash.");
    menu[2] = new Dish("quesadilla", 90, "mexican beans,meat,red pepper");
    menu[3] = new Dish("taco", 105, "beef,chichen,seafood and cheese");
    menu[4] = new Dish("burrito", 80, "bean puree, meat, cheese");
    menu[5] = new Dish("nachos", 120, "chips covered with a cheese sauce.");

    const int DESSERTS_SIZE = 2;
    Food* desserts[DESSERTS_SIZE];
    desserts[0] = new Desserts("churros", 60, "chocolate and cinnamon sauce");
    desserts[1] = new Desserts("papaya", 60, "exotic fruits");

    const int DRINK_SIZE = 2;
    Food* drink[DRINK_SIZE];
    drink[0] = new Drink("tequila", 50, "Large");
    drink[1] = new Drink("horchata", 60, "Large");


    // It includes menu display in the output.


    cout << "Welcome to the Mexican Restaurant!" << endl;
    cout << setw(17) << "-MENU-" << endl;
    cout << "-----------------------------" << endl;
    cout << "Name\t\tPrice" << endl;
    cout << "---------MEXÝCAN FOOD--------" << endl;

    for (int i = 0; i < MENU_SIZE; ++i) {
        menu[i]->display();
    }

    cout << "-----------DESSERTS----------" << endl;

    for (int i = 0; i < DESSERTS_SIZE; ++i) {
        desserts[i]->display();
    }

    cout << "---------BEVERAGES-----------" << endl;

    for (int i = 0; i < DRINK_SIZE; ++i) {
        drink[i]->display();
    }


    cout << "-----------------------------" << endl;

    // here we will take orders from customers and show the total amount in the output. 
    double total = 0.0;
    string order;

    while (order != "exit") {
        cout << "Enter your order (or 'exit' to quit): ";
        cin >> order;

        for (int i = 0; i < MENU_SIZE; ++i) {
            if (menu[i]->getName() == order) {
                total += menu[i]->getPrice();
                break;
            }
        }
        for (int i = 0; i < DESSERTS_SIZE; ++i) {
            if (desserts[i]->getName() == order) {
                total += desserts[i]->getPrice();
                break;
            }
        }
        for (int i = 0; i < DRINK_SIZE; ++i) {
            if (drink[i]->getName() == order) {
                total += drink[i]->getPrice();
                break;
            }
        }
    }

    cout << "Total: TL" << total << endl;

    return 0;
}

