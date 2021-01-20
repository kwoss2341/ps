#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

//https://programmers.co.kr/learn/courses/30/lessons/17676
int solution(vector<string> lines) {
    int answer = 0;
    
    vector < vector <int> > sch;
    
    string str;
  
    int mst,mfi;
    for(int i=0; i<lines.size(); i++)
    {
        mst=0;
        mfi=0;
        
        mfi+=stoi(lines[i].substr(11,2))*3600000; //완료시간
        mfi+=stoi(lines[i].substr(14,2))*60000;   
        mfi+=stoi(lines[i].substr(17,2))*1000;
        mfi+=stoi(lines[i].substr(20,3));
        
        mst=mfi-(int)((stod(lines[i].substr(24)))*1000-1); //시작시간
        mfi++;
        
        vector<int> t1,t2,t3;
        t1.push_back(mst);
        t1.push_back(0);
        
        t2.push_back(mfi);
        t2.push_back(1);
        
        
        sch.push_back(t1);
        sch.push_back(t2);
        
    }
    
    sort(sch.begin(),sch.end());
  
    
   
 
    int myst=-100000;
    int cnt=0;
    
    for(int i=0; i<sch.size(); i++)
    {
        if(myst==sch[i][0])
        {
            
            if(sch[i][1]==0)
            {
                cnt++;
            }
            else
            {
                cnt--;
            }
        }
        else
        {
            int ccnt=0;
            int sc=sch[i][0];
            if(sch[i][1]==1) sc--;
            for(int j=i; j<sch.size(); j++)
            {
                if(sch[j][0]-sc>=1000) 
                {
                   break; 
                }
                    
                if(sch[j][1]==0)
                {
                    ccnt++;
                }
            }
            
            if(cnt+ccnt>answer)
            {
                answer=cnt+ccnt;
            }
            
         
            myst=sch[i][0];
            if(sch[i][1]==0)
            {
                cnt++;
            }
            else
            {
                cnt--;
            }
        }
      
    }
    
   
    
    return answer;
}
