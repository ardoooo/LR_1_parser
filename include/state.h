#pragma once
#include <string>
#include <map>

struct state {
    char in; // левая часть правила
    std::string out; // правая часть правила
    int pos_in_rule; // позиция в правой части правила
    char next; // символ "lookahead"
    std::multimap<char, std::string>::const_iterator rule; // номер правила в грамматике

    state();
    state(char in, std::string out, int pos_in_rule, char next, std::multimap<char, std::string>::iterator rule);
    state(const state& other);
    bool operator==(const state& other) const;

    friend bool operator<(const state& a, const state& b);
};