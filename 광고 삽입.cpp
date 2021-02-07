#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int tosec(string s)
{
    int hh=(s[0]-'0')*10+s[1]-'0';
    int mm=(s[3]-'0')*10+s[4]-'0';
    int ss=(s[6]-'0')*10+s[7]-'0';
    
    return hh*3600+mm*60+ss;
}

string tostr(int i)
{
    
    string hh=to_string(i/3600);
    i=i%3600;
    if(hh.length()==1) hh="0"+hh;
    
    string mm=to_string(i/60);
    if(mm.length()==1) mm="0"+mm;
    
    string ss=to_string(i%60);
    if(ss.length()==1) ss="0"+ss;
    
    return hh+":"+mm+":"+ss;
}

//https://programmers.co.kr/learn/courses/30/lessons/72414
string solution(string play_time, string adv_time, vector<string> logs) {
    
    string answer = "";
    vector< vector <int> > myinout;
    vector< vector <int> > xt;
    int playt=tosec(play_time);
    int advt =tosec(adv_time);
    
    for(int i=0; i<logs.size(); i++)
    {
        vector <int> t2;
        
        int myin=tosec(logs[i].substr(0,8));
        int myout=tosec(logs[i].substr(9));
              
        t2.push_back(myin);
        t2.push_back(1);
        myinout.push_back(t2);
        
        t2.clear();
        t2.push_back(myout);
        t2.push_back(0);
        myinout.push_back(t2);
    }
    
    sort(myinout.begin(),myinout.end());
    
    int cnt=0;
    int temp;
    for(int i=0; i<myinout.size(); i++)
    {
        temp=myinout[i][0];
        
        for(i; i<myinout.size(); i++)
        {
            if(myinout[i][0]==temp)
            {
                if(myinout[i][1]==1) cnt++;
                else cnt--;
            }
            else
            {
                i--;
                break;
            }
        }
        
        vector <int> t;
        t.push_back(temp);
        t.push_back(cnt);
        xt.push_back(t);        
    }
    
   
    
    int tim[360001];
    long long int sum[360001];
    int j;   
    
    for(j=0; j<xt[0][0]; j++)
    {
        tim[j]=0;
    }
    
    for(int i=1; i<xt.size(); i++)
    {
        for(j; j<xt[i][0]; j++)
        {
            tim[j]=xt[i-1][1];
        }
    }    
    
    for(j; j<=playt; j++)
    {
        tim[j]=xt[xt.size()-1][1];
    }
    
    sum[0]=0;
    for(int i=0; i<advt; i++)
    {
        sum[0]+=tim[i];
    }
 
    for(int i=1; i<=playt; i++)
    {
        if(i+advt>playt)break;
        sum[i]=sum[i-1]-tim[i-1]+tim[i+advt-1];
    }
    
    int mii=0;
    for(int i=1; i<=playt; i++)
    {
        if(i+advt>playt)break;
        if(sum[mii]<sum[i])
        {
            mii=i;
        }
    }
 
    
    answer=tostr(mii);
    
    return answer;
}
