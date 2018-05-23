#ifdef _WINDOWS
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#endif

#include "MString.h"
#include "Minigtest.h"

#include <ctime>
#include <iostream>

void foo(String x)
{
}
 
void bar(const String& x)
{
}

String baz()
{
  String ret("world");
  return ret;
}

MTEST(operator_set)
{
    String a("HELLO"), b("hello"), c;
    c = a;
    TEST_ASSERT(c == a);

    c = b;
    TEST_ASSERT(c == b);

    TEST_ASSERT(c.size() == b.size());
}

int main()
{
  String s0;
  String s1("hello");
  String s2(s0);
  String s3 = s1;
  s2 = s1;
 
  foo(s1);
  bar(s1);
  foo("temporary");
  bar("temporary");
  String s4 = baz();
 
  std::vector<String> svec;
  svec.push_back(s0);
  svec.push_back(s1);
  svec.push_back(baz());
  svec.push_back("good job");
  for(auto it: svec)
  {
    std::cout << it << std::endl;
  }
  MRUN_ALL_TESTS();
}