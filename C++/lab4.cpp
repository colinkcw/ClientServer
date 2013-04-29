#include <iostream>
#include <cstdlib>
#include <sstream>
#include <cstring>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

string reverse(const string& s);
string squeeze(const string& s, char c);
string delete_all(const string&s, const string& delim);
vector<string> split(const string&s, const string& delim);

int main(){
	string foo;
	vector<string> vec;
	string test1 = ("heeeeeello");
	foo = reverse(test1);
	cout<<foo<<endl;
	foo = squeeze(test1,'e');
	cout<<foo<<endl;
	cout<<delete_all("hoomnmer simpsoomnn","omn")<<endl;
	vec = split("ab>cd>ef<gh>i","<>");
	print(vec);
}

string reverse(const string& s){

	string::size_type i, j = s.size()-1;
	string new1(s);
	for(i = 0; i < s.size(); i++){
		new1[j] = s[i];
		j--;
	}
	return new1;
}

string squeeze(const string& s, char c){
	string::size_type i, j = 0;
	string new2(s);
	char prev = 0;
	for(i = 0; i < s.size(); i++){
		if(prev == c && s[i] == c){
			prev = s[i];
		}
		else{
			new2[j] = s[i];
			j++;
			prev = s[i];
		}
	}
	new2.erase(j);
	return new2;
}
string delete_all(const string&s, const string& delim){
	string::size_type i, j = 0;
	string new3;
	while((i = s.find(delim,j))!= string::npos){
		new3.append(s,j,i-j);
		j = i + delim.size();
	}
	new3 += s.substr(j);
	return new3;
}
vector<string> split(const string&s, const string& delim){
	vector<string> vec;
	string::size_type i, j = 0;
	for(i = 0; i < s.size(); i++){
		if(s[i] == delim[0] || s[i] == delim[1]){
			vec.insert(j,s+i,s+j);
		}
		j = i + 1;
	}
	return vec;
}