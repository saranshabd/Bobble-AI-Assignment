#pragma once

#include "bits/stdc++.h"
using namespace std;

const int SPECIAL_TRIE_ARRAY_SIZE = 256;

class SpecialTrieNode {

public:

  SpecialTrieNode(const int&);
  void insert(const string&, const int&);
  string search(const int&);

private:

  bool isEnd;
  SpecialTrieNode *arr[SPECIAL_TRIE_ARRAY_SIZE];
  int totalIndices;
  int *indices;
};
