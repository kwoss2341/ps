#include <string>
#include <vector>
#include <iostream>

using namespace std;

int visit[101][101][2];
int m;

bool build0(int x, int y) //기둥 설치 가능?
{
    if (y == 0)
    {
        return true;
    }
    else if (visit[x][y - 1][0] == 1)
    {
        return true;
    }
    else if (x != 0 && visit[x - 1][y][1] == 1)
    {
        return true;
    }
    else if (visit[x][y][1] == 1)
    {
        return true;
    }


    return false;

}

bool build1(int x, int y) //보 설치 가능?
{
    if (y == 0)
    {
        return false;
    }

    if (visit[x][y - 1][0] == 1 || visit[x + 1][y - 1][0] == 1)
    {
        return true;
    }
    else if ((x - 1 >= 0 && visit[x - 1][y][1] == 1) && (x + 1 < m && visit[x + 1][y][1] == 1))
    {
        return true;
    }

    return false;
}

bool check0(int x, int y) //기둥 삭제 가능?
{
    if (x - 1 >= 0 && y + 1 < m && visit[x - 1][y + 1][1] == 1)
    {
        if (!build1(x - 1, y + 1)) return false;
    }
    if (y + 1 < m && visit[x][y + 1][1] == 1)
    {
        if (!build1(x, y + 1)) return false;
    }
    if (y + 1 < m && visit[x][y + 1][0] == 1)
    {
        if (!build0(x, y + 1)) return false;
    }
    if (x - 1 >= 0 && visit[x - 1][y][1] == 1)
    {
        if (!build1(x - 1, y)) return false;
    }
    if (y - 1 >= 0 && visit[x][y - 1][0] == 1)
    {
        if (!build0(x, y - 1)) return false;
    }
    if (visit[x][y][1] == 1)
    {
        if (!build1(x, y)) return false;
    }

    return true;
}

bool check1(int x, int y) //보 삭제 가능?
{
    if (visit[x][y][0] == 1)
    {
        if (!build0(x, y)) return false;
    }
    if (x + 1 < m && visit[x + 1][y][0] == 1)
    {
        if (!build0(x + 1, y)) return false;
    }
    if (x - 1 >= 0 && visit[x - 1][y][1] == 1)
    {
        if (!build1(x - 1, y))return false;
    }
    if (x + 1 < m && visit[x + 1][y][1] == 1)
    {
        if (!build1(x + 1, y)) return false;
    }

    return true;
}

//https://programmers.co.kr/learn/courses/30/lessons/60061
vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    m = n;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                visit[i][j][k] = 0;
            }
        }
    }
    int x, y, a, b;
    for (int i = 0; i < build_frame.size(); i++)
    {
        x = build_frame[i][0];
        y = build_frame[i][1];
        a = build_frame[i][2];
        b = build_frame[i][3];
        if (a == 0) //기둥
        {
            if (b == 1)//설치
            {
                if (build0(x, y))
                {
                    visit[x][y][0] = 1;
                }
            }
            else
            {
                visit[x][y][0] = 0;
                if (!check0(x, y))
                {
                    visit[x][y][0] = 1;
                }
            }
        }
        else //보
        {
            if (b == 1)//설치
            {
                if (build1(x, y))
                {
                    visit[x][y][1] = 1;
                }
            }
            else
            {
                visit[x][y][1] = 0;
                if (!check1(x, y))
                {
                    visit[x][y][1] = 1;
                }
            }
        }

    }

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (visit[i][j][0] == 1)
            {
                vector <int> v1;
                v1.push_back(i);
                v1.push_back(j);
                v1.push_back(0);
                answer.push_back(v1);
            }

            if (visit[i][j][1] == 1)
            {
                vector <int> v1;
                v1.push_back(i);
                v1.push_back(j);
                v1.push_back(1);
                answer.push_back(v1);
            }
        }
    }

    return answer;
}