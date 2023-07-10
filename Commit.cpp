#include "Commit.h"
#include "Context.h"
#include <string>

using std::string;
using UGit::Commit;

struct UGit::Commit
{
    Commit* parent;
    string message;
    string hashCode;
    DateTime* date;
    User* user;
};

string CreateHashCode() {
    string hashCode = "";
    char alphanumeric[] = "0123456789abcdefghijklmnopqrstuvwxyz";
    int size = sizeof(alphanumeric) - 1;
    for (int i = 0; i < 40; i++) {
        hashCode += alphanumeric[rand() % size];
    }
    return hashCode;
}

Commit* UGit::CreateCommit(Commit* parent, string message)
{
    Commit* commit = new Commit;
    commit->message = message;
    commit->parent = parent;
    commit->hashCode = CreateHashCode();
    commit->user = UContext::GetCurrentUser();
    commit->date = UContext::GetNow();
    return commit;
}

DateTime* UGit::GetDate(const Commit* commit)
{
    return commit->date;
}

User* UGit::GetAuthor(const Commit* commit)
{
    return commit->user;    
}

string UGit::GetMessage(const Commit* commit)
{
    return commit->message;
}

Commit* UGit::GetParent(const Commit* commit)
{
    return commit->parent;
}

string UGit::GetHashCode(const Commit* commit)
{
    return commit->hashCode;
}

string UGit::GetShortHashCode(const Commit* commit)
{
    return commit->hashCode.substr(0,8);
}

void UGit::DestroyCommit(Commit* commit)
{
    delete commit;
}
