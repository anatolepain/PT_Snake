#include "include/gameMap.h"

int spawnSnake(grid* grid, body* body)
{
    int i;
    position pos = {(unsigned char)(X_SIZE/2), (unsigned char)(Y_SIZE/2)};

    if(firstEnqueue(body, pos) == ALLOC_ERROR)
    {
        return ALLOC_ERROR;
    }
    setValue(grid, pos, 2);

    for (i = 0; i < INIT_SNAKE_SIZE - 1; i++)
    {
        pos.m_X += 1;
        if(enqueue(body, pos) == ALLOC_ERROR)
        {
            return ALLOC_ERROR;
        }
        setValue(grid, pos, 2);
        printf(" vvv %hhd\n", getValue(grid, pos));
    }
}

void destroySnake(body* body)
{
    int i;
    for (i = 0; i < body->m_size - 1; i++)
    {
        dequeue(body);
    }
    free(body->m_head);
    body->m_head = NULL;
    body->m_queue = NULL;
}

void spawnApple(grid* grid)
{
    position pos;
    while (getValue(grid, pos) != (unsigned char)GRASS)
    {
        pos = RandPos(grid);
    }
    setValue(grid, pos, (unsigned char)APPLE);
}

position RandPos(grid* grid)
{
    position pos;
    srand(time(NULL));
    pos.m_X = (unsigned char)((rand() % (X_SIZE - 2)) + 1);
    pos.m_Y = (unsigned char)((rand() % (Y_SIZE - 2)) + 1);
    return pos;
}