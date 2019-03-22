//В массиве А(N,M) переставить строки в порядке возрастания элементов последнего столбца.
//Примечание: Основное задание не выполнено, у меня вылетает runtime error. Постараюсь разобраться.
#include <iostream>
#include <clocale>
#include <ctime>
#include <iomanip>

using namespace std;

int** giveMemory(int n, int m);
void initAr(int** ptr, int n, int m);
void printAr(int** ptr, int n, int m);
void freeMemory(int** ptr, int n, int m);
void sortAr(int** ptr, int n, int m);

int main() {
	int n(0);
	int m(0);
	setlocale(LC_ALL, "Russian");
	cout << "Введите количество строк" << '\n';
	cin >> n;
	cout << "Введите количество столбцов" << '\n';
	cin >> m;
	int** ptr = giveMemory(n, m);
	initAr(ptr, n, m);
	sortAr(ptr, n, m);
	printAr(ptr, n, m);
	freeMemory(ptr, n, m);
	system("pause");
	return 0;
}

int** giveMemory(int n, int m) {
	int** ptr = new (nothrow) int*[n];
	for (int i = 0; i < m; i++)
		ptr[i] = new (nothrow) int[m];
	return ptr;
}

void initAr(int** ptr, int n, int m) {
	srand(time(NULL));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			ptr[i][j] = rand() % 20 - 10;
		}
	
}

void printAr(int** ptr, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << setw(4) << ptr[i][j];
		}
		cout << '\n';
	}
}

void freeMemory(int** ptr, int n, int m) {
	for (int i = 0; i < m; i++) {
		delete[] ptr[i];
		ptr[i] = nullptr;
	}//не хватает ещё delete
}

void sortAr(int** ptr, int n, int m) {
	int max(0);
	int k(1);
	int* maxp = nullptr;
	int* tmp = nullptr;
	int** pp = ptr;
	for (int i = 0; i < n-1; ++i) {
		max = pp[i][m-1];
		for( i+k; k<n; ++k)
			if (ptr[i+k][m-1] >= max) {
				ptr[i] = ptr[i+k]; // ошибка. Утечка памяти
			}
		
		
	}

}
