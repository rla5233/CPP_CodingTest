#include <iostream>
#include <algorithm>

// 2992
int main()
{
    //std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
    std::string Num = "";
    std::cin >> Num;

    if (next_permutation(Num.begin(), Num.end()))
    {
        std::cout << Num;
    }
    else
    {
        std::cout << "0";
    }
}