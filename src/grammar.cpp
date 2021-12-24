#include "../include/grammar.h"

grammar::grammar() = default;

grammar::grammar(const std::vector<std::string>& list_rules) {
    for (auto rule: list_rules) {
        add_rule(rule);
    }
}

std::pair<char, std::string> grammar::parse(const std::string& rule) const {
    return std::make_pair(rule[0], rule.substr(3) + "$");
}

void grammar::update_alphabet(const std::string& rule) {
    for (auto symbol: rule) {
        alphabet.insert(symbol);
    }
}
void grammar::add_rule(const std::string& rule) {
    rules.insert(parse(rule));
}

const std::multimap<char, std::string>& grammar::get_rules() const {
    return rules;
}

const std::set<char>& grammar::get_alphabet() const {
    return alphabet;
}

bool is_terminal(const char symbol) {
    if (symbol == '#' || symbol >= 'A' && symbol <= 'Z') {
        return false;
    }
    return true;
}

std::set<char> grammar::get_first(const std::string& str) const {
    if (str[0] == '$') {
        return {'$'};
    }
    if (is_terminal(str[0])) {
        return {str[0]};
    }
    auto begin_it = rules.equal_range(str[0]).first;
    auto end_it = rules.equal_range(str[0]).second;
    std::set<char> first;
    for (auto it = begin_it; it != end_it; ++it) {
        std::set<char> first_symbol = get_first("" + (it->second)[0]);
        if (first_symbol.count(str[0])) {
            first.merge(get_first(str.substr(1)));
        }
        first.merge(first_symbol);
    }
    return first;
}