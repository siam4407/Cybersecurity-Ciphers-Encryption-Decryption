#include<bits/stdc++.h>
using namespace std;

const char* KEYS[3] = {
    "QWERTYUIOPASDFGHJKLZXCVBNM",
    "tyuiopasdfghklzxcvbnmqwer",
    "POIUYTREWQLKJHGASDFzxcvbnm"
};

char encryptCharacter(char originalCh, const char* encryptionKey) {
    int index = (originalCh) - 'a';
    char encryptedCh = encryptionKey[index];
    return encryptedCh;
}

int main() {
    string plaintextM;

    cout << "Enter the plaintext message: ";
    getline(cin, plaintextM);

    int portionSize = plaintextM.length() / 3;
    string portion1, portion2, portion3;

    for (int i = 0; i < plaintextM.length(); i++) {
        if (i < portionSize) {
            portion1 += plaintextM[i];
        }
         else if (i < 2 * portionSize) {
            portion2 += plaintextM[i];
        }
         else {
            portion3 += plaintextM[i];
        }
    }

    string encryptedText;

    for (int i = 0; i < portion1.length(); i++) {
        encryptedText += encryptCharacter(portion1[i], KEYS[0]);
    }

    for (int i = 0; i < portion2.length(); i++) {
        encryptedText += encryptCharacter(portion2[i], KEYS[1]);
    }

    for (int i = 0; i < portion3.length(); i++) {
        encryptedText += encryptCharacter(portion3[i], KEYS[2]);
    }

    cout << "\nThe Encrypted ciphertext is: " << encryptedText << endl;

    return 0;
}
