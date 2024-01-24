#include <iostream>
#include <vector>

// 11659
int main()
{
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
    int N = 0, M = 0;
    std::cin >> N >> M;

    std::vector<int> Sum(N + 1, 0);
    for (int i = 0; i < N; i++)
    {
        int Num = 0;
        std::cin >> Num;
        Sum[i + 1] = Sum[i] + Num;
    }

    for (int i = 0; i < M; i++)
    {
        int Left = 0, Right = 0;
        std::cin >> Left >> Right;

        std::cout << Sum[Right] - Sum[Left - 1] << "\n";
    }
}