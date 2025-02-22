#include <iostream>
using namespace std;

double celsiusKeFahrenheit(double celsius) {
    return (celsius * 9 / 5) + 32;
}

double fahrenheitKeCelsius(double fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

int main() {
    double suhu;
    int pilihan;

    cout << "Konversi Suhu\n";
    cout << "1. Celsius ke Fahrenheit\n";
    cout << "2. Fahrenheit ke Celsius\n";
    cout << "Pilih jenis konversi (1 atau 2): ";
    cin >> pilihan;

    switch (pilihan) {
        case 1:
            cout << "Masukkan suhu dalam Celsius: ";
            cin >> suhu;
            cout << suhu << " derajat Celsius = " << celsiusKeFahrenheit(suhu) << " derajat Fahrenheit\n";
            break;
        case 2:
            cout << "Masukkan suhu dalam Fahrenheit: ";
            cin >> suhu;
            cout << suhu << " derajat Fahrenheit = " << fahrenheitKeCelsius(suhu) << " derajat Celsius\n";
            break;
        default:
            cout << "Pilihan tidak valid. Program selesai.\n";
            break;
    }

    return 0;
}
