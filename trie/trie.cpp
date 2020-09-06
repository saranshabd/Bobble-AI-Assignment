#include "trie.hpp"

/**
 * Create a new `TrieNode` instance & initialize all private data members
 */
TrieNode::TrieNode() {
  this->isEnd = false;
  this->freq = 0;
  for (int i = 0; i < TRIE_ARRAY_SIZE; ++i) {
    this->arr[i] = nullptr;
  }
}

/**
 * Insert a new string in the tier data structure.
 * 
 * @param key String value to be stored in trie
 * @param freq Frequency of the string value to be stored in trie
 */
void TrieNode::insert(const string& key, const int& freq) {
  TrieNode* curr = this;
  for (char item : key) {
    int index = item; // ASCII value of char
    if (!curr->arr[index]) {
      curr->arr[index] = new TrieNode();
    }
    curr = curr->arr[index];
  }
  curr->isEnd = true;
  curr->freq = freq;
}

/**
 * Verify whether or not the given string is present in trie data structure
 * 
 * @param key String value to search in trie
 * 
 * @returns Frequency of the string value, if present in the data structure
 */
pair<bool, int> TrieNode::search(const string& key) {
  TrieNode* curr = this;
  for (char item : key) {
    int index = item;
    if (!curr->arr[index]) {
      return make_pair(false, 0);
    }
    curr = curr->arr[index];
  }
  if (nullptr == curr || !curr->isEnd) {
    return make_pair(false, 0);
  }
  return make_pair(true, curr->freq);
}

void TrieNode::serialize(const string& filename) {
  
}


void TrieNode::deserialize(const string& filename) {

}
