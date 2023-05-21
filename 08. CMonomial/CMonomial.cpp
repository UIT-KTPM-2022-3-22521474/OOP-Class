#include <iostream>
using namespace std;

class CMonomial
{
private:
	float Coefficient;
	int Exponent;
public:
	//Initialization methods
	void Init();
	void Init(float, int);
	void Init(const CMonomial&);
	CMonomial();
	CMonomial(float, int);
	CMonomial(const CMonomial&);
	void Input();
	friend istream& operator>>(istream&, CMonomial&);

	//Information provider methods
	void Output();
	friend ostream& operator<<(ostream&, CMonomial&);
	float getCoef();
	int getExpo();

	//Information update methods
	void setCoef(float);
	void setExpo(int);	
	CMonomial& operator=(const CMonomial&);

	//"Check-if" methods
	bool isZero();
	int ExpoCompare(const CMonomial&);
	bool operator>(const CMonomial&);
	bool operator>=(const CMonomial&);
	bool operator<(const CMonomial&);
	bool operator<=(const CMonomial&);
	bool operator==(const CMonomial&);
	bool operator!=(const CMonomial&);

	//Processing methods
	CMonomial Multi(const CMonomial&);
	CMonomial Quote(const CMonomial&);
	CMonomial& Derivative();
	CMonomial operator*(const CMonomial&);
	CMonomial operator/(const CMonomial&);
	CMonomial& operator*=(const CMonomial&);
	CMonomial& operator/=(const CMonomial&);
	~CMonomial();
};

int main()
{
	cout << "Project 08 - 22521474 - Class CMonomial design." << endl;
	return 1;
}

//Initialization methods
void CMonomial::Init()
{
	Coefficient = 0;
	Exponent = 0;
}
void CMonomial::Init(float Coef, int Expo)
{
	Coefficient = 0;
	Exponent = 0;
}
void CMonomial::Init(const CMonomial& mn)
{
	Coefficient = mn.Coefficient;
	Exponent = mn.Exponent;
}

CMonomial::CMonomial()
{
	Coefficient = 0;
	Exponent = 0;
}
CMonomial::CMonomial(float Coef, int Expo)
{
	Coefficient = Coef;
	Exponent = Expo;
}
CMonomial::CMonomial(const CMonomial& mn)
{
	Coefficient = mn.Coefficient;
	Exponent = mn.Exponent;
}

void CMonomial::Input()
{
	cout << "Enter the coefficient:		";
	cin >> Coefficient;
	cout << "Enter the exponent:		";
	cin >> Exponent;
}
istream& operator>>(istream& is, CMonomial& mn)
{
	cout << "Enter the coefficient:		";
	is >> mn.Coefficient;
	cout << "Enter the exponent:		";
	is >> mn.Exponent;
	return is;
}

//Information provider methods
void CMonomial::Output()
{
	if (Exponent == 0 || Coefficient == 0)
		cout << Coefficient;
	else
	{
		if (Coefficient == -1)
			cout << " - ";
		else if (Coefficient != 1)
			cout << Coefficient;
		if (Exponent == 1)
			cout << 'x';
		else
			cout << "x^" << Exponent;
	}
}
ostream& operator<<(ostream& os, CMonomial& mn)
{
	if (mn.Exponent == 0 || mn.Coefficient == 0)
		os << mn.Coefficient;
	else
	{
		if (mn.Coefficient == -1)
			os << "-";
		else if (mn.Coefficient != 1)
			os << mn.Coefficient;
		if (mn.Exponent == 1)
			os << "x";
		else
			os << "x^" << mn.Exponent;
	}
	return os;
}

void CMonomial::setCoef(float Coef)
{
	Coefficient = Coef;
}

void CMonomial::setExpo(int Expo)
{
	Exponent = Expo;
}
//Information update methods
float CMonomial::getCoef()
{
	return Coefficient;
}
int CMonomial::getExpo()
{
	return Exponent;
}

CMonomial& CMonomial::operator=(const CMonomial& mn)
{
	Coefficient = mn.Coefficient;
	Exponent = mn.Exponent;
	return *this;
}

//"Check-if" methods
bool CMonomial::isZero()
{
	if (Coefficient == 0)
		return true;
	return false;
}

int CMonomial::ExpoCompare(const CMonomial& mn)
{
	if (Exponent > mn.Exponent)
		return 1;
	if (Exponent < mn.Exponent)
		return -1;
	return 0;
}
bool CMonomial::operator==(const CMonomial& mn)
{
	if ((Exponent = mn.Exponent) && (Coefficient == mn.Coefficient))
		return true;
	return false;
}
bool CMonomial::operator!=(const CMonomial& mn)
{
	if (!((Exponent = mn.Exponent) && (Coefficient == mn.Coefficient)))
		return true;
	return false;
}

bool CMonomial::operator>(const CMonomial& mn)
{
	if (Exponent > mn.Exponent)
		return true;
	if ((Exponent == mn.Exponent) && (Coefficient > mn.Coefficient))
		return true;
	return false;
}
bool CMonomial::operator<(const CMonomial& mn)
{
	if (Exponent < mn.Exponent)
		return true;
	if ((Exponent == mn.Exponent) && (Coefficient < mn.Coefficient))
		return true;
	return false;
}

bool CMonomial::operator>=(const CMonomial& mn)
{
	if (!((*this) < mn))
		return true;
	return false;
}
bool CMonomial::operator<=(const CMonomial& mn)
{
	if (!((*this) > mn))
		return true;
	return false;
}

//Processing methods
CMonomial CMonomial::Multi(const CMonomial& mn)
{
	CMonomial m;
	m.Coefficient = Coefficient * mn.Coefficient;
	m.Exponent = Exponent + mn.Exponent;
	return m;
}
CMonomial CMonomial::Quote(const CMonomial& mn)
{
	CMonomial q;
	q.Coefficient = Coefficient / mn.Coefficient;
	q.Exponent = Exponent - mn.Exponent;
	return q;
}

CMonomial& CMonomial::Derivative()
{
	Coefficient = Coefficient * Exponent;
	Exponent--;
	return *this;
}

CMonomial CMonomial::operator*(const CMonomial& mn)
{
	CMonomial m;
	m.Coefficient = Coefficient * mn.Coefficient;
	m.Exponent = Exponent + mn.Exponent;
	return m;
}
CMonomial CMonomial::operator/(const CMonomial& mn)
{
	CMonomial q;
	q.Coefficient = Coefficient / mn.Coefficient;
	q.Exponent = Exponent - mn.Exponent;
	return q;
}

CMonomial& CMonomial::operator*=(const CMonomial& mn)
{
	Coefficient = Coefficient * mn.Coefficient;
	Exponent = Exponent + mn.Exponent;
	return *this;
}
CMonomial& CMonomial::operator/=(const CMonomial& mn)
{
	Coefficient = Coefficient / mn.Coefficient;
	Exponent = Exponent - mn.Exponent;
	return *this;
}

CMonomial::~CMonomial()
{
	return;
}