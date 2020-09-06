#include "specialTrie/specialTrie.hpp"
#include "csv/csv.hpp"
#include "experimental/filesystem"
namespace fs = std::experimental::filesystem;

int main(int args, char** argv);
SpecialTrieNode* convertDictToSpecialTrie(unordered_set<string>& dict);

int main(int args, char** argv) {
  if (args < 2) {
    cout << "CSV filename and/or word to search missing; exitting...\n";
    exit(1);
  }

  string csvFilePath = fs::current_path().string() + "/static/EnglishDictionary.csv";
  unordered_set<string> dict = CsvReader::parseToDict(csvFilePath);
  SpecialTrieNode *trieRoot = convertDictToSpecialTrie(dict);

  string searchedWord = trieRoot->search(stoi(argv[1]));
  if (searchedWord.empty()) {
    cout << "Word not found\n";
  } else {
    cout << "Word Found!, Word = " << searchedWord << "\n";
  }

  return 0;
}

SpecialTrieNode* convertDictToSpecialTrie(unordered_set<string>& dict) {
  SpecialTrieNode *trieRoot = new SpecialTrieNode(dict.size());
  int i = 0;
  for (auto itr = dict.begin(); itr != dict.end(); ++itr, ++i) {
    string key = itr->data();
    itr = dict.erase(itr); // returns next iterator
    trieRoot->insert(key, i);
  }
  return trieRoot;
}
