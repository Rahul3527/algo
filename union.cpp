#include "union.h"

using namespace std;

//template<int32_t SIZE>
UnionFind::UnionFind(uint32_t size)
{
  SIZE = size;
  Parent = new uint32_t[SIZE];
  Size = new uint32_t[SIZE];
  for (int32_t i = 0; i < SIZE; i++) {
    Parent[i] = i; 
    Size[i] = 1;
  }
}

uint32_t UnionFind::getRoot(uint32_t i)
{
  while (Parent[i] != i) {
    Parent[i] = Parent[Parent[i]];
    i = Parent[i];  
  }
  return i;
}

bool UnionFind::isConnected(uint32_t p, uint32_t q)
{
  uint32_t rp = getRoot(p);
  uint32_t rq = getRoot(q);
  return rp == rq;
}

void UnionFind::doUnion(uint32_t p, uint32_t q)
{
  cout << "Union(" << p << " ," << q << ")" << endl;
  uint32_t rp = getRoot(p);
  uint32_t rq = getRoot(q);
  if (rp == rq) return;
  if (Size[rp] < Size[rq]) {
    Parent[rp] = rq; 
    Size[rq] += Size[rp];
  }
  else {
    Parent[rq] = rp;
    Size[rp] += Size[rq];
  }
}

void UnionFind::print()
{
  cout << "ID : Parent: SIZE " << endl;
  for (int32_t i = 0; i < SIZE; i++) {
    cout << i << " : " << Parent[i] << " : " << Size[getRoot(i)] << endl;
  }
}

