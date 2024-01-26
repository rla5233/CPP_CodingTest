#include <iostream>
#include <vector>
#include <algorithm>

// 2959
int main()
{
	//std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	std::vector<int> Num(4, 0);
	for (int i = 0; i < 4; i++)
	{
		std::cin >> Num[i];
	}

	sort(Num.begin(), Num.end());

	std::cout << Num[0] * Num[2];
}