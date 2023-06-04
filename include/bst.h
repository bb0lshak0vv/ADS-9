// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include <algorithm>

template <typename T>
class BST {
 private:
  struct Node {
    T val;
    int cnt;
    Node* left, *right;
    explicit Node(T v): val(v), cnt(1), left(nullptr), right(nullptr) {}
  };
  Node* root;
  Node* addNode(Node*, const T&);
  int depthTree(Node*);
  int searchTree(Node*, const T&);
 public:
  BST(): root(nullptr) {}
  void add(const T&);
  int depth();
  int search(const T&);
};

template <typename T>
typename BST<T>::Node* BST<T>::addNode(Node* root, const T& value) {
  if (root == nullptr) {
    root = new Node(value);
  } else if (root->val > value) {
    root->left = addNode(root->left, value);
  } else if (root->val < value) {
    root->right = addNode(root->right, value);
  } else {
    root->cnt++;
  }
  return root;
}

template <typename T>
void BST<T>::add(const T& value) {
  root = addNode(root, value);
}

template <typename T>
int BST <T>::depthTree(Node* root) {
  if (root == nullptr) {
    return 0;
  }
  return 1 + std::max(depthTree(root->left), depthTree(root->right));
}

template <typename T>
int BST<T>::depth() {
  return depthTree(root) - 1;
}

template <typename T>
int BST<T>::searchTree(Node* root, const T& value) {
  if (root == nullptr) {
    return 0;
  } else if (root->val == value) {
    return root->cnt;
  } else if (root->val < value) {
    return searchTree(root->right, value);
  }
  return searchTree(root->left, value);
}

template <typename T>
int BST<T>::search(const T& value) {
  return searchTree(root, value);
}

#endif  // INCLUDE_BST_H_
