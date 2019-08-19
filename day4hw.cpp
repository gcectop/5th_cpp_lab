#include <bits/stdc++.h>

using namespace std;


int value(string test){
	int n=test.size();
	int c=0;
	//int sum=0;
	//int len=1;
	vector<pair<int,int>> result; 
	int pref[n];
	pref[0]=(int)test[0];
	for(int i=1;i<n;i++){
		pref[i]=pref[i-1]+(int)test[i];
	}
	/*cout<<"prefix= "<<endl;
	for(auto x:pref){
		cout<<x<<" ";
	}*/
	//cout<<endl;
	int start=0;
	int end=0;
	//increasing sequence like 1 2 3 4 5 
	while(c<n-1){
		if((test[c+1]-test[c])==1){
			end++;
			c++;
		}
		else{
			end=c;
			if(start==0){
				result.push_back(make_pair(end+1,pref[end]));
			}
			else{
				result.push_back(make_pair(end-start+1,pref[end]-pref[start-1]));
			}
			c++;
			start=c;
			end=c;
		}
	}
	if(start==0){
		result.push_back(make_pair(end+1,pref[end]));
	}
	else{
		result.push_back(make_pair(end-start+1,pref[end]-pref[start-1]));
	}
	// decreasing sequence 5 4 3 2 1 
	c=0;
	start=0;
	end=0;
	while(c<test.size()-1){
		if((test[c]-test[c+1])==1){
			end++;
			c++;
		}
		else{
			end=c;
			if(start==0){
				result.push_back(make_pair(end+1,pref[end]));
			}
			else{
				result.push_back(make_pair(end-start+1,pref[end]-pref[start-1]));
			}
			c++;
			start=c;
			end=c;
		}
	}
	if(start==0){
		result.push_back(make_pair(end+1,pref[end]));
	}
	else{
		result.push_back(make_pair(end-start+1,pref[end]-pref[start-1]));
	}
	pair<int,int> ans=*(max_element(result.begin(),result.end()));
/*	cout<<"Result= "<<endl;
	for(auto x:result){
		cout<<x.first<<" "<<x.second<<"\n";
	}*/
	return ans.second;
}


vector<int> search(string test,string pattern){
	vector<int> result;
	auto found=test.find(pattern);
	while(found!=string::npos){
		result.push_back(found);
		found=test.find(pattern,found+1);
	}
	return result;
}

int main(int argc,char** argv){
	string test;
	string pattern;
	test=argv[1];
	pattern=argv[2];
	cout<<"Sum of Maximum Consecutive Pattern: "<<value(test)<<endl;
	vector<int> result=search(test,pattern);
	cout<<"Positions of Substring= ";
	for(int i=0;i<result.size();i++){
		cout<<result[i]<<" ";
	}
	cout<<endl;
	return 0;
}
