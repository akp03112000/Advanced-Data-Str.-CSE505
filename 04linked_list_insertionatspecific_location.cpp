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

  // Function to insert a new node at a specific position
  void insertAtPosition(int position, int value)
  {
    // Create a new node
    Node *newNode = new Node(value);

    // If inserting at the beginning (position 0)
    if (position == 0)
    {
      newNode->next = head;
      head = newNode;
      return;
    }

    // Traverse to the node just before the specified position
    Node *temp = head;
    int currentPos = 0;

    // Traverse until the node before the specified position
    while (temp != nullptr && currentPos < position - 1)
    {
      temp = temp->next;
      currentPos++;
    }

    // If we reached the end of the list and the position is out of bounds
    if (temp == nullptr)
    {
      cout << "Position out of range!" << endl;
      return;
    }

    // Insert the new node at the specified position
    newNode->next = temp->next;
    temp->next = newNode;
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

  // Insert elements at the beginning
  list.insertAtPosition(0, 10); // List: 10
  list.insertAtPosition(1, 20); // List: 10 20
  list.insertAtPosition(2, 30); // List: 10 20 30
  list.insertAtPosition(1, 15); // List: 10 15 20 30

  // Display the linked list
  cout << "Linked List: ";
  list.display();

  return 0;
}
