#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int GCD(int, int);

class CFraction
{
private:
	int Numerator;
	int Denominator;
public:
	//Initialization methods
	void Init();
	void Init(int);
	void Init(int, int);
	void Init(const CFraction&);
	CFraction();
	CFraction(int);
	CFraction(int, int);
	CFraction(const CFraction&);
	void Input();
	friend istream& operator>>(istream&, CFraction&);

	//Information provider methods
	void Output();
	friend ostream& operator<<(ostream&, CFraction&);
	int getNumerator();
	int getDenominator();
	double getResult();


	//Information update methods
	void setNumerator(int);
	void setDenominator(int);
	CFraction& operator=(const CFraction&);

	//"Check-if" methods
	bool isValid();
	bool isIrreducible();
	bool isZero();
	bool isPos();
	bool isNeg();
	bool operator>(const CFraction&);
	bool operator>=(const CFraction&);
	bool operator<(const CFraction&);
	bool operator<=(const CFraction&);
	bool operator!=(const CFraction&);
	bool operator==(const CFraction&);

	//Processing methods
	void Reduce();
	CFraction Sum(CFraction&);
	CFraction Diff(CFraction&);
	CFraction Mult(CFraction&);
	CFraction Quote(CFraction&);
	CFraction operator+(const CFraction&);
	CFraction operator-(const CFraction&);
	CFraction operator*(const CFraction&);
	CFraction operator/(const CFraction&);
	CFraction& operator+=(const CFraction&);
	CFraction& operator-=(const CFraction&);
	CFraction& operator*=(const CFraction&);
	CFraction& operator/=(const CFraction&);
	CFraction operator^(int);
	CFraction& operator++();
	CFraction& operator--();
	CFraction& operator++(int);
	CFraction& operator--(int);
	~CFraction();
};

int main()
{
	cout << "Project 03 - 22521474 - Class CFraction design." << endl;
	return 1;
}

int GCD(int a, int b)
{
	if (b == 0)
		return a;
	return GCD(b, a % b);
}

//Initialization methods
void CFraction::Init()
{
	Numerator = 0;
	Denominator = 1;
}
void CFraction::Init(int Nume)
{
	Numerator = Nume;
	Denominator = 1;
}
void CFraction::Init(int Nume, int Deno)
{
	Numerator = Nume;
	Denominator = Deno;
}
void CFraction::Init(const CFraction& ft)
{
	Numerator = ft.Numerator;
	Denominator = ft.Denominator;
}

CFraction::CFraction()
{
	Numerator = 0;
	Denominator = 1;
}
CFraction::CFraction(int Nume)
{
	Numerator = Nume;
	Denominator = 1;
}
CFraction::CFraction(int Nume, int Deno)
{
	Numerator = Nume;
	Denominator = Deno;
}
CFraction::CFraction(const CFraction& ft)
{
	Numerator = ft.Numerator;
	Denominator = ft.Denominator;
}

void CFraction::Input()
{
	cout << "Enter the fraction's numerator:		";
	cin >> Numerator;
	cout << "Enter the fraction's denominator:	";
	cin >> Denominator;
}

istream& operator>>(istream& is, CFraction& ft)
{
	cout << "Enter the fraction's numerator:		";
	is >> ft.Numerator;
	cout << "Enter the fraction's denominator:	";
	is >> ft.Denominator;
	return is;
}

//Information provider methods
void CFraction::Output()
{
	if(Denominator < 0)
		cout << -Numerator << "/" << -Denominator;
	else
		cout << Numerator << "/" << Denominator;
}

ostream& operator<<(ostream& os, CFraction& ft)
{
	if (ft.Denominator < 0)
		os << -ft.Numerator << "/" << -ft.Denominator;
	else
		os << ft.Numerator << "/" << ft.Denominator;
	return os;
}

int CFraction::getNumerator()
{
	return Numerator;
}
int CFraction::getDenominator()
{
	return Denominator;
}
double CFraction::getResult()
{
	return (double)Numerator / Denominator;
}

//Information update methods
void CFraction::setNumerator(int Nume)
{
	Numerator = Nume;
}
void CFraction::setDenominator(int Deno)
{
	Denominator = Deno;
}

CFraction& CFraction::operator=(const CFraction& ft)
{
	Numerator = ft.Numerator;
	Denominator = ft.Denominator;
	return *this;
}

//"Check-if" methods
bool CFraction::isValid()
{
	if (Denominator != 0)
		return true;
	return false;
}

bool CFraction::isIrreducible()
{
	if (GCD(Numerator, Denominator) == 1)
		return true;
	return false;
}

bool CFraction::isZero()
{
	if (Numerator == 0)
		return true;
	return false;
}

bool CFraction::isPos()
{
	if (Numerator * Denominator > 0)
		return true;
	return false;
}

bool CFraction::isNeg()
{
	if (Numerator * Denominator < 0)
		return true;
	return false;
}

bool CFraction::operator>(const CFraction& ft)
{
	if ((double)Numerator / Denominator > (double)ft.Numerator / ft.Denominator)
		return true;
	return false;
}

bool CFraction::operator>=(const CFraction& ft)
{
	if ((double)Numerator / Denominator >= (double)ft.Numerator / ft.Denominator)
		return true;
	return false;
}

bool CFraction::operator<(const CFraction& ft)
{
	if ((double)Numerator / Denominator < (double)ft.Numerator / ft.Denominator)
		return true;
	return false;
}

bool CFraction::operator<=(const CFraction& ft)
{
	if ((double)Numerator / Denominator <= (double)ft.Numerator / ft.Denominator)
		return true;
	return false;
}

bool CFraction::operator==(const CFraction& ft)
{
	if ((double)Numerator / Denominator == (double)ft.Numerator / ft.Denominator)
		return true;
	return false;
}

bool CFraction::operator!=(const CFraction& ft)
{
	if ((double)Numerator / Denominator != (double)ft.Numerator / ft.Denominator)
		return true;
	return false;
}

//Processing methods
void CFraction::Reduce()
{
	int gcd = GCD(Numerator, Denominator);
	Numerator /= gcd;
	Denominator /= gcd;
}

CFraction CFraction::Sum(CFraction& ft)
{
	CFraction s;
	s.Numerator = ft.Numerator * Denominator + Numerator * ft.Denominator;
	s.Denominator = ft.Denominator * Denominator;
	return s;
}
CFraction CFraction::Diff(CFraction& ft)
{
	CFraction d;
	d.Numerator = ft.Numerator * Denominator - Numerator * ft.Denominator;
	d.Denominator = ft.Denominator * Denominator;
	return d;
}
CFraction CFraction::Mult(CFraction& ft)
{
	CFraction m;
	m.Numerator = ft.Numerator * Numerator;
	m.Denominator = ft.Denominator * Denominator;
	return m;
}
CFraction CFraction::Quote(CFraction& ft)
{
	CFraction q;
	q.Numerator = Numerator * ft.Denominator;
	q.Denominator = Denominator * ft.Numerator;
	return q;
}

CFraction CFraction::operator+(const CFraction& ft)
{
	CFraction s;
	s.Numerator = ft.Numerator * Denominator + Numerator * ft.Denominator;
	s.Denominator = ft.Denominator * Denominator;
	return s;
}
CFraction CFraction::operator-(const CFraction& ft)
{
	CFraction d;
	d.Numerator = ft.Numerator * Denominator - Numerator * ft.Denominator;
	d.Denominator = ft.Denominator * Denominator;
	return d;
}
CFraction CFraction::operator*(const CFraction& ft)
{
	CFraction m;
	m.Numerator = ft.Numerator * Numerator;
	m.Denominator = ft.Denominator * Denominator;
	return m;
}
CFraction CFraction::operator/(const CFraction& ft)
{
	CFraction q;
	q.Numerator = Numerator * ft.Denominator;
	q.Denominator = Denominator * ft.Numerator;
	return q;
}

CFraction& CFraction::operator+=(const CFraction& ft)
{
	Numerator = ft.Numerator * Denominator + Numerator * ft.Denominator;
	Denominator = ft.Denominator * Denominator;
	return *this;
}
CFraction& CFraction::operator-=(const CFraction& ft)
{
	Numerator = ft.Numerator * Denominator + Numerator * ft.Denominator;
	Denominator = ft.Denominator * Denominator;
	return *this;
}
CFraction& CFraction::operator*=(const CFraction& ft)
{
	Numerator = ft.Numerator * Numerator;
	Denominator = ft.Denominator * Denominator;
	return *this;
}
CFraction& CFraction::operator/=(const CFraction& ft)
{
	Numerator = Numerator * ft.Denominator;
	Denominator = Denominator * ft.Numerator;
	return *this;
}

CFraction CFraction::operator^(int n)
{
	CFraction p{ 1,1 };
	for (int i = 1; i <= n; i++)
		p *= (*this);
	return p;
}

CFraction& CFraction::operator++()
{
	Numerator += Denominator;
	Denominator = Denominator;
	return *this;
}
CFraction& CFraction::operator--()
{
	Numerator -= Denominator;
	Denominator = Denominator;
	return *this;
}
CFraction& CFraction::operator++(int)
{
	Numerator += Denominator;
	Denominator = Denominator;
	return *this;
}
CFraction& CFraction::operator--(int)
{
	Numerator -= Denominator;
	Denominator = Denominator;
	return *this;
}

CFraction::~CFraction()
{
	return;
}