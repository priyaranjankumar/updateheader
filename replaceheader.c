/**
 * @Author: PRIYA RANJAN KUMAR
 * @Date: 2023-10-0 20:00:00
 * This program takes two arguments: a file name and a date in the format YYYY-MM-DD.
 * It opens the file in read-write mode, reads the header of the file, manipulates the header as needed,
 * and writes the modified header back to the file. The header is assumed to be the first 56 characters of the file.
 * The manipulation in this program replaces the string "001|" in the header with "001|YYYY-MM-DD".
 * If the arguments are not provided or are not in the correct format, the program returns an error.
 *
 * @param argc The number of arguments passed to the program.
 * @param argv An array of strings containing the arguments passed to the program.
 *             The first argument should be the file name, and the second argument should be the date in the format YYYY-MM-DD.
 *
 * @return 0 if the program executes successfully, and 1 if there is an error.
 */
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    printf("No of argument provided: %d\n", argc);
    if (argc < 3 || argc > 4)
    {
        printf("Provide all arguments");
        return 1;
    }
    if (argv[0][0] == '\0')
    {
        printf("File name must not be empty");
        return 1;
    }
    if (argv[2][0] == '\0')
    {
        printf("Date must not be empty");
        return 1;
    }
    if (strlen(argv[2]) != 10)
    {
        printf("Date must be 10 characters long");
        return 1;
    }
    if (argv[2][4] != '-' || argv[2][7] != '-')
    {
        printf("Date must be in the format YYYY-MM-DD");
        return 1;
    }
    if (argv[2][0] < '0' || argv[2][0] > '9' ||
        argv[2][1] < '0' || argv[2][1] > '9' ||
        argv[2][2] < '0' || argv[2][2] > '9' ||
        argv[2][3] < '0' || argv[2][3] > '9' ||
        argv[2][5] < '0' || argv[2][5] > '9' ||
        argv[2][6] < '0' || argv[2][6] > '9' ||
        argv[2][8] < '0' || argv[2][8] > '9' ||
        argv[2][9] < '0' || argv[2][9] > '9')
    {
        printf("Date must be in the format YYYY-MM-DD");
        return 1;
    }
    if (argv[2][5] != '0' && argv[2][5] != '1')
    {
        printf("Month must be between 01 and 12");
        return 1;
    }
    printf("argv[0]: %s\n", argv[0]);
    printf("argv[1]: %s\n", argv[1]);
    printf("argv[2]: %s\n", argv[2]);
    // Open the file in read-write mode
    FILE *file = fopen(argv[1], "r+b");
    if (file == NULL)
    {
        printf("Failed to open file");
        return 1;
    }

    // Read the header of the file
    char header[56];
    if (fgets(header, sizeof(header), file) == NULL)
    {
        printf("Failed to read header");
        fclose(file);
        return 1;
    }

    // Manipulate the header as needed
    // For example, replace "old" with "new"
    // Take input
    char *old = "001|";
    char *date = argv[2];
    char new[25] = "";
    char *pos = strstr(header, old);
    printf("pos: %s\n", pos);
    printf("old: %s\n", old);
    strcpy(new, old);
    printf("new: %s\n", new);
    strcat(new, date);
    printf("new: %s\n", new);
    strcat(new, "|");
    printf("new: %s\n", new);
    strcat(new, date);
    printf("new: %s\n", new);
    if (pos != NULL)
    {
        strncpy(pos, new, strlen(new));
    }

    // Write the modified header back to the file
    if (fseek(file, 0, SEEK_SET) != 0)
    {
        printf("Failed to seek to beginning of file");
        fclose(file);
        return 1;
    }
    if (fputs(header, file) == EOF)
    {
        printf("Failed to write header");
        fclose(file);
        return 1;
    }

    // Close the file
    if (fclose(file) != 0)
    {
        printf("Failed to close file");
        return 1;
    }

    return 0;
}
