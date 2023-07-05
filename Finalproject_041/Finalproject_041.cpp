#include <iostream>
using namespace std;

class MataKuliah {
private:
    float presensi;
    float activity;
    float exercise;
    float tugasAkhir;
    float NilaiAkhir;

public:
    MataKuliah() {
        presensi = 0;
        activity = 0;
        exercise = 0;
        tugasAkhir = 0;
        NilaiAkhir = 0;
    }

    virtual void input() {
        cout << "Masukkan nilai Presensi: ";
        cin >> presensi;
        cout << "Masukkan nilai Activity: ";
        cin >> activity;
        cout << "Masukkan nilai Exercise: ";
        cin >> exercise;
        cout << "Masukkan nilai Tugas Akhir: ";
        cin >> tugasAkhir;
        cout << "Masukkan nilai Akhir: ";
        cin >> NilaiAkhir;
    }

    virtual void hitungNilaiAkhir() {
        NilaiAkhir = ((presensi * 0.10) + (activity * 0.20) + (exercise * 0.30) + (tugasAkhir * 0.40)) / 4;
    }

    virtual void cekKelulusan() {
        if (NilaiAkhir > 75) {
            cout << "Selamat, Anda lulus mata kuliah dengan nilai akhir " << NilaiAkhir << endl;
        }
        else {
            cout << "Maaf, Anda tidak lulus" << endl;
        }
    }
};

class Pemrograman : public MataKuliah {
public:
    void input() {
        cout << "Mata Kuliah: Pemrograman" << endl;
        MataKuliah::input();
    }

    void hitungNilaiAkhir() {
        MataKuliah::hitungNilaiAkhir();
    }

    void cekKelulusan() {
        MataKuliah::cekKelulusan();
    }
};

int main() {
    char choice;
    do {
        Pemrograman pemrograman;
        pemrograman.input();
        pemrograman.hitungNilaiAkhir();
        pemrograman.cekKelulusan();

        cout << "\nApakah Anda ingin mengulang program? (Y/N): ";
        cin >> choice;
    } while (choice == 'Y' || choice == 'y');

    return 0;
}