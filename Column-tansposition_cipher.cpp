#include<bits/stdc++.h>
using namespace std;

string encryptMessage(const string& encryptionKey, const string& plaintextM) {
    vector<vector<char>> charMatrix(encryptionKey.size());

    int insertionIndex = 0;
    for (char character : plaintextM) {
        if (character != ' ') {
            int position = insertionIndex % encryptionKey.size();
            charMatrix[position].push_back(character);
            insertionIndex++;
        }
    }


    string sortedKey = encryptionKey;
    sort(sortedKey.begin(), sortedKey.end());

    string encryptedText = "";
    for (char character : sortedKey) {
        int position = encryptionKey.find(character);
        for (char plaintextCharacter : charMatrix[position]) {
            encryptedText += plaintextCharacter;
        }

      //  if (charMatrix[position].size() < charMatrix[0].size()) {
         //   encryptedText += 'x';

    }

    return encryptedText;
}


int main() {

    string encryptionKey, plaintextM;

    cout << "Enter the encryption key: ";
    cin >> encryptionKey;
    cin.ignore();

    cout << "Enter the plaintext message: ";
    getline(cin, plaintextM);

    string encryptedText = encryptMessage(encryptionKey, plaintextM);
    cout << "\nThe Encrypted ciphertext is: " << encryptedText << endl;

    return 0;
}

