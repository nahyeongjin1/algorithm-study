/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 10096                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/10096                          #+#        #+#      #+#    */
/*   Solved: 2025/03/04 21:15:32 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <string>
#include <vector>

using std::vector;

typedef unsigned long long ull;

constexpr ull BASE = 131;

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    uint64_t n;
    std::string s;
    std::cin >> n >> s;
    if (n % 2 == 0)
    {
        std::cout << "NOT POSSIBLE" << '\n';
        return 0;
    }

    uint64_t k = n / 2;

    // rolling hash 기법
    // 해시 배열과 거듭제곱 배열
    vector<ull> h(n + 1, 0), p(n + 1, 0);
    p[0] = 1;
    for (uint64_t i = 0; i < n; i++)
    {
        h[i + 1] = h[i] * BASE + (ull)(s[i]);
        p[i + 1] = p[i] * BASE;
    }

    // 구간 [l, r]의 해시를 O(1)에 구하는 람다 함수
    auto get_hash = [&](uint64_t l, uint64_t r) -> ull
    {
        if (l > r)
            return 0;
        return h[r + 1] - h[l] * p[r - l + 1];
    };

    // 오른쪽 절반은 후보에 따라 다르게 구성되지만,
    // i < k 인 경우 오른쪽 절반은 항상 s[k+1 ... 2*k] (길이 k)
    ull r_common = get_hash(k + 1, 2 * k);
    // i >= k 인 경우 왼쪽 절반은 항상 s[0 ... k-1]
    ull l_common = get_hash(0, k - 1);

    int valid_count = 0;
    ull first_r_hash = 0;
    std::string first_r = "";
    bool duplicate = false;

    // 각 삭제 위치 i에 대해 검사 (0 ~ n-1)
    for (uint64_t i = 0; i < n; i++)
    {
        ull left_hash = 0, right_hash = 0;
        if (i < k)
        {
            // 삭제가 왼쪽 절반에 있을 때
            // 왼쪽 절반 L = s[0 ... i-1] + s[i+1 ... k]
            left_hash = get_hash(0, i - 1) * p[k - i] + get_hash(i + 1, k);
            // 오른쪽 절반 R는 항상 s[k+1 ... 2*k]
            right_hash = r_common;
        }
        else
        {
            // 삭제가 오른쪽 절반에 있을 때
            // 왼쪽 절반 L = s[0 ... k-1] (변함없음)
            left_hash = l_common;
            // 오른쪽 절반 R = s[k ... i-1] + s[i+1 ... 2*k]
            right_hash = get_hash(k, i - 1) * p[2 * k - i] + get_hash(i + 1, 2 * k);
        }
        // 두 절반의 해시가 일치하면 후보
        if (left_hash == right_hash)
        {
            valid_count++;
            ull candidate_r_hash = right_hash; // 오른쪽 절반의 해시
            if (valid_count == 1)
            {
                first_r_hash = candidate_r_hash;
                // 첫 번째 유효 후보에 대해 실제 오른쪽 절반 문자열을 저장
                if (i < k)
                {
                    first_r = s.substr(k + 1, k);
                }
                else
                {
                    std::string part1 = s.substr(k, i - k);
                    std::string part2 = s.substr(i + 1, 2 * k - i);
                    first_r = part1 + part2;
                }
            }
            else
            {
                if (candidate_r_hash != first_r_hash)
                {
                    duplicate = true;
                    break;
                }
            }
        }
    }

    if (valid_count == 0)
    {
        std::cout << "NOT POSSIBLE" << "\n";
    }
    else if (duplicate)
    {
        std::cout << "NOT UNIQUE" << "\n";
    }
    else
    {
        std::cout << first_r << "\n";
    }

    return 0;
}
