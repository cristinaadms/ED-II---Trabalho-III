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
int Calculate_Rotated_Value(const char *registration, int table_size);
int Extract_Digits(const char *registration);
int Hash_Function_LA(const char *registration, int table_size);
int Hash_Function_LB(const char *registration, int table_size);
void Replace_Employee(HashingTable *hash_table, int index_employee);
int Handle_Collision_LA(HashingTable *hash_table, const char *registration, int original_index);
void Insert_Employee_LA(HashingTable *hash_table, Employee *employee);
int Handle_Collision_LB(HashingTable *hash_table, const char *registration, int original_index);
void Insert_Employee_LB(HashingTable *hash_table, Employee *employee);
void Initialize_Hash_Table(HashingTable *hash_table, int size);
void Show_Hash_Table(HashingTable *hash_table);
void Free_Hash_Table(HashingTable *hash_table);
double Measure_Insertion_Performance(HashingTable *hash_table, Employee **employees, int num_employees, int hash_case);
int Compare_Collisions(HashingTable *hash_table, Employee **employees, int num_employees, int hash_case);



#endif