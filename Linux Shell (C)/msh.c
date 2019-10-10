/*
    Name: Brianna Peterson
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

#define _GNU_SOURCE

#include <stdio.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <signal.h>

#define WHITESPACE " \t\n"      // We want to split our command line up into tokens
                                // so we need to define what delimits our tokens.
                                // In this case  white space
                                // will separate the tokens on our command line

#define MAX_COMMAND_SIZE 255    // The maximum command-line size

#define MAX_NUM_ARGUMENTS 10     // Mav shell only supports ten arguments

int main()
{
  char * cmd_str = (char*) malloc(MAX_COMMAND_SIZE);
  char * history[50];
  int commandCount = 0, count = 0, pids[15], pidCount = 0, isNumber = 1;

  while(1)
  {
    char * histCheck;

    // Print out the msh prompt
    printf ("msh> ");

    // Read the command from the commandline. The
    // maximum command that will be read is MAX_COMMAND_SIZE
    // This while command will wait here until the user
    // inputs something since fgets returns NULL when there
    // is no input

    while(!fgets (cmd_str, MAX_COMMAND_SIZE, stdin));

    /* Parse input */
    char *token[MAX_NUM_ARGUMENTS];

    int token_count = 0;

    // Pointer to point to the token
    // parsed by strsep
    char *arg_ptr;

    char *working_str  = strdup(cmd_str);

    // Store command retrieved from user in an array
    // To keep track of previous 50 commands

    history[commandCount] = strdup(cmd_str);

    // we are going to move the working_str pointer so
    // keep track of its original value so we can deallocate
    // the correct amount at the end
    char *working_root = working_str;

    // Tokenize the input strings with whitespace used as the delimiter
    while (((arg_ptr = strsep(&working_str, WHITESPACE )) != NULL) &&
            (token_count<MAX_NUM_ARGUMENTS))
    {
        token[token_count] = strndup(arg_ptr, MAX_COMMAND_SIZE);

        if(strlen(token[token_count]) == 0)
        {
            token[token_count] = NULL;
        }
        token_count++;
    }



    if(token[0] != NULL)
    {
        // Use a "!" delimiter to check if a previous
        // command needs to be executed again, and check to see
        // if the string following the delimiter is a number.
        histCheck = strtok(token[0], "!");

        for (count = 0; count < strlen(histCheck); count++)
        {
            if(!isdigit(histCheck[count]))
                isNumber = 0;
        }

        if(isNumber)
        {
            int numCommand;

            // Converts string into integer in order to
            // locate command to be called within history array
            sscanf(histCheck, "%d", &numCommand);

            if(numCommand <= 14)
            {
                int tempCount = 0;
                char *temp, *strptr;

                temp = strdup(history[numCommand]);

                // Tokenize the command with whitespace as delimiter
                while((strptr = strsep(&temp, WHITESPACE)) != NULL)
                {
                    token[tempCount] = strdup(strptr);

                    if(strlen(token[tempCount]) == 0)
                    {
                        token[tempCount] = NULL;
                    }
                    tempCount++;
                }
            }
        }

        if((strcmp(token[0], "exit") == 0) || (strcmp(token[0], "quit") == 0))
        {
            exit(EXIT_SUCCESS);
        }

        // Displays the last 50 commands that were entered.
        // Allows user to re-use commands by typing !n, where
        // n is the number of the command on the display.
        else if(strcmp(token[0], "history") == 0)
        {
            for (count = 0; count <= commandCount; count++)
            {
                printf("%d: %s", count, history[count]);

            }
        }

        else if(strcmp(token[0], "listpids") == 0)
        {
            for (count = 0; count < pidCount; count++)
            {
                printf("%d: %d\n", count, pids[count]);
            }
        }

        // Execute change directory command before fork is called.
        // This allows the change in directory to affect other commands
        // executed in the future.
        else if (strcmp(token[0], "cd") == 0)
        {
            if (token[1] != NULL)
                chdir(token[1]);
        }

        else
        {
            pid_t pid = fork();

            // Stores process ID of current process into an array.
            // mav shell only supports storage of up to 15 process IDs.
            if(pidCount <= 14)
            {
                pids[pidCount] = pid;
                pidCount++;
            }

            else
            {
                pidCount = 0;
            }

            int status;
            char directory[MAX_COMMAND_SIZE];
            char binTest[MAX_COMMAND_SIZE];
            char usrBinTest[MAX_COMMAND_SIZE];
            char localBinTest[MAX_COMMAND_SIZE];

            // Initialize the beginning of the directories that
            // will be tested for commands.
            strcpy(binTest, "/bin/");
            strcpy(usrBinTest, "/usr/bin/");
            strcpy(localBinTest, "/usr/local/bin/");

            // Obtain the current working directory so we can test
            // to see if a command can be executed in that directory.
            getcwd(directory,sizeof(directory));

            if (pid == -1)
            {
                perror("fork failed.");
                exit(EXIT_FAILURE);
            }

            else if (pid == 0)
            {
                // Append the command we are searching for to the end
                // of the directories.
                strcat(binTest, token[0]);
                strcat(usrBinTest, token[0]);
                strcat(localBinTest, token[0]);

                // Check four directories for command in specified order.
                if(token[1] == NULL)
                {
                    execl(directory, token[0], NULL);
                    execl(localBinTest, token[0], NULL);
                    execl(usrBinTest, token[0], NULL);
                    execl(binTest, token[0], NULL);
                    printf("%s: Command not found.\n", token[0]);
                }

                else if(token[2] == NULL)
                {
                    execl(directory, token[0], token[1], NULL);
                    execl(localBinTest, token[0], token[1], NULL);
                    execl(usrBinTest, token[0], token[1], NULL);
                    execl(binTest, token[0], token[1], NULL);
                    printf("%s: Command not found.\n", token[0]);
                }

                else if(token[3] == NULL)
                {
                    execl(directory, token[0], token[1], token[2], NULL);
                    execl(localBinTest, token[0], token[1], token[2], NULL);
                    execl(usrBinTest, token[0], token[1], token[2], NULL);
                    execl(binTest, token[0], token[1], token[2], NULL);
                    printf("%s: Command not found.\n", token[0]);

                }

                else if(token[4] == NULL)
                {
                    execl(directory, token[0], token[1], token[2], token[3], NULL);
                    execl(localBinTest, token[0], token[1], token[2], token[3], NULL);
                    execl(usrBinTest, token[0], token[1], token[2], token[3], NULL);
                    execl(binTest, token[0], token[1], token[2], token[3], NULL);
                    printf("%s: Command not found.\n", token[0]);
                }

                else if(token[5] == NULL)
                {
                    execl(directory, token[0], token[1], token[2], token[3], token[4], NULL);
                    execl(localBinTest, token[0], token[1], token[2], token[3], token[4], NULL);
                    execl(usrBinTest, token[0], token[1], token[2], token[3], token[4], NULL);
                    execl(binTest, token[0], token[1], token[2], token[3], token[4], NULL);
                    printf("%s: Command not found.\n", token[0]);

                }

                else if(token[6] == NULL)
                {
                    execl(directory, token[0], token[1], token[2],
                          token[3], token[4], token[5], NULL);
                    execl(localBinTest, token[0], token[1], token[2],
                          token[3], token[4], token[5], NULL);
                    execl(usrBinTest, token[0], token[1], token[2],
                          token[3], token[4], token[5], NULL);
                    execl(binTest, token[0], token[1], token[2],
                           token[3], token[4], token[5], NULL);
                    printf("%s: Command not found.\n", token[0]);

                }

                else if(token[7] == NULL)
                {
                    execl(directory, token[0], token[1], token[2], token[3],
                          token[4], token[5], token[6], NULL);
                    execl(localBinTest, token[0], token[1], token[2], token[3],
                           token[4], token[5], token[6], NULL);
                    execl(usrBinTest, token[0], token[1], token[2], token[3],
                           token[4], token[5], token[6], NULL);
                    execl(binTest, token[0], token[1], token[2], token[3],
                           token[4], token[5], token[6], NULL);
                    printf("%s: Command not found.\n", token[0]);
                }

                else if(token[8] == NULL)
                {
                    execl(directory, token[0], token[1], token[2], token[3],
                          token[4], token[5], token[6], token[7], NULL);
                    execl(localBinTest, token[0], token[1], token[2], token[3],
                           token[4], token[5], token[6], token[7], NULL);
                    execl(usrBinTest, token[0], token[1], token[2], token[3],
                           token[4], token[5], token[6], token[7], NULL);
                    execl(binTest, token[0], token[1], token[2], token[3],
                           token[4], token[5], token[6], token[7], NULL);
                    printf("%s: Command not found.\n", token[0]);
                }

                else if(token[9] == NULL)
                {
                    execl(directory, token[0], token[1], token[2], token[3],
                          token[4], token[5], token[6], token[7], token[8], NULL);
                    execl(localBinTest, token[0], token[1], token[2], token[3],
                           token[4], token[5], token[6], token[7], token[8], NULL);
                    execl(usrBinTest, token[0], token[1], token[2], token[3],
                           token[4], token[5], token[6], token[7], token[8], NULL);
                    execl(binTest, token[0], token[1], token[2], token[3],
                           token[4], token[5], token[6], token[7], token[8], NULL);
                    printf("%s: Command not found.\n", token[0]);
                }

                // Shell Supports up to 10 arguments. If more than 10 arguments
                // are listed, shell will execute the first 10.
                else
                {
                    execl(directory, token[0], token[1], token[2], token[3], token[4],
                           token[5], token[6], token[7], token[8], token[9], NULL);
                    execl(localBinTest, token[0], token[1], token[2], token[3], token[4],
                           token[5], token[6], token[7], token[8], token[9], NULL);
                    execl(usrBinTest, token[0], token[1], token[2], token[3], token[4],
                           token[5], token[6], token[7], token[8], token[9], NULL);
                    execl(binTest, token[0], token[1], token[2], token[3], token[4],
                           token[5], token[6], token[7], token[8], token[9], NULL);
                    printf("%s: Command not found.\n", token[0]);
                }

                exit(EXIT_SUCCESS);
            }

            waitpid(pid, &status, 0);
        }
    }

    free(working_root);

    // mav shell does not support a history of more than 50 commands
    if(commandCount < 50)
        commandCount++;

    isNumber = 1;

  }
  return 0;
}
