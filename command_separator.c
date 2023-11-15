#include "simple_shell.h"

/**
*readcmd_with_separator - This function handles the command separator
*@s: string
*@file_stream: get line input
*Return: 0
*/

int readcmd_with_separator(char *s, size_t __attribute__((unused))file_stream)
{
	char *tkn = NULL;
	char *command_array[100];
	int ab, i;
	/** This tokenize input string based on semi coluns **/
	tkn = strtok(s, ";");
	ab = 0;
	while (tkn)
	{
		/** This remove leading whitespace from the current command **/
		while (*tkn == ' ' || *tkn == '\t')
		tkn++;

		/** This skip empty commands **/
		if (*tkn != '\0')
		{
			command_array[ab++] = tkn;
		}

		/** This get the next command separately **/
		tkn = strtok(NULL, ";");
	}

	/** This execute each command separately **/
	for (i = 0; i < ab; i++)
	{
		char *current_command = command_array[i];

		if (__mystrcmp(current_command, "exit")
			== 0)
			return (2);
		else if (__mystrcmp(current_command, "env") == 0)
			__printenv();
		else if (__mystrncmp(current_command, "setenv", 6) == 0)
		{
			char *variable, *value;

			variable = strtok(s + 7, " ");
			value = strtok(NULL, " ");
			if (variable != NULL && value != NULL)
			return (mysetenv(variable, value, 1));
			else
			{
			fprintf(stderr, "Usage: setenv Variable Value\n");
			return (-1);
			}
		}
		else if (__mystrncmp(current_command, "unsetenv", 8) == 0)
		{
			char *variable = strtok(s + 9, " ");

			if (variable != NULL)
			return (myunsetenv(variable));
			else
			{
				fprintf(stderr, "usage: unsetenv Variable\n");
				return (-1);
			}
		}
		else
		{
			char *subtkn = strtok(current_command, " ");

	/** This create an array of pointers to store command arguments **/
			char *subcommand_array[100];
			int subab = 0;
			int j;

	/** We tokonize the current command based on spaces **/
			while (subtkn)
			{
				subcommand_array[subab++] = subtkn;
				subtkn = strtok(NULL, " ");
			}
		/** This execute each sub-command **/
			for (j = 0; j < subab; j++)
			{
			/** Separate each command **/
				char *argument = subcommand_array[j];
				(void)argument;
			}
		}
	}
	return (0);
}
