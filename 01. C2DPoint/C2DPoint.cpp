#include <iostream>
#include <cmath>
using namespace std;

class C2DPoint
{
private:
	float x;
	float y;
public:
	//Initialization methods
	void Init();
	void Init(float, float);
	void Init(const C2DPoint&);
	C2DPoint();
	C2DPoint(float, float);
	C2DPoint(const C2DPoint&);
	void Input();
	friend istream& operator>>(istream&, C2DPoint&);

	//Information provider methods
	void Output();
	friend ostream& operator<<(ostream&, C2DPoint&);
	float getX();
	float getY();

	//Information updater methods
	C2DPoint& operator=(const C2DPoint&);
	void setX(float);
	void setY(float);

	//"Check-if" methods
	bool ChkOriOverlap();
	bool ChkOverlap(const C2DPoint&);
	bool ChkNonOverlap(const C2DPoint&);
	bool ChkYAxis();
	bool ChkXAxis();
	bool ChkQuarter1();
	bool ChkQuarter2();
	bool ChkQuarter3();
	bool ChkQuarter4();
	bool operator==(C2DPoint&);
	bool operator!=(C2DPoint&);
	bool operator>(C2DPoint&);
	bool operator>=(C2DPoint&);
	bool operator<(C2DPoint&);
	bool operator<=(C2DPoint&);

	//Processing methods
	float OriDist();
	float Distance(const C2DPoint&);
	float DistanceX(const C2DPoint&);
	float DistanceY(const C2DPoint&);
	C2DPoint OriSym();
	C2DPoint XSym();
	C2DPoint YSym();
	C2DPoint BisectorSym1();
	C2DPoint BisectorSym2();
	~C2DPoint();
};

int main()
{
	cout << "Project 01 - 22521474 - Class C2DPoint design." << endl;
	C2DPoint A;
	A.Init();
	C2DPoint B = { 0,0 };
	B.Init(0, 0);
	C2DPoint C(A);
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
	if (A.ChkXAxis()==true)
		cout << "\nThe first inputted point is located on horizontal X-axis." << endl;
	if (A.ChkYAxis() == true)
		cout << "\nThe first inputted point is located on vertical Y-axis." << endl;
	if (A.ChkQuarter1() == true)
		cout << "\nThe first inputted point is located on the Quarter I of Cartesian coordinate system." << endl;
	if (A.ChkQuarter2() == true)
		cout << "\nThe first inputted point is located on the Quarter II of Cartesian coordinate system." << endl;
	if (A.ChkQuarter3() == true)
		cout << "\nThe first inputted point is located on the Quarter III of Cartesian coordinate system." << endl;
	if (A.ChkQuarter4() == true)
		cout << "\nThe first inputted point is located on the Quarter IV of Cartesian coordinate system." << endl;
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
	float d = A.Distance(B);
	cout << "\nThe distance between the first inputted point and the second ones is:	" << d << ".";
	float dx = A.DistanceX(B);
	cout << "\nThe X-axis distance between the first inputted point and the second ones is:	" << dx << ".";
	float dy = A.DistanceY(B);
	cout << "\nThe Y-axis distance between the first inputted point and the second ones is:	" << dy << ".";
	cout << endl;
	C2DPoint D = A.OriSym();
	cout << "\nThe coordinate of the point which is origin-symmetrical with the first inputted point is:	" << D << ".";
	C2DPoint E = A.XSym();
	cout << "\nThe coordinate of the point which is X-axis-symmetrical with the first inputted point is:	" << E << ".";
	C2DPoint F = A.YSym();
	cout << "\nThe coordinate of the point which is Y-axis-symmetrical with the first inputted point is:	" << F << ".";
	C2DPoint G = A.BisectorSym1();
	cout << "\nThe coordinate of the point which is biosector-symmetrical (y = x) with the first inputted point is:	" << G << ".";
	C2DPoint H = A.BisectorSym2();
	cout << "\nThe coordinate of the point which is biosector-symmetrical (y = -x) with the first inputted point is:	" << H << ".";
	cout << endl;
	return 1;
}

//Initialization methods
void C2DPoint::Init()
{
	x = 0;
	y = 0;
}
void C2DPoint::Init(float px, float py)
{
	x = px;
	y = py;
}
void C2DPoint::Init(const C2DPoint& p)
{
	x = p.x;
	y = p.y;
}

C2DPoint::C2DPoint()
{
	x = 0;
	y = 0;
}
C2DPoint::C2DPoint(float px, float py)
{
	x = px;
	y = py;
}
C2DPoint::C2DPoint(const C2DPoint& p)
{
	x = p.x;
	y = p.y;
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

//Information provider methods
void C2DPoint::Output()
{
	cout << "(" << x << ", " << y << ")";
}

ostream& operator<<(ostream& os, C2DPoint& P)
{
	os << "(" << P.x << ", " << P.y << ")";
	return os;
}

float C2DPoint::getX()
{
	return x;
}
float C2DPoint::getY()
{
	return y;
}

//Information updater methods
C2DPoint& C2DPoint::operator=(const C2DPoint& P)
{
	x = P.x;
	y = P.y;
	return *this;
}

void C2DPoint::setX(float px)
{
	x = px;
}
void C2DPoint::setY(float py)
{
	y = py;
}

//"Check-if" methods
bool C2DPoint::ChkOriOverlap()
{
	if (x == 0 && y == 0)
		return true;
	return false;
}
bool C2DPoint::ChkOverlap(const C2DPoint& P)
{
	if (x == P.x && y == P.y)
		return true;
	return false;
}
bool C2DPoint::ChkNonOverlap(const C2DPoint& P)
{
	if (x != P.x || y != P.y)
		return true;
	return false;
}

bool C2DPoint::ChkXAxis()
{
	if (y == 0)
		return true;
	return false;
}
bool C2DPoint::ChkYAxis()
{
	if (x == 0)
		return true;
	return false;
}

bool C2DPoint::ChkQuarter1()
{
	if (x > 0 && y > 0)
		return true;
	return false;
}
bool C2DPoint::ChkQuarter2()
{
	if (x < 0 && y > 0)
		return true;
	return false;
}
bool C2DPoint::ChkQuarter3()
{
	if (x < 0 && y < 0)
		return true;
	return false;
}
bool C2DPoint::ChkQuarter4()
{
	if (x > 0 && y < 0)
		return true;
	return false;
}

bool C2DPoint::operator==(C2DPoint& P)
{
	if (OriDist() == P.OriDist())
		return true;
	return false;
}

bool C2DPoint::operator!=(C2DPoint& P)
{
	if (OriDist() != P.OriDist())
		return true;
	return false;
}

bool C2DPoint::operator>(C2DPoint& P)
{
	if (OriDist() > P.OriDist())
		return true;
	return false;
}

bool C2DPoint::operator>=(C2DPoint& P)
{
	if (OriDist() >= P.OriDist())
		return true;
	return false;
}

bool C2DPoint::operator<(C2DPoint& P)
{
	if (OriDist() < P.OriDist())
		return true;
	return false;
}

bool C2DPoint::operator<=(C2DPoint& P)
{
	if (OriDist() <= P.OriDist())
		return true;
	return false;
}

//Processing methods
float C2DPoint::OriDist()
{
	return sqrt(x * x + y * y);
}

float C2DPoint::Distance(const C2DPoint& P)
{
	return sqrt((x - P.x) * (x - P.x) + (y - P.y) * (y - P.y));
}

float C2DPoint::DistanceX(const C2DPoint& P)
{
	return abs(x - P.x);
}

float C2DPoint::DistanceY(const C2DPoint& P)
{
	return abs(y - P.y);
}

C2DPoint C2DPoint::OriSym()
{
	C2DPoint temp;
	temp.x = -x;
	temp.y = -y;
	if (x == 0)
		temp.x = 0;
	if (y == 0)
		temp.y = 0;
	return temp;
}

C2DPoint C2DPoint::XSym()
{
	C2DPoint temp;
	temp.x = x;
	temp.y = -y;
	if (x == 0)
		temp.x = 0;
	if (y == 0)
		temp.y = 0;
	return temp;
}

C2DPoint C2DPoint::YSym()
{
	C2DPoint temp;
	temp.x = -x;
	temp.y = y;
	if (x == 0)
		temp.x = 0;
	if (y == 0)
		temp.y = 0;
	return temp;
}

C2DPoint C2DPoint::BisectorSym1()
{
	C2DPoint temp;
	temp.x = y;
	temp.y = x;
	if (x == 0)
		temp.y = 0;
	if (y == 0)
		temp.x = 0;
	return temp;
}

C2DPoint C2DPoint::BisectorSym2()
{
	C2DPoint temp;
	temp.x = -y;
	temp.y = -x;
	if (x == 0)
		temp.y = 0;
	if (y == 0)
		temp.x = 0;
	return temp;
}

C2DPoint::~C2DPoint()
{
	return;
}