#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Buku {
    string judul;
    string penulis;
    int tahunTerbit;
    string isbn;
};

void tambahBuku(vector<Buku>& daftarBuku) {
    Buku bukuBaru;
    
    cout << "\nMasukkan informasi buku baru:\n";
    cout << "Judul: ";
    cin.ignore();
    getline(cin, bukuBaru.judul);
    
    cout << "Penulis: ";
    getline(cin, bukuBaru.penulis);
    
    cout << "Tahun Terbit: ";
    cin >> bukuBaru.tahunTerbit;
    
    cout << "ISBN: ";
    cin.ignore();
    getline(cin, bukuBaru.isbn);
    
    daftarBuku.push_back(bukuBaru);
    cout << "\nBuku berhasil ditambahkan!\n";
}

void tampilkanDaftarBuku(const vector<Buku>& daftarBuku) {
    cout << "\nDaftar Buku:\n";
    if (daftarBuku.empty()) {
        cout << "Tidak ada buku dalam daftar.\n";
        return;
    }
    
    for (const auto& buku : daftarBuku) {
        cout << "Judul: " << buku.judul << "\n";
        cout << "Penulis: " << buku.penulis << "\n";
        cout << "Tahun Terbit: " << buku.tahunTerbit << "\n";
        cout << "ISBN: " << buku.isbn << "\n";
        cout << "-------------------------\n";
    }
}

void cariBuku(const vector<Buku>& daftarBuku) {
    string keyword;
    cout << "\nMasukkan judul atau ISBN untuk mencari buku: ";
    cin.ignore();
    getline(cin, keyword);
    
    bool ditemukan = false;
    for (const auto& buku : daftarBuku) {
        if (buku.judul == keyword || buku.isbn == keyword) {
            cout << "\nBuku ditemukan:\n";
            cout << "Judul: " << buku.judul << "\n";
            cout << "Penulis: " << buku.penulis << "\n";
            cout << "Tahun Terbit: " << buku.tahunTerbit << "\n";
            cout << "ISBN: " << buku.isbn << "\n";
            ditemukan = true;
            break;
        }
    }
    
    if (!ditemukan) {
        cout << "Buku tidak ditemukan.\n";
    }
}

void hapusBuku(vector<Buku>& daftarBuku) {
    string keyword;
    cout << "\nMasukkan judul atau ISBN buku yang ingin dihapus: ";
    cin.ignore();
    getline(cin, keyword);
    
    auto it = find_if(daftarBuku.begin(), daftarBuku.end(), [&](const Buku& buku) {
        return buku.judul == keyword || buku.isbn == keyword;
    });

    if (it != daftarBuku.end()) {
        daftarBuku.erase(it);
        cout << "Buku berhasil dihapus.\n";
    } else {
        cout << "Buku tidak ditemukan.\n";
    }
}

int main() {
    vector<Buku> daftarBuku;
    int pilihan;

    do {
        cout << "\nMenu:\n";
        cout << "1. Tambah Buku\n";
        cout << "2. Tampilkan Daftar Buku\n";
        cout << "3. Cari Buku\n";
        cout << "4. Hapus Buku\n";
        cout << "5. Keluar\n";
        cout << "Pilih opsi (1-5): ";
        cin >> pilihan;
        
        switch (pilihan) {
            case 1:
                tambahBuku(daftarBuku);
                break;
            case 2:
                tampilkanDaftarBuku(daftarBuku);
                break;
            case 3:
                cariBuku(daftarBuku);
                break;
            case 4:
                hapusBuku(daftarBuku);
                break;
            case 5:
                cout << "Terima kasih! Program selesai.\n";
                break;
            default:
                cout << "Pilihan tidak valid. Silakan pilih lagi.\n";
                break;
        }
    } while (pilihan != 5);

    return 0;
}
