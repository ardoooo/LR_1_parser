#include "../include/state.h"

state::state() {};

state::state(char in, std::string out, int pos_in_rule, char next, std::multimap<char, std::string>::iterator rule): 
    in(in), out(out), pos_in_rule(pos_in_rule), rule(rule) {};

state::state(const state& other): in(other.in), out(other.out), 
    pos_in_rule(other.pos_in_rule), rule(other.rule) {};

bool state::operator==(const state& other) const {
    return (rule == other.rule) && (pos_in_rule == other.pos_in_rule) && (next == other.next);
}