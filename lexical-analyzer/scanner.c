#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Token types
typedef enum
{
    tokword,
    toknumber,
    tokop
} TokenType;

// Function to determine the token type
TokenType getTokenType(const char *token)
{
    if (isalpha(token[0]))
    {
        return tokword;
    }
    else if (isdigit(token[0]))
    {
        return toknumber;
    }
    else
    {
        return tokop;
    }
}

// Function to tokenize the input program
void gettoken(const char *input)
{
    char buffer[100]; // Assuming max token length of 100 characters
    int i = 0;

    for (int j = 0; input[j] != '\0'; j++)
    {
        if (isalnum(input[j]) || input[j] == '_')
        {
            buffer[i++] = input[j];
        }
        else
        {
            if (i > 0)
            {
                buffer[i] = '\0';

                // Only print the token if it's not "BEGIN" or "END"
                if (strcmp(buffer, "BEGIN") != 0 && strcmp(buffer, "END") != 0)
                {
                    TokenType type = getTokenType(buffer);
                    printf("%s\t", buffer);

                    switch (type)
                    {
                    case tokword:
                        printf("tokword\n");
                        break;
                    case toknumber:
                        printf("toknumber\n");
                        break;
                    case tokop:
                        printf("tokop\n");
                        break;
                    }
                }

                i = 0;
            }

            if (input[j] != ' ' && input[j] != '\t' && input[j] != '\n' && input[j] != '\r')
            {
                printf("%c\ttokop\n", input[j]);
            }
        }
    }
}

int main()
{
    const char *input_program = "PROGRAM Sample (Input, Output);\n  CONST\n     x  = 15;\n  BEGIN\n    \n  END;";
    gettoken(input_program);
    return 0;
}
