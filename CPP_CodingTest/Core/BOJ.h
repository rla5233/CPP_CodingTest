#pragma once

// ���� :
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



};

