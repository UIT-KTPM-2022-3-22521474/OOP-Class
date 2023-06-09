#include <iostream>
#include <string>
using namespace std;

class CTime
{
private:
	int hh;
	int mm;
	int ss;
public:
	//Initialization methods
	void Init();
	void Init(int, int, int);
	void Init(const CTime&);
	CTime();
	CTime(int, int, int);
	CTime(const CTime&);
	void Input();
	friend istream& operator>>(istream& is, CTime& cn);

	//Information provider methods
	void Output();
	friend ostream& operator<<(ostream& os, CTime& cn);
	int getHour();
	int getMin();
	int getSec();

	//Information upsec methods
	void setHour(int);
	void setMin(int);
	void setSec(int);
	CTime& operator=(const CTime&);

	//"Check-if" methods
	bool isValid();
	bool isMorning();
	bool isNoon();
	bool isAfternoon();
	bool isEvening();
	bool isNight();
	bool operator==(const CTime&);
	bool operator!=(const CTime&);
	bool operator>(const CTime&);
	bool operator<(const CTime&);
	bool operator>=(const CTime&);
	bool operator<=(const CTime&);

	//Processing methods
	int SecCount();
	~CTime();
};

int main()
{
	cout << "Project 07 - 22521474 - Class CTime design." << endl;
	CTime A, C, E;
	A.Init();
	CTime B(0, 0, 0);
	C.Init(0, 0, 0);
	CTime D(A);
	E.Init(A);
	cout << "\nEnter the first time:" << endl;
	A.Input();
	while (A.isValid() == false)
	{
		cout << "\nThe inputted time is invalid. Please try again." << endl;
		A.Input();
	}
	cout << "\nEnter the second time:" << endl;
	cin >> B;
	while (B.isValid() == false)
	{
		cout << "\nThe inputted time is invalid. Please try again." << endl;
		B.Input();
	}
	cout << "\nThe first inputted time is:							";
	A.Output();
	cout << ".\nThe second inputted time is:							";
	cout << B << "." << endl;
	cout << "\nAfter assign the first time's value to the third ones, its value is:		";
	C = A;
	cout << C;
	cout << ".\nAfter assign the second time's value to the fourth ones, its value is:		";
	D = B;
	D.Output();
	cout << "." << endl;
	if (A.isMorning() == true)
		cout << "\nThe first inputted time is in the morning.";
	if (A.isNoon() == true)
		cout << "\nThe first inputted time is in the noon.";
	if (A.isAfternoon() == true)
		cout << "\nThe first inputted time is in the afternoon.";
	if (A.isEvening() == true)
		cout << "\nThe first inputted time is in the evening.";
	if (A.isNight() == true)
		cout << "\nThe first inputted time is in night.";
	cout << endl;
	if (A >= B)
	{
		cout << "\nThe first inputted time has the bigger or equal value with the second ones.";
		if (A == B)
			cout << "\nThe first inputted time has equal value with the second ones." << endl;
		else
		{
			if (A != B)
				cout << "\nThe first inputted time doesn't have equal value with the second ones.";
			if (A > B)
				cout << "\nThe first inputted time has the bigger value with the second ones." << endl;
		}
	}
	if (A <= B)
	{
		cout << "\nThe first inputted time has the smaller or equal value with the second ones.";
		if (A == B)
			cout << "\nThe first inputted time has equal value with the second ones." << endl;
		else
		{
			if (A != B)
				cout << "\nThe first inputted time doesn't have equal value with the second ones.";
			if (A < B)
				cout << "\nThe first inputted time has the smaller value with the second ones." << endl;
		}
	}
	return 1;
}

//Initialization methods
void CTime::Init()
{
	ss = 0;
	mm = 0;
	hh = 0;
}
void CTime::Init(int sec, int min, int hour)
{
	ss = sec;
	mm = min;
	hh = hour;
}
void CTime::Init(const CTime& t)
{
	ss = t.ss;
	mm = t.mm;
	hh = t.hh;
}

CTime::CTime()
{
	ss = 0;
	mm = 0;
	hh = 0;
}
CTime::CTime(int sec, int min, int hour)
{
	ss = sec;
	mm = min;
	hh = hour;
}
CTime::CTime(const CTime& t)
{
	ss = t.ss;
	mm = t.mm;
	hh = t.hh;
}

void CTime::Input()
{
	cout << "Enter the second:	";
	cin >> ss;
	cout << "Enter the minute:	";
	cin >> mm;
	cout << "Enter the hour:		";
	cin >> hh;
}
istream& operator>>(istream& is, CTime& t)
{
	cout << "Enter the second:	";
	is >> t.ss;
	cout << "Enter the minute:	";
	is >> t.mm;
	cout << "Enter the hour:		";
	is >> t.hh;
	return is;
}

//Information provider methods
void CTime::Output()
{
	string second, minute, hour;
	if (ss < 10)
		second = "0" + to_string(ss);
	else
		second = to_string(ss);
	if (mm < 10)
		minute = "0" + to_string(mm);
	else
		minute = to_string(mm);
	if (hh < 10)
		hour = "0" + to_string(hh);
	else
		hour = to_string(hh);
	cout << hour << ":" << minute << ":" << second;
}
ostream& operator<<(ostream& os, CTime& t)
{
	string second, minute, hour;
	if (t.ss < 10)
		second = "0" + to_string(t.ss);
	else
		second = to_string(t.ss);
	if (t.mm < 10)
		minute = "0" + to_string(t.mm);
	else
		minute = to_string(t.mm);
	if (t.hh < 10)
		hour = "0" + to_string(t.hh);
	else
		hour = to_string(t.hh);
	os << hour << ":" << minute << ":" << second;
	return os;
}

int CTime::getSec()
{
	return ss;
}
int CTime::getMin()
{
	return mm;
}
int CTime::getHour()
{
	return hh;
}

//Information upsecond methods
void CTime::setSec(int second)
{
	ss = second;
}
void CTime::setMin(int minute)
{
	mm = minute;
}
void CTime::setHour(int hour)
{
	hh = hour;
}

CTime& CTime::operator=(const CTime& t)
{
	ss = t.ss;
	mm = t.mm;
	hh = t.hh;
	return *this;
}

//"Check-if" methods
bool CTime::isValid()
{
	if (hh > 23 || hh < 0)
		return false;
	if (mm > 59 || mm < 0)
		return false;
	if (ss > 59 || mm < 0)
		return false;
	return true;
}
bool CTime::isMorning()
{
	if (hh >= 6 && hh < 11)
		return true;
	return false;
}
bool CTime::isNoon()
{
	if (hh >= 11 && hh < 13)
		return true;
	return false;
}
bool CTime::isAfternoon()
{
	if (hh >= 13 && hh < 18)
		return true;
	return false;
}
bool CTime::isEvening()
{
	if (hh >= 18 && hh < 22)
		return true;
	return false;
}
bool CTime::isNight()
{
	if ((hh >= 22 && hh < 24) || (hh >= 0 && hh < 6))
		return true;
	return false;
}

bool CTime::operator==(const CTime& t)
{
	CTime temp = t;
	if (SecCount() == temp.SecCount())
		return true;
	return false;
}
bool CTime::operator!=(const CTime& t)
{
	CTime temp = t;
	if (SecCount() != temp.SecCount())
		return true;
	return false;
}
bool CTime::operator>(const CTime& t)
{
	CTime temp = t;
	if (SecCount() > temp.SecCount())
		return true;
	return false;
}
bool CTime::operator<(const CTime & t)
{
	CTime temp = t;
	if (SecCount() < temp.SecCount())
		return true;
	return false;
}
bool CTime::operator>=(const CTime& t)
{
	CTime temp = t;
	if (SecCount() >= temp.SecCount())
		return true;
	return false;
}
bool CTime::operator<=(const CTime& t)
{
	CTime temp = t;
	if (SecCount() <= temp.SecCount())
		return true;
	return false;
}

//Processing methods
int CTime::SecCount()
{
	return (hh * 3600 + mm * 60 + ss);
}

CTime::~CTime()
{
	return;
}