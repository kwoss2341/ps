#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int cost[201][201];
int dis[201];
int visit[201];
int vvv[201];
int gn;
int vn; // s와 접근가능한 정점수
vector <int> mymap[201];
#define MY_MAX 100000000;


int govn(int s) // 필요없는 구간 자르기
{
    
    for(int i=1; i<=gn; i++)
    {
       vvv[i]=0; 
    }
    
    int st=s;
    int cnt=0;
    queue <int> q;
    
    q.push(st);
    vvv[st]=1;
    while(!q.empty())
    {
        
        st=q.front();
        cnt++;

        for(int i=0; i<mymap[st].size(); i++)
        {
            if(vvv[mymap[st][i]]==0)
            {
                q.push(mymap[st][i]);
                vvv[mymap[st][i]]=1;
            }
        }
        
        q.pop();
        
    }
    
    return cnt;
}


void dij(int s,int dis[],int a1,int a2,int a3) //다익스트라
{
  
    
    for(int i=0; i<=gn; i++)
    {
       dis[i]=MY_MAX;
       visit[i]=0;
    }
    
    dis[s]=0;
    visit[s]=1;
    for(int i=0; i<mymap[s].size(); i++)
    {
        dis[mymap[s][i]]=cost[s][mymap[s][i]];
    }
    
    int cnt=0;
    while(1)
    {
        if(cnt==vn) break;
        
        s=0;
        for(int i=1; i<=gn; i++)
        {
            if(visit[i]==0&&dis[s]>dis[i])
            {
                s=i;
            }
        }
        
        
        
        visit[s]=1;
        if(visit[a1]*visit[a2]*visit[a3]==1) break;
        
        for(int i=0; i<mymap[s].size(); i++)
        {
            int w=mymap[s][i];
            
            if(visit[w]==0&&dis[w]>dis[s]+cost[s][w])
            {
                dis[w]=dis[s]+cost[s][w];
            }

        }
            
        
        
        cnt++;
    }
    
    
}


//https://programmers.co.kr/learn/courses/30/lessons/72413 
int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;
    gn=n;
    
    
    for(int i=1; i<=n; i++)
    {
        mymap[i].clear();
        for(int j=1; j<=n; j++)
        {
            cost[i][j]=MY_MAX;
        }
    }
    
    for(int i=0; i<fares.size(); i++)
    {
        cost[fares[i][0]][fares[i][1]]=fares[i][2];
        cost[fares[i][1]][fares[i][0]]=fares[i][2];
        
        mymap[fares[i][0]].push_back(fares[i][1]);
        mymap[fares[i][1]].push_back(fares[i][0]);
        
    }
    
    vn=govn(s);
    
    int ato[201];
    int bto[201];
    int sto[201];
    
    
    
    dij(a,ato,a,b,s);
    dij(b,bto,a,b,s);
    dij(s,sto,a,b,s);
    
        
        
    answer=MY_MAX;
    for(int i=1; i<=gn; i++)
    {
        if(vvv[i]!=0 )
        {
            int z=ato[i]+bto[i]+sto[i];
            
            if(z<answer)
            {
                answer=z;
            }
        }
    }
    
    
    
    
    return answer;
}
