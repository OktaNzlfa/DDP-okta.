#include <iostream>
using namespace std;

int main(){
	int a,b;
	cout<<"Masukan jumlah baris \t: ";
	cin>>a;
	cout<<"Masukan jumlah kolom \t: ";
	cin>>b;
	cout<<endl;
	
  for (int c = 0; c < a; c++) {
  	for(int d = 1; d< b; d++){
  		cout<<"|_";
  	    }
  	cout<<"|_|"<<endl;
  }
}
