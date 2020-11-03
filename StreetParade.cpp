// https://www.spoj.com/problems/STPAR/

// Street Parade

#include <bits/stdc++.h>
using namespace std;

string streetParade(vector<int> cars){
	stack<int> s;
	
	int order = 1;
	
	for (int i=0; i<cars.size(); i++){
		int car = cars[i];

		while (!s.empty() and order == s.top()){
			order++;
			s.pop();
		}

		if (car == order){
			order++;
		} else if (!s.empty() and car > s.top()){
			return "no";
		} else {
			s.push(car);
		}
	}
	
	while (!s.empty()){
		if (s.top() != order){
			return "no";
		}
		order++;
		s.pop();
	}
	
	return "yes";
}

int main() {
	while (true){
		int n, x;
		cin >> n;
		
		if (n==0) break;
		
		vector<int> v;
		
		for (int i=1; i<=n; i++){
			cin >> x;
			v.push_back(x);
		}	

		cout << streetParade(v) << endl;
	}
	return 0;
}

/*

Input:
6
10
6 1 5 2 7 3 4 10 8 9 
0
5
1 3 4 2 5
0
4
4 2 3 1
0
10
1 2 10 5 4 3 9 8 7 6
0
5
4 1 5 3 2
0
5
3 1 2 5 4
0

Output:
no
no
no
yes
no
yes

*/
