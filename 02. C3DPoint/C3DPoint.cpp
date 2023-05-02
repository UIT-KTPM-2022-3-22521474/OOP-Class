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
	C3DPoint A;
	A.Init();
	C3DPoint B = { 0,0,0 };
	B.Init(0, 0, 0);
	C3DPoint C(A);
	C.Init(A);
	cout << "\nEnter the first point's coordinate:" << endl;
	A.Input();
	cout << "\nEnter the second point's coordinate:" << endl;
	cin >> B;
	cout << "\nThe first inputted point's coordinate is:	";
	A.Output();
	cout << "\nThe second inputted point's coordinate is:	";
	cout << B << endl;
	cout << "\nAfter assigned the first point's coordinate to third point, the coordinate of the third point is:	";
	C = A;
	C.Output();
	cout << endl;
	if (A.ChkOriOverlap() == true)
		cout << "\nThe first inputted point is overlapped with origin point.";
	else
		cout << "\nThe first inputted point isn't overlapped with origin point.";
	if (A.ChkOverlap(B) == true)
		cout << "\nThe first inputted point is overlapped with the second ones.";
	else if (A.ChkNonOverlap(B) == true)
		cout << "\nThe first inputted point isn't overlapped with the second ones.";
	cout << endl;
	if (A.ChkXAxis() == true)
		cout << "\nThe first inputted point is located on horizontal X-axis." << endl;
	if (A.ChkYAxis() == true)
		cout << "\nThe first inputted point is located on vertical Y-axis." << endl;
	if (A.ChkZAxis() == true)
		cout << "\nThe first inputted point is located on height Z-axis." << endl;
	if (A.ChkOxy() == true)
		cout << "\nThe first inputted point is located on Oxy plane." << endl;
	if (A.ChkOxz() == true)
		cout << "\nThe first inputted point is located on Oxz plane." << endl;
	if (A.ChkOyz() == true)
		cout << "\nThe first inputted point is located on Oyz plane." << endl;
	if (A >= B)
	{
		cout << "\nThe first inputted point has the bigger or equal origin distance with the second ones.";
		if (A == B)
			cout << "\nThe first inputted point has equal origin distance with the second ones." << endl;
		else
		{
			if (A != B)
				cout << "\nThe first inputted point doesn't have equal origin distance with the second ones.";
			if (A > B)
				cout << "\nThe first inputted point has the bigger origin distance with the second ones." << endl;
		}
	}
	if (A <= B)
	{
		cout << "\nThe first inputted point has the smaller or equal origin distance with the second ones.";
		if (A == B)
			cout << "\nThe first inputted point has equal origin distance with the second ones." << endl;
		else
		{
			if (A != B)
				cout << "\nThe first inputted point doesn't have equal origin distance with the second ones.";
			if (A < B)
				cout << "\nThe first inputted point has the smaller origin distance with the second ones." << endl;
		}
	}
	cout << endl;
	float d = A.Distance(B);
	cout << "\nThe distance between the first inputted point and the second ones is:	" << d << ".";
	float dx = A.DistanceX(B);
	cout << "\nThe X-axis distance between the first inputted point and the second ones is:	" << dx << ".";
	float dy = A.DistanceY(B);
	cout << "\nThe Y-axis distance between the first inputted point and the second ones is:	" << dy << ".";
	float dz = A.DistanceZ(B);
	cout << "\nThe Z-axis distance between the first inputted point and the second ones is:	" << dz << ".";
	cout << endl;
	C3DPoint D = A.OriSym();
	cout << "\nThe coordinate of the point which is origin-symmetrical with the first inputted point is:	" << D << ".";
	C3DPoint E = A.XSym();
	cout << "\nThe coordinate of the point which is X-axis-symmetrical with the first inputted point is:	" << E << ".";
	C3DPoint F = A.YSym();
	cout << "\nThe coordinate of the point which is Y-axis-symmetrical with the first inputted point is:	" << F << ".";
	C3DPoint G = A.ZSym();
	cout << "\nThe coordinate of the point which is Z-axis-symmetrical with the first inputted point is:	" << G << ".";
	C3DPoint H = A.OxySym();
	cout << "\nThe coordinate of the point which is Oxy-plane-symmetrical with the first inputted point is:	" << H << ".";
	C3DPoint I = A.OxzSym();
	cout << "\nThe coordinate of the point which is Oxz-plane-symmetrical with the first inputted point is:	" << I << ".";
	C3DPoint J = A.OyzSym();
	cout << "\nThe coordinate of the point which is Oyz-plane-symmetrical with the first inputted point is:	" << J << ".";
	cout << endl;
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