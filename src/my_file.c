/*
** EPITECH PROJECT, 2017
** my_file.c
** File description:
**
*/

#include "bsq.h"

void serialize_file(const char *file_path, struct file *file_instance)
{
	get_file_content(file_instance, file_path);
	set_width_file(file_instance);
	set_height_file(file_instance);
	get_content_file(file_instance);
}

void display_file(struct file *file)
{
	int i;
	int n = 0;
	int cells_count = file->file_height * file->file_width;
	int result_count = cells_count + file->file_height - 1;
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
			result[n] = 'x';
		n++;
	}
	write(1, result, result_count);
	my_put_char('\n');
}

void get_content_file(struct file *file_instance)
{
	struct cell cell = get_cell_instance(0, 0, 0, 0);
	int c;
	int i;

	set_content_file(file_instance);
	for (i = 0; i < file_instance->file_size; i++) {
		c = file_instance->file_content[i];
		if (cell.value == 0 && c != '\n')
			continue;
		else if (cell.value == 0) {
			cell.value++;
			continue;
		}
		if (cell.value == 1 && c == '\n') {
			cell.y++;
			cell.x = 0;
			continue;
		} else if (cell.value == 1)
			cell = fill_cell_instance(cell, file_instance, c);
	}
}

void set_width_file(struct file *file_instance)
{
	int width = 0;
	int status = 0;
	int c;
	int i;

	for (i = 0; i < file_instance->file_size; i++) {
		c = file_instance->file_content[i];
		if (status == 0 && c != '\n')
			continue;
		else if (status == 0) {
			status++;
			continue;
		}
		if (status == 1 && c == '\n')
			status++;
		if (status == 1)
			width++;
	}
	file_instance->file_width = width;
}

void set_height_file(struct file *file_instance)
{
	int height = 0;
	int c;
	int i;

	for (i = 0; i < file_instance->file_size; i++) {
		c = file_instance->file_content[i];
		if (c >= '0' && c <= '9') {
			height *= 10;
			height += c - '0';
		}
		else
			break;
	}
	file_instance->file_height = height;
}