#include <inttypes.h>

class Sort
{
  public:
    template<class T>
    static void selectionSort(T array[], int32_t size);

    template<class T>
    static void insertionSort(T array[], int32_t size);

    template<class T>
    static void mergeSort(T array[], T aux[], int32_t low, int32_t high);

    template<class T>
    static void quickSort(T array[], int32_t low, int32_t high);

    template<class T>
    static bool verifySort(T array[], int32_t size);
  private:
    template<class T>
    static void merge(T array[], T aux[], int32_t low, int32_t mid, int32_t high);

    template<class T>
    static int32_t partition(T array[], int32_t low, int32_t high);
}; 

template<class T>
void Sort::selectionSort(T array[], int32_t size)
{
  for (int32_t i = 0; i < size; i++) {
    int32_t minIndex = i;
    for (int32_t j = i + 1; j < size; j++) {
      if (array[minIndex] > array[j]) { 
        minIndex = j;
      }
    }
    T tmp = array[i];
    array[i] = array[minIndex];
    array[minIndex] = tmp;
  }
}

template<class T>
void Sort::insertionSort(T array[], int32_t size)
{
  for (int32_t i = 1; i < size; i++) {
    T element = array[i];
    int32_t j = i - 1;
    while(j > 0 && array[j] > element) {array[j+1] = array[j]; j--;}
    array[j] = element;
/*
    for (int32_t j = i - 1; j >= 0; j--) {
      if (array[j] > element) 
        array[j + 1] = array[j];
      else {
        array[j] = element;
        break;
      }
    }
*/
  }
}

template<class T>
void Sort::merge(T array[], T aux[], int32_t low, int32_t mid, int32_t high)
{
  for (int32_t i = low; i <= high; i++) {
    aux[i] = array[i];
  }

  int32_t i = low, j = mid + 1, k = low;  
  
  while(i <= mid && j <= high) {
    if (aux[i] < aux[j]) {array[k++] = aux[i++];}
    else {array[k++] = aux[j++];}
  }
  while(i <= mid) {
    array[k++] = aux[i++];
  }
  while(j <= high){
    array[k++] = aux[j++];
  }
}

template<class T>
void Sort::mergeSort(T array[], T aux[], int32_t low, int32_t high)
{
  if (low < high) {
    int32_t mid = (low + high-1)/2; 
    mergeSort(array, aux, low, mid);
    mergeSort(array, aux, mid+1, high);
    merge(array, aux, low, mid, high);
  }
}

template<class T>
int32_t Sort::partition(T array[], int32_t low, int32_t high)
{
  int32_t left = low, right = high+1;
  while(true) {
    while (array[++left] <= array[low])
    if (left == high) break;

    while (array[--right] >= array[low])
    if (right == low) break;  

    if (left >= right) break;
    T tmp = array[left];
    array[left] = array[right];
    array[right] = tmp; 
  }
  T tmp1 = array[low];
  array[low] = array[right];
  array[right] = tmp1; 
  return right;
}

template<class T>
void Sort::quickSort(T array[], int32_t low, int32_t high)
{
  //if (low >= high) return;
  if (high <= low + 10) {
    selectionSort(array+low, high - low + 1);
    return;
  }
  int32_t p = partition(array, low, high);
  quickSort(array, low, p-1);
  quickSort(array, p+1, high);  
}

template<class T>
bool Sort::verifySort(T array[], int32_t size)
{
  for (int32_t i = 0; i < size - 1; i++) {
    if (array[i] > array[i+1]) return false;
  }
  return true;
}
