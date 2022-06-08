﻿// Leecode.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <string.h>
#include <bitset>
#include <algorithm>
#include <typeinfo>
#include <vector>
#include  <set>
#include <unordered_map>
#include <math.h>
#include<stack>
#include <queue>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode() :val(0), next(0) {};
    ListNode(int x) :val(x), next(0) {};
    ListNode(int x, ListNode* next) :val(x), next(next) {};
};


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(0), right(0) {};
    TreeNode(int x) : val(x), left(0), right(0) {};
    TreeNode(int x, TreeNode* left, TreeNode* right) :val(x), left(left), right(right) {};
};

template <class T>
void clear(T q) {
        T empty;
        swap(empty, q);
    }
struct Node {
    int val;
    Node* left;
    Node* right;
    Node* next;
    Node() :val(0), left(NULL), right(NULL), next(NULL) {};
    Node(int _val) :val(_val), left(NULL), right(NULL), next(NULL) {};
    Node(int _val, Node* _left, Node* _right, Node* _next) :val(_val), left(_left), right(_right), next(_next) {};
};
TreeNode* constructTree(vector<int> root) {
    TreeNode* output = 0;
    queue<TreeNode*> temp;
    int size;

    size = root.size();

    if (size == 0) {
        return output;
    }

    //int h = log2(size);
    output = new TreeNode(root[0]);
    temp.push(output);
    int m = 1;
    while (m < size) {

        if (root[m] != 0) {

            temp.front()->left = new TreeNode(root[m]);

            temp.push(temp.front()->left);
            ++m;
        }
        else {

            temp.front()->left = 0;
            ++m;
        }


        if (m < size) {

            if (root[m] != 0) {
                temp.front()->right = new TreeNode(root[m]);
                temp.push(temp.front()->right);
                ++m;
            }
            else {
                temp.front()->right = 0;
                ++m;
            }
        }


        temp.pop();

    }
    return output;



}
vector<vector<int>> levelorder(TreeNode* root) {
    vector<vector<int>> output;
    vector<int> temp;
    queue<TreeNode*> level;
    if (root) {
        temp.push_back(root->val);
        level.push(root);
        output.push_back(temp);

    }
    else {
        return output;
    }
    int size;
    while (level.size() >= 1) {

        temp.clear();
        size = level.size();
        for (size_t i = 0; i < size; ++i) {
            if (level.front()->left) {
                temp.push_back(level.front()->left->val);
                level.push(level.front()->left);
            }
            else {
                temp.push_back(NULL);

            }
            if (level.front()->right) {
                temp.push_back(level.front()->right->val);
                level.push(level.front()->right);
            }
            else {
                temp.push_back(NULL);

            }
            level.pop();
        }
        if (level.size() > 0) {
            output.push_back(temp);
        }


    }
    for (size_t i = 0; i < output.size(); ++i) {
        for (const auto l : output[i]) {
            cout << l << " ";
        }
        cout << endl;
    }
    return output;


}

int searchpath(TreeNode* root, int& maxpath) {
    if (!root->right && !root->left) {
        if (root->val > maxpath) {
            maxpath = root->val;
        }
        return root->val;
    }
    
    int right, left,path;
    if (root->right && root->left) {
        right = searchpath(root->right, maxpath);
        left = searchpath(root->left, maxpath);
        if (root->val > 0) {
            path = max(left+root->val, right+root->val);
            
            path = max(path, root->val);
        }
        else {
            path = max(left, right);
        }
        path = max(path, left + right + root->val);
        maxpath = max(path, maxpath);
        printf("root:%d path%d\n", root->val, maxpath);
        return max(max(right, left)+root->val,root->val);
    }
    else if (root->left && !root->right) {
        left = searchpath(root->left, maxpath);
        path = max(left, root->val);
        path = max(path, left + root->val);
        maxpath = max(path, maxpath);
        printf("root:%d path%d\n", root->val, maxpath);
        return max(root->val,left+root->val);
    }
    else {

        right = searchpath(root->right, maxpath);
        path = max(right, root->val);
        path = max(path, right + root->val);
        maxpath = max(path, maxpath);
        printf("root:%d path%d\n", root->val, maxpath);
        return max(root->val,right+root->val);
    }

}
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxpath = -10000;
        searchpath(root, maxpath);

        return maxpath;

    }
};
int main() {
    vector<int> root{-1,5,NULL,4,NULL,NULL,2,-4};
    TreeNode* tree= constructTree(root);

    Solution sol;
    cout<<sol.maxPathSum(tree);
  
    
}

// 執行程式: Ctrl + F5 或 [偵錯] > [啟動但不偵錯] 功能表
// 偵錯程式: F5 或 [偵錯] > [啟動偵錯] 功能表

// 開始使用的提示: 
//   1. 使用 [方案總管] 視窗，新增/管理檔案
//   2. 使用 [Team Explorer] 視窗，連線到原始檔控制
//   3. 使用 [輸出] 視窗，參閱組建輸出與其他訊息
//   4. 使用 [錯誤清單] 視窗，檢視錯誤
//   5. 前往 [專案] > [新增項目]，建立新的程式碼檔案，或是前往 [專案] > [新增現有項目]，將現有程式碼檔案新增至專案
//   6. 之後要再次開啟此專案時，請前往 [檔案] > [開啟] > [專案]，然後選取 .sln 檔案