#include <iostream>

using namespace std;

const int MAKS = 1000;

int panjangString(char teks[]) {
    int n = 0;
    while (teks[n] != '\0') {
        n++;
    }
    return n;
}

char keKapital(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - 'a' + 'A';
    }
    return c;
}

bool adalahHuruf(char c) {
    return (c >= 'A' && c <= 'Z');
}

int hurufKeAngka(char c) {
    if (adalahHuruf(c)) {
        return c - 'A' + 1;
    }
    return 0;
}

char angkaKeHuruf(int n) {
    return (char)('A' + n - 1);
}

int main() {
    char pesan[MAKS];
    char hasil[MAKS];

    cout << "ALIEN-IN-THE-MIDDLE CIPHER" << endl;
    cout << "Masukkan pesan : ";
    cin.getline(pesan, MAKS);

    int panjang = panjangString(pesan);
    for (int i = 0; i < panjang; i++) {
        pesan[i] = keKapital(pesan[i]);
    }

    cout << "\nPROSES PERGESERAN" << endl;

    for (int i = 0; i < panjang; i++) {

        if (!adalahHuruf(pesan[i])) {
            hasil[i] = pesan[i];
            continue;
        }

        int posisiSekarang = hurufKeAngka(pesan[i]);

        int geser;
        if (i == 0) {
            geser = 0;
        } else {
            geser = hurufKeAngka(pesan[i - 1]);
        }

        int posisiBaru = (posisiSekarang + geser - 1) % 26 + 1;

        hasil[i] = angkaKeHuruf(posisiBaru);

        cout << "Huruf ke-" << (i + 1) << " : " << pesan[i]
             << " (" << posisiSekarang << ") + geser " << geser
             << " = " << (posisiSekarang + geser);
        if (posisiSekarang + geser > 26) {
            cout << " -> wrap jadi " << posisiBaru;
        }
        cout << " -> " << hasil[i] << endl;
    }

    hasil[panjang] = '\0';

    cout << "\nHASIL" << endl;
    cout << "Pesan asli    : " << pesan << endl;
    cout << "Pesan sandi   : " << hasil << endl;

    return 0;
}