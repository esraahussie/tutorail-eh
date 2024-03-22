// File: CS112_A2_T2_S19 S20_20230123_20230052_20230538.cpp

// Authors :
// Hassan Abdallah Hassan Mohamed
// Esraa Hussien Mohamed Abdullah
// Yomn Tarek Fathi Arab

// Section -->> S19 S20

// Who did which cipher
// cipher 3 (Vignere) -->> Hassan
// cipher 2 (Atbash) -->> Esraa
// cipher 8 (XOR) -->> Yomn

//ID for Hassan : 20230123
//ID for Esraa : 20230052
//ID for Yomn : 20230538

#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <bitset>
#include <sstream>
#include <iomanip>

using namespace std;

// Hassan
// Function to perform Vigenère encryption
string vigenereEncrypt(const string& message, const string& keyword) {
   string encryptedMessage;
  int keywordLength = keyword.length();

  for (size_t i = 0; i < message.length(); ++i) {
    char c = message[i];
    if (isalpha(c)) {
      char keywordChar = keyword[i % keywordLength];
      int shift = toupper(keywordChar) - 'A';
      char encryptedChar = (toupper(c) - 'A' + shift) % 26 + 'A';
      encryptedMessage += encryptedChar;
    } else {
      encryptedMessage += c;
    }
  }

  return encryptedMessage;
}

// Example usage function
void encryptMessage() {
  string message, keyword;
  cin.ignore();
  do {
    cout << "Enter the message (up to 80 characters): ";
    getline(cin, message);
  } while (message.length() > 80);

  do {
    cout << "Enter the keyword (up to 8 characters): ";
    getline(cin, keyword);
  } while (keyword.length() > 8);

  // Encrypt the message
  string encryptedMessage = vigenereEncrypt(message, keyword);
  cout << "Encrypted message: " << encryptedMessage << endl;
}

// Function to perform Vigenère decryption
void decryptMessage() {
  // Example usage
  string encryptedMessage;
  string keyword;
  cin.ignore();
  do {
    cout << "Enter the message (up to 80 characters): ";
    getline(cin, encryptedMessage);
  } while (encryptedMessage.length() > 80);

  do {
    cout << "Enter the keyword (up to 8 characters): ";
    getline(cin, keyword);
  } while (keyword.length() > 8);


  string decryptedMessage;
  int keywordLength = keyword.length();

  for (size_t i = 0; i < encryptedMessage.length(); ++i) {
    char c = encryptedMessage[i];
    if (isalpha(c))
    {
      char keywordChar = keyword[i % keywordLength];
      int shift = toupper(keywordChar) - 'A';
      char decryptedChar = (toupper(c) - 'A' - shift + 26) % 26 + 'A';
      decryptedMessage += decryptedChar;
    }
    else
    {
      decryptedMessage += c;
    }
  }

  cout << "Decrypted message: " << decryptedMessage << endl;
}
//end Hassan


// Esraa
map<int, int> cipher;
string text;

void cipher_atbash() {
  cout << "Please enter a text to cipher : \n";
  cin.ignore();
  getline(cin, text);
  //Removing non-alphabetic characters and numbers
  text.erase(remove_if(text.begin(), text.end(), [](char& C) {return not (isalpha(C)); }), text.end());

  //Removing spaces
  text.erase(remove_if(text.begin(), text.end(), [](char& C) {return (C == ' '); }), text.end());

  //Transforming to uppercase
  transform(text.begin(), text.end(), text.begin(), ::toupper);

  //Partitioning number
  cout << "Enter a partitioning number : \n";
  int X;
  cin >> X;
  // 0 1 2 3 4 5 ... 24 25
  int step = 26 / X, rem = 26 % X, range{ step }, cnt{};
  for (int i{}; i < X && range <= 26; i++)
  {
    for (int j = 0; cnt < range; cnt++, j++)
      cipher[cnt] = range - j - 1;
    range += step;
  }
  //Remaining block
  for (int j = 0; cnt < 26; cnt++, j++)
    cipher[cnt] = 26 - j - 1;
  //ABCDEFGHIJKLMNOPQRSTUVWXYZ
  for (char& C : text)
    C = char(cipher[C - 65] + 65);
  cout << "Ciphered text: "<<text;
}

void decipher_atbash() {
  map<int, int> decipher;
  cout << "Please enter a text to decipher : ";
  cin.ignore();
  getline(cin, text);
  for (auto& it : cipher)
    decipher[it.second] = it.first;

  for (char& C : text)
    C = char(decipher[C - 65] + 65);

  cout << "Deciphered text: " << text;
}


// Display menu
void displayMenu() {
  cout << "Choose a cipher:\n";
  cout << "1. Cipher Vignere\n";
  cout << "2. Atbash Cipher\n";
  cout << "3. XOR Cipher\n";
  cout << "Enter your choice: ";
}

// end esraa


// yomn
string xorrCipher(const string& message, const string& key) {
  string encryptedMessage;
  for (size_t i = 0; i < message.length(); ++i) {
    encryptedMessage += message[i] ^ key[i % key.length()];
  }
  return encryptedMessage;
}

void encryptDecrypt() {
  string key, message;
  cin.ignore();
  // Input key and message
  cout << "Enter the secret key: ";
  getline(cin, key);
  cout << "Enter the message: ";
  getline(cin, message);

  // Encrypt the message
  string encryptedMessage = xorrCipher(message, key);

  // Output the encrypted message
  cout << "Cipher text: ";
  for (size_t i = 0; i < encryptedMessage.length(); ++i) {
    cout << encryptedMessage[i];
  }
  cout << endl;

  // Output the encrypted message in hexadecimal
  cout << "Hexa: ";
  for (size_t i = 0; i < encryptedMessage.length(); ++i) {
    cout << hex << uppercase << setw(2) << setfill('0') << (int)(unsigned char)encryptedMessage[i] << " ";
  }
  cout << endl;
}

string xorCipher(const string& message, const string& key) {
  string decryptedMessage;
  for (size_t i = 0; i < message.length(); ++i) {
    decryptedMessage += message[i] ^ key[i % key.length()];
  }
  return decryptedMessage;
}

void decrypt() {
  string key, cipherHexa;
  cin.ignore();
  // Input key and cipher text in hexadecimal
  cout << "Enter the secret key: ";
  getline(cin, key);
  cout << "Enter the cipher text in hexadecimal (space-separated): ";
  getline(cin, cipherHexa);

  // Convert hexadecimal string to cipher text
  istringstream iss(cipherHexa);
  ostringstream oss;
  int hexValue;
  while (iss >> hex >> hexValue) {
    oss << static_cast<char>(hexValue);
  }
  string cipherText = oss.str();

  // Decrypt the cipher text
  string decryptedMessage = xorCipher(cipherText, key);

  // Output the decrypted message
  cout << "Decrypted message: " << decryptedMessage << endl;
}

// end yomn

int main() {
  int choice1, choice2, choice3;
  string encryptedText, key;
  while (true) {
    //welcome message and menu to choice
    cout << "Welcome , What do you like to do today?\n" << "1- Cipher a message \n" << "2 - Decipher a message\n" << "3 - End\n";
    cin >> choice1;

    if (choice1 == 1) {
      displayMenu();
      cin >> choice2;
      if (choice2 == 1)
      {
        encryptMessage();
      }
      else if (choice2 == 2) {
        cipher_atbash();
        cout << endl;
      }
      else if (choice2 == 3)
      {
        encryptDecrypt();
      }
    }
    if (choice1 == 2) {
      displayMenu();
      cin >> choice3;
      if (choice3 == 1) {
        decryptMessage();
      }
      if (choice3 == 2) {
        decipher_atbash();
        cout << endl;
      }
      if (choice3 == 3) {
        decrypt();
      }
    }
    if (choice1 == 3) {
      cout << "Thanks for using my program.";
      break;
      {
      }
      return 0;
    }
  }
}