/*
** EPITECH PROJECT, 2017
** my_engine.c
** File description:
**
*/

#include "bsq.h"

void process_file(struct file *file_inst)
{
	int cells_count = file_inst->file_height * file_inst->file_width;
	struct cell biggest_cell;
	int i;

	if (file_inst->file_width == 1 || file_inst->file_height == 1)
		fill_first_entry(file_inst);
	for (i = file_inst->file_width + 1; i < cells_count; i++) {
		if (i != 0 && i % file_inst->file_width == 0)
			continue;
		process_value(file_inst, i);
	}
	biggest_cell = process_biggest(file_inst);
	if (biggest_cell.id == 0) {
		display_file(file_inst);
		exit(0);
	}
	else
		process_result(biggest_cell, file_inst);
}

void process_value(struct file *file, int i)
{
	struct cell curr = file->content[i];
	struct cell left = file->content[i - 1];
	struct cell top = file->content[i - file->file_width];
	struct cell dia = file->content[i - file->file_width - 1];

	if (curr.value < 1 || left.value < 1 ||
	top.value < 1 || dia.value < 1)
		return;
	if (curr.value == left.value && left.value == top.value)
		file->content[i].value = top.value + 1;
	else
		if (left.value <= top.value && left.value <= dia.value)
			file->content[i].value = left.value + 1;
		else if (top.value <= left.value && top.value <= dia.value)
			file->content[i].value = top.value + 1;
		else
			file->content[i].value = dia.value + 1;
}

struct cell process_biggest(struct file *file_inst)
{
	int biggest_index = 0;
	int biggest_value = -1;
	int i;
	int cells_count = file_inst->file_height * file_inst->file_width;

	for (i = 0; i < cells_count; i++)
		if (file_inst->content[i].value > biggest_value) {
			biggest_value = file_inst->content[i].value;
			biggest_index = i;
		}
	return (file_inst->content[biggest_index]);
}

void process_result(struct cell biggest_cell, struct file *file_inst)
{
	int size = biggest_cell.value;
	int y = 0;
	int i;

	file_inst->square_size = (size * size) * 9;
	for (i = biggest_cell.id; y < size; i--) {
		if (i <= biggest_cell.id -
		(size + file_inst->file_width * y)) {
			y++;
			i = biggest_cell.id - (file_inst->file_width * y);
		}
		if (y < size && i > biggest_cell.id -
		(size + file_inst->file_width * y))
			file_inst->content[i].value = -1;
	}
}

void set_content_file(struct file *file_instance)
{
	file_instance->content = malloc(sizeof(struct cell) *
	file_instance->file_height * (file_instance->file_width + 1));
	if (file_instance->content == NULL)
		report_error("Fatal error: malloc failed.\n");
}