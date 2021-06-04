/* just for leetcode test */
#define S_DEP 1001
#define MAX_INPUT 1000

int stack[S_DEP];
int top = 0;

static void push(int a)
{
    stack[top] = a;
    top++;
}

static void pop(void)
{
    top--;
}

static int get_top_val(void)
{
    return stack[top - 1];
}

static void clear_stack(void)
{
    top = 0;
}

static bool is_empty(void)
{
    return !top ? true : false;
}

bool validateStackSequences(int* pushed, int pushedSize, int* popped, int poppedSize)
{
    int cur_push, cur_pop;

    if (!pushed || !popped || pushedSize < 0 ||
        pushedSize > MAX_INPUT || poppedSize < 0 || poppedSize > MAX_INPUT)
        return false;

    cur_push = 0;
    cur_pop = 0;

    while (cur_push < pushedSize && cur_pop < poppedSize) {
        while (cur_push < pushedSize && pushed[cur_push] != popped[cur_pop]) {
            push(pushed[cur_push]);
            cur_push++;
        }
        if (cur_push == pushedSize) {
            cur_pop++;
        } else {
            cur_push++;   
            cur_pop++;
        }

        while (!is_empty() && cur_pop < poppedSize && get_top_val() == popped[cur_pop]) {
            pop();
            cur_pop++;
        }
    } 

    clear_stack();

    if (cur_push == pushedSize && cur_pop == poppedSize && is_empty())
        return true;

    return false;
}