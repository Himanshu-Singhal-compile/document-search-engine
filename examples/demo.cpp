#include "dict.h"
#include "search.h"

int main() {
    Dict dictionary;
    SearchEngine search;
    std::string sentence = "Algorithms make search fast. Search makes text useful.";
    dictionary.insert_sentence(1, 1, 1, 1, sentence);
    search.insert_sentence(1, 1, 1, 1, sentence);
    std::cout << "Word count for search: " << dictionary.get_word_count("search") << '\n';
    int count = 0;
    Node* result = search.search("SEARCH", count);
    std::cout << "Substring matches: " << count << '\n';
    for (Node* item = result; item; item = item->right)
        std::cout << "book=" << item->book_code << " offset=" << item->offset << '\n';
    search.free_results(result);
}
