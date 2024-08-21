#include "PreCompile.h"
#include "Programmers.h"

Programmers::Programmers()
{
}
Programmers::~Programmers()
{
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

