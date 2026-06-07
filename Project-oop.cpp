#include <iostream>
#include <string>
using namespace std;

class Message {
public:
    string original;
    string result;
    string cipherUsed;
    string operation;

    void display() {
        cout << "\n=============================" << endl;
        cout << " Cipher    : " << cipherUsed    << endl;
        cout << " Operation : " << operation     << endl;
        cout << " Original  : " << original      << endl;
        cout << " Result    : " << result        << endl;
        cout << "=============================" << endl;
    }
};

class Cipher {
public:
    string name;

    virtual string encrypt(string text) {
        return text;
    }

    virtual string decrypt(string text) {
        return text;
    }
};

class CaesarCipher : public Cipher {
public:
    int shift;

    CaesarCipher(int s) {
        name  = "Caesar Cipher";
        shift = ((s % 26) + 26) % 26;
    }

    string encrypt(string text) {
        string result = "";
        for (int i = 0; i < (int)text.length(); i++) {
            char c = text[i];
            if (c >= 'a' && c <= 'z')
                result += (char)(((c - 'a' + shift) % 26) + 'a');
            else if (c >= 'A' && c <= 'Z')
                result += (char)(((c - 'A' + shift) % 26) + 'A');
            else
                result += c;
        }
        return result;
    }

    string decrypt(string text) {
        string result = "";
        for (int i = 0; i < (int)text.length(); i++) {
            char c = text[i];
            if (c >= 'a' && c <= 'z')
                result += (char)(((c - 'a' - shift + 26) % 26) + 'a');
            else if (c >= 'A' && c <= 'Z')
                result += (char)(((c - 'A' - shift + 26) % 26) + 'A');
            else
                result += c;
        }
        return result;
    }
};

class ReverseCipher : public Cipher {
public:
    ReverseCipher() {
        name = "Reverse Cipher";
    }

    string encrypt(string text) {
        string result = "";
        for (int i = (int)text.length() - 1; i >= 0; i--)
            result += text[i];
        return result;
    }

    string decrypt(string text) {
        return encrypt(text);
    }
};

class ROT13Cipher : public Cipher {
public:
    ROT13Cipher() {
        name = "ROT13 Cipher";
    }

    string encrypt(string text) {
        string result = "";
        for (int i = 0; i < (int)text.length(); i++) {
            char c = text[i];
            if (c >= 'a' && c <= 'z')
                result += (char)(((c - 'a' + 13) % 26) + 'a');
            else if (c >= 'A' && c <= 'Z')
                result += (char)(((c - 'A' + 13) % 26) + 'A');
            else
                result += c;
        }
        return result;
    }

    string decrypt(string text) {
        return encrypt(text);
    }
};

void showHistory(string history[], int historyCount) {
    cout << "\n===== Conversion History =====" << endl;
    if (historyCount == 0) {
        cout << "  No history yet." << endl;
    } else {
        for (int i = 0; i < historyCount; i++) {
            cout << "  " << i + 1
                 << ". " << history[i] << endl;
        }
    }
    cout << "==============================" << endl;
}

int getOperationChoice() {
    int op;
    cout << "\n  -------------------------" << endl;
    cout << "  1. Encrypt"                 << endl;
    cout << "  2. Decrypt"                 << endl;
    cout << "  -------------------------"  << endl;
    cout << "  Choose: ";
    cin  >> op;
    cin.ignore();

    if (op != 1 && op != 2) {
        cout << "  Invalid! Defaulting to Encrypt." << endl;
        op = 1;
    }
    return op;
}

int main() {

    string history[10];
    int    historyCount = 0;
    int    choice;

    cout << "=============================" << endl;
    cout << "    C++ Encryption Tool      " << endl;
    cout << "=============================" << endl;

    do {
        cout << "\n  -------- MAIN MENU --------" << endl;
        cout << "  1. Caesar Cipher"              << endl;
        cout << "  2. Reverse Cipher"             << endl;
        cout << "  3. ROT13 Cipher"               << endl;
        cout << "  4. View History"               << endl;
        cout << "  5. Exit"                       << endl;
        cout << "  ---------------------------"   << endl;
        cout << "  Choose: ";
        cin  >> choice;
        cin.ignore();

        if (choice == 4) {
            showHistory(history, historyCount);
            continue;
        }

        if (choice == 5) {
            cout << "\n  Goodbye! Thank you for using" << endl;
            cout << "  C++ Encryption Tool."          << endl;
            cout << "=============================" << endl;
            break;
        }

        if (choice < 1 || choice > 3) {
            cout << "\n  [!] Invalid choice! Try again." << endl;
            continue;
        }

        string text;
        cout << "\n  Enter your message: ";
        getline(cin, text);

        if (text.empty()) {
            cout << "  [!] Message cannot be empty!" << endl;
            continue;
        }

        Message msg;
        msg.original = text;

        if (choice == 1) {
            int op = getOperationChoice();

            int shift;
            cout << "  Enter shift number: ";
            cin  >> shift;
            cin.ignore();

            CaesarCipher c(shift);
            msg.cipherUsed = c.name;

            if (op == 1) {
                msg.result    = c.encrypt(text);
                msg.operation = "ENCRYPT";
            } else {
                msg.result    = c.decrypt(text);
                msg.operation = "DECRYPT";
            }
        }

        else if (choice == 2) {
            int op = getOperationChoice();

            ReverseCipher r;
            msg.cipherUsed = r.name;

            if (op == 1) {
                msg.result    = r.encrypt(text);
                msg.operation = "ENCRYPT";
            } else {
                msg.result    = r.decrypt(text);
                msg.operation = "DECRYPT";
            }
        }

        else if (choice == 3) {
            int op = getOperationChoice();

            ROT13Cipher rot;
            msg.cipherUsed = rot.name;

            if (op == 1) {
                msg.result    = rot.encrypt(text);
                msg.operation = "ENCRYPT";
            } else {
                msg.result    = rot.decrypt(text);
                msg.operation = "DECRYPT";
            }
        }

        msg.display();

        if (historyCount < 10) {
            history[historyCount] = "[" + msg.operation + "] " +
                                     msg.cipherUsed     +
                                     " | "              +
                                     msg.original       +
                                     " -> "             +
                                     msg.result;
            historyCount++;
        } else {
            for (int i = 0; i < 9; i++)
                history[i] = history[i + 1];
            history[9] = "[" + msg.operation + "] " +
                          msg.cipherUsed     +
                          " | "              +
                          msg.original       +
                          " -> "             +
                          msg.result;
        }

        cout << "\n  ---------------------------"  << endl;
        cout << "  1. Go Again"                   << endl;
        cout << "  2. View History"               << endl;
        cout << "  3. Exit"                       << endl;
        cout << "  ---------------------------"   << endl;
        cout << "  Choose: ";
        cin  >> choice;
        cin.ignore();

        if (choice == 2) {
            showHistory(history, historyCount);
            choice = 1;
        } else if (choice == 3) {
            cout << "\n  Goodbye! Thank you for using" << endl;
            cout << "  C++ Encryption Tool."          << endl;
            cout << "=============================" << endl;
            break;
        }

    } while (choice != 5);

    return 0;
}