// Горизонтальная заливка
#include<iostream>
#include<fstream>  
#include <clocale>
using namespace std;
struct color { unsigned char r; unsigned char g; unsigned char b; } c;
struct tmp { float r; float g; float b; } t;



int main() {
	setlocale(LC_ALL, "Russian");
	ifstream fff("c:\\proj\\test.bmp", ios::binary); //  ios::binary влияет ТОЛЬКО на endl.
	ofstream ggg("c:\\proj\\rez.bmp", ios::binary);//сюда пишем (поток типа ofstream= output file stream)
	if (!fff) { cout << "No file d:\\1.bmp. Can't open\n"; exit(1); }
	if (!ggg) { cout << "   file d:\\rez.bmp. Can't create\n"; exit(1); }

	unsigned char rr(0), gg(0), bb(0);
	float steps(0);
	float stepr(0), stepg(0), stepb(0);
	char buf[30];// Куда читать байты
	unsigned char r, g, b;//Компоненты цвета
	color c;
	tmp t;
	unsigned int w, h;//Надеемся, что тут 4 байта

	r = 20;
	g = 0;
	b = 50;

	rr = 100;
	gg = 100;
	bb = 100;

	steps = 500;


	fff.read((char *)&buf, 18);   //Чтение 18 байт заголовка bmp
	ggg.write((char *)&buf, 18);    //Запись 18 байт заголовка bmp
	fff.read((char *)&w, 4); cout << "w=" << w;   //Чтение width из заголовка bmp
	fff.read((char *)&w, 4); cout << ", h=" << w; //Чтение height из заголовка bmp

	w = 1024;
	ggg.write((char *)&w, 4);    //Запись width в заголовок bmp ( w кратно 4, обязательно для нас, чтобы не делать выравнивание)
	
	h = 512;
	ggg.write((char *)&h, 4);    //Запись height в заголовок bmp
	fff.read((char *)&buf, 28);   //Чтение 28 байт заголовка bmp
	ggg.write((char *)&buf, 28);    //Запись 28 байт заголовка bmp

	stepr = (float)(rr - r) / steps;
	stepg = (float)(gg - g) / steps;
	stepb = (float)(bb - b) / steps;
	t.r = (float)r;
	t.g = (float)g;
	t.b = (float)b; 
	int l = 0;
		for (unsigned int i = 1; i <= h; i++){
			for (unsigned int j = 1; j <= w; j++) {
				if (l < steps) {
					t.r += stepr;
					t.g += stepg;
					t.b += stepb;
					c.r = (unsigned char)t.r;
					c.g = (unsigned char)t.g;
					c.b = (unsigned char)t.g;
					++l;
				}
				
				ggg.write((char *)&c, 3);
				
			}
			t.r = (float)r;
			t.g = (float)g;
			t.b = (float)b;
		l = 0;
	}
	

	fff.close();//закрыли файл
	ggg.close();//закрыли файл
	return 0;
} 
