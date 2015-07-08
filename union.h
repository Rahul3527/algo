//#include <string>
#include <inttypes.h>
#include <cstdio>
#include <iostream>

using namespace std; 

//template<int32_t SIZE>
class UnionFind
{
  public:
    UnionFind(uint32_t size = 10);
    uint32_t getRoot(uint32_t i);
    bool isConnected(uint32_t p, uint32_t q);
    void doUnion(uint32_t p, uint32_t q);  
    void print();
  private:
    uint32_t SIZE;
    uint32_t *Parent; 
    uint32_t *Size;
};

