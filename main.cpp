#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <queue>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <sstream>
#include <math.h>
#include <list>
#include <memory>
#include <set>
#include <map>
#include <windows.h>
#include <stdio.h>
#include <unordered_set>
#include <bitset>

using namespace std;

struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };

struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> p;
        if (!root) p.push(root);
        while (!p.empty())
        {
            TreeNode* tmp = p.top();
            p.pop();
            if (!tmp) continue;
            res.emplace_back(tmp->val);
            if (tmp->right) p.push(tmp->right);
            if (tmp->left) p.push(tmp->left);
        }
        return res;
    }

    void Pre(TreeNode* root, vector<int> &res)
    {
        if (!root) return;
        res.emplace_back(root->val);
        if (root->left != NULL) Pre(root->left, res);
        if (root->right != NULL) Pre(root->right, res);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> p;
        TreeNode* t = root;
        while (!p.empty() || t)
        {
            while (t)
            {
                p.push(t);
                t = t->left;
            }
            if (!p.empty())
            {
                TreeNode* tmp = p.top();
                p.pop();
                res.emplace_back(t->val);
                t = t->right;
            }
        }
        return res;
    }

    void In(TreeNode* root, vector<int> &res)
    {
        if (!root) return;
        if (root->left != NULL) In(root->left, res);
        res.emplace_back(root->val);
        if (root->right != NULL) In(root->right, res);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<pair<TreeNode*, bool>> s;
        if (root) s.push(make_pair(root, false));
        while (!s.empty())
        {
            pair<TreeNode*, bool> p = s.top();
            s.pop();
            bool visit = p.second;
            if (!p.first) continue;
            if (visit) res.emplace_back(p.first->val);
            else
            {
                s.push(make_pair(p.first, true));
                if (p.first->right) s.push(make_pair(p.first->right, false));
                if (p.first->left) s.push(make_pair(p.first->left, false));
            }
        }
        return res;
    }

    void Post(TreeNode* root, vector<int> &res)
    {
        if (!root) return;
        if (root->left != NULL) Post(root->left, res);
        if (root->right != NULL) Post(root->right, res);
        res.emplace_back(root->val);
    }
};

int main()
{
    int a = 1;
    shared_ptr<int> p;
    *p = a;
    shared_ptr<int> p1 = make_shared<int>(2);
    cout << p.use_count() << endl;
    cout << *p << endl;
    cout << p1 << endl;
    cout << *p1 << endl;
    return 0;
}