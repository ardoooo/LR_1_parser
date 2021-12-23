#pragma once
#include <algorithm>
#include "state.h"
#include "grammar.h"
#include "item.h"

std::vector<item> build_automaton(const grammar& grammar);

class parsing_table {
private:

    struct status {
        char str; // имя статуса
        int to_number; // переход, если есть
        char in; // соответсвующее правило, если есть
        std::string out;
    };

    std::vector<std::map<char, status>> table;

public:
    parsing_table(const grammar& grammar);

    bool parse(const std::string& str) const;
};

