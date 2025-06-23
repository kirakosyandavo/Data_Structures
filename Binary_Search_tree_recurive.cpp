#include <iostream>
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

    void inorder_traversal(TreeNode* node) {
        if (node == nullptr) return;
        inorder_traversal(node->left);
        cout << node->value << " ";
        inorder_traversal(node->right);
    }

    void preorder_traversal(TreeNode* node) {
        if (node == nullptr) return;
        cout << node->value << " ";
        preorder_traversal(node->left);
        preorder_traversal(node->right);
    }

    void postorder_traversal(TreeNode* node) {
        if (node == nullptr) return;
        postorder_traversal(node->left);
        postorder_traversal(node->right);
        cout << node->value << " ";
    }

    TreeNode* helper_insert(TreeNode* node, T values) {
        if (node == nullptr) {
            node = new TreeNode(values);
            return node;
        }
        if (node->value > values) {
            node->left = helper_insert(node->left, values);
        } else {
            node->right = helper_insert(node->right, values);
        }
        return node;
    }

    bool find_helper(TreeNode* node, T values) {
        if (node == nullptr) return false;
        if (node->value == values) return true;
        if (node->value > values) return find_helper(node->left, values);
        return find_helper(node->right, values);
    }

    TreeNode* find_successor(TreeNode* node) {
        if (node->left == nullptr) return node;
        return find_successor(node->left);
    }

    TreeNode* find_predecessor(TreeNode* node) {
        if (node->right == nullptr) return node;
        return find_predecessor(node->right);
    }

    TreeNode* helper_deletion(TreeNode* node, T values) {
        if (node == nullptr) return node;

        if (node->value < values) {
            node->right = helper_deletion(node->right, values);
        } else if (node->value > values) {
            node->left = helper_deletion(node->left, values);
        } else {
            if (node->left == nullptr) {
                TreeNode* temp = node->right;
                delete node;
                return temp;
            }
            if (node->right == nullptr) {
                TreeNode* temp = node->left;
                delete node;
                return temp;
            }
            TreeNode* ptr = find_successor(node->right);
            node->value = ptr->value;
            node->right = helper_deletion(node->right, ptr->value);
        }

        return node;
    }

public:
    BST() : root{nullptr} {}

    void insert(T values) {
        root = helper_insert(root, values);
    }

    bool find(T values) {
        return find_helper(root, values);
    }

    TreeNode* deletion(T values) {
        root = helper_deletion(root, values);
        return root;
    }

    void print_inorder() {
        inorder_traversal(root);
    }

    void print_preorder() {
        preorder_traversal(root);
    }

    void print_postorder() {
        postorder_traversal(root);
    }
};
