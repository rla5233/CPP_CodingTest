#include "PreCompile.h"
#include "Programmers.h"

Programmers::Programmers()
{
}
Programmers::~Programmers()
{
}

std::string Programmers::Problem_12899(int N)
{
    std::string Answer = "";

    while (N != 0)
    {
        int Mod = N % 3;

        N /= 3;
        if (0 == Mod)
        {
            --N;
        }

        Answer = "412"[Mod] + Answer;
    }

    return Answer;
}
int Programmers::Problem_120956(std::vector<std::string> Babbling)
{
    int Answer = 0;
    std::vector<std::string> Words = { "aya", "ye", "woo", "ma" };
    std::vector<int> Count(Babbling.size(), 0);

    for (size_t i = 0; i < Babbling.size(); ++i)
    {
        for (std::string& Word : Words)
        {
            if (std::string::npos != Babbling[i].find(Word))
            {
                Count[i] += static_cast<int>(Word.size());
            }
        }

        if (Babbling[i].size() == Count[i])
        {
            ++Answer;
        }
    }

    return Answer;
}
std::vector<int> Programmers::Problem_176963(std::vector<std::string> Name, std::vector<int> Yearning, std::vector<std::vector<std::string>> Photo)
{
    std::unordered_map<std::string, int> NameYearning;
    for (size_t i = 0; i < Name.size(); ++i)
    {
        NameYearning[Name[i]] = Yearning[i];
    }

    std::vector<int> Result;
    for (std::vector<std::string>& Names : Photo)
    {
        int Score = 0;
        for (std::string& CurName : Names)
        {
            if (NameYearning.end() != NameYearning.find(CurName))
            {
                Score += NameYearning[CurName];
            }
        }

        Result.push_back(Score);
    }

    return Result;
}
std::vector<std::string> Programmers::Problem_178871(std::vector<std::string> Players, std::vector<std::string> Callings)
{
    std::map<std::string, int> PlayersIndex;
    for (int i = 0; i < Players.size(); ++i)
    {
        PlayersIndex[Players[i]] = i;
    }

    for (int i = 0; i < Callings.size(); ++i)
    {
        std::string FrontPlayer = Players[PlayersIndex[Callings[i]]];
        std::string BackPlayer = Players[PlayersIndex[Callings[i]] - 1];

        std::swap(Players[PlayersIndex[Callings[i]]], Players[PlayersIndex[Callings[i]] - 1]);

        --PlayersIndex[FrontPlayer];
        ++PlayersIndex[BackPlayer];
    }

    return Players;
}
std::vector<std::vector<int>> Programmers::Problem_181832(int N)
{
    std::vector<std::vector<int>> Answer(N, std::vector<int>(N, -1));

    std::vector<int> dx = { 1, 0, -1, 0 };
    std::vector<int> dy = { 0, 1, 0, -1 };

    int DirIndex = 0, NCount = 1, y = 0, x = 0;
    while (N * N >= NCount)
    {
        Answer[y][x] = NCount;
        ++NCount;

        int NextX = x + dx[DirIndex];
        int NextY = y + dy[DirIndex];

        if (NextX < 0 || NextX >= Answer[y].size() || NextY < 0 || NextY >= Answer.size() || -1 != Answer[NextY][NextX])
        {
            DirIndex = ++DirIndex % 4;
        }

        x += dx[DirIndex];
        y += dy[DirIndex];
    }

    return Answer;
}
std::vector<int> Programmers::Problem_181897(int N, std::vector<int> Slicer, std::vector<int> Num_list)
{
    std::vector<int> Result;

    int Start = 0, End = 0, InterVal = 0;
    switch (N)
    {
    case 1:
        Start = 0;
        End = Slicer[1];
        InterVal = 1;
        break;
    case 2:
        Start = Slicer[0];
        End = static_cast<int>(Num_list.size() - 1);
        InterVal = 1;
        break;
    case 3:
        Start = Slicer[0];
        End = Slicer[1];
        InterVal = 1;
        break;
    case 4:
        Start = Slicer[0];
        End = Slicer[1];
        InterVal = Slicer[2];
        break;
    }

    for (int i = Start; i <= End; i += InterVal)
    {
        Result.push_back(Num_list[i]);
    }

    return Result;
}
std::vector<int> Programmers::Problem_181893(std::vector<int> Arr, std::vector<int> Query)
{
    std::vector<int> Result = Arr;

    for (int i = 0; i < Query.size(); ++i)
    {
        if (0 == i % 2)
        {
            Result = std::vector(Result.begin(), Result.begin() + Query[i] + 1);
        }
        else
        {
            Result = std::vector(Result.begin() + Query[i], Result.end());
        }
    }

    return Result;
}
int Programmers::Problem_181916(int A, int B, int C, int D)
{
    std::vector<int> Table(6, 0);
    ++Table[A - 1]; ++Table[B - 1]; ++Table[C - 1]; ++Table[D - 1];
    std::vector<std::vector<int>> Nums(5);

    for (int i = 0; i < static_cast<int>(Table.size()); ++i)
    {
        Nums[Table[i]].push_back(i + 1);
    }

    if (!Nums[4].empty())
    {
        return 1111 * Nums[4][0];
    }
    else if (!Nums[3].empty())
    {
        return static_cast<int>(pow(10 * Nums[3][0] + Nums[1][0], 2));
    }
    else if (Nums[2].size() == 2)
    {
        return (Nums[2][0] + Nums[2][1]) * abs(Nums[2][0] - Nums[2][1]);
    }
    else if (Nums[2].size() == 1)
    {
        return Nums[1][0] * Nums[1][1];
    }
    else
    {
        return *std::min_element(Nums[1].begin(), Nums[1].end());
    }
}
std::vector<int> Programmers::Problem_181921(int L, int R)
{
    std::vector<int> Answer;

    int CurNum = 5, Index = 1;
    while (R >= CurNum)
    {
        if (L <= CurNum && R >= CurNum)
        {
            Answer.push_back(CurNum);
        }

        ++Index;

        int Dex = Index;
        std::string Bin = "";
        while (Dex >= 2)
        {
            Bin = "01"[Dex % 2] + Bin;
            Dex /= 2;
        }

        if (1 == Dex)
        {
            Bin = "1" + Bin;
        }

        CurNum = std::stoi(Bin) * 5;
    }

    return Answer.empty() ? std::vector<int>(1, -1) : Answer;
}
std::vector<std::vector<int>> Programmers::Problem_250121(std::vector<std::vector<int>> Data, std::string Ext, int Val_Ext, std::string Sort_By)
{
    std::vector<std::vector<int>> Answer;

    std::map<std::string, int> DataIndex;
    DataIndex["code"] = 0;
    DataIndex["date"] = 1;
    DataIndex["maximum"] = 2;
    DataIndex["remain"] = 3;

    for (int i = 0; i < Data.size(); ++i)
    {
        if (Val_Ext > Data[i][DataIndex[Ext]])
        {
            Answer.push_back(Data[i]);
        }
    }

    sort(Answer.begin(), Answer.end(), [&](const std::vector<int>& A, const std::vector<int>& B)
        {
            return A[DataIndex[Sort_By]] < B[DataIndex[Sort_By]];
        }
    );

    return Answer;
}
int Programmers::Problem_250125(std::vector<std::vector<std::string>> Board, int H, int W)
{
    int N = static_cast<int>(Board.size());
    int Count = 0;

    std::vector<int> dH = { 0, 1, -1, 0 };
    std::vector<int> dW = { 1, 0, 0, -1 };

    for (int i = 0; i < 3; ++i)
    {
        int H_Check = H + dH[i];
        int W_Check = W + dW[i];

        if (0 > H_Check || N <= H_Check || 0 > W_Check || N <= W_Check)
        {
            continue;
        }

        if (Board[H][W] == Board[H_Check][W_Check])
        {
            ++Count;
        }
    }

    return Count;
}
int Programmers::Problem_250137(std::vector<int> Bandage, int Health, std::vector<std::vector<int>> Attacks)
{
	int MaxHp = Health;
    int CurHp = MaxHp;

    int AttackIndex = 0;
    int HealTime = 0;
    int TotalSecond = Attacks[Attacks.size() - 1][0];
    for (int i = 1; i <= TotalSecond; ++i)
    {
        if (i == Attacks[AttackIndex][0])
        {
            CurHp -= Attacks[AttackIndex][1];
            HealTime = 0;
            ++AttackIndex;

            if (0 >= CurHp)
            {
                return -1;
            }
        }
        else
        {
            CurHp += Bandage[1];
            ++HealTime;

            if (HealTime == Bandage[0])
            {
                CurHp += Bandage[2];
                HealTime = 0;
            }

            if (CurHp > MaxHp)
            {
                CurHp = MaxHp;
            }
        }
    }

    return CurHp;
}
int Programmers::Problem_258712(std::vector<std::string> Friends, std::vector<std::string> Gifts)
{
    // Set Index
    std::map<std::string, int> FriendsIdx;
    for (int i = 0; i < Friends.size(); ++i)
    {
        FriendsIdx[Friends[i]] = i;
    }

    // Set GiftInfo, GiftIndex
    std::vector<int> GiftIdx(FriendsIdx.size(), 0);
    std::vector<std::vector<int>> GiftsInfo(FriendsIdx.size(), std::vector<int>(FriendsIdx.size(), 0));
    for (int i = 0; i < Gifts.size(); ++i)
    {
        std::string Sender = Gifts[i].substr(0, Gifts[i].find(' '));
        std::string Receiver = Gifts[i].substr(Gifts[i].find(' ') + 1);

        ++GiftsInfo[FriendsIdx[Sender]][FriendsIdx[Receiver]];

        --GiftIdx[FriendsIdx[Receiver]];
        ++GiftIdx[FriendsIdx[Sender]];
    }

    // Set Result
    std::vector<int> Result(FriendsIdx.size(), 0);
    for (int i = 0; i < Friends.size(); ++i)
    {
        int Sender = FriendsIdx[Friends[i]];
        for (int Receiver = 0; Receiver < GiftsInfo[Sender].size(); ++Receiver)
        {
            if (Sender == Receiver || GiftsInfo[Sender][Receiver] < GiftsInfo[Receiver][Sender])
            {
                continue;
            }

            if (GiftsInfo[Sender][Receiver] > GiftsInfo[Receiver][Sender] || GiftIdx[Sender] > GiftIdx[Receiver])
            {
                ++Result[Sender];
            }
        }
    }

    return *std::max_element(Result.begin(), Result.end());
}

