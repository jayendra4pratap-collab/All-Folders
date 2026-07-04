
  #include<iostream>
  #include<vector>
  using namespace std;
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
  
  
 
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (!list1)
            return list2;
        if (!list2)
            return list1;

        ListNode *temp1 = list1;
        ListNode *temp2 = list2;
        ListNode *prev = list1;
        while (temp1 != NULL && temp2 != NULL)
        {
            ListNode *next1 = temp1->next;
            ListNode *next2 = temp2->next;

            if (temp1->val == temp2->val)
            {
                temp1->next = temp2;
                temp2->next = next1;
                temp2 = next2;
                temp1 = next1;
            }
            else if (temp1->val < temp2->val)
            {
                temp1 = temp1->next;
                /*temp1->next = temp2;
                temp2->next = next1;
                temp2 = next2;*/
            }
            else
            {
                ListNode *list1Head = temp1;
                if (temp2 == list2)
                {
                    list1 = temp2;
                    temp2->next = list1Head;
                    temp2 = next2;
                    temp1 = list1->next;
                    prev = list1;
                }
                else
                {
                    prev->next = temp2;

                    // temp1 = temp2;
                    temp2->next = list1Head;
                    temp2 = next2;
                    prev = prev->next;
                }
            }
        }
        if (temp2)
        {
            temp1 = temp2;
        }
        return list1;
    }
};
int main()
  {
    
    return 0;
  }