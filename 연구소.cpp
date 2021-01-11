#include <iostream>

using namespace std;

int n;
int m;
int lab[8][8];
int mylab[8][8];


void govirus(int i, int j)
{
	if (i - 1 >= 0 && mylab[i - 1][j] == 0)
	{
		mylab[i - 1][j] = 2;
		govirus(i - 1, j);
	}

	if (i + 1 < n && mylab[i + 1][j] == 0)
	{
		mylab[i + 1][j] = 2;
		govirus(i + 1, j);
	}

	if (j - 1 >= 0 && mylab[i][j - 1] == 0)
	{
		mylab[i][j - 1] = 2;
		govirus(i, j - 1);
	}

	if (j + 1 < m && mylab[i][j + 1] == 0)
	{
		mylab[i][j + 1] = 2;
		govirus(i, j + 1);
	}


	return;
}


int safe(int a, int b, int c)
{
	
	
	int answer = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			mylab[i][j] = lab[i][j];
		}
	}

	mylab[a/m][a%m] = 1;
	mylab[b/m][b%m] = 1;
	mylab[c/m][c%m] = 1;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (mylab[i][j] == 2)
			{
				govirus(i,j);
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (mylab[i][j] == 0)
			{
				answer++;
			}
		}
	}

	return answer;
}

int findArea()
{
	
	int s = n * m;
	int answer = 0;
	int a, b, c;
	int temp;

	for (int i = 0; i < s; i++)
	{

		
		if (lab[i/m][i%m] == 0)
		{
			a = i;
		}
		else
		{
			continue;
		}
		

		for (int j = i+1; j < s; j++)
		{
	
			if (lab[j / m][j % m] == 0)
			{
				b = j;
			}
			else
			{
				continue;
			}
			

			for (int k = j+1; k < s; k++)
			{
				if (lab[k/m][k%m] == 0)
				{
					c = k; 
					temp = safe(a, b, c);
					if (temp > answer) answer = temp;
				}
				else 
				{
					continue;
				}
				
			}
		}
	}


	return answer;
}

//https://www.acmicpc.net/problem/14502
int main()
{
	cin >> n;
	cin >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> lab[i][j];
		}
	}

	cout << findArea();


	return 0;
}