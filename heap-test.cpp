#include "heap.h"
#include <iostream>
#include <string>
#include <functional>


struct Comparator
{
  bool operator() (const int&a, int&b)
  {
    return a<b;
  }
};

void testMinHeapInt()
{
  std::cout << "Min heap test for ints: " << std::endl;
  Heap<int> min;
  min.push(10);
  min.push(20);
  min.push(30);
  min.push(40);  

  while (!min.empty())
  {
    std::cout << "top value" << min.top() << std::endl;
    min.pop();
  }
}

void testMaxHeapInt()
{
  std::cout << "Max heap test for ints: " << std::endl;
  Heap<int> max;
  max.push(10);
  max.push(20);
  max.push(30);
  max.push(40);  

  while (!max.empty())
  {
    std::cout << "top value" << max.top() << std::endl;
    max.pop();
  }
}

void testMinHeapString()
{
  std::cout << "Min heap test for strings: " << std::endl;
  Heap<std::string> min_string;
  min_string.push("csci");
  min_string.push("buad");
  min_string.push("econ");
  min_string.push("phil");  

  while (!min_string.empty())
  {
    std::cout << "top value" << min_string.top() << std::endl;
    min_string.pop();
  }
}

void testComparator()
{
  std::cout << "Min heap test with comparator: " << std::endl;

  Heap<int, Comparator> c_heap(2, Comparator());
  c_heap.push(10);
  c_heap.push(20);
  c_heap.push(30);
  c_heap.push(40);

  while (!c_heap.empty())
  {
    std::cout << "top value" << c_heap.top() << std::endl;
    c_heap.pop();
  }
}

void testExceptions()
{
  std::cout << "exceptions test for empty heap" << std::endl;
  Heap<int> empty_heap;

  try 
  {
    empty_heap.top();
  }
  catch(const std::underflow_error &e)
  {
    std::cout << "exception in top function" << e.what() << std::endl;
  }

  try 
  {
    empty_heap.pop();
  }
  catch(const std::underflow_error &e)
  {
    std::cout << "exception in pop function" << e.what() << std::endl;
  }
}

int main()
{
  testMinHeapInt();
  testMaxHeapInt();
  testMinHeapString();
  testComparator();
  testExceptions();

  return 0;
}