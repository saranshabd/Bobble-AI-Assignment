PWD := $(shell dirname $(realpath $(firstword $(MAKEFILE_LIST))))

build:
	g++ --std=c++11 -o dict_conversion build.cpp trie/trie.cpp csv/csv.cpp
	g++ --std=c++11 -o reverse_search reserveSearch.cpp specialTrie/specialTrie.cpp csv/csv.cpp trie/trie.cpp

run_dict_conversion:
	./dict_conversion $(PWD)/static/EnglishDictionary.csv

run_reverse_search:
	./reverse_search $(PWD)/static/EnglishDictionary.csv 155
