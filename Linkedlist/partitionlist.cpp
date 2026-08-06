/*
Approach:

- Create two dummy nodes:
  - `dummysmall` to store nodes with values less than `x`.
  - `dummylarge` to store nodes with values greater than or equal to `x`.
- Maintain two pointers:
  - `small` for the end of the smaller list.
  - `large` for the end of the larger list.
- Traverse the original linked list:
  1. If `head->val < x`:
     - Append the current node to the smaller list.
     - Move the `small` pointer forward.
  2. Otherwise:
     - Append the current node to the larger list.
     - Move the `large` pointer forward.
  3. Disconnect the appended node by setting its `next` to `NULL`.
  4. Move to the next node in the original list.
- After the traversal, connect the end of the smaller list to the beginning of the larger list.
- Return the head of the new partitioned list (`dummysmall->next`).

Time Complexity: O(n)

- The linked list is traversed only once.
- Each node is processed exactly once.

Space Complexity: O(1)

- Only two dummy nodes and a few pointers are used.
- No extra space proportional to the input size is required.
*/






class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode * dummysmall = new ListNode(-1);
        ListNode * dummylarge = new ListNode(-1);
        ListNode * small = dummysmall;
        ListNode * large = dummylarge;

        while(head!=NULL){
            if(head->val <x){
                small->next = head;
                small = small->next;
                head=head->next;
                small->next = NULL;
            }
            else {
                large->next = head;
                large = large->next;
                head= head->next;
                large->next=NULL;
            }

        }
        small->next = dummylarge->next;
        return dummysmall->next;
    }
};