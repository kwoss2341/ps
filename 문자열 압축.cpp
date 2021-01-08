#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int mysqrt(int cnt)
{
    int x = cnt;
    for (int i = 1; i < 4; i++)
    {
        x = x / 10;
        if (x == 0)
        {
            return i;
        }
    }
}

bool check(string str, string temp)
{
    if (temp.length() < str.length())
    {
        return false;
    }

    bool sw = true;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] != temp[i])
        {
            sw = false;
            break;
        }
    }

    return sw;
}

//https://programmers.co.kr/learn/courses/30/lessons/60057
int solution(string s) {
    int answer = 10000;
    string str;
    string temp;
    int myanswer;

    if (s.length() == 1) return 1;

    for (int i = 1; i < s.length() - 1; i++)
    {

        str = s.substr(0, i);
        myanswer = i;
        int cnt = 1;
        for (int j = 1; j < s.length() / i; j++)
        {
            if (i >= answer) break;
            temp = s.substr(j * i, i);
            if (check(str, temp))
            {

                cnt++;
            }
            else
            {

                myanswer = myanswer + i;
                if (cnt > 1) myanswer += mysqrt(cnt);
                str = temp;
                cnt = 1;

            }
        }


        myanswer = myanswer + s.length() % i;
        if (cnt > 1)myanswer += mysqrt(cnt);
        if (answer > myanswer) answer = myanswer;

    }

    return answer;
}