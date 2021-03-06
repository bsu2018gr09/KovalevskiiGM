//Класс - парабола. Хранятся коэффициенты и координаты вершины
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

class Parabola {
public:
	Parabola() : a(1), b(0), c(0), vertX(0), vertY(0) { cout << "Constructor by default\n"; };

	Parabola(float tmp1, float tmp2 = 0, float tmp3 = 0) : a(tmp1), b(tmp2), c(tmp3), vertX(0), vertY(0) {
		if (a == 0) {
			cout << "This parabola does not exist! Setting the first coefficient to default\n";
			a = 1;
		}
		findVertX();
		findVertY();
		cout << "Constructor\n";
	};

	Parabola(Parabola const &tmp) : a(tmp.a), b(tmp.b), c(tmp.c) { cout << "Copy constructor\n"; };

	Parabola& operator = (const Parabola& other) {
		this->a = other.a;
		this->b = other.b;
		this->c = other.c;
		findVertX();
		findVertY();
		return *this;
	}

	~Parabola() { cout << "Destructor\n"; };

	Parabola& operator + (const Parabola& other) {
		this->a += other.a;
		if (!this->a) {
			cout << "This parabola does not exist! Setting the first coefficient to default\n";
			a = 1;
		}
		this->b += other.b;
		this->c += other.c;
		findVertX();
		findVertY();
		return *this;
	}

	Parabola& operator - (const Parabola& other) {
		this->a -= other.a;
		if (!this->a) {
			cout << "This parabola does not exist! Setting the first coefficient to default\n";
			a = 1;
		}
		this->b -= other.b;
		this->c -= other.c;
		findVertX();
		findVertY();
		return *this;
	}

	Parabola& operator * (float t) {
		this->a *= t;
		if (!this->a) {
			cout << "This parabola does not exist! Setting the first coefficient to default\n";
			a = 1;
		}
		this->b *= t;
		this->c *= t;
		findVertX();
		findVertY();
		return *this;
	}

	Parabola& operator / (float t) {
		if (!t) {
			cout << "This parabola does not exist!\n";
			return *this;
		}
		this->a /= t;
		this->b /= t;
		this->c /= t;
		findVertX();
		findVertY();
		return *this;
	}

	void seta(float t) { a = t;
	if (!a) {
		cout << "This parabola does not exist! Setting the first coefficient to default\n";
		a = 1;
		}
	};

	void setb(float t) { b = t; };

	void setc(float t) { c = t; };

	void findVertex(){
		findVertX();
		findVertY();
	};

	void setall(float t, float m, float p) {
		a = t;
		if (!a) {
			cout << "This parabola does not exist! Setting the first coefficient to default\n";
			a = 1;
		}
		b = m;
		c = p;
	}

	

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
	float vertX;
	float vertY;
	void findVertX() { this->vertX = -this->b / (2 * this->a); };
	void findVertY() { vertY = -(b*b - 4 * a * c) / (4 * a); };
};

int main() {
	Parabola* p = new (nothrow) Parabola[5] ;
	(*p).setall(5, 7, 2);
	Parabola p2(3, 5, 7);
	(*(p + 1)).setall(10, 10, 10);
	cout << *p + p2 << '\n';
	cout << *(p + 1) - p2 << '\n';
	cout << *p / 0 << '\n';
	cout << *(p + 1) / 2 << '\n';
	
	cout << setprecision(1) << "The vertex is: " << p2.getVertX() << " " << p2.getVertY() << '\n';
	p2.setb(10);
	p2.findVertex();
	cout << setprecision(1) << "The vertex is: " << p2.getVertX() << " " << p2.getVertY() << '\n';
	delete[] p;
	system("pause");
	return 0;
}