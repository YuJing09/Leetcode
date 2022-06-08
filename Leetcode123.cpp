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


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> left, right;
        int minum, maxium;
        int leftprofit, rightfit;
        leftprofit = 0, rightfit = 0;
        left.push_back(0);
        right.push_back(0);
        minum = prices[0];
        maxium = prices[prices.size() - 1 ];
        int diff1, diff2;
        int now_l, now_r;
        for (size_t i =1; i < prices.size(); ++i) {
          
        
                now_l = prices[i];
                now_r = prices[prices.size() - 1 - i];
                diff1 = now_l - minum;
                diff2 = maxium - now_r;
                
                leftprofit = diff1 > leftprofit ? diff1 : leftprofit;
                minum = now_l < minum ? now_l : minum;
                rightfit = diff2 > rightfit ? diff2 : rightfit;
                maxium = now_r > maxium ? now_r : maxium;
                left.push_back(leftprofit);
                right.push_back(rightfit);


            


        }
        int output=0;
        for (size_t i = 0; i < right.size(); ++i) {
           
            if ((right[right.size()-1-i] + left[i]) > output) {
                output = right[right.size()-i-1] + left[i];
            }
        }
        return output;
        }

    
};
int main() {


    Solution sol;
    vector<int> prices{1, 2, 4, 2, 5, 7, 2, 4, 9, 0
};
    cout<<sol.maxProfit(prices);
    
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