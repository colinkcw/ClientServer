#include <iostream>
#include<cstdlib>
#include <sstream>
#include "Clock.h"
using namespace std;
Clock::Clock(int hour, int min):hour_(hour),min_(min){
	if(hour < 0 && hour > 23)
		throw"Clock:Clock(int hour = 0, int min = 0):invalid hour";
	if(min < 0 && min > 59)
		throw"Clock:Clock(int hour = 0, int min = 0):invalid minute";
}

Clock::Clock(const std::string& s){
	istringstream	iss(s);
	int hour = 0;
	int minute = 0;
	char delim =':';
	if(!iss>>hour)
		throw"Clock:Clock(const std::string& s):invalid hour";
	iss.clear();
	if(!iss>>delim)
		throw"Clock:Clock(const std::string& s):invalid delim";
	iss.clear();
	if(!iss>>minute)
		throw"Clock:Clock(const std::string& s):invalid minute";
	if(hour < 0 && hour > 23)
		throw"Clock:Clock(const std::string& s):invalid hour";
	if(minute < 0 && minute > 59)
		throw"Clock:Clock(const std::string& s):invalid minute";
	
	hour_ = hour;
	
	min_ = minute;
	
}
void Clock::print() const
{
	string dayHalf;
	int hour = hour_;
	int min = min_;

	if(hour == 12){
		dayHalf = "PM";
	}
	if(hour == 0){
		dayHalf = "AM";
		hour = 12;
	}
	if(hour < 12 && hour > 0){
		dayHalf = "AM";
	}

	if(hour > 12 && hour < 24)	{
		hour -= 12;
		dayHalf = "PM";
	}
	cout << setw(2) << setfill('0') << hour;
	cout << ':';
	cout << setw(2) << setfill('0') << min;
	cout << dayHalf << endl;
}
Clock& Clock::operator++(){
	if(++min_ > 59){
		min_ = 0;
		if(++hour_ > 23)
			hour_ = 0;
	}
	return *this;
}
Clock Clock::operator++(int){
	Clock tmp(*this);
	++*this;
	return tmp;
}

int main(){
	Clock c(23,59);
	//c++;
	string s = "23:59";
	Clock c2(s);
	cout<<c<<endl;
	cout<<s<<endl;
	if(c2 == c)
		cout<<"c is greater"<<endl;
}