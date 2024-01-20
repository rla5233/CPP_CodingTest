#include <iostream>
#include <vector>

// 2559
int main()
{
    //std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
    int N = 0, K = 0;
    std::cin >> N >> K;

    std::vector<int> SumTemperature(N + 1, 0);
    for (int i = 0; i < N; i++)
    {
        int Num = 0;
        std::cin >> Num;
        SumTemperature[i + 1] = SumTemperature[i] + Num;
    }

    int SumMax = 0, Sum = 0;
    int Left = 0, Right = K;
    for (int i = 0; i + Right < SumTemperature.size(); i++)
    {
        Sum = SumTemperature[i + Right] - SumTemperature[i + Left];
        if (Sum > SumMax || i == 0)
        {
            SumMax = Sum;
        }
    }

    std::cout << SumMax;
}