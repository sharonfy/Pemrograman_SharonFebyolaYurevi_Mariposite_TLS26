#include <iostream>
#include <vector>

using namespace std;
int main() {
    int N, K;

    cout << "THE LAST ASTRONAUT" << endl;
    cout << "Masukkan jumlah astronot (N) : ";
    cin >> N;
    cout << "Masukkan nilai loncatan (K)  : ";
    cin >> K;

    if (N < 1) {
        cout << "Jumlah astronot minimal 1." << endl;
        return 0;
    }
    if (K < 2) {
        K = 2;
    }

    vector<int> alive;
    for (int i = 1; i <= N; i++) {
        alive.push_back(i);
    }

    vector<int> urutanEliminasi;

    int idx = 0;

    cout << "\nPROSES SIMULASI" << endl;
    int putaran = 1;

    while (alive.size() > 1) {
        int jumlahHidup = (int)alive.size();

        idx = (idx + K - 1) % jumlahHidup;

        int korban = alive[idx];
        urutanEliminasi.push_back(korban);

        cout << "Putaran " << putaran << " : K = " << K
             << " -> Astronot nomor " << korban << " tereliminasi";

        for (int i = idx; i < jumlahHidup - 1; i++) {
            alive[i] = alive[i + 1];
        }
        alive.pop_back();

        if (korban % 2 == 0) {
            K = K + 2; // genap
        } else {
            K = K - 1; // ganjil
        }
        if (K < 2) {
            K = 2; // batas minimal
        }

        cout << " | K baru = " << K << endl;

        if (!alive.empty()) {
            idx = idx % (int)alive.size();
        }

        putaran++;
    }

    cout << "\nHASIL" << endl;
    cout << "Urutan eliminasi : ";
    for (size_t i = 0; i < urutanEliminasi.size(); i++) {
        cout << urutanEliminasi[i];
        if (i < urutanEliminasi.size() - 1) cout << " -> ";
    }
    if (urutanEliminasi.empty()) cout << "(tidak ada)";
    cout << endl;

    cout << "Astronot terakhir yang selamat : " << alive[0] << endl;

    return 0;
}