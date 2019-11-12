/*
** EPITECH PROJECT, 2019
** CPE_BSQ_2019
** File description:
** resolve board
*/

#include "bsq.h"
#include "my.h"

static void write_solution(board_t *board, file_data_t *file)
{
    unsigned int width = *board->sol;
    unsigned int length = file->column;
    unsigned int i_board_sol = (board->sol - board->b);
    unsigned int i_sol = i_board_sol + (i_board_sol / board->x);

    for (unsigned int y = 0; y < width; y++) {
        for (unsigned int x = 0;x < width; x++) {
            *(((file->board_start + i_sol) - (y * length)) - x) = 'x';
        }
    }
}

void display_result(board_t *board, file_data_t *file)
{
    if (board->sol != NULL)
        write_solution(board, file);
    write(1, file->board_start, my_strlen(file->board_start));
}

static unsigned int min(uint_t const *a, uint_t const *b, uint_t const *c)
{
    unsigned int min = *a;

    if (min > *b)
        min = *b;
    if (min > *c)
        min = *c;
    return min;
}

void resolve(board_t *board)
{
    unsigned int size = board->x * board->y;
    unsigned int x = 2;
    unsigned int *a = &board->b[0];
    unsigned int *b = &board->b[1];
    unsigned int *c = &board->b[board->x];

    for (unsigned int i = board->x + 1; i < size; i++) {
        if (x != 1 && board->b[i] != 0)
            board->b[i] = min(a, b, c) + 1;
        if (x != 1 && (board->sol == NULL || board->b[i] > *(board->sol)))
            board->sol = (board->b + i);
        if (x == board->x) {
            x = 1;
        } else
            x++;
        a++;
        b++;
        c++;
    }
}

void resolve_line(file_data_t *file)
{
    int i = -1;

    while (file->board_start[++i] != '\0') {
        if (file->board_start[i] == '.') {
            file->board_start[i] = 'x';
            break;
        }
    }
    write(1, file->board_start, my_strlen(file->board_start));
}
