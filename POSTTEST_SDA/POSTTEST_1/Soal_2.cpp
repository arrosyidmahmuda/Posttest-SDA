#include <iostream>
using namespace std;
struct Mahasiswa {
    string nama;
    string nim;
    float ipk;
};
int main() {
    Mahasiswa mhs[5];
    int i;

    for (i = 0; i < 5; i++) {
        cout << "Mahasiswa ke-" << i+1 << endl;
        cout << "Nama : ";
        cin >> mhs[i].nama;
        cout << "NIM  : ";
        cin >> mhs[i].nim;
        cout << "IPK  : ";
        cin >> mhs[i].ipk;
        cout << endl;
    }

    int max = 0;
    for (i = 1; i < 5; i++) {
        if (mhs[i].ipk > mhs[max].ipk) {
            max = i;
        }
    }

    cout << "Mahasiswa dengan IPK Tertinggi:" << endl;
    cout << "Nama : " << mhs[max].nama << endl;
    cout << "NIM  : " << mhs[max].nim << endl;
    cout << "IPK  : " << mhs[max].ipk << endl;

    return 0;
}