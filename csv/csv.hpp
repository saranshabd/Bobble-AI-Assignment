#pragma once

#include "../trie/trie.hpp"

class CsvReader {
public:
  static TrieNode* parseToTrie(const string&);
};
