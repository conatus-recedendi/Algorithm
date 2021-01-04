/*
**	09486.cpp
**
**	https://www.acmicpc.net/problem/9486
*/

#include <iostream>
#include <vector>
#include <queue>

#define MAX_VAL 99999999

using namespace std;

struct T
{
	int	state;
	int	cursor;
	int	ret;
};
int		list[(1 << 17)];
queue<T>	q; // state, cursur

int		abs(int a)
{
	return (a > 0 ? a : -a);
}

int		get_distance(int src, int dest, string in, int state)
{
	int	n;
	int	i;
	int	cursor;
	int	up;

	n = in.size();
	i = src;
	cursor = 0;
	while (i > dest)
	{
		if (state & (1 << i))
			cursor++;
		i--;
	}
	while (i < dest)
	{
		if (state & (1 << i))
			cursor++;
		i++;
	}
	up = 0;
	if (in[dest] >= 'A' && in[dest] <= 'N')
		up = in[dest] - 'A';
	else
		up = 'Z' - in[dest] + 1;
	return (up + cursor + 1);
}

int		main(void)
{
	int	m;
	int	n;
	int	i;
	string in;

	while (1)
	{
		i = 0;
		while (i < (1 << 17))
		{
			list[i] = MAX_VAL;
			i++;
		}
		cin >> in;
		if (!in.compare("0"))
			break ;
		n = in.size();
		while (!q.empty())
		{
			m = 0; // count of state bit == 현재 입력한 문자의 개수
			i = 0;
			while (i < n)
			{
				if (q.front().state & (1 << i))
					m++;
				i++;
			}
			i = 0;
			while (i < n)
			{
				if (!(q.front().state & (1 << i)))
				{
					int newstate;
					int	distance;
					newstate = q.front().state | (1 << i);
					distance = get_distance(q.front().cursor, i, in, q.front().state);
					if (q.front().ret + distance < list[newstate])
						q.push({newstate, i, q.front().ret + distance});
				}
				i++;
			}
			q.pop();
		}
		cout << list[(1 << n) - 1] << "\n";
	}
}

