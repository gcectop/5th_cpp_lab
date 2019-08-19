#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

class depart{
	string dname;
	string hname;
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
	    	for(int i=0;i<n;i++){
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
	    		if (s[i].d>max){
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
    };
	public:
		student s[100];
        int n;
		init_depart(string dpt,string hod,int n){
	    	hname=hod;
 	    	dname=dpt;
    	    
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
     	};
	    depart(){  	;}
	    void display(int n){
	    	for(int i=0;i<n;i++){
	    			this->s[i].show(s[i]);
	    		}
		}
		void search_roll(int r){
			cout<<"Searching roll no in "<<dname<<" department\n";
			s[0].roll_search(this->s,r,this->n);
		}
		void dept_top(){
			float k=this->s[0].max_dgpa(this->s,this->n);
			this->s[0].dgpa_search(this->s,k,this->n);
		}
    	string deptname(){
    		return this->dname;
		}
		
};
int main(void){
	depart de[3];
	string dn,hn;
	int i=0,j=0,n=0;
	for (i=0;i<3;i++){
		cout<<"dept. name= ";
		fflush(stdin);
		cin>>dn;
		cout<<"dept. hod= ";
		fflush(stdin);
		cin>>hn;
		int n;
    	cout<<"Enter number of students= ";cin>>n;
		de[i].init_depart(dn,hn,n);
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
				de[i].search_roll(r);
			}
		}
		else if(choice==2){
			cout<<"Enter dept.= ";string r;cin>>r;
			for (int i=0;i<3;i++){
				if(de[i].deptname()==r){
					de[i].dept_top();
				}
			}
		}
	}
}
