#pragma once
#include <vector>
#include <map>
#include <string>
#include <set>
#include <unordered_set>
#include <algorithm>

const int MAX_ALPHABET_SIZE = 256;

class grammar {
private:
    std::multimap<char, std::string> rules;
    std::set<char> alphabet;
public:
    grammar();
    grammar(const std::vector<std::string>& list_pules);

    std::pair<char, std::string> parse(const std::string& rule) const;
    void update_alphabet(const std::string& rule);
    void add_rule(const std::string& rule);

    const std::multimap<char, std::string>& get_rules() const;
    const std::set<char>& get_alphabet() const;

    std::set<char> get_first(const std::string& str) const;
};

bool is_terminal(const char symbol);