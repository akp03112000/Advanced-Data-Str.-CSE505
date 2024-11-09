#include <iostream>
#include <list>
using namespace std;

// HashTable class using chaining for collision resolution
class HashTable
{
  int size;         // Size of the hash table
  list<int> *table; // Array of linked lists

public:
  // Constructor to initialize the hash table with the given size
  HashTable(int size)
  {
    this->size = size;
    table = new list<int>[size];
  }

  // Hash function to map a key to an index
  int hashFunction(int key)
  {
    return key % size;
  }

  // Insert a key into the hash table
  void insert(int key)
  {
    int index = hashFunction(key);
    table[index].push_back(key); // Add key to the linked list at the computed index
  }

  // Search for a key in the hash table
  bool search(int key)
  {
    int index = hashFunction(key);
    // Traverse the linked list at the computed index
    for (int elem : table[index])
    {
      if (elem == key)
      {
        return true;
      }
    }
    return false; // Key not found
  }

  // Delete a key from the hash table
  void deleteKey(int key)
  {
    int index = hashFunction(key);
    // Traverse the linked list at the computed index and remove the key
    table[index].remove(key);
  }

  // Display the hash table
  void display()
  {
    for (int i = 0; i < size; i++)
    {
      cout << "Index " << i << ": ";
      for (int elem : table[i])
      {
        cout << elem << " ";
      }
      cout << endl;
    }
  }
};

int main()
{
  HashTable ht(7); // Create a hash table with size 7

  // Insert elements into the hash table
  ht.insert(10);
  ht.insert(20);
  ht.insert(15);
  ht.insert(30);
  ht.insert(17);
  ht.insert(22);

  // Display the hash table
  cout << "Hash Table after insertion:" << endl;
  ht.display();

  // Search for a key
  int keyToSearch = 15;
  if (ht.search(keyToSearch))
  {
    cout << keyToSearch << " found in the hash table." << endl;
  }
  else
  {
    cout << keyToSearch << " not found in the hash table." << endl;
  }

  // Delete a key
  int keyToDelete = 20;
  ht.deleteKey(keyToDelete);
  cout << "Hash Table after deleting " << keyToDelete << ":" << endl;
  ht.display();

  return 0;
}
