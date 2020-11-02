// https://www.spoj.com/problems/STPAR/

// Street Parade

#include <bits/stdc++.h>
using namespace std;

string streetParade(vector<int> cars){
	vector<int> order(cars);
	sort(order.begin(), order.end());
	
	stack<int> s;
	
	int order_index = 0;
	
	for (int i=0; i<cars.size(); i++){
		int car = cars[i];
			
		if (car == order[order_index]){
			order_index++;
		} else {
			if (s.empty()){
				s.push(car);
			} else {
				if (order[order_index] == s.top()) {
					while (!s.empty() and order[order_index] == s.top()){
						order_index++;
						s.pop();
					}
				} 
				else if (car > s.top()){
					return "no";				
				}
				s.push(car);
			}
		}
	}

	while (!s.empty()){
		if (s.top() == order[order_index]){
			order_index++;
			s.pop();
		} else {
			return "no";
		}
	}
	
	return "yes";
}
int main() {
	int t;
	cin >> t;
	
	while (t--){
		int n, x;
		cin >> n;
		
		vector<int> v;
		
		for (int i=1; i<=n; i++){
			cin >> x;
			v.push_back(x);
		}	
		
		cin>>x;
		
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
