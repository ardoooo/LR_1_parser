#include <vector>
#include <set>
#include "grammar.h"
#include "state.h"

class item {
private:
    std::set<state> states;
    std::vector<int> to;
    const grammar* grammar_pointer;
public:
    item(const grammar& grammar);
    item(const grammar& grammar, const state& state);

    void add(const state& state);

    const std::set<state>& get_states() const;
    int get_to(char ch) const;
    int get_size_to() const;

    void closure();
    item goto_item(const char symbol);

    bool empty() const;
};