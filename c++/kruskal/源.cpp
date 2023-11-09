#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 定义一个边的结构体，包括起点、终点和权重
struct Edge {
    int start, end, weight;

    // 自定义比较函数，用于将边按权重升序排序
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

// 定义并查集（Disjoint Set）用于判断两个顶点是否在同一个集合中
struct DisjointSet {
    vector<int> parent, rank;

    // 初始化并查集
    DisjointSet(int size) {
        parent.resize(size);
        rank.resize(size, 0);
        for (int i = 0; i < size; i++) {
            parent[i] = i;
        }
    }

    // 查找根节点，并进行路径压缩
    int find(int x) {
        if (x != parent[x]) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    // 合并两个集合
    void unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            }
            else if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            }
            else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};

// Kruskal算法用于生成最小生成树
vector<Edge> kruskal(vector<Edge>& edges, int numVertices) {
    vector<Edge> mst; // 存储最小生成树的边
    sort(edges.begin(), edges.end()); // 按权重升序排序

    DisjointSet dsu(numVertices);

    for (const Edge& edge : edges) {
        int start = edge.start;
        int end = edge.end;

        if (dsu.find(start) != dsu.find(end)) {
            mst.push_back(edge);
            dsu.unionSets(start, end);
        }
    }

    return mst;
}

int main() {
    int numVertices, numEdges;
    cout << "输入顶点数和边数: ";
    cin >> numVertices >> numEdges;

    vector<Edge> edges;
    cout << "输入每条边的起点、终点和权重:" << endl;

    for (int i = 0; i < numEdges; i++) {
        Edge edge;
        cin >> edge.start >> edge.end >> edge.weight;
        edges.push_back(edge);
    }

    vector<Edge> mst = kruskal(edges, numVertices);

    cout << "最小生成树的边:" << endl;
    for (const Edge& edge : mst) {
        cout << edge.start << " - " << edge.end << " (" << edge.weight << ")" << endl;
    }

    return 0;
}
