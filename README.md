🏦 Banking Management System (C)

Welcome to my Banking Management System project — a console-based application written in C that simulates real-world banking operations using file handling, structures, and role-based access control.

This project reflects my journey of strengthening core C fundamentals and understanding how real systems manage data persistently.

💻 About the Project

This system allows two types of users:

👤 Bank Users

🏦 Bankers (Admin)

Each role has its own permissions, workflows, and menu system — similar to how actual banking software operates.

🚀 Features
👤 User Features

Secure login system

Check account balance

Transfer money to another account

View transaction history

View personal account information

Update personal details (name, ID, password)

Logout or exit safely

🏦 Banker Features

Banker authentication

View user accounts

Update user information

Freeze or activate accounts

Safe file-based record updates

🗂️ File Structure
.
├── main.c
├── user-main.c
├── user-login.c
├── user-menu.c
├── check-account-balance.c
├── make-transaction.c
├── user-view-transaction.c
├── user-view-account.c
├── user-update-info.c
├── trx-id.c
├── time.c
├── clean.c
├── common-structs-header.h
├── user.bin
├── transaction.bin
└── temp.bin

💾 Data Storage
File Name	Purpose
user.bin	Stores user account records
transaction.bin	Stores transaction history
temp.bin	Used for safe updates (commit/rollback)

All records are stored using binary files for efficiency and persistence.

🧠 Concepts Used

C Structures

Binary File Handling (fread, fwrite)

Modular Programming

Role-based Access Control

Global State Management

Input Validation

Transaction Commit & Rollback Logic

Time & Date Handling

⚙️ Compilation & Execution
Compile
gcc check-account-balance.c clean.c make-transaction.c user-login.c time.c \
user-view-account.c trx-id.c user-main.c user-menu.c \
user-view-transaction.c user-update-info.c main.c -o bank_system

Run
./bank_system

🔄 Program Flow

Program starts

User selects User or Banker

Login validation

Role-specific menu appears

Operations performed

Data stored safely in files

User logs out or exits

⚠️ Limitations

Console-based interface

Passwords stored as plain text

Designed for single-user execution

Educational purpose only

🎯 Learning Goals Behind This Project

Strengthen C fundamentals

Understand real-world file-based systems

Practice safe data updates

Improve logical problem-solving

Prepare for advanced system-level programming

👤 Author

Talha Burhan
Computer Science Student
GitHub: https://github.com/creative-talha

⭐ Final Note

This project is part of my learning journey in C programming.
Feedback, suggestions, and improvements are always welcome!

If you found this project useful or interesting, feel free to ⭐ star the repository.
