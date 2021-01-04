/*
**	04354.cpp
**
**	https://www.acmicpc.net/problem/4354
*/

#include <iostream>
#include <string>
#include <vector>

#define DEBUG 0
using namespace std;

int		max(int a, int b)
{
	return (a > b ? a : b);
}

int		main(void)
{
	string in;
	int		ret;

	cin >> in;
	while (1)
	{
		if (!in.compare("."))
			break ;
		ret = 1;
		vector<int> f(in.length(), 0);
		int	j;
		int	k;
		int	flag;
		flag = 0;
		j = 1;
		k = 0;
		//cout << in << " " << sub << "\n";
		while (j < in.length())
		{
			while (k > 0 && in[k] != in[j])
				k = f[k - 1];
			if (in[k] == in[j])
				f[j] = ++k;
			j++;
		}
		#if DEBUG
		int i = 0;
		while (i < in.length())
		{
			cout << f[i] << " ";
			i++;
		}
		cout << "\n";
		#endif
		//cout << flag << " " << i << " " << in.length() << "\n";
		if (in.size() % (in.size() - f[in.size() - 1]) == 0)
			cout << in.size() / (in.size() - f[in.size() - 1]) << "\n";
		else
			cout << 1 << "\n";
		cin >> in;
	}
}
