#ifndef hashing_h
#define hashing_h

//structs
typedef struct employee{

    char registration[7];
    char name[50];
    char function[30];
    float salary;

} Employee;

typedef struct hashentry{

    Employee *employee;
    int busy;

} HashEntry;

typedef struct hashingtable{
    
    HashEntry *table;
    int size;
    int collisions;

} HashingTable;

//escopo das funções
int Hash_Function(const char *registration, int table_size);
void Insert_Employee(HashingTable *hash_table, Employee *employee);
void Initialize_Hash_Table(HashingTable *hash_table, int size);
void Show_Hash_Table(HashingTable *hashTable);


#endif