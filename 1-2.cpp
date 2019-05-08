/*Положительные элементы массива А(N) переставить в конец массива, сохраняя порядок следования.
Отрицательные элементы расположить в порядке убывания. Дополнительный массив не использовать.*/

//Примечание: периодически программа крашится, а также во время выполнения появляется непонятное число, я не понимаю, почему :(
// Ответ: я так и не видел тебя сидящим около меня с ноутом. Раз ты сам пошагово не можешь отлаживать, то научим....
#include <iostream>
#include <time.h>

using namespace std;

int N{ 0 };
int* newAr(int* p, int N);
void freeAr(int* p);
void randInit(int* p, int N);
void sortAr(int* p, int N);
void printAr(int* p, int N);

int main() {
	cout << "Enter the size" << '\n';
	cin >> N;
	int* p = nullptr;
	p = newAr(p, N);
	randInit(p, N);
	sortAr(p, N);
	printAr(p, N);

	system("pause");
	return 0;
}

int* newAr(int* p, int N){
	p = new (nothrow) int[N];
	if (!p)
		cout << "Error" << '\n';
	return p;
}

void freeAr(int* p) {
	delete[]p;
	p = nullptr;
}

void randInit(int* p, int n) {
	int x(0);
	srand(time(0));
		for (int i = 0; i < n; ++i) {	
			x = rand()%20 - 8;
			*(p + i) = x;
		}
}

void sortAr(int* p, int N) {
	int* end = nullptr;
	int* tmp = p;
	int swap(0);
	end = p + N;
		while (tmp != end)
		{
			if ((*tmp >= 0) && (*end < 0)) {
				swap = *tmp;
				*tmp = *end;
				*end = swap;
				end--;
				tmp++;
			}
			else if (*end >= 0)
				end--;
			else if (*tmp < 0)
				tmp++;
		}
		tmp = nullptr;
		
		if (*end > 0)
			end = end - 1;
		tmp = p;
		for (p; p < end; end--) {
			for (tmp; tmp < end; tmp++)
			{
				if (*tmp < *(tmp + 1)) {
					swap = *tmp;
					*tmp = *(tmp + 1);
					*(tmp + 1) = swap;
				}

			}
			tmp = p;
		}
	}

void printAr(int* p, int N) {
	cout << "Your array is: ";
	for (int i = 0; i < N; i++)
		cout << *(p + i) << ' ';
	cout << '\n';
}
		

