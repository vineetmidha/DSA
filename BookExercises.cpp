
// https://www.hackerearth.com/practice/data-structures/stacks/basics-of-stacks/practice-problems/algorithm/book-exercises-843d7c3b/description/

#include<bits/stdc++.h>

using namespace std;

int main()
{
	long long n;
	cin >> n;

	stack <pair<long long, string>> mainStack;
	stack <long long> minStack;

	while (n--){
		long long ex;
		cin >> ex;

		if (ex != -1){
			string book;
			cin >> book;

			if (ex != 0){
				mainStack.push({ex, book});

				if (minStack.empty()){
					minStack.push(ex);
				} else {
					if (ex < minStack.top()){
						minStack.push(ex);
					} else {
						minStack.push(minStack.top());
					}
				}
			}
		} 
		else {	// popping
			long long count=0;

			while (!mainStack.empty() && minStack.top() != mainStack.top().first){
				count++;
				mainStack.pop();
				minStack.pop();
			}

			if (!mainStack.empty()){
				cout << count << " " << mainStack.top().second << endl;

				mainStack.pop();
				minStack.pop();
			}
		}
	}
}
