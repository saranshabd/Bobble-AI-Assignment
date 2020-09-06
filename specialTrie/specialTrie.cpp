#include "specialTrie.hpp"

SpecialTrieNode::SpecialTrieNode(const int& totalIndices) {
  this->isEnd = false;
  for (int i = 0; i < SPECIAL_TRIE_ARRAY_SIZE; ++i) {
    this->arr[i] = nullptr;
  }
  this->totalIndices = totalIndices;
  this->indices = new int[this->totalIndices];
  for (int i = 0; i < this->totalIndices; ++i) {
    this->indices[i] = -1;
  }
}

void SpecialTrieNode::insert(const string& key, const int& index) {
  SpecialTrieNode* curr = this;
  for (char item : key) {
    int itemIndex = item; // ASCII value of char
    if (!curr->arr[itemIndex]) {
      curr->arr[itemIndex] = new SpecialTrieNode(this->totalIndices);
    }
    curr->indices[index] = itemIndex;
    curr = curr->arr[itemIndex];
  }
  curr->isEnd = true;
}

string SpecialTrieNode::search(const int& index) {
  SpecialTrieNode* curr = this;
  int currIndex = curr->indices[index];
  string word = "";
  while (currIndex >= 0) {
    word += (char) currIndex; // ASCII value to char
    curr = curr->arr[currIndex];
    currIndex = curr->indices[index];
  }
  return word;
}
