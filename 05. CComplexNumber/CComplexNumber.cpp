#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

class CComplexNumber
{
private:
	float Real;
	float Imaginary;
public:
	//Initialization methods
	void Init();
	void Init(float, float);
	void Init(const CComplexNumber&);
	CComplexNumber();
	CComplexNumber(float, float);
	CComplexNumber(const CComplexNumber&);
	void Input();
	friend istream& operator>>(istream& is, CComplexNumber& cn);

	//Information provider methods
	void Output();
	friend ostream& operator<<(ostream& os, CComplexNumber& cn);
	float getReal();
	float getImaginary();

	//Information update methods
	void setReal(float);
	void setImaginary(float);
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
	CComplexNumber& Power(int);
	CComplexNumber operator+(const CComplexNumber&);
	CComplexNumber operator-(const CComplexNumber&);
	CComplexNumber operator*(const CComplexNumber&);
	CComplexNumber operator/(const CComplexNumber&);
	CComplexNumber& operator^(int);
	CComplexNumber operator+=(const CComplexNumber&);
	CComplexNumber operator-=(const CComplexNumber&);
	CComplexNumber operator*=(const CComplexNumber&);
	CComplexNumber operator/=(const CComplexNumber&);
	float Module();
	CComplexNumber Conjugate();
	~CComplexNumber();
};

int main()
{
	cout << "Project 04 - 22521474 - Class CComplexNumber design." << endl;
	return 1;
}

//Initialization methods
void CComplexNumber::Init()
{
	Real = 0;
	Imaginary = 1;
}
void CComplexNumber::Init(float r, float i)
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
	Imaginary = 1;
}
CComplexNumber::CComplexNumber(float r, float i)
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
	cout << "Enter the real part:		";
	cin >> Real;
	cout << "Enter the imaginary part:	";
	cin >> Imaginary;
}

istream& operator>>(istream& is, CComplexNumber& cn)
{
	cout << "Enter the real part:		";
	is >> cn.Real;
	cout << "Enter the imaginary part:	";
	is >> cn.Imaginary;
	return is;
}

//Information provider methods
void CComplexNumber::Output()
{
	cout << Real;
	if (Imaginary == 0)
		return;
	if (Imaginary > 0)
		cout << " + " << Imaginary;
	if (Imaginary < 0)
		cout << " - " << abs(Imaginary);
	cout << "i";
}

ostream& operator<<(ostream& os, CComplexNumber& cn)
{
	os << cn.Real;
	if (cn.Imaginary == 0)
		return os;
	if (cn.Imaginary > 0)
		os << " + " << cn.Imaginary;
	if (cn.Imaginary < 0)
		os << " - " << abs(cn.Imaginary);
	os << "i";
	return os;
}

float CComplexNumber::getReal()
{
	return Real;
}
float CComplexNumber::getImaginary()
{
	return Imaginary;
}

//Information update methods
void CComplexNumber::setReal(float r)
{
	Real = r;
}
void CComplexNumber::setImaginary(float i)
{
	Imaginary = i;
}

CComplexNumber& CComplexNumber::operator=(const CComplexNumber& cn)
{
	Imaginary = cn.Imaginary;
	Real = cn.Real;
	return *this;
}

//"Check-if" methods
bool CComplexNumber::isReal()
{
	if (Imaginary = 0)
		return true;
	return false;
}
bool CComplexNumber::isImaginary()
{
	if (Real == 0 && Imaginary != 0)
		return true;
	return false;
}

bool CComplexNumber::isQuarter1()
{
	if (Real < 0 && Imaginary>0)
		return true;
	return false;
}
bool CComplexNumber::isQuarter2()
{
	if (Real > 0 && Imaginary > 0)
		return true;
	return false;
}
bool CComplexNumber::isQuarter3()
{
	if (Real < 0 && Imaginary < 0)
		return true;
	return false;
}
bool CComplexNumber::isQuarter4()
{
	if (Real > 0 && Imaginary < 0)
		return true;
	return false;
}

bool CComplexNumber::operator>(const CComplexNumber& cn)
{
	CComplexNumber cn1 = *this;
	float cn1m = cn1.Module();
	CComplexNumber cn2 = cn;
	float cn2m = cn2.Module();
	if (cn1m > cn2m)
		return true;
	return false;
}

bool CComplexNumber::operator>=(const CComplexNumber& cn)
{
	CComplexNumber cn1 = *this;
	float cn1m = cn1.Module();
	CComplexNumber cn2 = cn;
	float cn2m = cn2.Module();
	if (cn1m >= cn2m)
		return true;
	return false;
}

bool CComplexNumber::operator<(const CComplexNumber& cn)
{
	CComplexNumber cn1 = *this;
	float cn1m = cn1.Module();
	CComplexNumber cn2 = cn;
	float cn2m = cn2.Module();
	if (cn1m < cn2m)
		return true;
	return false;
}

bool CComplexNumber::operator<=(const CComplexNumber& cn)
{
	CComplexNumber cn1 = *this;
	float cn1m = cn1.Module();
	CComplexNumber cn2 = cn;
	float cn2m = cn2.Module();
	if (cn1m <= cn2m)
		return true;
	return false;
}

bool CComplexNumber::operator==(const CComplexNumber& cn)
{
	CComplexNumber cn1 = *this;
	float cn1m = cn1.Module();
	CComplexNumber cn2 = cn;
	float cn2m = cn2.Module();
	if (cn1m == cn2m)
		return true;
	return false;
}

bool CComplexNumber::operator!=(const CComplexNumber& cn)
{
	CComplexNumber cn1 = *this;
	float cn1m = cn1.Module();
	CComplexNumber cn2 = cn;
	float cn2m = cn2.Module();
	if (cn1m != cn2m)
		return true;
	return false;
}

//Processing methods
CComplexNumber CComplexNumber::Sum(const CComplexNumber& cn)
{
	CComplexNumber s;
	s.Real = Real + cn.Real;
	s.Imaginary = Imaginary + cn.Imaginary;
	return s;
}

CComplexNumber CComplexNumber::Diff(const CComplexNumber& cn)
{
	CComplexNumber d;
	d.Real = Real - cn.Real;
	d.Imaginary = Imaginary - cn.Imaginary;
	return d;
}

CComplexNumber CComplexNumber::Mult(const CComplexNumber& cn)
{
	CComplexNumber m;
	m.Real = Real * cn.Real - Imaginary * cn.Imaginary;
	m.Imaginary = Real * cn.Imaginary - Imaginary * cn.Real;
	return m;
}

CComplexNumber CComplexNumber::Quote(const CComplexNumber& cn)
{
	CComplexNumber q;
	q.Real = (Real * cn.Real + Imaginary * cn.Imaginary) / (cn.Real * cn.Real + cn.Imaginary * cn.Imaginary);
	q.Imaginary = (Imaginary * cn.Real - cn.Imaginary * Real) / (cn.Real * cn.Real + cn.Imaginary * cn.Imaginary);
	return q;
}

CComplexNumber& CComplexNumber::Power(int m)
{
	CComplexNumber p = *this;
	for (int i = 1; i < m; i++)
	{
		p = p * (*this);
	}		
	return p;
}

CComplexNumber CComplexNumber::operator+(const CComplexNumber& cn)
{
	CComplexNumber s;
	s.Real = Real + cn.Real;
	s.Imaginary = Imaginary + cn.Imaginary;
	return s;
}

CComplexNumber CComplexNumber::operator-(const CComplexNumber& cn)
{
	CComplexNumber d;
	d.Real = Real - cn.Real;
	d.Imaginary = Imaginary - cn.Imaginary;
	return d;
}

CComplexNumber CComplexNumber::operator*(const CComplexNumber& cn)
{
	CComplexNumber m;
	m.Real = Real * cn.Real - Imaginary * cn.Imaginary;
	m.Imaginary = Real * cn.Imaginary - Imaginary * cn.Real;
	return m;
}

CComplexNumber CComplexNumber::operator/(const CComplexNumber& cn)
{
	CComplexNumber q;
	q.Real = (Real * cn.Real + Imaginary * cn.Imaginary) / (cn.Real * cn.Real + cn.Imaginary * cn.Imaginary);
	q.Imaginary = (Imaginary * cn.Real - cn.Imaginary * Real) / (cn.Real * cn.Real + cn.Imaginary * cn.Imaginary);
	return q;
}

CComplexNumber& CComplexNumber::operator^(int n)
{
	CComplexNumber p = *this;
	for (int i = 1; i < n; i++)
	{
		p *= (*this);
	}		
	return p;
}

CComplexNumber CComplexNumber::operator+=(const CComplexNumber& cn)
{
	Real += cn.Real;
	Imaginary += cn.Imaginary;
	return *this;
}

CComplexNumber CComplexNumber::operator-=(const CComplexNumber& cn)
{
	Real -= cn.Real;
	Imaginary -= cn.Imaginary;
	return *this;
}

CComplexNumber CComplexNumber::operator*=(const CComplexNumber& cn)
{
	Real = Real * cn.Real - Imaginary * cn.Imaginary;
	Imaginary = Real * cn.Imaginary - Imaginary * cn.Real;
	return *this;
}

CComplexNumber CComplexNumber::operator/=(const CComplexNumber& cn)
{
	Real = (Real * cn.Real + Imaginary * cn.Imaginary) / (cn.Real * cn.Real + cn.Imaginary * cn.Imaginary);
	Imaginary = (Imaginary * cn.Real - cn.Imaginary * Real) / (cn.Real * cn.Real + cn.Imaginary * cn.Imaginary);
	return *this;
}

float CComplexNumber::Module()
{
	return sqrt(Real * Real + Imaginary * Imaginary);
}

CComplexNumber CComplexNumber::Conjugate()
{
	CComplexNumber conj;
	conj.Real = Real;
	conj.Imaginary = -Imaginary;
	return conj;
}

CComplexNumber::~CComplexNumber()
{
	return;
}
