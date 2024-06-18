/*
** EPITECH PROJECT, 2017
** my_get.c
** File description:
**
*/

#include "bsq.h"

struct file *get_file_instance(void)
{
	struct file *f = malloc(sizeof(struct file));

	if (f == NULL)
		report_error("Fatal error: malloc failed.\n");
	return (f);
}

struct cell get_cell_instance(int id, int x, int y, int value)
{
	struct cell cell;

	cell.id = id;
	cell.x = x;
	cell.y = y;
	cell.value = value;
	return (cell);
}

struct cell fill_cell_instance(struct cell cell, struct file *file, char c)
{
	file->content[cell.id] = get_cell_instance(
	cell.id, cell.x, cell.y, get_obstacle_value(c));
	cell.x++;
	cell.id++;
	return (cell);
}