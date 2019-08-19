#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

class depart{
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
	    student(){	  ;}
	    void roll_search(student s[],int r,int n){
	     	bool flag=true;
	    	for(int i=0;i<s.size();i++){
	    		if(s[i].roll==r){
		    		flag=false;
		    		cout<<"The students with roll "<<r<<" are:\n";
		    		show(s[i]);
		    	}
		    }
	     	if(flag){
	    		cout<<"There is no student with this roll no. in this department.\n";
	     	}
	    }
	    vector<student> dept_search(student s[],string d,int n){
	        student result[100];j=0;
	    	bool flag=true;
	    	for(int i=0;i<n;i++){
		    	if(s[i].dept==d){
		    		flag=false;
			    	cout<<"The students with dept. "<<d<<" are:\n";
			    	show(s[i]);
			    	result[j]=s[i];
					j++	
		    	}
	    	}
	    	if(flag){
		    	cout<<"There is no student with this dept.\n";
	    	}
	    	return result;
    	    }
        void dgpa_search(student s[],float r,int n){
	    	bool flag=true;
	    	for(int i=0;i<n;i++){
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
    	float max_dgpa(student s[],int n){
	    	int j=0;float max=0;
	    	for(int i=0;i<n;i++){
	    		if (s[i]>max){
	    			max = s[i].d;
				}
		    	
	    	}
	    	return max;
        }
        void show(student a){
	    	cout<<"Name= "<<a.name<<"\n";
		    cout<<"Roll= "<<a.roll<<"\n";
	    	cout<<"Dept.= "<<a.dept<<"\n";	
	    	cout<<"Cgpa1	Cgap2	Cgpa3	Cgpa4\n";
		    cout<<a.c1<<"	"<<a.c2<<"	"<<a.c3<<"	"<<a.c4<<"	\n";
		    cout<<"Dgpa= "<<a.d<<"\n";
     	    }
	public:
		string dname;
	    string hname;
    	student s[100];
    	int n;
		init_dept(string dpt,string hod){
	    	hname=hod;
 	    	dname=dpt;
    	    cout<<"Enter number of students= ";cin>>n;
         	for(int i=0;i<n;i++){
	    	    cout<<i+1<<"th stuent details\n";
	        	cout<<"name= ";
	         	char name[20];
	        	fflush(stdin);
	        	gets(name);
	    	    cout<<"roll= ";
	        	int roll;
	        	cin>>roll;
	        	cout<<"cgpa1,cgpa2,cgpa3,cgpa4\n";
		        float c1,c2,c3,c4;
		        cin>>c1>>c2>>c3>>c4;
		        s[i].init_student(name,roll,this->dname,c1,c2,c3,c4);
    	    }
     	}
	    depart(){  	;}
	    void display(s[]){
	    	for(int i=0;i<s.size();i++){
	    			s[i].show(s[i]);
	    		}
		}
		void search_roll(s[],int r){
			cout<<"Searching roll no in ">>dname>>" department\n";
			roll_search(s,r);
		}
		void dept_top(s[]){
			float k=temp.max_dgpa(s);
			s[0].dgpa_search(s,k,this->n);
		}
    	
		
};
int main(void){
	depart de[3];
	string dn,hn;
	int i=0,j=0,n=0;
	for (i=0;i<3;i++){
		cout<<"dept. name= ";
		fflush(stdin);
		gets(dn);
		cout<<"dept. hod= ";
		fflush(stdin);
		gets(hn);
		int n;
    	cout<<"Enter number of students= ";cin>>n;
		de[i].init_dept(dn,hn,n);
	}
	cout<<"Options:\nSearch by roll(1)\ndept. topper(2)\n\n";
	while(1){
		int choice;
		cin>>choice;
		if(!choice){
			exit(0);
		}
		if(choice==1){
			cout<<"Enter roll= ";int r;cin>>r;
			for(int u=0;i<3;i++){
				de[i].search_roll(de[i].s,r);
			}
		}
		else if(choice==2){
			cout<<"Enter dept.= ";string r;cin>>r;
			for (int i=0;i<3;i++){
				if(de[i].dname==r){
					de[i].dept_top(de[i].s,r);
				}
			}
		}
	}
}
