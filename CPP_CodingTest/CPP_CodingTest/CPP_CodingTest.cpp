#include <iostream>
#include <map>

// 9375
int main()
{
    //std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
    int TestCase = 0;
    std::cin >> TestCase;

    for (int i = 0; i < TestCase; i++)
    {
        int Count = 0;
        std::cin >> Count;
        std::map<std::string, int> Clothes;
        for (int i = 0; i < Count; i++)
        {
            std::string A = "", B = "";
            std::cin >> A >> B;
            Clothes[B]++;
        }

        long long AllCase = 1;
        for (auto i : Clothes)
        {
            AllCase *= (static_cast<long long>(i.second) + 1);
        }

        --AllCase;
        std::cout << AllCase << "\n";
    }
}