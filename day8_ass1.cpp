#include <stdio.h>
#include <iostream>
#include <string.h>
#include <windows.h>
#include <bits/stdc++.h>

using namespace std;

class Emp{
public:
	string emp_id;
	string emp_name;
	string dept;
	int yob;
	int yoj;
	double basic;
	Emp(){;}
	
	Emp(string a,char b[],string c,int d,int e,double f){
		emp_id=a;
		string temp(b);
		emp_name=b;
		dept=c;
		yob=d;
		yoj=e;
		basic=f;
	}
	void show(){
		cout<<"___________________Employee Details______________________ \n\n";
		cout<<"ID    NAME    DEPARTMENT    YoB    YOJ    BASIC\n\n";
		cout<<emp_id<<"    "<<emp_name<<"    "<<dept<<"    "<<yob<<"    "<<yoj<<"    "<<basic<<"\n\n";		
	}	
};

class TA:public Emp{
public:
	string qual;
	Emp q;
public:
	TA(){
		;
	}
	TA(string a,char b[],string c,int d,int e,double f,string z): q(a,b,c,d,e,f) {qual=z;}
	
	void show(){
		cout<<"Staff = Technical Assistant\n\n";
		cout<<"Qualification = \n"<<qual;
		q.show();
	}
	
	double salary(){
		return q.basic+q.basic*(2019-q.yoj);	
	}
};

class Faculty:public Emp{
public:
	int gp;
	string spec;
	Emp q;

	Faculty(){
		;
	}
	Faculty(string a,char b[],string c,int d,int e,double f,string z,int zz): q(a,b,c,d,e,f) {spec=z;gp=zz;}
	
	void show(){
		cout<<"Staff = Faculty\n\n";
		cout<<"Specialization = \n"<<spec;
		q.show();
	}
	
	double salary(){
		return q.basic+q.basic*(2019-q.yoj)*gp;	
	}
};

class Clark:public Emp{
public:
	string qual;
	Emp q;
public:
	Clark(){
		;
	}
	Clark(string a,char b[],string c,int d,int e,double f,string z): q(a,b,c,d,e,f) {qual=z;}
	
	void show(){
		cout<<"Staff = Clerk\n\n";
		cout<<"Designation = \n"<<qual;
		q.show();
	}
	
	double salary(){
		return q.basic+7000*q.basic+100*(2019-q.yoj);	
	}
};


int main(){
	while(1){
		cout<<"What do you want?\n(1)Entry Data\n(2)Show Data\n";
		int choke;
		cin>>choke;
		vector<TA>  t;
		vector<Faculty> f;
		vector<Clark> c;
		if(choke==1){
		system("clear");	
		cout<<"Enter type of staff\n";
		cout<<"<1> Technical Assistant\n<2> Faculty\n<3> Clerk\n";
		int choice;
		cin>>choice;
		system("clear");
		if(choice == 1){
			string id,dept,spec;
			int yob,yoj;
			double basic;
			char name[100];
			cout<<"Enter ID= ";cin>>id;
			cout<<"Enter Name= ";cin>>name;
			cout<<"Enter Department= ";cin>>dept;
			cout<<"Enter year of birth= ";cin>>yob;
			cout<<"Enter year of joining = ";cin>>yoj;
			cout<<"Enter basic= ";cin>>basic;
			cout<<"Enter qualification= ";cin>>spec;
			TA temp(id,name,dept,yob,yoj,basic,spec);
			t.push_back(temp);
		}
		else if(choice == 2){
			string id,dept,spec;
			int yob,yoj,gp;
			double basic;
			char name[100];
			cout<<"Enter ID= ";cin>>id;
			cout<<"Enter Name= ";cin>>name;
			cout<<"Enter Department= ";cin>>dept;
			cout<<"Enter year of birth= ";cin>>yob;
			cout<<"Enter year of joining = ";cin>>yoj;
			cout<<"Enter basic= ";cin>>basic;
			cout<<"Enter specialization= ";cin>>spec;
			cout<<"Enter gp= ";cin>>gp;
			Faculty temp(id,name,dept,yob,yoj,basic,spec,gp);
			f.push_back(temp);
		}
		else if(choice==3){
			string id,dept,spec;
			int yob,yoj;
			double basic;
			char name[100];
			cout<<"Enter ID= ";cin>>id;
			cout<<"Enter Name= ";cin>>name;
			cout<<"Enter Department= ";cin>>dept;
			cout<<"Enter year of birth= ";cin>>yob;
			cout<<"Enter year of joining = ";cin>>yoj;
			cout<<"Enter basic= ";cin>>basic;
			cout<<"Enter designation= ";cin>>spec;
			Clark temp(id,name,dept,yob,yoj,basic,spec);
			c.push_back(temp);
		}
	}
	else if(choke==2){
		system("clear");	
		cout<<"Enter type of query\n";
		cout<<"<1> TA with B.SC\n<2> Faculty with DBMS\n<3> Clerk with Salary\n<4>Employee Details\n";
		int choice;
		cin>>choice;
		if(choice==1){
			for(int i=0;i<t.size();i++){
				if(t[i].qual=="B.SC"){
					t[i].show();
				}
			}
		}
		else if(choice==2){
			for(int i=0;i<f.size();i++){
				if(f[i].spec=="DBMS"){
					f[i].show();
					cout<<"Salary = "<<f[i].salary()<<"\n\n";
				}
			}
		}
		else if(choice==3){
			for(int i=0;i<c.size();i++){
				if(c[i].qual=="C"){
					c[i].show();
					cout<<"Salary = "<<c[i].salary()<<"\n\n";
				}
			}
		}
		else{
			string id;
			cin>>id;
			for(int i=0;i<c.size();i++){
				if(c[i].emp_id==id){
					c[i].show();
					//cout<<"Salary = "<<c[i].salary()<<"\n\n";
				}
			}
			for(int i=0;i<f.size();i++){
				if(f[i].emp_id==id){
					f[i].show();
					//cout<<"Salary = "<<f[i].salary()<<"\n\n";
				}
			}
			for(int i=0;i<t.size();i++){
				if(t[i].emp_id==id){
					t[i].show();
					//cout<<"Salary = "<<f[i].salary()<<"\n\n";
				}
			}
		}
	}
	}
	return 0;
}


