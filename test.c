#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>



int calPoints(char** operations, int operationsSize)
{
    int* stack = (int*)malloc(sizeof(int) * operationsSize);
    int sum = 0;
    int p = 0;
    for (int i = 0; i < operationsSize; i++)
    {
        switch (operations[i][0])
        {
        case '+':
        {
            stack[p++] = stack[p - 1] + stack[p - 2];
            sum += stack[p - 1];
            break;
        }
        case 'D':
        {
            stack[p++] = stack[p - 1] * 2;
            sum += stack[p - 1];
            break;
        }
        case 'C':
        {
            sum -= stack[p - 1];
            p--;
            break;
        }
        default:
        {
            sum += atoi(operations[i]);
            stack[p++] = atoi(operations[i]);
            break;
        }
        }
    }
    free(stack);
    return sum;
}