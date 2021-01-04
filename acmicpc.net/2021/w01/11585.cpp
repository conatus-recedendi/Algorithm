/*
**	11585.cpp
**
**	https://www.acmicpc.net/problem/11585
*/

#include <iostream>
#include <vector>

using namespace std;

char		in[1000001];
char		now[1000001];

vector<int>	kmp(int n)
{
	vector<int> ret(n, 0);
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < n)
	{
		while (j > 0 && in[i] != in[j])
			j = ret[j - 1];
		if (in[i] == in[j])
			ret[i] = ++j;
		i++;
	}
	return (ret);
}

int			main(void)
{
	int		n;
	int		i;
	vector<int>	f;

	cin >> n;
	i = 0;
	while (i < n)
	{
		cin >> in[i];
		i++;
	}
	i = 0;
	while (i < n)
	{
		cin >> in[i];
		i++;
	}
	f = kmp(n);
	if (n % (n - f[n - 1]) == 0)
		cout << "1/" << (n-f[n-1]);
	else
		cout << "1/" << n;
}
