#include <cstdlib>
#include <ctime>

#include "union.h"
#include "stack.h"
#include "sort.h"

using namespace std;

class Algorithm
{
  public:
  static void testUnionFind(int32_t args, char* argv[]);
  static void testStack(int32_t args, char* argv[]);
  static void testSelectionSort(int32_t args, char* argv[]);
  static void testInsertionSort(int32_t args, char* argv[]);
  static void testMergeSort(int32_t args, char* argv[]);
  static void testQuickSort(int32_t args, char* argv[]);
  static int32_t prepareArray(int32_t args, char* argv[], int64_t **array);
  static void verifySortedArray(int64_t *array, int32_t size);
};

void Algorithm::testUnionFind(int32_t args, char* argv[])
{
  int32_t count = 20;
  if (args > 2) {
    count = atoi(argv[2]);
  }
  UnionFind *UF = new UnionFind(count);
  srand ( time(NULL) );
  int32_t itr = rand() % 100;
  for (uint32_t i = 0; i < itr; i++) {
    uint32_t n1 = rand() % count; 
    uint32_t n2 = rand() % count; 
    UF->doUnion(n1, n2); 
  }
  UF->print();
  delete UF;
}

void Algorithm::testStack(int32_t args, char* argv[])
{
  Stack<int32_t, 20> stack;
  int32_t ops = 20;
  if (args > 2) {
    ops = atoi(argv[2]);
  }
  srand ( time(NULL) );
  for (uint32_t i = 0; i < ops; i++) {
    if (rand() & 1) {
      uint32_t n1 = rand() & 0xFFFF; 
      stack.push(n1);
      cout << "Pushed 0x" << hex << n1 << " : "<<  dec << stack.getTop() << endl; 
    }
    else {
      cout << "Poped 0x" << hex << stack.pop() << endl;
    } 
  }
}

int32_t Algorithm::prepareArray(int32_t args, char* argv[], int64_t **array)
{
  int32_t size = 20;
  if (args > 2) {
    size = atoi(argv[2]);
  }
  *array = new int64_t[size];
  srand ( time(NULL) );
  for (uint64_t i = 0; i < size; i++) {
    uint64_t n1 = rand() & 0xFFFF; 
    (*array)[i] = n1;
  }
  return size; 
}

void Algorithm::verifySortedArray(int64_t *array, int32_t size)
{
  cout << "Sorted Array : [" 
    <<(Sort::verifySort<int64_t>(array, size) ? "True" : "False") << "] : ("; 
  for (uint32_t i = 0; i < size - 1; i++) {
    cout << array[i] << ", ";
  }
  cout << array[size - 1] << ")" << endl;
}

void Algorithm::testSelectionSort(int32_t args, char* argv[])
{
  int64_t *array;
  int32_t size = prepareArray(args, argv, &array);

  Sort::selectionSort<int64_t>(array, size);  
  verifySortedArray(array, size);
  delete[] array;  
}

void Algorithm::testInsertionSort(int32_t args, char* argv[])
{
  int64_t *array;
  int32_t size = prepareArray(args, argv, &array);
  Sort::insertionSort<int64_t>(array, size);  
  verifySortedArray(array, size);  
  delete[] array;  
}

void Algorithm::testMergeSort(int32_t args, char* argv[])
{
  int64_t *array;
  int32_t size = prepareArray(args, argv, &array);
  int64_t *aux = new int64_t[size];
  Sort::mergeSort<int64_t>(array, aux, 0, size - 1);  
  verifySortedArray(array, size);  
  delete[] array;
  delete[] aux;
}

void Algorithm::testQuickSort(int32_t args, char* argv[])
{
  int64_t *array;
  int32_t size = prepareArray(args, argv, &array);
  Sort::quickSort<int64_t>(array, 0, size - 1);  
  verifySortedArray(array, size);  
  delete[] array;
}

int32_t main(int32_t args, char* argv[])
{
  int32_t option = 1;
  if (args > 1) { option = atoi(argv[1]);}
  switch (option) {
    case 1:
      Algorithm::testUnionFind(args, argv);
      break;
    case 2:
      Algorithm::testStack(args, argv);
      break;
    case 3:
      Algorithm::testSelectionSort(args, argv);
      break;
    case 4:
      Algorithm::testInsertionSort(args, argv);
      break;
    case 5:
      Algorithm::testMergeSort(args, argv);
      break;
    case 6:
      Algorithm::testQuickSort(args, argv);
      break;
    default:
      cout << option << " is not valid Option" << endl;
      cout << "Usage : ./main <option> <count>" << endl;
      cout << "option: 1: Union Find 2: Stack 3: Selection Sort" << endl;
      break;
  } 
  return 0;
}
