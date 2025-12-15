// -------------------- Part 1: Rabia Ozair --------------------
#include <iostream>
#include <cstring>
#include <windows.h>
using namespace std;

// -------------------- Console Colors --------------------
void setColor(int textColor) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, textColor);
}
#define COLOR_YELLOW 6      
#define COLOR_RED 4          
#define COLOR_GREEN 2        
#define COLOR_BLUE 1         
#define COLOR_WHITE 15       
#define COLOR_PURPLE 5      
#define COLOR_CYAN 3       
#define COLOR_PINK 13      
#define COLOR_GRAY 8       
#define COLOR_ORANGE 6     
#define COLOR_GOLD 11      

// -------------------- Constants --------------------
const int MAX_ORDERS = 100;
const int MAX_INVENTORY = 50;
const float TAX_RATE = 0.05; // 5% tax

// -------------------- Structures --------------------
struct Order {
    int orderId;
    int tableNumber;
    int itemIndex;  
    int quantity;
    float price;
    int rating;           
    char feedback[200];
    bool isCompleted;
};

struct InventoryItem {
    char itemName[50];
    int stockQuantity;
    float price;
};

// -------------------- Global Variables --------------------
Order orders[MAX_ORDERS];
int orderCount = 0;

InventoryItem inventory[MAX_INVENTORY];
int inventoryCount = 0;

float totalSales = 0.0;

// -------------------- Function Prototypes --------------------
void mainMenu();
void orderManagement();
void inventoryManagement();
void paymentProcessing();
void displayMenu();
void placeOrder();
void viewOrders();
void completeOrder();
void viewInventory();
void addInventoryItem();
void updateInventory();
bool checkInventory(int itemIndex, int quantity);
void addSampleInventory();

// -------------------- Functions --------------------
void addSampleInventory() {
    struct SampleItem { 
        const char* itemName; 
        int stockQuantity; 
        float price; 
    };
    
    SampleItem sampleItems[] = {
        {"Coffee", 100, 2.5},
        {"Cake", 50, 5.0},
        {"Pizza", 100, 6.5},
        {"Ramen", 100, 4.5},
        {"Tea", 100, 1.5}
    };

    for (int i = 0; i < 5; i++) {
        strcpy(inventory[inventoryCount].itemName, sampleItems[i].itemName);
        inventory[inventoryCount].stockQuantity = sampleItems[i].stockQuantity;
        inventory[inventoryCount].price = sampleItems[i].price;
        inventoryCount++;
    }
}

void displayMenu() {
    setColor(COLOR_WHITE);
    cout << "\n===== Menu =====\n";
    for (int i = 0; i < inventoryCount; i++) {
        cout << i + 1 << ". " << inventory[i].itemName
            << " - $" << inventory[i].price
            << " (" << inventory[i].stockQuantity << " available)\n";
    }
    cout << "================\n";
}

bool checkInventory(int itemIndex, int quantity) {
    if (itemIndex < 0 || itemIndex >= inventoryCount) return false;
    return inventory[itemIndex].stockQuantity >= quantity;
}

void placeOrder() {
    if (orderCount >= MAX_ORDERS) {
        setColor(COLOR_CYAN);
        cout << "Order list is full. Cannot place more orders.\n";
        return;
    }

    displayMenu();

    int choice, qty;
    setColor(COLOR_GRAY);
    cout << "Select item by number: ";
    setColor(COLOR_PINK);
    cin >> choice;
    int itemIndex = choice - 1;

    setColor(COLOR_GRAY);
    cout << "Enter quantity: ";
    setColor(COLOR_PINK);
    cin >> qty;

    if (choice < 1 || choice > inventoryCount) {
        setColor(COLOR_PURPLE);
        cout << "Invalid item selection.\n";
        return;
    }

    if (!checkInventory(itemIndex, qty)) {
        setColor(COLOR_PURPLE);
        cout << "Item not available or insufficient stock.\n";
        return;
    }

    Order newOrder;
    newOrder.orderId = orderCount + 1;
    newOrder.itemIndex = itemIndex;
    newOrder.quantity = qty;
    newOrder.price = inventory[itemIndex].price * qty * (1 + TAX_RATE);
    newOrder.isCompleted = false;
    newOrder.rating = 0;
    strcpy(newOrder.feedback, "");

    setColor(COLOR_GRAY);
    cout << "Enter Table Number: ";
    setColor(COLOR_PINK);
    cin >> newOrder.tableNumber;

    inventory[itemIndex].stockQuantity -= qty;

    orders[orderCount] = newOrder;
    orderCount++;
    
    setColor(COLOR_PURPLE);
    cout << "Order placed successfully! Order ID: " << newOrder.orderId << "\n";
}

