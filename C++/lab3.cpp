#include <iostream>
#include <cstdlib>
#include <sstream>
#include <cstring>
#include <fstream>
#define NAMESIZE	20
using namespace std;
struct Record{
	char firstname[NAMESIZE], lastname[NAMESIZE];
	int score;
};
bool get_valid_int(const string& prompt,int& n,bool (*is_valid)(int)=0);
bool is_valid_int(int n);
int main(int argc, char* argv[]){
	string prompt("enter a valid number");
	int selection  = 0;
	Record rec;
	if (argc != 2){
		cout<<"incorrect usage"<<endl;
		return 1;
	}
	ifstream out(argv[1],ios_base::in|ios_base::binary);
	if(!out){
		cout<<"unable to open"<<argv[2]<<endl;
		return 3;
	}
	
	while (get_valid_int(prompt,selection,is_valid_int)) {
		if(selection > 0){
			out.clear();
			if(!out.seekg(ios::pos_type((selection-1)*sizeof(rec)),ios_base::beg)){
				cout<<"seek fail"<<endl;
				continue;
			}
			if(out.read((char*)&rec,sizeof(rec))){
				cout<<rec.firstname<<" "<<rec.lastname<<" "<<rec.score<<endl;
			}
			
		}
		if(selection < 0){
			out.clear();// like rewind in C
			if(!out.seekg(ios::pos_type(sizeof(rec)*(-selection-1)))){// make search number a doubkle negative or use abs(selection)-1
					cout<<"seek fail"<<endl;
					continue;
				}
			while(out.read((char*)&rec,sizeof(rec))){ // while we can read a record
				cout<<rec.firstname<<" "<<rec.lastname<<" "<<rec.score<<endl;
			}
		}
		if(selection == 0){
			break;
		}
	}	
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
bool is_valid_int(int n){
	int x = abs(n);
	if(isalpha(x))
		return false;
	return true;
}