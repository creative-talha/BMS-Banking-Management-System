
# 🏦 Banking Management System (C Programming)

A **console-based Banking Management System** built in **C**, simulating real-world banking operations.  
The project uses **binary files**, **structures**, and **modular programming** to manage both **Banker** and **User** roles securely.

---

## 📌 Overview

This system allows:

- **Bankers** to manage customer accounts  
- **Users** to securely access their accounts  
- Persistent storage using **binary files**  
- Clean, **menu-driven terminal UI**

The project emphasizes **data consistency**, **safe transaction logic**, and **role-based access**.

---

## 👥 User Roles

### 🔐 Banker

- Create new accounts  
- View account details  
- Update user information  
- Freeze / activate accounts  
- Monitor system-level operations  

### 👤 User

- Secure login  
- Check account balance  
- Transfer money  
- View transaction history  
- View / update personal info  
- Logout safely  

---

## ⚙️ Core Features

- **Secure login system** (Banker & User)  
- **Binary file storage** (`user.bin`, `transaction.bin`)  
- **Transaction history** with timestamps  
- **Account freeze / activation**  
- Input validation and error handling  
- Box-style, readable console UI  
- Modular and well-commented code  

---

## 🗂️ Project Structure

*****BMS-Banking-Management-System/*****
-|
-├── **Main/**
-│ ├── main.c
-│
-├── **banker/**
-│ ├── banker_login.c
-│ ├── banker_menu.c
-│ ├── create_account.c
-│ ├── view_account.c
-│ ├── update_user_account.c
-│ ├── freeze_activate_account.c
-│ └── banker_header.h
-│
-├── **user/**
-│ ├── user_login.c
-│ ├── user_menu.c
-│ ├── check_balance.c
-│ ├── transfer.c
-│ ├── view_transaction.c
-│ ├── user_view_account.c
-│ ├── update_account.c
-│ └── user_header.h
-│
-├── **common/**
-│ ├── common-structs-header.h
-│ ├── clean.c
-│ ├── trx-id.c
-│ └── time.c
-|
-├── **files/**
-├── user.bin
-├── transaction.bin


---

## 💻 Compilation & Running

### **Linux / macOS**
```bash
# Compile all files together
gcc main.c banker-login.c banker-menu.c create-account.c view-account.c update-user-account.c freeze-activate-account.c user-login.c user-menu.c check-account-balance.c make-transaction.c user-view-account.c user-view-transaction.c user-update-info.c trx-id.c time.c clean.c banker-deposit.c banker-withdrawal.c banker-veiw-transaction.c -o BMS

# Run the program
./BMS
```
### **Windows**
```cmd
:: Compile all files together
gcc main.c banker-login.c banker-menu.c create-account.c view-account.c update-user-account.c freeze-activate-account.c user-login.c user-menu.c check-account-balance.c make-transaction.c user-view-account.c user-view-transaction.c user-update-info.c trx-id.c time.c clean.c banker-deposit.c banker-withdrawal.c banker-veiw-transaction.c -o BMS.exe

:: Run the program
BMS.exe
```

