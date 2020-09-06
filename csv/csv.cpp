#include "csv.hpp"

/**
 * Parse CSV file to read dictionary words & their frequencies, and store this
 * data in an `unordered_map`
 * 
 * @param filename Name of CSV file to read dictionary words from
 * 
 * @returns Dictionary words with their frequency
 */
TrieNode* CsvReader::parseToTrie(const string& filename) {
  TrieNode* trieRoot = new TrieNode();
  
  fstream fin;
  fin.open(filename, ios::in);

  while (!fin.eof()) {
    string data;
    fin >> data; // stream CSV row into `data` string
    int commaIndex = data.find(',');
    string word = data.substr(0, commaIndex);
    int freq = stoi(data.substr(commaIndex + 1, data.size() - 1));
    trieRoot->insert(word, freq);
  }

  fin.close();

  return trieRoot;
}
