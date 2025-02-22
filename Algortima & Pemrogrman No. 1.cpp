#include <iostream>
#include <vector>
#include <string>

using namespace std;

char hitung_grade(int nilai) {
    if (nilai >= 80) {
        return 'A';
    } else if (nilai >= 70) {
        return 'B';
    } else if (nilai >= 60) {
        return 'C';
    } else if (nilai >= 50) {
        return 'D';
    } else {
        return 'E';
    }
}

string hitung_status(char grade) {
    if (grade == 'A' || grade == 'B' || grade == 'C') {
        return "Lulus";
    } else if (grade == 'D') {
        return "Mengulang";
    } else {
        return "Tidak Lulus";
    }
}

int main() {
    vector<vector<string>> data_mahasiswa;
    string nim, nama;
    int nilai;
    char grade;
    string status;
    char tambah_lagi;

    do {
        cout << "INPUT :" << endl;
        cout << "Masukkan NIM: ";
        cin >> nim;
        cout << "Masukkan Nama: ";
        cin.ignore();
        getline(cin, nama);
        cout << "Masukkan Nilai: ";
        cin >> nilai;

        grade = hitung_grade(nilai);
        status = hitung_status(grade);

        data_mahasiswa.push_back({nim, nama, to_string(nilai), string(1, grade), status});

        cout << "Ingin tambah lagi [Y/T]: ";
        cin >> tambah_lagi;
    } while (tambah_lagi == 'Y' || tambah_lagi == 'y');

    cout << "\nOUTPUT :" << endl;
    cout << "NIM\t\tNama\t\tNilai\tGrade\tStatus" << endl;
    cout << "------------------------------------------------------" << endl;

    for (const auto& mhs : data_mahasiswa) {
        cout << mhs[0] << "\t" << mhs[1] << "\t" << mhs[2] << "\t" << mhs[3] << "\t" << mhs[4] << endl;
    }

    return 0;
}
