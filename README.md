# Hospital Patient Queue Management

A simple **C-based Data Structures project** that manages hospital patients using a **Priority Queue implemented with a Linked List**.

##  Project Overview

Patients are treated based on the severity of their medical condition:

| Priority | Condition | Order  |
| -------- | --------- | ------ |
| 1        | Critical  | First  |
| 2        | Serious   | Second |
| 3        | Normal    | Third  |

The system maintains a waiting queue and a separate list of treated patients.

##  Features

* Register new patients
* Automatically generate Patient ID
* Display waiting patients
* Treat the highest-priority patient
* Maintain treated patient history
* Search patients by ID or name
* Dynamic memory allocation
* Menu-driven interface
* Properly free allocated memory

##  Concepts Used

* Priority Queue
* Linked List
* Structures
* Pointers
* Dynamic Memory Allocation
* `malloc()` and `free()`
* Searching
* Queue Operations
* Menu-driven Programming

##  Project Structure

```text
Hospital-Patient-Queue-Management/
│
├── hospital_queue.c
├── README.md
└── .gitignore
```

##  How to Run

### Compile

```bash
gcc hospital_queue.c -o hospital_queue
```

### Run on Windows

```powershell
.\hospital_queue.exe
```

### Run on Linux/macOS

```bash
./hospital_queue
```

##  Main Menu

```text
========================================
   HOSPITAL PATIENT QUEUE MANAGEMENT
========================================
1. Register New Patient
2. Display Waiting Queue
3. Treat Next Patient
4. Display Treated Patients
5. Search Patient
6. Exit
========================================
```

##  How It Works

Example patients:

```text
101 - Anu - Critical
102 - Rahul - Normal
103 - Meera - Serious
```

Waiting queue:

```text
Anu → Meera → Rahul
```

Patients are treated in the order:

```text
Critical → Serious → Normal
```

##  Future Enhancements

* File handling
* Save and load patient records
* Doctor assignment
* Ward allocation
* Waiting-time calculation
* Treatment statistics

##  Author

**Aswin Arun**

##  License

This project is created for **educational purposes**.
