// 15681
#include <iostream>
#include <vector>

using namespace std;

uint32_t N; // [2, 100_000]
uint32_t R; // [1, N]
uint32_t Q; // [1, 100_000]
uint32_t U;
uint32_t V;
vector<vector<uint32_t>> adj_list;
vector<uint32_t> child_count;

uint32_t traverse(uint32_t cur_root, uint32_t parent, vector<vector<uint32_t>> &adj_list)
{
    uint32_t count = 1;

    for (uint32_t child : adj_list[cur_root])
    {
        if (child == parent)
            continue;
        count += traverse(child, cur_root, adj_list);
    }

    child_count[cur_root] = count;
    return count;
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> N >> R >> Q;

    adj_list.resize(N, vector<uint32_t>(0)); // push_back 하기 위해 비워두기
    child_count.resize(N, 0);                // 본인은 traverse에서 포함시킴

    for (uint32_t i = 0; i < N - 1; i++)
    {
        cin >> U >> V;
        adj_list[U - 1].push_back(V - 1);
        adj_list[V - 1].push_back(U - 1);
    }

    traverse(R - 1, R - 1, adj_list); // 부모를 본인으로 하면 문제가 안 생길듯?

    /*입력으로 받은 노드의 서브트리 자식 개수 카운트*/
    for (uint32_t i = 0; i < Q; i++)
    {
        cin >> U;
        cout << child_count[U - 1] << '\n';
    }

    return 0;
}