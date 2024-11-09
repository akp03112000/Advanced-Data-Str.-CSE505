#include <iostream>
using namespace std;

// HashTable class using double hashing for collision resolution
class HashTable
{
  int *table;
  int size;

public:
  // Constructor to initialize the hash table with the given size
  HashTable(int size)
  {
    this->size = size;
    table = new int[size];

    // Initialize table elements to -1 (indicating empty slots)
    for (int i = 0; i < size; i++)
    {
      table[i] = -1;
    }
  }

  // Primary hash function to map a key to an index
  int hash1(int key)
  {
    return key % size;
  }

  // Secondary hash function to calculate the step size
  int hash2(int key)
  {
    return (size - (key % size)); // We use a different formula for the second hash
  }

  // Insert a key into the hash table using double hashing
  void insert(int key)
  {
    int index = hash1(key);
    int stepSize = hash2(key);
    int i = 0;

    // Try to find an empty spot using double hashing
    while (table[(index + i * stepSize) % size] != -1)
    {
      i++;
    }

    table[(index + i * stepSize) % size] = key; // Insert key
  }

  // Search for a key in the hash table using double hashing
  bool search(int key)
  {
    int index = hash1(key);
    int stepSize = hash2(key);
    int i = 0;

    // Probe the table to find the key
    while (table[(index + i * stepSize) % size] != -1)
    {
      if (table[(index + i * stepSize) % size] == key)
      {
        return true; // Key found
      }
      i++;
    }

    return false; // Key not found
  }

  // Delete a key from the hash table using double hashing
  void deleteKey(int key)
  {
    int index = hash1(key);
    int stepSize = hash2(key);
    int i = 0;

    // Probe the table to find and delete the key
    while (table[(index + i * stepSize) % size] != -1)
    {
      if (table[(index + i * stepSize) % size] == key)
      {
        table[(index + i * stepSize) % size] = -1; // Mark the slot as empty
        return;
      }
      i++;
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
