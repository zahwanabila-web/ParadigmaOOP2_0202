#include <iostream>
using namespace std;

// Abstract Class
class RekeningBank {
protected:
    int saldo;

public:
    RekeningBank(int s) {
        saldo = s;
    }

    virtual void potongAdmin() = 0;

    void tampilSaldo() {
        cout << "Saldo sekarang : Rp " << saldo << endl;
    }
};

// Rekening Syariah
class RekeningSyariah : public RekeningBank {
public:
    RekeningSyariah(int s) : RekeningBank(s) {
    }
    void potongAdmin() {
        cout << "Tidak ada biaya admin" << endl;
    }
};

// Rekening Konvensional
class RekeningKonvensional : public RekeningBank {
public:
    RekeningKonvensional(int s) : RekeningBank(s) {
    }
    void potongAdmin() {
        saldo = saldo - 15000;
        cout << "Potong admin Rp 15.000" << endl;
    }
};

// Rekening Premium
class RekeningPremium : public RekeningBank {
public:
    RekeningPremium(int s) : RekeningBank(s) {
    }
    void potongAdmin() {
        if (saldo > 10000000) {
            cout << "Bebas biaya admin" << endl;
        } else {
            saldo = saldo - 50000;
            cout << "Potong admin Rp 50.000" << endl;
        }
    }
};

int main() {

    RekeningSyariah a(5000000);
    RekeningKonvensional b(5000000);
    RekeningPremium c(8000000);

    cout << "Rekening Syariah" << endl;
    a.potongAdmin();
    a.tampilSaldo();

    cout << endl;

    cout << "Rekening Konvensional" << endl;
    b.potongAdmin();
    b.tampilSaldo();

    cout << endl;

    cout << "Rekening Premium" << endl;
    c.potongAdmin();
    c.tampilSaldo();

    return 0;
}