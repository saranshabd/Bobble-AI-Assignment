#include <bits/stdc++.h>
using namespace std;

const int TOTAL_ALPHABETS = 26;

class TrieNode {

public:

  TrieNode();
  void insert(const string&);
  bool search(const string&);

private:

  bool isEnd;
  TrieNode *arr[TOTAL_ALPHABETS];
};
