#include <iostream>

using namespace std;

int cnt;//시험장갯수
int n;//총감독관
int m;//부감독관
int test[1000000];// 시험장 응시자수

int main()
{
	long long int answer = 0;

	cin >> cnt;
	
	for(int i = 0; i < cnt; i++)
	{
		cin >> test[i];
	}

	cin >> n;
	cin >> m;

	for (int i = 0; i < cnt; i++)
	{
		answer++;
		test[i] = test[i] - n;
		if (test[i] > 0)
		{
			if (test[i] % m == 0)
			{
				answer += test[i] / m;
			}
			else
			{
				answer += test[i] / m + 1;
			}
		}
	}


	cout << answer;

	return 0;
}
