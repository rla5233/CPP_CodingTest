#include <iostream>
#include <vector>
#include <map>
#include <string>

// 1620
int main()
{
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
    
    int N = 0, M = 0;
    std::cin >> N >> M;

    std::vector<std::string> PoketmonVec(N);
    std::map<std::string, int> PoketmonMap = std::map<std::string, int>();

    for (int i = 0; i < N; i++)
    {
        std::string Input = "";
        std::cin >> Input;

        PoketmonMap[Input] = i + 1;
        PoketmonVec[i] = Input;
    }

    for (int i = 0; i < M; i++)
    {
        std::string Input = "";
        std::cin >> Input;

        std::map<std::string, int>::iterator FindIter = PoketmonMap.find(Input);
        if (FindIter != PoketmonMap.end())
        {
            std::cout << FindIter->second << "\n";
        }
        else
        {
            std::cout << PoketmonVec[stoi(Input) - 1] << "\n";
        }
    }}