
/*
Naive Approach -> O(n^2)
========================
Iterate through the histograms from left to right. 
For each iteration, look backward to see how far could the current height extend to 
and find out the largest area.
*/

#include <iostream>
#include <vector> 

using namespace std;

int getMax(int a, int b){
    return a > b ? a : b;
}

int getMin(int a, int b){
    return a < b ? a : b;
}

int histogram_area (vector<int> hist){
    int maxArea = 0;

    for (int i = 0; i < hist.size(); ++i){
        int h = hist.at(i);

        maxArea = getMax(maxArea, h);
        
        for (int j = i - 1; j >= 0; --j){
            int width = i - j + 1;
            h = getMin(h, hist[j]);
            maxArea = getMax(maxArea, h * width);
        }
    }
    return maxArea;
}

int main() {
    int n;
    cin>>n;
    
    vector<int> hist;
    
    for (int i = 0; i < n; i++){
        int ht;
        cin >> ht;
        hist.push_back(ht);
    }
    
    cout<<histogram_area(hist);

	return 0;
}

/*
Input: 
6
2 1 5 6 2 3
Output: 
10
Input: 
5
1 2 3 4 5
Output: 
9
Input: 
7
10 40 30 70 10 30 60
Output: 
90
*/
