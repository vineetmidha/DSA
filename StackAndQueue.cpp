// https://www.hackerearth.com/practice/data-structures/stacks/basics-of-stacks/practice-problems/algorithm/staque-1-e790a29f/description/

#include<iostream>

using namespace std;

long solve(long a[], int n, int k)
{
	long sumK=0;

	for (int i=n-k; i<n; i++){
		sumK += a[i];
	}

	long ans=0;
	long sum=0;

	for (int i=0; i<k; i++){
		sum += a[i];
		sumK -= a[n-k+i];
		ans = max(sum+sumK, ans);
	}

	return ans;
}
int main()
{
	int n, k;
	cin >> n >> k;

	long a[n];

	for (int i=0; i<n; i++){
		cin >> a[i];
	}

	cout << solve(a, n, k) << endl;
}
