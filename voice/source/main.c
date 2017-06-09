

#include "syntax.h"

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

