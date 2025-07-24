/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 11444                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/11444                          #+#        #+#      #+#    */
/*   Solved: 2025/07/19 20:12:46 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <array>

using std::array;
using matrix = array<array<uint32_t, 2>, 2>;

constexpr uint32_t MOD = 1000000007;

matrix mat_mul(const matrix &A, const matrix &B)
{
    matrix result{};
    result[0][0] = ((static_cast<uint64_t>(A[0][0]) * B[0][0]) % MOD + (static_cast<uint64_t>(A[0][1]) * B[1][0]) % MOD) % MOD;
    result[0][1] = ((static_cast<uint64_t>(A[0][0]) * B[0][1]) % MOD + (static_cast<uint64_t>(A[0][1]) * B[1][1]) % MOD) % MOD;
    result[1][0] = ((static_cast<uint64_t>(A[1][0]) * B[0][0]) % MOD + (static_cast<uint64_t>(A[1][1]) * B[1][0]) % MOD) % MOD;
    result[1][1] = ((static_cast<uint64_t>(A[1][0]) * B[0][1]) % MOD + (static_cast<uint64_t>(A[1][1]) * B[1][1]) % MOD) % MOD;
    return result;
}

/**
 * Matrix Exponentiation by Squaring
 */
int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    uint64_t n; // [0, 2^64-1]
    std::cin >> n;

    if (n <= 1)
    {
        std::cout << n << '\n';
        return 0;
    }

    matrix result = {{{1, 0}, {0, 1}}};
    matrix A = {{{1, 1}, {1, 0}}};

    while (n > 0)
    {
        if (n & 1)
        {
            result = mat_mul(result, A);
        }
        A = mat_mul(A, A);
        n /= 2;
    }

    std::cout << result[1][0] << '\n';

    return 0;
}