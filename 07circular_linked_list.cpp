#include <iostream>
using namespace std;

// Node structure for the circular linked list
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

class CircularLinkedList
{
public:
  Node *head;

  // Constructor to initialize an empty list
  CircularLinkedList()
  {
    head = nullptr;
  }

  // Function to insert a new node at the beginning
  void insertAtBeginning(int value)
  {
    Node *newNode = new Node(value);

    if (head == nullptr)
    {
      head = newNode;
      newNode->next = head; // Make it circular
    }
    else
    {
      Node *temp = head;
      while (temp->next != head)
      {
        temp = temp->next;
      }
      temp->next = newNode;
      newNode->next = head;
      head = newNode;
    }
  }

  // Function to insert a new node at the end
  void insertAtEnd(int value)
  {
    Node *newNode = new Node(value);

    if (head == nullptr)
    {
      head = newNode;
      newNode->next = head; // Make it circular
    }
    else
    {
      Node *temp = head;
      while (temp->next != head)
      {
        temp = temp->next;
      }
      temp->next = newNode;
      newNode->next = head;
    }
  }

  // Function to insert a new node at a specific position
  void insertAtPosition(int position, int value)
  {
    if (position < 0)
    {
      cout << "Invalid position!" << endl;
      return;
    }

    Node *newNode = new Node(value);

    // If inserting at position 0, insert at the beginning
    if (position == 0)
    {
      insertAtBeginning(value);
      return;
    }

    Node *temp = head;
    int currentPos = 0;

    // Traverse the list to find the node before the specified position
    while (temp != nullptr && currentPos < position - 1)
    {
      temp = temp->next;
      currentPos++;
      if (temp == head)
      {
        break;
      }
    }

    if (temp == nullptr || temp->next == head)
    {
      cout << "Position out of range!" << endl;
      return;
    }

    // Insert the new node after temp
    newNode->next = temp->next;
    temp->next = newNode;
  }

  // Function to delete the head node
  void deleteHead()
  {
    if (head == nullptr)
    {
      cout << "List is empty!" << endl;
      return;
    }

    if (head->next == head)
    {
      delete head;
      head = nullptr;
      return;
    }

    Node *temp = head;
    while (temp->next != head)
    {
      temp = temp->next;
    }

    // Temp is now the last node
    temp->next = head->next;
    Node *toDelete = head;
    head = head->next;
    delete toDelete;
  }

  // Function to delete the last node
  void deleteLast()
  {
    if (head == nullptr)
    {
      cout << "List is empty!" << endl;
      return;
    }

    if (head->next == head)
    {
      delete head;
      head = nullptr;
      return;
    }

    Node *temp = head;
    while (temp->next->next != head)
    {
      temp = temp->next;
    }

    // Temp is now the second last node
    Node *toDelete = temp->next;
    temp->next = head;
    delete toDelete;
  }

  // Function to delete a node at a specific position
  void deleteAtPosition(int position)
  {
    if (head == nullptr || position < 0)
    {
      cout << "List is empty or invalid position!" << endl;
      return;
    }

    // If deleting the head node
    if (position == 0)
    {
      deleteHead();
      return;
    }

    Node *temp = head;
    int currentPos = 0;

    // Traverse the list to find the node before the specified position
    while (temp != nullptr && currentPos < position - 1)
    {
      temp = temp->next;
      currentPos++;
      if (temp == head)
      {
        break;
      }
    }

    if (temp == nullptr || temp->next == head)
    {
      cout << "Position out of range!" << endl;
      return;
    }

    // Unlink the node to be deleted
    Node *toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
  }

  // Function to display the list
  void display()
  {
    if (head == nullptr)
    {
      cout << "List is empty!" << endl;
      return;
    }

    Node *temp = head;
    do
    {
      cout << temp->data << " ";
      temp = temp->next;
    } while (temp != head);
    cout << endl;
  }
};

int main()
{
  CircularLinkedList list;

  // Insert elements at the beginning, end, and at a specific position
  list.insertAtBeginning(10);
  list.insertAtEnd(20);
  list.insertAtEnd(30);
  list.insertAtPosition(1, 15); // Insert at position 1

  cout << "Circular List: ";
  list.display();

  // Deleting nodes
  list.deleteHead();        // Delete head node
  list.deleteLast();        // Delete last node
  list.deleteAtPosition(1); // Delete node at position 1

  cout << "Circular List after deletions: ";
  list.display();

  return 0;
}
