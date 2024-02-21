#ifndef ARTOZERSKY_TESTS_HPP
#define ARTOZERSKY_TESTS_HPP

#include <iostream> // cout, cerr

#define ANSI_COLOR_RESET "\x1b[0m"
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_CYAN "\x1b[36m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
/*******************************************************************************************
Example of usage:
int main()
{
    int a = 5;
    int b = 10;

    TestEqual(6, a);         
    TestLarger(b, a);         
    TestUnEqual(5, b);       
    TestExpression(a == b); 

    return 0;
}
Output:
TestEqual failed: 6 == a in file ds3exam.cpp at line 170; failure number: 1; 
TestExpression failed: a == b in file ds3exam.cpp at line 173; failure number: 2; 
*********************************************************************************************/

size_t g_failureCount = 0;
size_t num_of_tests = 0;
#define TestEqual(expected, received) \
(++num_of_tests);\
   if(expected != received) \
    { \
    std::cerr <<ANSI_COLOR_RESET ANSI_COLOR_RED<< "TestEqual failed: " #expected " == " #received \
              << " in file " << __FILE__ \
              << " at line " << __LINE__  \
              <<"; "<< "failure number: "<<++g_failureCount<< "; " <<std::endl; \
  }
  #define TestLarger(expected, received) \
  (++num_of_tests);\
  if (!(expected > received)) { \
    std::cerr << "TestLarger failed: " #expected " > " #received \
              << " in file " << __FILE__ \
              << " at line " << __LINE__  \
              <<"; "<< "failure number: "<<++g_failureCount<< "; " <<std::endl; \
  }
#define TestUnEqual(expected, received) \
(++num_of_tests);\
  if (!(expected != received)) { \
    std::cerr << "TestUnEqual failed: " #expected " != " #received \
             << " in file " << __FILE__ \
             << " at line " << __LINE__  \
             <<"; "<< "failure number: " <<++g_failureCount<< "; " <<std::endl; \
  }
#define TestExpression(expression) \
  (++num_of_tests);\
  if (!(expression)) { \
    std::cerr <<ANSI_COLOR_RESET ANSI_COLOR_RED<< "TestExpression failed: " #expression \
              << " in file " << __FILE__ \
              << " at line " << __LINE__  \
              <<"; "<< "failure number: " <<++g_failureCount<< "; " <<std::endl; \
  }

class TestSummary {
public:
    ~TestSummary() {
        std::cerr << ANSI_COLOR_CYAN<< "Summary of Tests:" << std::endl;
        std::cerr <<  "Total Tests: " << num_of_tests << std::endl;
        std::cerr << ANSI_COLOR_RESET ANSI_COLOR_GREEN << "Passed Tests: " << (num_of_tests - g_failureCount) << std::endl;
        std::cerr << ANSI_COLOR_RESET ANSI_COLOR_RED << "Failed Tests: " << g_failureCount << std::endl;
    }
};


// Create a static instance of TestSummary
static TestSummary testSummary;

  #endif /* ARTOZERSKY_TESTS_HPP*/
