#include <iostream>
#include <string>

// 1541
int main()
{
    //std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
    std::string Problem = "";
    std::cin >> Problem;
    
    int result = 0;
    bool Exist_Minus = false;
    std::string num = "";
    for (int i = 0; i < Problem.size(); i++)
    {
        if (Problem[i] == '-')
        {
            if (Exist_Minus)
            {
                result -= stoi(num);
            }
            else
            {
                result += stoi(num);
            }

            num = "";
            Exist_Minus = true;
        }
        else if (Problem[i] == '+')
        {
            if (Exist_Minus)
            {
                result -= stoi(num);
            }
            else
            {
                result += stoi(num);
            }

            num = "";
        }
        else
        {
            num += Problem[i];
        }
    } 

    if (Exist_Minus)
    {
        result -= stoi(num);
    }
    else
    {
        result += stoi(num);
    }

    std::cout << result;
}