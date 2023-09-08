#include <iostream>
#include <string>

using std::string;

bool IsPrefix(string str, int len, int index, int sub_len);
bool IsKPeriodic(string str, int len, int k);

int main()
{
    string str = "abcabcabc";
    int len = str.length();
    int k = 5;

    if (IsKPeriodic(str, len, k))
    std::cout << ("Yes");
    else
    std::cout << ("No");
}

bool IsPrefix(string str, int len, int index, int sub_len)
{

    if (index + sub_len > len)
        return false;
    for (int i = 0; i < sub_len; i++)
    {
        if (str[index] != str[i])
            return false;
        index++;
    }
    return true;
}

bool IsKPeriodic(string str, int len, int k)
{
    for (int i = k; i < len; i += k)
        if (!IsPrefix(str, len, i, k))
            return false;
    return true;
}
