#include <string.h>
#include <stdlib.h>
#include "Employee.h"

//Defined in employeeSearchOne.c
PtrToEmployee searchEmployeeByNumber(const Employee table[], int sizeTable, long numberToFind);
PtrToEmployee searchEmployeeByName(const Employee table[], int sizeTable, char * nameToFind);
PtrToEmployee searchEmployeeByPhoneNumber(const Employee table[], int sizeTable, char * phoneNumberToFind);
PtrToEmployee searchEmployeeBySalary(const Employee table[], int sizeTable, double salaryToFind);

int main(void)
{

    extern Employee EmployeeTable[];
    extern const int EmployeeTableEntries;

    PtrToEmployee matchPtr;
    matchPtr = searchEmployeeByNumber(EmployeeTable, EmployeeTableEntries, 1045);

    if(matchPtr != NULL)
    {
        printf("Employee ID 1045 is in record %d\n", matchPtr - EmployeeTable);
    }
    else
    {
        printf("Employee ID is NOT found in the record\n");
    }

    matchPtr = searchEmployeeByName(EmployeeTable, EmployeeTableEntries, "Tony Bobcat");
    if(matchPtr != NULL)
    {
        printf("Employee Tony Bobcat is in record %d\n", matchPtr - EmployeeTable);
    }
    else
    {
        printf("Employee Tony Bobcat is NOT found in the record\n");
    }

    matchPtr = searchEmployeeByPhoneNumber(EmployeeTable, EmployeeTableEntries, "310-555-1215");
    if(matchPtr != NULL)
    {
        printf("Phone number 310-55-1215 is in record %d\n", matchPtr - EmployeeTable);
    }
    else
    {
        printf("Phone number 310-55-1215 is NOT found in the record\n");
    }


    matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 8.32);
    if(matchPtr != NULL)
    {
        printf("Salary of 8.32 is in record %d\n", matchPtr - EmployeeTable);
    }
    else
    {
        printf("Salary of 8.32 is NOT found in the record\n");
    }
    return 0;
    
}