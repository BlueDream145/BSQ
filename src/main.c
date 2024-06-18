/*
** EPITECH PROJECT, 2017
** main.c
** File description:
**
*/

#include "bsq.h"

int main(int ac, char **as)
{
	const char *error_usage = "Bad usage.\n";
	struct file *file = get_file_instance();
	char *file_path;

	if (ac != 2)
		report_error(error_usage);
	file_path = as[1];
	serialize_file(file_path, file);
	process_file(file);
	display_file(file);
	free(file);
}