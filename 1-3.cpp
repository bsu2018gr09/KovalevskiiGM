/*
	Элементы массива А(N), значения которых – простые числа, расположить в порядке возрастания, не нарушая порядка следования других элементов.
*/
#include <iostream>
#include <time.h>
#include <cmath>

using namespace std;

int N{ 0 };
int* newAr(int* p, int N);
void freeAr(int* p);
void randInit(int* p, int N);
void sortPrime(int*p, int N);
void printAr(int* p, int N);

int main() {
	cout << "Enter the size" << '\n';
	cin >> N;
	int* p = nullptr;
	p = newAr(p, N);
	randInit(p, N);
	sortPrime(p, N);
	printAr(p, N);
	system("pause");
	return 0;
}

int* newAr(int* p, int N) {
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
		x = rand()%100 + 100; 
		*(p + i) = x;
	}
}

bool isPrime(int num) {
	if (num = 1)
		return false;
	for (int ch = 2; ch <= sqrt(num); ++ch)
		if (!(num % ch)) {
				return false;
		}
	return true;
}

void sortPrime(int* p, int N)
{
	for (int i(0); i < N; i++) {
		int* curptr = nullptr;
		int* prevptr = nullptr;
		for (int* tmp = p; tmp < p + N; tmp++) {
			if (curptr && isPrime(*tmp) && (*tmp < *curptr)) {
				swap(*curptr, *tmp);
				prevptr = curptr;
				curptr = tmp;
			}
			else if (isPrime(*tmp)) {
				prevptr = curptr;
				curptr = tmp;
			}
			
		}
	}

}

void printAr(int* p, int N) {
	cout << "Your array is: ";
	for (int i = 0; i < N; i++)
		cout << *(p + i) << ' ';
	cout << '\n';
}