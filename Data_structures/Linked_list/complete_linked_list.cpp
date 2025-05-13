#include <bits/stdc++.h>
using namespace std;

#define int int64_t

class node
{
public:
  int data;
  node *next;
  node(int data1, node *next1) : data(data1), next(next1) {}
  node(int data1) : data(data1), next(nullptr) {}
};
void print(node *head)
{
  while (head != NULL)
  {
    cout << head->data << " ";
    head = head->next;
  }
}
node *insert_head(node *head, int val)
{
  node *temp = new node(val, head);
  return temp;
  // temp pointer hai;
}
// delete a node not tail node

void del(node *n)
{
  node *temp = n->next; // store the next node
  n->data = temp->data; // copy data from next
  n->next = temp->next; // bypass next
  delete temp;          // delete original next
}

node *del_tail(node *head)
{
  if (head == NULL)
    return NULL;
  if (head->next == NULL)
  {
    delete head;
    return NULL;
  }
  node *temp = head;
  while (temp->next->next != NULL)
    temp = temp->next;
  delete temp->next;
  temp->next = NULL;
  return head;
}

// to count the length of linked list
int len(node *head)
{
  int cnt = 0;
  while (head != NULL)
    head = head->next, cnt++;
  return cnt;
}
// to search a element in linked_list
bool is_found(node *head, int val)
{
  while (head != NULL)
  {
    if (head->data == val)
      return true;
    head = head->next;
  }
  return false;
}

int32_t main()
{
  vector<int> arr{1, 2, 3, 4};
  int val = 100;
  node *head = new node(arr[0]);
  head->next = new node(arr[1]);
  head->next->next = new node(arr[2]);
  head->next->next->next = new node(arr[3]);
  head = insert_head(head, val);
  // print(head);
  // del(head);
  if (is_found(head, 9))
    cout << len(head) << "\n";
}

