#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

class C2DPoint
{
private:
	float x;
	float y;
public:
	void Init();
	void Input();
	friend istream& operator>>(istream&, C2DPoint&);
	void setX(float);
	void setY(float);
	float getX();
	float getY();
	void Output();
	friend ostream& operator<<(ostream&, C2DPoint&);
	float Distance(const C2DPoint&);

};
class CCircle
{
private:
	C2DPoint I;
	float R;
public:
	//Initialization methods
	void Init();
	void Init(C2DPoint, float);
	void Init(const CCircle&);
	CCircle();
	CCircle(C2DPoint, float);
	CCircle(const CCircle&);
	void Input();
	friend istream& operator>>(istream&, CCircle&);

	//Information provider methods
	void Output();
	friend ostream& operator<<(ostream&, CCircle&);
	C2DPoint getI();
	float getR();

	//Information update methods
	CCircle& operator=(const CCircle&);
	void setI(const C2DPoint&);
	void setR(float);

	//"Check-if" methods
	bool isCoincident(CCircle);
	bool isIntersected(CCircle);
	bool isIncircle(CCircle);
	bool isCircumcircle(CCircle);
	bool isInside(CCircle);
	bool isOutside(CCircle);
	bool isConcentric(CCircle);
	bool isUnit(CCircle);
	bool operator==(CCircle);
	bool operator!=(CCircle);
	bool operator>(CCircle);
	bool operator>=(CCircle);
	bool operator<(CCircle);
	bool operator<=(CCircle);

	//Processing methods
	float Circumference();
	float Area();	
	~CCircle();
};

int main()
{
	cout << "Project 10 - 22521474 - Class CCircle design." << endl;
	return 1;
}

void C2DPoint::Init()
{
	x = 0;
	y = 0;
}

void C2DPoint::Input()
{
	cout << "Enter point's x:	";
	cin >> x;
	cout << "Enter point's y:	";
	cin >> y;
}

istream& operator>>(istream& is, C2DPoint& P)
{
	cout << "Enter point's x:	";
	is >> P.x;
	cout << "Enter point's y:	";
	is >> P.y;
	return is;
}

float C2DPoint::getX()
{
	return x;
}
float C2DPoint::getY()
{
	return y;
}

void C2DPoint::setX(float px)
{
	x = px;
}
void C2DPoint::setY(float py)
{
	y = py;
}

void C2DPoint::Output()
{
	cout << "(" << x << ", " << y << ")";
}

ostream& operator<<(ostream& os, C2DPoint& P)
{
	os << "(" << P.x << ", " << P.y << ")";
	return os;
}

float C2DPoint::Distance(const C2DPoint& P)
{
	return sqrt((x - P.x) * (x - P.x) + (y - P.y) * (y - P.y));
}

//Initialization methods
void CCircle::Init()
{
	I.Init();
	R = 0;
}
void CCircle::Init(C2DPoint O, float radius)
{
	I = O;
	R = radius;
}
void CCircle::Init(const CCircle& C)
{
	I = C.I;
	R = C.R;
}

CCircle::CCircle()
{
	I.Init();
	R = 0;
}
CCircle::CCircle(C2DPoint O, float radius)
{
	I = O;
	R = radius;
}
CCircle::CCircle(const CCircle& C)
{
	I = C.I;
	R = C.R;
}

void CCircle::Input()
{
	cout << "Enter the centerpoint's coordinate:";
	I.Input();
	cout << "Enter the circle's radius:		";
	cin >> R;
}

istream& operator>>(istream& is, CCircle& C)
{
	cout << "Enter the centerpoint's coordinate:";
	is >> C.I;
	cout << "Enter the circle's radius:		";
	is >> C.R;
	return is;
}

//Information provider methods
void CCircle::Output()
{
	cout << "\nThe circle centerpoint's coordinate is:	";
	I.Output();
	cout << "\nThe circle's radius is:		" << R;
}

ostream& operator<<(ostream& os, CCircle& C)
{
	cout << "\nThe circle centerpoint's coordinate is:	";
	os << C.I;
	cout << "\nThe circle's radius is:		";
	os << C.R;
	return os;
}

C2DPoint CCircle::getI()
{
	return I;
}
float CCircle::getR()
{
	return R;
}

//Information update methods
CCircle& CCircle::operator=(const CCircle& c)
{
	*this = c;
	return *this;
}

void CCircle::setI(const C2DPoint& O)
{
	I = O;
}
void CCircle::setR(float radius)
{
	R = radius;
}

//"Check-if" methods
bool CCircle::isCoincident(CCircle C)
{
	return(*this == C);
}
bool CCircle::isIntersected(CCircle C)
{
	float d = I.Distance(C.I);
	return(((R - C.R) < d) && (d < (R + C.R)));
}
bool CCircle::isIncircle(CCircle C)
{
	float d = I.Distance(C.I);
	return(abs(R - C.R) == d);
}
bool CCircle::isCircumcircle(CCircle C)
{
	float d = I.Distance(C.I);
	return((R + C.R) == d);
}
bool CCircle::isInside(CCircle C)
{
	float d = I.Distance(C.I);
	return(abs(R - C.R) < d);
}
bool CCircle::isOutside(CCircle C)
{
	float d = I.Distance(C.I);
	return((R + C.R) < d);
}
bool CCircle::isConcentric(CCircle C)
{
	return (R == C.R);
}
bool CCircle::isUnit(CCircle C)
{
	C2DPoint O{};
	O.Init();
	CCircle temp(O, 1);
	return (temp == C);
}

bool CCircle::operator==(CCircle C)
{
	if ((C.I.getX() == I.getX()) && (C.I.getY() == I.getY()) && C.R == R)
	{
		C.R = R;
		return true;
	}
	return false;
}
bool CCircle::operator!=(CCircle C)
{
	if (!((C.I.getX() == I.getX()) && (C.I.getY() == I.getY()) && (C.R == R)))
	{
		C.R = R;
		return true;
	}
	return false;
}
bool CCircle::operator>(CCircle C)
{
	if (R > C.R)
		return true;
	return false;
}
bool CCircle::operator>=(CCircle C)
{
	if (R >= C.R)
		return true;
	return false;
}
bool CCircle::operator<(CCircle C)
{
	if (R < C.R)
		return true;
	return false;
}
bool CCircle::operator<=(CCircle C)
{
	if (R <= C.R)
		return true;
	return false;
}

//Processing methods
float CCircle::Circumference()
{
	return (float)M_PI * 2 * R;
}
float CCircle::Area()
{
	return (float)M_PI * pow(R, 2);
}

CCircle::~CCircle()
{
	return;
}