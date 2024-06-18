/*
** EPITECH PROJECT, 2017
** bsq.h
** File description:
**
*/

#ifndef bsq_
#define bsq_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

struct file {
	int file_width;
	int file_height;
	struct cell *content;
	int square_size;
	int file_size;
	char *file_content;
};

struct cell {
	int id;
	int x;
	int y;
	int value;
};

// my_color.c
int manage_color(char *result, int n);
int add_green_color(char *result, int n);
int reset_color(char *result, int n);
void display_file_colored(struct file *file);

// my_engine.c
void process_file(struct file *file_inst);
void process_value(struct file *file, int i);
struct cell process_biggest(struct file *file_inst);
void process_result(struct cell biggest_cell, struct file *file_inst);
void set_content_file(struct file *file_instance);

// my_file.c
void serialize_file(const char *file_path, struct file *file_instance);
void display_file(struct file *file_instance);
void get_content_file(struct file *file_instance);
void set_width_file(struct file *file_instance);
void set_height_file(struct file *file_instance);

// my_get.c
struct file *get_file_instance(void);
struct cell get_cell_instance(int id, int x, int y, int value);
struct cell fill_cell_instance(struct cell cell, struct file *file, char c);

// my_put.c
int my_put_nbr(int nb);
void my_put_str(const char *str);
void my_put_char(char c);
char *my_strcat(char *dest, const char *src);

// my_report.c
void report_error(const char *str);
void fill_first_entry(struct file *file_inst);

// my_utils.c
void get_file_content(struct file *file, const char *file_path);
int get_obstacle_value(char c);
int my_getnbr(char *str);

#endif /* bsq_ */