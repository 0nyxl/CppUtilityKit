#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
#include <ctime>
#include <string>
#include <vector>

class ClsDate
{

private:
	
	short _Day;
	short _Month;
	short _Year;


	void _ParseStringDate(string sDate) {

		vector<string>vString;

		string delim = "/";
		size_t pos = 0;
		string sWord;

		while ((pos = sDate.find(delim)) != std::string::npos) {
			sWord = sDate.substr(0, pos);
			vString.push_back(sWord);
			sDate.erase(0, pos + delim.length());
		}
		vString.push_back(sDate);

		_Day = stoi(vString[0]);
		_Month = stoi(vString[1]);
		_Year = stoi(vString[2]);

	}

	void _ConvertDayOfYearToDate(short DayOrderInYear, short Year) {

		_Year = Year;

		short monthsDays[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

		if ((Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0))
			monthsDays[2] = 29;

		short remainingDays = DayOrderInYear;
		short monthCounter = 1;

		while (true)
		{
			if (remainingDays <= monthsDays[monthCounter]) {
				_Day = remainingDays;
				_Month = monthCounter;
				break;
			}

			remainingDays -= monthsDays[monthCounter];
			monthCounter++;
		}
	}

public:
	ClsDate() 
	{
		time_t t = time(0);
		tm* now = localtime(&t);
		_Day = now->tm_mday;
		_Month = now->tm_mon + 1;
		_Year = now->tm_year + 1900;
	};

	ClsDate(string sDate) {
		_ParseStringDate(sDate);
	}

	ClsDate(short Day, short Month, short Year) {
		_Day = Day;
		_Month = Month;
		_Year = Year;
	}

	ClsDate(short DayOrder, short Year) {

		_ConvertDayOfYearToDate(DayOrder, Year);
	}

	void SetDay(short Day) {
		_Day = Day;
	}
	void SetMonth(short Month) {
		_Month = Month;
	}
	void SetYear(short Year) {
		_Year = Year;
	}

	short GetDay() {
		return _Day;
	}

	short GetMonth() {
		return _Month;
	}

	short GetYear() {
		return _Year;
	}


	 void PrintDate() {
		cout << _Day << "/" << _Month << "/" << _Year << endl;
	}
};
