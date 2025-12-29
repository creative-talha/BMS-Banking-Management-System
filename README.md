Banking Management System (C)

A console-based Banking Management System written in C, implementing real-world banking logic using binary file handling, modular design, and role-based access control.

This project supports User and Banker roles with separate workflows and persistent data storage.

📌 Key Features
👤 User Module

Secure login

Check account balance

Transfer money to another account

View transaction history

View account information

Update personal details (name, ID, password)

Logout / Exit safely

🏦 Banker Module

Banker authentication

Create new user accounts

View user details

Update user information

Freeze / activate user accounts

Safe file-based updates

🗂️ Project Structure
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
File	Description
user.bin	Stores all user account records
transaction.bin	Stores transaction history
temp.bin	Temporary file for safe updates

All data is stored in binary format for efficiency and persistence.

🧩 Core Data Structures

struct user – stores account details

struct transaction – stores transaction records

user_info – global structure holding the logged-in user's data

⚙️ Compilation & Execution
Compile the project
gcc check-account-balance.c clean.c make-transaction.c user-login.c time.c \
user-view-account.c trx-id.c user-main.c user-menu.c \
user-view-transaction.c user-update-info.c main.c -o bank_system

Run
./bank_system

🔄 Program Flow

Program starts

User selects User or Banker

Authentication is performed

Role-specific menu is displayed

Operations are executed

Data is written to binary files

User returns to menu or exits

✅ Validation & Safety Measures

Menu input validation

Frozen accounts cannot perform transactions

Sender ≠ receiver validation

Insufficient balance protection

Safe file updates using temporary files

Controlled exit and logout handling

🛠️ Concepts Used

C Structures

Binary File Handling (fread, fwrite)

Modular Programming

Role-Based Access Control

Persistent Storage

Input Validation

File Commit / Rollback Logic

⚠️ Known Limitations

Console-based interface

Passwords stored in plain text

Single-session execution model

👤 Author

Talha Burhan
Computer Science Student
Project: Banking Management System in C

📄 License

This project is intended for educational and learning purposes only.
