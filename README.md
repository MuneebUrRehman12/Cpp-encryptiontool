C++ Encryption Tool
A simple encryption application demonstrating Object-Oriented Programming concepts in C++.

Features
Caesar Cipher (adjustable shift)
Reverse Cipher
ROT13 Cipher
Encrypt & Decrypt messages
Operation history tracking
Input validation
Quick Start
Compile
Bash

g++ -std=c++11 main.cpp -o encryption
Run
Bash

./encryption
How to Use
Select a cipher from the menu (1-3)
Enter your message
Choose encrypt or decrypt
Provide cipher parameters (shift value for Caesar)
View the result
Check history or exit
Example
text

Message: HELLO
Cipher: Caesar (shift 3)
Result: KHOOR
OOP Concepts
Classes: Message, Cipher, CaesarCipher, ReverseCipher, ROT13Cipher
Inheritance: All ciphers inherit from base Cipher class
Polymorphism: Virtual encrypt() and decrypt() methods
Encapsulation: Private data with public methods
Abstraction: Simple interface for complex algorithms
Project Structure
text

main.cpp          # Complete program
README.md         # This file
Requirements
C++ compiler (g++, clang, MSVC)
C++11 or higher
Team
Member 1: Cipher implementation
Member 2: UI & history management
Status
✅ Complete and working

License
Educational project

