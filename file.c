/*
** EPITECH PROJECT, 2019
** CPE_BSQ_2019
** File description:
** read the file (arg)
*/

#include "bsq.h"
#include "my.h"

#include <stdio.h>

board_t *create_board(file_data_t *file)
{
    board_t *board = malloc(sizeof(board_t));
    int i = -1;
    int j = 0;

    board->b = malloc(sizeof(UINT) * file->lines * (file->column - 1));
    if (board == NULL || board->b == NULL)
        return NULL;
    while (file->board_start[++i] != '\0') {
        if (file->board_start[i] == 'o')
            board->b[j] = 0;
        else if (file->board_start[i] == '.')
            board->b[j] = 1;
        if (file->board_start[i] != '\n')
            j++;
    }
    board->x = file->column - 1;
    board->y = file->lines;
    board->sol = NULL;
    return board;
}

static int check_board_content(file_data_t *file, char *board_ptr)
{
    unsigned int i_line = 0;
    unsigned int i_column = 0;
    int i = -1;

    while (board_ptr[++i] != '\0') {
        i_column++;
        if (board_ptr[i] == '\n' && i_line == 0)
            file->column = i_column;
        else if (board_ptr[i] == '\n' && file->column != i_column)
            return -1;
        if (board_ptr[i] == '\n') {
            i_line++;
            i_column = 0;
        } else if (board_ptr[i] != 'o' && board_ptr[i] != '.')
            return -1;
    }
    if (i_line != file->lines || i_column != 0)
        return -1;
    return 0;
}

int check_board(file_data_t *file)
{
    int i = -1;

    while (file->buffer[++i] != '\n') {
        if (file->buffer[i] < '0' || file->buffer[i] > '9') {
            my_putstr_error("ERROR: first line characters not digit\n");
            return -1;
        }
    }
    file->lines = my_getnbr(&file->buffer[0]);
    file->column = 0;
    if (i > 10 || file->lines < 1) {
        my_putstr_error("ERROR: first line length or nb of lines < 1\n");
        return -1;
    }
    file->board_start = file->buffer + i + 1;
    if (check_board_content(file, file->board_start) != 0) {
        my_putstr_error("ERROR: board content\n");
        return -1;
    }
    return 0;
}

file_data_t *read_file(char *file_name)
{
    file_data_t *file = malloc(sizeof(file_data_t));
    int fd = open(file_name, O_RDONLY);
    int ret;

    ret = stat(file_name, &file->stat_file);
    if (fd == -1 || ret != 0) {
        my_putstr_error("ERROR: open file\n");
        return NULL;
    }
    file->buffer = malloc(sizeof(char) * (file->stat_file.st_size + 1));
    ret = read(fd, file->buffer, (file->stat_file.st_size + 1));
    close(fd);
    if (ret == -1) {
        my_putstr_error("ERROR: read file\n");
        return NULL;
    }
    file->buffer[file->stat_file.st_size] = '\0';
    if (check_board(file) == -1)
        return NULL;
    return file;
}
