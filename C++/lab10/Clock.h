#ifndef CLOCK_H
#define CLOCK_H
#include<iomanip>
#include <string>
#include<iostream>
class Clock{
	public:
		explicit Clock(int hour = 0, int min = 0);
		explicit Clock(const std::string& s);
		Clock& operator++();
		Clock	operator++(int);
		
		void print() const;
		friend std::ostream& operator<<(std::ostream& os, Clock& c);
		friend bool operator<(const Clock&lhs, const Clock& rhs);
		friend bool operator==(const Clock& lhs, const Clock& rhs);
		friend bool operator>(const Clock& lhs, const Clock& rhs);
		friend bool operator!= (const Clock& lhs, const Clock& rhs);
		friend bool operator<= (const Clock& lhs, const Clock& rhs);
		friend bool operator>= (const Clock& lhs, const Clock& rhs);
		
		
	private:
		int hour_;
		int min_;
};
inline std::ostream& operator<<(std::ostream& os, Clock& c){
	os<<std::setw(2)<<std::setfill('0')<<c.hour_<<":"<<std::setw(2)<<std::setfill('0')<<c.min_;
	return os;
}
inline bool operator<(const Clock&lhs, const Clock& rhs){
	return lhs.hour_ < rhs.hour_ ||(lhs.hour_ == rhs.hour_ && lhs.min_ < rhs.min_); 
}
inline bool operator<= (const Clock& lhs, const Clock& rhs){
	return ((lhs < rhs) || (lhs == rhs));
}
inline bool operator>(const Clock& lhs, const Clock& rhs){
	return lhs.hour_ > rhs.hour_ ||(lhs.hour_ == rhs.hour_ && lhs.min_ > rhs.min_); 
}
inline bool operator>= (const Clock& lhs, const Clock& rhs){
	return (lhs.hour_ > lhs.min_)  || (rhs == rhs);
}
inline bool operator==(const Clock& lhs, const Clock& rhs){
	return (lhs.hour_ == rhs.hour_ )&& (lhs.min_ == rhs.min_);
}

inline bool operator!= (const Clock& lhs, const Clock& rhs){
	return (lhs.hour_ != lhs.hour_) || (lhs.min_ != rhs.min_);
}

#endif