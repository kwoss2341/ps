#include <string>
#include <vector>
#include <queue>

using namespace std;


//https://programmers.co.kr/learn/courses/30/lessons/43162
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    int visit[n];
    vector <int> mycom[n];
    queue<int> q;
    
    for(int i=0; i<n; i++)
    {
        visit[i]=0;
    }
    
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i==j) continue;
            if(computers[i][j]==1)
            {
                mycom[i].push_back(j);
            }
        }
    }
    
    
    int start;
    for(int i=0; i<n; i++)
    {   
        if(visit[i]==1) 
        {
            continue;
        }

        
        start=i;
        while(1)
        {
            visit[start]=1;
            for(int j=0; j<mycom[start].size(); j++)
            {
                if(visit[mycom[start][j]]==1) continue;
                q.push(mycom[start][j]);
            }
            
            if(q.empty()) break;
            
            start=q.front();
            q.pop();
        }
        
        answer++;
    }
    
    
    return answer;
}