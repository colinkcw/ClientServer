// Student.h
#ifndef 	STUDENT_H
#define		STUDENT_H
#include 	<string>
#include	<iostream>
class Student {
	public:
		// provide ctor(s)
		explicit Student(const std::string& id,
							const std::string& first,
							const std::string&last);
							
		virtual ~Student() {}
		virtual void display(std::ostream& os) const{
			os<<"ID: "<<id_<<std::endl;
			os<<"Name: "<<firstname_<<" "<<lastname_<<std::endl;
		}
		// see sample output below
		// friend declarations
		friend std::ostream& operator<<(std::ostream& os, const Student& s);

	private:
		std::string id_; // e.g. a11111111
		std::string firstname_, lastname_; // e.g. homer simpson
		// A valid ID must start with the letter `a', followed by 8 digits.
		static bool isValidId(const std::string& id); // check for valid ID
		// A valid first/last name must be non-empty & cannot contain whitespace
		// the same function is used to validate the first & the last name
		static bool isValidName(const std::string& name);
		// additional helper functions if needed
};
#endif
// overloaded operator<< (see sample output) & operator>>