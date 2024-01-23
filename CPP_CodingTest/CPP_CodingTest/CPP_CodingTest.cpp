#include <iostream>

// 4375
int main()
{
    //std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
    long long n = 0;
    
    while (true)
    {
        std::cin >> n;
        if (std::cin.eof())
        {
            break;
        }

        long long count = 1;
        int ans = 1;
        while (true)
        {
            if (count % n == 0)
            {
                std::cout << ans << "\n";
                break;
            }
            else
            {
                count = (count * 10) + 1;
                count %= n;
                ++ans;
            }
        }
    }
}