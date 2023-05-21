#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int GCD(int, int);

class CMixedNumber
{
private:
	int IntPart;
	int Numerator;
	int Denominator;
public:
	//Initialization methods
	void Init();
	void Init(int, int, int);
	void Init(const CMixedNumber&);
	CMixedNumber();
	CMixedNumber(int, int, int);
	CMixedNumber(const CMixedNumber&);
	void Input();
	friend istream& operator>>(istream&, CMixedNumber&);

	//Information provider methods
	void Output();
	friend ostream& operator<<(ostream&, CMixedNumber&);
	int getIntPart();
	int getNumerator();
	int getDenominator();
	double getResult();

	//Information update methods
	void setIntPart(int);
	void setNumerator(int);
	void setDenominator(int);
	CMixedNumber& operator=(const CMixedNumber&);

	//"Check-if" methods
	bool isValid();
	bool isIrreducible();
	bool isZero();
	int PosOrNeg();
	bool operator>(const CMixedNumber&);
	bool operator>=(const CMixedNumber&);
	bool operator<(const CMixedNumber&);
	bool operator<=(const CMixedNumber&);
	bool operator!=(const CMixedNumber&);
	bool operator==(const CMixedNumber&);

	//Processing methods
	CMixedNumber Reduce();
	CMixedNumber Sum(CMixedNumber&);
	CMixedNumber Diff(CMixedNumber&);
	CMixedNumber Mult(CMixedNumber&);
	CMixedNumber Quote(CMixedNumber&);
	CMixedNumber operator+(const CMixedNumber&);
	CMixedNumber operator-(const CMixedNumber&);
	CMixedNumber operator*(const CMixedNumber&);
	CMixedNumber operator/(const CMixedNumber&);
	CMixedNumber& operator+=(const CMixedNumber&);
	CMixedNumber& operator-=(const CMixedNumber&);
	CMixedNumber& operator*=(const CMixedNumber&);
	CMixedNumber& operator/=(const CMixedNumber&);
	CMixedNumber& operator++();
	CMixedNumber& operator--();
	CMixedNumber& operator++(int);
	CMixedNumber& operator--(int);
	~CMixedNumber();
};

int main()
{
	cout << "Project 04 - 22521474 - Class CMixedNumber design." << endl;
	return 1;
}

int GCD(int a, int b)
{
	if (b == 0)
		return a;
	return GCD(b, a % b);
}

//Initialization methods
void CMixedNumber::Init()
{
	IntPart = 0;
	Numerator = 0;
	Denominator = 1;
}
void CMixedNumber::Init(int IntPt, int Nume, int Deno)
{
	IntPart = IntPt;
	Numerator = Nume;
	Denominator = Deno;
}
void CMixedNumber::Init(const CMixedNumber& mn)
{
	IntPart = mn.IntPart;
	Numerator = mn.Numerator;
	Denominator = mn.Denominator;
}

CMixedNumber::CMixedNumber()
{
	IntPart = 0;
	Numerator = 0;
	Denominator = 1;
}
CMixedNumber::CMixedNumber(int IntPt, int Nume, int Deno)
{
	IntPart = IntPt;
	Numerator = Nume;
	Denominator = Deno;
}
CMixedNumber::CMixedNumber(const CMixedNumber& mn)
{
	IntPart = mn.IntPart;
	Numerator = mn.Numerator;
	Denominator = mn.Denominator;
}

void CMixedNumber::Input()
{
	cout << "Enter the integer-part:				";
	cin >> IntPart;
	cout << "Enter the fraction-part's numerator:		";
	cin >> Numerator;
	cout << "Enter the fraction-part's denominator:		";
	cin >> Denominator;
}

istream& operator>>(istream& is, CMixedNumber& mn)
{
	cout << "Enter the integer-part:				";
	is >> mn.IntPart;
	cout << "Enter the fraction-part's numerator:		";
	is >> mn.Numerator;
	cout << "Enter the fraction-part's denominator:		";
	is >> mn.Denominator;
	return is;
}

//Information provider methods
void CMixedNumber::Output()
{
	if (Numerator < 0 && Denominator < 0)
	{
		Numerator = -Numerator;
		Denominator = -Denominator;
		cout << IntPart << " (" << Numerator << "/" << Denominator << ")";
	}
	else if (Numerator > 0 && Denominator < 0)
	{
		Numerator = -Numerator;
		Denominator = -Denominator;
		cout << -IntPart << " (" << Numerator << "/" << Denominator << ")";
	}
	else if (Numerator < 0 && Denominator > 0)
	{
		Numerator = -Numerator;
		Denominator = Denominator;
		cout << -IntPart << " (" << Numerator << "/" << Denominator << ")";
	}
	else if (Numerator > 0 && Denominator > 0)
	{
		cout << IntPart << " (" << Numerator << "/" << Denominator << ")";
	}
	else if (Numerator == 0)
	{
		cout << 0;
	}
}
ostream& operator<<(ostream& os, CMixedNumber& mn)
{
	CMixedNumber temp = mn;
	if (temp.Numerator < 0 && temp.Denominator < 0)
	{
		temp.Numerator = -temp.Numerator;
		temp.Denominator = -temp.Denominator;
		os << temp.IntPart << " (" << temp.Numerator << "/" << temp.Denominator << ")";
	}
	else if (temp.Numerator > 0 && temp.Denominator < 0)
	{
		temp.Numerator = -temp.Numerator;
		temp.Denominator = -temp.Denominator;
		os << -temp.IntPart << " (" << temp.Numerator << "/" << temp.Denominator << ")";
	}
	else if (temp.Numerator < 0 && temp.Denominator > 0)
	{
		temp.Numerator = -temp.Numerator;
		temp.Denominator = temp.Denominator;
		os << -temp.IntPart << " (" << temp.Numerator << "/" << temp.Denominator << ")";
	}
	else if (temp.Numerator > 0 && temp.Denominator > 0)
	{
		os << temp.IntPart << " (" << temp.Numerator << "/" << temp.Denominator << ")";
	}
	else if (temp.Numerator == 0)
	{
		os << 0;
	}
	return os;
}

int CMixedNumber::getIntPart()
{
	return IntPart;
}
int CMixedNumber::getNumerator()
{
	return Numerator;
}
int CMixedNumber::getDenominator()
{
	return Denominator;
}
double CMixedNumber::getResult()
{
	return IntPart + (double)Numerator / Denominator;
}

//Information update methods
void CMixedNumber::setIntPart(int IntPt)
{
	IntPart = IntPt;
}
void CMixedNumber::setNumerator(int Nume)
{
	Numerator = Nume;
}
void CMixedNumber::setDenominator(int Deno)
{
	Denominator = Deno;
}

CMixedNumber& CMixedNumber::operator=(const CMixedNumber& mn)
{
	IntPart = mn.IntPart;
	Numerator = mn.Numerator;
	Denominator = mn.Denominator;
	return *this;
}

//"Check-if" methods
bool CMixedNumber::isValid()
{
	if (Denominator != 0)
		return true;
	return false;
}

bool CMixedNumber::isIrreducible()
{
	if (Numerator > Denominator)
		return true;
	return false;
}

bool CMixedNumber::isZero()
{
	if (Numerator == 0 > Denominator != 0)
		return true;
	return false;
}

int CMixedNumber::PosOrNeg()
{
	if (IntPart + (double)Numerator / Denominator)
		return 1;
	return -1;
}

bool CMixedNumber::operator>(const CMixedNumber& mn)
{
	CMixedNumber ft1;
	ft1.Numerator = IntPart * Denominator + Numerator;
	ft1.Denominator = Denominator;
	CMixedNumber ft2;
	ft2.Numerator = mn.IntPart * mn.Denominator + mn.Numerator;
	ft2.Denominator = mn.Denominator;
	float r1 = (float)ft1.Numerator / ft1.Denominator;
	float r2 = (float)ft2.Numerator / ft2.Denominator;
	if (r1 > r2)
		return true;
	return false;
}

bool CMixedNumber::operator>=(const CMixedNumber& mn)
{
	CMixedNumber ft1;
	ft1.Numerator = IntPart * Denominator + Numerator;
	ft1.Denominator = Denominator;
	CMixedNumber ft2;
	ft2.Numerator = mn.IntPart * mn.Denominator + mn.Numerator;
	ft2.Denominator = mn.Denominator;
	float r1 = (float)ft1.Numerator / ft1.Denominator;
	float r2 = (float)ft2.Numerator / ft2.Denominator;
	if (r1 >= r2)
		return true;
	return false;
}

bool CMixedNumber::operator<(const CMixedNumber& mn)
{
	CMixedNumber ft1;
	ft1.Numerator = IntPart * Denominator + Numerator;
	ft1.Denominator = Denominator;
	CMixedNumber ft2;
	ft2.Numerator = mn.IntPart * mn.Denominator + mn.Numerator;
	ft2.Denominator = mn.Denominator;
	float r1 = (float)ft1.Numerator / ft1.Denominator;
	float r2 = (float)ft2.Numerator / ft2.Denominator;
	if (r1 < r2)
		return true;
	return false;
}

bool CMixedNumber::operator<=(const CMixedNumber& mn)
{
	CMixedNumber ft1;
	ft1.Numerator = IntPart * Denominator + Numerator;
	ft1.Denominator = Denominator;
	CMixedNumber ft2;
	ft2.Numerator = mn.IntPart * mn.Denominator + mn.Numerator;
	ft2.Denominator = mn.Denominator;
	float r1 = (float)ft1.Numerator / ft1.Denominator;
	float r2 = (float)ft2.Numerator / ft2.Denominator;
	if (r1 <= r2)
		return true;
	return false;
}

bool CMixedNumber::operator==(const CMixedNumber& mn)
{
	CMixedNumber ft1;
	ft1.Numerator = IntPart * Denominator + Numerator;
	ft1.Denominator = Denominator;
	CMixedNumber ft2;
	ft2.Numerator = mn.IntPart * mn.Denominator + mn.Numerator;
	ft2.Denominator = mn.Denominator;
	float r1 = (float)ft1.Numerator / ft1.Denominator;
	float r2 = (float)ft2.Numerator / ft2.Denominator;
	if (r1 == r2)
		return true;
	return false;
}

bool CMixedNumber::operator!=(const CMixedNumber& mn)
{
	CMixedNumber ft1;
	ft1.Numerator = IntPart * Denominator + Numerator;
	ft1.Denominator = Denominator;
	CMixedNumber ft2;
	ft2.Numerator = mn.IntPart * mn.Denominator + mn.Numerator;
	ft2.Denominator = mn.Denominator;
	float r1 = (float)ft1.Numerator / ft1.Denominator;
	float r2 = (float)ft2.Numerator / ft2.Denominator;
	if (r1 != r2)
		return true;
	return false;
}

//Processing methods
CMixedNumber CMixedNumber::Reduce()
{
	
	if (Numerator == 0) 
	{
		IntPart = 0;
		Denominator = 1;
		return *this;
	}
	int gcd = GCD(abs(Numerator), abs(Denominator));
	Numerator /= gcd;
	Denominator /= gcd;
	IntPart += Numerator / Denominator;
	Numerator = Numerator % Denominator;
	if (Denominator < 0) 
	{
		Numerator = -Numerator;
		Denominator = -Denominator;
	}
	return *this;
}

CMixedNumber CMixedNumber::Sum(CMixedNumber& mn)
{
	CMixedNumber s;
	s.IntPart = IntPart + mn.IntPart;
	s.Numerator = mn.Numerator * Denominator + Numerator * mn.Denominator;
	s.Denominator = mn.Denominator * Denominator;
	s.Reduce();
	return s;
}
CMixedNumber CMixedNumber::Diff(CMixedNumber& mn)
{
	CMixedNumber d;
	d.IntPart = IntPart - mn.IntPart;
	d.Numerator = mn.Numerator * Denominator - Numerator * mn.Denominator;
	d.Denominator = mn.Denominator * Denominator;
	d.Reduce();
	return d;
}
CMixedNumber CMixedNumber::Mult(CMixedNumber& mn)
{
	CMixedNumber m;
	m.IntPart = 0;
	m.Numerator = (IntPart * Denominator + Numerator) * (mn.IntPart * mn.Denominator + mn.Numerator);
	m.Denominator = mn.Denominator * Denominator;
	m.Reduce();
	return m;
}
CMixedNumber CMixedNumber::Quote(CMixedNumber& mn)
{
	CMixedNumber q;
	q.IntPart = 0;
	q.Numerator = (IntPart * Denominator + Numerator) * mn.Denominator;
	q.Denominator = Denominator * (mn.IntPart * mn.Denominator + mn.Numerator);
	q.Reduce();
	return q;
}

CMixedNumber CMixedNumber::operator+(const CMixedNumber& mn)
{
	CMixedNumber s;
	s.IntPart = IntPart + mn.IntPart;
	s.Numerator = mn.Numerator * Denominator + Numerator * mn.Denominator;
	s.Denominator = mn.Denominator * Denominator;
	s.Reduce();
	return s;
}
CMixedNumber CMixedNumber::operator-(const CMixedNumber& mn)
{
	CMixedNumber d;
	d.IntPart = IntPart - mn.IntPart;
	d.Numerator = mn.Numerator * Denominator - Numerator * mn.Denominator;
	d.Denominator = mn.Denominator * Denominator;
	d.Reduce();
	return d;
}
CMixedNumber CMixedNumber::operator*(const CMixedNumber& mn)
{
	CMixedNumber m;
	m.IntPart = 0;
	m.Numerator = (IntPart * Denominator + Numerator) * (mn.IntPart * mn.Denominator + mn.Numerator);
	m.Denominator = mn.Denominator * Denominator;
	m.Reduce();
	return m;
}
CMixedNumber CMixedNumber::operator/(const CMixedNumber& mn)
{
	CMixedNumber q;
	q.IntPart = 0;
	q.Numerator = (IntPart * Denominator + Numerator) * mn.Denominator;
	q.Denominator = Denominator * (mn.IntPart * mn.Denominator + mn.Numerator);
	q.Reduce();
	return q;
}

CMixedNumber& CMixedNumber::operator+=(const CMixedNumber& mn)
{
	CMixedNumber s;
	s.IntPart = IntPart + mn.IntPart;
	s.Numerator = mn.Numerator * Denominator + Numerator * mn.Denominator;
	s.Denominator = mn.Denominator * Denominator;
	s.Reduce();
	*this = s;
	return *this;
}
CMixedNumber& CMixedNumber::operator-=(const CMixedNumber& mn)
{
	CMixedNumber d;
	d.IntPart = IntPart - mn.IntPart;
	d.Numerator = mn.Numerator * Denominator - Numerator * mn.Denominator;
	d.Denominator = mn.Denominator * Denominator;
	d.Reduce();
	*this = d;
	return *this;
}
CMixedNumber& CMixedNumber::operator*=(const CMixedNumber& mn)
{
	CMixedNumber m;
	m.IntPart = 0;
	m.Numerator = (IntPart * Denominator + Numerator) * (mn.IntPart * mn.Denominator + mn.Numerator);
	m.Denominator = mn.Denominator * Denominator;
	m.Reduce();
	*this = m;
	return *this;
}
CMixedNumber& CMixedNumber::operator/=(const CMixedNumber& mn)
{
	CMixedNumber q;
	q.IntPart = 0;
	q.Numerator = (IntPart * Denominator + Numerator) * mn.Denominator;
	q.Denominator = Denominator * (mn.IntPart * mn.Denominator + mn.Numerator);
	q.Reduce();
	*this = q;
	return *this;
}

CMixedNumber& CMixedNumber::operator++()
{
	IntPart++;
	return *this;
}
CMixedNumber& CMixedNumber::operator--()
{
	IntPart--;
	return *this;
}
CMixedNumber& CMixedNumber::operator++(int)
{
	IntPart++;
	return *this;
}
CMixedNumber& CMixedNumber::operator--(int)
{
	IntPart--;
	return *this;
}

CMixedNumber::~CMixedNumber()
{
	return;
}