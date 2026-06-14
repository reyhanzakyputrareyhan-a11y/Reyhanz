#include <iostream>
#include <string>
using namespace std;
#include <iostream>
#include <string>
using namespace std;

// Fungsi rekursif menampilkan nomor kamar tersedia
void tampilKamar(int nomor) {
    if (nomor > 10)
        return;

    cout << "Kamar Nomor " << nomor << " tersedia" << endl;
    tampilKamar(nomor + 1);
}

// Fungsi menghitung biaya
double hitungBiaya(int harga, int malam) {
    double total = harga * malam;

    if (malam > 3) {
        total = total - (0.15 * total);
    }

    return total;
}

int main() {
    string nama;
    int pilihan, malam, harga;
    char lagi = 'Y';

    cout << "===== SISTEM RESERVASI HOTEL =====" << endl;

    cout << "\nDaftar Kamar Tersedia:" << endl;
    tampilKamar(1);

    while (lagi == 'Y' || lagi == 'y') {
        cin.ignore();

        cout << "\nNama Pelanggan : ";
        getline(cin, nama);

        cout << "\nJenis Kamar" << endl;
        cout << "1. Standard (Rp250000/malam)" << endl;
        cout << "2. Deluxe (Rp450000/malam)" << endl;
        cout << "3. Suite (Rp750000/malam)" << endl;
        cout << "Pilih Jenis Kamar (1-3): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                harga = 250000;
                break;
            case 2:
                harga = 450000;
                break;
            case 3:
                harga = 750000;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
                continue;
        }

        cout << "Jumlah Malam Menginap : ";
        cin >> malam;

        double diskon = 0;
        if (malam > 3) {
            diskon = harga * malam * 0.15;
        }

        double total = hitungBiaya(harga, malam);

        cout << "\n===== RINCIAN PEMBAYARAN =====" << endl;
        cout << "Nama Pelanggan : " << nama << endl;
        cout << "Harga per Malam : Rp" << harga << endl;
        cout << "Jumlah Malam : " << malam << endl;
        cout << "Diskon : Rp" << diskon << endl;
        cout << "Total Bayar : Rp" << total << endl;

        cout << "\nInput pelanggan lagi? (Y/T): ";
        cin >> lagi;
    }

    cout << "\nTerima kasih telah menggunakan sistem reservasi hotel." << endl;

    return 0;
}