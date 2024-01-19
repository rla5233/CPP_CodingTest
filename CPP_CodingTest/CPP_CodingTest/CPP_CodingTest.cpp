#include <iostream>
#include <string>

// 9996
int main()
{
    //std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
    int N = 0;
    std::cin >> N;

    std::string Pattern = "";
    std::cin >> Pattern;

    bool isLeft = true;
    std::string Left = "", Right = "";
    for (int i = 0; i < Pattern.length(); i++)
    {
        if (Pattern[i] == '*')
        {
            isLeft = false;
            continue;
        }

        if (isLeft)
        {
            Left += Pattern[i];
        }
        else
        {
            Right += Pattern[i];
        }
    }

    for (int i = 0; i < N; i++)
    {
        std::string File = "";
        std::cin >> File;

        int a = 0;
        if (Left.length() + Right.length() <= File.length())
        {
            if (Left == File.substr(0, Left.length())
                && Right == File.substr(File.length() - Right.length(), Right.length()))
            {
                std::cout << "DA\n";
            }
            else
            {
                std::cout << "NE\n";
            }
        }
        else
        {
            std::cout << "NE\n";
        }    
    }
}