#include <iostream>
#include <string>

int GCD(int _A, int _B);

// 14490
int main()
{
	std::string Num = "";
	std::cin >> Num;

	bool IsN = true;
	int N = 0, M = 0;
	std::string N_Str = "", M_Str = "";
	for (int i = 0; i < Num.size(); i++)
	{
		if (Num[i] == ':')
		{
			IsN = false;
			continue;
		}

		if (IsN)
		{
			N_Str += Num[i];
		}
		else
		{
			M_Str += Num[i];
		}
	}

	N = stoi(N_Str);
	M = stoi(M_Str);

	int gcd = 0;
	gcd = GCD(N, M);
	
	N /= gcd;
	M /= gcd;
	
	std::string Result = "";
	Result += std::to_string(N) + ":" + std::to_string(M);
	std::cout << Result << std::endl;
}

int GCD(int _A, int _B)
{
	int r;
	while (_B != 0)
	{
		r = _A % _B;
		_A = _B;
		_B = r;
	}
	return _A;
}