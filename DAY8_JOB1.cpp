#include<iostream>
#inlclude<cstring>
#include<windows.h>>
using namespace std;
int PY= 2019;
class Emp{
	int eID;
	string name;
	string dept;
	int YoB;
	int YoJ;
	float salary;
	//constructor
	Emp(){;}
	}
	Emp(int a,char b[],string c,int d,int e,float f){
		eID=a;
		name=b[];
		dept=c;
		YoB=d;
		YoJ=e;
		salary=f;
	}
	void show(){
		cout<<"*-----------------------Employee Details-------------------------------*";
		cout<< " eID\t\t eNAME\t\t\t eDEPT\t\t\tYoB\t\t\tYoJ\t\t\tsalary";
		cout<<a\t\t<<b[]\t\t\t<<c\t\t\t<<d\t\t\t<<e\t\t\t<<f;
		
		}
	class Faculty:public Emp{
		string spec;
		Emp q;
		public:
			Faculty(){;}
			Faculty(int a,char b[],string c,int d,int e,float f,string z):q(a,b,c,d,e,f){
				gradepay=z;
			}
		//display stuff
		//display stuff
		void show(){
			cout<<"Staff=Faculty\n\n";
			cout<<"Designation = \n"<<qual;
			q.show();
		}
		double money(){
			return (q.salary+gradepay *q.salary*(PY-YoJ));
		}
		//TEACHING ASSISTANT
			//display stuff
		void show(){
			cout<<"Staff=Teaching Assistant\n\n";
			cout<<"Designation = \n"<<qual;
			q.show();
		}
		double money(){
			return ()
		}
		class TA:public Emp{
		string spec;
		Emp q;
		public:
			TA(){;}
			TA(int a,char b[],string c,int d,int e,float f,string z):q(a,b,c,d,e,f){
				qual=z;
			}
				//display stuff
		void show(){
			cout<<"Staff=TA\n\n";
			cout<<"Designation = \n"<<qual;
			q.show();
		}
		double money(){
			return (q.salary+q.salary*(PY -YoJ));
		}
		/////////CLLLLLLERRRRKKKKKKKK-------------------------------
		class clerk:public Emp{
		string GRc;
		Emp q;
		public:
			clerk(){;}
			clerk(int a,char b[],string c,int d,int e,float f,string z):q(a,b,c,d,e,f){
				qual=z;
			}
		//display stuff
		void show(){
			cout<<"Staff=Clerk\n\n";
			cout<<"Designation = \n"<<qual;
			q.show();
		}
		double money(){
			return (q.salary+ 7000*q.salary+(PY-YoJ)*100);
		}
			
	}; 

