/* Brianna Peterson
   ID: 1001551110
*/

// The MIT License (MIT)
//
// Copyright (c) 2016, 2017 Trevor Bakker
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

//#define _GNU_SOURCE

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <stdint.h>
#include <ctype.h>


#define WHITESPACE " \t\n"      // We want to split our command line up into tokens
                                // so we need to define what delimits our tokens.
                                // In this case  white space
                                // will separate the tokens on our command line

#define MAX_COMMAND_SIZE 255    // The maximum command-line size

#define MAX_NUM_ARGUMENTS 4

char* convert_file_name(char*);
int LBAToOffset(int);
int16_t NextLB(uint32_t);

FILE *fp;
uint16_t BPB_RsvdSecCnt;
uint16_t BPB_BytesPerSec;
uint8_t BPB_SecPerClus;
uint32_t BPB_FATSz32;
uint8_t BPB_NumFats;

struct DirectoryEntry
{
    char DIR_Name[11];
    uint8_t DIR_Attr;
    uint8_t Unused1[8];
    uint16_t DIR_FirstClusterHigh;
    uint8_t Unused2[4];
    uint16_t DIR_FirstClusterLow;
    uint32_t DIR_FileSize;
};

struct DirectoryEntry dir[16];

int main()
{
    char * cmd_str = (char*) malloc( MAX_COMMAND_SIZE );
    long root_Dir;
    long curr_Dir;
    long prev_Dir;

    while(1)
    {
        printf ("mfs> ");

        while( !fgets (cmd_str, MAX_COMMAND_SIZE, stdin) );

        /* Parse input */
        char *token[MAX_NUM_ARGUMENTS];

        int   token_count = 0;

        // Pointer to point to the token
        // parsed by strsep
        char *arg_ptr;

        char *working_str  = strdup( cmd_str );

        // we are going to move the working_str pointer so
        // keep track of its original value so we can deallocate
        // the correct amount at the end
        char *working_root = working_str;

        // Tokenize the input strings with whitespace used as the delimiter
        while ( ( (arg_ptr = strsep(&working_str, WHITESPACE ) ) != NULL) &&
                  (token_count<MAX_NUM_ARGUMENTS))
        {
            token[token_count] = strndup( arg_ptr, MAX_COMMAND_SIZE );
            if( strlen( token[token_count] ) == 0 )
            {
                token[token_count] = NULL;
            }
            token_count++;
        }

        if(strcmp(token[0], "open") == 0)
        {
            if(token[1] != NULL)
            {
                if(fp != NULL)
                {
                    printf("Error: File system image already open.\n");
                }

                fp = fopen(token[1], "r");
                if(fp == NULL)
                {
                    printf("Error: File system image not found.\n");
                }
                else
                {
                    int offset;
                    int i = 0;

                    // Get BPB Information
                    fseek(fp, 11, SEEK_SET);
                    fread(&BPB_BytesPerSec, 1, 2, fp);
                    fseek(fp, 13, SEEK_SET);
                    fread(&BPB_SecPerClus, 1, 1, fp);
                    fseek(fp, 14, SEEK_SET);
                    fread(&BPB_RsvdSecCnt, 1, 2, fp);
                    fseek(fp, 16, SEEK_SET);
                    fread(&BPB_NumFats, 1, 1, fp);
                    fseek(fp, 36, SEEK_SET);
                    fread(&BPB_FATSz32, 1, 4, fp);

                    // Set root directory address
                    root_Dir = (BPB_NumFats*BPB_FATSz32*BPB_BytesPerSec) + (BPB_RsvdSecCnt*BPB_BytesPerSec);
                    curr_Dir = root_Dir;
                    prev_Dir = root_Dir;
                    offset = root_Dir;

                    fseek(fp, root_Dir, SEEK_SET);

                    // Read root directory into directory array
                    while(offset < (root_Dir + 512))
                    {
                        fread(&dir[i].DIR_Name, 1, 11, fp);
                        fseek(fp, offset + 11, SEEK_SET);
                        fread(&dir[i].DIR_Attr, 1, 1, fp);
                        fseek(fp, offset + 20, SEEK_SET);
                        fread(&dir[i].DIR_FirstClusterHigh, 1, 2, fp);
                        fseek(fp, offset + 26, SEEK_SET);
                        fread(&dir[i].DIR_FirstClusterLow, 1, 2, fp);
                        fseek(fp, offset + 28, SEEK_SET);
                        fread(&dir[i].DIR_FileSize, 1, 4, fp);
                        offset = offset + 32;
                        fseek(fp, offset, SEEK_SET);
                        i++;
                    }
                }
            }
        }

        if(strcmp(token[0], "info") == 0)
        {
            if(fp != NULL)
            {
                printf("BPB_BytesPerSec: %d %x\n", BPB_BytesPerSec, BPB_BytesPerSec);

                printf("BPB_SecPerClus: %d %x\n", BPB_SecPerClus, BPB_SecPerClus);

                printf("BPB_RsvdSecCnt: %d %x\n", BPB_RsvdSecCnt, BPB_RsvdSecCnt);

                printf("BPB_NumFATS: %d %x\n", BPB_NumFats, BPB_NumFats);

                printf("BPB_FATSz32: %d %x\n", BPB_FATSz32, BPB_FATSz32);

            }

            else
            {
                printf("Error: File system image must be opened first.\n");
            }
        }

        // Closes file system image.
        if(strcmp(token[0], "close") == 0)
        {
            if(fp == NULL)
            {
                printf("Error: File system not open.\n");
            }
            else
            {
                fclose(fp);
                fp = NULL;
            }
        }

        if(strcmp(token[0], "stat") == 0)
        {
            if(fp == NULL)
            {
                printf("Error: File system image must be opened first.\n");
            }

            else
            {
                int isMatch = 0, offset;
                int i = 0, firstClus;
                uint8_t attribute;
                char* temp_DIR;
                char read_directory[11];

                if(token[1] != NULL)
                {
                    temp_DIR = strdup(token[1]);
                    temp_DIR = convert_file_name(temp_DIR);

                    offset = curr_Dir;
                    fseek(fp, offset, SEEK_SET);

                    while(!isMatch && i < 16)
                    {
                        fread(&read_directory, 1, 11, fp);

                        if (strncmp(temp_DIR, read_directory, 11) == 0)
                        {
                            isMatch = 1;

                            fseek(fp, offset+11, SEEK_SET);
                            fread(&attribute, 1, 1, fp);
                            fseek(fp, offset+26, SEEK_SET);
                            fread(&firstClus, 1, 2, fp);

                            printf("attribute(hex): %x (decimal): %d\n",
                                   attribute, attribute);
                            printf("starting cluster number (hex): %x (decimal): %d\n"
                                   ,firstClus, firstClus);
                        }
                        offset = offset + 32;
                        fseek(fp, offset, SEEK_SET);
                        i++;
                    }

                    if(!isMatch)
                    {
                        printf("Error: File not found.\n");
                    }
                }
            }
        }

        if(strcmp(token[0], "ls") == 0)
        {
            int i = 0;

            if(fp != NULL)
            {
                if(curr_Dir == root_Dir)
                {
                    while(i < 16)
                    {
                        if(dir[i].DIR_Attr == 1 || dir[i].DIR_Attr == 16 || dir[i].DIR_Attr == 32)
                        {
                            printf("%s\n", dir[i].DIR_Name);
                        }
                        i++;
                    }
                }

                else
                {
                    char directory_name[11];
                    int offset, firstChar;
                    int8_t attribute;
                    offset = curr_Dir;

                    fseek(fp, offset, SEEK_SET);

                    while(i < 16)
                    {
                        fread(&firstChar, 1, 1, fp);
                        firstChar = firstChar & 0xFF;

                        if(firstChar != 229 && firstChar != 0)
                        {
                            fseek(fp, offset, SEEK_SET);
                            fread(&directory_name, 1, 11, fp);
                            fseek(fp, offset + 11, SEEK_SET);
                            fread(&attribute, 1, 1, fp);

                            if(attribute == 1 || attribute == 16 || attribute == 32)
                            {
                                    printf("%.11s\n", directory_name);
                            }
                        }

                        offset = offset + 32;
                        fseek(fp, offset, SEEK_SET);
                        i++;
                    }
                }
            }

            else
            {
                printf("Error: File system image must be opened first.\n");
            }
        }

        if(strcmp(token[0], "cd") == 0)
        {
            if(fp != NULL)
            {
                if(token[1] != NULL)
                {
                    char *parseptr, *directory, read_directory[11];
                    char* parsed_DIR[10];
                    int i = 0, j = 0, k = 0, notFound = 1, isAbsolute = 1, offset, length = 0;
                    uint16_t firstClus;
                    long temp_curr_DIR;

                    if(strcmp(token[1], "..") == 0)
                    {
                        int16_t clus;

                        curr_Dir = prev_Dir;
                        fseek(fp, curr_Dir + 26, SEEK_SET);
                        fread(&clus, 1, 2, fp);

                        prev_Dir = NextLB(clus);

                        if(prev_Dir == 0 || prev_Dir == -1)
                           {
                               prev_Dir = root_Dir;
                           }
                    }

                    else
                    {
                        temp_curr_DIR = curr_Dir;

                        parseptr = strtok(token[1], "/");

                        // Break directory up into its individual components
                        while(parseptr != NULL)
                        {
                            parsed_DIR[i] = strdup(parseptr);
                            parseptr = strtok(NULL, "/");
                            length++;
                            i++;
                        }

                        i = 0;

                        while (k < 2 && isAbsolute)
                        {
                            // Loop searches for relative path first,
                            // then absolute path, which starts at root.
                            if (k == 1)
                            {
                                curr_Dir = root_Dir;
                            }

                            while(j < length)
                            {
                                offset = curr_Dir;
                                directory = strdup(parsed_DIR[j]);

                                directory = convert_file_name(directory);

                                while(i < 16 && notFound)
                                {
                                    fseek(fp, offset, SEEK_SET);
                                    fread(read_directory, 1, 11, fp);

                                    if(strncmp(directory, read_directory, 11) == 0)
                                    {
                                        fseek(fp, offset + 26, SEEK_SET);
                                        fread(&firstClus, 1, 2, fp);
                                        prev_Dir = curr_Dir;
                                        curr_Dir = LBAToOffset(firstClus);
                                        notFound = 0;
                                        isAbsolute = 0;
                                    }

                                    offset = offset + 32;
                                    i++;
                                }
                                j++;
                                i = 0;
                                notFound = 1;
                            }
                            k++;
                            j = 0;
                        }
                    }
                }
            }
            else
            {
                printf("Error: File system image must be opened first.\n");
            }
        }

        if(strcmp(token[0], "read") == 0)
        {
            if(fp != NULL)
            {
                char *directory;
                char read_directory[11], filechar, ch[2];
                int pos, numBytes, offset, firstClus, intFileChar;
                long address;
                uint8_t val;

                if(token[1] != NULL && token[2] != NULL && token[3] != NULL)
                {
                    directory = strdup(token[1]);
                    directory = convert_file_name(directory);
                    pos = atoi(token[2]);
                    numBytes = atoi(token[3]);

                    offset = curr_Dir;

                    for(int i = 0; i < 16; i++)
                    {
                        fseek(fp, offset, SEEK_SET);
                        fread(&read_directory, 1, 11, fp);

                        if(strncmp(directory, read_directory, 11) == 0)
                        {
                            fseek(fp, offset + 26, SEEK_SET);
                            fread(&firstClus, 1, 2, fp);

                            address = LBAToOffset(firstClus);
                            fseek(fp, address + pos, SEEK_SET);
                            printf("ASCII: ");

                            for(int j = 0; j < numBytes; j++)
                            {
                                fseek(fp, address + pos + j, SEEK_SET);
                                fread(&ch, 1, 1, fp);
                                printf("%.1s ", ch);
                            }

                            printf("\nHEX: ");

                            for(int k = 0; k < numBytes; k++)
                            {
                                fseek(fp, address + pos + k, SEEK_SET);
                                fread(&val, 1, 1, fp);
                                printf("%x ", val);
                            }

                        }
                        offset = offset + 32;
                    }
                    printf("\n");
                }
            }

            else
            {
                printf("Error: File system image must be opened first.\n");
            }
        }

        if(strcmp(token[0], "get") == 0)
        {
            if(fp != NULL)
            {
                if(token[1] != NULL)
                {
                    FILE *get_file;
                    int cnt = 0, cnt2 = 0, num, found = 0, temp_address;
                    char *directory, myFile[12], read_directory[11];

                    strncpy(myFile, token[1], sizeof(myFile));

                    directory = strdup(token[1]);
                    directory = convert_file_name(directory);

                    temp_address = curr_Dir;

                    while(cnt < 16 && !found)
                    {
                        char read_directory[11];

                        fseek(fp, temp_address, SEEK_SET);
                        fread(&read_directory, 1, 11, fp);

                        if(strncmp(read_directory, directory, 11) == 0)
                        {
                            myFile [12] = '\0';
                            get_file = fopen(myFile, "w");

                            uint32_t fileSize;
                            fseek(fp, temp_address + 28, SEEK_SET);
                            fread(&fileSize, 1, 4, fp);

                            found = 1;

                            while(cnt2 < fileSize)
                            {
                                int address;
                                uint16_t firstClus;

                                fseek(fp, temp_address + 26, SEEK_SET);
                                fread(&firstClus, 1, 2, fp);

                                address = LBAToOffset(firstClus);

                                fseek(fp, address+cnt2, SEEK_SET);
                                fread(&num, 1, 1, fp);

                                fprintf(get_file, "%c", num);

                                cnt2++;
                            }

                            fclose(get_file);
                        }
                        temp_address += 32;
                        fseek(fp, temp_address, SEEK_SET);
                        cnt++;
                    }

                    if(!found)
                    {
                        printf("Error: File not found.\n");
                    }
                }

            }
            else
            {
                printf("Error: File system image must be opened first.\n");
            }
        }
        free(working_root);
    }

    return 0;
}

/* Converts a file name (i.e num.txt) to how it is stored in fat32.img */
char* convert_file_name(char *temp_DIR)
{
    char *charptr, *temp;
    int length1 = 0, length2 = 0, numSpaces, cnt = 0, isPeriod = 0;

    // check to see if file vs folder or directory
     for(cnt = 0; cnt < 11; cnt++)
    {
        if(temp_DIR[cnt] == '.')
        {
            isPeriod = 1;
        }
    }

    // separate the file name from the period
    charptr = strtok(temp_DIR, ".");
    temp = strdup(charptr);
    length1 = strlen(charptr);

    if(isPeriod)
    {
    // get the extension
    charptr = strtok(NULL, ".");
    length2 = strlen(charptr);
    }


    numSpaces = 11 - length1 - length2;
    cnt = 0;

    while(cnt < numSpaces)
    {
        strcat(temp, " ");
        cnt++;
    }

    if(isPeriod)
    {
        strcat(temp, charptr);
    }

    for(cnt = 0; cnt < 11; cnt++)
    {
        temp[cnt] = toupper(temp[cnt]);
    }

    temp_DIR = strdup(temp);

    return temp_DIR;

}

/* Given cluster number, goes to where file/folder contents are stored */
int LBAToOffset(int sector)
{
    return ((sector -2) * BPB_BytesPerSec) + (BPB_BytesPerSec * BPB_RsvdSecCnt) +
    (BPB_NumFats * BPB_FATSz32 * BPB_BytesPerSec);
}

/* Returns next logical block address */
int16_t NextLB(uint32_t sector)
{
    uint32_t FATAddress = (BPB_BytesPerSec*BPB_RsvdSecCnt) + (sector*4);
    int16_t val;
    fseek(fp, FATAddress, SEEK_SET);
    fread(&val, 2, 1, fp);
    return val;
}


