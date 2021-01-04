/*
**	01701.cpp
**
**	https://www.acmicpc.net/problem/1701
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int		max(int a, int b)
{
	return (a > b ? a : b);
}

int		main(void)
{
	string	in;
	int		i;
	int		j;
	int		k;
	int		len;
	int		ret;

	cin >> in;
	len = in.length();
	i = 0;
	ret = 0;
	while (i < len)
	{
		string sub = in.substr(i, len - i);
		int len_sub = sub.length();
		vector<int> f(len_sub, 0);
		j = 1;
		k = 0;
		while (j < len_sub)
		{
			while (k > 0 && sub[k] != sub[j])
				k = f[k - 1];
			if (sub[k] == sub[j])
				f[j] = ++k;
			j++;
		}
		k = 0;
		while (k < len_sub)
		{
			ret = max(ret, f[k]);
			k++;
		}
		i++;
	}
	cout << ret;
}
