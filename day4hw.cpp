#include <iostream> 
using namespace std; 
int value(string test)
{
    int n=test.size();
    int c=0,len =1,max_len=0;
    int pref[n];
    int start=0,end=0;
        vector< pair<int,int> > result;
    pref[0]=(int)test[0];
    for(int i=1;i<=n;i++)
    {
        pref[i]=pref[i-1]+(int)test[i];
        
    }

    while(c<test.size() -1){
        if((test[c+1]-test[c])==1)
        {
            end++;
            c++;
        }
        else{
            end = c;
            if(start == 0){
                result.push_back(make_pair(end+1,pref[end]));
                else 
                result.push_back(make_pair(end-start+1,pref[end]-pref[start-1]));
            }
            c++;
            start=c;
            end=c;
        }
        if(start == 0){
                result.push_back(make_pair(end+1,pref[end]));
                else 
                result.push_back(make_pair(end-start+1,pref[end]-pref[start-1]));
            
        }
       // sum=sum+(int)
       //decreasing sequence
    while(c<test.size() -1){
        if((test[c]-test[c+1])==1)
        {
            end++;
            c++;
        }
        else{
            end = c;
            if(start == 0){
                result.push_back(make_pair(end+1,pref[end]));
                else 
                result.push_back(make_pair(end-start+1,pref[end]-pref[start-1]));
            }
            c++;
            start=c;
            end=c;

        }
        if(start == 0){
                result.push_back(make_pair(end+1,pref[end]));
                else 
                result.push_back(make_pair(end-start+1,pref[end]-pref[start-1]));
            }
}

//------ 2nd part

return *max_element(result.begin(),result_end().second)
}
int main(int argc, char** argv) 
{ 
   string test =argv[1];
   cout<<value(test)<<endl;
   return(0);
        
    }