#pragma once

// Ό³Έν :
class Programmers
{
public:
	// constrcuter destructer
	Programmers();
	~Programmers();

	// delete Function
	Programmers(const Programmers& _Other) = delete;
	Programmers(Programmers&& _Other) noexcept = delete;
	Programmers& operator=(const Programmers& _Other) = delete;
	Programmers& operator=(Programmers&& _Other) noexcept = delete;
	
public:
	static std::string Problem_12899(int N);
	static int Problem_120956(std::vector<std::string> Babbling);
	static std::vector<int> Problem_150370(std::string Today, std::vector<std::string> Terms, std::vector<std::string> Privacies);
	static std::string Problem_155652(std::string Str, std::string Skip, int Index);
	static int Problem_161989(int N, int M, std::vector<int> Section);
	static std::vector<int> Problem_176963(std::vector<std::string> Name, std::vector<int> Yearning, std::vector<std::vector<std::string>> Photo);
	static std::vector<std::string> Problem_178871(std::vector<std::string> Players, std::vector<std::string> Callings);
	static std::vector<std::vector<int>> Problem_181830(std::vector<std::vector<int>> Arr);
	static std::vector<std::vector<int>> Problem_181832(int N);
	static std::vector<int> Problem_181844(std::vector<int> Arr, std::vector<int> Delete);
	static std::string Problem_181846(std::string A, std::string B);
	static int Problem_181849(std::string NumStr);
	static int Problem_181851(std::vector<int> Rank, std::vector<bool> Attendance);
	static int Problem_181855(std::vector<std::string> StrArr);
	static int Problem_181856(std::vector<int> Arr1, std::vector<int> Arr2);
	static std::vector<int> Problem_181857(std::vector<int> Arr);
	static int Problem_181865(std::string Binomial);
	static std::vector<std::string> Problem_181866(std::string String);
	static std::vector<std::string> Problem_181868(std::string String);
	static std::vector<int> Problem_181897(int N, std::vector<int> Slicer, std::vector<int> Num_list);
	static std::vector<int> Problem_181893(std::vector<int> Arr, std::vector<int> Query);
	static int Problem_181916(int A, int B, int C, int D);
	static std::vector<int> Problem_181921(int L, int R);
	static std::vector<std::vector<int>> Problem_250121(std::vector<std::vector<int>> Data, std::string Ext, int Val_Ext, std::string Sort_By);
	static int Problem_250125(std::vector<std::vector<std::string>> Board, int H, int W);
	static int Problem_250137(std::vector<int> Bandage, int Health, std::vector<std::vector<int>> Attacks);
	static int Problem_258712(std::vector<std::string> Friends, std::vector<std::string> Gifts);

};

