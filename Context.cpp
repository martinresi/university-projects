#include "Context.h"

using UUser::CreateUser;
using UUser::DestroyUser;
using UDateTime::Now;

User* currentUser = NULL;
User* UContext::GetCurrentUser()
{  
    if (!currentUser) {
		currentUser = CreateUser("euler27");
    }
    return currentUser;
}

DateTime* UContext::GetNow()
{
    return Now();
}

void UContext::DestroyContext() 
{
    if (currentUser) {
       DestroyUser(currentUser);
    }
}