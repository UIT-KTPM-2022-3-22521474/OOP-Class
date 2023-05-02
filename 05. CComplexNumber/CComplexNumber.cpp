#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

class CComplexNumber
{
private:
	int Real;
	int Imaginary;
public:
	//Initialization methods
	void Init();
	void Init(int, int);
	void Init(const CComplexNumber&);
	CComplexNumber();
	CComplexNumber(int, int);
	CComplexNumber(const CComplexNumber&);
	void Input();
	friend istream& operator>>(istream& is, CComplexNumber& cn);

	//Information provider methods
	void Output();
	friend ostream& operator<<(ostream& os, CComplexNumber& cn);
	int getReal();
	int getImaginary();

	//Information update methods
	void setReal();
	void setImaginary();
	CComplexNumber& operator=(const CComplexNumber&);

	//"Check-if" methods
	bool isReal();
	bool isImaginary();
	bool isQuarter1();
	bool isQuarter2();
	bool isQuarter3();
	bool isQuarter4();
	bool operator>(const CComplexNumber&);
	bool operator>=(const CComplexNumber&);
	bool operator<(const CComplexNumber&);
	bool operator<=(const CComplexNumber&);
	bool operator==(const CComplexNumber&);
	bool operator!=(const CComplexNumber&);

	//Processing methods
	CComplexNumber Sum(const CComplexNumber&);
	CComplexNumber Diff(const CComplexNumber&);
	CComplexNumber Mult(const CComplexNumber&);
	CComplexNumber Quote(const CComplexNumber&);
	CComplexNumber Power(int);
	CComplexNumber operator+(const CComplexNumber&);
	CComplexNumber operator-(const CComplexNumber&);
	CComplexNumber operator*(const CComplexNumber&);
	CComplexNumber operator/(const CComplexNumber&);
	CComplexNumber operator^(const CComplexNumber&);
	CComplexNumber operator+=(const CComplexNumber&);
	CComplexNumber operator-=(const CComplexNumber&);
	CComplexNumber operator*=(const CComplexNumber&);
	CComplexNumber operator/=(const CComplexNumber&);
	float Module();
	CComplexNumber Conjugate();
};

int main()
{
	
	return 1;
}

//Initialization methods
void CComplexNumber::Init()
{
	Real = 0;
	Imaginary = 0;
}
void CComplexNumber::Init(int r, int i)
{
	Real = r;
	Imaginary = i;
}
void CComplexNumber::Init(const CComplexNumber& cn)
{
	Real = cn.Real;
	Imaginary = cn.Imaginary;
}

CComplexNumber::CComplexNumber()
{
	Real = 0;
	Imaginary = 0;
}
CComplexNumber::CComplexNumber(int r, int i)
{
	Real = r;
	Imaginary = i;
}
CComplexNumber::CComplexNumber(const CComplexNumber& cn)
{
	Real = cn.Real;
	Imaginary = cn.Imaginary;
}

void CComplexNumber::Input()
{
	cout << "Enter the real part:	";
	cin >> Real;
	cout << "Enter the imaginary part:	";
	cin >> Imaginary;
}

istream& operator>>(istream& is, CComplexNumber& cn)
{
	cout << "Enter the real part:	";
	is >> cn.Real;
	cout << "Enter the imaginary part:	";
	is >> cn.Imaginary;
	return is;
}