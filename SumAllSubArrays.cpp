// https://www.geeksforgeeks.org/sum-of-all-subarrays/

#include <iostream>
using namespace std;

int SumAllSubArrays(int a[], int n){
    int sum = 0;
    for (int i=0; i<n; i++){
        sum += a[i] * (n-i) * (i+1);
    }
    return sum;
}
int main() {
	int n=4;
	int a[n] = {1,2,3,4};
	cout<<SumAllSubArrays(a,n);
	return 0;
}

/*

a = [1,2,3]

Sub-arrays:
[1], [1,2], [1,2,3]
[2], [2,3]
[3]

Sum = 20

*/
