#include <iostream>
#include <stack>

// 3986
int main()
{
    //std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
    int N = 0;
    std::cin >> N;

    int count = 0;
    for (int i = 0; i < N; i++)
    {
        std::string Word = "";
        std::cin >> Word;

        std::stack<char> Stack = std::stack<char>();
        for (int i = 0; i < Word.size(); i++)
        {
            if (Stack.empty() || Stack.top() != Word[i])
            {
                Stack.push(Word[i]);
            }
            else
            {
                Stack.pop();
            }
        }

        if (Stack.empty())
        {
            ++count;
        }
    }

    std::cout << count;
}