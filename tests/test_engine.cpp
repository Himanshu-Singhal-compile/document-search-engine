#include "dict.h"
#include "search.h"
#include <cassert>
#include <map>
#include <random>
#include <cstdio>

int main() {
    Dict dictionary;
    dictionary.insert_sentence(1, 2, 3, 4, "Hello, HELLO! world-world?");
    assert(dictionary.get_word_count("hello") == 2);
    assert(dictionary.get_word_count("world") == 2);
    assert(dictionary.get_word_count("absent") == 0);
    SymbolTable tree;
    std::map<std::string, int> expected;
    std::mt19937 random(42);
    for (int i=0; i<10000; ++i) {
        std::string key = std::to_string(random() % 2000);
        tree.insert(key); ++expected[key];
    }
    for (const auto& entry : expected) assert(tree.get_count(entry.first) == entry.second);
    SearchEngine search;
    search.insert_sentence(1, 2, 3, 4, "aBaBa");
    search.insert_sentence(2, 3, 4, 5, "ABA");
    int matches = 99;
    Node* head = search.search("AbA", matches);
    assert(matches == 3 && head && head->offset == 0);
    assert(head->right->offset == 2 && head->right->left == head);
    assert(head->right->right->book_code == 2);
    search.free_results(head);
    head = search.search("", matches);
    assert(head == nullptr && matches == 0);
    head = search.search("missing", matches);
    assert(head == nullptr && matches == 0);
    dictionary.dump_dictionary("test_dictionary.txt");
    dictionary.dump_dictionary("test_dictionary.txt");
    std::ifstream file("test_dictionary.txt");
    std::string line; int lines=0;
    while (std::getline(file,line)) ++lines;
    assert(lines == 2);
    file.close(); std::remove("test_dictionary.txt");
    std::cout << "Dictionary and search regression checks passed\n";
}
