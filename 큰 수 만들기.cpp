#include <string>
#include <vector>
#include <iostream>
using namespace std;

int maxfind(int num[],int st,int fi)
{
    int answer=st;
    int maxi=num[st];
    for(int i=st+1; i<=fi; i++)
    {
        if(maxi<num[i])
        {
            maxi=num[i];
            answer=i;
        }
    }
    
    return answer;
}

//https://programmers.co.kr/learn/courses/30/lessons/42883#
string solution(string number, int k) {
    string answer = "";
    int n=number.length();
    
    int num[n];
    for(int i=0; i<n; i++)
    {
         num[i]=(int)number[i]-'0' ;
    }
    
    int st=0;
    int cnt=n-k;
    
    while(1)
    {
        if(n-st==cnt)
        {
            for(int i=st; i<n; i++)
            {
                answer+=number[i];
            }
            break;
        }
        else if(cnt==0)
        {
            break;
        }
        
        st=maxfind(num,st,n-cnt);
        answer+=number[st];
       
        st++;
        cnt--;
    }
    
    return answer;
}
