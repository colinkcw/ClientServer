#include "Student.h"
#include "OptionStudent.h"
size_t OptionStudent::count_ = 0;
using namespace std;

Student::Student(const std::string& id,
					const std::string& first,
					const std::string&last):id_(id),firstname_(first),lastname_(last){
						if(!isValidId(id_))
							throw"Student::Student(const string&,const string&, const string&):invalid id";
						if(!isValidName(firstname_))
							throw"Student::Student(const string&,const string&, const string&):invalid name";
						if(!isValidName(lastname_))
							throw"Student::Student(const string&,const string&, const string&):invalid name";
					
					}

ostream& operator<<(std::ostream& os, const Student& s){
	os<<s.id_<<" "<<s.firstname_<<" "<<s.lastname_;
	return os;
}
bool Student::isValidId(const std::string& id){
	if(id.length() != 7 )
		return false;
	if(id.at(0) != 'a')
		return false;
	for(string::size_type i = 1; i < 8; i++)
		if(!isdigit(id.at(i)))
			return false;
	return true;
}
bool Student::isValidName(const std::string& name){
	for(string::size_type i = 0; i < name.length(); i++)
		if(!isalpha(name.at(i)))
			return false;
	return true;
}

OptionStudent::OptionStudent(const std::string& id,
								const std::string& first,
								const std::string& last,
								int term,
								const std::string& option
								):Student(id,first,last),option_(option),term_(term){
	
	if(term < 0 )
		throw"OptionStudent::OptionStudent(const string&,const string&, const string&,int, const string&):invalid term";
	
	count_++;
}
ostream& operator<<(std::ostream& os, const OptionStudent& s){
	os<<(const Student&)s<<" "<<s.term_<<" "<<s.option_;
	return os;
}

int main(){
Student s1("a11111111", "Homer", "Simpson");
cout << s1 << endl; // outputs: a11111111 homer simpson
OptionStudent s2("a22222222", "Monty", "Burns", 3, "IS");
cout << s2 << endl; // outputs: a22222222 monty burns 3 IS
Student s3("AAA", "car2l", "carlson"); // should throw exception
s1.display(cout);
s2.display(cout);
}