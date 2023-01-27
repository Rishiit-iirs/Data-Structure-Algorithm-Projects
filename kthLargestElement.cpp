#include<bits/stdc++.h>
using namespace std;
int partition(int arr[], int l, int h) {
  int high = arr[h];
  int x = l;
  for (int i=l;i<h;i++) {
    if (arr[i] < high) {   // If arr[i] is less than high, then swap arr[x] with arr[i]
      swap(arr[x], arr[i]);
      x++;
    }
  }
  swap(arr[x], arr[h]);  //swap arr[x] with arr[h]
  return x;
}
int KthLargestElement(int a[],int n,int k){
    if (n == 1) {
    return a[0];
  }
  int l = 0;
  int h = n - 1;
  int target = n-k;
  while (l <= h) {
    int pivot = partition(a, l, h);  // Initializing pivot with the value returned by partition function
    if (pivot < target) {        // If the pivot is less than the target, then we have to go to the right side
      l = pivot + 1;
    }
     else if (pivot > target) {  // If the pivot is greater than the target, then we have to go to the left side
      h = pivot - 1;
    }
     else {            // If the pivot is equal to the target, return arr[pivot]
      return a[pivot];
    }
  }
    return -1;
}

int main(){
    int arr[] = {2,1,4,6,3,9,7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;
    int x = KthLargestElement(arr,n,k);
    cout<<"Kth largest element is "<< x <<endl;
    return 0;
}