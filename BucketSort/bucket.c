#include <stdio.h>
#include "node.h"
#define NUMBUCKS 8

struct bucket
{
int minInitial;
int maxInitial;
int numWords;
struct node* chainHead;
};

struct bucket list[NUMBUCKS] = {
        'a', 'b', 0, NULL,
        'c', 'c', 0, NULL,
        'd', 'f', 0, NULL,
        'g', 'k', 0, NULL,
        'l', 'o', 0, NULL,
        'p', 'r', 0, NULL,
        's', 's', 0, NULL,
        't', 'z', 0, NULL
    };

void PassString(char* string)
{
   struct node temp = {string, NULL};
    
   if (*string >= 'a' && *string <= 'b')
       PickBucket(0, &temp, string);
   else if (*string == 'c')
       PickBucket(1, &temp, string);
   else if (*string >= 'd' && *string <= 'f')
       PickBucket(2, &temp, string);
   else if (*string >= 'g' && *string <= 'k')
       PickBucket(3, &temp, string);
   else if (*string >= 'l' && *string <= 'o')
       PickBucket(4, &temp, string);
   else if (*string >= 'p' && *string <= 'r')
       PickBucket(5, &temp, string);
   else if (*string == 's')
       PickBucket(6, &temp, string);
   else
       PickBucket(7, &temp, string);
}

void PickBucket(int bucketNum, struct node* temp, char* string)
{
    temp->string = string;
    temp->next = list[bucketNum].chainHead;
    list[bucketNum].chainHead = &temp;
    list[bucketNum].numWords++;
}

void SortAndPrintBucket()
{
    for (int i = 0; i < NUMBUCKS; i++)
    {
        SortAndPrintBucketPass(i);
    }
}

void SortAndPrintBucketPass(int bucketNum)
{
    int n = list[bucketNum].numWords;
    
    char* sortedList[n - 1];
    
    for (int i = 0; i < n; i++)
    {
        sortedList[i] = list[0].chainHead->string;
        list[0].chainHead = list[0].chainHead->next;
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            if (strcmp(sortedList[j] , sortedList[j + 1]) > 0)
            {
                char* temp = sortedList[j];
                sortedList[j] = sortedList[j + 1];
                sortedList[j + 1] = temp;
            }
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        printf("%s\n", sortedList[i]);
    }
}