#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct kuis {
    string pertanyaan;
    string jawaban;
};

void nilaibenar(int &poin) {
    cout << "Benar, poin bertambah satu\n";
    poin++;
    cout << "Poin: " << poin << endl << endl;
}

void nilaisalah(int &poin) {
    cout << "Salah, poin berkurang satu\n";
    poin--;
    cout << "Poin: " << poin << endl << endl;
}

bool pertanyaanDitanyakan(int index, int *pertanyaanDitanya, int totalPertanyaanDitanyakan) {
    for (int i = 0; i < totalPertanyaanDitanyakan; i++) {
        if (pertanyaanDitanya[i] == index) {
            return true;
        }
    }
    return false;
}

int main() {
    int poin = 0;
    srand(time(NULL));

    kuis questions[6];
    questions[0].pertanyaan = "43+22 sama dengan";
    questions[0].jawaban = "65";
    questions[1].pertanyaan = "Berapa Luas Segitiga siku-siku jika diketahui panjang alasnya 6cm dan tingginya 4";
    questions[1].jawaban = "12";
    questions[2].pertanyaan = "Berapa volume sebuah tabung dengan jari-jari 7 cm dan tinggi 10 cm?";
    questions[2].jawaban = "1540";
    questions[3].pertanyaan = "disediakan data 1,2,3,4,5 berapa rata-ratanya?";
    questions[3].jawaban = "3";
	questions[4].pertanyaan = "Bangun Datar: Tentukan keliling segitiga dengan panjang sisi-sisi 6 cm, 8 cm, dan 10 cm.";
	questions[4].jawaban = "24";
	questions[5].pertanyaan = "Berapa banyak simpul (vertex) yang terdapat dalam sebuah graf yang memiliki 7 sisi (edge)?";
	questions[5].jawaban = "6";
	
    int totalPertanyaan = 6;
    int pertanyaanDitanya[6] = {0}; // Array untuk nyimpen indeks pertanyaan yang sudah ditanyakan
    int totalPertanyaanDitanyakan = 0; // Jumlah pertanyaan yang udah ditanyakan

    for (int i = 0; i < totalPertanyaan; i++) {
        int randomIndex;
        do {
            randomIndex = rand() % totalPertanyaan;
        } while (pertanyaanDitanyakan(randomIndex, pertanyaanDitanya, totalPertanyaanDitanyakan));

        cout << questions[randomIndex].pertanyaan << endl;
        string jawaban;
        cin >> jawaban;

        if (jawaban == questions[randomIndex].jawaban) {
            nilaibenar(poin);
        } else {
            nilaisalah(poin);
        }

        pertanyaanDitanya[totalPertanyaanDitanyakan] = randomIndex;
        totalPertanyaanDitanyakan++;
    }

    cout << "Total Poin yang didapat: " << poin << endl;
}

