#include "trie/trie.hpp"
#include "csv/csv.hpp"

int main(int args, char** argv) {
  if (args < 3) {
    cout << "CSV filename and/or word to search missing; exitting...\n";
    exit(1);
  }
  
  TrieNode* trieRoot = CsvReader::parseToTrie(argv[1]);

  return 0;
}
