#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool check(string& p);
string one(string& p);
string two(string& p);


//https://programmers.co.kr/learn/courses/30/lessons/60058
string solution(string p) {
    string answer = "";

    answer = one(p);

    return answer;
}


bool check(string& p)
{
    int stack = 0;
    for (int i = 0; i < p.length(); i++)
    {
        if (p[i] == '(')
        {
            stack++;
        }
        else
        {
            stack--;
        }

        if (stack < 0) return false;
    }

    if (stack == 0) return true;
    else return false;
}


string one(string& p) // 1.
{
    if (p.length() == 0)
    {
        return "";
    }
    else
    {
        return two(p);
    }
}

string two(string& p) //2.
{
    string u, v;
    int ln = 0;
    int rn = 0;
    int ui;
    for (int i = 0; i < p.length(); i++)
    {
        if (p[i] == '(')
        {
            ln++;
        }
        else
        {
            rn++;
        }

        if (rn == ln)
        {
            ui = i;
            break;
        }
    }

    u = p.substr(0, ui + 1);
    v = p.substr(ui + 1);



    if (check(u))//3.
    {
        return u.append(one(v));//3-1.
    }
    else //4.
    {

        string temp = "(";//4-1.
        temp.append(one(v));//4-2.
        temp.append(")");//4-3.


        u.erase(u.begin()); //4-4.
        u.erase(u.end() - 1);
        for (int i = 0; i < u.length(); i++)
        {
            if (u[i] == '(') u[i] = ')';
            else u[i] = '(';
        }
        temp.append(u);


        return temp; //4-5.
    }

}