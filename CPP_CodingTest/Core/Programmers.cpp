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

