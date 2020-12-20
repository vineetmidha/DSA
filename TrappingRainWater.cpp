// https://www.geeksforgeeks.org/trapping-rain-water/

int trappingWater(int height[], int n){

        int left=0; 
        int right=n-1;
        int res=0;
        int maxleft=0, maxright=0;
        
        while(left<=right){
            
            if(height[left]<=height[right]){

                if(height[left]>=maxleft) 
                    maxleft=height[left];
                else 
                    res+=maxleft-height[left];
                
                left++;
            }
            else{

                if(height[right]>=maxright) 
                    maxright= height[right];
                else 
                    res+=maxright-height[right];
                
                right--;
            }
        }
        return res;
    
}
