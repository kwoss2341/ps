#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;



bool islower(int i, string p)
{
    return p[i]>96&&p[i]<123;
}


int gobs(string word, string p)
{
    int answer=0;
    transform(word.begin(), word.end(), word.begin(), ::tolower);
    transform(p.begin(), p.end(), p.begin(), ::tolower);
    
    
    int k=0;
    while(1)
    {
        if(k>=p.length()) break;
        
        k=p.find(word,k);
        
        if(k==-1)
        {
            break;
        }
        else
        {
            if(k+word.length()==p.length())
            {
                break;
            }
            
            if(!islower(k+word.length(),p) )
            {
                answer++;
            }
            
            for(int i=k+word.length(); i<p.length(); i++)
            {
                if(!islower(i,p))
                {
                    k=i;
                    break;
                }
            }
        }
    }
    
    
    return answer;
}

string cuthttp(int k,string word, string p)
{
    
    int i,j;
    i=p.find(word,k)+word.length();
    
    if(i==-1)
    {
        return "";
    }
    
    i=p.find("https://",i)+8;
    j=p.find("\"",i+1);
    string str=p.substr(i,j-i);
    
    return str;
}


int goahref(int pn,vector <int> strin[],vector <string> &str,string p)
{
    int answer=0;
    int k=0;
    string st;
    while(1)
    {
        k=p.find("<a href",k);
        if(k==-1) break;
        
        st=cuthttp(k,"<a href",p);
        k=k+8;
        answer++;
        
        for(int i=0; i<str.size(); i++)
        {
            if(str[i]==st)
            {
                strin[i].push_back(pn);
            }
        }
        
    }
    

    return answer;
}

//https://programmers.co.kr/learn/courses/30/lessons/42893
int solution(string word, vector<string> pages) {
    int answer = 0;
    int n=pages.size();
    vector <int> bs;        // bs[i] = pages[i] 기본점수
    vector <string> str;    // str[i] = pages[i] 주소
    vector <int> strin[n];  // strln[i].size() = pages[i]로 링크가 걸린 페이지 수
                            // strln[i][j] = pages[i]로 링크가 걸린 pages index     
    
    vector <int> el;        // el[i] = pages[i] 외부 링크수
    vector <double> ls;     // ls[i] = pages[i] 링크 점수
    vector <double> ms;     // ms[i] = pages[i] 매칭 점수
    
    for(int i=0; i<n; i++)
    {
        str.push_back( cuthttp(0,"meta property=\"og:url\"",pages[i]) ) ;
        ls.push_back(0);
    }
    
    for(int i=0; i<n; i++)
    {
        bs.push_back( gobs(word,pages[i]) );
        el.push_back( goahref(i,strin,str,pages[i]) );
    }
    
    for(int i=0; i<n; i++)
    {
        double linkscore=0;
        for(int j=0; j<strin[i].size(); j++)
        {
            linkscore+=(double)bs[strin[i][j]]/el[strin[i][j]];
        }
        ls.push_back(linkscore);
        ms.push_back(linkscore+bs[i]);
    }
    
    for(int i=1; i<n; i++)
    {
        if(ms[i]>ms[answer])
        {
            answer=i;
        }
    }
    
    
    return answer;
}
