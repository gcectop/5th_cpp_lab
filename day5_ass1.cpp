#include <bits/stdc++.h>
#include <string>

using namespace std;


class student{
	
		int roll;
		string name;
		string dept;
	public:
		student(int r,char n[],string d){
		roll=r;
		string temp(n);
		name=temp;
		dept=d;
		}
		student(){
			;	
		}
		friend class project;

		void show(){
						cout<<"name= "<<name<<"\n";
			cout<<"dept= "<<dept<<"\n";
			cout<<"roll= "<<roll<<"\n";
		}

};

class teacher{
	
		string name;
		string dept;
	public:
		teacher(char n[],string d){
		string temp(n);
		name=temp;
		dept=d;
		}
		teacher(){
		;	
		}
		void show(){
								cout<<"name= "<<name<<"\n";
					cout<<"dept= "<<dept<<"\n";
		}
		friend class project;


};

class project{
	
		string id;
		string name;
		int sem;
		int sroll;
		string tname;
	public:
		project(string i,char n[],int sm,int r,char t[]){
		id=i;
		string temp(n);
		name=temp;
		sem=sm;
		sroll=r;
		string temp1(t);
		tname=temp1;
		}
		project(){
			;
		}
		void show(){
							cout<<"Id: "<<id<<"\n";
				cout<<"Topic: "<<name<<"\n";
				cout<<"Sem: "<<sem<<"\n";
		}
		friend vector<student> query1(string topic,int sm);
		friend vector<teacher> query2(string topic,int sm);
		friend pair<teacher,project> query3(int r,int sm);
};
map<string,project> p;
map<int,student> s;
map<string,teacher> t;
vector<student> query1(string topic,int sm){
	vector<student> result;
	for(map<string,project>::iterator it=p.begin();it!=p.end();it++){
		if(it->second.name==topic && it->second.sem==sm){
			result.push_back(s[it->second.sroll]);
		}
	}
	return result;
}

vector<teacher> query2(string topic,int sm){
	vector<teacher> result;
	for(map<string,project>::iterator it=p.begin();it!=p.end();it++){
		if(it->second.name==topic && it->second.sem==sm){
			result.push_back(t[it->second.tname]);
		}
	}
	return result;
}
pair<teacher,project> query3(int r,int sm){
	for(map<string,project>::iterator it=p.begin();it!=p.end();it++){
		if(it->second.sroll==r && it->second.sem==sm){
			return make_pair(t[it->second.tname],it->second); 
		}
	}
}

int main(){
	int choice;
	while(1){
		cout<<"1.Add data\n2.Retrieve Data\n";
		cin>>choice;
		if(choice==1){
			system("cls");
			cout<<"1.Add Student Details\n2.Add Teacher Details3.Add Project Details\n";
			int choice1;
			cin>>choice1;
			if(choice1==1){
				system("cls");
				int r;
				cout<<"Enter Student Roll: ";cin>>r;
				char name[20];
				cout<<"Enter Student Name: ";fflush(stdin);gets(name);
				string dept;
				cout<<"Enter Department: ";cin>>dept;
				student s1(r,name,dept);
				s[r]=s1;
			}
			else if(choice1==2){
				system("cls");
				char name[20];
				cout<<"Enter Teacher Name: ";fflush(stdin);gets(name);
				string dept;
				cout<<"Enter Department: ";cin>>dept;
				teacher t1(name,dept);
				t[name]=t1;
			}
			else if(choice1==3){
				system("cls");
				string id;
				cout<<"Enter Project ID: ";cin>>id;
				char name[20];
				cout<<"Enter Project Name: ";fflush(stdin);gets(name);
				int sm;
				cout<<"Enter Semester: ";cin>>sm;
				int sroll;
				cout<<"Enter Student Roll: ";cin>>sroll;
				char tname[20];
				cout<<"Enter Teacher Name: ";fflush(stdin);gets(tname);
				project p1(id,name,sm,sroll,tname);
				p[id]=p1;
			}
			else{
				break;
			}	
		}
		else if(choice==2){
			int choice2;
			cout<<"1. Query1\n2. Query2\n3. Query3\n";
			cin>>choice2;
			if(choice2==1){
				vector<student> result;//query1(string topic,int sm);
				char name[20];
				cout<<"Enter Topic= ";fflush(stdin);gets(name);
				string temp(name);
				int sm;
				cout<<"Enter Sem= ";cin>>sm;
				result=query1(temp,sm);
				cout<<"Student working on these projects are\n";
				for(int i=0;i<result.size();i++){
						result[i].show();
				}
				cout<<endl;
			}
			else if(choice2==2){
				vector<teacher> result;//query2(string topic,int sm)
				char name[20];
				cout<<"Enter Topic= ";fflush(stdin);gets(name);
				string temp(name);
				int sm;
				cout<<"Enter Sem= ";cin>>sm;
				result=query2(temp,sm);
				cout<<"Teachers working on these projects are\n";
				for(int i=0;i<result.size();i++){
						result[i].show();
				}
				cout<<endl;
			}
			else if(choice2==3){
				pair<teacher,project> result;//query3(int r,int sm);
				int r;
				cout<<"Enter Student Roll: ";cin>>r;
				int sm;
				cout<<"Enter Sem: ";cin>>sm;
				result=query3(r,sm);
				cout<<"Corredponding Teacher\n";
				result.first.show();
				cout<<endl;
				cout<<"Corresponding Project\n";
				result.second.show();
				cout<<endl;
				cout<<"Corresponding Student\n";
				s[r].show();

				cout<<endl;
			}
			else{
				break;
			}
		}
		else{
			break;
		}
	}
	return 0;
}
