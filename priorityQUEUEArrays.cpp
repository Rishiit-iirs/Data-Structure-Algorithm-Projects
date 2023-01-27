// C++ program to implement Priority Queue
// using Arrays
#include <bits/stdc++.h>
using namespace std;
 
// Structure for the elements in the
// priority queue
struct Process {
    int BurstTime;
    int Priority;
};
 
// Store the element of a priority queue
Process pr[100000];
 
// Pointer to the last index
int size = -1;
 
// Function to insert a new element
// into priority queue
void enqueue(int BT, int priority)
{
    // Increase the size
    size++;
 
    // Insert the element
    pr[size].BurstTime = BT;
    pr[size].Priority = priority;
}
 
// Function to check the top element
int peek()
{
    int maxPriority = INT_MAX;
    int ind = -1;
 
    // Check for the element with
    // highest priority
    for (int i = 0; i <= size; i++) {
 
        // If priority is same choose
        // the Process with 
        // lowest BurstTime value
        if (maxPriority == pr[i].Priority && ind > -1
            && pr[ind].BurstTime > pr[i].BurstTime) {
            maxPriority = pr[i].Priority;
            ind = i;
        }
        else if (maxPriority > pr[i].Priority) {
            maxPriority = pr[i].Priority;
            ind = i;
        }
    }
 
    // Return position of the element
    return ind;
}
 
// Function to remove the element with
// the highest priority
void dequeue()
{
    // Find the position of the element
    // with highest priority
    int ind = peek();
 
    // Shift the element one index before
    // from the position of the element
    // with highest priority is found
    for (int i = ind; i < size; i++) {
        pr[i] = pr[i+1];
    }
 
    // Decrease the size of the
    // priority queue by one
    size--;
}
 
// Driver Code
int main()
{
    // Function Call to insert elements
    // as per the priority
    enqueue(10, 2);
    enqueue(14, 1);
    enqueue(7, 3);
    enqueue(16, 1);
    enqueue(12, 7);
    enqueue(15, 5);
    enqueue(25, 1);
    enqueue(8, 0);
    enqueue(5, 1); 
    // Stores the top element
    // at the moment
    int ind = peek();
 
    cout << pr[ind].BurstTime << endl;
 
    // Dequeue the top element
    dequeue();
         
 
    // Check the top element
    ind = peek();
    cout << pr[ind].BurstTime << endl;
 
    // Dequeue the top element
    dequeue();
 
    // Check the top element
    ind = peek();
    cout << pr[ind].BurstTime << endl;

    dequeue();

    ind = peek();
    cout << pr[ind].BurstTime << endl;

    dequeue();

    ind = peek();
    cout << pr[ind].BurstTime << endl;

    dequeue();

    ind = peek();
    cout << pr[ind].BurstTime << endl;

    return 0;
}