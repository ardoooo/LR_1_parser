#include "../include/parsing_table.h"

parsing_table::parsing_table(const grammar& grammar) {
    grammar_pointer = &grammar;
}

std::vector<item> parsing_table::build_automaton() {
    std::vector<item> items;
    auto rules = grammar_pointer->get_rules();
    auto alphabet = grammar_pointer->get_alphabet();
    auto it = rules.equal_range('#').first;
    items.emplace_back(state('#', std::string("S"), 0, '$', it));
    items[0].closure();
    bool added = false;
    do {
        added = false;
        for (int i = 0; i < items.size(); ++i) {
            for (auto symbol: alphabet) {
                item item_go_symbol = items[i].goto_item(symbol);
                if (!item_go_symbol.empty() && std::find(items.begin(), items.end(), item_go_symbol) == items.end()) {
                    items.push_back(item_go_symbol);
                }
            }
        }
    } while (added);
    return items;
}