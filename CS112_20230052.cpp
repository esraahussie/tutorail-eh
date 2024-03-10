#include <iostream>
#include<algorithm>
#include<string>
#include<map>
using namespace std;
map<int, int>cipher;
string text;
int main()
{
    while (true) {
        //welcome message and menu to choice
        cout << "Welcome , What do you like to do today?\n" << "1- Cipher a message \n" << "2 - Decipher a message\n" << "3 - End\n";
        int choice;
        cin >> choice;
        if (choice == 1) {
            cout << "Please enter a text to cipher : \n";
            cin.ignore();
            getline(cin, text);
            //Removing No-char and numbers
            text.erase(remove_if(text.begin(), text.end(), [](char& C) {return not (isalpha(C)); }), text.end());

            //Removing spaces
            text.erase(remove_if(text.begin(), text.end(), [](char& C) {return (C == ' '); }), text.end());

            //Transforming to capital
            transform(text.begin(), text.end(), text.begin(), ::toupper);

            //Partitioning number
            cout << "Enter a partitioning number : \n";
            int X;
            cin >> X;
            map<int, int>cipher;
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
            cout << "Ciphered text: " << text << endl;
        }
        //---------------------------------
        if (choice == 2) {
            map<int, int>decipher;
            cout << "Please enter a text to decipher : ";
            cin.ignore();
            getline(cin, text);
            for (auto& it : cipher)
                decipher[it.second] = it.first;

            for (char& C : text)
                C = char(decipher[C - 65] + 65);

            cout << "Deciphered text: " << text << endl;
        }
        if (choice == 3) {
            cout << "Thanks for using my program.";
            break;
        }
    }
    return 0;
}
