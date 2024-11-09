#include <iostream>
#include <string>
using namespace std;

// Function for Run Length Encoding
string runLengthEncode(const string &input)
{
  string encoded = ""; // To store the encoded string
  int n = input.length();

  // Loop through the input string
  for (int i = 0; i < n; i++)
  {
    // Count occurrences of the same character
    int count = 1;
    while (i < n - 1 && input[i] == input[i + 1])
    {
      i++;
      count++;
    }
    // Append the character and its count to the encoded string
    encoded += to_string(count) + input[i];
  }

  return encoded;
}

// Function for decoding the Run Length Encoded string
string runLengthDecode(const string &encoded)
{
  string decoded = ""; // To store the decoded string
  int n = encoded.length();

  // Loop through the encoded string
  for (int i = 0; i < n; i++)
  {
    // If the character is a digit, extract the full count
    if (isdigit(encoded[i]))
    {
      int count = 0;
      while (i < n && isdigit(encoded[i]))
      {
        count = count * 10 + (encoded[i] - '0');
        i++;
      }
      // Append the character repeated 'count' times
      decoded += string(count, encoded[i]);
    }
  }

  return decoded;
}

int main()
{
  string input = "AAAABBBCCDAA";

  // Run Length Encoding
  string encoded = runLengthEncode(input);
  cout << "Encoded: " << encoded << endl;

  // Run Length Decoding
  string decoded = runLengthDecode(encoded);
  cout << "Decoded: " << decoded << endl;

  return 0;
}
