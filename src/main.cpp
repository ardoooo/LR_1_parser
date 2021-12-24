#include<iostream>
#include "../include/parsing_table.h"

int main() {
    std::vector<std::string> rules;
    rules.push_back("S->aB");
    rules.push_back("B->bc");
    rules.push_back("B->b");
    grammar gr(rules);

    parsing_table table(gr);

    return 0;
}