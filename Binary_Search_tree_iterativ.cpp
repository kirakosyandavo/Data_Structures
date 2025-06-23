#include <iostream>
#include <stack>
using namespace std;

template <typename T>
class BST {
    struct TreeNode {
        T value;
        TreeNode* left;
        TreeNode* right;

        TreeNode(T val) : value{val}, left{nullptr}, right{nullptr} {}
        TreeNode(T val, TreeNode* lefts, TreeNode* rights) : value{val}, left{lefts}, right{rights} {}
    };

    TreeNode* root;

    void preorder_traversal(TreeNode* node) {
        if (node == nullptr) return;

        stack<TreeNode*> stas;
        stas.push(node);

        while (!stas.empty()) {
            TreeNode* curr = stas.top();
            stas.pop();
            cout << curr->value << " ";
            if (curr->right) stas.push(curr->right);
            if (curr->left) stas.push(curr->left);
        }
    }

    TreeNode* find_predecessor(TreeNode* node) {
        if (node == nullptr) return nullptr;
        while (!(node->left)) {
            node = node->left;
        }
        return node;
    }

    TreeNode* find_successor(TreeNode* node) {
        if (node == nullptr) return nullptr;
        while (node->left) {
            node = node->left;
        }
        return node;
    }

    TreeNode* helper_insert(TreeNode* root, T values) {
        if (root == nullptr) {
            return new TreeNode(values);
        }

        TreeNode* node = root;
        TreeNode* parent = nullptr;

        while (node) {
            parent = node;
            if (node->value > values) {
                node = node->left;
            } else {
                node = node->right;
            }
        }

        if (values > parent->value) {
            parent->right = new TreeNode(values);
        } else {
            parent->left = new TreeNode(values);
        }

        return root;
    }

    TreeNode* helper_deletion(T values) {
        TreeNode* current = root;
        TreeNode* parent = nullptr;
        int flag = 1;

        while (current && current->value != values) {
            parent = current;
            if (current->value > values) {
                current = current->left;
            } else {
                current = current->right;
            }
        }

        if (parent == nullptr) {
            flag = 0;
        }

        if (current->left == nullptr) {
            parent = current->right;
            delete current;
            if (flag == 0) return parent;
        }

        if (current->right == nullptr) {
            parent = current->left;
            delete current;
            if (flag == 0) return parent;
        }

        TreeNode* ptr = find_successor(current->right);
        current->value = ptr->value;

        if (values > current->value) {
            current->right = ptr->right;
        } else {
            current->left = ptr->right;
        }

        delete ptr;

        if (flag == 0) return current;
        return root;
    }

public:
    BST() : root{nullptr} {}

    void print() {
        preorder_traversal(root);
        cout << endl;
    }

    void insert(T values) {
        root = helper_insert(root, values);
    }

    bool find(T values) {
        TreeNode* current = root;
        while (current) {
            if (current->value == values) return true;
            if (current->value > values) {
                current = current->left;
            } else {
                current = current->right;
            }
        }
        return false;
    }

    TreeNode* deletion(T value) {
        root = helper_deletion(value);
        return root;
    }
};
