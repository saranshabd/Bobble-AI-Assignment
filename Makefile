build:
	g++ --std=c++17 -o dict_conversion.out build.cpp trie/trie.cpp csv/csv.cpp -lstdc++fs
	g++ --std=c++11 -o reverse_search.out reserveSearch.cpp specialTrie/specialTrie.cpp csv/csv.cpp trie/trie.cpp -lstdc++fs
