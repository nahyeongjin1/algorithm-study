#include <iostream>

constexpr uint32_t MOD = 1000000007;

uint64_t power(uint64_t base, uint64_t exp)
{
    uint64_t res = 1;
    base %= MOD;
    while (exp > 0)
    {
        if (exp % 2 == 1)
        {
            res = (res * base) % MOD;
        }
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

uint64_t mod_inverse(uint64_t n)
{
    return power(n, MOD - 2);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    uint32_t answer = 0;

    uint16_t m;
    std::cin >> m;
    for (uint16_t i = 0; i < m; i++)
    {
        uint32_t n, s;
        std::cin >> n >> s;

        uint64_t n_inverse = mod_inverse(n);

        uint64_t expected_value = (s * n_inverse) % MOD;
        answer = (answer + expected_value) % MOD;
    }

    std::cout << answer << '\n';
    return 0;
}