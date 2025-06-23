#include<iostream>
using namespace std;
template <typename T>
class BST{
class TreeNode{
  T value;
  TreeNode* left;
  TreeNode* right;
  TreeNode(T val):value{val},left{nullptr},right{nullptr}{};
  TreeNode(T val,TreeNode* lefts,TreeNode* rights):value{val},left{lefts},right{rights}{};
};
TreeNode* root;
void Inorder_traversal(TreeNode* node){
   if(node==nullptr){
    return;
   }
   Inorder_traversal(node->left);
   cout<<node->value;
   Inorder_traversal(node->right);
}
void Preorder_traversal(TreeNode* node){
  if(node==nullptr){
    return;
   }
   cout<<node->value;
   Preorder_traversal(node->left);
   Preorder_traversal(node->right);
}
void Postorder_traversal(TreeNode* node){
   if(node==nullptr){
    return;
   }
   Postorder_traversal(node->left);
   Postorder_traversal(Node->right);
   cout<<node->value;
}
TreeNode* helper_insert(TreeNode* node, T values){
   if(node=nullptr){
        node=new TreeNode(value);
        return node;
   }
  if(node->value > values){
    node->left=helper_insert(node->left,values);
  }
  else{
      node->right=helper_insert(node->right,values);
  }
  return node;
}
bool find_helper(TreeNode* node,T values){
  if(node==nullptr){
    return false;
  }
  if(node->value==values){
    return true;
  }
  if(node->value>values){
    return find_helper(node->left,values);
  }
  else{
    return find_helper(node->right,values);
  }
}
TreeNode* find_successor(TreeNode* node){
  if(node->left==nullptr){
    return node;
  }
  return find_successor(node->left);
}
TreeNode* find_predecessor(TreeNode* node){
  if(node->right==nullptr){
    return node;
  }
  return find_predecessor(node->right);
}
TreeNode* helper_deletion(TreeNode* node,T values){
    if(node==nullptr){
         return node;
   }
   if(node->value<values){
    
   }
}
public:
BST(){root=nullptr;}
TreeNode* insert( T values){
  return helper_insert(root,values);
}
bool find(T values){
    return find_helper(root,values);
}
TreeNode* delete( T values){
  return helper_deletion(root,values);
}

    










};