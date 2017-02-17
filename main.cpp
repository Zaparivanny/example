#include <iostream>
#include <vector>
using namespace std;


int main()
{
	int n, s;
	vector<int> vec, vec2;
	cin >> n >> s;
	vec.resize(n);
	
	for(int i = 0; i < n; i++)
	{
		cin >> vec[i];
	}
	int res = 0;
	
	for(unsigned int i = 0; i < (1 << (n - 1)); i++)
	{
		int value = 0;
		vec2 = vec;
		for(unsigned int j = n - 1; j != 0; j--)
		{
			if(i & (1 << (j - 1)))
			{
				vec2[j - 1] *= vec2[j];
				vec2.erase(vec2.begin() + j);
			}
		}
		
		for(int j = 0; j < vec2.size(); j++)
		{
			value += vec2[j];
		}
		if(value == s)
		{
			res++;
		}
	}
	
	cout << res << endl;
	
	return 0;
}