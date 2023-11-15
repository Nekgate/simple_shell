#include "simple_shell.h"

/**
 * __printenv - Custom printenv function
 *
 * Return: 0
 */
int __printenv(void)

{
	char *s = environ[0];
	int i = 0;

	while (s)
	{
		write(1, s, __mystrlen(s));
		write(1, "\n", 1);
		s = environ[++i];
	}
	return (0);
}

/**
 * __mystrncmp - Lexicographically compares not more than count chars
 * from two strings and returns an integer based on the result.
 * @s1: first string
 * @s2: second string to compare to first string
 * @n: count of the comparison between s1 and s2
 * Return: < 0 if s1 is less than s2, 0 for equal, > 0 if s1 is greater than s2
 * Description: Src code file like GNU C library
 */

int __mystrncmp(char *s1, char *s2, int n)
{
	char b1, b2;

	while (n--)
	{
		b1 = *s1++;
		b2 = *s2++;
		if (b1 == '\0' || b1 != b2)

			return (b1 > b2 ? 1 : (b1 < b2 ? -1 : 0));
	}
				return (0);
}

/**
 * __mygetenv - Custom getenv function
 * @var: Environment variable
 *
 * Return: Suceess (0)
 */

char *__mygetenv(char *var)
{
	int a = 0;

	for (a = 0; environ[a]; a++)
	{
		if (__mystrncmp(environ[a], var, __mystrlen(var)) == 0)
			return (&environ[a][__mystrlen(var)]);
	}
	return (NULL);
}
