#include <iostream>
#include <vector>
#include <queue>
#include <stack>

int main ()
{
    // ========================================================================
    // グラフを定義
    // ========================================================================

    std::vector<std::vector<int>> graph{{1, 2},
                                        {3, 4},
                                        {5, 6},
                                        {},
                                        {7, 8},
                                        {},
                                        {},
                                        {},
                                        {}};


    // ========================================================================
    // 幅優先探索: breadth first search
    // ========================================================================

    std::queue<int> que;
    std::vector<int> bfs_result_array;
    que.push(0);
    while(!que.empty())
    {
        // 要素を取り出す
        int target_iter = que.front();
        que.pop();

        // 探索順に格納
        bfs_result_array.push_back(target_iter);

        // 隣接するノードがあるならリストに追加
        if (!graph[target_iter].empty())
        {
            for (int i = 0; i < graph[target_iter].size(); i++)
            {
                que.push(graph[target_iter][i]);
            }
        }
    }
    // 探索順結果
    std::cout << "BFS RESULT" << std::endl;
    for (int i = 0; i < bfs_result_array.size(); i++)
    {
        std::cout << bfs_result_array[i] << std::endl;
    }


    // ========================================================================
    // 深さ優先探索: depth first search
    // ========================================================================

    std::stack<int> sta;
    std::vector<int> dfs_result_array;
    sta.push(0);
    while(!sta.empty())
    {
        // 要素を取り出す
        int target_iter = sta.top();
        sta.pop();

        // 探索順に格納
        dfs_result_array.push_back(target_iter);

        // 隣接ノードがあればリストに追加
        if (!graph[target_iter].empty())
        {
            for (int i = 0; i < graph[target_iter].size(); i++)
            {
                sta.push(graph[target_iter][i]);
            }
        }
    }

    // 探索順結果
    std::cout << "DFS RESULT" << std::endl;
    for (int i = 0; i < dfs_result_array.size(); i++)
    {
        std::cout << dfs_result_array[i] << std::endl;
    }

}
