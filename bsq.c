/*
** EPITECH PROJECT, 2019
** CPE_BSQ_2019
** File description:
** bsq
*/

#include "bsq.h"
#include "my.h"

int bsq(char *filename)
{
    file_data_t *file;
    board_t *board;

    file = read_file(filename);
    if (file == NULL)
        return 84;
    if (file->lines == 1 || file->column == 2)
        resolve_line(file);
    else {
        board = create_board(file);
        if (board == NULL)
            return 84;
        resolve(board);
        display_result(board, file);
        free(board->b);
        free(board);
    }
    free(file->buffer);
    free(file);
    return 0;
}
