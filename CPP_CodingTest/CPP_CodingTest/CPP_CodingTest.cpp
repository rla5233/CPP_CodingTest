#include <iostream>
#include <set>

// 14425
int main()
{
    //std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
    int N = 0, M = 0;
    std::cin >> N >> M;

    std::set<std::string> WordSet;
    for (int i = 0; i < N; i++)
    {
        std::string Word = "";
        std::cin >> Word;
        WordSet.insert(Word);
    }

    int Count = 0;
    for (int i = 0; i < M; i++)
    {
        std::string Word = "";
        std::cin >> Word;
        if (WordSet.contains(Word))
        {
            ++Count;
        }
    }

    std::cout << Count;
}