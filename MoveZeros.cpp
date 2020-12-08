// https://leetcode.com/problems/move-zeroes/solution/

void moveZeroes(vector<int>& a) {

    int left = 0;

    for (int i=0; i<a.size(); i++){
        if (a[i] != 0){
            a[left++] = a[i];
        }
    }

    while (left < a.size()){
        a[left++] = 0;
    }
}
    
    
