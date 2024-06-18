/*
** EPITECH PROJECT, 2017
** my_report.c
** File description:
**
*/

#include "bsq.h"

void report_error(const char *str)
{
	int len = 0;

	for (len = 0; str[len]; len++);
	write(2, str, len);
	exit(84);
}

void fill_first_entry(struct file *file_inst)
{
	int cells_count = file_inst->file_height * file_inst->file_width;
	int i;

	for (i = 0; i < cells_count; i++)
		if (file_inst->content[i].value >= 1) {
			file_inst->content[i].value = -1;
			display_file(file_inst);
			exit(0);
		}
	display_file(file_inst);
	exit(0);
}