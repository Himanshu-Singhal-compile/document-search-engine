#pragma once
// Do NOT add any other includes
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

class SymNode
{
public:
    string key;
    int height;
    int count = 0;
    SymNode *par = NULL;
    SymNode *left = NULL;
    SymNode *right = NULL;
    SymNode(string k);
    SymNode *LeftLeftRotation();   // case 1
    SymNode *RightRightRotation(); // case 2
    SymNode *LeftRightRotation();  // case 3
    SymNode *RightLeftRotation();  // case 4
    void dump(ofstream &out);
    ~SymNode();
};

class SymbolTable
{
public:
    SymNode *root = NULL;
    SymbolTable();
    ~SymbolTable();
    void insert(string k);
    int get_count(string k);
};

class Dict
{
public:
    int m;
    SymbolTable **hash_table;

    /* ------------------------------------------- */
    Dict();

    ~Dict();

    void insert_sentence(int book_code, int page, int paragraph, int sentence_no, string sentence);

    int get_word_count(string word);

    void dump_dictionary(string filename);

    /* -----------------------------------------*/
};
