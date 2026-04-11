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

struct Queue {
    Hewan data[MAX];
    int front;
    int rear;
};

struct Stack {
    Hewan data[MAX];
    int top;
};

void tukar(Hewan *a, Hewan *b) {
    Hewan temp = *a;
    *a = *b;
    *b = temp;
}

void initQueue(Queue &q) {
    q.front = 0;
    q.rear = -1;
}

void initStack(Stack &s) {
    s.top = -1;
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

void cariNama(Hewan *arr, int n) {
    string cari;
    cout << "\nMasukkan nama: ";
    cin >> cari;

    bool ketemu = false;

    cout << "\nProses Iterasi:\n";
    for (int i = 0; i < n; i++) {
        cout << "Cek index " << i << endl;

        if ((arr+i)->nama == cari) {
            cout << "\nData ditemukan!\n";
            cout << "ID         : " << (arr+i)->id << endl;
            cout << "Nama Hewan : " << (arr+i)->namaHewan << endl;
            cout << "Harga      : " << (arr+i)->harga << endl;
            ketemu = true;
        }
    }

    if (!ketemu) cout << "Data tidak ditemukan!\n";
}

void cariID(Hewan *arr, int n) {
    int x;
    cout << "\nMasukkan ID: ";
    cin >> x;

    int f2 = 0, f1 = 1, f = f2 + f1;
    while (f < n) {
        f2 = f1;
        f1 = f;
        f = f2 + f1;
    }

    int offset = -1;

    cout << "\nProses Iterasi:\n";

    while (f > 1) {
        int i = min(offset + f2, n - 1);

        cout << "Cek index " << i << endl;

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
            cout << "Data ditemukan!\n";
            cout << "Nama : " << (arr+i)->nama << endl;
            return;
        }
    }

    if (f1 && (arr+offset+1)->id == x) {
        cout << "Data ditemukan!\n";
        return;
    }

    cout << "Data tidak ditemukan!\n";
}

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

void enqueue(Queue &q, Hewan h) {
    if (q.rear == MAX - 1) {
        cout << "Antrian penuh!\n";
        return;
    }
    q.rear++;
    *(q.data + q.rear) = h;
}

Hewan dequeue(Queue &q) {
    Hewan kosong; kosong.id = -1;

    if (q.front > q.rear) {
        cout << "Antrian kosong!\n";
        return kosong;
    }

    Hewan h = *(q.data + q.front);
    q.front++;

    cout << "Memanggil: " << h.nama << endl;
    return h;
}

void tampilQueue(Queue *q) {
    if (q->front > q->rear) {
        cout << "Antrian kosong!\n";
        return;
    }

    cout << "\n=== ANTRIAN ===\n";
    for (int i = q->front; i <= q->rear; i++) {
        cout << (q->data+i)->nama << endl;
    }
}

void push(Stack &s, Hewan h) {
    if (s.top == MAX - 1) {
        cout << "Riwayat penuh!\n";
        return;
    }
    s.top++;
    *(s.data + s.top) = h;
}

void pop(Stack &s) {
    if (s.top == -1) {
        cout << "Riwayat kosong!\n";
        return;
    }

    cout << "Hapus riwayat: " << (s.data+s.top)->nama << endl;
    s.top--;
}

void tampilStack(Stack *s) {
    if (s->top == -1) {
        cout << "Riwayat kosong!\n";
        return;
    }

    cout << "\n=== RIWAYAT ===\n";
    for (int i = s->top; i >= 0; i--) {
        cout << (s->data+i)->nama << endl;
    }
}

void peek(Queue *q, Stack *s) {
    cout << "\n=== PEEK ===\n";

    if (q->front <= q->rear)
        cout << "Depan antrian: " << (q->data+q->front)->nama << endl;
    else
        cout << "Antrian kosong\n";

    if (s->top != -1)
        cout << "Riwayat terakhir: " << (s->data+s->top)->nama << endl;
    else
        cout << "Riwayat kosong\n";
}

int main() {
    Hewan data[MAX];
    Queue q;
    Stack s;

    initQueue(q);
    initStack(s);

    int pilih;

    do {
        cout << "\n=== MENU PAWCARE ===\n";
        cout << "1. Tambah Data\n";
        cout << "2. Tampil Data\n";
        cout << "3. Cari Nama\n";
        cout << "4. Cari ID\n";
        cout << "5. Sort Nama\n";
        cout << "6. Sort Harga\n";
        cout << "7. Masuk Antrian\n";
        cout << "8. Panggil Pasien\n";
        cout << "9. Tampil Antrian\n";
        cout << "10. Tampil Riwayat\n";
        cout << "11. Pop Riwayat\n";
        cout << "12. Peek\n";
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

            case 7: {
                int id;
                cout << "Masukkan ID: ";
                cin >> id;
                for (int i = 0; i < jumlah; i++) {
                    if ((data+i)->id == id)
                        enqueue(q, *(data+i));
                }
                break;
            }

            case 8: {
                Hewan h = dequeue(q);
                if (h.id != -1) push(s, h);
                break;
            }

            case 9: tampilQueue(&q); break;
            case 10: tampilStack(&s); break;
            case 11: pop(s); break;
            case 12: peek(&q, &s); break;
        }

    } while (pilih != 0);

    return 0;
}