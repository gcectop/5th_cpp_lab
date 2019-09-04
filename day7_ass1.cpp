#include <iostream>
#include <cmath>

using namespace std;

bool prime(int a){
	a=abs(a);
	if(a==1 || a==0){
		return false;
	}
	for(int i=2;i*i<=a;i++){
		if(a%i==0){
			return false;
		}
	}
	return true;
}

class complex{
	int real,imaginary;
	public:
		complex(){
			;
		}
		void init(int a,int b){
			real=a;
			imaginary=b;
		}
		void show(){
			cout<<"("<<real<<") + i("<<imaginary<<")";
		}
		bool operator >(complex a){
			int one=real+imaginary;
			int two=a.real+a.imaginary;
			if(one>two){
				return true;
			}
			else{
				return false;
			}
		}
		bool operator <(complex a){
			int one=real+imaginary;
			int two=a.real+a.imaginary;
			if(one<two){
				return true;
			}
			else{
				return false;
			}
		}
		complex operator +(complex a){
			complex b;
			b.real=real+a.real;
			b.imaginary=imaginary+a.imaginary;
			return b;
		}
		bool operator ==(complex a){
			if(real==a.real && imaginary==a.imaginary){
				return true;
			}
			else{
				return false;
			}
		}
		complex operator *(int a){
			complex b;
			b.real=a*real;
			b.imaginary=a*imaginary;
			return b;
		}
		bool isPrime(){
			if(prime(real) && prime(imaginary)){
				return true;
			}
			else{
				return false;
			}
		}
		friend int operator +(int b,complex a);
};

int operator +(int b,complex a){
	return  b+a.real+a.imaginary;
}

int main(){
	complex c[10];
	cout<<"Enter 10 elements\n";
	for(int i=0;i<10;i++){
		int a,b;
		cin>>a>>b;
		c[i].init(a,b);
	}
	int mn,mx;
	if(c[0]<(c[1])){
		mn=0;
		mx=1;
	}
	for(int i=2;i<10;i++){
		if(c[i]>(c[mx])){
			mx=i;
		}
		else if(c[i]<(c[mn])){
			mn=i;
		}
	}
	complex z=c[mx]+(c[mn]);
	cout<<"Sum of max and min = ";z.show();cout<<endl;
	complex sum;
	sum.init(0,0);
	for(int i=0;i<10;i++){
		if(c[i].isPrime()){
			sum=sum+(c[i]);
		}
	}
	cout<<"Sum of prime numbers= ";sum.show();cout<<endl;
	//int z=sumlang(0,sum);
	int sm=0;
	for(int i=0;i<10;i++){
		if(c[i].isPrime()){
			sm=sm+(c[i]);
		}
	}
	cout<<"Freind sum= "<<sm<<endl;
	int mx_count=0;
	complex mx_value;
	mx_value.init(INT_MIN,INT_MIN);
	for(int i=0;i<10;i++){
		complex key=c[i];
		int count=0;
		for(int i=0;i<10;i++){
			if(key==c[i]){
				count++;
			}
		}
		if(count>mx_count){
			mx_count=count;
			mx_value=key;
		}
		else if(count==mx_count){
			if(key>mx_value){
				mx_value=key;
			}
		}
	}
	complex b=mx_value*mx_count;
	cout<<"Result= ";b.show();cout<<endl;
	return 0; 
}
