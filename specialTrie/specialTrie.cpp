#include "specialTrie.hpp"

/**
 * Constructor for `SpecialTrieNode` object
 * 
 * @param totalIndices Total number of words present in dictionary
 */
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

/**
 * Insert a dictionary word in the trie data structure
 * 
 * @param key Dictionary word to be stored
 * @param index Index of the dictionary word (which will be used to search the word later)
 */
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

/**
 * Search a dictionary word in the trie data structure using its index value
 * 
 * @param index Index value of the dictionary word to search
 * 
 * @returns String value representing the searched dictionary word, if present otherwise
 * returns an empty string
 */
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
