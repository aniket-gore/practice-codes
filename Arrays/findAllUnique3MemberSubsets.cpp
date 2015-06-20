#include<iostream>
#include<map>

using namespace std;

/*
Given an array, find all unique three-member subsets, with unique being that [0,2,3] and [3,2,0] are the same set. 
Should run in faster than 2^n time
*/
// Time : O(n^3)
/*
int main()
{
    string s = "11223";
    map<char,int> mymap;
    for(int i=0;i<s.length();i++)
    {
        if(mymap.find(s[i])==mymap.end())mymap[s[i]]=1;
        else mymap[s[i]]++;
    }

    char arr[4];
    arr[3]='\0';
    map<char,int>::iterator it1,it2,it3;
    for(it1=mymap.begin();it1!=mymap.end();it1++)
    {
        arr[0]=it1->first;
        (it1->second)--;
        
        it2=it1;
        if(it1->second==0)it2++;
        for(;it2!=mymap.end();it2++)
        {
            //if(it2->second >0)
            arr[1]=it2->first;
            it3=it2;
            if(it2->second==1)it3++;
            for(;it3!=mymap.end();it3++)
            {
                arr[2]=it3->first;
                cout<<arr<<endl;
            }
        }
	}*/
