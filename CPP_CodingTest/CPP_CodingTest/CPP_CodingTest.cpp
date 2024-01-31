#include <iostream>
#include <string>
#include <stack>

// 17413
int main()
{
    //std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
    std::string Word = "";
    getline(std::cin, Word);

    std::string Result = "";
    std::stack<char> WordStack;
    for (int i = 0; i < Word.size(); i++)
    {
        if (WordStack.empty())
        {
            if (Word[i] == '<')
            {
                Result += Word[i];
            }
         
            WordStack.push(Word[i]);
        }
        else if (Word[i] == '<')
        {
            while (false == WordStack.empty())
            {
                Result += WordStack.top();
                WordStack.pop();
            }

            WordStack.push(Word[i]);
            Result += Word[i];
        }
        else if (WordStack.top() == '<')
        {
            if (Word[i] == '>')
            {
                WordStack.pop();
            }

            Result += Word[i];
        }
        else if (Word[i] == ' ')
        {
            while (false == WordStack.empty())
            {
                Result += WordStack.top();
                WordStack.pop();
            }

            Result += Word[i];
        }
        else
        {
            WordStack.push(Word[i]);
        }
    }

    while (false == WordStack.empty())
    {
        Result += WordStack.top();
        WordStack.pop();
    }

    std::cout << Result;
}