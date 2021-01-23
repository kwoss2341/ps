#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct myfile
{
    string head;
    int num;
    string tail;
    int ind;
};

int cmpbigs(string a, string b)
{
    int n=min(a.length(),b.length());
    
    int sw=0;
    for(int i=0; i<n; i++)
    {
        if(a[i]>b[i])
        {
            return 0;
        }
        else if(a[i]<b[i])
        {
            return 1;   
        }
    }
    
    if(a.length()==b.length())
    {
        return 2;
    }
    else if(a.length()<b.length())
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}

bool cmp(myfile p1,myfile p2)
{
    int i=cmpbigs(p1.head,p2.head);
    
    if(i==2)
    {
        if(p1.num>p2.num)
        {
            return 0;
        }
        else if(p1.num<p2.num)
        {
            return 1;
        }
        else
        {
            if(p1.ind>p2.ind)
            {
                return 0;
            }
            else
            {
                return 1;
            }
        }
    }
    else
    {
        return i;
    }
}

bool ischar(char c)
{
    return c>96&&c<123;
}

bool isnum(char c)
{
    return c>47&&c<58;
}

void mypush(myfile m[],string str,int ind)
{
    int i,j,k;
    for(i=0; i<str.length(); i++)
    {
        if(isnum(str[i]))
        {
            break;
        }
    }
    m[ind].head=str.substr(0,i);
   
    for(j=i; i<str.length(); j++)
    {
        if(!isnum(str[j]))
        {
            break;
        }
    }
    m[ind].num=stoi(str.substr(i,j-i));
    m[ind].tail=str.substr(j);
    m[ind].ind=ind;
    
    transform(m[ind].head.begin(), m[ind].head.end(), m[ind].head.begin(), ::tolower);
  
    return;
}

//https://programmers.co.kr/learn/courses/30/lessons/17686
vector<string> solution(vector<string> files) {
    vector<string> answer;
    int n=files.size();
    
    myfile m[n];
    
    for(int i=0; i<n; i++)
    {
        mypush(m,files[i],i);
    }
    
    sort(m,m+n,cmp);
    
    for(int i=0; i<n; i++)
    {
        answer.push_back(files[m[i].ind]);
    }
    
    
    return answer;
}
