// Sort an array which contains only 0, 1 and 2, in O(n) time and O(1) space.

#include <iostream>

using namespace std;

void swap (int &a, int &b){
    int t;
    t = a;
    a = b;
    b = t;
}

void sort_012 (int a[], int n){
    int low = 0;
    int mid = 0;
    int high = n - 1;
    
    for (int i = 0; i < n; i++){
        if (a[mid] == 2){
            swap (a[mid], a[high]);
            high--;
        } else if (a[mid] == 1){
            mid++;
        } else {
            swap (a[mid], a[low]);
            low++;
            mid++;
        }
    }
}

void display(int a[], int n){
    
    for (int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    
    cout << endl;
}

int main()
{
    int a[] = {2,1,1,0,1,0,1,2,1,0,2,1,2};
    
    int size = sizeof(a) / sizeof(int);
    
    cout << "Original Array: ";
    
    display(a, size);
    
    sort_012(a, size);

    cout << "Sorted Array: ";
    
    display(a, size);
    
    return 0;
}

/*

Output:

Original Array: 2 1 1 0 1 0 1 2 1 0 2 1 2                                                                                                      
Sorted Array: 0 0 0 1 1 1 1 1 1 2 2 2 2 

*/
