/*
Approach:

- Use two pointers:
  - `l` starts from the left end.
  - `r` starts from the right end.
- Maintain two variables:
  - `leftMax` = maximum height seen so far from the left.
  - `rightMax` = maximum height seen so far from the right.
- While `l < r`:
  1. If `height[l] <= height[r]`:
     - If `height[l] < leftMax`, water trapped is `leftMax - height[l]`.
     - Otherwise, update `leftMax`.
     - Move `l` one step to the right.
  2. Otherwise:
     - If `height[r] < rightMax`, water trapped is `rightMax - height[r]`.
     - Otherwise, update `rightMax`.
     - Move `r` one step to the left.
- Continue until both pointers meet.
- Return the total amount of trapped water.

Time Complexity: O(n)

- Each pointer traverses the array at most once.
- Every element is processed exactly once.

Space Complexity: O(1)

- Only a few extra variables (`l`, `r`, `leftMax`, `rightMax`, and `total`) are used.
- No additional data structures are required.
*/





class Solution {
public:
    int trap(vector<int>& height) {
        int l =0;
        int r = height.size()-1;
        int leftmax=0;
        int rightmax=0;
        int total=0;

        while(l<r){
            if(height[l]<=height[r]){
                if(leftmax > height[l]){
                 total += leftmax-height[l];
                }
                else{
                    leftmax = height[l];
                    
                }
                l++;
              

            }
            else{
                if(rightmax > height[r]){
                    total += rightmax - height[r];
                }
                else{
                    rightmax = height[r];
                   
                }
             r--;
            }
            
        }
        return total;
    }
};