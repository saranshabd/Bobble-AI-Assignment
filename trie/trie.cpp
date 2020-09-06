#include "trie.hpp"

TrieNode::TrieNode() {
  this->isEnd = false;
  this->freq = 0;
  for (int i = 0; i < TRIE_ARRAY_SIZE; ++i) {
    this->arr[i] = nullptr;
  }
}

void TrieNode::insert(const string& key, const int& freq) {
  TrieNode* curr = this;
  for (char item : key) {
    int index = item;
    if (!curr->arr[index]) {
      curr->arr[index] = new TrieNode();
    }
    curr = curr->arr[index];
  }
  curr->isEnd = true;
  curr->freq = freq;
}

pair<bool, int> TrieNode::search(const string& key) {
  TrieNode* curr = this;
  for (char item : key) {
    int index = item;
    if (!curr->arr[index]) {
      return make_pair(false, 0);
    }
    curr = curr->arr[index];
  }
  if (nullptr == curr && !curr->isEnd) {
    return make_pair(false, 0);
  }
  return make_pair(true, curr->freq);
}
