//Класс - парабола. Хранятся коэффициенты и координаты вершины
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

class Parabola {
public:
	Parabola() : a(1), b(0), c(0) { cout << "Constructor by default\n"; };

	Parabola(float tmp1, float tmp2 = 0, float tmp3 = 0) : a(tmp1), b(tmp2), c(tmp3) {
		if (a == 0) {
			cout << "This parabola does not exist!\n";
			system("pause");
		exit(1);
		}
		cout << "Constructor\n";
	};

	Parabola(Parabola const &tmp) : a(tmp.a), b(tmp.b), c(tmp.c) { cout << "Copy constructor\n"; };

	Parabola& operator = (const Parabola& other) {
		this->a = other.a;
		this->b = other.b;
		this->c = other.c;
		return *this;
	}

	~Parabola() { cout << "Destructor\n"; };

	Parabola& operator + (const Parabola& other) {
		this->a += other.a;
		this->b += other.b;
		this->c += other.c;
		return *this;
	}

	Parabola& operator - (const Parabola& other) {
		this->a -= other.a;
		this->b -= other.b;
		this->c -= other.c;
		return *this;
	}

	Parabola& operator * (float t) {
		this->a *= t;//а проверить!!!!
		this->b *= t;
		this->c *= t;
		return *this;
	}

	Parabola& operator / (float t) {
		this->a /= t;////а проверить!!!!
		this->b /= t;
		this->c /= t;
		return *this;
	}

	void seta(float t) { a = t;
	if (a == 0) {
		cout << "This parabola does not exist!\n";
		system("pause");
		exit(1);
		}
	};

	void setb(float t) { b = t; };

	void setc(float t) { c = t; };

	void setall(float t, float m, float p) {
		a = t;
		if (a == 0) {
			cout << "This parabola does not exist!\n";
			system("pause");
			exit(1);
		}
		b = m;
		c = p;
	}

	void findVertX() { this->vertX = - this->b / (2 * this->a); };

	void findVertY() { vertY = -(b*b - 4 * a * c) / (4 * a); };

	float geta() { return a; };

	float getb() { return b; };

	float getc() { return c; };

	float getVertX() { return vertX; };

	float getVertY() { return vertY; };

	friend ostream& operator << (ostream & stream, const Parabola& par)
	{
		stream << "(" << par.a << ", " << par.b << ", " << par.c << ")" ;
		return stream;
	}

	friend istream& operator >> (istream& stream, Parabola& par) { 
		stream >> par.a;
		stream >> par.b;
		stream >> par.c;
		return stream;
	}

private:
	float a;
	float b;
	float c;
	float vertX;// и они почти всегда у тебя мусором будут заполнены!!!!
	float vertY;
};

int main() {
	Parabola* p = new (nothrow) Parabola[5] ;
	(*p).setall(5, 7, 2);
	Parabola p2(3, 5, 7);
	(*(p + 1)).setall(10, 10, 10);
	cout << *p + p2 << '\n';
	cout << *(p + 1) - p2 << '\n';
	cout << *p * 3 << '\n';
	cout << *(p + 1) / 2 << '\n';
	p2.findVertX();
	p2.findVertY();
	cout << setprecision(1) << "The vertex is: " << p2.getVertX() << " " << p2.getVertY() << '\n';
	delete[] p;
	system("pause");
	return 0;
}
