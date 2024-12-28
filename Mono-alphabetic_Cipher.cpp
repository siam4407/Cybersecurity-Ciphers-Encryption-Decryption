#include<bits/stdc++.h>
using namespace std;

const string ENCRYPTION_KEY = "MNBVCXZQWERTYUIOPASDFGHJKL";

char encryptCharacter(char originalCharacter) {
    if (originalCharacter >= 'a' && originalCharacter <= 'z') {
        return ENCRYPTION_KEY[originalCharacter - 'a'];
    } else if (originalCharacter >= 'A' && originalCharacter <= 'Z') {
        return ENCRYPTION_KEY[originalCharacter - 'A'];
    } else {
        return originalCharacter;
    }
}

int main() {
    string plaintextM;

    cout << "Enter the plaintext message: ";
    getline(cin, plaintextM);

    string encryptedM;

    for (char character : plaintextM) {
        encryptedM += encryptCharacter(character);
    }

    cout << "\nThe Encrypted message is: " << encryptedM << endl;

    return 0;
}
