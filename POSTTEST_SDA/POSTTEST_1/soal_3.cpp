#include <iostream>
using namespace std;

int main() {
    int arr[7] = {2, 3, 5, 7, 11, 13, 17};
    int n = 7;

    cout << "Array sebelum dibalik:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << "\n\nAlamat tiap elemen:\n";
    for (int i = 0; i < n; i++) {
        cout << "arr[" << i << "] = " << arr[i]
             << " di alamat " << &arr[i] << endl;
    }
    int start = 0;
    int end = n - 1;

    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        start++;
        end--;
    }

    cout << "\nArray setelah dibalik:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}