#include "./perform.h"
#include "./extract_tokens.h"
#include "./expand_repeats.h"

namespace tree_sitter {
    using std::pair;
    
    namespace prepare_grammar {
        pair<Grammar, Grammar> perform(const Grammar &input_grammar) {
            auto grammars = prepare_grammar::extract_tokens(input_grammar);
            auto rule_grammar = expand_repeats(grammars.first);
            auto lex_grammar = grammars.second;
            return { rule_grammar, lex_grammar };
        }
    }
}
