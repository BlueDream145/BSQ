/*
** EPITECH PROJECT, 2017
** my_color.c
** File description:
**
*/

#include "bsq.h"

int manage_color(char *result, int n)
{
	n = add_green_color(result, n);
	result[n] = 'x';
	n++;
	n = reset_color(result, n);
	n--;
	return (n);
}

int add_green_color(char *result, int n)
{
	const char *green = "\x1B[32m";
	int i;

	for (i = 0; i < 5; i++)
		result[n + i] = green[i];
	return (n + 5);
}

int reset_color(char *result, int n)
{
	const char *reset = "\033[0m";
	int i;

	for (i = 0; i < 4; i++)
		result[n + i] = reset[i];
	return (n + 4);
}

void display_file_colored(struct file *file)
{
	int i;
	int n = 0;
	int cells_count = file->file_height * file->file_width;
	int result_count = cells_count + file->file_height + file->square_size;
	char *result = malloc(sizeof(char) * result_count);

	for (i = 0; i < cells_count; i++) {
		if (i != 0 && i % file->file_width == 0) {
			result[n] = '\n';
			n++;
		}
		if (file->content[i].value == 0)
			result[n] = 'o';
		else if (file->content[i].value >= 1)
			result[n] = '.';
		else
			n = manage_color(result, n);
		n++;
	}
	write(1, result, result_count);
	my_put_char('\n');
}