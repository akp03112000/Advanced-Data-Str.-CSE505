#include <iostream>
using namespace std;

// HashTable class using linear probing for collision resolution
class HashTable
{
  int *table;
  int size;
  int currentSize;

public:
  // Constructor to initialize the hash table with the given size
  HashTable(int size)
  {
    this->size = size;
    table = new int[size];
    currentSize = 0;

    // Initialize table elements to -1 (indicating empty slots)
    for (int i = 0; i < size; i++)
    {
      table[i] = -1;
    }
  }

  // Hash function to map a key to an index
  int hashFunction(int key)
  {
    return key % size;
  }

  // Insert a key into the hash table
  void insert(int key)
  {
    if (currentSize == size)
    {
      cout << "Hash Table is full. Cannot insert new key." << endl;
      return;
    }

    int index = hashFunction(key);

    // Linear probing to find the next available slot
    while (table[index] != -1)
    {
      index = (index + 1) % size;
    }

    table[index] = key; // Insert key
    currentSize++;
  }

  // Search for a key in the hash table
  bool search(int key)
  {
    int index = hashFunction(key);
    int startIdx = index;

    // Linear probing to find the key
    while (table[index] != -1)
    {
      if (table[index] == key)
      {
        return true;
      }
      index = (index + 1) % size;

      // If we've looped through the entire table
      if (index == startIdx)
      {
        break;
      }
    }

    return false; // Key not found
  }

  // Delete a key from the hash table
  void deleteKey(int key)
  {
    int index = hashFunction(key);
    int startIdx = index;

    // Linear probing to find the key
    while (table[index] != -1)
    {
      if (table[index] == key)
      {
        table[index] = -1; // Mark the slot as empty
        currentSize--;
        return;
      }
      index = (index + 1) % size;

      // If we've looped through the entire table
      if (index == startIdx)
      {
        break;
      }
    }

    cout << "Key not found!" << endl;
  }

  // Display the hash table
  void display()
  {
    for (int i = 0; i < size; i++)
    {
      if (table[i] == -1)
      {
        cout << "Index " << i << ": Empty" << endl;
      }
      else
      {
        cout << "Index " << i << ": " << table[i] << endl;
      }
    }
  }
};

int main()
{
  HashTable ht(7); // Create a hash table of size 7

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
