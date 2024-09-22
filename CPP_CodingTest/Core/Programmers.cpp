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

std::vector<std::string> Programmers::Problem_120907(std::vector<std::string> Quiz)
{
    std::vector<std::string> Result;

    for (const std::string& Str : Quiz)
    {
        int X = 0, Y = 0, Z = 0;
        char Oper = ' ', Equal = ' ';

        std::stringstream SS(Str);
        SS >> X >> Oper >> Y >> Equal >> Z;

        int Answer = 0;
        switch (Oper)
        {
        case '+':
            Answer = X + Y;
            break;
        case '-':
            Answer = X - Y;
            break;
        }

        (Answer == Z) ? Result.push_back("O") : Result.push_back("X");
    }

    return Result;
}

int Programmers::Problem_120909(int N)
{
    double Numd = sqrt(N);
    int Numl = static_cast<int>(Numd);
    return (Numd - Numl) == 0.0 ? 1 : 2;
}

std::string Programmers::Problem_120911(std::string String)
{
    std::transform(String.begin(), String.end(), String.begin(), ::tolower);
    std::sort(String.begin(), String.end());
    return String;
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

std::vector<int> Programmers::Problem_138477(int K, std::vector<int> Scores)
{
    std::vector<int> Result(Scores.size(), 0);

    std::multiset<int> Board;
    for (size_t i = 0; i < Scores.size(); ++i)
    {
        Board.insert(Scores[i]);
        if (K < Board.size())
        {
            Board.erase(Board.begin());
        }

        Result[i] = (*(Board.begin()));
    }

    return Result;
}

std::vector<int> Programmers::Problem_142086(std::string S)
{
    std::vector<int> Result(S.size(), 0), Alpha(26, -1);
    for (size_t i = 0; i < S.size(); ++i)
    {
        if (-1 == Alpha[S[i] - 'a'])
        {
            Result[i] = -1;
        }
        else
        {
            Result[i] = i - Alpha[S[i] - 'a'];
        }

        Alpha[S[i] - 'a'] = i;
    }

    return Result;
}

int Programmers::Problem_147355(std::string T, std::string P)
{
    int Result = 0, SizeP = P.size();
    for (size_t i = 0; i <= T.size() - SizeP; ++i)
    {
        std::string PartStr = T.substr(i, SizeP);
        if (PartStr <= P)
        {
            ++Result;
        }
    }

    return Result;
}

std::vector<int> Programmers::Problem_150370(std::string Today, std::vector<std::string> Terms, std::vector<std::string> Privacies)
{
    std::vector<int> Result;
    std::string Temp = "";
    int TodayDate = 0;

    {
        std::vector<int> TodayDateVec;
        std::stringstream SStream(Today);
        while (std::getline(SStream, Temp, '.'))
        {
            TodayDateVec.push_back(std::stoi(Temp));
        }

        TodayDate = (TodayDateVec[0] * 12 * 28) + (TodayDateVec[1] - 1) * 28 + TodayDateVec[2];
    }

    std::map<char, int> TermMap;
    for (size_t i = 0; i < Terms.size(); ++i)
    {
        int Month = 0;
        char Key = ' ';
        std::stringstream SStream(Terms[i]);
        SStream >> Key >> Month;
        TermMap[Key] = Month;
    }

    for (size_t i = 0; i < Privacies.size(); ++i)
    {
        char TermKey = Privacies[i].back();
        std::string StartDateStr = Privacies[i].substr(0, Privacies[i].size() - 2);

        int EndDate = 0;
        {
            std::vector<int> StartDateVec;
            std::stringstream SStream(StartDateStr);
            while (std::getline(SStream, Temp, '.'))
            {
                StartDateVec.push_back(std::stoi(Temp));
            }

            EndDate = (StartDateVec[0] * 12 * 28) + (StartDateVec[1] - 1 + TermMap[TermKey]) * 28 + StartDateVec[2] - 1;
        }

        if (EndDate < TodayDate)
        {
            Result.push_back(i + 1);
        }
    }

    return Result;
}

std::string Programmers::Problem_155652(std::string Str, std::string Skip, int Index)
{
    std::string Result = "";
    for (char CurChar : Str)
    {
        int RoopIdx = 0;
        int AlphaIdx = CurChar - 'a';
        while (RoopIdx < Index)
        {
            ++AlphaIdx;
            CurChar = 'a' + (AlphaIdx % 26);

            if (std::string::npos == Skip.find(CurChar))
            {
                ++RoopIdx;
            }
        }

        Result.push_back(CurChar);
    }

    return Result;
}

int Programmers::Problem_161989(int N, int M, std::vector<int> Section)
{
    int Result = 1, pivot = Section[0];
    for (const int v : Section)
    {
        if (v < pivot + M)
        {
            continue;
        }
        else
        {
            pivot = v;
            ++Result;
        }
    }

    return Result;
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

std::vector<std::vector<int>> Programmers::Problem_181830(std::vector<std::vector<int>> Arr)
{
    if (Arr.size() < Arr[0].size())
    {
        Arr.resize(Arr[0].size());
    }

    for (size_t i = 0; i < Arr.size(); ++i)
    {
        Arr[i].resize(Arr.size());
    }

    return Arr;
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

std::vector<int> Programmers::Problem_181844(std::vector<int> Arr, std::vector<int> Delete)
{
    std::vector<int> Result;

    for (const int& Num : Arr)
    {
        if (Delete.end() == std::find(Delete.begin(), Delete.end(), Num))
        {
            Result.push_back(Num);
        }
    }

    return Result;
}

std::string Programmers::Problem_181846(std::string A, std::string B)
{
    std::string Result = "";

    int Sum = 0;
    bool isHighTen = false;
    for (size_t i = 1; i <= std::max(A.size(), B.size()); ++i)
    {
        Sum += (A.size() >= i) ? A[A.size() - i] - '0' : 0;
        Sum += (B.size() >= i) ? B[B.size() - i] - '0' : 0;

        if (1 <= Sum / 10)
        {
            Sum %= 10;
            isHighTen = true;
        }

        Result = std::to_string(Sum) + Result;
        isHighTen ? Sum = 1, isHighTen = false : Sum = 0;
    }

    return Sum >= 1 ? "1" + Result : Result;
}

int Programmers::Problem_181849(std::string NumStr)
{
    int Result = std::accumulate(NumStr.begin(), NumStr.end(), 0, [=](int A, char B) { return A + (B - '0'); });
    return Result;
}

int Programmers::Problem_181851(std::vector<int> Rank, std::vector<bool> Attendance)
{
    std::vector<std::pair<int, int>> NewRank;
    for (size_t i = 0; i < Attendance.size(); ++i)
    {
        if (Attendance[i])
        {
            NewRank.push_back({ Rank[i], i });
        }
    }

    std::sort(NewRank.begin(), NewRank.end());

    return (10000 * NewRank[0].second) + (100 * NewRank[1].second) + NewRank[2].second;
}

int Programmers::Problem_181855(std::vector<std::string> StrArr)
{
    std::vector<int> SizeCount(31, 0);

    for (std::string& Str : StrArr)
    {
        ++SizeCount[Str.size()];
    }

    return *std::max_element(SizeCount.begin(), SizeCount.end());
}

int Programmers::Problem_181856(std::vector<int> Arr1, std::vector<int> Arr2)
{
    if (Arr1.size() != Arr2.size())
    {
        return Arr1.size() > Arr2.size() ? 1 : -1;
    }

    int SumArr1 = std::accumulate(Arr1.begin(), Arr1.end(), 0);
    int SumArr2 = std::accumulate(Arr2.begin(), Arr2.end(), 0);
    return SumArr1 > SumArr2 ? 1 : SumArr1 == SumArr2 ? 0 : -1;
}

std::vector<int> Programmers::Problem_181857(std::vector<int> Arr)
{
    int Size = 1;
    while (Size < Arr.size())
    {
        Size *= 2;
    }

    Arr.resize(Size);
    return Arr;
}

int Programmers::Problem_181865(std::string Binomial)
{
    int Result = 0;
    int Num1 = 0, Num2 = 0;
    char Oper;

    std::stringstream SStream(Binomial);
    SStream >> Num1 >> Oper >> Num2;

    switch (Oper)
    {
    case '+':
        Result = Num1 + Num2;
        break;
    case '-':
        Result = Num1 - Num2;
        break;
    case '*':
        Result = Num1 * Num2;
        break;
    }

    return Result;
}

std::vector<std::string> Programmers::Problem_181866(std::string String)
{
    std::vector<std::string> Result;

    std::string Temp = "";
    std::stringstream SStream(String);
    while (std::getline(SStream, Temp, 'x'))
    {
        if (!Temp.empty())
        {
            Result.push_back(Temp);
        }
    }

    std::sort(Result.begin(), Result.end());

    return Result;
}

std::vector<std::string> Programmers::Problem_181868(std::string String)
{
    std::vector<std::string> Result;

    std::string Temp = "";
    std::stringstream StringStream(String);
    while (StringStream >> Temp)
    {
        Result.push_back(Temp);
    }

    return Result;
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

