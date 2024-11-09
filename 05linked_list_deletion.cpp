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

  // Function to delete the head node
  void deleteHead()
  {
    if (head == nullptr)
    {
      cout << "List is empty. Cannot delete head." << endl;
      return;
    }
    Node *temp = head;
    head = head->next; // Move the head to the next node
    delete temp;       // Delete the old head node
  }

  // Function to delete a node at a specific position
  void deleteAtPosition(int position)
  {
    if (head == nullptr)
    {
      cout << "List is empty. Cannot delete." << endl;
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
    }

    // If position is out of range
    if (temp == nullptr || temp->next == nullptr)
    {
      cout << "Position out of range!" << endl;
      return;
    }

    // Delete the node at the specified position
    Node *nodeToDelete = temp->next;
    temp->next = temp->next->next; // Link to the next of the node to be deleted
    delete nodeToDelete;           // Delete the node
  }

  // Function to delete the last node
  void deleteLast()
  {
    if (head == nullptr)
    {
      cout << "List is empty. Cannot delete last node." << endl;
      return;
    }

    // If there's only one node
    if (head->next == nullptr)
    {
      delete head;
      head = nullptr;
      return;
    }

    Node *temp = head;
    // Traverse to the second-last node
    while (temp->next != nullptr && temp->next->next != nullptr)
    {
      temp = temp->next;
    }

    // Delete the last node
    Node *lastNode = temp->next;
    temp->next = nullptr;
    delete lastNode;
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

  // Insert some nodes at the end
  list.deleteHead(); // Should show "List is empty. Cannot delete head."

  list.deleteAtPosition(0); // Should show "List is empty. Cannot delete."

  list.deleteLast(); // Should show "List is empty. Cannot delete last node."

  // Now let's add some nodes and test the deletion
  list.deleteHead();        // Testing on an empty list
  list.deleteAtPosition(0); // Trying to delete from an empty list
  list.deleteLast();        // Testing on an empty list

  // Add nodes manually for testing
  list.head = new Node(10);
  list.head->next = new Node(20);
  list.head->next->next = new Node(30);
  list.head->next->next->next = new Node(40);

  cout << "Before Deletion:" << endl;
  list.display();

  // Test delete head
  list.deleteHead();
  cout << "After deleting head:" << endl;
  list.display();

  // Test delete last
  list.deleteLast();
  cout << "After deleting last node:" << endl;
  list.display();

  // Test delete at a specific position
  list.deleteAtPosition(1);
  cout << "After deleting node at position 1:" << endl;
  list.display();

  return 0;
}
