#include <iostream>
using namespace std;

void tampilArray(int (*arr)[3], int baris, int kolom) {
    cout << "--- Menampilkan Seluruh Array ---" << endl;
    for (int i = 0; i < baris; i++) {
        for (int j = 0; j < kolom; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void ubahNilai(int (*ptr)[3], int baris, int kolom, int nilaiBaru) {
    *(*(ptr + baris) + kolom) = nilaiBaru;
    cout << "Nilai pada posisi [" << baris << "][" << kolom << "] berhasil diubah menjadi " << nilaiBaru << endl;
}

int main() {
    int array2D[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int (*ptr1)[3] = array2D;
    int *ptr2;

    cout << "Array Awal:" << endl;
    tampilArray(ptr1, 3, 3);

    ubahNilai(ptr1, 1, 2, 100);

    cout << "\nArray Setelah Diubah:" << endl;
    tampilArray(ptr1, 3, 3);

    ptr2 = &array2D[2][0]; 
    cout << "Nilai yang ditunjuk ptr2 (baris 2, kolom 0): " << *ptr2 << endl;

    return 0;
}
