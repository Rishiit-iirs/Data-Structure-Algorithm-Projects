#include <iostream>
using namespace std;
 
// returns the index of second largest
// if second largest didn't exist return -1
int secondLargest(int a[], int n) {
    int first = 0, second = -1;
    for (int i = 1; i < n; i++) {
        if (a[i] > a[first]) {
            second = first;
            first = i;
        }
        else if (a[i] < a[first]) {
            if (second == -1 || a[second] < a[i])
                second = i;
        }
    }
    return second;
}
 
int main() {
    /*int arr[] = { 50, 50,50, 5, 50, 50 };
    int index = secondLargest(arr, sizeof(arr)/sizeof(arr[0]));*/
    int i,n;
    printf("Enter the size of array : ");
    scanf("%d",&n);
    //Declaring array
    int arr[n];
    printf("Enter the elements of the array : ");
    for(i=0;i<n;i++) {
        scanf("%d",&arr[i]);
    } 
        int index = secondLargest(arr, sizeof(arr)/sizeof(arr[0]));
    if (index == -1)
        cout << "Second Largest didn't exist";
    else
        cout << "Second largest : " << arr[index] << endl;
}