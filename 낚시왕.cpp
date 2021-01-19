#include <iostream>
#include <vector>
#include <iostream>

using  namespace std;

int sea[101][101][2];
int kg[12000];
int si[12000];
int answer ,w, h, n;
vector<vector <int>> shark;

void catchshark (int tim)
{
	int x = tim;
	for (int i = 1; i < h + 1; i++)
	{
		int id = sea[i][x][1];
		if (sea[i][x][0]==tim)
		{
			answer += kg[id];
			kg[id] = -1;
			break;
		}
	}

	return;
}

void moveshark(int tim)
{
	for (int i = 0; i < n; i++)
	{
		int x = shark[i][1];
		int y = shark[i][0];
		int s = shark[i][2];
		int d = shark[i][3];
		int z = shark[i][4];
		int id = shark[i][5];
		
		if (kg[id] == -1) continue;

		if (d == 1)
		{
			y -= s;
		}
		else if (d == 2)
		{
			y += s;
		}
		else if (d == 3)
		{
			x += s;
		}
		else
		{
			x -= s;
		}

		if (x < 1)
		{
			int tt = w - 1;
			int mx = x * -1;
			if ((mx / tt) % 2 == 0)
			{
				x = 1 + (mx % tt)+1;
				d = 3;
			}
			else
			{
				x = tt - (mx % tt);
			}

		}
		else if(y<1)
		{
			int tt = h - 1;
			int mx = y * -1;
			if ((mx / tt) % 2 == 0)
			{
				y = 1 + (mx % tt) + 1;
				d = 2;
			}
			else
			{
				y = tt - (mx % tt);
			}
		}
		else if (x > w)
		{
			int tt = w - 1;
			int mx = x-w-1;
			
			if ((mx / tt) % 2 == 0)
			{
				x = tt - (mx % tt);
				d = 4;
			}
			else
			{
				x = 1 + (mx % tt) + 1;
			}

		}
		else if (y > h)
		{
			int tt = h - 1;
			int mx = y - h - 1;

			if ((mx / tt) % 2 == 0)
			{
				y = tt - (mx % tt);
				d = 1;
			}
			else
			{
				y = 1 + (mx % tt) + 1;
			}
		}

		shark[i][1]=x;
		shark[i][0]=y;
		shark[i][3]=d;

		if (sea[y][x][0] == tim)
		{
			int e = sea[y][x][1];
			
			if (kg[e] < kg[id])
			{
				kg[sea[y][x][1]] = -1;
				sea[y][x][1] = id;
			}
			else
			{
				kg[id] = -1;
			}

		}
		else
		{
			sea[y][x][0] = tim;
			sea[y][x][1] = id;
		}
		

	}
}

//https://www.acmicpc.net/problem/17143
int main()
{
	
	answer = 0;
	cin >> h>>w>>n;
	
	
	for (int i = 0; i < h+1; i++)
	{
		for (int j = 0; j < w + 1; j++)
		{
			sea[h][w][0] = -1;
			sea[h][w][1] = -1;
		}
	}

	for (int i = 0; i < n; i++)
	{
		vector<int> temp;
		int t;
		for (int j = 0; j < 5; j++)
		{
			cin >> t;
			temp.push_back(t);
		}
		temp.push_back(i);
		shark.push_back(temp);
		
		sea[shark[i][0]][shark[i][1]][0] = 1;
		sea[shark[i][0]][shark[i][1]][1] = shark[i][5];
		kg[i] = shark[i][4];
		
	}


	for (int i = 1; i < w + 1; i++)
	{
		catchshark(i);
		moveshark(i+1);

	}
	
	cout << answer << endl;



	return 0;
}
