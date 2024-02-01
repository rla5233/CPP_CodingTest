#include <iostream>
#include <vector>

// 2903
int main()
{
    //std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

    int N = 0;
    std::cin >> N;

    std::vector<int> Len(N + 1, 0);
    Len[0] = 2;

    for (int i = 1; i <= N; i++)
    {
        Len[i] = 2 * Len[i - 1] - 1;
    }

    std::cout << Len[N] * Len[N];
}