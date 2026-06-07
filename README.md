🔐 C++ Encryption Tool
A command-line encryption application built with Object-Oriented Programming principles. Encrypt and decrypt messages using multiple classical cipher algorithms with an intuitive menu interface.

✨ Features
Multiple Cipher Algorithms

Caesar Cipher (adjustable shift)
Reverse Cipher
ROT13 Cipher
Core Functionality

Encrypt messages
Decrypt messages
View operation history (last 10 operations)
Input validation
User-friendly menu system
OOP Implementation

Clean class hierarchy
Inheritance and polymorphism
Encapsulation and abstraction
Virtual functions
🚀 Quick Start
Prerequisites
C++ compiler (g++, clang, or MSVC)
C++11 or higher
Compilation
Bash

g++ -std=c++11 main.cpp -o encryption
Running
Bash

./encryption
📖 How to Use
Start the program - You'll see the main menu
Choose a cipher - Select 1 (Caesar), 2 (Reverse), or 3 (ROT13)
Enter your message - Type the text you want to encrypt/decrypt
Select operation - Choose to encrypt or decrypt
Provide parameters - Enter shift value if using Caesar cipher
View result - Your encrypted/decrypted message appears
Check history - View all your previous operations
Exit - Choose 5 to exit the program
💡 Example
text

Enter your message: HELLO
Choose shift: 3

Result: KHOOR
🏗️ Project Structure
text

encryption-tool/
├── main.cpp              # Main program file
├── README.md            # This file
└── docs/
    └── REPORT.md        # Detailed project report
🧩 OOP Concepts Implemented
Concept	Implementation
Classes	Message, Cipher, CaesarCipher, ReverseCipher, ROT13Cipher
Inheritance	All ciphers inherit from base Cipher class
Polymorphism	Virtual encrypt() and decrypt() methods
Encapsulation	Private data with public methods
Abstraction	Users interact through simple menu
Constructors	Custom initialization for each cipher
📚 Class Diagram
text

Cipher (Base Class)
│
├── CaesarCipher
├── ReverseCipher
└── ROT13Cipher

Message (Data Container)
🔍 Cipher Algorithms
Caesar Cipher
Shifts each letter by a fixed number of positions.

Example: "HELLO" with shift 3 → "KHOOR"
Time Complexity: O(n)
Parameters: Shift value (1-25)
Reverse Cipher
Reverses the entire message.

Example: "HELLO" → "OLLEH"
Time Complexity: O(n)
Note: Encryption = Decryption
ROT13 Cipher
Special case of Caesar cipher with fixed shift of 13.

Example: "HELLO" → "URYYB"
Time Complexity: O(n)
Property: Self-inverse cipher
🧪 Testing
The program has been tested with:

✅ Various message lengths
✅ Special characters and spaces
✅ Mixed case text
✅ Empty input handling
✅ Invalid menu choices
✅ History tracking
✅ Encrypt/decrypt roundtrips
📊 Program Output Example
text

=============================
 Cipher    : Caesar Cipher
 Operation : ENCRYPT
 Original  : HELLO WORLD
 Result    : KHOOR ZRUOG
=============================
🎯 Future Enhancements
 Add more cipher algorithms (Vigenère, Atbash)
 File encryption/decryption support
 Save/load history to file
 Unlimited history (use vector instead of array)
 GUI interface using Qt
 Brute force decryption tool
 Frequency analysis
📝 Code Example
C++

// Create a Caesar cipher with shift 3
CaesarCipher cipher(3);

// Encrypt a message
string encrypted = cipher.encrypt("HELLO");
// Result: "KHOOR"

// Decrypt a message
string decrypted = cipher.decrypt("KHOOR");
// Result: "HELLO"
🤝 Team Members
Member 1 - Cipher implementations and algorithm design
Member 2 - User interface and history management
📄 License
This project is created for educational purposes as part of an OOP Lab final project.

🎓 Course Information
Course: Object-Oriented Programming Lab
Project Type: Final Project
Team Size: 2 people
Language: C++11
📞 Support
For questions or issues, please contact the team members or refer to the detailed project report in the docs folder.

✅ Project Status
Status: Complete and Functional
Last Updated: [Date]
Lines of Code: ~300
Classes: 5
OOP Concepts: 6+
