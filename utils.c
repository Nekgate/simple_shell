#include "simple_shell.h"

/**
*contains_commands_separator - This Check if the input string contains a (;)
*@cmd: the command separator
*Return: Returns 0
*/
int contains_commands_separator(char *cmd)
{
/** This Check if the input string contains a semicolon (';') **/
	while (*cmd != '\0')
	{
	if (*cmd == ';')
	{
		return (1);
	}
	cmd++;
	}
	return (0); /** Return 0 if semicolon is found **/
}
