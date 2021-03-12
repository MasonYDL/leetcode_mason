#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<math.h>
#include<ext/hash_map>
#include<list>
#include<stdio.h>
#include<map> 
#include<unordered_map>
#include<numeric>
using namespace std;
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

  class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

  class Solution{
      public:
        int kthToLast(ListNode* head, int k) {
            //面试题02.02 easy

            int len=0;
            ListNode* temp=head;
            while(temp->next)
            {
                ++len;
                temp=temp->next;
            }
            k=len-k+1;
            len=0;
            while(len!=k)
                {head=head->next;
                ++len;}
            return head->val;
    }

        ListNode *detectCycle(ListNode *head) {
            //面试题02.08
            if(!head || !head->next)
                return nullptr;
            ListNode* fast=head;
            ListNode* slow=head;
            while(fast && fast->next)
            {
                fast=fast->next->next;
                slow=slow->next;
                if(fast==slow)
                    break;
            }

            if(fast!=slow)
                return nullptr;
            fast=head;
            while(slow != fast)
            {
                slow=slow->next;
                fast=fast->next;
            }
            return slow;
    }


    ListNode* getKthFromEnd(ListNode* head, int k) {
        //剑指Offer 22
            int len=0;
            ListNode* temp=head;
            while(temp->next)
            {
                ++len;
                temp=temp->next;
            }
            k=len-k+1;
            len=0;
            while(len!=k)
                {head=head->next;
                ++len;}
            return head;
    }


    Node* copyRandomList(Node* head) {
        if(!head)
            return nullptr;
        Node* newhead=new Node(head->val);
        Node* temp1=newhead;
        Node* temp2=head;
        unordered_map <Node*,Node*> map;
        map[temp2]=temp1;
        while(temp2->next)
        {
            Node* cur=new Node(temp2->next->val);
            temp1->next=cur;
            temp1=temp1->next;
            temp2=temp2->next;
            map[temp2]=temp1;
        }
        temp1->next=nullptr;
        temp1=newhead;
        temp2=head;
        while(temp2->next)
        {
            temp1->random=map[temp2->random];
            temp1=temp1->next;
            temp2=temp2->next;
        }
        temp1->random=map[temp2->random];
        return newhead;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        //61 medium
        if(!head || !head->next || k==0)
            return head;
        int len=1;
        ListNode* temp=head;
        while(temp->next)
            {
                temp=temp->next;
                ++len;
            }
        k=k%len;
        temp=head;
        ListNode* fast=head;
        ListNode* slow=head;
        while(k--)
        {
            fast=fast->next;
        }
        while(fast->next)
        {
            fast=fast->next;
            slow=slow->next;
        }
        temp=slow->next;
        slow->next=nullptr;
        fast->next=head;
        return temp;
    }


  };


class Node1
{
public:
    Node1(int val) : val(val), prev(nullptr), next(nullptr) {}

    int val;
    Node1* prev;
    Node1* next;
};

class MyLinkedList {
private:
    // 构建两个虚拟头尾结点来解决边缘情况
    Node1* head;
    Node1* tail;
    // 记录当前链表的大小
    int size;

public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        size = 0;
        head = new Node1(0);
        tail = new Node1(0);
        // 首尾结点链接一起
        head->next = tail;
        tail->prev = head;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        // 考虑无效的范围，index起始是0
        if (index < 0 || index >= size)
        {
            return -1;
        }
        // 按照位置去判断是从前还是后去遍历
        Node* curr = nullptr;
        if (index + index < size)
        {
            curr = head;
            // 这里需要额外+1才能到真正index位置
            for (int i = 0; i < index+1; ++i)
            {
                curr = curr->next;
            }
        }
        else
        {
            curr = tail;
            for (int i = 0; i < size-index; ++i)
            {
                curr = curr->prev;
            }
        }
        return curr->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        // 记录当前头结点的信息
        Node1* prev = head;
        Node1* next = head->next;

        ++size;
        // 给新结点赋值,并且指向两边结点
        Node1* curr = new Node1(val);
        curr->next = next;
        curr->prev = prev;

        // 将两边结点指向新结点
        prev->next = curr;
        next->prev = curr;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        // 记录当前尾结点的信息: 这里赋值顺序和addAtHead是正好相反的
        Node1* next = tail;
        Node1* prev = tail->prev;

        ++size;
        // 给新结点赋值,并且指向两边结点
        Node1* curr = new Node1(val);
        curr->next = next;
        curr->prev = prev;

        // 将两边结点指向新结点
        prev->next = curr;
        next->prev = curr;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        // 实现了deleteAtIndex前半部完全一样
        // 这里允许index和size相等，即插入到最后的位置，等价于 addAtTail
        if (index >= 0 && index <= size)
        {
            Node1* prev = nullptr;
            Node1* next = nullptr;
            // 按照位置去判断是从前还是后去遍历
            if (index + index < size)
            {
                prev = head;
                // 这里要到 index-1的位置就结束了，所以和Get不一样，无需+1
                for (int i = 0; i < index; ++i)
                {
                    prev = prev->next;
                }
                next = prev->next;
                // cout << "head add " << prev->val << " " << next->val << endl;
            }
            else
            {
                next = tail;
                for (int i = 0; i < size-index; ++i)
                {
                    next = next->prev;
                }
                prev = next->prev;
                // cout << "tail add " << prev->val << " " << next->val << endl;
            }
            
            Node1* newNode = new Node1(val);
            newNode->prev = prev;
            newNode->next = next;
            prev->next = newNode;
            next->prev = newNode;
            ++size;
        }
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        // 考虑无效的范围，index起始是0
        if (index >= 0 && index < size)
        {
            Node1* prev = nullptr;
            Node1* next = nullptr;
            // 按照位置去判断是从前还是后去遍历
            if (index + index < size)
            {
                prev = head;
                // 这里要到 index-1的位置就结束了，所以和Get不一样，无需+1
                for (int i = 0; i < index; ++i)
                {
                    prev = prev->next;
                }
                next = prev->next->next;
            }
            else
            {
                next = tail;
                for (int i = 0; i < size-index-1; ++i)
                {
                    next = next->prev;
                }
                prev = next->prev->prev;
            }
            
            // 跳过prev的下一个结点（就是对应 index编号）
            prev->next = next;
            next->prev = prev;
            --size;
        }

    }
};