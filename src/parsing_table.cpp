#include "../include/parsing_table.h"

std::vector<item> build_automaton(const grammar& grammar) {
    std::vector<item> items;
    auto rules = grammar.get_rules();
    auto alphabet = grammar.get_alphabet();
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

parsing_table::parsing_table(const grammar& grammar) {
    std::vector<item> automaton = build_automaton(grammar);
    int count = -1;
    for (auto curr_item: automaton) {
        ++count;
        for (char ch = 0; ch < 256; ++ch) {
            if (!is_terminal(curr_item.get_to[ch]) {
                if (table[count].count(ch)) {
                    throw "error";
                }
                status st;
                st.str = s;
                st.to_number = curr_item.get_to(ch);
                table[count][ch] = st;
            }
        }
        std::set<state> states = curr_item.get_states();
        for (auto state: states) {
            if (state.pos_in_rule < state.out.size() && is_terminal(state.out[state.pos_in_rule])) {
                status st;
                st.char = s;
                st.to_number = curr_item.get_to(state.out[state.pos_in_rule]);
                if (table[count][state.out[state.pos_in_rule]]) {
                    throw "error";
                }
                table[count][state.out[state.pos_in_rule]] = st;
                continue;
            }
            if (state.in != '#') {
                status st;
                st.char = r;
                st.in = state.in;
                st.out = state.out;
                if (table[count].count(state.next)) {
                    throw "error";
                }
                table[count][state.next] = st;
            } else {
                if (state.next == '$') {
                    if (table[count].count('$')) Х
                    throw "error";
                }
                status st;
                st.str = a;
                table[count]['$'] = st;
            }
        }
    }
}