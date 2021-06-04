#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define STACK_DEPTH 30000
#define DAY_NUM 30000

struct stack {
        int array[STACK_DEPTH];
        int top;
};

static void push(struct stack *st, int index)
{
        st->array[st->top] = index;
        st->top++;
}

static void pop(struct stack *st)
{
        st->top--;
}

static int get_top_val(struct stack *st)
{
        return st->array[st->top - 1];
}

static bool is_empty(struct stack *st)
{
        return !st->top ? true : false;
}

struct stack st;
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *dailyTemperatures(int *T, int TSize, int *returnSize)
{
        int *result;
        int i;
        int p;

        if (!T || TSize < 1 || TSize > DAY_NUM || !returnSize)
                return NULL;

        result = calloc(TSize, sizeof(int));
        if (!result)
                return NULL;

        for (i = 0; i < TSize; i++) {
                if (is_empty(&st)) {
                        push(&st, i);
                } else {
                        while (!is_empty(&st) && (T[get_top_val(&st)] < T[i])) {
                                result[get_top_val(&st)] = i - get_top_val(&st);
                                pop(&st);
                        }
                        push(&st, i);
                }
        }

        while (!is_empty(&st)) {
                p = get_top_val(&st);
                result[p] = 0;
                pop(&st);
        }

        *returnSize = TSize;
        return result; 
}

int main()
{
    int T[8] = {73, 74, 75, 71, 69, 72, 76, 73};
    int returnSize;
    int *result;
    int i;

    result = dailyTemperatures(T, 8, &returnSize);

    for (i = 0; i < 8; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    return 0;
}
