#include <string>
#include <vector>
#include <iostream>
using namespace std;

void swap(int heap[],int x,int y)
{
    int temp=heap[x];
    heap[x]=heap[y];
    heap[y]=temp;
    
    return;
}

void insertheap(int heap[],int x,int i)
{
    i++;
    heap[i]=x;
    
    while(1)
    {
        if(i==1) break;
        
        if(x<heap[i/2])
        {
            swap(heap,i,i/2);
            i=i/2;
        }
        else
        {
            break;
        }
    }
    
}

void deleteheap(int heap[],int n)
{
    if(n==0) return;
    
    int item=heap[1];
    int temp=heap[n];
    n--;
    
    int i=1;
    int j=2;
    
    while(j<=n)
    {
        if(j<n && heap[j]>heap[j+1]) j=j+1;
        
        if(temp<=heap[j]) break;
        
        heap[i]=heap[j];
        i=j;
        j=j*2;
    }
    
    heap[i]=temp;
    
}

//https://programmers.co.kr/learn/courses/30/lessons/42626#
int solution(vector<int> scoville, int K) {
    int answer = 0;
    int n=scoville.size();
    int heap[n+2];
    
    
    for(int i=0; i<n; i++)
    {
        insertheap(heap,scoville[i],i);
    }
    
    
    
    int heapsize=n;
    int mixsc;
    int cnt=0;
    
    while(n>1)
    {
        mixsc=heap[1]+min(heap[2],heap[3])*2;
        
        deleteheap(heap,n);
        
        deleteheap(heap,n-1);
        
        insertheap(heap,mixsc,n-2);
        n--;
        cnt++;
        
        if(heap[1]>=K)
        {
            return cnt;
        }
    }
        
        
  
    
    
    return -1;
}
