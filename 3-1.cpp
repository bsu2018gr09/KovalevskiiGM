//Определить количество слов в строке, которые начинаются на заданную букву. Вывести их на экран.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <clocale>

using namespace std;

int max(255);

char* createStr(int max);
void fillStr(char* str, int max);
void printStr(char* str);
void freeStr(char* str);
void findWords(char a, char* str, int max);

int main()
{
	setlocale(LC_ALL, "Russian");
	char* str = nullptr;
	char a;
	str = createStr(max);
	fillStr(str, max);
	cout << "Введите искомую букву" << '\n';
	cin >> a;
	findWords(a, str, max);
	freeStr(str);
	system("pause");
	return 0;
}

char* createStr(int max) {
	char* s = new (nothrow) char[max];
	if (!s) 
		cout << "Error!" << '\n';
	return s;
}

void fillStr(char* str, int max) {
	cin.getline(str, max);
}

void printStr(char* str) {
	cout << str;
}

void freeStr(char* str) {
	delete[] str;
	str = nullptr;
}

void findWords(char a, char* str, int max) {
	char* word = strtok(str, " ,.:;&?");
	int cnt(0);
	while (word) {
		if (word[0] == a) {
			cout << word << " ";
			++cnt;
		}
		word = strtok(NULL, " ,.:;&?");
	}
	cout << '\n' << "Всего букв, начинающихся на " << a << ", " << cnt << '\n';
} 