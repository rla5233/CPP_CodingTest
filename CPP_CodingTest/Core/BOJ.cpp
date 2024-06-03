#include "PreCompile.h"
#include "BOJ.h"

BOJ::BOJ()
{
}

BOJ::~BOJ()
{
}

void BOJ::Problem_10845()
{
	int N = 0;
	std::cin >> N;
	
	std::queue<int> Q;
	for (int i = 0; i < N; i++)
	{
		int Num = 0;
		std::string Command;
		std::cin >> Command;

		if ("push" == Command)
		{
			std::cin >> Num;
			Q.push(Num);
		}
		else if ("pop" == Command)
		{
			if (true == Q.empty())
			{
				std::cout << "-1\n";
			}
			else
			{
				std::cout << Q.front() << "\n";
				Q.pop();
			}
		}
		else if ("size" == Command)
		{
			std::cout << Q.size() << "\n";
		}
		else if ("empty" == Command)
		{
			if (true == Q.empty())
			{
				std::cout << "1\n";
			}
			else 
			{
				std::cout << "0\n";
			}
		}
		else if ("front" == Command)
		{
			if (true == Q.empty())
			{
				std::cout << "-1\n";
			}
			else
			{
				std::cout << Q.front() << "\n";
			}
		}
		else if ("back" == Command)
		{
			if (true == Q.empty())
			{
				std::cout << "-1\n";
			}
			else
			{
				std::cout << Q.back() << "\n";
			}
		}
	}
}
void BOJ::Problem_18258()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);

	int N = 0;
	std::cin >> N;

	std::queue<int> Q;
	for (int i = 0; i < N; i++)
	{
		int Num = 0;
		std::string Command;
		std::cin >> Command;

		if ("push" == Command)
		{
			std::cin >> Num;
			Q.push(Num);
		}
		else if ("pop" == Command)
		{
			if (true == Q.empty())
			{
				std::cout << "-1\n";
			}
			else
			{
				std::cout << Q.front() << "\n";
				Q.pop();
			}
		}
		else if ("size" == Command)
		{
			std::cout << Q.size() << "\n";
		}
		else if ("empty" == Command)
		{
			if (true == Q.empty())
			{
				std::cout << "1\n";
			}
			else
			{
				std::cout << "0\n";
			}
		}
		else if ("front" == Command)
		{
			if (true == Q.empty())
			{
				std::cout << "-1\n";
			}
			else
			{
				std::cout << Q.front() << "\n";
			}
		}
		else if ("back" == Command)
		{
			if (true == Q.empty())
			{
				std::cout << "-1\n";
			}
			else
			{
				std::cout << Q.back() << "\n";
			}
		}
	}
}