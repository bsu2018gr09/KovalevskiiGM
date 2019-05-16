/*Даны точки плоскости своими координатами в виде двух одномерных массивов (случайные числа).
 Точки плоскости рассортировать по возрастанию расстояния до прямой ax + by + c = 0.*/

#include <iostream>
#include <time.h>

using namespace std;

int* newAr(int N);
void freeAr(int* p);
void randInit(int* p, int N);
void findDist(int* X, int* Y, int A, int B, int C, float* dist, int N);
void sort(float* dist, int* X, int* Y, int N);
void printRes(int* X, int* Y, int N, float* dist);

int main() {
	int N{ 0 };
	int a{ 0 };
	int b{ 0 };
	int c{ 0 };
	cout << "Enter the number of elements\n";
	cin >> N;
	cout << "Enter a,b,c\n";
	cin >> a >> b >> c;
	int* X = newAr(N);
	randInit(X, N);
	int* Y = newAr(N);
	randInit(Y, N);
	float* dist = new (nothrow) float[N];
	if (!dist)
		cout << "Error\n";
	findDist(X, Y, a, b, c, dist, N);
	sort(dist, X, Y, N);
	printRes(X, Y, N, dist);
	system("pause");
	return 0;
}


int* newAr(int N) {
	int* p = new (nothrow) int[N];
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
		*(p + i)= rand() % 20;
	}
}

void findDist(int* X, int* Y, int A, int B, int C, float* dist, int N) {
	for (int i = 0; i < N; i++) {
		dist[i] = abs(A * X[i] + B * Y[i] + C) / sqrt(A * A + B * B);
	}
}

void sort(float* dist, int* X, int* Y, int N) {
	bool flag = true;
	while (flag) {
		for (int i = 0; i < N - 1; i++) {
			if (dist[i] > dist[i + 1]) {
				swap(dist[i], dist[i + 1]);
				swap(X[i], X[i + 1]);
				swap(Y[i], Y[i + 1]);
				flag = false;
			}
		}
		if (flag) { break; }
		else { flag = true; }
	}
}

void printRes(int* X, int* Y, int N, float* dist) {
	for (int i = 0; i < N; i++) {
		cout << "The distance of the point (" << X[i] << ", " << Y[i] << "): ";
		cout << dist[i] << '\n';
	}
}