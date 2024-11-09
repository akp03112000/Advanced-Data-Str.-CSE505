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

  // Function to insert a new node at the end
  void insertAtEnd(int value)
  {
    // Create a new node
    Node *newNode = new Node(value);

    // If the list is empty, the new node becomes the head
    if (head == nullptr)
    {
      head = newNode;
    }
    else
    {
      // Traverse to the last node
      Node *temp = head;
      while (temp->next != nullptr)
      {
        temp = temp->next;
      }

      // Set the next pointer of the last node to the new node
      temp->next = newNode;
    }
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

  // Insert elements at the end
  list.insertAtEnd(10);
  list.insertAtEnd(20);
  list.insertAtEnd(30);
  list.insertAtEnd(40);

  // Display the linked list
  cout << "Linked List: ";
  list.display();

  return 0;
}
