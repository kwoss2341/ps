#include <string>
#include <vector>
#include <iostream>
using namespace std;

int maxx;
int maxy;
int minx;
int miny;

void turnR(vector<vector<int>>& key)
{
    int size = key.size();
    vector<vector<int>> temp(key.size(), vector<int>(key[0].size(), 0));
    copy(key.begin(), key.end(), temp.begin());

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            key[i][j] = temp[size - 1 - j][i];
        }
    }

    return;
}


bool check(vector<vector<int>>& key, vector<vector<int>>& lock)
{
    int sizex = maxx - minx + 1;
    int sizey = maxy - miny + 1;
    if (sizex == sizey && sizex == -21) return true;
    if (sizex > key.size() || sizey > key.size()) return false;



    bool sw = false;

    for (int i = 0; i < key.size() - sizey + 1; i++)
    {
        for (int j = 0; j < key.size() - sizex + 1; j++)
        {
            int locki = 0;
            int lockj = 0;
            bool ssw = true;
            for (int k = i; k < i + sizey; k++)
            {
                lockj = 0;
                for (int z = j; z < j + sizex; z++)
                {

                    if (key[k][z] == lock[miny + locki][minx + lockj])
                    {
                        ssw = false;
                    }
                    if (ssw == false) break;
                    lockj++;
                }
                if (ssw == false) break;
                locki++;
            }

            if (ssw == true)
            {
                sw = true; break;
            }

        }
        if (sw == true) break;
    }


    return sw;
}


//https://programmers.co.kr/learn/courses/30/lessons/60059
bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;
    int ls = lock.size();
    int ks = key.size();

    maxx = -1;
    minx = 21;
    maxy = -1;
    miny = 21;


    for (int i = 0; i < ls; i++)
    {
        for (int j = 0; j < ls; j++)
        {
            if (lock[i][j] == 0)
            {
                if (j < minx)
                {
                    minx = j;
                }
                if (j > maxx)
                {
                    maxx = j;
                }
                if (i < miny)
                {
                    miny = i;
                }
                if (i > maxy)
                {
                    maxy = i;
                }
            }
        }
    }



    for (int i = 0; i < 4; i++)
    {
        if (i != 0)
        {
            turnR(key);
        }

        if (check(key, lock) == 1)
        {
            answer = true;
        }

        if (answer == true)break;
    }

    return answer;
}