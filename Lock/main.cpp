#include "Lock.hpp"
#include "/home/art/Preparation/examples/test_macros.hpp"/*tests*/
#include <thread>
#include <vector>
using namespace artozersky;

void Test1()
{
    std::mutex m;
    {
        Lock l(std::ref(m));
    }
}


int main()
{
    Test1();
    return 0;
}
