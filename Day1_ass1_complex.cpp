#include <iostream>
using namespace std;

class complex{
	int real;
	int im;
public:
	complex(int r,int i){
		real=r;
		im=i;
	}
	complex addition(complex a,complex b){
	    complex result(0,0);
     	result.real=a.real+b.real;
     	result.im=a.im+b.im;
     	return result;
    }
	complex substraction(complex a,complex b){
	    complex result(0,0);
     	result.real=a.real-b.real;
     	result.im=a.im-b.im;
     	return result;
    }
    void compare(complex a,complex b){
    	if((a.real+a.im>(b.real+b.im))){
    		cout<<"The big number is= ";
    		a.show();cout<<"\n";
		}
		else if((a.real+a.im<(b.real+b.im))){
    		cout<<"The big number is= ";
    		b.show();cout<<"\n";			
		}
		else{
			cout<<"both ";
			a.show();cout<<" ";
			b.show();cout<<" are equal\n";
		}
	}
	void show(){
		cout<<real<<" + i("<<im<<")";
	}
	void input(){
		cout<<"Enter Real Part= ";
		cin>>real;
		cout<<"Enter Imaginary Part= "; 
		cin>>im;
	}
};


int main(){
	cout<<"Options:\nAddition(1)\nSubstraction(2)\nCompare(3)\nExit(0)\n";
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
	}
	return 0;	
}
