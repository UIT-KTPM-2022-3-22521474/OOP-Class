#include <iostream>
#include <cmath>
using namespace std;

class C2DPoint
{
private:
	float x;
	float y;
public:
	void Input();
	void setX(float);
	void setY(float);
	float getX();
	float getY();
	void Output();
};

class C2DLine
{
private:
	float a;
	float b;
	float c;
public:
	//Initialization methods
	void Init();
	void Init(float, float, float);
	void Init(const C2DLine&);
	C2DLine();
	C2DLine(float, float, float);
	C2DLine(const C2DLine&);
	void Input();
	friend istream& operator>>(istream&, C2DLine&);

	//Information provider methods
	void Output();
	friend ostream& operator<<(ostream&, C2DLine&);
	float getA();
	float getB();
	float getC();

	//Information update methods
	void setA(float);
	void setB(float);
	void setC(float);

	//"Check-if" methods
	bool isLinear(C2DPoint);
	bool isCoincident(C2DLine);
	bool isParallel(C2DLine);
	bool isIntersected(C2DLine);
	bool isPerpendicular(C2DLine);
	bool operator==(const C2DLine&);
	bool operator!=(const C2DLine&);

	//Processing methods
	float PointDist(C2DPoint);
	float LineDist(C2DLine);
	C2DPoint Intersect(C2DLine);
	~C2DLine();
};

int main()
{
	cout << "Project 09 - 22521474 - Class C2DLine design." << endl;
	return 1;
}

void C2DPoint::Input()
{
	cout << "Enter point's x:	";
	cin >> x;
	cout << "Enter point's y:	";
	cin >> y;
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

//Initialization methods
void C2DLine::Init()
{
	a = 0;
	b = 0;
	c = 0;
}
void C2DLine::Init(float la, float lb, float lc)
{
	a = la;
	b = lb;
	c = lc;
}
void C2DLine::Init(const C2DLine& l)
{
	a = l.a;
	b = l.b;
	c = l.c;
}

C2DLine::C2DLine()
{
	a = 0;
	b = 0;
	c = 0;
}
C2DLine::C2DLine(float la, float lb, float lc)
{
	a = la;
	b = lb;
	c = lc;
}
C2DLine::C2DLine(const C2DLine& l)
{
	a = l.a;
	b = l.b;
	c = l.c;
}

void C2DLine::Input()
{
	cout << "The line equation's type is: ax + by + c = 0." << endl;
	cout << "Enter a:	";
	cin >> a;
	cout << "Enter b:	";
	cin >> b;
	cout << "Enter c:	";
	cin >> c;
}

istream& operator>>(istream& is, C2DLine& l)
{
	cout << "The line equation's type is: ax + by + c = 0." << endl;
	cout << "Enter a:	";
	is >> l.a;
	cout << "Enter b:	";
	is >> l.b;
	cout << "Enter c:	";
	is >> l.c;
	return is;
}

//Information provider methods
void C2DLine::Output()
{
	cout << a << "x + " << b << "y + " << c << " = 0" << endl;
}

ostream& operator<<(ostream& os, C2DLine& l)
{
	os << l.a << "x + " << l.b << "y + " << l.c << " = 0";
	return os;
}

float C2DLine::getA()
{
	return a;
}
float C2DLine::getB()
{
	return b;
}
float C2DLine::getC()
{
	return c;
}

//Information update methods
void C2DLine::setA(float la)
{
	a = la;
}
void C2DLine::setB(float lb)
{
	b = lb;
}
void C2DLine::setC(float lc)
{
	c = lc;
}

//"Check-if" methods
bool C2DLine::isLinear(C2DPoint p)
{
	if ((a * p.getX() + b * p.getY() + c) == 0)
		return true;
	return false;
}
bool C2DLine::isCoincident(C2DLine l)
{
	if ((a == l.a) && (b == l.b) && (c == l.c))
		return true;
	return false;
}
bool C2DLine::isParallel(C2DLine l)
{
	if ((a == l.a) && (b == l.b) && (c != l.c))
		return true;
	return false;
}
bool C2DLine::isIntersected(C2DLine l)
{
	float L = a * l.b - l.a * b;
	if (L != 0)
		return true;
	return false;
}
bool C2DLine::isPerpendicular(C2DLine l)
{
	if ((a * l.a + b * l.b) == 0)
		return true;
	return false;
}

bool C2DLine::operator==(const C2DLine& l)
{
	if ((a == l.a) && (b == l.b) && (c == l.c))
		return true;
	return false;
}
bool C2DLine::operator!=(const C2DLine& l)
{
	if (!((a == l.a) && (b == l.b) && (c == l.c)))
		return true;
	return false;
}

//Processing methods
float C2DLine::PointDist(C2DPoint p)
{
	float dnume = abs(a * p.getX() + b * p.getY() + c);
	float ddeno = sqrt(a * a + b * b);
	return (dnume / ddeno);
}

float C2DLine::LineDist(C2DLine l)
{
	float d = 0;
	if (isParallel(l) == true)
	{
		C2DPoint p{};
		p.Input();
		if (isLinear(p) == true)
			d = l.PointDist(p);
	}
	return d;
}

C2DPoint C2DLine::Intersect(C2DLine l)
{
	if (isIntersected(l) == false)
		return;
	C2DPoint I;
	float xCoef = (-a / b) - (-l.a / l.b);
	float cFree = (-c / b) - (-l.c / l.b);
	I.setX(-cFree/xCoef);
	I.setY((-xCoef / b) * I.getX() - (-cFree / b));
	return I;
}

C2DLine::~C2DLine()
{
	return;
}