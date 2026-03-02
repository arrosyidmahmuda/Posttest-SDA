#include <iostream>
using namespace std;

int tukar(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;

    return 0;
}

int main() {
    int x, y;

    cout << "Masukkan nilai x: ";
    cin >> x;
    cout << "Masukkan nilai y: ";
    cin >> y;

    cout << "\nSebelum di tukar:\n";
    cout << "x = " << x << ", y = " << y << endl;

    tukar(&x, &y);

    cout << "\nSetelah di tukar:\n";
    cout << "x = " << x << ", y = " << y << endl;

    return 0;
}