#include "monty.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char **op_toks = NULL;

/**
 * main - the start of the programme
 *
 * @argc: the number of arguments
 * @argv: pointer to a pointer to an array of arguments
 *
 * Return: success or failure
 */
int main(int argc, char **argv)
{
	FILE *script_fd = NULL;
	int exit_code = EXIT_SUCCESS;

	if (argc != 2)
		return (usage_error());
	script_fd = fopen(argv[1], "r");
	if (script_fd == NULL)
		return (f_open_error(argv[1]));
	exit_code = play_monty(script_fd);
	fclose(script_fd);
	return (exit_code);
}
