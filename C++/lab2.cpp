#include <iostream>
#include<cstdlib>
#include <sstream>
#include <cstring>
#define NAMESIZE	20
using namespace std;
struct Record{
	char firstname[NAMESIZE], lastname[NAMESIZE];
	int score;
};
bool get_valid_word(const string& prompt,string& word,bool (*is_valid)(const string&)=0);
bool get_valid_int(const string& prompt,int& n,bool (*is_valid)(int)=0);
bool is_valid_word(const string& word);
bool is_valid_int(int n);
int main(){
	string prompt1("enter a valid name"),
		   prompt2("enter a valid last name"),
		   prompt3("enter a valid score"),
		   first,
		   last;
	int score;
	Record rec;
	while(1){
		if(get_valid_word(prompt1,first,is_valid_word)&&
			get_valid_word(prompt2,last,is_valid_word)&&
			get_valid_int(prompt3,score,is_valid_int)){
			
			strcpy(rec.firstname,first.c_str());
			strcpy(rec.lastname,last.c_str());
			rec.score = score;
			cerr.write((char*)&rec,sizeof(rec));
		}
		else
			break;	
	}
}
bool get_valid_word(const string& prompt,string& word,bool (*is_valid)(const string&)){
	string line,name;
	while(1){
		cout<<prompt<<endl;
		if(!getline(cin,line)){
			cin.clear();
			return false;
		}
		istringstream iss(line);
		if(iss>>name)
			if(is_valid(name))
				break;
	}
	word = name;
	return true;
}
bool get_valid_int(const string& prompt,int& n,bool (*is_valid)(int)){
	int score;
	string line;
	while(1){
		cout<<prompt<<endl;
		if(!getline(cin,line)){
			cin.clear();
			return false;
		}
		istringstream iss(line);
		if(iss>>score)
			if(is_valid(score))
				break;
	}
	n = score;
	return true;
}
bool is_valid_word(const string& word){
	string::size_type i;
	if (word.size() >= 20)
		return false;
	for(i = 0; i < word.size(); i++){
		if(!isalpha(word[i]))
			return false;
	}
	return true;
}
bool is_valid_int(int n){
	if(n > 0 && n < 100)
		return true;
	return false;
}