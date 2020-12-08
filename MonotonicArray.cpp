// https://leetcode.com/problems/monotonic-array/

// including duplicates

bool isMonotonic(vector<int>& a) {
    int c1 = 0;
    int c2 = 0;

    for (int i=0; i<a.size()-1; i++){
        if (a[i] <= a[i+1])
                c1++;
        if (a[i] >= a[i+1])
                c2++;
    }
    return (c1 == a.size()-1 || c2 == a.size()-1);
}
    
    
