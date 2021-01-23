#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int n;
int mb[105][105];
int visit[102][102][102][102];

void mypush(int sti,int stj,int bi,int bj,int bang,int cnt,
            queue< pair<int,int> > &qi,
            queue< pair<int,int> > &back,
            queue<int> &b, 
            queue<int> &c)
{
    visit[sti][stj][bi][bj]=1;
    visit[bi][bj][sti][stj]=1;
    qi.push(pair<int,int>(sti,stj));
    back.push(pair<int,int>(bi,bj));
    b.push(bang);
    c.push(cnt);
    
    return;
}    
    


int bbfs()
{
    queue< pair<int,int> > qi;
    queue< pair<int,int> > back;    
    queue<int> b;
    queue<int> c;
 
    for(int i=0; i<n+2; i++)
    {
        for(int j=0; j<n+2; j++)
        {
            for(int k=0; k<n+2; k++)
            {
                for(int r=0; r<n+2; r++)
                {
                    visit[i][j][k][r]=0;
                }
            }
        }
    }
    
    
    int fi=n;
    int sti=1;
    int stj=2;
    int bi=1;
    int bj=1;
    int cnt=0;
    
    int bang=1; //°¡·Î  // -1-> ¼¼·Î
    
    qi.push(pair<int,int>(sti,stj));
    back.push(pair<int,int>(bi,bj));
    b.push(bang);
    c.push(cnt);
    
    visit[sti][stj][bi][bj]=bang;
  
    while(!qi.empty())
    {
        sti=qi.front().first;
        stj=qi.front().second;
        bi=back.front().first;
        bj=back.front().second;
        bang=b.front();
        cnt=c.front();
        
        qi.pop();
        back.pop();
        b.pop();
        c.pop();
        
        
        if((sti==fi&&stj==fi)||((bi==fi&&bj==fi))) 
        {
            break;
        }
        
        if(bang==1)//°¡·Î
        {
           
            if(mb[bi][bj+1]==0&&mb[sti][stj+1]==0&&visit[sti][stj+1][bi][bj+1]==0) //¿À¸¥ÂÊÇÑÄ­
            {
                mypush(sti,stj+1,bi,bj+1,bang,cnt+1,qi,back,b,c);
                mypush(bi,bj+1,sti,stj+1,bang,cnt+1,qi,back,b,c);//
            }
            if(mb[bi][bj-1]==0&&mb[sti][stj-1]==0&&visit[sti][stj-1][bi][bj-1]==0) //¿ÞÂÊÇÑÄ­
            {
                mypush(sti,stj-1,bi,bj-1,bang,cnt+1,qi,back,b,c);
                mypush(bi,bj-1,sti,stj-1,bang,cnt+1,qi,back,b,c);//
            }
            if(mb[sti+1][stj]==0&&mb[bi+1][bj]==0&&visit[sti+1][stj][bi+1][bj]==0)//¹ØÇÑÄ­
            {
                mypush(sti+1,stj,bi+1,bj,bang,cnt+1,qi,back,b,c);
                mypush(bi+1,bj,sti+1,stj,bang,cnt+1,qi,back,b,c);//
            }
            if(mb[sti-1][stj]==0&&mb[bi-1][bj]==0&&visit[sti-1][stj][bi-1][bj]==0)//À§ÇÑÄ­
            {
                mypush(sti-1,stj,bi-1,bj,bang,cnt+1,qi,back,b,c);
                mypush(bi-1,bj,sti-1,stj,bang,cnt+1,qi,back,b,c);//
            }
            if(mb[bi+1][bj]==0&&mb[sti+1][stj]==0&&visit[sti+1][stj][sti][stj]==0) //¹Ø
            {
                mypush(sti+1,stj,sti,stj,bang*-1,cnt+1,qi,back,b,c);
                mypush(bi+1,bj,bi,bj,bang*-1,cnt+1,qi,back,b,c);
            }
            if(mb[bi-1][bj]==0&&mb[sti-1][stj]==0&&visit[sti-1][stj][sti][stj]==0) //À§
            {
                mypush(sti-1,stj,sti,stj,bang*-1,cnt+1,qi,back,b,c);
                mypush(bi-1,bj,bi,bj,bang*-1,cnt+1,qi,back,b,c);
            }
            
            
        }
        else//¼¼·Î
        {
            if(mb[sti][stj+1]==0&&mb[bi][bj+1]==0&&visit[sti][stj+1][bi][bj+1]==0)//¿À¸¥ÂÊÇÑÄ­
            {
                mypush(sti,stj+1,bi,bj+1,bang,cnt+1,qi,back,b,c);
                mypush(bi,bj+1,sti,stj+1,bang,cnt+1,qi,back,b,c);//
            }
            if(mb[sti][stj-1]==0&&mb[bi][bj-1]==0&&visit[sti][stj-1][bi][bj-1]==0)//¿ÞÂÊÇÑÄ­
            {
                mypush(sti,stj-1,bi,bj-1,bang,cnt+1,qi,back,b,c);
                mypush(bi,bj-1,sti,stj-1,bang,cnt+1,qi,back,b,c);//
            }
            if(mb[bi+1][bj]==0&&mb[sti+1][stj]==0&&visit[sti+1][stj][bi+1][bj]==0) //¹ØÇÑÄ­
            {
                mypush(sti+1,stj,bi+1,bj,bang,cnt+1,qi,back,b,c);
                mypush(bi+1,bj,sti+1,stj,bang,cnt+1,qi,back,b,c);//
            }
            if(mb[bi-1][bj]==0&&mb[sti-1][stj]==0&&visit[sti-1][stj][bi-1][bj]==0) //À§ÇÑÄ­
            {
                mypush(sti-1,stj,bi-1,bj,bang,cnt+1,qi,back,b,c);
                mypush(bi-1,bj,sti-1,stj,bang,cnt+1,qi,back,b,c);//
            }
            if(mb[bi][bj+1]==0&&mb[sti][stj+1]==0&&visit[sti][stj+1][sti][stj]==0) //¿À
            {
                mypush(sti,stj+1,sti,stj,bang*-1,cnt+1,qi,back,b,c);
                mypush(bi,bj+1,bi,bj,bang*-1,cnt+1,qi,back,b,c);
            }
            if(mb[bi][bj-1]==0&&mb[sti][stj-1]==0&&visit[sti][stj-1][sti][stj]==0) //¿Þ
            {
                mypush(sti,stj-1,sti,stj,bang*-1,cnt+1,qi,back,b,c);
                mypush(bi,bj-1,bi,bj,bang*-1,cnt+1,qi,back,b,c);
            }
        }
        
        
    }
    
    
    return cnt;
}

//https://programmers.co.kr/learn/courses/30/lessons/60063
int solution(vector<vector<int>> board) {
    int answer = 0;
    n=board.size();
    

    
    for(int i=0; i<n+2; i++)
    {
        for(int j=0; j<n+2; j++)
        {
            if(i>0&&i<n+1&&j>0&&j<n+1)
            {
                mb[i][j]=board[i-1][j-1];
            }
            else
            {
                mb[i][j]=1;
            }
        }
    }
   
    
    
    answer=bbfs();
  
    
    return answer;
}
