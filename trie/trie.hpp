#pragma once

#include "bits/stdc++.h"
using namespace std;

const int TRIE_ARRAY_SIZE = 256;

class TrieNode {

public:

  TrieNode();
  void insert(const string&, const int&);
  pair<bool, int> search(const string&);

private:

  bool isEnd;
  int freq;
  TrieNode *arr[TRIE_ARRAY_SIZE];
};
