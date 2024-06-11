#pragma once

// Ό³Έν :
class BOJ
{
public:
	// constrcuter destructer
	BOJ();
	~BOJ();

	// delete Function
	BOJ(const BOJ& _Other) = delete;
	BOJ(BOJ&& _Other) noexcept = delete;
	BOJ& operator=(const BOJ& _Other) = delete;
	BOJ& operator=(BOJ&& _Other) noexcept = delete;

public:
	static void Problem_10845();
	static void Problem_18258();
	static void Problem_2164();
	static void Problem_10828();
	static void Problem_10773();

};

