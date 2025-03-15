#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>
template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below

  std::vector<T> data_;
  size_t m_;
  PComparator compare_;

  void heapifyUp(size_t i);
  void heapifyDown(size_t i);


};

// Add implementation of member functions here

template <typename T, typename PComparator>
Heap<T,PComparator>::Heap(int m, PComparator c) : m_(m), compare_(c)
{
  if (m<2)
  {
    throw std::invalid_argument("m-ary value should be greater than 2");
  }
}

template<typename T, typename PComparator>
Heap<T,PComparator>::~Heap()
{

}

template<typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item)
{
  data_.push_back(item);
  heapifyUp(data_.size()-1);

}

// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Empty heap");
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return data_[0];
}

// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("empty heap");
  }
  data_[0]= data_.back();
  data_.pop_back();
  if(!empty())
  {
    heapifyDown(0);
  }
}

template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const
{
  return data_.empty();
}

template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const
{
  return data_.size();
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::heapifyUp(size_t i)
{
  if(i>0)
  {
    size_t parent_index = (i-1)/m_;
    if(compare_(data_[i], data_[parent_index]))
    {
      std::swap(data_[i], data_[parent_index]);
      heapifyUp(parent_index);
    }
  }
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::heapifyDown(size_t i)
{
  size_t number_elements = data_.size();
  size_t best_index = i;
  
  size_t j=1;
  while(j<=m_)
  {
    size_t child_index = i * m_ + j;
    if(child_index < number_elements && compare_(data_[child_index], data_[best_index]))
    {
      best_index=child_index;
    }
    j++;
  }

  if(best_index != i)
  {
    std::swap(data_[i], data_[best_index]);
    heapifyDown(best_index);
  }
}

#endif

