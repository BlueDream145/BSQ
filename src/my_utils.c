/*
** EPITECH PROJECT, 2017
** my_utils.c
** File description:
**
*/

#include "bsq.h"

void get_file_content(struct file *file, const char *file_path)
{
	const char *error_open = "Can't open file.\n";
	struct stat info;
	int status = stat(file_path, &info);
	int fd = open(file_path, O_RDONLY);
	char *buff;
	int offset = 0;

	if (fd <= 0 || status != 0)
		report_error(error_open);
	file->file_size = info.st_size;
	buff = malloc(sizeof(char) * file->file_size);
	while (read(fd, buff + offset, 4096) > 0)
		offset += 4096;
	close(fd);
	file->file_content = buff;
}

int get_obstacle_value(char c)
{
	if (c == '.')
		return (1);
	else
		return (0);
}

int my_getnbr(char *str)
{
	int val = 0;

	while (*str) {
		if (*str >= '0' && *str <= '9') {
			val *= 10;
			val += *str - '0';
		}
		else
			return (val);
		str++;
	}
	return (val);
}