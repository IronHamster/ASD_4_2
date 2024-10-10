#include <iostream>
#include <string>
using namespace std;

int kolejka[11];
int poczatek = 0;
int koniec = 0;

void Enqueue(int liczba) {
    if ((koniec + 1) % 11 == poczatek) {
        cout << "Error: queue is full" << endl;
    } else {
        kolejka[koniec] = liczba;
        koniec = (koniec + 1) % 11;
        cout << "--->" << endl;
    }
}

void Dequeue() {
    if (poczatek == koniec) {
        cout << "Error: queue is empty" << endl;
    } else {
        cout << kolejka[poczatek] << endl;
        poczatek = (poczatek + 1) % 11;
    }
}

void Print() {
    if (poczatek == koniec) {
        cout << "Print: Queue is empty" << endl;
    } else {
        cout << "Print: ";
        for (int i = poczatek; i != koniec; i = (i + 1) % 11) {
            cout << kolejka[i];
            if ((i + 1) % 11 != koniec) {
                cout << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    string komenda;
    int liczba;

    while (cin >> komenda) {
        if (komenda == "Enqueue") {
            cin >> liczba;
            Enqueue(liczba);
        } else if (komenda == "Dequeue") {
            Dequeue();
        } else if (komenda == "Print") {
            Print();
        }
    }

    return 0;
}
