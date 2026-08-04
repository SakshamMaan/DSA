/*
    Next Greater Element I
    ----------------------
    Approach:
    - Traverse nums2 from right to left using a monotonic decreasing stack.
    - Store each element and its next greater element in an unordered_map.
    - Traverse nums1 and fetch the answer directly from the map.

    Time Complexity:
    - Building map : O(n)
    - Answer queries : O(m)
    - Overall : O(n + m)

    Space Complexity:
    - Stack : O(n)
    - unordered_map : O(n)
    - Answer vector : O(m)
    - Overall : O(n + m)
*/






class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
      stack<int>st;
      unordered_map<int,int>mp;
      vector<int>ans;

      for(int i=nums2.size()-1;i>=0;i--){
        while(!st.empty() && st.top()<=nums2[i]){
            st.pop();
        }
        if(st.empty()){
            mp[nums2[i]]=-1;
        }
        else{
            mp[nums2[i]]=st.top();
        }
        st.push(nums2[i]);
      } 
      
      

      for(int i=0;i<nums1.size();i++){
        auto it = mp.find(nums1[i]);

        ans.push_back(it->second);
      }
     return ans;
    }
};