#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

// Structure to represent a Huffman Tree Node
struct HuffmanNode
{
  char data;                 // Store the character
  int frequency;             // Store frequency of the character
  HuffmanNode *left, *right; // Left and right child nodes

  HuffmanNode(char data, int frequency)
  {
    this->data = data;
    this->frequency = frequency;
    left = right = nullptr;
  }
};

// Comparison function to help in creating a min-heap (priority queue)
struct Compare
{
  bool operator()(HuffmanNode *left, HuffmanNode *right)
  {
    return left->frequency > right->frequency;
  }
};

// Function to generate the Huffman codes
void generateCodes(HuffmanNode *root, string code, unordered_map<char, string> &huffmanCodes)
{
  if (root == nullptr)
    return;

  // If leaf node, store the character and its corresponding code
  if (root->left == nullptr && root->right == nullptr)
  {
    huffmanCodes[root->data] = code;
  }

  // Traverse left and right subtrees with updated code
  generateCodes(root->left, code + "0", huffmanCodes);
  generateCodes(root->right, code + "1", huffmanCodes);
}

// Function to perform Huffman Coding and return the encoded string
string huffmanCoding(string text, unordered_map<char, string> &huffmanCodes)
{
  // Step 1: Calculate frequency of each character
  unordered_map<char, int> freq;
  for (char ch : text)
  {
    freq[ch]++;
  }

  // Step 2: Create a priority queue (min-heap) for Huffman tree construction
  priority_queue<HuffmanNode *, vector<HuffmanNode *>, Compare> minHeap;

  // Step 3: Create a Huffman node for each character and add to the priority queue
  for (auto pair : freq)
  {
    minHeap.push(new HuffmanNode(pair.first, pair.second));
  }

  // Step 4: Build the Huffman Tree
  while (minHeap.size() > 1)
  {
    // Extract two nodes with the lowest frequency
    HuffmanNode *left = minHeap.top();
    minHeap.pop();
    HuffmanNode *right = minHeap.top();
    minHeap.pop();

    // Create a new internal node with the sum of the frequencies
    HuffmanNode *internalNode = new HuffmanNode('$', left->frequency + right->frequency);
    internalNode->left = left;
    internalNode->right = right;

    // Insert the internal node back into the priority queue
    minHeap.push(internalNode);
  }

  // Step 5: Generate the Huffman codes
  HuffmanNode *root = minHeap.top();
  generateCodes(root, "", huffmanCodes);

  // Step 6: Encode the input text using the generated Huffman codes
  string encoded = "";
  for (char ch : text)
  {
    encoded += huffmanCodes[ch];
  }

  return encoded;
}

// Function to decode the Huffman encoded string
string huffmanDecode(HuffmanNode *root, string encoded)
{
  string decoded = "";
  HuffmanNode *current = root;

  for (char bit : encoded)
  {
    if (bit == '0')
      current = current->left;
    else
      current = current->right;

    // If a leaf node is reached, add the character to the decoded string
    if (current->left == nullptr && current->right == nullptr)
    {
      decoded += current->data;
      current = root; // Reset to the root for the next character
    }
  }

  return decoded;
}

int main()
{
  string text = "ABRACADABRA";

  unordered_map<char, string> huffmanCodes;

  // Perform Huffman Coding
  string encoded = huffmanCoding(text, huffmanCodes);

  // Print Huffman Codes for each character
  cout << "Huffman Codes: " << endl;
  for (auto pair : huffmanCodes)
  {
    cout << pair.first << ": " << pair.second << endl;
  }

  cout << "\nEncoded Text: " << encoded << endl;

  // Decode the encoded text
  HuffmanNode *root = new HuffmanNode('$', 0);
  priority_queue<HuffmanNode *, vector<HuffmanNode *>, Compare> minHeap;
  unordered_map<char, int> freq;

  // Rebuild the Huffman Tree from the codes
  for (char ch : text)
  {
    freq[ch]++;
  }
  for (auto pair : freq)
  {
    minHeap.push(new HuffmanNode(pair.first, pair.second));
  }

  while (minHeap.size() > 1)
  {
    HuffmanNode *left = minHeap.top();
    minHeap.pop();
    HuffmanNode *right = minHeap.top();
    minHeap.pop();
    HuffmanNode *internalNode = new HuffmanNode('$', left->frequency + right->frequency);
    internalNode->left = left;
    internalNode->right = right;
    minHeap.push(internalNode);
  }

  root = minHeap.top();

  string decoded = huffmanDecode(root, encoded);
  cout << "\nDecoded Text: " << decoded << endl;

  return 0;
}
