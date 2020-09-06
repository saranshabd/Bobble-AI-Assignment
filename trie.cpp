#include "trie.hpp"

TrieNode::TrieNode() {
  this->isEnd = false;
  for (int i = 0; i < TOTAL_ALPHABETS; ++i) {
    this->arr[i] = nullptr;
  }
}

void TrieNode::insert(const string& key) {
  TrieNode* curr = this;
  for (char item : key) {
    int index = item - 'a';
    if (!curr->arr[index]) {
      curr->arr[index] = new TrieNode();
    }
    curr = curr->arr[index];
  }
  curr->isEnd = true;
}

bool TrieNode::search(const string& key) {
  TrieNode* curr = this;
  for (char item : key) {
    int index = item - 'a';
    if (!curr->arr[index]) {
      return false;
    }
    curr = curr->arr[index];
  }
  return nullptr != curr && curr->isEnd;
}
