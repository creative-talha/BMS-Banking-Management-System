Banking Management System (C Language)
Overview
The Banking Management System is a console-based application developed in C, designed to simulate real-world banking operations. The system supports two roles—Banker and User—each with clearly separated responsibilities and access controls. All records are stored persistently using binary files, ensuring data integrity across executions.
This project emphasizes file handling, structures, modular programming, and secure flow control without recursion.

Features
User Module


Secure user login


View account balance


Transfer funds


View transaction history


View personal account information


Update personal details (name, ID, password)


Logout and exit options


Banker Module


Banker login


Create new user accounts


View user accounts


Update user account details


Freeze or activate accounts


Logout and exit options



System Design
Role-Based Entry
At program start, the system asks the user to choose:


Banker


User


Exit


Each role is routed to its own login and menu system.
Data Storage
All data is stored using binary files:


user.bin – stores user account records


transaction.bin – stores transaction history


temp.bin – used for safe updates during file modification


Core Structures


struct user – stores account details


struct transaction – stores transaction metadata


Global user_info structure holds the currently logged-in user



File Structure
.
├── main.c
├── common-structs-header.h
├── user-header.h
├── banker_header.h
├── user-login.c
├── user-menu.c
├── user-main.c
├── check-account-balance.c
├── make-transaction.c
├── user-veiw-transaction.c
├── user-veiw_account.c
├── user-update-info.c
├── trx-id.c
├── time.c
├── clean.c
├── banker files...
├── user.bin
├── transaction.bin
└── README.md


Compilation
Use GCC to compile all source files:
gcc check-account-balance.c clean.c make-transaction.c user-login.c time.c \
user-veiw_account.c trx-id.c user-main.c user-menu.c user-veiw-transaction.c \
user-update-info.c main.c -o bank_system

Run the program:
./bank_system


Input Validation & Safety


All menu inputs are validated


Invalid numeric or character inputs are handled safely


File updates use temporary files to prevent data corruption


Logout uses controlled program flow (no recursion)



Key Concepts Used


Structures and nested structures


Binary file handling (fread, fwrite)


Modular programming


Input validation


Role-based access control


Persistent storage


Secure program flow



Limitations


Console-based interface


No encryption for stored passwords


Single-user session at a time



Future Improvements


Password hashing


Admin privilege levels


Search and filter options


GUI or web interface


Multi-user concurrency



Author
Talha Burhan
Computer Science Student
Project: Banking Management System (C)

If you want, I can now:


Convert this into a PDF or DOC


Shorten it for university submission


Add screenshots section


Add algorithm / flowchart description


Just tell me.
