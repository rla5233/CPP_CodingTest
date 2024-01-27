#include <iostream>
#include <stack>

// 11899
int main()
{
    //std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
    std::string String = "";
    std::cin >> String;

    std::stack<char> Stack;
    for (int i = 0; i < String.size(); i++)
    {
        char Ch = String[i];
        if (Ch == '(' || Stack.empty())
        {
            Stack.push(Ch);
        }
        else if (Ch == ')')
        {
            if (Stack.top() == '(')
            {
                Stack.pop();
            }
            else
            {
                Stack.push(Ch);
            }
        }
    }

    std::cout << Stack.size();
}