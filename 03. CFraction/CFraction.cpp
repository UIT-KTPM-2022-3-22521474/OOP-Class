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
	CFraction A;
	A.Init();
	CFraction B(0);
	B.Init(0);
	CFraction C(0, 1);
	C.Init(0, 1);
	CFraction D(A);
	D.Init(A);
	cout << "\nEnter the first fraction:" << endl;
	A.Input();
	while (A.isValid() == false)
	{
		cout << "\nThe inputted fraction is invalid. Please try again." << endl;
		A.Input();
	}	
	cout << "\nEnter the second fraction:" << endl;
	cin >> B;
	while (B.isValid() == false)
	{
		cout << "\nThe inputted fraction is invalid. Please try again." << endl;
		B.Input();
	}
	cout << "\nThe first inputted fraction is:								";
	A.Output();
	cout << ".\nThe second inputted fraction is:							";
	cout << B << endl;
	cout << "\nAfter assign the first fraction's value to the third ones, its value is:		";
	C = A;
	cout << C;
	cout << "\nAfter assign the second fraction's value to the fourth ones, its value is:		";
	D = B;
	cout << D << endl;
	if (A.isIrreducible() == true)
		cout << "\nThe first inputted fraction is irreducible." << endl;
	if (A.isZero()==true)
		cout << "\nThe first inputted fraction's value is zero." << endl;
	else
	{
		if (A.isNeg() == true)
			cout << "\nThe first inputted fraction is negative." << endl;
		if (A.isPos() == true)
			cout << "\nThe first inputted fraction is positive." << endl;
	}
	if (A >= B)
	{
		cout << "\nThe first inputted fraction has the bigger or equal value with the second ones.";
		if (A == B)
			cout << "\nThe first inputted fraction has equal value with the second ones." << endl;
		else
		{
			if (A != B)
				cout << "\nThe first inputted fraction doesn't have equal value with the second ones.";
			if (A > B)
				cout << "\nThe first inputted fraction has the bigger value with the second ones." << endl;
		}
	}
	if (A <= B)
	{
		cout << "\nThe first inputted fraction has the smaller or equal value with the second ones.";
		if (A == B)
			cout << "\nThe first inputted fraction has equal value with the second ones." << endl;
		else
		{
			if (A != B)
				cout << "\nThe first inputted fraction doesn't have equal value with the second ones.";
			if (A < B)
				cout << "\nThe first inputted fraction has the smaller value with the second ones." << endl;
		}
	}
	CFraction S1 = A.Sum(B);
	cout << "\nThe addition of the first inputted fraction and the second ones is:			" << S1 << ".";
	CFraction S2 = B + A;
	cout << "\nThe addition of the second inputted fraction and the second ones is:			" << S2 << "." << endl;
	CFraction D1 = A.Diff(B);
	cout << "\nThe subtraction of the first inputted fraction and the second ones is:			" << D1 << ".";
	CFraction D2 = B - A;
	cout << "\nThe subtraction of the second inputted fraction and the second ones is:			" << D2 << "." << endl;
	CFraction M1 = A.Mult(B);
	cout << "\nThe multiplication of the first inputted fraction and the second ones is:		" << M1 << ".";
	CFraction M2 = B * A;
	cout << "\nThe multiplication of the second inputted fraction and the first ones is:		" << M2 << "." << endl;
	CFraction Q1 = A.Quote(B);
	cout << "\nThe division of the first inputted fraction and the second ones is:			" << Q1 << ".";
	CFraction Q2 = B / A;
	cout << "\nThe division of the second inputted fraction and the first ones is:			" << Q2 << "." << endl;
	cout << "\nAfter adding one into the third fraction, its value is:					" << C++ << "." << endl;
	cout << "\nAfter minus one to the fourth inputted fraction, its value is:				" << D-- << "." << endl;
	cout << "\nAdd second inputted fraction into the third ones, its value becomes:			"; 
	C += B;
	C.Output();
	cout << ".\nSubtract first inputted fraction from the fourth one, its value becomes:		";
	D -= A;
	D.Output();
	cout << ".\nGet the sum between the first and the second fraction, multiply with its difference";
	cout << "\nand then assign the result to the variable which hold the sum, its value becomes :	";
	M1 *= D1;
	M1.Output();
	cout << ".\nGet the sum between the second and the first fraction, divide with its difference";
	cout <<"\nand then assign the result to the variable which hold the sum, its value becomes :	"; 
	M2 /= D2;
	M2.Output();
	cout << "." << endl;
	int n;
	cout << "\nEnter the exponent which you want to power the first inputted fraction:	";
	cin >> n;
	CFraction APN = A ^ n;
	cout << "The exponentation of the first inputted fraction (" << A << ") with " << n << " is :			" << APN << "." << endl;
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
	CFraction s;
	s.Numerator = ft.Numerator * Denominator - Numerator * ft.Denominator;
	s.Denominator = ft.Denominator * Denominator;
	return s;
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