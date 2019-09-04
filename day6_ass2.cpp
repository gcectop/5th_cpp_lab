#include <bits/stdc++.h>

using namespace std;
int size;
class B;
class A{
	string x;
	public:
		A(){
			;
		}
		void setdata(string a){
			x=a;
		}
	friend void search(A a1[],B b1[]);
	friend string getdata(A a);

};

class B{
	string y;
	public:
		B(){
			;
		}
		void setdata(string a){
			y=a;
		}
	friend void search(A a1[],B b1[]);
	friend string getdata(B b);
};

string getdata(A a){
	return a.x;
}
string getdata(B b){
	return b.y;
}

void search(A a1[],B b1[])
{
	string newly="";
	for(int i; i <size;i++){
		newly=newly+a1[i].getdata().at(0);
	} 
	for (int i; i<size;i++)
	{
		if(newly==b1[i].getdata()){
			cout<<"\nYes"<<i<<endl;
		}
	}
	
};

int main(void){
	cout<<"Enter N= ";
	cin>>size;
	A a1[size];
	B b1[size];
	cout<<"Enter Distinct Values of A= \n";
	for(int i=0;i<size;i++){
		int x;
		cin>>x;
		bool dstnct=true;
		for(int j=0;j<i;j++){
			if(getdata(a1[j])==x){
				cout<<"Please Enter Ditinct Value!!!\n";
				i--;
				dstnct=false;
				break;	
			}
		}
		if(dstnct){
			a1[i].setdata(x);
		}
	}
	cout<<"Enter values of B= ";
	for(int i=0;i<size;i++){
		int y;
		cin>>y;
		b1[i].setdata(y);
	}
	cout<<"Result= "<<sum(a1,b1)<<endl;
	return 0;
}
