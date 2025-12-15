// -------------------- Part 3: Abeera Amjad --------------------
#include <iostream>
#include <windows.h>
using namespace std;

extern void orderManagement();
extern void inventoryManagement();
extern void paymentProcessing();
extern void setColor(int);

void orderManagement();
void inventoryManagement();
void paymentProcessing();

void orderManagement() {
    int choice;
    do {
        setColor(COLOR_ORANGE);
        cout << "\n===== Order Management =====\n";
        setColor(COLOR_GREEN);
        cout << "1. Display Menu\n";
        cout << "2. Place Order\n";
        cout << "3. View All Orders\n";
        cout << "4. Complete Order\n";
        cout << "5. Back to Main Menu\n";
        setColor(COLOR_ORANGE);
        cout << "=============================\n";
        setColor(COLOR_GRAY);
        cout << "Enter your choice: ";
        setColor(COLOR_PINK);
        cin >> choice;

        switch (choice) {
        case 1: break;
        case 2: break;
        case 3: break;
        case 4: break;
        case 5: return;
        default: setColor(COLOR_PURPLE); cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 5);
}

void inventoryManagement() {
    int choice;
    do {
        setColor(COLOR_ORANGE);
        cout << "\n===== Inventory Management =====\n";
        setColor(COLOR_GREEN);
        cout << "1. View Inventory\n";
        cout << "2. Add Inventory Item\n";
        cout << "3. Update Inventory\n";
        cout << "4. Back to Main Menu\n";
        setColor(COLOR_ORANGE);
        cout << "=================================\n";
        setColor(COLOR_GRAY);
        cout << "Enter your choice: ";
        setColor(COLOR_PINK);
        cin >> choice;

        switch (choice) {
        case 1: break;
        case 2: break;
        case 3: break;
        case 4: return;
        default: setColor(COLOR_PURPLE); cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 4);
}

void paymentProcessing() {
    extern float totalSales;
    setColor(COLOR_CYAN);
    cout << "Total Sales till now: $" << totalSales << "\n";
}

void mainMenu() {
    int choice;
    do {
        setColor(COLOR_RED);
        cout << "\n======= Cafeteria Order Management System =======\n";
        setColor(COLOR_CYAN);
        cout << "1. Order Management\n";
        cout << "2. Inventory Management\n";
        cout << "3. View Total Sales\n";
        cout << "4. Exit\n";
        setColor(COLOR_RED);
        cout << "=================================================\n";
        setColor(COLOR_GRAY);
        cout << "Enter your choice: ";
        setColor(COLOR_PINK);
        cin >> choice;

        switch (choice) {
        case 1: orderManagement(); break;
        case 2: inventoryManagement(); break;
        case 3: paymentProcessing(); break;
        case 4: setColor(COLOR_WHITE); cout << "Exiting... Thank you!\n"; break;
        default: setColor(COLOR_PURPLE); cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 4);
}

// -------------------- Main --------------------
int main() {
    extern void addSampleInventory();
    addSampleInventory();
    mainMenu();
    return 0;
}
