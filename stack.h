#include <string>
#include <cstdlib>
#include <cstdio>

using namespace std;

template<class T, uint32_t SIZE>
class Stack
{
  
  public:
    Stack() {top = -1; size = SIZE; items = new T[size];}
    void push(T item);
    T pop();
    int32_t getTop() {return top;}

  private:
    void resize(int32_t newSize)
    {
      T *newItems = new T[newSize];
      for (int32_t i = 0; i < size; i++) newItems[i] = items[i];
      delete[] items;
      items = newItems;
      size = newSize;
    }
    int32_t size;
    int32_t top;
    T *items; 
};

template<class T, uint32_t SIZE>
void Stack<T, SIZE>::push(T item)
{
  if (top == (size - 1)) {
    //cout << "Stack Overflow " << endl;
    //return;
    cout << "Resizing " << dec << size << " : " << size*2 << endl;
    resize(size*2);
  }
  top++;
  items[top] = item;
}

template<class T, uint32_t SIZE>
T Stack<T, SIZE>::pop()
{
  if (top < 0 ) {
    cout << "Stack Underflow" << endl;
    return (T)0;
  }
  T item = items[top];
  top--;
  return item;
}

