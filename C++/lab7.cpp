#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;
struct Grades{
	string				id;
	map<string,int>		scores;
}
int main(){

}
ostream& operator<<(ostream& os, const Grades& grade){
	map<string, int>::const_iterator it;
	os<<grade.id<<endl;
	os<<grade.scores.size()<<endl;
	for(it = grade.scores.begin(); it != grade.scores.end(); ++it){
		os<<it->first<<" "<<it->second<<endl;
	}
	return os;
}
istream& operator>>(istream& is,Grade& grade){
	int size = 0;
	string course;
	int score;
	is>>grade.id;
	if(!is)
		return is;
	is>>size;
	for(int i = 0; i < size; i++){
		is>>course;
		is>>score;
		grade.scores[course]=score;
	}
	return is;
}
struct cmp{
	string  c;
	cmp(string course):course(c){}
	bool operator()(Grade& g1, Grade& g2)const{
		int s1 = g1.scores.find(course) != g1.scores.end() ? g1.scores[course] : -1;
		int s2 = g2.scores.find(course) != g1.scores.end() ? g1.scores[course] : -1;	
		return s1 > s2;
	}
}
struct Stats{
	string c;
	Stats(string course):course(c){}
		
}