#include <iostream>
using namespace std;

/*
ANALISIS KOMPLEKSITAS – FindMin

Pseudocode:
1 min ← A[0]
2 for i ← 1 to n-1
3    if A[i] < min
4       min ← A[i]
5 return min

TABEL COST

Baris 1 : c1 > 1 kali
Baris 2 : c2 > (n-1) kali
Baris 3 : c3 > (n-1) kali
Baris 4 : c4 > 0 (best) / (n-1) (worst)
Baris 5 : c5 > 1 kali

BEST CASE (elemen pertama sudah minimum)
Tmin(n) = c1 + (n-1)c2 + (n-1)c3 + c5
        = (c2+c3)(n-1) + (c1+c5)
        = an + b
Big-O = O(n)

WORST CASE (selalu update min)
Tmax(n) = c1 + (n-1)c2 + (n-1)c3 + (n-1)c4 + c5
        = (c2+c3+c4)(n-1) + (c1+c5)
        = an + b
Big-O = O(n)

Kesimpulan: selalu mengecek semua elemen > Linear Time O(n).
*/

int FindMin(int A[], int n, int &idx) {
    int min = A[0];
    idx = 0;

    for(int i = 1; i < n; i++) {
        if(A[i] < min) {
            min = A[i];
            idx = i;
        }
    }
    return min;
}

int main() {

    int A[8] = {1, 1, 2, 3, 5, 8, 13, 21};
    int indexMin;

    int minimum = FindMin(A, 8, indexMin);

    cout << "Min   : " << minimum << endl;
    cout << "Index : " << indexMin << endl;

    return 0;
}