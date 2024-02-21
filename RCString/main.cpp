#include "RCString.hpp"
#include "/home/art/Preparation/examples/test_macros.hpp"
using namespace artozersky;


//functionalities:
// 1. create string/delete strings
// 2. when cctor or copy constructor used, counter is going up
// 2.1 they should all point to the same address
// 3. counter is going down, when object starts to point to another string
// 3.1 deletes str when there is only one holder and it is the end of the scope
// 4. when counter is 0 we can release the memory
// 5. Copy On write, when making changes , make changes to copy, not to original
// 6. [] operators
//Important:
//when pointing to a specific char in 
//a RCString the modification will 
//affect the string for all object that point to it
// This behaviour is undefined
void TestOne()
{
    RCString str1("Art");
    TestExpression(str1 == "Art");
    TestExpression(str1 != "AA");
}
void TestTwo()
{
    RCString str1("Art");
    TestExpression(str1.GetCounter() == 1);
    RCString str2("dd");
    str2 = str1;
    TestExpression(str2.GetCounter() == 2);
    TestExpression(str1.GetCounter() == 2);
    RCString def;
    RCString str3(str2);
    RCString str4("hello world");
    str4 = str3;

    TestExpression(str3.GetCounter() == 4);
    TestExpression(str2.GetCounter() == 4);
    TestExpression(str1.GetCounter() == 4);
    TestExpression(str4.GetCounter() == 4);
}
void TestDeletionInDtor()//use valgrind
{
    RCString str1("Art");
    RCString str2("bb");
    RCString str3("kkk");
    str1 = str2; //deletion in operator=
    RCString str4(str1);//deletion in cctor
    const char *addr1 = str1.GetStr();
    const char *addr2 = str2.GetStr();
    const char *addr3 = str3.GetStr();
    const char *addr4 = str4.GetStr();

    TestExpression(str1 == str2);
    TestExpression(str1 != str3);
    TestExpression(str1 == str4);

    TestExpression(*addr1 == *addr2);

    TestExpression(*addr3 != *addr1);
    TestExpression(*addr4 == *addr1);
}
void TestCopyOnWrite()
{
    RCString str1("Art");
    RCString str2("bb");
    RCString str3("kkk");
    str2 = str1;
    str3 = str2;
    TestExpression(str3 == "Art");
    str3[0] = 'B';
    TestExpression(str1 == "Art");
    TestExpression(str2 == "Art");
    TestExpression(str3 == "Brt");

    TestExpression(str1.GetStr() == str2.GetStr());
    TestExpression(str2.GetStr() != str3.GetStr());

}
void TestReadConst()
{
    RCString str1("Art");
   
    char c = str1[0];

    c = str1[0];
    TestExpression(c == 'A');
    c = str1[1];
    TestExpression(c == 'r');
    c = str1[2];
    TestExpression(c == 't');    
}

int main()
{
    TestOne();
    TestTwo();
    TestDeletionInDtor();
    TestCopyOnWrite();
    TestReadConst();
    return 0;
}
