# Hospital Patient Queue Management

## Project Description

Hospital Patient Queue Management is a C-based Data Structures project that manages patients using a **Priority Queue implemented with a Linked List**.

Patients are treated according to the severity of their medical condition:

- **1 - Critical**: Highest priority
- **2 - Serious**: Medium priority
- **3 - Normal**: Lowest priority

The system allows hospital staff to register patients, display the waiting queue, treat patients, maintain treatment history, and search for patients.

---

## Objective

To design and implement a hospital patient management system using:

- Priority Queue
- Linked List
- Dynamic Memory Allocation
- Queue Operations
- Searching
- Menu-driven programming

---

## Features

### 1. Register New Patient

Allows staff to enter:

- Patient name
- Age
- Disease
- Medical priority

A unique Patient ID is automatically assigned.

### 2. Display Waiting Queue

Displays all patients waiting for treatment.

Patients are shown according to priority:

```text
Critical -> Serious -> Normal
```

### 3. Treat Next Patient

Removes the patient with the highest priority from the waiting queue and moves the patient record to the treated patient list.

### 4. Display Treated Patients

Displays all patients who have already been treated.

### 5. Search Patient

Patients can be searched using:

- Patient ID
- Patient Name

The search checks both:

- Waiting Queue
- Treated Patient List

### 6. Exit

Terminates the program and releases dynamically allocated memory.

---

## Data Structures Used

### Priority Queue

A linked list is used to implement the priority queue.

Each patient contains:

```c
struct Patient {
    int id;
    char name[50];
    int age;
    char disease[100];
    int priority;
    struct Patient *next;
};
```

### Treated Patient Linked List

Treated patients are stored in a separate linked list.

```c
struct TreatedPatient {
    int id;
    char name[50];
    int age;
    char disease[100];
    char status[20];
    struct TreatedPatient *next;
};
```

---

## Priority System

| Priority | Meaning  | Treatment Order |
|----------|----------|-----------------|
| 1        | Critical | First           |
| 2        | Serious  | Second          |
| 3        | Normal   | Third           |

For example:

```text
Patient A -> Normal
Patient B -> Critical
Patient C -> Serious
```

The waiting queue becomes:

```text
Patient B -> Patient C -> Patient A
```

because critical patients must be treated first.

---

## Main Functions

| Function | Description |
|----------|-------------|
| `registerPatient()` | Registers a new patient |
| `displayWaitingQueue()` | Displays patients waiting for treatment |
| `treatNextPatient()` | Treats the highest-priority patient |
| `displayTreatedPatients()` | Displays treatment history |
| `searchPatient()` | Searches for patients |
| `searchByID()` | Searches using patient ID |
| `searchByName()` | Searches using patient name |
| `getPriorityName()` | Converts priority number to text |
| `freeMemory()` | Releases dynamically allocated memory |
| `main()` | Controls the menu |

---

## Program Flow

```text
Start
  |
  v
Display Main Menu
  |
  +----> Register Patient
  |
  +----> Display Waiting Queue
  |
  +----> Treat Next Patient
  |
  +----> Display Treated Patients
  |
  +----> Search Patient
  |
  +----> Exit
```

---

## Sample Output

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
Enter your choice:
```

### Register Patient

```text
Enter patient name: Anu
Enter age: 45
Enter disease: Chest Pain
Enter priority (1=Critical, 2=Serious, 3=Normal): 1

Patient registered successfully!
Assigned ID: 101
```

### Waiting Queue

```text
ID       : 101
Name     : Anu
Age      : 45
Disease  : Chest Pain
Priority : 1 (Critical)
```

### Treat Patient

```text
TREATING NEXT PATIENT

ID       : 101
Name     : Anu
Priority : 1 (Critical)

Treatment complete!
Record moved to Treated List.
```

---

## Requirements

To run this project, you need:

- Windows / Linux / macOS
- GCC Compiler
- Visual Studio Code (recommended)

---

## How to Run

### 1. Open the project folder

```text
Hospital-Patient-Queue-Management
```

### 2. Open the terminal

In VS Code:

```text
Terminal -> New Terminal
```

### 3. Compile the program

```bash
gcc hospital_queue.c -o hospital_queue
```

### 4. Run the program

On Windows:

```powershell
.\hospital_queue.exe
```

On Linux/macOS:

```bash
./hospital_queue
```

---

## Example Queue

Suppose the following patients are registered:

```text
101 - Anu - Critical
102 - Rahul - Normal
103 - Meera - Serious
```

The priority queue becomes:

```text
[101 | Anu | Critical]
        |
        v
[103 | Meera | Serious]
        |
        v
[102 | Rahul | Normal]
        |
        v
NULL
```

After treating Anu:

```text
Waiting Queue:

[103 | Meera | Serious]
        |
        v
[102 | Rahul | Normal]
        |
        v
NULL
```

Treated List:

```text
[101 | Anu | Chest Pain | Treated]
        |
        v
NULL
```

---

## Concepts Demonstrated

This project demonstrates the following Data Structures concepts:

- Linked Lists
- Priority Queues
- Enqueue / Insertion
- Dequeue / Deletion
- Linked List Traversal
- Searching
- Dynamic Memory Allocation
- `malloc()`
- `free()`
- Structures
- Pointers
- Menu-driven programming

---

## Project Structure

```text
Hospital-Patient-Queue-Management/
|
|-- hospital_queue.c
|-- README.md
|-- .gitignore
```

---

## Future Enhancements

The project can be extended with:

- File handling
- Save and load patient records
- Critical patients-only display
- Queue sorting
- Doctor assignment
- Ward allocation
- Estimated treatment time
- Waiting-time calculation
- Daily treatment statistics

---

## Conclusion

The Hospital Patient Queue Management system demonstrates how a **Priority Queue and Linked List** can be used to manage patients efficiently.

Critical patients are treated first, followed by serious and normal patients, while treated patients are maintained in a separate history list.
