#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv)
{
    char inputFileName[50], outputFileName[50];
    char *inputFileExtension, *outputFileExtension;
    
    printf("Enter file name\n");
    scanf("%s", inputFileName);
    inputFileExtension = strchr(inputFileName, '.');
    
    printf("What file would you like to store this in?\n");
    scanf("%s", outputFileName);
    outputFileExtension = strchr(outputFileName, '.');
    
    if (strcmp(inputFileExtension, ".csv") == 0)
    {
        if (strcmp(outputFileExtension, ".csv") == 0)
            printf("Already in correct format");
        else if (strcmp(outputFileExtension, ".tl5") == 0)
            ConvertCsvToTl5(inputFileName, outputFileName);
        else if (strcmp(outputFileExtension, ".tr9") == 0)
            ConvertCsvToTr9(inputFileName, outputFileName);
        else if (strcmp(outputFileExtension, ".tc9") == 0)
            /*ConvertCsvToTc9(inputFileName, outputFileName)*/;
        else
            printf("Not valid");
    }
    else if (strcmp(inputFileExtension, ".tl5") == 0)
    {
        if (strcmp(outputFileExtension, ".csv") == 0)
            ConvertTl5ToCsv(inputFileName, outputFileName);
        else if (strcmp(outputFileExtension, ".tl5") == 0)
            printf("Already in correct format");
        else if (strcmp(outputFileExtension, ".tr9") == 0)
            ConvertTl5ToTr9(inputFileName, outputFileName);
        else if (strcmp(outputFileExtension, ".tc9") == 0)
            /*ConvertTl5ToTc9(inputFileName, outputFileName)*/;
        else
            printf("Not valid");
    }
    else if (strcmp(inputFileExtension, ".tr9") == 0)
    {
        if (strcmp(outputFileExtension, ".csv") == 0)
            ConvertTr9ToCsv(inputFileName, outputFileName);
        else if (strcmp(outputFileExtension, ".tl5") == 0)
            /*ConvertTr9ToTl5(inputFileName, outputFileName)*/;
        else if (strcmp(outputFileExtension, ".tr9") == 0)
            printf("Already in correct format");
        else if (strcmp(outputFileExtension, ".tc9") == 0)
            /*ConvertTr9ToTc9(inputFileName, outputFileName)*/;
        else
            printf("Not valid");
    }
    else if (strcmp(inputFileExtension, ".tc9") == 0)
    {
        if (strcmp(outputFileExtension, ".csv") == 0)
            /*ConvertTc9ToCsv(inputFileName, outputFileName)*/;
        else if (strcmp(outputFileExtension, ".tl5") == 0)
            /*ConvertTc9ToTl5(inputFileName, outputFileName)*/;
        else if (strcmp(outputFileExtension, ".tr9") == 0)
            /*ConvertTc9ToTr9(inputFileName, outputFileName)*/;
        else if (strcmp(outputFileExtension, ".tc9") == 0)
            printf("Already in correct format");
        else
            printf("Not valid");
    }
    else
        printf("Not valid");
    
    return (EXIT_SUCCESS);
}

void ConvertCsvToTl5(char* input, char* output)
{
    FILE *fpin = fopen(input, "r");
    FILE *fpout = fopen(output, "w");
    char fileInput[500];
    char* token;
    
    while (fgets(fileInput, 500, fpin))
    {
        token = strtok(fileInput, ",");
        while (token != NULL)
        {
            if (isspace(token[0]))
                token += 1;
            fprintf(fpout, "%-5.5s|", token);
            token = strtok(NULL, ",");
        }
    }
    
    printf("Conversion success!\n");
}

void ConvertTl5ToCsv(char* input, char* output)
{
    FILE *fpin = fopen(input, "r");
    FILE *fpout = fopen(output, "w");
    char fileInput[500];
    char temp;
    
    while (1)
    {
        fscanf(fpin, "%[^|]s", fileInput);
        temp = getc(fpin);
        if (temp == '|')
            fprintf(fpout, "%s, ", fileInput);
        else if (temp == '\n')
            fprintf(fpout, "\n");
        else if (temp == EOF)
            break;
        else
        {
            printf("Error in input file formatting");
            break;
        }
    }
    
    printf("Conversion success!\n");
}

void ConvertCsvToTr9(char* input, char* output)
{
    FILE *fpin = fopen(input, "r");
    FILE *fpout = fopen(output, "w");
    char fileInput[500];
    char* token;
    
    while (fgets(fileInput, 500, fpin))
    {
        token = strtok(fileInput, ",");
        
        while (token != NULL)
        {
            if (isspace(token[0]))
                token += 1;
            if (strlen(token) > 9)
                token += (strlen(token) - (strlen(token) - 9));
            printf("%9s|\n", token);
            fprintf(fpout, "%9s|", token);
            token = strtok(NULL, ",");
        }
    }
    
    printf("Conversion success!\n");
}

void ConvertTl5ToTr9(char* input, char* output)
{
    FILE *fpin = fopen(input, "r");
    FILE *fpout = fopen(output, "w");
    char fileInput[500];
    char* token;
    
    while (fgets(fileInput, 500, fpin))
    {
        token = strtok(fileInput, "|");
        
        while (token != NULL)
        {
            printf("%c", token[strlen(token) - 1]);
            if (isspace(token[strlen(token) - 1]))  
                token[strlen(token) - 1] = '\0';
            fprintf(fpout, "%9s|", token);
            token = strtok(NULL, "|");
        }
    }
    
    printf("Conversion success!\n");
}

ConvertTr9ToCsv(char* input, char* output)
{
    FILE *fpin = fopen(input, "r");
    FILE *fpout = fopen(output, "w");
    char fileInput[500];
    char temp;
    
    while (1)
    {
        fscanf(fpin, "%[^|]s", fileInput);
        temp = getc(fpin);
        if (temp == '|')
            fprintf(fpout, "%s, ", fileInput);
        else if (temp == '\n')
            fprintf(fpout, "\n");
        else if (temp == EOF)
            break;
        else
        {
            printf("Error in input file formatting");
            break;
        }
    }
    
    printf("Conversion success!\n");
}