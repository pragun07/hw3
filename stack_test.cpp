#include "stack.h"
#include <iostream>
#include <stdexcept>

int main ()
{
  Stack<int> s;
  std::cout << "Initial Stack: " << std::endl;

  s.push(10);
  s.push(20);
  s.push(30);

  std::cout << "Top value: " << s.top() << std::endl;
  std::cout << "Size: " << s.size() << std::endl;

  s.pop();
  s.pop();

  std::cout << "Top value: " << s.top() << std::endl;
  std::cout << "Size: " << s.size() << std::endl;

  s.pop();

  if(s.empty())
  {
    std::cout << "Stack empty" << std::endl;
  }
  else
  {
    std::cout << "not empty" << std::endl;
  }

  try 
  {
    s.top();
  }
  catch(std::underflow_error &error)
  {
    std::cout << "Exception caught for top" << std::endl;
  }

  try 
  {
    s.pop();
  }
  catch(std::underflow_error &error)
  {
    std::cout << "Exception caught for top" << std::endl;
  }

  return 0;
}