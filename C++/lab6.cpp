#include <iostream>
#include <cstdlib>
#include <map>
#include <bitset>
#include <sstream>
#include <vector>
#include <algorithm>
#define N 1000000
using namespace std;
string key(int i);
int main(){
	bitset<N> isprime;
	isprime.set();
	map<string,vector<int> > m;
	map<string,vector<int> >::iterator it;
	map<string,vector<int> >::iterator max;
	vector<int>::iterator st;
	for(size_t i = 2; i*i < N; i++)
		if(isprime[i])
			for(size_t j = 2; j*i<N;j++)
				isprime[j*i] = 0;
				
	for(size_t i = 100000; i < N; i++)
		if(isprime[i])
			m[key(i)].push_back(i);
			//cout<<key(i)<<" "<<i<<endl;
	
	max = m.begin();
	for(it= m.begin(); it!=m.end();++it){
		if(it->second.size() > max->second.size())
			max = it;
	}
	cout<<max->second.size()<<endl;
	for(st=max->second.begin(); st!= max->second.end();++st)
		cout<<it->second.size()<<endl;

}

string key(int i){
	ostringstream oss;
	string s;
	oss<<i;
	s = oss.str();
	sort(s.begin(),s.end());
	return s;
}