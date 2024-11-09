#include <iostream>
using namespace std;

// Node structure for the linked list
struct Node
{
  int data;
  Node *next;

  // Constructor to initialize a node
  Node(int value)
  {
    data = value;
    next = nullptr;
  }
};

class LinkedList
{
public:
  Node *head;

  // Constructor to initialize an empty list
  LinkedList()
  {
    head = nullptr;
  }

  // Function to insert a new node at the start
  void insertAtStart(int value)
  {
    // Create a new node
    Node *newNode = new Node(value);

    // Point the new node's next to the current head
    newNode->next = head;

    // Update the head to point to the new node
    head = newNode;
  }

  // Function to display the list
  void display()
  {
    if (head == nullptr)
    {
      cout << "List is empty." << endl;
      return;
    }

    Node *temp = head;
    while (temp != nullptr)
    {
      cout << temp->data << " ";
      temp = temp->next;
    }
    cout << endl;
  }
};

int main()
{
  LinkedList list;

  // Insert elements at the start
  list.insertAtStart(10);
  list.insertAtStart(20);
  list.insertAtStart(30);
  list.insertAtStart(40);

  // Display the linked list
  cout << "Linked List: ";
  list.display();

  return 0;
}
