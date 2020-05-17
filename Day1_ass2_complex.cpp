#include <iostream>
#include <vector>
#define pb push_back
using namespace std;

class complex{
	int real;
	int im;
public:
	complex(int r,int i){
		real=r;
		im=i;
	}
	complex(){
		real=0;
		im=0;
	}
	complex addition(complex a,complex b){
	    complex result(0,0);
     	result.real=a.real+b.real;
     	result.im=a.im+b.im;
     	return result;
    }
    complex addition(complex c[],int i,int j){
    	complex temp;
    	return temp.addition(c[i],c[j]);
	}
	complex substraction(complex a,complex b){
	    complex result(0,0);
     	result.real=a.real-b.real;
     	result.im=a.im-b.im;
     	return result;
    }
    int compare(complex a,complex b){
    	if((a.real+a.im>(b.real+b.im))){
    	//	cout<<"The big number is= ";
    	//	a.show();cout<<"\n";
    		return 1;
		}
		else if((a.real+a.im<(b.real+b.im))){
    	//	cout<<"The big number is= ";
    	//	b.show();cout<<"\n";
			return 0;			
		}
		else{
		//	cout<<"both ";
		//	a.show();cout<<" ";
		//	b.show();cout<<" are equal\n";
			return 0;
		}
	}
	void show(){
		cout<<real<<" + i("<<im<<")";
	}
	void input(){
		//cout<<"Enter Real Part= ";
		cin>>real;
		cout<<"Enter Imaginary Part= "; 
		cin>>im;
	}
	pair<int,int> extreme(complex arr[],int n){
		int min,max;
		if(n==1){
			return {0,0};
		}
		if(compare(arr[0],arr[1])){
			min=1;
			max=0;
		}
		else{
			min=0;
			max=1;
		}
		for(int i=2;i<n;i++){
			if(compare(arr[i],arr[max])){
				max=i;
			}
			else{
				if(compare(arr[min],arr[i])){
					min=i;
				}
			}
		}
		return make_pair(max,min);
	}
	void showExtreme(complex arr[],int n){
		pair<int,int> result=extreme(arr,n);
		cout<<"Maximum number is = ";arr[result.first].show();cout<<"\n";
		cout<<"Minimum Number is = ";arr[result.second].show();cout<<"\n";
	}
	
};


int main(){
	/*cout<<"Options:\nAddition(1)\nSubstraction(2)\nCompare(3)\nExit(0)\n";
	while(1){
		complex temp(0,0);
		
		int choice;
		cin>>choice;
		
		complex a(0,0);
		complex b(0,0);
		a.input();
		b.input();
		if(choice==0){
			exit(0);
		}
		else if(choice==1){
			a.show();cout<<" + ";b.show();cout<<" = \n";
			temp.addition(a,b).show();
		}
		else if(choice==2){
			a.show();cout<<" - ";b.show();cout<<" = \n";
			temp.substraction(a,b).show();
		}
		else{
			temp.compare(a,b);
		}
	}*/
	cout<<"Options:\nAddition(1)\nËxtreme(2)\n\nExit(0)\n";
	while(1){
		int choice;
		cin>>choice;
		if(!choice){
			exit(0);
		}
		int n;
		cin>>n;
		vector<complex> c;
		for(int i=0;i<n;i++){
			int x,y;
			cin>>x>>y;
			//scanf("%lld+i(%lld)",&x,&y);
			complex C(x,y);
			c.pb(C);
		}
		if(choice==1){
			int i,j;
			cout<<"Give i and j= ";
			cin>>i>>j;
			complex temp;
			complex result;
			if(i<=j && i>=0 && i<=n-1 && j>=0 && j<=n-1)result=temp.addition(c,i,j);
			else{
				cout<<"Are you drunk?\n";
				continue;
			}
			cout<<"result= ";result.show();cout<<"\n";
		}
		if(choice==2){
			complex temp;
			temp.showExtreme(c,n);
		}
	}
	return 0;	
}
