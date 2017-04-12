#include "thefriend.h"
#include "theclass.h"

FriendOfThePrivateCopyClass::FriendOfThePrivateCopyClass()
{
    ContainsPrivateCopyCtor obj1;
    ContainsPrivateCopyCtor obj2(obj1);
    ContainsPrivateCopyCtor obj3;
    obj3 = obj1;
}

FriendOfThePrivateCopyClass::~FriendOfThePrivateCopyClass()
{}
