#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

bool checkForLoShuSquare(int arr[3][3]) //Checks if we have a Lou Shu Square
{
    bool confirm = true;
    const int FIFTEEN = 15;
    int countRows = 0;
    int countFirstCol = 0;
    int countSecondCol = 0;
    int countThirdCol = 0;

    for(int i = 0; i < 3; i++)
    {
        for(int y = 0; y < 3; y++)
        {
            countRows += arr[i][y];
            if(y == 0)
            {
                countFirstCol += arr[i][y];
            }
            else if(y == 1)
            {
                countSecondCol += arr[i][y];
            }
            else
            {
                countThirdCol += arr[i][y];
            }
        }
        if(countRows != FIFTEEN)
        {
            confirm = false;
        }
        countRows = 0;
    }

    return confirm && countFirstCol == FIFTEEN && countSecondCol == FIFTEEN && countThirdCol == FIFTEEN;
}


void reset(int newArr[3][3]) //Resets the nested array
{
    for(int i = 0; i < 3; i++)
    {
        for(int y = 0; y < 3; y++)
        {
            newArr[i][y] = 0;
        }
    }
}
bool checkForSame(int newArr[3][3], int value) //Checks if we already included the numbers
{
    for(int i = 0; i < 3; i++)
    {
        for(int y = 0; y < 3; y++)
        {
            if(newArr[i][y] == value)
            {
                return true;
            }
        }
    }
    return false;
}


void addValues(int newArr[3][3]) //Adds the values
{
    int min = 1;
    int max = 9;
  
    for(int i = 0; i < 3; i++)
    {
        for(int y = 0; y < 3; y++)
        {
            int random;
            do
            {
                random = (rand() % (max - min + 1)) + min;
            } while(checkForSame(newArr, random));
            newArr[i][y] = random;
        }
    }
}


int main()
{
    int newArr[3][3];
    int count = 0;
    bool check;
    int isLou[3][3] = {{4,9,2},{3,5,7},{8,1,6}};
    int isNotLou[3][3] = {{9,5,4},{3,2,1},{8,6,7}};
    //First Test: Checks if it is not a Lou Shu Square
    bool confirmLou = checkForLoShuSquare(isLou);
    bool confirmIsNotLou = checkForLoShuSquare(isNotLou);
    //Confirms it is a Loud Shu Square
    if(confirmLou)
    {   
        printf("It is a Lou Shu Square\n");
    }
    else
    {
        printf("It is NOT a Lou Shu Square\n");
    }

    //Confirms it is NOT a Loud Shu Square
    if(confirmIsNotLou)
    {   
        printf("It is a Lou Shu Square\n");
    }
    else
    {
        printf("It is NOT a Lou Shu Square\n");
    }

    //Second Test: Finds the Lou Shu Square and outputs the array and the text
    do
    {
        reset(newArr);
        addValues(newArr);
        check = checkForLoShuSquare(newArr);    
        count++;
    } while(!check);
    
    //Outputs the correct Loud
    for(int i = 0; i < 3; i++)
    {
        printf("[");
        for(int y = 0; y < 3; y++)
        {
            if(y != 2)
            {
                printf("%d ", newArr[i][y]);
            }
            else
            {
                printf("%d", newArr[i][y]);
            }
        }
        printf("]\n");
    }

    //Outputs the number of tries
    printf("Total number of tries: %d", count);
    
    return 0;
}