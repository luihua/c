
#include "iostream"
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <algorithm>
#include <limits.h>
using namespace std;

struct myComp
{
    constexpr bool operator()(
        pair<int, int> const &a,
        pair<int, int> const &b)
        const noexcept
    {
        return a.second > b.second;
    }
};

class Solution
{
public:
    /**
     * @brief
     *
     * @param Ajmatrix vector<map<int,int>>图
     * @param s 起点端点
     * @param d 终点端点
     * @return int 最短路径
     */
    int smallestPath(vector<map<int, int>> &Ajmatrix, int s, int d)
    {
        int m = Ajmatrix.size();      // m表示端点数量
        vector<int> cost(m, INT_MAX); // 初始化cost数组，储存目前各端点到source的距离，INT_MAX表示无连接关系，0表示起点
        // vector<int> used(m);//记录各端点与起点的连接关系
        vector<int> path(m, -1); // 记录最短路径的指向关系
        cost[s] = 0;
        path[s] = INT_MIN;

        /*建立辅助优先队列,采取vector容器存储,队列元素为{端点号,端点到source的距离}，优先弹出端点到source的距离较小者*/
        priority_queue<pair<int, int>, vector<pair<int, int>>, myComp> Q;
        Q.push({s, 0});
        while (!Q.empty()) // 循环至队列空
        {
            auto ii = Q.top(); // 读取队头元素
            // used[ii.first]=1;
            Q.pop(); // 对头出队
            /*如果此端点到source的距离大于cost数组记录的距离或者暂未找到路径，读取队列下一元素*/
            if (ii.second > cost[ii.first] || cost[ii.first] == INT_MAX)
                continue;
            for (auto jj : Ajmatrix[ii.first]) // 遍历端点指向的所有其他端点
            {

                if (cost[ii.first] + jj.second < cost[jj.first])
                {
                    cost[jj.first] = cost[ii.first] + jj.second; /*i->j更新新路线*/
                    path[jj.first] = ii.first;

                    Q.push({jj.first, cost[jj.first]});
                }
            }
        }
        if (path[d] == -1)
            std::cout << "NO PATH" << std::endl;

        else
        {
            std::cout << d;
            while (path[d] != INT_MIN)
            {

                {
                    std::cout << "<-" << path[d];

                    path[d] = path[path[d]];
                }
            }
            std::cout << std::endl;
        }
        return cost[d];
    }
};

/*******************************************int main()*********************************************/
/**************************************************************************************************/
int main()
{
    int s, d;
    Solution S;
    /**
     * vector嵌套map实现图的存储，
     * vector下标表示端点，
     * map<key,value>表示弧，
     * key为弧头端点指向，value为权值
     */
    vector<map<int, int>> Graph;
    map<int, int> map1;
    std::cout << "source:" << "\n"
              << "destination:" << std::endl;
    cin >> s >> d;
    // map使用insert
    map1.insert(pair<int, int>(1, 2));
    map1.insert(pair<int, int>(3, 1));
    Graph.push_back(map1);
    map1.clear();
    map1.insert(pair<int, int>(4, 10));
    map1.insert(pair<int, int>(3, 3));
    Graph.push_back(map1);
    map1.clear();
    map1.insert(pair<int, int>(0, 4));
    map1.insert(pair<int, int>(5, 5));
    Graph.push_back(map1);
    map1.clear();
    map1.insert(pair<int, int>(4, 2));
    Graph.push_back(map1);
    map1.clear();
    Graph.push_back(map1);
    map1.insert(pair<int, int>(6, 2));
    Graph.push_back(map1);
    map1.clear();
    map1.insert(pair<int, int>(5, 1));
    Graph.push_back(map1);
    map1.clear();
    int length = S.smallestPath(Graph, s, d);
    if (length != INT_MAX)
        std::cout << "The length of the shortest path is" << " " << length << std::endl;

    return 0;
}