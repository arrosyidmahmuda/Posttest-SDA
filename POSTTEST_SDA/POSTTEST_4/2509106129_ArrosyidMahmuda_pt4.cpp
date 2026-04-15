#include <iostream>
using namespace std;

struct Hewan {
    int id;
    string nama;
    string namaHewan;
    float harga;
    Hewan *next;
};

int IdOtomatis = 1;

struct Queue {
    Hewan *front;
    Hewan *rear;
};

void initQueue(Queue &q) {
    q.front = q.rear = NULL;
}

void enqueue(Queue &q, Hewan *data) {
    Hewan *baru = new Hewan(*data);
    baru->next = NULL;

    if (q.rear == NULL) {
        q.front = q.rear = baru;
    } else {
        q.rear->next = baru;
        q.rear = baru;
    }

    cout << "Masuk antrian: " << baru->nama << endl;
}

void dequeue(Queue &q, Hewan *&out) {
    if (q.front == NULL) {
        cout << "Antrian kosong!\n";
        out = NULL;
        return;
    }

    Hewan *hapus = q.front;
    out = hapus;

    q.front = q.front->next;
    if (q.front == NULL) q.rear = NULL;

    cout << "Memanggil: " << hapus->nama << endl;
}

void tampilQueue(Queue *q) {
    if (q->front == NULL) {
        cout << "Antrian kosong!\n";
        return;
    }

    Hewan *temp = q->front;
    cout << "\n=== ANTRIAN ===\n";
    while (temp != NULL) {
        cout << temp->nama << endl;
        temp = temp->next;
    }
}

struct Stack {
    Hewan *top;
};

void initStack(Stack &s) {
    s.top = NULL;
}

void push(Stack &s, Hewan *data) {
    Hewan *baru = new Hewan(*data);

    baru->next = s.top;
    s.top = baru;

    cout << "Masuk riwayat: " << baru->nama << endl;
}

void pop(Stack &s) {
    if (s.top == NULL) {
        cout << "Riwayat kosong!\n";
        return;
    }

    Hewan *hapus = s.top;
    cout << "Hapus riwayat: " << hapus->nama << endl;

    s.top = s.top->next;
    delete hapus;
}

void tampilStack(Stack *s) {
    if (s->top == NULL) {
        cout << "Riwayat kosong!\n";
        return;
    }

    Hewan *temp = s->top;
    cout << "\n=== RIWAYAT ===\n";
    while (temp != NULL) {
        cout << temp->nama << endl;
        temp = temp->next;
    }
}

void peek(Queue *q, Stack *s) {
    cout << "\n=== PEEK ===\n";

    if (q->front != NULL)
        cout << "Depan antrian: " << q->front->nama << endl;
    else
        cout << "Antrian kosong\n";

    if (s->top != NULL)
        cout << "Riwayat terakhir: " << s->top->nama << endl;
    else
        cout << "Riwayat kosong\n";
}

void tambah(Hewan *&head) {
    Hewan *baru = new Hewan;

    baru->id = IdOtomatis++;
    cout << "ID         : " << baru->id << endl;

    cout << "Nama       : ";
    cin >> baru->nama;

    cout << "Nama Hewan : ";
    cin >> baru->namaHewan;

    cout << "Harga      : ";
    cin >> baru->harga;

    baru->next = head;
    head = baru;
}

void tampil(Hewan *head) {
    if (head == NULL) {
        cout << "Data kosong!\n";
        return;
    }

    cout << "\n=== DATA HEWAN ===\n";
    Hewan *temp = head;

    while (temp != NULL) {
        cout << "ID         : " << temp->id << endl;
        cout << "Nama       : " << temp->nama << endl;
        cout << "Nama Hewan : " << temp->namaHewan << endl;
        cout << "Harga      : " << temp->harga << endl;
        cout << "------------------\n";

        temp = temp->next;
    }
}

int main() {
    Hewan *data = NULL;
    Queue q;
    Stack s;

    initQueue(q);
    initStack(s);

    int pilih;

    do {
        cout << "\n=== MENU PAWCARE (Linked List) ===\n";
        cout << "1. Tambah Data\n";
        cout << "2. Tampil Data\n";
        cout << "3. Masuk Antrian\n";
        cout << "4. Panggil Pasien\n";
        cout << "5. Tampil Antrian\n";
        cout << "6. Tampil Riwayat\n";
        cout << "7. Pop Riwayat\n";
        cout << "8. Peek\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;

        switch (pilih) {
            case 1:
                tambah(data);
                break;

            case 2:
                tampil(data);
                break;

            case 3: {
                int id;
                cout << "Masukkan ID: ";
                cin >> id;

                Hewan *temp = data;
                while (temp != NULL) {
                    if (temp->id == id) {
                        enqueue(q, temp);
                        break;
                    }
                    temp = temp->next;
                }
                break;
            }

            case 4: {
                Hewan *h;
                dequeue(q, h);
                if (h != NULL) push(s, h);
                break;
            }

            case 5:
                tampilQueue(&q);
                break;

            case 6:
                tampilStack(&s);
                break;

            case 7:
                pop(s);
                break;

            case 8:
                peek(&q, &s);
                break;
        }

    } while (pilih != 0);

    return 0;
}