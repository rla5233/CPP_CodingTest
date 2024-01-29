#include <iostream>
#include <vector>
#include <map>

// 9322
int main()
{
    //std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
    int TestCase = 0;
    std::cin >> TestCase;

    for (int i = 0; i < TestCase; i++)
    {
        int WordCount = 0;
        std::cin >> WordCount;

        std::string Word = "";
        std::map<std::string, int> FirstKey;
        for (int idx = 0; idx < WordCount; idx++)
        {
            std::cin >> Word;
            FirstKey[Word] = idx;
        }

        std::vector<int> Order(WordCount);
        for (int idx = 0; idx < WordCount; idx++)
        {
            std::cin >> Word;
            Order[idx] = FirstKey[Word];
        }

        std::vector<std::string> OrgWordVec(WordCount);
        for (int idx = 0; idx < WordCount; idx++)
        {
            std::cin >> Word;
            OrgWordVec[Order[idx]] = Word;
        }

        for (std::string& Word : OrgWordVec)
        {
            std::cout << Word << " ";
        }
        std::cout << "\n";
    }
}