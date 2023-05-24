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
	friend ostream& operator<<(ostream&, C2DPoint&);
	void Output();
	float Distance(const C2DPoint&);
};
class CTriangle
{
private:
	C2DPoint A;
	C2DPoint B;
	C2DPoint C;
public:
	//Initialization methods
	void Init();
	void Init(C2DPoint, C2DPoint, C2DPoint);
	void Init(const CTriangle&);
	CTriangle();
	CTriangle(C2DPoint, C2DPoint, C2DPoint);
	CTriangle(const CTriangle&);
	void Input();
	friend istream& operator>>(istream&, CTriangle&);

	//Information provider methods
	void Output();
	friend ostream& operator<<(ostream&, CTriangle&);
	C2DPoint getA();
	float getAx();
	float getAy();
	C2DPoint getB();
	float getBx();
	float getBy();
	C2DPoint getC();
	float getCx();
	float getCy();

	//Information update methods
	CTriangle& operator=(CTriangle&);
	void setAx(float);
	void setAy(float);
	void setBx(float);
	void setBy(float);
	void setCx(float);
	void setCy(float);
	void setA(C2DPoint);
	void setA(float, float);
	void setB(C2DPoint);
	void setB(float, float);
	void setC(C2DPoint);
	void setC(float, float);	

	//"Check-if" methods
	bool isEquilateral();
	bool isIsosceles();
	bool isIsoRight();
	bool isRight();
	bool operator==(const CTriangle&);
	bool operator!=(const CTriangle&);
	bool operator<(const CTriangle&);
	bool operator>(const CTriangle&);
	bool operator<=(const CTriangle&);
	bool operator>=(const CTriangle&);

	//Processing methods
	float Area();
	float Circumference();
	C2DPoint MedPoint();
	C2DPoint Orthocenter();
	~CTriangle();
};

int main()
{
	cout << "Project 11 - 22521474 - Class CTriangle design." << endl;
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

float C2DPoint::Distance(const C2DPoint& P)
{
	return sqrt((x - P.x) * (x - P.x) + (y - P.y) * (y - P.y));
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

//Initialization methods
void CTriangle::Init()
{
	C2DPoint A{}, B{}, C{};
}
void CTriangle::Init(C2DPoint PA, C2DPoint PB, C2DPoint PC)
{
	C2DPoint A = PA;
	C2DPoint B = PB;
	C2DPoint C = PC;
}
void CTriangle::Init(const CTriangle& T)
{
	C2DPoint A = T.A;
	C2DPoint B = T.B;
	C2DPoint C = T.C;
}

CTriangle::CTriangle()
{
	A.Init();
	B.Init();
	C.Init();
}
CTriangle::CTriangle(C2DPoint PA, C2DPoint PB, C2DPoint PC)
{
	A = PA;
	B = PB;
	C = PC;
}
CTriangle::CTriangle(const CTriangle& T)
{
	A = T.A;
	B = T.B;
	C = T.C;
}

void CTriangle::Input()
{
	cout << "\nEnter three point of the triangle:" << endl;
	cout << "\nEnter first point's coordinate:";
	A.Input();
	cout << "\nEnter second point's coordinate:";
	B.Input();
	cout << "\nEnter third point's coordinate:";
	C.Input();
}

istream& operator>>(istream& is, CTriangle& T)
{
	cout << "\nEnter three point of the triangle:" << endl;
	cout << "\nEnter first point's coordinate:";
	is >> T.A;
	cout << "\nEnter second point's coordinate:";
	is >> T.B;
	cout << "\nEnter third point's coordinate:";
	is >> T.C;
	return is;
}

//Information provider methods
void CTriangle::Output()
{
	cout << A << "; " << B << "; " << C;
}

ostream& operator<<(ostream& os, CTriangle& T)
{
	os << T.A << "; " << T.B << "; " << T.C;
	return os;
}

C2DPoint CTriangle::getA()
{
	return A;
}
float CTriangle::getAx()
{
	return A.getX();
}
float CTriangle::getAy()
{
	return A.getY();
}
C2DPoint CTriangle::getB()
{
	return B;
}
float CTriangle::getBx()
{
	return B.getX();
}
float CTriangle::getBy()
{
	return B.getY();
}
C2DPoint CTriangle::getC()
{
	return C;
}
float CTriangle::getCx()
{
	return C.getX();
}
float CTriangle::getCy()
{
	return C.getY();
}
//Information update methods
void CTriangle::setAx(float PAx)
{
	A.setX(PAx);
}
void CTriangle::setBx(float PBx)
{
	B.setX(PBx);
}
void CTriangle::setCx(float PCx)
{
	C.setX(PCx);
}
void CTriangle::setAy(float PAy)
{
	A.setY(PAy);
}
void CTriangle::setBy(float PBy)
{
	B.setY(PBy);
}
void CTriangle::setCy(float PCy)
{
	C.setY(PCy);
}
void CTriangle::setA(C2DPoint PA)
{
	A = PA;
}
void CTriangle::setA(float PAx, float PAy)
{
	setAx(PAx);
	setAy(PAy);
}
void CTriangle::setB(C2DPoint PB)
{
	B = PB;
}
void CTriangle::setB(float PBx, float PBy)
{
	setBx(PBx);
	setBy(PBy);
}
void CTriangle::setC(C2DPoint PC)
{
	C = PC;
}
void CTriangle::setC(float PCx, float PCy)
{
	setCx(PCx);
	setCy(PCy);
}

CTriangle& CTriangle::operator=(CTriangle &T)
{
	A = T.A;
	B = T.B;
	C = T.C;
	return *this;
}

//"Check-if" methods
bool CTriangle::isEquilateral()
{
	float a = A.Distance(B);
	float b = A.Distance(C);
	float c = B.Distance(C);
	if ((a == b) && (b == c) && (a == c))
		return true;
	return false;
}
bool CTriangle::isIsosceles()
{
	float a = A.Distance(B);
	float b = A.Distance(C);
	float c = B.Distance(C);
	if ((isEquilateral() == false) && ((a == b) || (b == c) || (a == c)))
		return true;
	return false;
}
bool CTriangle::isRight()
{
	float a = A.Distance(B);
	float b = A.Distance(C);
	float c = B.Distance(C);
	if ((a * a + b * b == c * c) || (a * a + c * c == b * b) || (b * b + c * c == a * a))
		return true;
	return false;
}
bool CTriangle::isIsoRight()
{
	if ((isRight() == true) && (isIsosceles() == true))
		return true;
	return false;
}

bool CTriangle::operator==(const CTriangle& T)
{
	CTriangle temp = T;
	float s = Area() - temp.Area();
	if (s == 0)
		return true;
	return false;
}
bool CTriangle::operator!=(const CTriangle& T)
{
	CTriangle temp = T;
	float s = Area() - temp.Area();
	if (s != 0)
		return true;
	return false;
}
bool CTriangle::operator>(const CTriangle& T)
{
	CTriangle temp = T;
	float s = Area() - temp.Area();
	if (s > 0)
		return true;
	return false;
}
bool CTriangle::operator>=(const CTriangle& T)
{
	CTriangle temp = T;
	float s = Area() - temp.Area();
	if (s >= 0)
		return true;
	return false;
}
bool CTriangle::operator<(const CTriangle& T)
{
	CTriangle temp = T;
	float s = Area() - temp.Area();
	if (s < 0)
		return true;
	return false;
}
bool CTriangle::operator<=(const CTriangle& T)
{
	CTriangle temp = T;
	float s = Area() - temp.Area();
	if (s <= 0)
		return true;
	return false;
}

//Processing methods
float CTriangle::Area()
{
	float a = A.Distance(B);
	float b = A.Distance(C);
	float c = B.Distance(C);
	float p = (a + b + c) / 2;
	return sqrt(p * (p - a) * (p - b) * (p - c));
}

float CTriangle::Circumference()
{
	float a = A.Distance(B);
	float b = A.Distance(C);
	float c = B.Distance(C);
	return a + b + c;
}

C2DPoint CTriangle::MedPoint()
{
	C2DPoint G{};
	G.setX((A.getX() + B.getX() + C.getX()) / 3);
	G.setY((A.getY() + B.getY() + C.getY()) / 3);
	return G;
}

C2DPoint CTriangle::Orthocenter()
{
	C2DPoint H{};
	double d = 4 * (B.getX() - B.getX()) * (C.getY() - A.getY()) - 4 * (C.getX() - A.getX()) * (B.getY() - A.getY());
	double dx = (pow(B.getX(), 2) + pow(B.getY(), 2) - pow(A.getX(), 2) - pow(A.getY(), 2)) * 2 * (C.getY() - A.getY())
				- (pow(C.getX(), 2) + pow(C.getY(), 2) - pow(A.getX(), 2) - pow(A.getY(), 2)) * 2 * (B.getY() - A.getY());
	double dy = (pow(C.getX(), 2) + pow(C.getY(), 2) - pow(A.getX(), 2) - pow(A.getY(), 2)) * 2 * (B.getX() - A.getX())
				- (pow(B.getX(), 2) + pow(B.getY(), 2) - pow(A.getX(), 2) - pow(A.getY(), 2)) * 2 * (C.getX() - A.getX());
	H.setX(dx / d);
	H.setY(dy / d);
	return H;
}

CTriangle::~CTriangle()
{
	return;
}