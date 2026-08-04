/*
Approach:
- Since the array is circular, traverse it twice from right to left.
- Use a monotonic decreasing stack to keep track of the next greater elements.
- For each element:
    1. Pop all elements from the stack that are smaller than or equal to the current element.
    2. If we are in the first traversal (i < n):
        - If the stack is empty, there is no next greater element.
        - Otherwise, the top of the stack is the next greater element.
    3. Push the current element onto the stack.
- Using i % n simulates the circular nature of the array.

Time Complexity: O(n)
- Although we iterate 2n times, each element is pushed and popped at most twice.
- Therefore, the total number of stack operations is linear.

Space Complexity: O(n)
- The stack can store up to n elements in the worst case.
- The answer array also takes O(n) space.
*/



class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
     stack<int>st;
     vector<int>ans(nums.size());
     int n = nums.size();


     for(int i=2*nums.size()-1;i>=0;i--){
        while(!st.empty() && st.top()<=nums[i%n]){
            st.pop();
        }
        if(i<n){
            if(st.empty()) {
               ans[i]=-1;
            }
            else{
                ans[i] = st.top();
            }
            
        }
        st.push(nums[i%n]);
        
    
     }   
     
     return ans;
    }
};