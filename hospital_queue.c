#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_SIZE 50
#define DISEASE_SIZE 100

// ===============================
// WAITING PATIENT NODE
// ===============================
struct Patient {
    int id;
    char name[NAME_SIZE];
    int age;
    char disease[DISEASE_SIZE];
    int priority;
    struct Patient *next;
};

// ===============================
// TREATED PATIENT NODE
// ===============================
struct TreatedPatient {
    int id;
    char name[NAME_SIZE];
    int age;
    char disease[DISEASE_SIZE];
    char status[20];
    struct TreatedPatient *next;
};

// Head pointers
struct Patient *waitingQueue = NULL;
struct TreatedPatient *treatedList = NULL;

// Patient ID starts from 101
int nextID = 101;


// ===============================
// GET PRIORITY NAME
// ===============================
const char* getPriorityName(int priority)
{
    if (priority == 1)
        return "Critical";
    else if (priority == 2)
        return "Serious";
    else
        return "Normal";
}


// ===============================
// READ INTEGER SAFELY
// ===============================
int readInt(const char *message)
{
    char input[100];
    int value;

    while (1)
    {
        printf("%s", message);

        fgets(input, sizeof(input), stdin);

        if (sscanf(input, "%d", &value) == 1)
        {
            return value;
        }

        printf("Invalid input! Please enter a number.\n");
    }
}


// ===============================
// READ STRING SAFELY
// ===============================
void readString(const char *message, char *str, int size)
{
    printf("%s", message);

    fgets(str, size, stdin);

    // Remove newline
    str[strcspn(str, "\n")] = '\0';
}


// ===============================
// REGISTER PATIENT
// ===============================
void registerPatient()
{
    struct Patient *newPatient;
    struct Patient *temp;

    newPatient = (struct Patient*)malloc(sizeof(struct Patient));

    if (newPatient == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    // Assign ID
    newPatient->id = nextID++;

    // Get patient details
    readString("Enter patient name: ",
               newPatient->name,
               NAME_SIZE);

    newPatient->age = readInt("Enter age: ");

    readString("Enter disease: ",
               newPatient->disease,
               DISEASE_SIZE);

    // Get priority
    do
    {
        newPatient->priority =
            readInt("Enter priority (1=Critical, 2=Serious, 3=Normal): ");

        if (newPatient->priority < 1 ||
            newPatient->priority > 3)
        {
            printf("Priority must be 1, 2 or 3.\n");
        }

    } while (newPatient->priority < 1 ||
             newPatient->priority > 3);

    newPatient->next = NULL;


    // ===============================
    // INSERT INTO PRIORITY QUEUE
    // ===============================

    // Case 1: Queue empty
    if (waitingQueue == NULL)
    {
        waitingQueue = newPatient;
    }

    // Case 2: New patient has highest priority
    else if (newPatient->priority <
             waitingQueue->priority)
    {
        newPatient->next = waitingQueue;
        waitingQueue = newPatient;
    }

    // Case 3: Insert in correct position
    else
    {
        temp = waitingQueue;

        while (temp->next != NULL &&
               temp->next->priority <=
               newPatient->priority)
        {
            temp = temp->next;
        }

        newPatient->next = temp->next;
        temp->next = newPatient;
    }

    printf("\nPatient registered successfully!\n");
    printf("Assigned ID: %d\n", newPatient->id);
}


// ===============================
// DISPLAY WAITING QUEUE
// ===============================
void displayWaitingQueue()
{
    struct Patient *temp = waitingQueue;

    if (temp == NULL)
    {
        printf("\nWaiting queue is empty.\n");
        return;
    }

    printf("\n========================================\n");
    printf("           WAITING QUEUE\n");
    printf("========================================\n");

    while (temp != NULL)
    {
        printf("\nID       : %d", temp->id);
        printf("\nName     : %s", temp->name);
        printf("\nAge      : %d", temp->age);
        printf("\nDisease  : %s", temp->disease);
        printf("\nPriority : %d (%s)",
               temp->priority,
               getPriorityName(temp->priority));

        printf("\n----------------------------------------\n");

        temp = temp->next;
    }
}


// ===============================
// TREAT NEXT PATIENT
// ===============================
void treatNextPatient()
{
    struct Patient *patient;
    struct TreatedPatient *newTreated;
    struct TreatedPatient *temp;

    // No patient
    if (waitingQueue == NULL)
    {
        printf("\nNo patients waiting.\n");
        return;
    }

    // Remove first patient
    patient = waitingQueue;
    waitingQueue = waitingQueue->next;

    printf("\n========================================\n");
    printf("         TREATING NEXT PATIENT\n");
    printf("========================================\n");

    printf("ID       : %d\n", patient->id);
    printf("Name     : %s\n", patient->name);
    printf("Priority : %d (%s)\n",
           patient->priority,
           getPriorityName(patient->priority));


    // Create treated node
    newTreated =
        (struct TreatedPatient*)
        malloc(sizeof(struct TreatedPatient));

    if (newTreated == NULL)
    {
        printf("Memory allocation failed!\n");

        // Put patient back
        patient->next = waitingQueue;
        waitingQueue = patient;

        return;
    }

    // Copy details
    newTreated->id = patient->id;

    strcpy(newTreated->name,
           patient->name);

    newTreated->age = patient->age;

    strcpy(newTreated->disease,
           patient->disease);

    strcpy(newTreated->status,
           "Treated");

    newTreated->next = NULL;


    // Add to treated list
    if (treatedList == NULL)
    {
        treatedList = newTreated;
    }
    else
    {
        temp = treatedList;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newTreated;
    }

    // Delete old waiting node
    free(patient);

    printf("\nTreatment complete!\n");
    printf("Record moved to Treated List.\n");
}


// ===============================
// DISPLAY TREATED PATIENTS
// ===============================
void displayTreatedPatients()
{
    struct TreatedPatient *temp = treatedList;

    if (temp == NULL)
    {
        printf("\nNo patients have been treated yet.\n");
        return;
    }

    printf("\n========================================\n");
    printf("          TREATED PATIENTS\n");
    printf("========================================\n");

    while (temp != NULL)
    {
        printf("\nID       : %d", temp->id);
        printf("\nName     : %s", temp->name);
        printf("\nAge      : %d", temp->age);
        printf("\nDisease  : %s", temp->disease);
        printf("\nStatus   : %s", temp->status);

        printf("\n----------------------------------------\n");

        temp = temp->next;
    }
}


// ===============================
// SEARCH BY ID
// ===============================
void searchByID()
{
    int id;
    struct Patient *p;
    struct TreatedPatient *t;

    id = readInt("Enter patient ID: ");

    // Search waiting queue
    p = waitingQueue;

    while (p != NULL)
    {
        if (p->id == id)
        {
            printf("\nPatient found in WAITING QUEUE!\n");

            printf("ID       : %d\n", p->id);
            printf("Name     : %s\n", p->name);
            printf("Age      : %d\n", p->age);
            printf("Disease  : %s\n", p->disease);
            printf("Priority : %d (%s)\n",
                   p->priority,
                   getPriorityName(p->priority));

            return;
        }

        p = p->next;
    }


    // Search treated list
    t = treatedList;

    while (t != NULL)
    {
        if (t->id == id)
        {
            printf("\nPatient found in TREATED LIST!\n");

            printf("ID       : %d\n", t->id);
            printf("Name     : %s\n", t->name);
            printf("Age      : %d\n", t->age);
            printf("Disease  : %s\n", t->disease);
            printf("Status   : %s\n", t->status);

            return;
        }

        t = t->next;
    }

    printf("\nPatient not found.\n");
}


// ===============================
// SEARCH BY NAME
// ===============================
void searchByName()
{
    char name[NAME_SIZE];

    struct Patient *p;
    struct TreatedPatient *t;

    readString("Enter patient name: ",
               name,
               NAME_SIZE);


    // Search waiting queue
    p = waitingQueue;

    while (p != NULL)
    {
        if (strcmp(p->name, name) == 0)
        {
            printf("\nPatient found in WAITING QUEUE!\n");

            printf("ID       : %d\n", p->id);
            printf("Name     : %s\n", p->name);
            printf("Age      : %d\n", p->age);
            printf("Disease  : %s\n", p->disease);
            printf("Priority : %d (%s)\n",
                   p->priority,
                   getPriorityName(p->priority));

            return;
        }

        p = p->next;
    }


    // Search treated list
    t = treatedList;

    while (t != NULL)
    {
        if (strcmp(t->name, name) == 0)
        {
            printf("\nPatient found in TREATED LIST!\n");

            printf("ID       : %d\n", t->id);
            printf("Name     : %s\n", t->name);
            printf("Age      : %d\n", t->age);
            printf("Disease  : %s\n", t->disease);
            printf("Status   : %s\n", t->status);

            return;
        }

        t = t->next;
    }

    printf("\nPatient not found.\n");
}


// ===============================
// SEARCH PATIENT MENU
// ===============================
void searchPatient()
{
    int choice;

    printf("\n========================================\n");
    printf("            SEARCH PATIENT\n");
    printf("========================================\n");

    printf("1. Search by ID\n");
    printf("2. Search by Name\n");

    choice = readInt("Enter choice: ");


    if (choice == 1)
    {
        searchByID();
    }
    else if (choice == 2)
    {
        searchByName();
    }
    else
    {
        printf("\nInvalid choice! Please select 1 or 2.\n");
    }
}


// ===============================
// FREE MEMORY
// ===============================
void freeMemory()
{
    struct Patient *p;
    struct TreatedPatient *t;

    // Free waiting queue
    while (waitingQueue != NULL)
    {
        p = waitingQueue;
        waitingQueue = waitingQueue->next;

        free(p);
    }

    // Free treated list
    while (treatedList != NULL)
    {
        t = treatedList;
        treatedList = treatedList->next;

        free(t);
    }
}


// ===============================
// MAIN FUNCTION
// ===============================
int main()
{
    int choice;

    while (1)
    {
        printf("\n\n");
        printf("========================================\n");
        printf("   HOSPITAL PATIENT QUEUE MANAGEMENT\n");
        printf("========================================\n");

        printf("1. Register New Patient\n");
        printf("2. Display Waiting Queue\n");
        printf("3. Treat Next Patient\n");
        printf("4. Display Treated Patients\n");
        printf("5. Search Patient\n");
        printf("6. Exit\n");

        printf("========================================\n");

        choice = readInt("Enter your choice: ");


        switch (choice)
        {
            case 1:
                registerPatient();
                break;

            case 2:
                displayWaitingQueue();
                break;

            case 3:
                treatNextPatient();
                break;

            case 4:
                displayTreatedPatients();
                break;

            case 5:
                searchPatient();
                break;

            case 6:
                freeMemory();

                printf("\nProgram ended successfully.\n");
                return 0;

            default:
                printf("\nInvalid choice! Please enter 1 to 6.\n");
        }
    }

    return 0;
}