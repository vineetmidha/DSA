// https://practice.geeksforgeeks.org/problems/first-repeating-element/0#

#include <bits/stdc++.h>

using namespace std;

int FirstRepeatingElement(vector<int> &v){
    set<int> s;
    int min = -1;
    for (int i=v.size()-1; i>=0; i--){
        if (s.find(v[i]) != s.end()){
            min = i;
        } else {
            s.insert(v[i]);
        }
    }
    
    if (min != -1)
        return min+1;
    else
        return min;
}
int main() {
	int t;
	cin >> t;
	
	vector<int> v;

	while (t--) {
    	int n;
    	cin >> n;
    	
    	for (int i=0; i<n; i++){
    	    int x;
    	    cin >> x;
    	    v.push_back(x);
    	}

    	cout << FirstRepeatingElement(v) << endl;
    	
        v.clear();
    }
	
	return 0;
}

/*

Input:
3
7
1 5 3 4 3 5 6
4
1 2 3 4
5
1 2 2 1 3

Output:
2
-1
1

*/
