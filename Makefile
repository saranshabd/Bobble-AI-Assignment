PWD := $(shell dirname $(realpath $(firstword $(MAKEFILE_LIST))))

build:
	g++ --std=c++11 build.cpp trie/trie.cpp csv/csv.cpp
	./a.out $(PWD)/static/EnglishDictionary.csv
