//Saranya and subrata
#include <bits/stdc++.h>

using namespace std;

int size;
class B;
class A{
	int x;
	public:
		A(){
			;
		}
		void setdata(int a){
			x=a;
		}
	friend int sum(A a1[],B b1[]);
	friend int getdata(A a);

};

class B{
	int y;
	public:
		B(){
			;
		}
		void setdata(int a){
			y=a;
		}
	friend int sum(A a1[],B b1[]);
	friend int getdata(B b);
};
int getdata(A a){
	return a.x;
}
int getdata(B b){
	return b.y;
}

int sum(A a1[],B b1[]){
	//int size=sizeof(a1)/sizeof(A);
	//cout<<size<<endl;
	pair<int,int> count[size];
	for(int i=0;i<size;i++){
		int key=getdata(a1[i]);
		count[i].second=key;
		count[i].first=0;
		for(int j=0;j<size;j++){
			if(getdata(b1[j])==key){
				count[i].first++;
			}
		}
	}
	pair<int,int> max_pair=*max_element(count,count+size);
	//cout<<"Count= \n";
	//for(int i=0;i<size;i++){
	//	cout<<count[i].first<<" "<<count[i].second<<endl;
	//}
	/*cout<<"Beta Result=\n";
	cout<<max_pair.first<<" "<<max_pair.second<<endl;*/
	return max_pair.first*max_pair.second;
}

int main(){
	
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
