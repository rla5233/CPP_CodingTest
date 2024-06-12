#include "PreCompile.h"
#include "BOJ.h"

BOJ::BOJ()
{
}

BOJ::~BOJ()
{
}

void BOJ::Problem_1475()
{
	int N = 0;
	std::cin >> N;

	std::vector<int> NumVec(10, 0);
	while (0 != N)
	{
		++NumVec[N % 10];
		N /= 10;
	}

	NumVec[6] += NumVec[9];
	NumVec[6] = static_cast<int>(ceil(NumVec[6] / 2.0));

	int SetCount = 0;
	for (size_t i = 0; i < NumVec.size() - 1; i++)
	{
		if (SetCount < NumVec[i])
		{
			SetCount = NumVec[i];
		}
	}
	
	std::cout << SetCount;
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
void BOJ::Problem_2577()
{
	int A = 0, B = 0, C = 0;
	std::cin >> A >> B >> C;

	int Mul = A * B * C;
	std::vector<int> NumVec(10, 0);
	while (0 != Mul)
	{
		++NumVec[Mul % 10];
		Mul /= 10;
	}

	for (size_t i = 0; i < NumVec.size(); i++)
	{
		std::cout << NumVec[i] << std::endl;
	}
}
void BOJ::Problem_3273()
{
	int n = 0;
	std::cin >> n;

	std::vector<int> Sequence;
	Sequence.reserve(n);

	for (size_t i = 0; i < Sequence.capacity(); i++)
	{
		int Num = 0;
		std::cin >> Num;
		Sequence.push_back(Num);
	}

	sort(Sequence.begin(), Sequence.end());

	int x = 0;
	std::cin >> x;

	int Count = 0;
	int Left = 0, Right = static_cast<int>(Sequence.size() - 1);
	while (Left < Right)
	{
		if (x < Sequence[Left] + Sequence[Right])
		{
			--Right;
		}
		else if (x > Sequence[Left] + Sequence[Right])
		{
			++Left;
		}
		else
		{
			++Left; 
			--Right; 
			++Count;
		}
	}

	std::cout << Count;
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
void BOJ::Problem_10807()
{
	int N = 0;
	std::cin >> N;

	int Num = 0;
	
	std::vector<int> NumVec;
	NumVec.reserve(N);
	for (int i = 0; i < NumVec.capacity(); i++)
	{
		std::cin >> Num;
		NumVec.push_back(Num);
	}

	int v = 0, count = 0;
	std::cin >> v;
	for (size_t i = 0; i < NumVec.size(); i++)
	{
		if (v == NumVec[i])
		{
			++count;
		}
	}

	std::cout << count;
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
void BOJ::Problem_11328()
{
	int N = 0;
	std::cin >> N;

	for (int i = 0; i < N; i++)
	{
		std::string str1 = "", str2 = "";
		std::cin >> str1 >> str2;

		sort(str1.begin(), str1.end());
		sort(str2.begin(), str2.end());

		if (str1 == str2)
		{
			std::cout << "Possible\n";
		}
		else
		{
			std::cout << "Impossible\n";
		}
	}
}
void BOJ::Problem_13300()
{
	int N = 0, K = 0;
	std::cin >> N >> K;

	std::vector<int> Girl(6, 0);
	std::vector<int> Boy(6, 0);

	int S = 0, Y = 0;
	for (int i = 0; i < N; i++)
	{
		std::cin >> S >> Y;

		switch (S)
		{
		case 0:
			++Girl[Y - 1];
			break;
		case 1:
			++Boy[Y - 1];
			break;
		}
	}

	int Count = 0;
	for (size_t i = 0; i < 6; i++)
	{
		float fK = static_cast<float>(K);
		Count += static_cast<int>(ceil(Girl[i] / fK));
		Count += static_cast<int>(ceil(Boy[i] / fK));
	}

	std::cout << Count;
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
