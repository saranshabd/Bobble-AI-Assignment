#include "trie/trie.hpp"
#include "csv/csv.hpp"
#include "experimental/filesystem"
namespace fs = std::experimental::filesystem;

/**
 * Parse the input CSV file to create a `TrieNode` object instance and serialize
 * that instance in JSON format, which can be used later to perform search operation
 * on the data.
 */

int main(int args, char** argv);

int main(int args, char** argv) {
  if (args < 2) {
    cout << "CSV filename and/or word to search missing; exitting...\n";
    exit(1);
  }
  
  string csvFilePath = fs::current_path().string() + "/static/EnglishDictionary.csv";
  TrieNode* trieRoot = CsvReader::parseToTrie(csvFilePath);

  /**
   * @todo Serialize trie object instance in a file. Use a JSON library to store the data
   * in following format:
   * {
   *  "isEnd": false,
   *  "freq": 0,
   *  "arr": [
   *    {
   *      "isEnd": true,
   *      "freq": 127,
   *      "arr": [
   *        null,
   *        null, 
   *        null, 
   *        null
   *      ]
   *    },
   *    null,
   *    null,
   *    null
   *  ]
   * }
   */

  string wordToSearch = argv[1];
  pair<bool, int> searchedWord = trieRoot->search(wordToSearch);
  if (!searchedWord.first) {
    cout << "No\n";
  } else {
    cout << "YES, " << searchedWord.second << "\n";
  }

  return 0;
}
