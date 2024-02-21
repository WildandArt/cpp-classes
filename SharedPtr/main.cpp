#include "SharedPtr.hpp"
#include "/home/art/Preparation/examples/test_macros.hpp"
using namespace artozersky;


class A
{
    public:
        A(double x = 0.5, double y = 1.5): xx(x), yy(y)
        {

        }
        double GetX() const
        {
            return xx;
        }
        double GetY() const
        {
            return yy;
        }
    private:
        double xx;
        double yy;

};

void Test1()
{
    SharedPtr<int> file(new int(10));
    SharedPtr<A> f2(new A(1.1, 2.1));
    //A &a = *f2;
    TestExpression((((*f2).GetX()) == 1.1) && ((*f2).GetY() == 2.1));
    TestExpression(f2->GetX() == 1.1 && f2->GetY() == 2.1); 
}
//To TEST:
//can you copy copy pointer?
//operator=
//what if two pointers point to the same address
void Test2()
{
    SharedPtr<int> file(new int(10));
    SharedPtr<int> f2(file);
    SharedPtr<int> f3(file);
    SharedPtr<int> f4(file);
    TestExpression(file.GetCounter() == 4);
    TestExpression(f2.GetCounter() == 4);
    TestExpression(f3.GetCounter() == 4);
    TestExpression(f4.GetCounter() == 4);
    SharedPtr<int> f5(new int(9));


    f3 = f5;
    TestExpression(f4.GetCounter() == 3);

    f2 = file;
    TestExpression(f2.GetCounter() == 3);
}
void TestConversion()
{
    SharedPtr<int> file(new int(10));
    SharedPtr<double> f2(new double(10.0));
    
    //f2 = file;

}






int main()
{
    Test1();
    Test2();
    TestConversion();
    return 0;
}

// Test#()
// {

// }
// Test#()
// {
    
// }