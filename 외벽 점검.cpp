#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool comp(int a, int b) {
    return a > b;
}



//https://programmers.co.kr/learn/courses/30/lessons/60062
int solution(int n, vector<int> weak, vector<int> dist) {
    
    int answer =10000;
    int ws = weak.size();
    int ds = dist.size();
    sort(dist.begin(),dist.end(),comp);
    for(int i=0; i<ws; i++) weak.push_back(n+weak[i]);
    
    
    int std,stdist,cn,total,sw;
        
    for(int stw=0; stw<ws; stw++)
    {

        while(1)
        {
         
            std=0;
            stdist=dist[0];
            cn=0;
            total=0;
            sw=0;
            for(int i=stw; i<ws+stw; i++)
            {
                
                if(cn==0)
                {
                    cn++;
                    continue;
                }
                
                if(stdist-(weak[i]-weak[i-1])<0)
                {
                    i--;
                    cn=0;
                    total++;
                    if(total+1>=answer||total==ds) 
                    {
                        sw=1;
                        break;
                    }   
                    std++;
                    stdist=dist[std];
                }
                else
                {
                    cn++;
                    stdist=stdist-(weak[i]-weak[i-1]);
                }
                
            }
            
            
            if(sw==0&&answer>total+1)
            {
                answer=total+1;
            }
            
            if(!prev_permutation(dist.begin(),dist.end()))
            {
                break;
            }
        }
        
        
    }
    
    
   if(answer==10000) answer=-1;
    
    return answer;
}
