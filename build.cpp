#include "trie/trie.hpp"
#include "csv/csv.hpp"

/**
 * Parse the input CSV file to create a `TrieNode` object instance and serialize
 * that instance in JSON format, which can be used later to perform search operation
 * on the data.
 */

int main(int args, char** argv) {
  if (args < 3) {
    cout << "CSV filename and/or word to search missing; exitting...\n";
    exit(1);
  }
  
  TrieNode* trieRoot = CsvReader::parseToTrie(argv[1]);

  return 0;
}
