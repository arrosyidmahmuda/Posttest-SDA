#include <iostream>
using namespace std;

struct Hewan {
    int id;
    string nama;
    string namaHewan;
    float harga;
};

const int MAX = 100;
int jumlah = 0;
int IdOtomatis = 1;

void tukar(Hewan *a, Hewan *b) {
    Hewan temp = *a;
    *a = *b;
    *b = temp;
}

void tambah(Hewan *arr, int &n) {
    cout << "\n=== Tambah Data Hewan ===\n";

    (arr+n)->id = IdOtomatis++;
    cout << "ID         : " << (arr+n)->id << endl;

    cout << "Nama       : ";
    cin >> (arr+n)->nama;

    cout << "Nama Hewan : ";
    cin >> (arr+n)->namaHewan;

    cout << "Harga      : ";
    cin >> (arr+n)->harga;

    n++;
}

void tampil(Hewan *arr, int n) {
    if (n == 0) {
        cout << "Data kosong!\n";
        return;
    }

    cout << "\n=== DATA HEWAN ===\n";

    for (int i = 0; i < n; i++) {
        cout << "ID         : " << (arr+i)->id << endl;
        cout << "Nama       : " << (arr+i)->nama << endl;
        cout << "Nama Hewan : " << (arr+i)->namaHewan << endl;
        cout << "Harga      : " << (arr+i)->harga << endl;
        cout << "----------------------\n";
    }
}

// linear sear
void cariNama(Hewan *arr, int n) {
    string cari;
    cout << "\nMasukkan nama: ";
    cin >> cari;

    bool ketemu = false;

    for (int i = 0; i < n; i++) {
        if ((arr+i)->nama == cari) {
            cout << "\nData ditemukan!\n";
            cout << "ID         : " << (arr+i)->id << endl;
            cout << "Nama Hewan : " << (arr+i)->namaHewan << endl;
            cout << "Harga      : " << (arr+i)->harga << endl;
            ketemu = true;
        }
    }

    if (!ketemu) {
        cout << "Data tidak ditemukan!\n";
    }
}

// fibonacci sear
void cariID(Hewan *arr, int n) {
    int x;
    cout << "\nMasukkan ID: ";
    cin >> x;

    int f2 = 0;
    int f1 = 1;
    int f = f2 + f1;

    while (f < n) {
        f2 = f1;
        f1 = f;
        f = f2 + f1;
    }

    int offset = -1;

    cout << "\nProses Iterasi:\n";

    while (f > 1) {
        int i = min(offset + f2, n - 1);

        cout << "Iterasi -> cek index: " << i
             << " | ID: " << (arr+i)->id << endl;

        if ((arr+i)->id < x) {
            f = f1;
            f1 = f2;
            f2 = f - f1;
            offset = i;
        }
        else if ((arr+i)->id > x) {
            f = f2;
            f1 = f1 - f2;
            f2 = f - f1;
        }
        else {
            cout << "\nData ditemukan!\n";
            cout << "Nama       : " << (arr+i)->nama << endl;
            cout << "Nama Hewan : " << (arr+i)->namaHewan << endl;
            cout << "Harga      : " << (arr+i)->harga << endl;
            return;
        }
    }

    if (f1 && (arr+offset+1)->id == x) {
        cout << "\nData ditemukan!\n";
        cout << "Nama       : " << (arr+offset+1)->nama << endl;
        cout << "Nama Hewan : " << (arr+offset+1)->namaHewan << endl;
        cout << "Harga      : " << (arr+offset+1)->harga << endl;
        return;
    }

    cout << "Data tidak ditemukan!\n";
}

// bubble sor
void sortNama(Hewan *arr, int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if ((arr+j)->nama > (arr+j+1)->nama) {
                tukar(arr+j, arr+j+1);
            }
        }
    }
    cout << "Data diurutkan berdasarkan nama\n";
}

// selection sor
void sortHarga(Hewan *arr, int n) {
    for (int i = 0; i < n-1; i++) {
        int min = i;

        for (int j = i+1; j < n; j++) {
            if ((arr+j)->harga < (arr+min)->harga) {
                min = j;
            }
        }

        tukar(arr+i, arr+min);
    }
    cout << "Data diurutkan berdasarkan harga\n";
}

int main() {
    Hewan data[MAX];
    int pilih;

    do {
        cout << "\n=== MENU PAWCARE ===\n";
        cout << "1. Tambah Data\n";
        cout << "2. Tampil Data\n";
        cout << "3. Cari Nama\n";
        cout << "4. Cari ID\n";
        cout << "5. Ngurut Nama(A-Z)\n";
        cout << "6. Ngurut Harga(murah->mahal)\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;

        switch(pilih) {
            case 1: tambah(data, jumlah); break;
            case 2: tampil(data, jumlah); break;
            case 3: cariNama(data, jumlah); break;
            case 4: cariID(data, jumlah); break;
            case 5: sortNama(data, jumlah); break;
            case 6: sortHarga(data, jumlah); break;
        }

    } while (pilih != 0);

    return 0;
}