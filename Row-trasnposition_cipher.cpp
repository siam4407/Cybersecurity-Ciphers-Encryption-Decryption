#include<bits/stdc++.h>
using namespace std;


string encrypt(const string& key, const string& plaintext) {

    int numRows = (double)plaintext.length() / key.length();
    vector<string> matrix(numRows, string(key.length(), ' '));


    int rowIdx = 0, colIdx = 0;
    for (char ch : plaintext) {
        if (!isalnum(ch)) {
            continue;
        }
        matrix[rowIdx][colIdx] = ch;
        colIdx++;
        if (colIdx == key.length()) {
            colIdx = 0;
            rowIdx++;
        }
    }
    if (colIdx != 0) {
        while (colIdx < key.length()) {
            matrix[rowIdx][colIdx] = 'x';
            colIdx++;
        }
    }

    vector<pair<int, int>> sortedKey;
    for (int i = 0; i < key.length(); ++i) {
        sortedKey.push_back(make_pair(i, key[i] - '0'));
    }
    sort(sortedKey.begin(), sortedKey.end());

    vector<string> rearrangedMatrix(numRows, string(key.length(), ' '));
    for (int i = 0; i < key.length(); ++i) {
        for (int j = 0; j < numRows; ++j) {
            rearrangedMatrix[j][i] = matrix[j][sortedKey[i].second - 1];
        }
    }


    string ciphertext;
    for (const string& row : rearrangedMatrix) {
        ciphertext += row;
    }

    return ciphertext;
}

int main() {
    string encryptionKey, plaintextM;


    cout << "Enter encryption key: ";
    cin >> encryptionKey;
    cin.ignore();


    cout << "Enter plaintext message: ";
    getline(cin, plaintextM);

    string ciphertext = encrypt(encryptionKey, plaintextM);
    cout << "\nThe Encrypted ciphertext is: " << ciphertext << endl;

    return 0;
}
