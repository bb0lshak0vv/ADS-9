// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  BST<std::string> tree;
  std::string word;
  std::ifstream file;
  file.open(filename);
  if (!file.is_open()) {
    throw std::string("file opening error!");
  }  // поместите сюда свой код
  while (!file.eof()) {
    char symbol = file.get();
    if (symbol != ' ' && isalpha(symbol)) {
      symbol = tolower(symbol);
      word += symbol;
    } else {
      tree.add(word);
      word = "";
    }
  }
  file.close();
  return tree;
}
