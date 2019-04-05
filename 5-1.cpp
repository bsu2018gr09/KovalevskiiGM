#include<iostream> //где условие задачи? Какой градиент ты делаешь???
#include<fstream>  
#include <clocale>
using namespace std;
struct color { unsigned char r; unsigned char g; unsigned char b; } c;
struct tmp { float r; float g; float b; } t;

void swap(unsigned char &a, unsigned char &b) {//зачем?????????????? Есть встроенный swap!!!
	a += b;//это потенциально очень опасное место!!!!!!! Можно легко получить переполнение!!!!!
	b = a - b;
	a = a - b;
}

int main() {
	setlocale(LC_ALL, "Russian");
	ifstream fff("c:\\test.bmp", ios::binary); //  ios::binary влияет ТОЛЬКО на endl.
	ofstream ggg("c:\\rez.bmp", ios::binary);//сюда пишем (поток типа ofstream= output file stream)
	if (!fff) { cout << "No file d:\\1.bmp. Can't open\n"; exit(1); }
	if (!ggg) { cout << "   file d:\\rez.bmp. Can't create\n"; exit(1); }

	unsigned char rr(0), gg(0), bb(0);
	float steps(0);
	int stepr(0), stepg(0), stepb(0);
	char buf[30];// Куда читать байты
	unsigned char r, g, b;//Компоненты цвета
	color c;
	tmp t;
	unsigned int w, h;//Надеемся, что тут 4 байта

	fff.read((char *)&buf, 18);   //Чтение 18 байт заголовка bmp
	ggg.write((char *)&buf, 18);    //Запись 18 байт заголовка bmp
	fff.read((char *)&w, 4); cout << "w=" << w;   //Чтение width из заголовка bmp
	fff.read((char *)&w, 4); cout << ", h=" << w; //Чтение height из заголовка bmp
	cout << "Введите ширину: ";
	cin >> w;
	if (w % 4) {
		cout << "Неверное значение\n";
		exit(1);
	}
	ggg.write((char *)&w, 4);    //Запись width в заголовок bmp ( w кратно 4, обязательно для нас, чтобы не делать выравнивание)
	cout << "Введите высоту: ";
	cin >> h;
	ggg.write((char *)&h, 4);    //Запись height в заголовок bmp
	fff.read((char *)&buf, 28);   //Чтение 28 байт заголовка bmp
	ggg.write((char *)&buf, 28);    //Запись 28 байт заголовка bmp

	/*cout << "Введите в RGB начальный цвет: ";
	cout << "Введите r\n";
	cin >> c.r;
	cout << "Введите g\n";
	cin >> c.g;
	cout << "Введите b\n";
	cin >> c.b;
	cout << "Введите в RGB конечный цвет: ";
	cout << "Введите rr\n";
	cin >> rr;
	cout << "Введите gg\n";
	cin >> gg;
	cout << "Введите bb\n";
	cin >> bb;
	cout << "Количество шагов: ";
	cin >> steps;*/
	//Хотел сделать набор цветов и количества шагов с клавиатуры, но некоторые cin просто пропускаются в консоли.

	c.r = 255;
	c.g = 0;
	c.b = 0;

	rr = 0;
	gg = 0;
	bb = 255;

	steps = 200;

	swap(c.r, rr);
	swap(c.g, gg);
	swap(c.b, bb);

	stepr = ((float)rr - c.r) / steps;
	stepg = ((float)gg - c.g) / steps;
	stepb = ((float)bb - c.b) / steps;
	t.r = (float)c.r;
	t.g = (float)c.g;
	t.b = (float)c.b; {
		for (unsigned int i = 1; i <= h; i++)
			for (unsigned int j = 1; j <= w; j++) {
				ggg.write((char *)&c, 3);
				c.r += stepr;
				c.g += stepg;
				c.b += stepb;
			}
		c.r = (unsigned char)t.r;
		c.g = (unsigned char)t.g;
		c.b = (unsigned char)t.b;
	}
	

	fff.close();//закрыли файл
	ggg.close();//закрыли файл
	return 1;
} 

