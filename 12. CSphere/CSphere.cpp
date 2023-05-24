#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

class C3DPoint
{
private:
	float x;
	float y;
	float z;
public:
	void Init();
	void Input();
	friend istream& operator>>(istream&, C3DPoint&);
	void setX(float);
	void setY(float);
	void setZ(float);
	float getX();
	float getY();
	float getZ();
	float Distance(const C3DPoint&);
	void Output();
	friend ostream& operator<<(ostream&, C3DPoint&);
};
class CSphere
{
private:
	C3DPoint I;
	float R;
public:
	//Initialization methods
	void Init();
	void Init(C3DPoint, float);
	void Init(const CSphere&);
	CSphere();
	CSphere(C3DPoint, float);
	CSphere(const CSphere&);
	void Input();
	friend istream& operator>>(istream&, CSphere&);

	//Information provider methods
	void Output();
	friend ostream& operator<<(ostream&, CSphere&);
	C3DPoint getI();
	float getR();
	
	//Information update methods
	CSphere& operator=(const CSphere&);
	void setI(C3DPoint);
	void setR(float);

	//"Check-if" methods
	bool isCoincident(CSphere);
	bool isIncircle(CSphere);
	bool isCircumcircle(CSphere);
	bool isInside(CSphere);
	bool isOutside(CSphere);
	bool isIntersected(CSphere);
	bool isInside(C3DPoint);
	bool isOutside(C3DPoint);
	bool isBelong(CSphere);
	bool operator==(CSphere);
	bool operator!=(CSphere);
	bool operator>(CSphere);
	bool operator>=(CSphere);
	bool operator<(CSphere);
	bool operator<=(CSphere);

	//Processing methods
	float Area();
	float Volume();
	~CSphere();
};

int main()
{
	cout << "Project 12 - 22521474 - Class CSphere design." << endl;
	return 1;
}

void C3DPoint::Init()
{
	x = 0;
	y = 0;
	z = 0;
}

void C3DPoint::Input()
{
	cout << "Enter point's x:	";
	cin >> x;
	cout << "Enter point's y:	";
	cin >> y;
	cout << "Enter point's z:	";
	cin >> z;
}

istream& operator>>(istream& is, C3DPoint& P)
{
	cout << "Enter point's x:	";
	is >> P.x;
	cout << "Enter point's y:	";
	is >> P.y;
	cout << "Enter point's z:	";
	cin >> P.z;
	return is;
}

void C3DPoint::Output()
{
	cout << "(" << x << ", " << y << ", " << z << ")";
}

ostream& operator<<(ostream& os, C3DPoint& P)
{
	os << "(" << P.x << ", " << P.y << ", " << P.z << ")";
	return os;
}

float C3DPoint::getX()
{
	return x;
}
float C3DPoint::getY()
{
	return y;
}
float C3DPoint::getZ()
{
	return z;
}

void C3DPoint::setX(float px)
{
	x = px;
}
void C3DPoint::setY(float py)
{
	y = py;
}
void C3DPoint::setZ(float pz)
{
	z = pz;
}
float C3DPoint::Distance(const C3DPoint& P)
{
	return sqrt((x - P.x) * (x - P.x) + (y - P.y) * (y - P.y) + (z - P.z) * (z - P.z));
}

//Initialization methods
void CSphere::Init()
{
	I.Init();
	R = 0;
}
void CSphere::Init(C3DPoint O, float radius)
{
	I = O;
	R = radius;
}
void CSphere::Init(const CSphere& S)
{
	I = S.I;
	R = S.R;
}

CSphere::CSphere()
{
	I.Init();
	R = 0;
}
CSphere::CSphere(C3DPoint O, float radius)
{
	I = O;
	R = radius;
}
CSphere::CSphere(const CSphere& S)
{
	I = S.I;
	R = S.R;
}

void CSphere::Input()
{
	cout << "Enter the centerpoint's coordinate:";
	I.Input();
	cout << "Enter the centerpoint's radius:	";
	cin >> R;
}

istream& operator>>(istream& is, CSphere& S)
{
	cout << "Enter the centerpoint's coordinate:";
	is >> S.I;
	cout << "Enter the centerpoint's radius:	";
	is >> S.R;
	return is;
}

//Information provider methods
void CSphere::Output()
{
	cout << "The circle centerpoint's coordinate:";
	I.Output();
	cout << "The circle's radius:" << R;
}

ostream& operator>>(ostream& os, CSphere& S)
{
	cout << "The circle centerpoint's coordinate:";
	os << S.I;
	cout << "The circle's radius:";
	os << S.R;
	return os;
}