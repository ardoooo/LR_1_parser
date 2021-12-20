#include "../include/item.h"

item::item(const grammar& grammar) {
    grammar_pointer = &grammar;
    to.assign(MAX_ALPHABET_SIZE, -1);
}

item::item(const grammar& grammar, const state& state) {
    grammar_pointer = &grammar;
    to.assign(MAX_ALPHABET_SIZE, -1);
    states.insert(state);
}

void item::add(const state& state) {
    states.insert(state);
}

void item::closure() {
    auto rules = grammar_pointer->get_rules();
    bool added = false;
    do {
        added = false;
        for (auto st: states) {
            auto begin_it = rules.equal_range(st.out[st.pos_in_rule]).first;
            auto end_it = rules.equal_range(st.out[st.pos_in_rule]).second;
            for (auto rule = begin_it; rule != end_it; ++rule) {
                auto set_of_first = grammar_pointer->get_first(st.out.substr(st.pos_in_rule) + st.next);
                for (auto first: set_of_first) {
                    state tmp(rule->first, rule->second, 0, first, rule);
                    if (states.find(tmp) != states.end()) {
                        added = true;
                        states.insert(tmp);
                    }
                }
            }
        }
    } while (added);
}

item item::goto_item(const char symbol) {
    item item_to_symbol(*grammar_pointer);
    for (auto st: states) {
        state added_state(st);
        ++added_state.pos_in_rule;
        item_to_symbol.add(added_state);
    }
    item_to_symbol.closure();
    return item_to_symbol;
}

bool item::empty() const {
    return states.size() == 0;
}