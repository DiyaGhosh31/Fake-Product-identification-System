#include <iostream>
#include <unordered_map>
using namespace std;

struct Product {
    int id;
    string name;
    string qrCode;
    bool isAuthentic;
};

unordered_map<int, Product> productDatabase;
int productCount = 0;


void registerProduct(string name, string qrCode) {
    productCount++;
    productDatabase[productCount] = {productCount, name, qrCode, true};
    cout << "Product Registered Successfully! ID: " << productCount << endl;
}


void verifyProduct(int id) {
    if (productDatabase.find(id) != productDatabase.end()) {
        Product p = productDatabase[id];
        cout << "Product ID: " << p.id << "\nName: " << p.name << "\nQR Code: " << p.qrCode
             << "\nAuthentic: " << (p.isAuthentic ? "Yes" : "No") << endl;
    } else {
        cout << "Product Not Found!" << endl;
    }
}

int main() {
    registerProduct("Laptop", "QRCODE_HASH_123");
    registerProduct("Mobile", "QRCODE_HASH_456");

    cout << "\nVerifying Product 1:\n";
    verifyProduct(1);

    cout << "\nVerifying Product 3 (Non-existent):\n";
    verifyProduct(3);

    return 0;
}

