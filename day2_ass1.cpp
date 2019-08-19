#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

class student{
	string name;
	int roll;
	string dept;
	float c1,c2,c3,c4,d;
public:
	init_student(char n[],int r,string dpt,float cg1,float cg2,float cg3,float cg4){
		string b(n);

		name=n;
		roll=r;
		dept=dpt;
		c1=cg1;
		c2=cg2;
		c3=cg3;
		c4=cg4;
		d=(float)((c1+c2+c3+c4)/(4.0));
	}
	student(){
		;
	}
	void roll_search(vector<student> s,int r){
		bool flag=true;
		for(int i=0;i<s.size();i++){
			if(s[i].roll==r){
				flag=false;
				cout<<"The students with roll "<<r<<" are:\n";
				show(s[i]);
			}
		}
		if(flag){
			cout<<"There is no student with this roll no.\n";
		}
	}
	vector<student> dept_search(vector<student> s,string d){
		vector<student> result;
		bool flag=true;
		for(int i=0;i<s.size();i++){
			if(s[i].dept==d){
				flag=false;
				cout<<"The students with dept. "<<d<<" are:\n";
				show(s[i]);
				result.push_back(s[i]);	
			}
		}
		if(flag){
			cout<<"There is no student with this dept.\n";
		}
		return result;
	}
	void dgpa_search(vector<student> s,float r){
		bool flag=true;
		for(int i=0;i<s.size();i++){
			if(s[i].d>=r){
				flag=false;
				cout<<"The students with dgpa >= "<<r<<" are:\n";
				show(s[i]);
			}
		}
		if(flag){
			cout<<"I think it is only you\n";
		}
	}
	float max_dgpa(vector<student> s){
		vector<float> dgpa;
		for(int i=0;i<s.size();i++){
			dgpa.push_back(s[i].d);
		}
		return *max_element(dgpa.begin(),dgpa.end());
	}
	void show(student a){
		cout<<"Name= "<<a.name<<"\n";
		cout<<"Roll= "<<a.roll<<"\n";
		cout<<"Dept.= "<<a.dept<<"\n";	
		cout<<"Cgpa1	Cgap2	Cgpa3	Cgpa4\n";
		cout<<a.c1<<"	"<<a.c2<<"	"<<a.c3<<"	"<<a.c4<<"	\n";
		cout<<"Dgpa= "<<a.d<<"\n";
	}
};

int main(){
	student temp;
	int n;
	cout<<"Enter number of students= ";cin>>n;
	vector<student> s(n);
	for(int i=0;i<n;i++){
		cout<<i+1<<"th stuent details\n";
		cout<<"name= ";
		char name[20];
		fflush(stdin);
		gets(name);
		cout<<"roll= ";
		int roll;
		cin>>roll;
		cout<<"dept.= ";
		string dept;
		cin>>dept;

		cout<<"cgpa1,cgpa2,cgpa3,cgpa4\n";
		float c1,c2,c3,c4;
		cin>>c1>>c2>>c3>>c4;
		s[i].init_student(name,roll,dept,c1,c2,c3,c4);
	}
	cout<<"Options:\nSearch by roll(1)\nSearch by dept.(2)\nDGPA wise students(3)\nTopper(4)\nTopper_Specific(5)\n";
	while(1){
		int choice;
		cin>>choice;
		if(!choice){
			exit(0);
		}
		if(choice==1){
			cout<<"Enter roll= ";int r;cin>>r;
			temp.roll_search(s,r);
		}
		else if(choice==2){
			cout<<"Enter dept.= ";string r;cin>>r;
			temp.dept_search(s,r);
		}
		else if(choice==3){
			cout<<"Enter DGPA= ";float d;cin>>d;
			temp.dgpa_search(s,d);
		}
		else if(choice==4){
			cout<<"Toppers of CSE dept. are= \n";
			vector<student> a=dept_search(s,"CSE");
			float m=max_dgpa(a);
			dgpa_search(a,m);
			cout<<"Toppers of IT dept. are= \n";
			a=dept_search(s,"IT");
			m=max_dgpa(a);
			dgpa_search(a,m);
			cout<<"Toppers of CT dept. are= \n";
			a=dept_search(s,"CT");
			m=max_dgpa(a);
			dgpa_search(a,m);
		}
		else if(choice==5){
			cout<<"Enter dept.= ";string r;cin>>r;
			cout<<"Toppers of "<<r<<" are= \n";
			vector<student> a=dept_search(s,r);
			float m=max_dgpa(a);
			dgpa_search(a,m);
		}
	}
	return 0;
	
}
