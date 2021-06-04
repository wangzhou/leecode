#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <malloc.h>

#define QUEUE_LEN 1500

struct element {
        char *w;
        int d;
};

struct queue {
        struct element e[QUEUE_LEN];
        int tail;
        int head;
};

struct arrive_array {
        char **a;
        int pos;
};

static void produce_q(struct queue *q, char *w, int d)
{
        q->e[q->tail].w = w;
        q->e[q->tail].d = d;
        if (q->tail == QUEUE_LEN - 1)
                q->tail = 0;
        else
                q->tail++;
}

static struct element *consume_q(struct queue *q)
{
        int i;

        i = q->head;
        if (q->head == QUEUE_LEN - 1)
                q->head = 0;
        else
                q->head++;

        return q->e + i;
}

static bool is_q_empty(struct queue *q)
{
        return q->tail == q->head;
}

/* check if we can jump to i word */
static bool jump_to_word(char **wordList, char *w, int j)
{
        char *tmp = wordList[j];
        int diff = 0;
        int len;
        int i;

        len = strlen(w);
        for (i = 0; i < len; i++) {
                if (*tmp != *w)
                        diff++;
                tmp++;
                w++;
        }

        return diff == 1 ? true : false;
}

static bool is_arrive(struct arrive_array *array, char *w)
{
        int i;

        for (i = 0; i < array->pos; i++)
                if (array->a[i] == w)
                        return true;

        return false;
}

static void store_in_arrive(struct arrive_array *array, char *w)
{
        array->a[array->pos] = w;
        array->pos++;
}

int ladderLength(char *beginWord, char *endWord, char **wordList, int wordListSize)
{
        int is_find = 0;
        int i;
        struct element *tmp;
        char **once_arrive;
        struct arrive_array array;
        struct queue q = {0};

        if (!beginWord || !endWord || !wordList || !wordListSize)
                return 0;
	
	once_arrive = calloc(wordListSize, sizeof(char *));
        if (!once_arrive)
                return -1;
        array.a = once_arrive;
        array.pos = 0;

        produce_q(&q, beginWord, 1);

        while (!is_find && !is_q_empty(&q)) {
                tmp = consume_q(&q);
                for (i = 0; i < wordListSize; i++) {
                        if (!jump_to_word(wordList, tmp->w, i)) {
                                continue;
                        } else {
                                if (!strcmp(wordList[i], endWord)) {
                                        is_find = 1;        
                                        goto find;
                                }
                                if (is_arrive(&array, wordList[i]))
                                        continue;
                                produce_q(&q, wordList[i], tmp->d + 1);
                                store_in_arrive(&array, wordList[i]);
                        }
                }
        }
find:
        free(once_arrive);

        if (is_find)
                return tmp->d + 1;

        return 0;
}

int main()
{
        char *list[6] = {"hot", "dot", "dog", "lot", "log", "cog"};
        char *begin = "hit";
        char *end = "cog";

        char *list2[2] = {"hot", "dog"};
        char *begin2 = "hot";
        char *end2 = "dog";
        int num;

        printf("%s\n", list[0]);
        num = ladderLength(begin, end, list, 6);
        printf("jump: %d\n", num);

        num = ladderLength(begin2, end2, list2, 2);
        printf("jump2: %d\n", num);

        return 0;
}
