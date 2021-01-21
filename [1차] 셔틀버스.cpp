#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

//https://programmers.co.kr/learn/courses/30/lessons/17678
string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    int ia;
    int s=timetable.size();
    vector <int> crew;
    
    for(int i=0; i<s; i++)
    {
        crew.push_back(stoi(timetable[i].substr(0,2))*60+stoi(timetable[i].substr(3,2)));
    }
    
    sort(crew.begin(), crew.end());
    
    
    vector <int> last;
    int sttime=9*60;
    int st=0;
    for(int i=0; i<n; i++)
    {
        
       
       for(int j=0; j<m; j++)
       {
          if(st>s-1) break; 
           
          if(crew[st]<=sttime)
          {
              if(i==n-1)
              {
                  last.push_back(crew[st]);
              }
              st++;
          }
          else
          {
              break;
          }
       }
       
       if(i==n-1)
       {
           if(last.size()<m)
           {
               ia=sttime;
           }
           else
           {
               ia=last[last.size()-1]-1;
           }
       }
       
       sttime+=t; 
    }
    
    if(ia/60<10)
    {
        answer="0"+to_string(ia/60);
    }
    else
    {
        answer=to_string(ia/60);
    }
    
    answer+=":";
    
    if(ia%60<10)
    {
        answer+="0"+to_string(ia%60);
    }
    else
    {
        answer+=to_string(ia%60);
    }
    
    return answer;
}
