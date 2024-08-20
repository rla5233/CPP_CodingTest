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


};

