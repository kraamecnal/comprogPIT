#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <string>
using namespace std;

struct Product {
    string id;
    string name;
    string category;
    int quantity;
    double price;
};

vector<Product> inventory;

void loadFromFile() {
    ifstream file("inventory.dat");
    Product p;
    inventory.clear();
    while (file >> p.id >> ws && getline(file, p.name) && getline(file, p.category) && file >> p.quantity >> p.price) {
        inventory.push_back(p);
    }
    file.close();
}

void saveToFile() {
    ofstream file("inventory.dat");
    for (Product& p : inventory) {
        file << p.id << endl
             << p.name << endl
             << p.category << endl
             << p.quantity << " " << p.price << endl;
    }
    file.close();
}

void addProduct() {
    Product p;
    cout << "Enter Product ID: ";
    cin >> p.id;
    cin.ignore();
    
    cout << "Enter Product Name: ";
    getline(cin, p.name);
    
    cout << "Enter Category: ";
    getline(cin, p.category);
    
    cout << "Enter Quantity: ";
    cin >> p.quantity;
    if (cin.fail()) {
        cin.clear(); 
        cin.ignore(1000, '\n'); 
        cout << "INVALID INPUT! numbers only" << "\nQuantity: ";
        cin >> p.quantity;
        
        return;
        }    
    
    cout << "Enter Price: ";
    cin >> p.price;

    inventory.push_back(p);
    saveToFile();
    cout << "Product added successfully.\n";
}

void updateStock() {
    string id;
    int change;
    char type;
    cout << "Enter Product ID: ";
    cin >> id;
    bool found = false;

    for (Product& p : inventory) {
        if (p.id == id) {
            found = true;
            cout << "Stock In (i) or Stock Out (o)? ";
            cin >> type;
            cout << "Enter quantity: ";
            cin >> change;

            if (type == 'i') {
                p.quantity += change;
                cout << "Stock updated.\n";
            } else if (type == 'o') {
                if (change > p.quantity) {
                    cout << "Not enough stock.\n";
                } else {
                    p.quantity -= change;
                    cout << "Stock updated.\n";
                }
            } else {
                cout << "Invalid option.\n";
            }

            saveToFile();
            break;
        }
    }

    if (!found) cout << "Product not found.\n";
}

void searchProduct() {
    int option;
    cout << "Search by (1. ID) or (2. Name): ";
    cin >> option;
    cin.ignore();
    bool found = false;

    if (option == 1) {
        string id;
        cout << "Enter Product ID: ";
        cin >> id;
        for (Product& p : inventory) {
            if (p.id == id) {
                cout << "Found: " << p.name << " (" << p.category << "), Quantity: " << p.quantity << ", Price: $" << p.price << endl;
                found = true;
                break;
            }
        }
    } if (option == 2) {
        string name;
        cout << "Enter Product Name: ";
        getline(cin, name);
        for (Product& p : inventory) {
            if (p.name == name) {
                cout << "Found: " << p.id << " (" << p.category << "), Quantity: " << p.quantity << ", Price: $" << p.price << endl;
                found = true;
                break;
            }
        }
    } else {
    cout << "Invalid Input!";
    return;
    }

    if (!found) cout << "Product not found.\n";
}

void displayAll() {
    cout << setw(10) << "ID" << setw(20) << "Name" << setw(15) << "Category"
         << setw(10) << "Qty" << setw(10) << "Price" << endl;
    cout << string(65, '-') << endl;
    for (Product& p : inventory) {
        cout << setw(10) << p.id << setw(20) << p.name << setw(15) << p.category
             << setw(10) << p.quantity << setw(10) << fixed << setprecision(2) << p.price << endl;
    }
}

void calculateInventoryValue() {
    double total = 0;
    for (Product& p : inventory) {
        total += p.quantity * p.price;
    }
    cout << "Total Inventory Value: " << fixed << setprecision(2) << total << "pesos" << endl;
}

void deleteProduct() {
    string id;
    cout << "Enter Product ID to delete: ";
    cin >> id;
    getline(cin, id);
    bool found = false;

    for (auto it = inventory.begin(); it != inventory.end(); ++it) {
        if (it->id == id) {
            inventory.erase(it);
            saveToFile();
            cout << "Product deleted.\n";
            found = true;
            break;
        }
    }

    if (!found) cout << "Product not found.\n";
}


int main() {
    loadFromFile();
    int choice;
    
    do {
        cout << "\n======= INVENTORY OF ITEMS ========\n";
        cout << "1. Add New Product\n";
        cout << "2. Update Stock\n";
        cout << "3. Search Product\n";
        cout << "4. Display All Products\n";
        cout << "5. Calculate Inventory Value\n";
        cout << "6. Delete Product\n";
        cout << "7. Exit\n";
        cout << "\nSelect an Option (1 to 7): ";
        cin >> choice;
        
        if (cin.fail()) {
        cin.clear(); 
        cin.ignore(1000, '\n'); 
        cout << "INVALID INPUT! number 1 to 7 only.\n";
        continue; 
        }    
        
        switch (choice) {
            case 1: addProduct(); break;
            case 2: updateStock(); break;
            case 3: searchProduct(); break;
            case 4: displayAll(); break;
            case 5: calculateInventoryValue(); break;
            case 6: deleteProduct(); break;
            case 7: cout << "Exit system.\n"; break;
            default: cout << "INVALID INPUT! number 1 to 7 only\n"; break;
        }

    } while (choice != 7);

    return 0;
}
