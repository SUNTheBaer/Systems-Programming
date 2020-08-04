#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv)
{
    char userInput[100];
    int result;
    
    printf("Enter an english word\n");
    scanf("%s", userInput);
    result = spellCheck(userInput, "dictionary.txt");
    printf("%d", result);
    return (EXIT_SUCCESS);
}

int spellCheck(char* word, char* dictionaryFileName)
{
    FILE* fp = fopen(dictionaryFileName, "r");
    char* dictionaryWords[100000];
    char temp[100];
    int i = 0;
    int result;
    
    while (!feof(fp))
    {
        fscanf(fp, "%s", temp);
        dictionaryWords[i] = (char*)malloc(sizeof(temp) + 1);
        strcpy(dictionaryWords[i++], temp);
    }
    
    result = binsearch(dictionaryWords, i, word);
    
    if (result == -1)
        return 0;
    else
        return 1;
}

int binsearch(char* dictionaryWords[],int listSize,char* keyword)
{
    int mid, low = 0, high = listSize - 1;
    while (high >= low)
    {
        mid = (high + low) / 2;
        if (strcmp(dictionaryWords[mid],keyword) < 0)
            low = mid + 1;
        else if (strcmp(dictionaryWords[mid],keyword) > 0)
            high = mid - 1;
        else
            return mid;
    }
    
    return -1;
}