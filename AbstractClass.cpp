
#include <iostream>
#include <string>
#include <math.h>
using namespace std;

class Figure
{
private:
	virtual int Peremeter() = 0;
	virtual double Square() = 0;
	virtual void FigureType() = 0;
	virtual void GetInfo() = 0;
};

class Triangle : private Figure
{
private:
	int a;
	int b;
	int c;
	double p;
public: 
	int Peremeter() override
	{
		cout << "Периметр фигуры = " << a + b + c << endl;
		return 0;
	}

	double Square() override
	{
		p = (a + b + c) / 2;
		cout << "Площадь фигуры = " << sqrt(p * (p - a) * (p - b) * (p - c)) << endl;
		return 0;
	}

	void FigureType()
	{
		cout << "Это треугольник!!" << endl;
	}

	void GetInfo()
	{
		FigureType();
		Peremeter();
		Square();
		
	}

	Triangle(int aValue = 0, int bValue = 0, int cValue = 0, double pValue = 0) 
	{
		a = aValue;
		b = bValue;
		c = cValue;
		p = pValue;
	}
	~Triangle();

};

class Rectangle : private Figure
{
private:
	int a;
	int b;
	int c;
	int d;
	double p;

	int Peremeter() override
	{
		cout << "Периметр фигуры = " << a + b + c + d << endl;
		return 0;
	}

	double Square() override
	{
		cout << "Площадь фигуры = " << (a + b) * 2 << endl;
		return 0;
	}

	void FigureType()
	{
		cout << "Это прямоугольник!!" << endl;
	}

public:
	void GetInfo()
	{
		FigureType();
		Peremeter();
		Square();

	}

	Rectangle(int aValue = 0, int bValue = 0, int cValue = 0, int dValue = 0)
	{
		a = aValue;
		b = bValue;
		c = cValue;
		d = dValue;
	}
	~Rectangle();

};

class Circle : private Figure
{
private:
	int r;
	const float Pi = 3.14;
	int Peremeter() override
	{
		cout << "Периметр фигуры = " << 2*Pi*r << endl;
		return 0;
	}
	double Square() override
	{
		cout << "Площадь фигуры = " << Pi * (r * r);
		return 0;
	}
	void FigureType()
	{
		cout << "Это окружность!!!" << endl;
	}
	
public:
	void GetInfo()
	{
		FigureType();
		Peremeter();
		Square();

	}
	Circle(int rValue = 0)
	{
		r = rValue;
	}
	~Circle();

};



int main()
{
	setlocale(LC_ALL, "Russian");
	int StoronaA;
	int StoronaB;
	int StoronaC;
	int StoronaD;
	cout << "Введите стороны желаемой фигуры, или радиус окружности,"<< endl <<"остальные стороны в таком случае оставьте пустыми." << endl << "!НЕ ВВОДИТЬ ОТРИЦАТЕЛЬНЫЕ ИЛИ ДРОБНЫЕ ЧИСЛА!" << endl;
	cin >> StoronaA >> StoronaB >> StoronaC >> StoronaD;
	if ((StoronaA != 0) & (StoronaB != 0) & (StoronaC != 0) && (StoronaD == 0)) 
	{
		Triangle XAM(StoronaA, StoronaB, StoronaC);
		XAM.GetInfo();
	}
	else if (((StoronaA == StoronaC) & (StoronaB == StoronaD)) || ((StoronaA == StoronaB) & (StoronaC == StoronaD)))
	{
		Rectangle HEF(StoronaA, StoronaB, StoronaC, StoronaD);
		HEF.GetInfo();
	}
	else if ((StoronaB == 0) & (StoronaC == 0) & (StoronaD == 0))
	{
		Circle OQC(StoronaA);
		OQC.GetInfo();
	}
	else
	{
		cout << "Странную фигуру вы однако загадали... Поки" << endl;
	}
}

