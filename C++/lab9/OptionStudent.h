// OptionStudent.h
#ifndef		OptionStudent_H
#define		OptionStudent_H

#include	"Student.h"
class OptionStudent: public Student {
	public:
		// provide suitable ctors & dtor (see example below)
		explicit OptionStudent(const std::string& id,
								const std::string& first,
								const std::string& last,
								int term,
								const std::string& option
								);
		virtual ~OptionStudent(){count_--;}
		static size_t count() { return count_; }
		virtual void display(std::ostream& os) const{
			Student::display(os);
			os<<"Term: "<<term_<<std::endl;
			os<<"option: "<<option_<<std::endl;
		}// see sample output below
		// friend declarations
		friend std::ostream& operator<<(std::ostream& os, const OptionStudent& s);
	private:
		std::string option_;
		int term_; // 3, 4, ...
 // 1 word, e.g., IS, CS, ...
		static size_t count_; // keep track of the number of option students in existence
};
#endif