#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ����һ���ߵĽṹ�壬������㡢�յ��Ȩ��
struct Edge {
    int start, end, weight;

    // �Զ���ȽϺ��������ڽ��߰�Ȩ����������
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

// ���岢�鼯��Disjoint Set�������ж����������Ƿ���ͬһ��������
struct DisjointSet {
    vector<int> parent, rank;

    // ��ʼ�����鼯
    DisjointSet(int size) {
        parent.resize(size);
        rank.resize(size, 0);
        for (int i = 0; i < size; i++) {
            parent[i] = i;
        }
    }

    // ���Ҹ��ڵ㣬������·��ѹ��
    int find(int x) {
        if (x != parent[x]) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    // �ϲ���������
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

// Kruskal�㷨����������С������
vector<Edge> kruskal(vector<Edge>& edges, int numVertices) {
    vector<Edge> mst; // �洢��С�������ı�
    sort(edges.begin(), edges.end()); // ��Ȩ����������

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
    cout << "���붥�����ͱ���: ";
    cin >> numVertices >> numEdges;

    vector<Edge> edges;
    cout << "����ÿ���ߵ���㡢�յ��Ȩ��:" << endl;

    for (int i = 0; i < numEdges; i++) {
        Edge edge;
        cin >> edge.start >> edge.end >> edge.weight;
        edges.push_back(edge);
    }

    vector<Edge> mst = kruskal(edges, numVertices);

    cout << "��С�������ı�:" << endl;
    for (const Edge& edge : mst) {
        cout << edge.start << " - " << edge.end << " (" << edge.weight << ")" << endl;
    }

    return 0;
}
