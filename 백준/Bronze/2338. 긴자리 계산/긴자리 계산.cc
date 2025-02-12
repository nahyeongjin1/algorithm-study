/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2338                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2338                           #+#        #+#      #+#    */
/*   Solved: 2025/02/07 20:12:05 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

void fill_zero(std::string &a, std::string &b)
{
    while (a.length() != b.length())
    {
        if (a.length() > b.length())
        {
            b = '0' + b;
        }
        else
        {
            a = '0' + a;
        }
    }
    return;
}

void eliminate_zero(std::string &output)
{
    while (output.length() > 1 && output.at(0) == '0')
    {
        output.erase(0, 1);
    }
}

std::string abs_add(std::string a, std::string b)
{
    short carry = 0, calc;
    std::string output = "";

    fill_zero(a, b);
    std::reverse(a.begin(), a.end());
    std::reverse(b.begin(), b.end());

    for (auto i = 0; i < a.length(); i++)
    {
        calc = (a.at(i) - '0') + (b.at(i) - '0') + carry;
        if (calc >= 10)
        {
            carry = 1;
            calc -= 10;
        }
        else
        {
            carry = 0;
        }
        output += calc + '0';
    }
    if (carry == 1)
    {
        output += '1';
    }
    std::reverse(output.begin(), output.end());

    return output;
};

std::string abs_subtract(std::string a, std::string b)
{
    std::string output = "";

    fill_zero(a, b);
    for (auto i = 0; i < a.length(); i++)
    {
        a.at(i) = '9' - a.at(i) + '0';
    }
    output = abs_add(a, b);
    for (auto i = 0; i < output.length(); i++)
    {
        output.at(i) = '9' - output.at(i) + '0';
    }
    eliminate_zero(output);

    return output;
};

std::string add(std::string a, std::string b)
{
    std::string signA = "";
    std::string signB = "";
    std::string output = "";

    if (a.at(0) == '-')
    {
        signA += '-';
        a.erase(0, 1);
    }
    if (b.at(0) == '-')
    {
        signB += '-';
        b.erase(0, 1);
    }

    if (signA == signB)
    {
        output = signA + abs_add(a, b);
    }
    else
    {
        if (a == b)
        {
            return "0";
        }

        if (a.length() > b.length())
        {
            output = signA + abs_subtract(a, b);
        }
        else if (a.length() < b.length())
        {
            output = signB + abs_subtract(b, a);
        }
        else
        {
            if (a > b)
            {
                output = signA + abs_subtract(a, b);
            }
            else
            {
                output = signB + abs_subtract(b, a);
            }
        }
    }

    return output;
};

std::string subtract(std::string a, std::string b)
{
    std::string signA = "";
    std::string signB = "";
    std::string output = "";

    if (a.at(0) == '-')
    {
        signA += '-';
        a.erase(0, 1);
    }
    if (b.at(0) == '-')
    {
        signB += '-';
        b.erase(0, 1);
    }

    if (signA == signB)
    {
        if (a == b)
        {
            return "0";
        }

        bool aIsGreater;
        if (a.length() != b.length())
        {
            aIsGreater = a.length() > b.length();
        }
        else
        {
            aIsGreater = a > b;
        }

        if ((signA == "" && aIsGreater) || (signA == "-" && !aIsGreater))
        {
            output = abs_subtract(aIsGreater ? a : b, aIsGreater ? b : a);
        }
        else
        {
            output = "-" + abs_subtract(aIsGreater ? a : b, aIsGreater ? b : a);
        }
    }
    else
    {
        output = signA + abs_add(a, b);
    }

    return output;
};

std::string multiply(std::string a, std::string b)
{
    // 0인 경우 바로 처리
    if (a == "0" || b == "0")
        return "0";

    // 부호 처리
    bool neg = false;
    if (a[0] == '-')
    {
        neg = !neg;
        a.erase(0, 1);
    }
    if (b[0] == '-')
    {
        neg = !neg;
        b.erase(0, 1);
    }

    int n = a.size(), m = b.size();
    std::vector<int> result(n + m, 0);

    // 뒤집어서 계산
    std::reverse(a.begin(), a.end());
    std::reverse(b.begin(), b.end());

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            result[i + j] += (a[i] - '0') * (b[j] - '0');
        }
    }

    // 캐리 처리
    for (int i = 0; i < result.size(); i++)
    {
        if (result[i] >= 10)
        {
            if (i + 1 < result.size())
                result[i + 1] += result[i] / 10;
            result[i] %= 10;
        }
    }

    // 결과 벡터를 문자열로 변환 (뒤집힌 상태)
    while (result.size() > 1 && result.back() == 0)
        result.pop_back();

    std::string output = "";
    for (int digit : result)
        output.push_back(digit + '0');

    // 다시 뒤집어서 정방향으로
    std::reverse(output.begin(), output.end());

    if (neg)
        output = "-" + output;

    return output;
}

int main()
{
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    std::string a, b;

    std::cin >> a >> b;

    std::cout
        << add(a, b) << '\n'
        << subtract(a, b) << '\n'
        << multiply(a, b) << '\n';

    return 0;
}