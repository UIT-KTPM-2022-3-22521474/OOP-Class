#include <iostream>
#include <string>
using namespace std;

class CDate
{
private:
	int dd;
	int mm;
	int yyyy;
public:
	//Initialization methods
	void Init();
	void Init(int, int, int);
	void Init(const CDate&);
	CDate();
	CDate(int, int, int);
	CDate(const CDate&);
	void Input();
	friend istream& operator>>(istream& is, CDate& cn);

	//Information provider methods
	void Output();
	friend ostream& operator<<(ostream& os, CDate& cn);
	int getDate();
	int getMonth();
	int getYear();

	//Information update methods
	void setDate(int);
	void setMonth(int);
	void setYear(int);
	CDate& operator=(const CDate&);

	//"Check-if" methods
	bool isValid();
	bool isLeap();
	bool operator>(const CDate&);
	bool operator>=(const CDate&);
	bool operator<(const CDate&);
	bool operator<=(const CDate&);
	bool operator==(const CDate&);
	bool operator!=(const CDate&);

	//Processing methods
	int LastDateOfMonth();
	int LastDateOfYear();
	int OrdNumInYear();
	int OrdNum();
	int Compare(CDate);
	int Distance(CDate);
	CDate& NextDate();
	CDate& PrevDate();
	CDate& Before(int);
	void DaysOfTheWeek();
	~CDate();
};

int main()
{
	cout << "Project 06 - 22521474 - Class CDate design." << endl;
	return 1;
}

void CDate::Init()
{
	dd = 1;
	mm = 1;
	yyyy = 1;
}
void CDate::Init(int date, int month, int year)
{
	dd = date;
	mm = month;
	yyyy = year;
}
void CDate::Init(const CDate& d)
{
	dd = d.dd;
	mm = d.mm;
	yyyy = d.yyyy;
}

CDate::CDate()
{
	dd = 1;
	mm = 1;
	yyyy = 1;
}
CDate::CDate(int date, int month, int year)
{
	dd = date;
	mm = month;
	yyyy = year;
}
CDate::CDate(const CDate& d)
{
	dd = d.dd;
	mm = d.mm;
	yyyy = d.yyyy;
}

void CDate::Input()
{
	cout << "Enter the date:	";
	cin >> dd;
	cout << "Enter the month:	";
	cin >> mm;
	cout << "Enter the year:	";
	cin >> yyyy;
}
istream& operator>>(istream& is, CDate& d)
{
	cout << "Enter the date:	";
	is >> d.dd;
	cout << "Enter the month:	";
	is >> d.mm;
	cout << "Enter the year:	";
	is >> d.yyyy;
	return is;
}

//Information provider methods
void CDate::Output()
{
	string date, month, year;
	if(dd < 10)
		date = "0" + to_string(dd);
	date = to_string(dd);
	if (mm < 10)
		month = "0" + to_string(mm);
	month = to_string(mm);
	year = to_string(yyyy);
	cout << date << "/" << month << "/" << year;
}
ostream& operator<<(ostream& os, CDate& d)
{
	string date, month, year;
	if (d.dd < 10)
		date = "0" + to_string(d.dd);
	date = to_string(d.dd);
	if (d.mm < 10)
		month = "0" + to_string(d.mm);
	month = to_string(d.mm);
	year = to_string(d.yyyy);
	os << date << "/" << month << "/" << year;
	return os;
}

int CDate::getDate()
{
	return dd;
}
int CDate::getMonth()
{
	return mm;
}
int CDate::getYear()
{
	return yyyy;
}

//Information update methods
void CDate::setDate(int date)
{
	dd = date;
}
void CDate::setMonth(int month)
{
	mm = month;
}
void CDate::setYear(int year)
{
	yyyy = year;
}

CDate& CDate::operator=(const CDate& d)
{
	dd = d.dd;
	mm = d.mm;
	yyyy = d.yyyy;
	return *this;
}

//"Check-if" methods
bool CDate::isValid()
{
	if (dd<1 || dd>LastDateOfMonth())
		return false;
	if (mm < 1 || mm>12)
		return false;
	if (yyyy < 1)
		return false;
	return true;
}

bool CDate::isLeap()
{
	if (yyyy % 4 == 0 && yyyy % 100 != 0)
		return true;
	if (yyyy % 400 == 0)
		return true;
	return false;
}

bool CDate::operator==(const CDate& d)
{
	if ((yyyy == d.yyyy) && (mm = d.mm) && (dd = d.dd))
		return true;
	return false;
}
bool CDate::operator!=(const CDate& d)
{
	if (!((yyyy == d.yyyy) && (mm = d.mm) && (dd = d.dd)))
		return true;
	return false;
}
bool CDate::operator<(const CDate& d)
{
	if (yyyy < d.yyyy)
		return true;
	if ((yyyy == d.yyyy) && (mm < d.mm))
		return true;
	if ((yyyy == d.yyyy) && (mm = d.mm) && (dd < d.dd))
		return true;
	return false;
}
bool CDate::operator>(const CDate& d)
{
	if (yyyy > d.yyyy)
		return true;
	if ((yyyy == d.yyyy) && (mm > d.mm))
		return true;
	if ((yyyy == d.yyyy) && (mm = d.mm) && (dd > d.dd))
		return true;
	return false;
}
bool CDate::operator<=(const CDate& d)
{
	if (!((*this) > d))
		return true;
	return false;
}
bool CDate::operator>=(const CDate& d)
{
	if (!((*this) < d))
		return true;
	return false;
}

//Processing methods
int CDate::LastDateOfMonth()
{
	int LastDate[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (isLeap() == true)
		LastDate[1] = 29;
	return LastDate[mm - 1];
}
int CDate::LastDateOfYear()
{
	if (this->isLeap() == true)
		return 366;
	return 365;
}

int CDate::OrdNumInYear()
{
	int on = 0;
	for (int i = 1; i <= mm - 1; i++)
	{
		CDate temp = { 1,i,yyyy };
		on += temp.LastDateOfMonth();
	}
	return (on + dd);
}
int CDate::OrdNum()
{
	int on = 0;
	for (int i = 1; i <= yyyy - 1; i++)
	{
		CDate temp = { 1,1,i };
		on += temp.LastDateOfYear();
	}
	return (on + OrdNumInYear());
}

int CDate::Compare(CDate d)
{
	if ((*this) > d)
		return 1;
	if ((*this) < d)
		return -1;
	return 0;
}

int CDate::Distance(CDate d)
{
	int a = OrdNum();
	int b = d.OrdNum();
	return abs(a - b);
}

void CDate::DaysOfTheWeek()
{
	int on = OrdNum();
	switch (on % 7)
	{
	case 0:
		cout << "Sunday";
		break;
	case 1:
		cout << "Monday";
		break;
	case 2:
		cout << "Tuesday";
		break;
	case 3:
		cout << "Wednesday";
		break;
	case 4:
		cout << "Thursday";
		break;
	case 5:
		cout << "Friday";
		break;
	case 6:
		cout << "Saturday";
		break;
	}
}

CDate& CDate::NextDate()
{
	int LastDate[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (isLeap() == true)
		LastDate[1] = 29;
	dd++;
	if (dd > LastDate[mm - 1])
	{
		mm++;
		if (mm > 12)
		{
			yyyy++;
			mm = 1;
		}
		dd = 1;
	}
	return *this;
}
CDate& CDate::PrevDate()
{
	int LastDate[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (isLeap() == true)
		LastDate[1] = 29;
	dd--;
	if (dd==0)
	{
		mm--;
		if (mm == 0)
		{
			yyyy--;
			mm = 12;
		}
		dd = LastDate[mm - 1];
	}
	return *this;
}

CDate& CDate::Before(int k)
{
	for (int i = 1; i <= k; i++)
		*this = this->PrevDate();
	return *this;
}

CDate::~CDate()
{
	return;
}