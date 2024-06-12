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
void BOJ::Problem_2164()
{
	int N = 0;
	std::cin >> N;

	std::queue<int> Q;
	for (int i = 1; i <= N; i++)
	{
		Q.push(i);
	}

	while (1 != Q.size())
	{
		Q.pop();
		int Front = Q.front();
		Q.push(Front);
		Q.pop();
	}

	std::cout << Q.front();
}
void BOJ::Problem_10828()
{
	int N = 0;
	std::cin >> N;

	std::stack<int> Stack;
	for (int i = 0; i < N; i++)
	{
		std::string Input = "";
		std::cin >> Input;

		if ("push" == Input)
		{
			int Num = 0;
			std::cin >> Num;
			Stack.push(Num);
			continue;
		}

		if ("pop" == Input)
		{
			if (true == Stack.empty())
			{
				std::cout << "-1\n";
			}
			else
			{
				std::cout << Stack.top() << "\n";
				Stack.pop();
			}

			continue;
		}

		if ("size" == Input)
		{
			std::cout << Stack.size() << "\n";
			continue;
		}

		if ("empty" == Input)
		{
			if (true == Stack.empty())
			{
				std::cout << "1\n";
			}
			else
			{
				std::cout << "0\n";
			}

			continue;
		}

		if ("top" == Input)
		{
			if (true == Stack.empty())
			{
				std::cout << "-1\n";
			}
			else
			{
				std::cout << Stack.top() << "\n";
			}
		}
	}
}
void BOJ::Problem_10773()
{
	int K = 0;
	std::cin >> K;

	std::stack<int> Stack;
	for (int i = 0; i < K; i++)
	{
		int Num = 0;
		std::cin >> Num;

		if (0 == Num)
		{
			Stack.pop();
		}
		else
		{
			Stack.push(Num);
		}
	}

	int Sum = 0;
	while (false == Stack.empty())
	{
		Sum += Stack.top();
		Stack.pop();
	}

	std::cout << Sum;
}
void BOJ::Problem_2493()
{
	struct Top
	{
		int Height = 0;
		int Idx = 0;
	};

	int N = 0;
	scanf_s("%d", &N);
	
	std::stack<Top> Stack;
	for (int i = 1; i <= N; i++)
	{
		int H = 0;
		scanf_s("%d", &H);

		while (false == Stack.empty())
		{
			if (H < Stack.top().Height)
			{
				printf_s("%d ", Stack.top().Idx);
				break;
			}
		
			Stack.pop();
		}

		if (true == Stack.empty())
		{
			printf_s("0 ");
		}

		Stack.push(Top(H, i));
	}
}
void BOJ::Problem_10808()
{
	std::string Word = "";
	std::cin >> Word;

	std::vector<int> Alphabet(26, 0);
	for (size_t i = 0; i < Word.size(); i++)
	{
		++Alphabet[Word[i] - 'a'];
	}

	for (size_t i = 0; i < Alphabet.size(); i++)
	{
		std::cout << Alphabet[i] << " ";
	}
}
