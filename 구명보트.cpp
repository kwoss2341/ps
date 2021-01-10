#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool cmp(int x, int y)
{
    return x > y;
}

//https://programmers.co.kr/learn/courses/30/lessons/42885
int solution(vector<int> people, int limit) {
    int answer = 0;
    int fi = people.size() - 1;
    int cnt = 0;
    int kg;

    sort(people.begin(), people.end(), cmp);

    for (answer = 0; answer < people.size(); answer++)
    {
        cnt++;
        kg = limit - people[answer];


        while (1)
        {
            if (cnt == people.size()) break;

            if (kg - people[fi] >= 0)
            {
                kg = kg - people[fi];
                fi--;
                cnt++;
            }
            else
            {
                break;
            }
        }

        if (cnt == people.size())
        {
            break;
        }
    }

    return answer + 1;
}