#pragma once
#include <algorithm>
#include "state.h"
#include "grammar.h"
#include "item.h"

class parsing_table {
private:
    std::vector<int> table;
    const grammar* grammar_pointer;
public:
    parsing_table(const grammar& grammar);

    std::vector<item> build_automaton();

    bool parse(const std::string& str) const;
};

