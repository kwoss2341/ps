#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


bool cmpy(vector <int> a, vector <int> b)
{
    return a[1]>b[1];
}

struct tree{
    int key;
    int idx;
    struct tree *left;
    struct tree *right;
    
};

tree t[10000];

tree* insertnode(tree *p,int x,int i)
{
    if(p==NULL)
    {
        t[i].key=x;
        t[i].idx=i+1;
        t[i].right=NULL;
        t[i].left=NULL;
        return &t[i];
    }
    else if(x<p->key)
    {
        p->left=insertnode(p->left,x,i);
    }
    else
    {
        p->right=insertnode(p->right,x,i);
    }
    
    return p;
}

void preorder(tree* root,vector<int> &pre)
{
    if(root)
    {
        pre.push_back(root->idx);
        preorder(root->left,pre);
        preorder(root->right,pre);
    }
}

void postorder(tree* root,vector<int> &post)
{
    if(root)
    {
        postorder(root->left,post);
        postorder(root->right,post);
        post.push_back(root->idx);
    }
}

//https://programmers.co.kr/learn/courses/30/lessons/42892
vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
   
    vector<vector<int>> answer;
    vector <int> pre;
    vector <int> post;
    
    int n=nodeinfo.size();
    tree* root=NULL;
    
    
    for(int i=0; i<n; i++)
    {
       nodeinfo[i].push_back(i);
    }
    
    sort(nodeinfo.begin(),nodeinfo.end(),cmpy);
    
    root=insertnode(root,nodeinfo[0][0],nodeinfo[0][2]);
    for(int i=1; i<n; i++)
    {
       insertnode(root,nodeinfo[i][0],nodeinfo[i][2]);
    }
    
    
    
    preorder(root,pre);
    postorder(root,post);
    
    answer.push_back(pre);
    answer.push_back(post);
   
    
    
    
    
    return answer;
}
