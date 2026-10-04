#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    float uts;
    float uas;
    float tugas;
    float nilai_akhir;
};

float hitungNilaiAkhir(float uts, float uas, float tugas) {
    return (0.3 * uts) + (0.4 * uas) + (0.3 * tugas);
}

int main() {
    const int MAX_DATA = 10;
    Mahasiswa daftarMahasiswa[MAX_DATA];
    int jumlahInput;

    cout << "=== PROGRAM INPUT NILAI MAHASISWA ===" << endl;
    cout << "Masukkan jumlah mahasiswa (max 10): ";
    cin >> jumlahInput;

    if (jumlahInput > MAX_DATA) {
        cout << "Jumlah melebihi batas! Mengatur otomatis ke 10." << endl;
        jumlahInput = MAX_DATA;
    } else if (jumlahInput <= 0) {
        cout << "Jumlah tidak valid." << endl;
        return 0;
    }

    for (int i = 0; i < jumlahInput; i++) {
        cout << "\n--- Mahasiswa ke-" << (i + 1) << " ---" << endl;
        cin.ignore(); 
        cout << "Nama       : ";
        getline(cin, daftarMahasiswa[i].nama);
        cout << "NIM        : ";
        cin >> daftarMahasiswa[i].nim;
        cout << "Nilai UTS  : ";
        cin >> daftarMahasiswa[i].uts;
        cout << "Nilai UAS  : ";
        cin >> daftarMahasiswa[i].uas;
        cout << "Nilai Tugas: ";
        cin >> daftarMahasiswa[i].tugas;

        daftarMahasiswa[i].nilai_akhir = hitungNilaiAkhir(
            daftarMahasiswa[i].uts, 
            daftarMahasiswa[i].uas, 
            daftarMahasiswa[i].tugas
        );
    }

    cout << "\n\n============================================================" << endl;
    cout << "                 DAFTAR NILAI MAHASISWA                     " << endl;
    cout << "============================================================" << endl;
    cout << left << setw(15) << "Nama" 
         << setw(12) << "NIM" 
         << setw(8) << "UTS" 
         << setw(8) << "UAS" 
         << setw(8) << "Tugas" 
         << setw(10) << "Akhir" << endl;
    cout << "------------------------------------------------------------" << endl;

    for (int i = 0; i < jumlahInput; i++) {
        cout << left << setw(15) << daftarMahasiswa[i].nama 
             << setw(12) << daftarMahasiswa[i].nim 
             << setw(8) << daftarMahasiswa[i].uts 
             << setw(8) << daftarMahasiswa[i].uas 
             << setw(8) << daftarMahasiswa[i].tugas 
             << setw(10) << fixed << setprecision(2) << daftarMahasiswa[i].nilai_akhir << endl;
    }
    cout << "============================================================" << endl;

    return 0;
}