#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 根据数组构造二叉树
TreeNode* ConstructTreeNode(const vector<int>& nums) {
    TreeNode* root = nullptr;
    if (nums.empty()) {
        return root;
    }
    vector<TreeNode*> nodes;
    int n = nums.size();
    // 将输入的数值数组先转化为二叉树节点数组
    for (int i = 0; i < n; i++) {
        TreeNode* node = nullptr;
        // 数值数组中用 -1 表示 nullptr
        if (nums[i] != -1) {
            node = new TreeNode(nums[i]);
        }
        nodes.emplace_back(node);
    }
    root = nodes[0];
    for (int i = 0; i * 2 + 1 < n; i++) {
        if (nodes[i] != nullptr) {
            // 线性存储转链式存储的关键逻辑
            nodes[i]->left = nodes[i * 2 + 1];
            if (i * 2 + 2 < n) {
                nodes[i]->right = nodes[i * 2 + 2];
            }
        }
    }
    return root;
}

// 层序打印二叉树
void PrintBinaryTree(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    queue<TreeNode*> nodes;
    nodes.push(root);
    vector<vector<int>> res;
    while (!nodes.empty()) {
        // n 为该层节点数
        int n = nodes.size();
        vector<int> vec;
        for (int i = 0; i < n; i++) {
            TreeNode* node = nodes.front();
            nodes.pop();
            if (node != nullptr) {
                vec.emplace_back(node->val);
                nodes.push(node->left);
                nodes.push(node->right);
            }
            else {
                vec.emplace_back(-1);
            }
        }
        res.emplace_back(vec);
    }
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<int> vec = {4,1,6,0,2,5,7,-1,-1,-1,3,-1,-1,-1,8};
    TreeNode* root = ConstructTreeNode(vec);
    PrintBinaryTree(root);
    return 0;
}