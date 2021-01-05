#include <vector>
#include <iostream>

using namespace std;

struct myMap
{
    int way;
    int right;
    int down;
};


int MOD = 20170805;
myMap my[500][500];


// https://programmers.co.kr/learn/courses/30/lessons/1832
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map) {
    int answer = 0;


    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {

            if (i == 0 && j == 0)
            {
                my[i][j].way = 1;
                my[i][j].right = 0;
                my[i][j].down = 0;
                continue;
            }

            if (i == 0)
            {
                if (city_map[i][j] == 0)
                {
                    if (city_map[i][j - 1] == 0)
                    {
                        my[i][j].way = my[i][j - 1].way;
                    }
                    else if (city_map[i][j - 1] == 2)
                    {
                        my[i][j].way = my[i][j - 1].right;
                    }
                    else
                    {
                        my[i][j].way = 0;
                    }


                }
                else if (city_map[i][j] == 2)
                {
                    if (city_map[i][j - 1] == 0)
                    {
                        my[i][j].right = my[i][j - 1].way;
                        my[i][j].down = 0;
                    }
                    else if (city_map[i][j - 1] == 2)
                    {
                        my[i][j].right = my[i][j - 1].right;
                        my[i][j].down = 0;
                    }
                    else
                    {
                        my[i][j].right = 0;
                        my[i][j].down = 0;
                    }

                }
                else
                {
                    my[i][j].way = 0;
                }

            }
            else if (j == 0)
            {
                if (city_map[i][j] == 0)
                {
                    if (city_map[i - 1][j] == 0)
                    {
                        my[i][j].way = my[i - 1][j].way;
                    }
                    else if (city_map[i - 1][j] == 2)
                    {
                        my[i][j].way = my[i - 1][j].down;
                    }
                    else
                    {
                        my[i][j].way = 0;
                    }
                }
                else if (city_map[i][j] == 2)
                {
                    if (city_map[i - 1][j] == 0)
                    {
                        my[i][j].down = my[i - 1][j].way;
                        my[i][j].right = 0;
                    }
                    else if (city_map[i - 1][j] == 2)
                    {
                        my[i][j].down = my[i - 1][j].down;
                        my[i][j].right = 0;
                    }
                    else
                    {
                        my[i][j].right = 0;
                        my[i][j].down = 0;
                    }
                }
                else
                {
                    my[i][j].way = 0;
                }

            }
            else
            {
                if (city_map[i][j] == 0)
                {
                    my[i][j].way = 0;
                    if (city_map[i - 1][j] == 2)
                    {
                        my[i][j].way += my[i - 1][j].down % MOD;
                    }
                    else
                    {
                        my[i][j].way += my[i - 1][j].way % MOD;
                    }

                    if (city_map[i][j - 1] == 2)
                    {
                        my[i][j].way += my[i][j - 1].right % MOD;
                    }
                    else
                    {
                        my[i][j].way += my[i][j - 1].way % MOD;
                    }

                    my[i][j].way %= MOD;
                }
                else if (city_map[i][j] == 2)
                {
                    my[i][j].right = 0;
                    my[i][j].down = 0;

                    if (city_map[i - 1][j] == 2)
                    {
                        my[i][j].down += my[i - 1][j].down % MOD;
                    }
                    else
                    {
                        my[i][j].down += my[i - 1][j].way % MOD;
                    }

                    if (city_map[i][j - 1] == 2)
                    {
                        my[i][j].right += my[i][j - 1].right % MOD;
                    }
                    else
                    {
                        my[i][j].right += my[i][j - 1].way % MOD;
                    }

                    my[i][j].right %= MOD;
                    my[i][j].down %= MOD;
                }
                else
                {
                    my[i][j].way = 0;
                }



            }

        }
    }


    answer = my[m - 1][n - 1].way;
    return answer;
}