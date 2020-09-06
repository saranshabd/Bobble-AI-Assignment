#include "trie.hpp"

int main();
TrieNode* convertDictToTrie(unordered_map<string, int> dict);

int main() {

  unordered_map<string, int> dict;
  dict["testWord"] = 1;

  TrieNode* trieRoot = convertDictToTrie(dict);
  bool isWordFound = trieRoot->search("testWord");

  cout << "isWordFound = " << isWordFound << "\n";
  
  return 0;
}

TrieNode* convertDictToTrie(unordered_map<string, int> dict) {
  TrieNode* trieRoot = new TrieNode();
  for (auto item : dict) {
    trieRoot->insert(item.first);
  }
  return trieRoot;
}
