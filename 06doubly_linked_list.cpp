#include <iostream>
using namespace std;

// Node structure for the doubly linked list
struct Node
{
  int data;
  Node *next;
  Node *prev;

  // Constructor to initialize a node
  Node(int value)
  {
    data = value;
    next = nullptr;
    prev = nullptr;
  }
};

class DoublyLinkedList
{
public:
  Node *head;

  // Constructor to initialize an empty list
  DoublyLinkedList()
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
    }
    else
    {
      newNode->next = head;
      head->prev = newNode;
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
      return;
    }

    Node *temp = head;
    while (temp->next != nullptr)
    {
      temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
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

    // Traverse the list to the node before the specified position
    while (temp != nullptr && currentPos < position - 1)
    {
      temp = temp->next;
      currentPos++;
    }

    if (temp == nullptr)
    {
      cout << "Position out of range!" << endl;
      return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != nullptr)
    {
      temp->next->prev = newNode;
    }

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

    Node *temp = head;
    head = head->next;

    if (head != nullptr)
    {
      head->prev = nullptr;
    }

    delete temp;
  }

  // Function to delete the last node
  void deleteLast()
  {
    if (head == nullptr)
    {
      cout << "List is empty!" << endl;
      return;
    }

    if (head->next == nullptr)
    {
      delete head;
      head = nullptr;
      return;
    }

    Node *temp = head;
    while (temp->next != nullptr)
    {
      temp = temp->next;
    }

    temp->prev->next = nullptr;
    delete temp;
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
    while (temp != nullptr && currentPos < position)
    {
      temp = temp->next;
      currentPos++;
    }

    if (temp == nullptr)
    {
      cout << "Position out of range!" << endl;
      return;
    }

    // Unlink the node to be deleted
    if (temp->prev != nullptr)
    {
      temp->prev->next = temp->next;
    }
    if (temp->next != nullptr)
    {
      temp->next->prev = temp->prev;
    }

    delete temp;
  }

  // Function to display the list from head to tail (forward)
  void displayForward()
  {
    if (head == nullptr)
    {
      cout << "List is empty!" << endl;
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

  // Function to display the list from tail to head (backward)
  void displayBackward()
  {
    if (head == nullptr)
    {
      cout << "List is empty!" << endl;
      return;
    }

    // Traverse to the last node
    Node *temp = head;
    while (temp->next != nullptr)
    {
      temp = temp->next;
    }

    // Traverse backward and print the list
    while (temp != nullptr)
    {
      cout << temp->data << " ";
      temp = temp->prev;
    }
    cout << endl;
  }
};

int main()
{
  DoublyLinkedList list;

  // Insert elements at the beginning and end
  list.insertAtBeginning(10);
  list.insertAtEnd(20);
  list.insertAtEnd(30);
  list.insertAtPosition(1, 15); // Insert at position 1

  cout << "List (forward): ";
  list.displayForward();

  cout << "List (backward): ";
  list.displayBackward();

  // Deleting nodes
  list.deleteHead();        // Delete head node
  list.deleteLast();        // Delete last node
  list.deleteAtPosition(1); // Delete node at position 1

  cout << "List after deletions (forward): ";
  list.displayForward();

  return 0;
}
