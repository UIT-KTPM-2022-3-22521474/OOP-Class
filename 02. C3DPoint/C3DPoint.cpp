#include <iostream>
#include <cmath>
using namespace std;

class C3DPoint
{
private:
	float x;
	float y;
	float z;
public:
	//Initialization methods
	void Init();
	void Init(float, float, float);
	void Init(const C3DPoint&);
	C3DPoint();
	C3DPoint(float, float, float);
	C3DPoint(const C3DPoint&);
	void Input();
	friend istream& operator>>(istream&, C3DPoint&);

	//Information provider methods
	void Output();
	friend ostream& operator<<(ostream&, C3DPoint&);
	float getX();
	float getY();
	float getZ();

	//Information updater methods
	C3DPoint& operator=(const C3DPoint&);
	void setX(float);
	void setY(float);
	void setZ(float);

	//"Check-if" methods
	bool ChkOriOverlap();
	bool ChkOverlap(const C3DPoint&);
	bool ChkNonOverlap(const C3DPoint&);
	bool ChkXAxis();
	bool ChkYAxis();
	bool ChkZAxis();
	bool ChkOxy();
	bool ChkOxz();
	bool ChkOyz();
	bool operator==(C3DPoint&);
	bool operator!=(C3DPoint&);
	bool operator>(C3DPoint&);
	bool operator>=(C3DPoint&);
	bool operator<(C3DPoint&);
	bool operator<=(C3DPoint&);

	//Processing methods
	float OriDist();
	float Distance(const C3DPoint&);
	float DistanceX(const C3DPoint&);
	float DistanceY(const C3DPoint&);
	float DistanceZ(const C3DPoint&);
	C3DPoint OriSym();
	C3DPoint XSym();
	C3DPoint YSym();
	C3DPoint ZSym();
	C3DPoint OxySym();
	C3DPoint OxzSym();
	C3DPoint OyzSym();
	~C3DPoint();
};

int main()
{
	cout << "Project 02 - 22521474 - Class C3DPoint design." << endl;
	return 1;
}

//Initialization methods
void C3DPoint::Init()
{
	x = 0;
	y = 0;
	z = 0;
}
void C3DPoint::Init(float px, float py, float pz)
{
	x = px;
	y = py;
	z = pz;
}
void C3DPoint::Init(const C3DPoint& p)
{
	x = p.x;
	y = p.y;
	z = p.z;
}

C3DPoint::C3DPoint()
{
	x = 0;
	y = 0;
	z = 0;
}
C3DPoint::C3DPoint(float px, float py, float pz)
{
	x = px;
	y = py;
	z = pz;
}
C3DPoint::C3DPoint(const C3DPoint& p)
{
	x = p.x;
	y = p.y;
	z = p.z;
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

//Information provider methods
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

//Information updater methods
C3DPoint& C3DPoint::operator=(const C3DPoint& P)
{
	x = P.x;
	y = P.y;
	z = P.z;
	return *this;
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

//"Check-if" methods
bool C3DPoint::ChkOriOverlap()
{
	if (x == 0 && y == 0)
		return true;
	return false;
}
bool C3DPoint::ChkOverlap(const C3DPoint& P)
{
	if (x == P.x && y == P.y && z == P.z)
		return true;
	return false;
}
bool C3DPoint::ChkNonOverlap(const C3DPoint& P)
{
	if (!(x == P.x && y == P.y && z == P.z))
		return true;
	return false;
}

bool C3DPoint::ChkXAxis()
{
	if (y == 0 && z == 0)
		return true;
	return false;
}
bool C3DPoint::ChkYAxis()
{
	if (x == 0 && z == 0)
		return true;
	return false;
}
bool C3DPoint::ChkZAxis()
{
	if (x == 0 && y == 0)
		return true;
	return false;
}

bool C3DPoint::ChkOxy()
{
	if (z == 0)
		return true;
	return false;
}
bool C3DPoint::ChkOxz()
{
	if (y == 0)
		return true;
	return false;
}
bool C3DPoint::ChkOyz()
{
	if (x == 0)
		return true;
	return false;
}

bool C3DPoint::operator==(C3DPoint& P)
{
	if (OriDist() == P.OriDist())
		return true;
	return false;
}

bool C3DPoint::operator!=(C3DPoint& P)
{
	if (OriDist() != P.OriDist())
		return true;
	return false;
}

bool C3DPoint::operator>(C3DPoint& P)
{
	if (OriDist() > P.OriDist())
		return true;
	return false;
}

bool C3DPoint::operator>=(C3DPoint& P)
{
	if (OriDist() >= P.OriDist())
		return true;
	return false;
}

bool C3DPoint::operator<(C3DPoint& P)
{
	if (OriDist() < P.OriDist())
		return true;
	return false;
}

bool C3DPoint::operator<=(C3DPoint& P)
{
	if (OriDist() <= P.OriDist())
		return true;
	return false;
}

//Processing methods
float C3DPoint::OriDist()
{
	return sqrt(x * x + y * y + z * z);
}

float C3DPoint::Distance(const C3DPoint& P)
{
	return sqrt((x - P.x) * (x - P.x) + (y - P.y) * (y - P.y) + (z - P.z) * (z - P.z));
}
float C3DPoint::DistanceX(const C3DPoint& P)
{
	return abs(x - P.x);
}
float C3DPoint::DistanceY(const C3DPoint& P)
{
	return abs(y - P.y);
}
float C3DPoint::DistanceZ(const C3DPoint& P)
{
	return abs(z - P.z);
}
C3DPoint C3DPoint::OriSym()
{
	C3DPoint temp;
	temp.x = -x;
	temp.y = -y;
	temp.z = -z;
	if (x == 0)
		temp.x = 0;
	if (y == 0)
		temp.y = 0;
	if (z == 0)
		temp.z = 0;
	return temp;
}

C3DPoint C3DPoint::XSym()
{
	C3DPoint temp;
	temp.x = x;
	temp.y = -y;
	temp.z = -z;
	if (x == 0)
		temp.x = 0;
	if (y == 0)
		temp.y = 0;
	if (z == 0)
		temp.z = 0;
	return temp;
}
C3DPoint C3DPoint::YSym()
{
	C3DPoint temp;
	temp.x = -x;
	temp.y = y;
	temp.z = -z;
	if (x == 0)
		temp.x = 0;
	if (y == 0)
		temp.y = 0;
	if (z == 0)
		temp.z = 0;
	return temp;
}
C3DPoint C3DPoint::ZSym()
{
	C3DPoint temp;
	temp.x = -x;
	temp.y = -y;
	temp.z = z;
	if (x == 0)
		temp.x = 0;
	if (y == 0)
		temp.y = 0;
	if (z == 0)
		temp.z = 0;
	return temp;
}

C3DPoint C3DPoint::OxySym()
{
	C3DPoint temp;
	temp.x = x;
	temp.y = y;
	temp.z = -z;
	if (x == 0)
		temp.x = 0;
	if (y == 0)
		temp.y = 0;
	if (z == 0)
		temp.z = 0;
	return temp;
}
C3DPoint C3DPoint::OxzSym()
{
	C3DPoint temp;
	temp.x = x;
	temp.y = -y;
	temp.z = z;
	if (x == 0)
		temp.x = 0;
	if (y == 0)
		temp.y = 0;
	if (z == 0)
		temp.z = 0;
	return temp;
}
C3DPoint C3DPoint::OyzSym()
{
	C3DPoint temp;
	temp.x = -x;
	temp.y = y;
	temp.z = z;
	if (x == 0)
		temp.x = 0;
	if (y == 0)
		temp.y = 0;
	if (z == 0)
		temp.z = 0;
	return temp;
}

C3DPoint::~C3DPoint()
{
	return;
}