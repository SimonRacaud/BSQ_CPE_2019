/*
** EPITECH PROJECT, 2019
** CPE_BSQ_2019
** File description:
** header
*/

#ifndef H_BSQ
#define H_BSQ

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#define UINT unsigned int
typedef struct stat stat_t;

typedef struct board {
    unsigned int *sol;
    unsigned int x;
    unsigned int y;
    unsigned int *b;
} board_t;

typedef struct file_data {
    char *buffer;
    char *board_start;
    stat_t stat_file;
    unsigned int lines;
    unsigned int column;
} file_data_t;

int bsq(char *file_name);

int check_board(file_data_t *file);
board_t *create_board(file_data_t *file);
file_data_t *read_file(char *file_name);

void display_result(board_t *board, file_data_t *file);
void resolve(board_t *board);
void resolve_line(file_data_t *file);

#endif
