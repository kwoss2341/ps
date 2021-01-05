#include <string>
#include <vector>
#include <iostream>
using namespace std;


//https://programmers.co.kr/learn/courses/30/lessons/68646
int solution(vector<int> a) {
    int answer = 0;
    int rightmin[a.size()];
    int leftmin[a.size()];
    int mymin;


    leftmin[0] = 1000000001;
    rightmin[a.size() - 1] = 1000000001;

    mymin = a[0];
    for (int i = 1; i < a.size(); i++)
    {
        if (a[i - 1] < mymin)
        {
            mymin = a[i - 1];
        }
        leftmin[i] = mymin;
    }

    mymin = a[a.size() - 1];
    for (int i = a.size() - 2; i >= 0; i--)
    {
        if (a[i + 1] < mymin)
        {
            mymin = a[i + 1];
        }
        rightmin[i] = mymin;
    }

    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] < leftmin[i] || a[i] < rightmin[i])
        {
            answer++;
        }
    }


    return answer;
}