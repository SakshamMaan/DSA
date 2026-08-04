/*
Problem: Previous Smaller Element
Platform: GeeksforGeeks

Approach:
- Traverse the array from left to right.
- Use a monotonic increasing stack to store possible previous smaller elements.
- For every element:
    1. Remove elements from the stack that are greater than or equal to the current element.
    2. The top of the stack (if it exists) is the previous smaller element.
    3. Push the current element into the stack.

Time Complexity: O(n)
- Each element is pushed into the stack once and popped at most once.

Space Complexity: O(n)
- In the worst case, the stack can contain all elements.
*/


class Solution {
  public:
    vector<int> prevSmaller(vector<int>& arr) {
        stack<int>st;
        vector<int>ans(arr.size());
        
        
        for(int i=0;i<arr.size();i++){
            while(!st.empty() && st.top()>=arr[i]){
                st.pop();
            }
            if(st.empty()){
                ans[i]=-1;
            }
            else{
                ans[i]=st.top();
            }
            st.push(arr[i]);
        }
        return ans;
        
    }
};