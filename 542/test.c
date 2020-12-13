/* very stupid, bugs fly :) */
#define Q_DEP 500

#define IS_WALL -1
#define IS_ZERO 0
#define IS_ONE 1

struct element {
        int x;
        int y;
        int d;
};

struct element q[Q_DEP] = {0};
int head = 0;
int tail = 0;

static void add_to_q(int x, int y, int d)
{
        q[tail].x = x;
        q[tail].y = y;
        q[tail].d = d;

        tail++;
}

static struct element *remove_from_q(void)
{
        int cur_head;        

        cur_head = head++;
        return &q[cur_head];
}

static void clear_q(void)
{
        head = 0;
        tail = 0;
}

static bool is_q_empty(void)
{
        return head == tail;        
}

/* up: 1, right: 2, down: 3, left: 4 */
/* return -1 if is wall or is one, return distance value if is zero */
static int is_zero(int **matrix, int matrixSize, int colsize, int i, int j, int dir, int dep)
{
        int x, y;

        x = i;
        y = j;  
        switch (dir) {
        case 1:
                x--;
                break;
        case 2:
                y++;
                break;
        case 3:
                x++;
                break;
        case 4:
                y--;
                break;
        }

        if (x < 0 || x >= matrixSize || y < 0 || y >= colsize) {
                return -1;
        } else if (matrix[x][y] == 1) {
                add_to_q(x, y, dep + 1);
                return -1;
        }
        
        return dep;
}

static int bfs(int **matrix, int matrixSize, int colsize, int i, int j)
{
        int dir;
        int is_find = 0;
        struct element * tmp;
        int r;

        add_to_q(i, j, 1);        

        /* find as the order of up->right->down->left */
        while (!is_find && !is_q_empty()) {
                tmp = remove_from_q();
                for (dir = 1; dir <= 4; dir++) {
                        r = is_zero(matrix, matrixSize, colsize, tmp->x, tmp->y, dir, tmp->d);
                        if (r == -1)
                                continue;
                        else {
                                is_find = 1;
                                goto find;
                        }
                }
        }

find:
        /* hack here :) */
        clear_q();
        return r;
}

static void find_zero(int **matrix, int matrixSize, int colsize, int **ret)
{
        int i, j;
        int d;

        for (i = 0; i < matrixSize; i++) 
                for (j = 0; j < colsize; j++) {
                        if (!matrix[i][j]) {
                                ret[i][j] = 0;
                        } else {
                                d = bfs(matrix, matrixSize, colsize, i, j);
                                ret[i][j] = d;
                        }
                }
}

int** updateMatrix(int** matrix, int matrixSize, int* matrixColSize, int* returnSize, int** returnColumnSizes)
{
        int **ret;
        int i;
        int colsize;
        int *col;

        if (!matrix || !matrixSize || !matrixColSize || !returnSize || !returnColumnSizes)
                return NULL;

        ret = calloc(matrixSize, sizeof(int *));
	if (!ret)
		return NULL;
        
        colsize = *matrixColSize;
	for (i = 0; i < matrixSize; i++) {
		ret[i] = calloc(colsize, sizeof(int));
		if (!ret[i])
                        /* fix me: release mem */
			return NULL;
	}

        find_zero(matrix, matrixSize, colsize, ret);

        col = calloc(matrixSize, sizeof(int));
        if (!col)
                /* fix me: release mem */
                return NULL;
        for (i = 0; i < matrixSize; i++)
                col[i] = colsize;

        *returnColumnSizes = col;
        *returnSize = matrixSize;
        return ret;
}
