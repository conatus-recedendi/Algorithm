/*
**	 01786 찾기
**
**	https://www.acmicpc.net/problem/1786
**	2020.12.31
*/

#include <iostream>
#include <string>
#include <queue>

#define DEBUG 0
using namespace std;

int			next_arr[1000001];
queue<int>	q;

void		set_kmp(string p)
{
	int		i;
	int		j;
	int		m;

	m = p.length();
	i = 1;
	j = 0;
	while (i < m)
	{
		while (j > 0 && p[i] != p[j])
			j = next_arr[j - 1];
		if (p[i] == p[j])
			next_arr[i] = ++j;
		i++;
	}
}

void		get_pat(string t, string p)
{
	int		j;
	int		i;
	int		m;
	int		n;

	j = 0;
	i = 0;
	m = t.length();
	n = p.length();
	while (i < m)
	{
		while (j > 0 && t[i] != p[j])
			j  = next_arr[j - 1];
		if (t[i] == p[j])
		{
			if (j == n - 1)
			{
				q.push(i - n + 2);
				j = next_arr[j];
			}
			else
				j++;
		}
		i++;
	}
}

int			main(void)
{
	string	t;
	string	p;

	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	getline(cin, t);
	getline(cin, p);
	set_kmp(p);
	get_pat(t, p);
	cout << q.size() << "\n";
	#if DEBUG
	int i;
	i = 0;
	while (i < 20)
	{
		cout << next_arr[i] << " ";
		i++;
	}
	#endif
	while (!q.empty())
	{
		cout << q.front() << " ";
		q.pop();
	}
}

/*

ABCDABD
1123564

A
0
AB
0
ABC
1
ABCD
2
ABCDA
3
ABCDAB
3
ABCDABD

*/