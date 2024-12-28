#include<bits/stdc++.h>
using namespace std;

vector<int> stringToNumeric(const string& input);
string numericToString(const vector<int>& numericValues);
int modPow(int base, int exponent, int modulus);

int main() {

    cout << "Enter prime number p: ";
    string p_str;
    getline(cin, p_str);
    int p = stoi(p_str);

    cout << "Enter prime number q: ";
    string q_str;
    getline(cin, q_str);
    int q = stoi(q_str);

    int n = p * q;
    int phiN = (p - 1) * (q - 1);
    int e;

    do {
        cout << "Enter public exponent e: ";
        string e_str;
        getline(cin, e_str);
        e = stoi(e_str);
    } while (__gcd(e, phiN) != 1);

    int d = 1;
    while ((d * e) % phiN != 1) {
        d++;
    }

    cout << "Public Key (PU): {" << e << ", " << n << "}" << endl;
    cout << "Private Key (PR): {" << d << ", " << n << "}" << endl;

    cout << "Text: ";
    string inputText;
    getline(cin, inputText);

    vector<int> numericMessage = stringToNumeric(inputText);
    vector<int> encryptedMessage;

    for (int i = 0; i < numericMessage.size(); i++) {
        int encryptedValue = modPow(numericMessage[i], e, n);
        encryptedMessage.push_back(encryptedValue);
    }

    cout << "Encrypted Message: ";
    for (int value : encryptedMessage) {
        cout << value << " ";
    }
    cout << endl;

    vector<int> decryptedMessage;

    for (int i = 0; i < encryptedMessage.size(); i++) {
        int decryptedValue = modPow(encryptedMessage[i], d, n);
        decryptedMessage.push_back(decryptedValue);
    }

    cout << "Decrypted Message: ";
    for (int value : decryptedMessage) {
        cout << value << " ";
    }
    cout << endl;

    cout << "Decrypted Text: " << numericToString(decryptedMessage) << endl;

    return 0;
}


vector<int> stringToNumeric(const string& input) {
    vector<int> numericValues;
    for (char c : input) {
        numericValues.push_back(static_cast<int>(c));
    }
    return numericValues;
}

string numericToString(const vector<int>& numericValues) {
    stringstream result;
    for (int value : numericValues) {
        result << static_cast<char>(value);
    }
    return result.str();
}

int modPow(int base, int exponent, int modulus) {
    int result = 1;
    base = base % modulus;

    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % modulus;
        }

        exponent = exponent >> 1;
        base = (base * base) % modulus;
    }

    return result;
}
