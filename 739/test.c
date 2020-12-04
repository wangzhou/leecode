#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>

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

        result = calloc(DAY_NUM, sizeof(int));
        if (!result)
                return NULL;

        for (i = 0; i < DAY_NUM; i++) {
                if (is_empty(&st)) {
                        push(&st, T[i]);
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

        return result; 
}

int main()
{

    return 0;
}
