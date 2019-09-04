#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
int n =0; 
class B;
class A
{
    private:
        int x;
    public:
    A(){;}
    void setdata(int z)
    {
        x=z;
    }
    friend int sum(A a1[], B b1[]);
};
class B
{
    private:
        int y;
    public:
    B(){;}
    void setdata(int z)
    {
        y=z;
    }
    friend int sum(A a1[], B b1[]);
};
int sum(A a1[],B b1[])
{
    int c[n];
    for(int i=0; i<n;i++) /////////a
    {
        int key=a1[i].x;
        int count=0;
        for(int p =0; p<n; p++) ////b
        {
           if (b1[p].y == key)
           {
               count ++;
           }
           
        }
        c[i]= count;
    }
    ///////for loop ends--------
    //maxcount for a
    int y=c[0];
    for(int d=1; d<n;d++)
    {
        if( c[d] >= y )
        {
            y=c[d];
        }

    }
    //y holds max
    //max find ends
   // int maxine=-1;
    vector<int> moon;
    for(int r=0; r<n;r++)
    {
        if (c[r]== y)
        {
            moon.push_back(a1[r].x);       
        }
    }
    ///moon aray input ends
    int moon_max = *max_element(moon.begin(),moon.end());
    return y*moon_max;
}

int main(void)
{
   // int n;
    cout<<"Enter size of arrays: \t \n";
    cin>>n;
	int i,j=1;
	int arr1[n];
		cout<<"Enter " << n << "elements\n";
	for(i=0;i<n;i++)
	{
        cout<< i<< endl;
		cin>>arr1[i];
	    for(j=0;j<i;j++)
	    {
		    if(arr1[j]!=arr1[i]){;}
		
		    else
		    {
                cout<<"No duplicates allowed\n Enter some other number\n";
		        i--;
		    break;
		    }
	    }
		
	}
	//if(n==10);
	//break;
	//}
    A a1[n];
    B b1[n];


    for(i=0;i<n;i++)
        {
	            a1[i].setdata(arr1[i]);
        }  
    int temp;
    cout<<"Enter B array \n";
    for(i=0;i<n;i++)
        {
           // cout<<enter<<i << element;
                cin>> temp;  ///input temp
	            b1[i].setdata(temp);
        } 
    cout<< sum(a1,b1)<<endl;
    return 0;
    
}