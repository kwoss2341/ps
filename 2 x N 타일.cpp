#include <string>
#include <vector>
#include <iostream>

using namespace std;

//https://programmers.co.kr/learn/courses/30/lessons/12900
int solution(int n) {
    int answer = 1;
    int mod = 1000000007;

    int x1 = 1;
    int x2 = 1;
    int y;
    for (int i = 1; i < n; i++)
    {
        answer = (x1 + x2) % mod;
        x2 = x1;
        x1 = answer;
    }


    return answer;
}