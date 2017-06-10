

#include "syntax.h"

//#define USE_SEMANTIC_CC_LIB 0
#ifdef USE_SEMANTIC_CC_LIB
int main(int argc, const char* argv[])
{
    CSentence line("");

    CMetaData* syntaxTree = CSyntaxFactory::CreateSyntaxTree();
    if (syntaxTree != NULL) {
        CSyntax syntax(syntaxTree);
        return syntax.Parse(line);
    }
    return VOICE_SEMANTIC_ERROR;
}

#else

int voice_init(Sentence* sentence, Action* action, Syntax* syntax)
{
    if (voice_sentence_init(sentence) != STATUS_SUCCESS) {
        return STATUS_FAILED;
    }

    if (voice_action_init(action) != STATUS_SUCCESS) {
        return STATUS_FAILED;
    }

    if (voice_syntax_init(syntax) != STATUS_SUCCESS) {
        return STATUS_FAILED;
    }

    voice_log_debug("Voice init finished!\n");
    return STATUS_SUCCESS;
}

int main(int argc, const char* argv[])
{
    char data[] = "ÄãÊÇË­";
    Sentence line;
    Action action;
    Syntax syntax;

    if (voice_init(&line, &action, &syntax) == STATUS_SUCCESS) {

        if (voice_sentence_set_data(&line, data) != STATUS_SUCCESS) {
            voice_log_error("Set sentence data failed!\n");
            return STATUS_FAILED;
        }

        if (voice_syntax_parse_sentece(&syntax, &line, &action) == STATUS_SUCCESS) {
            voice_log_debug("Voice syntax parse sentence success!\n");
            return voice_action_generate_result(&action);
        } else {
            voice_log_debug("Voice syntax parse sentence failed!\n");
        }
    }

    return STATUS_FAILED;
}

#endif
