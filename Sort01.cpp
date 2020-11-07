// Sort a binary array consisting of 0s and 1s.

#include<iostream>
#include<algorithm>

using namespace std;

void sortBinary(int a[], int n){
    int count = 0;

    for (int i=0; i<n; i++){
        count += a[i] == 0;
    }

    for (int i=0; i<n; i++){
        a[i] = (i >= count);
    }
}

void sortBinaryEfficient(int a[], int n){
    int left = 0, right = n-1;

    while (left <= right){
        if (a[left] == 1){
            swap(a[left], a[right]);
            right--;
        } else {
            left++;
        }
    }
}

void display(int a[], int n){
    for (int i=0; i<n; i++){
        cout << a[i] << " ";
    }    
    cout << endl;
}

int main(){
    int a[]={0,1,0,1,0,1,0,1,0,1,0,1};

    int size = sizeof(a) / sizeof(int);

    display(a, size);

    //sortBinary(a,size);

    sortBinaryEfficient(a,size);

    display(a, size);
}

/*

Original: 0 1 0 1 0 1 0 1 0 1 0 1 
Sorted:   0 0 0 0 0 0 1 1 1 1 1 1 

*/
