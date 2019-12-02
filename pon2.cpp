// Zadanie 1 (6 pkt) (efekt 2)
// Napisz program, który pobiera od u¿ytkownika liczbê naturaln¹ n, a nastêpnie 
// wypisuje na ekran trzecie potêgi liczb naturalnych dodatnich mniejszych b¹dŸ równych
// liczbie n z odpowiednim formatowaniem.
// Na przyk³ad dla liczby 7 program wypisze:
// 1^3 = 1,
// 2^3 = 8,
// 3^3 = 27,
// 4^3 = 64
// 5^3 = 125,
// 6^3 = 216,
// 7^3 = 343.

// Zadanie 2 (6 pkt) (efekt 4)
// Napisz funkcjê, która dla zadanej tablicy liczb zwraca odchylenie standardowe
// zbioru tych liczb.
// Deklaracja funkcji: double odchylenieSTD(double *tab, int rozmiar), gdzie tab jest 
// wskaŸnikiem do tablicy, zaœ rozmiar jest rozmiarem tej tablicy. U¿yj notacji wskaŸnikowej.
// Wzór na odchylenie standardowe zbioru liczb {x1, x2, ..., xn}:
// s = pierwiastek_kwadratowy( 1/n * [ (x1 - m)^2 + (x2 - m)^2 + ... + (xn - m)^2 ]),
// gdzie s - odchylenie standardowe, m - œrednia arytmetyczn liczb, n - rozmiar zbioru.

// Zadanie 3 (8 pkt) (efekt 3)
// Napisz funkcjê, której parametrem jest liczba naturalna. Funkcja wypisuje na ekran
// konsoli szachownicê o zadanym wymiarze. Pojedyncze pole szachownicy jest wymiaru 3x3.
// Szachownica zaczyna siê od "bia³ego" pola.
// Deklaracja funkcji:  void szachownica(int rozmiar);
// Np. szachownica(5) wypisze:

//				___xxx___xxx___
//				___xxx___xxx___
//				___xxx___xxx___
//				xxx___xxx___xxx
//				xxx___xxx___xxx
//				xxx___xxx___xxx
//				___xxx___xxx___
//				___xxx___xxx___
//				___xxx___xxx___
//				xxx___xxx___xxx
//				xxx___xxx___xxx
//				xxx___xxx___xxx
//				___xxx___xxx___
//				___xxx___xxx___
//				___xxx___xxx___


#include<iostream>
using namespace std;

//deklaracje funkcji:
void napiszPotegi();
double odchylenieSTD(double* tab , int rozmiar);
void szachownica (int rozmiar);

int main()
{
	//napiszPotegi();

	double tablica[5] = { 1, 2, 3, 4, 5 };
	cout << odchylenieSTD(tablica, 5) << endl;

	//szachownica(4);

	system("pause");
}

//definicje funkcji:
void napiszPotegi() {
	int n;
	cout << "Podaj liczbe: "; cin >> n;
	for (n; n > 1; n--) {
		cout << n << "^3 = " << pow(n, 3) << "," << endl;
		//cout << n << "^3 = " << n * n * n << "," << endl;
	}
	cout << "1^3 = 1." << endl;

}

double odchylenieSTD(double *tab, int rozmiar)
{
	// implementacja funkcji
	double prawa{};
	double srednia{};
	for (int i = 0; i < rozmiar; i++) {
		srednia += *(tab + i);
	} srednia /= rozmiar;

	for (int i = 0; i < rozmiar; i++) {
		prawa += pow(*(tab + i) - srednia, 2);
		//prawa += (*(tab + i) - srednia) * (*(tab + i) - srednia)
	}
	return sqrt(( (double)1 / rozmiar) * prawa);
}

void szachownica(int rozmiar)
{
	for (int i = 0; i < rozmiar * 3; i++) {
		for (int j = 0; j < rozmiar; j++) {
			if ((i / 3) % 2) { // (i / 3) zwiekszy sie o 1 tylko po 3 iteracjach, gdyz jest to int
				if (j % 2) {
					cout << "___";
				} else {
					cout << "xxx";
				}
			} else {
				if (!(j % 2)) {
					cout << "___";
				} else {
					cout << "xxx";
				}
			}
		}
		cout << endl;
	}
}
