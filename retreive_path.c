#include "simple_shell.h"

/**
 * __mygetpath -  This accepts PATH string, splits it to tokens, then concats
 * with "/" & cmd
 *@command: command passed from getline in main
 *
 * Return: new_path for use in cmd_read
 */

char *__mygetpath(char *command)
{
	char *path = __mystrdup(__mygetenv("PATH"));
	int ab = 0, xy = 0;
	char *path_tokens = strtok(path, ":");
	char *path_array[100];
	char *s2 = command;
	char *new_path = NULL;
	struct stat buf;

	new_path = malloc(sizeof(char) * 100);
	if (__mygetenv("PATH")[0] == ':')
		if (stat(command, &buf) == 0)
			return (__mystrdup(command));
	while (path_tokens != NULL)
	{
		path_array[ab++] = path_tokens;
		path_tokens = strtok(NULL, ":");
	}
	path_array[ab] = NULL;
	for (xy = 0; path_array[xy]; xy++)
	{
		__mystrcpy(new_path, path_array[xy]);
		__mystrcat(new_path, "/");
		__mystrcat(new_path, s2);
		__mystrcat(new_path, "\0");

		if (stat(new_path, &buf) == 0)
		{
			free(path);
			return (new_path);
		}
		else
			new_path[0] = 0;
	}
	free(path);
	free(new_path);

/* This is for after PATH checked and cmd is there locally */
	if (stat(command, &buf) == 0)
		return (__mystrdup(command));
	return (NULL);
}
