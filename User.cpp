#include "User.h"
#include <string>

using std::string;
using UUser::User;

struct UUser::User
{
    string name;
    string lastName;
    string nickName;
};

User* UUser::CreateUser(string nickName)
{
    User* user = new User;
    user->nickName = nickName;
    user->name = "";
    user->lastName = "";
    return user;
}

string UUser::GetNickName(const User* user)
{
    return user->nickName;
}

string UUser::GetLastName(const User* user)
{
    return user->lastName;
}

string UUser::GetName(const User* user)
{
    return user->name;
}

void UUser::SetName(User* user, string name)
{
    user->name = name;
}

void UUser::SetLastName(User* user, string lastName)
{
    user->lastName = lastName;
}

void UUser::DestroyUser(User* user)
{
	delete user;
}