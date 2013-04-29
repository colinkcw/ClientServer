#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;
int main(){
	char c,x;
	int w,m;
	double n;
	cout<<setfill(' ');
	while(cin>>w>>c>>m){
		//cout << setw(abs(w)) << (w < 0 ? left : right);
		if(w>0)
			cout<<setw(abs(w))<<left;
		else
			cout<<setw(abs(w))<<right;
		if(c == 'd')
			cout<< fixed << noshowpos<<m<<"|";
		else if(c== 'o')
			cout<< oct<< fixed << noshowpos <<m<<"|";
		else if(c=='x')
			cout<<hex << fixed << noshowpos <<m<<"|";
		else if(c=='X')
			cout<< hex<< uppercase<<fixed << noshowpos <<m<<"|";
		else if(cin>>x>>n){
			if(x == 'f')
				cout<<fixed<<setprecision(m)<<n<<"|";
			if(x == 'e')
				cout<<noshowpoint<<scientific<<setprecision(m)<<n<<"|";
			if(x == 'E')
				cout<<scientific<<setprecision(m)<<uppercase<<n<<"|";
		}
	}
}