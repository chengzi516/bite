#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <queue>
#include <map>
#include <string>

using namespace std;

// 定义哈夫曼树节点结构
struct HuffmanNode {
    char data;
    int frequency;
    HuffmanNode* left;
    HuffmanNode* right;
    HuffmanNode(char data, int frequency) : data(data), frequency(frequency), left(nullptr), right(nullptr) {}
};

// 定义优先队列的比较函数，用于构建最小堆
struct Compare {
    bool operator() (HuffmanNode* a, HuffmanNode* b) {
        return a->frequency > b->frequency;
    }
};

// 构建哈夫曼树
HuffmanNode* buildHuffmanTree(map<char, int>& freqMap) {
    priority_queue<HuffmanNode*, vector<HuffmanNode*>, Compare> minHeap;

    // 将字符和频率信息存储到优先队列中。。

    for (auto entry : freqMap) {
        HuffmanNode* node = new HuffmanNode(entry.first, entry.second);
        minHeap.push(node);
    }

    while (minHeap.size() > 1) {
        //选出最小的两个fre
        HuffmanNode* left = minHeap.top();
        minHeap.pop();
        HuffmanNode* right = minHeap.top();
        minHeap.pop();

        HuffmanNode* parent = new HuffmanNode('\0', left->frequency + right->frequency);
        parent->left = left;
        parent->right = right;
        minHeap.push(parent);
    }

    return minHeap.top();
}

// 生成哈夫曼编码
void generateHuffmanCodes(HuffmanNode* root, string code, map<char, string>& huffmanCodes) {
    if (root == nullptr) {
        return;
    }
    if (root->data != '\0') {
        huffmanCodes[root->data] = code;
    }
    generateHuffmanCodes(root->left, code + "0", huffmanCodes);
    generateHuffmanCodes(root->right, code + "1", huffmanCodes);

}

int main() {
    string input = "this is an example for huffman encoding";
    map<char, int> freqMap;

    // 统计字符频率
    for (char c : input) {
        if (c != ' ') {
            freqMap[c]++;
        }
    }

    HuffmanNode* root = buildHuffmanTree(freqMap);
    map<char, string> huffmanCodes;
    generateHuffmanCodes(root, "", huffmanCodes);

    cout << "Huffman Codes:" << endl;
    for (auto entry : huffmanCodes) {
        cout << entry.first << ": " << entry.second << endl;
    }

    return 0;
}

