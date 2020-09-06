#pragma once

#include "../trie/trie.hpp"

class CsvReader {
public:
  static TrieNode* parseToTrie(const string&);
  static unordered_set<string> parseToDict(const string&);
};
