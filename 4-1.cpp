/*После каждого трёхбуквенного слова в строке вставить заданную подстроку.
Отсортировать строки по количеству вставленных подстрок.*/

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<clocale>
#include<cstring>

using namespace std;

void findNeededWord(char* tmp, char* substr);

ifstream inp("c:\\proj\\input.txt");
ofstream outp("c:\\proj\\output.txt");

int main() {
	setlocale(LC_ALL, "Russian");
	const int N(200);
	char *buff = new char[N];
	char* tmp = buff;
	char substr[5];
	cin >> substr;

	if (!inp) cout << "Can't read file\n";
	if (!outp) cout << "Can't create file\n";
	int count(0);
	while (true) {
		inp.getline(buff, N - 1);
		if (inp.fail()) inp.clear();
		tmp = buff;
		while (tmp) {
			findNeededWord(tmp, substr);
			tmp = nullptr;
		}
		if (inp.eof())
			break;
		outp << '\n';
		
	}
	delete[] buff;
	buff = nullptr;
	inp.close();
	outp.close();
	system("pause");
	return 0;

}

void findNeededWord(char* tmp, char* substr) {
	char* word = strtok(tmp, " ,.:;&?");
	while (word) {
		if (strlen(word) == 3) {
			outp << word << substr << ' ';
		}
		else
			outp << word << ' ';
		word = strtok(NULL, " ,.:;&?");
	}
}

