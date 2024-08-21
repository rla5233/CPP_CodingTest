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
	static int Problem_250137(std::vector<int> Bandage, int Health, std::vector<std::vector<int>> Attacks);
	static std::vector<int> Problem_181897(int N, std::vector<int> Slicer, std::vector<int> Num_list);
	static std::vector<int> Problem_181893(std::vector<int> Arr, std::vector<int> Query);

};

