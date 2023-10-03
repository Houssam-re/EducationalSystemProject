#pragma once
#pragma warning(disable:4996)
#include <iostream>
#include <vector>
#include <iostream>
#include <string>
#include "clsString.h"
using namespace std;
class clsDate
{

private:
	short _Day;
	short _Month;
	short _Year;

public:
	static clsDate GetSystemDate() {
		time_t t = time(0);
		tm* now = localtime(&t);
		short _Day;
		short _Month;
		short _Year;
		_Year = now->tm_year + 1900;
		_Month = now->tm_mon + 1;
		_Day = now->tm_mday;
		clsDate Date1(_Day, _Month, _Year);
		return Date1;
	}

	static string GetSystemDateTimeString()
	{

		time_t t = time(0);
		tm* now = localtime(&t);

		short Day, Month, Year, Hour, Minute, Second;

		Year = now->tm_year + 1900;
		Month = now->tm_mon + 1;
		Day = now->tm_mday;
		Hour = now->tm_hour;
		Minute = now->tm_min;
		Second = now->tm_sec;

		return (to_string(Day) + "/" + to_string(Month) + "/"
			+ to_string(Year) + " - "
			+ to_string(Hour) + ":" + to_string(Minute)
			+ ":" + to_string(Second));

	}
	clsDate()
	{
		*this = GetSystemDate();
	}

	clsDate(string sDate)
	{
		vector<string> vDate = clsString::SplitString(sDate, "/");
		_Day = stoi(vDate[0]);
		_Month = stoi(vDate[1]);
		_Year = stoi(vDate[2]);

	}

	clsDate(short Days, short Months, short Years)
	{
		_Day = Days;
		_Month = Months;
		_Year = Years;
	}

	clsDate(short Number, short Years)
	{
		*this = GiveTheDateFromNumber(Number, Years);
	}

	void setDay(short Days)
	{
		_Day = Days;
	}

	short GetDay()
	{
		return _Day;
	}

	void setMonth(short Months)
	{
		_Month = Months;
	}

	short GetMonth()
	{
		return _Month;
	}

	short GetYear()
	{
		return _Year;
	}

	void setYear(short Years)
	{
		_Year = Years;
	}

	__declspec(property(get = GetDay, put = setDay)) string _Day;
	__declspec(property(get = GetMonth, put = setMonth)) string _Month;
	__declspec(property(get = GetYear, put = setYear)) string _Year;

	void Print()
	{
		cout << _Day << "/" << _Month << "/" << _Year << endl;
	}
	static bool isLeapYear(int _Year)
	{
		return (_Year % 400 == 0) || (_Year % 4 == 0 && _Year % 100 != 0);
	}
	bool isLeapYear()
	{
		return isLeapYear(_Year);
	}
	static int numberOfDaysInMonth(short _Month, int _Year)
	{
		if (_Month < 1 || _Month > 12)
			return -1;
		short NumberOfDaysInMonth[] = { 31,0,31,30,31,30,31,31,30,31,30,31 };
		return (_Month == 2) ? (isLeapYear(_Year)) ? 29 : 28 : NumberOfDaysInMonth[_Month - 1];
	}
	int numberOfDaysInMonth()
	{
		return numberOfDaysInMonth(_Month, _Year);
	}
	static int numberOfDaysInYear(int _Year)
	{
		return (isLeapYear(_Year)) ? 366 : 365;
	}
	int numberOfDaysInYear()
	{
		return _Year;
	}

	static clsDate GiveTheDateFromNumber(short Number, short _Year)
	{
		short Days;
		short Months = 1;


		while (true)
		{
			if (Number > numberOfDaysInYear(_Year))
			{
				_Year++;
				Number -= numberOfDaysInYear(_Year);
			}
			else
			{
				if (Number > numberOfDaysInMonth(Months, _Year))
				{
					Months++;
					Number -= numberOfDaysInMonth(Months, _Year);
					if (Months > 12) { Months = 1; _Year++; }
				}
				else
				{

					Days = Number;
					break;
				}
			}
		}
		return clsDate(Days, Months, _Year);

	}
	static string WritDayName(short Day)
	{

		string arr[]{ "Sun", "Mon" ,"Tue" ,"Wed" ,"Thu" ,"Fri" ,"Sat" };
		return arr[Day];
	}
	string WritDayName()
	{
		return WritDayName(_Day);
	}
	static string WritMonthName(short MonthNum)
	{
		string arr[]{ "Jan", "Feb" ,"Mar" ,"App" ,"May" ,"Jun" ,"July","Aug" ,"Sep" ,"Oct" ,"Nov" ,
		"Dec" };
		return arr[MonthNum - 1];
	}
	string WritMonthName()
	{
		return WritMonthName(_Month);
	}
	enum enDayName
	{
		Sanday = 0, Monday = 1, Tuesday = 2, Wednsday = 3, Thursday = 4, Friday = 5, Saturday = 6
	};
	static short CalculeDayNum(short _Year, short _Month, short _Day = 1)
	{
		int day;
		day = (14 - _Month) / 12;
		_Year = _Year - day;
		_Month = _Month + (12 * day) - 2;
		_Day = ((_Day + _Year + (_Year / 4) - (_Year / 100) + (_Year / 400) + ((31 * _Month) / 12)) % 7);
		return _Day;
	}
	short CalculeDayNum()
	{
		return CalculeDayNum(_Year, _Month, _Day);
	}
	static void DrawCalendrer(short _Year, short _Month)
	{
		int current = CalculeDayNum(_Year, _Month);
		short numberofdaysatMonth = numberOfDaysInMonth(_Month, _Year);
		cout << "-----------------" << WritMonthName(_Month) << "------------------\n\n";
		printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat  \n");
		short i;
		for (i = 0; i < current; i++)
		{
			cout << "     ";
		}
		for (short j = 1; j < numberofdaysatMonth; j++)
		{
			printf("%5d", j);
			if (++i == 7)
			{
				cout << "\n";
				i = 0;
			}
		}
	}
	string ToString()
	{
		string Line = "";
		Line += to_string(GetDay()) + "/";
		Line += to_string(GetMonth()) + "/";
		Line += to_string(GetYear());
		return Line;
	}

	void DrawCalendrer()
	{
		return DrawCalendrer(_Year, _Month);
	}




	static void DrawYearCalendrer(short _Year)
	{
		for (short i = 1; i <= 12; i++)
		{
			DrawCalendrer(_Year, i);
			cout << endl;
		}
	}


	void DrawYearCalendrer()
	{
		return DrawYearCalendrer(_Year);
	}



	static bool isValid(clsDate Date)
	{
		return (Date._Day <= numberOfDaysInMonth(Date._Month, Date._Year) && Date._Day > 0 && Date._Year > 0) ? true : false;
	}


	bool isValid()
	{
		return isValid(*this);
	}


	static bool isDate1BeforeDate2(clsDate Date1, clsDate Date2)
	{
		return (Date1._Year < Date2._Year) ? true : (Date1._Year == Date2._Year) ? ((Date1._Month < Date2._Month) ? true : (Date1._Month == Date2._Month) ? ((Date1._Day < Date2._Day)) : false) : false;
	}


	bool isDate1BeforeDate2(clsDate Date2)
	{
		return isDate1BeforeDate2(*this, Date2);
	}



	static bool isDate1EqualDate2(clsDate Date1, clsDate Date2)
	{


		return (Date1._Year == Date2._Year) ? ((Date1._Month == Date2._Month) ? ((Date1._Day == Date2._Day) ? true : false) : false) : false;
	}


	bool isDate1EqualDate2(clsDate Date2)
	{
		return isDate1EqualDate2(*this, Date2);
	}


	static bool isDate1AfterDate2(clsDate Date1, clsDate Date2)
	{
		return (!isDate1BeforeDate2(Date1, Date2) && !isDate1EqualDate2(Date1, Date2));
	}


	bool isDate1AfterDate2(clsDate Date2)
	{
		return isDate1AfterDate2(*this, Date2);
	}

	static bool isLastDayInMonth(clsDate Date)
	{
		return (Date._Day == numberOfDaysInMonth(Date._Month, Date._Year));

	}

	bool isLastDayInMonth()
	{
		return isLastDayInMonth(*this);
	}

	static bool isLastMonthInYear(clsDate Date)
	{
		return  (Date._Month == 12);
	}

	bool isLastMonthInYear()
	{
		return isLastMonthInYear(*this);
	}

	static clsDate increaseDateByOneDay(clsDate Date)
	{
		if (isLastDayInMonth(Date))
		{
			if (isLastMonthInYear(Date))
			{
				Date._Day = 1;
				Date._Month = 1;
				Date._Year++;
			}
			else
			{
				Date._Day = 1;
				Date._Month++;
			}
		}
		else
			Date._Day++;

		return Date;
	}

	void increaseDateByOneDay()
	{
		*this = increaseDateByOneDay(*this);
	}
public:
	static void SwapDate(clsDate& Date1, clsDate& Date2)
	{
		short tYear;
		short tMonth;
		short tDay;
		tYear = Date1._Year;
		tMonth = Date1._Month;
		tDay = Date1._Day;
		Date1._Year = Date2._Year;
		Date1._Month = Date2._Month;
		Date1._Day = Date2._Day;
		Date2._Year = tYear;
		Date2._Month = tMonth;
		Date2._Day = tDay;

	}
	void SwapDate(clsDate& Date2)
	{
		SwapDate(*this, Date2);
	}
	static short countDayDeffBetweenTwoDate(clsDate Date1, clsDate Date2, bool inCludEndDay = false)
	{
		int DayCounter = 0;
		short Value = 1;
		if (isDate1EqualDate2(Date1, Date2))
		{
			return (inCludEndDay) ? 1 : 0;
		}
		if (!isDate1BeforeDate2(Date1, Date2))
		{
			SwapDate(Date1, Date2);
			Value = -1;

		}
		while (isDate1BeforeDate2(Date1, Date2))
		{
			DayCounter++;
			Date1 = increaseDateByOneDay(Date1);
		}

		return (inCludEndDay) ? ++DayCounter * Value : DayCounter * Value;
	}
	static short CalculeMyAgeInDate(clsDate Date)
	{
		return countDayDeffBetweenTwoDate(Date, GetSystemDate(), true);
	}

	short CalculeMyAgeInDate()
	{
		return CalculeMyAgeInDate(*this);
	}
	static short DayOrdreInWeek(clsDate Date)
	{

		return CalculeDayNum(Date._Year, Date._Month, Date._Day);

	}
	short DayOrdreInWeek()
	{

		return DayOrdreInWeek(*this);

	}
	static bool IsEndOfWeek(clsDate Date)
	{
		return (DayOrdreInWeek(Date) == 6);
	}

	bool IsEndOfWeek()
	{
		return IsEndOfWeek(*this);
	}
	static bool IsWeekEnd(clsDate Date)
	{
		short DayIndex = DayOrdreInWeek(Date);
		return (DayIndex == 5 || DayIndex == 6);
	}
	bool IsWeekEnd()
	{
		return IsWeekEnd(*this);
	}
	static bool IsBuisnessDate(clsDate Date)
	{
		return (!IsWeekEnd(Date));
	}
	bool IsBuisnessDate()
	{
		return IsBuisnessDate(*this);
	}


	static short DayUntilEndOfWeek(clsDate Date)
	{

		return (6 - DayOrdreInWeek(Date));
	}
	short DayUntilEndOfWeek()
	{
		return DayUntilEndOfWeek(*this);
	}


	static short DayUntilEndOMonth(clsDate Date)
	{

		short tDay = numberOfDaysInMonth(Date._Month, Date._Year);
		short tMonth = Date._Month;
		short tYear = Date._Year;
		clsDate Date2(tDay, tMonth, tYear);
		return countDayDeffBetweenTwoDate(Date, Date2, true);
	}
	short DayUntilEndOMonth()
	{
		return DayUntilEndOMonth(*this);
	}
	static short DayUntilEndOFYear(clsDate Date)
	{

		short Days = 31;
		short Months = 12;
		short Years = Date._Year;
		clsDate Date2(Days, Months, Years);
		return countDayDeffBetweenTwoDate(Date, Date2, true);
	}


	short DayUntilEndOFYear()
	{
		return DayUntilEndOFYear(*this);
	}
	static short CalculeActualVacation(clsDate Start, clsDate End)
	{
		short Counter = 0;
		while (isDate1BeforeDate2(Start, End))
		{
			if (IsBuisnessDate(Start))
				Counter++;

			Start = increaseDateByOneDay(Start);
		}
		return Counter;
	}

	short CalculeActualVacation(clsDate End)
	{
		return CalculeActualVacation(*this, End);
	}


	static clsDate  DecreaseDateByOneDay(clsDate  Date)
	{
		if (Date._Day == 1)
		{
			if (Date._Month == 1)
			{
				Date._Year--;
				Date._Month = 12;
				Date._Day = numberOfDaysInMonth(Date._Month, Date._Year);
			}
			else
			{
				Date._Month--;
				Date._Day = numberOfDaysInMonth(Date._Month, Date._Year);
			}
		}
		else
			Date._Day--;
		return Date;
	}
	clsDate DecreaseDateByOneDay()
	{
		return DecreaseDateByOneDay(*this);
	}


	static clsDate  DecreaseDateByXDay(short _Day, clsDate Date)
	{
		for (short i = 0; i < _Day; i++)
		{
			Date = DecreaseDateByOneDay(Date);
		}
		return Date;
	}
	clsDate  DecreaseDateByXDay(short _Day)
	{
		return DecreaseDateByXDay(_Day, *this);
	}
	static clsDate DecreaseDateByOneWeek(clsDate  Date)
	{
		for (short i = 1; i <= 7; i++)
		{
			Date = DecreaseDateByOneDay(Date);
		}
		return Date;
	}
	clsDate  DecreaseDateByOneWeek()
	{
		return DecreaseDateByOneWeek(*this);
	}
	static clsDate DecreesDateByXWeek(short Week, clsDate Date)
	{
		for (short i = 1; i <= Week; i++)
		{
			Date = DecreaseDateByOneWeek(Date);
		}
		return Date;
	}
	clsDate DecreesDateByXWeek(short Week)
	{
		return DecreesDateByXWeek(Week, *this);
	}
	static clsDate DecreaseDateByOneMonth(clsDate Date)
	{
		(Date._Month == 1) ? Date._Month = 12, Date._Year-- : Date._Month--;

		if (Date._Day > numberOfDaysInMonth(Date._Month, Date._Year))
		{
			Date._Day = numberOfDaysInMonth(Date._Month, Date._Year);
		}
		return Date;
	}
	clsDate DecreaseDateByOneMonth()
	{
		return DecreaseDateByOneMonth(*this);
	}
	static clsDate DecreaseDateByXMonth(short _Month, clsDate Date)
	{
		for (short i = 1; i <= _Month; i++)
		{
			Date = DecreaseDateByOneMonth(Date);
		}
		return Date;
	}
	clsDate DecreaseDateByXMonth(short _Month)
	{
		return DecreaseDateByXMonth(_Month, *this);
	}
	static clsDate DecreaseDateByOneYear(clsDate Date)
	{
		Date._Year -= 1;
		return Date;
	}
	clsDate DecreaseDateByOneYear()
	{
		return DecreaseDateByOneYear(*this);
	}
	static clsDate DecreaseDateByXYear(short _Year, clsDate Date)
	{
		for (short i = 1; i <= _Year; i++)
		{
			Date = DecreaseDateByOneYear(Date);
		}
		return Date;
	}

	clsDate DecreaseDateByXYear(short _Year)
	{
		return DecreaseDateByXYear(_Year, *this);
	}
	static clsDate DecreaseDateByXYearFaster(short _Year, clsDate Date)
	{
		Date._Year -= _Year;
		return Date;
	}
	clsDate DecreaseDateByXYearFaster(short _Year)
	{
		return DecreaseDateByXYearFaster(_Year, *this);
	}
	static clsDate DecreaseDateByOneDecade(clsDate Date)
	{
		Date._Year -= 10;
		return Date;
	}
	clsDate DecreaseDateByOneDecade()
	{
		return DecreaseDateByOneDecade(*this);
	}
	static clsDate DecreaseDateByXDecade(short Decade, clsDate Date)
	{
		for (short i = 1; i <= Decade; i++)
		{
			Date = DecreaseDateByOneDecade(Date);
		}
		return Date;
	}

	clsDate DecreaseDateByXDecade(short Decade)
	{
		return DecreaseDateByXDecade(Decade, *this);
	}

	static clsDate DecreaseDateByXDecadeFaster(short Decade, clsDate Date)
	{
		Date._Year -= (Decade * 10);
		return Date;
	}
	clsDate DecreaseDateByXDecadeFaster(short Decade)
	{
		return DecreaseDateByXDecadeFaster(Decade, *this);
	}
	static clsDate DecreaseDateByOneCentury(clsDate Date)
	{
		Date._Year -= 100;
		return Date;
	}
	clsDate DecreaseDateByOneCentury()
	{
		return DecreaseDateByOneCentury(*this);
	}

	static clsDate DecreaseDateByOneMillennium(clsDate Date)
	{
		Date._Year -= 1000;
		return Date;
	}



	static	clsDate inCreaseDateByXDay(short _Day, clsDate Date)
	{
		for (short i = 1; i <= _Day; i++)
		{
			Date = increaseDateByOneDay(Date);
		}
		return Date;
	}
	clsDate inCreaseDateByXDay(short _Day)
	{
		return inCreaseDateByXDay(_Day, *this);
	}
	static	clsDate inCreaseDateByOneWeek(clsDate& Date)
	{
		for (short i = 1; i <= 7; i++)
		{
			Date = increaseDateByOneDay(Date);
		}
		return Date;
	}
	clsDate inCreaseDateByOneWeek()
	{
		return inCreaseDateByOneWeek(*this);
	}
	static	clsDate inCreaseDateByXWeek(short Week, clsDate& Date)
	{
		for (short i = 1; i <= Week; i++)
		{
			Date = inCreaseDateByOneWeek(Date);
		}
		return Date;
	}
	clsDate inCreaseDateByXWeek(short Week)
	{
		return inCreaseDateByXWeek(Week, *this);
	}
	static	clsDate inCreaseDateByOneMonth(clsDate& Date)
	{

		(Date._Month < 12) ? Date._Month++ : Date._Month = 1;
		if (Date._Day > numberOfDaysInMonth(Date._Month, Date._Year))
			Date._Day = numberOfDaysInMonth(Date._Month, Date._Year);

		return Date;
	}
	clsDate inCreaseDateByOneMonth()
	{
		return inCreaseDateByOneMonth(*this);
	}
	static	clsDate inCreaseDateByXMonth(short _Month, clsDate& Date)
	{
		for (short i = 1; i <= _Month; i++)
		{
			Date = inCreaseDateByOneMonth(Date);
		}
		return Date;
	}
	clsDate inCreaseDateByXMonth(short _Month)
	{
		return inCreaseDateByXMonth(_Month, *this);
	}
	static	clsDate inCreaseDateByOneYear(clsDate& Date)
	{
		Date._Year++;
		return Date;
	}
	clsDate inCreaseDateByOneYear()
	{
		return inCreaseDateByOneYear(*this);
	}
	static	clsDate inCreaseDateByXYear(short _Year, clsDate& Date)
	{
		for (short i = 1; i <= _Year; i++)
		{
			Date = inCreaseDateByOneYear(Date);
		}
		return Date;
	}
	clsDate inCreaseDateByXYear(short _Year)
	{
		return inCreaseDateByXYear(_Year, *this);
	}
	static	clsDate inCreaseDateByXYearFaster(short _Year, clsDate& Date)
	{
		Date._Year += _Year;
		return Date;
	}
	clsDate inCreaseDateByXYearFaster(short _Year)
	{
		return inCreaseDateByXYearFaster(_Year, *this);
	}


	static	clsDate inCreaseDateByOneDecade(clsDate& Date)
	{

		return inCreaseDateByXYear(10, Date);
	}
	clsDate inCreaseDateByOneDecade()
	{
		return inCreaseDateByOneDecade(*this);
	}


	static	clsDate inCreaseDateByXDecade(short Decade, clsDate& Date)
	{
		for (short i = 1; i <= Decade; i++)
		{
			Date = inCreaseDateByOneDecade(Date);
		}
		return Date;
	}
	clsDate inCreaseDateByXDecade(short Decade)
	{
		return inCreaseDateByXDecade(Decade, *this);
	}

	static	clsDate inCreaseDateByXDecadeFaster(short Decade, clsDate& Date)
	{
		Date._Year += Decade * 10;
		return Date;
	}
	clsDate inCreaseDateByXDecadeFaster(short Decade)
	{
		return inCreaseDateByXDecadeFaster(Decade, *this);
	}
	static	clsDate inCreaseDateByOneCentury(clsDate& Date)
	{

		Date._Year += 100;
		return Date;
	}
	clsDate inCreaseDateByOneCentury()
	{
		return inCreaseDateByOneCentury(*this);
	}
	static	clsDate inCreaseDateByOneMillennium(clsDate& Date)
	{
		Date._Year += 1000;
		return Date;

	}
	clsDate inCreaseDateByOneMillennium()
	{
		return inCreaseDateByOneMillennium(*this);
	}


};

