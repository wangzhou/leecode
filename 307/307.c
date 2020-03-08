typedef struct {
#define SIZE 1000
        int arr[SIZE];
        int *nums;
        int size;
} NumArray;

int build_tree(int *nums, int begin, int end, NumArray *obj, int root_pos)
{
        int left, right;

        if (begin == end) {
                obj->arr[root_pos] = nums[begin];
                return nums[begin];
        }

        left = build_tree(nums, begin, (end - begin) / 2, obj, 2 * root_pos + 1);
        right = build_tree(nums, (end - begin) / 2 + 1, end, obj, 2 * root_pos + 2);
        obj->arr[root_pos] = left + right;
        
        return left + right;
}

NumArray *numArrayCreate(int *nums, int numsSize)
{
        NumArray *ret;

        if (!nums || !numsSize)
                return NULL;

        ret = malloc(sizeof(NumArray));
        if (!ret)
                return NULL;

        ret->size = numsSize;
        ret->nums = nums;

        build_tree(nums, 0, numsSize - 1, ret, 0);        

        return ret;
}

int update(int *nums, int begin, int end, int i, int val, int *arr, int pos)
{
        int fix, tmp;

        if (begin == end) {
                arr[begin] = val;
                return val;
        }

        if (i <= (end - begin) / 2) {
                fix = update(nums, begin, (end - begin) / 2, i, val, arr, 2 * pos + 1);
                tmp = arr[2 * pos + 2];
        } else {
                fix = update(nums, (end - begin) / 2 + 1, end, i, val, arr, 2 * pos + 2);
                tmp = arr[2 * pos + 1];
        }

        arr[pos] = fix + tmp;
        return arr[pos];
}

void numArrayUpdate(NumArray *obj, int i, int val)
{
        update(obj->nums, 0, obj->size - 1, i, val, obj->arr, 0);
}

int sum(int *nums, int begin, int end, int i, int j, int *arr, int pos)
{
        int op1, op2;

        if ((begin == i && end == j) || (begin == end))
                return arr[pos];

        if (j <= (end - begin) / 2) {
                op2 = 0;
                op1 = sum(nums, begin, (end - begin) / 2, i, j, arr, 2 * pos + 1);
        } else if (i > (end - begin) / 2) {
                op1 = 0;
                op2 = sum(nums, (end - begin) / 2 + 1, end, i, j, arr, 2 * pos + 2);
        } else {
                op1 = sum(nums, begin, (end - begin) / 2, i, (end - begin) / 2, arr, 2 * pos + 1);
                op2 = sum(nums, (end - begin) / 2 + 1, end, (end - begin) / 2 + 1, j, arr, 2 * pos + 2);
        }

        return op1 + op2;
}

int numArraySumRange(NumArray *obj, int i, int j)
{
        return sum(obj->nums, 0, obj->size - 1, i, j, obj->arr, 0);
}

void numArrayFree(NumArray *obj)
{
        free(obj);
}

/**
 * Your NumArray struct will be instantiated and called as such:
 * NumArray* obj = numArrayCreate(nums, numsSize);
 * numArrayUpdate(obj, i, val);
 * int param_2 = numArraySumRange(obj, i, j);
 * numArrayFree(obj);
 */
