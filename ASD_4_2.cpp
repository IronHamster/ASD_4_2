#include <iostream>
#include <string>

int kolejka[11];
int poczatek = 0;
int koniec = 0;

void Enqueue(int liczba) {
    if ((koniec + 1) % 11 == poczatek) {
        std::cout << "Error: queue is full" << std::endl;
    } else {
        kolejka[koniec] = liczba;
        koniec = (koniec + 1) % 11;
        std::cout << "--->" << std::endl;
    }
}

void Dequeue() {
    if (poczatek == koniec) {
        std::cout << "Error: queue is empty" << std::endl;
    } else {
        std::cout << kolejka[poczatek] << std::endl;
        poczatek = (poczatek + 1) % 11;
    }
}

void Print() {
    if (poczatek == koniec) {
        std::cout << "Print: Queue is empty" << std::endl;
    } else {
        std::cout << "Print: ";
        for (int i = poczatek; i != koniec; i = (i + 1) % 11) {
            std::cout << kolejka[i];
            if ((i + 1) % 11 != koniec) {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
}

int main() {
    std::string komenda;
    int liczba;

    while (std::cin >> komenda) {
        if (komenda == "Enqueue") {
            std::cin >> liczba;
            Enqueue(liczba);
        } else if (komenda == "Dequeue") {
            Dequeue();
        } else if (komenda == "Print") {
            Print();
        }
    }

    return 0;
}
