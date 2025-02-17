#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

vector<pair<int, int>> factorize(int n)
{
    vector<pair<int, int>> factors;
    for (int div = 2; div * div <= n; div++)
    {
        int count = 0;
        while (n % div == 0)
        {
            count++;
            n /= div;
        }
        if (count > 0)
        {
            factors.push_back({div, count});
        }
    }
    if (n > 1)
    {
        factors.push_back({n, 1});
    }
    return factors;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b;
    cin >> a >> b;

    int A = a, B = b;

    vector<pair<int, int>> fa = factorize(a);
    vector<pair<int, int>> fb = factorize(b);

    long long gcd = 1, lcm = 1;

    int i = 0, j = 0;
    while (i < fa.size() && j < fb.size())
    {
        if (fa[i].first == fb[j].first)
        {
            int prime = fa[i].first;
            int expGCD = min(fa[i].second, fb[j].second);
            int expLCM = max(fa[i].second, fb[j].second);
            gcd *= (int)pow(prime, expGCD);
            lcm *= (int)pow(prime, expLCM);
            i++;
            j++;
        }
        else if (fa[i].first < fb[j].first)
        {
            lcm *= (int)pow(fa[i].first, fa[i].second);
            i++;
        }
        else
        {
            lcm *= (int)pow(fb[j].first, fb[j].second);
            j++;
        }
    }

    while (i < fa.size())
    {
        lcm *= (int)pow(fa[i].first, fa[i].second);
        i++;
    }
    while (j < fb.size())
    {
        lcm *= (int)pow(fb[j].first, fb[j].second);
        j++;
    }

    cout << gcd << "\n"
         << lcm << "\n";

    return 0;
}
