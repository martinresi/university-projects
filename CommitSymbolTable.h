#ifndef COMMITSYMBOLTABLE_H
#define COMMITSYMBOLTABLE_H

#include "Commit.h"
#include <string>

using std::string;

namespace UCommitSymbolTable {
    struct Dictionary;

    Dictionary* Create();
    void AddElement(Dictionary* dictionary, string key, UGit::Commit* value);
    UGit::Commit* GetValue(Dictionary* dictionary, string key);
    bool IsKeyIncluded(Dictionary* dictionary, string key);
    void Destroy(Dictionary*);
}

#endif