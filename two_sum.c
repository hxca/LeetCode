/**
 *
 * Given an array of integers, return indices of the two numbers such that they add up to a specific target.
 * You may assume that each input would have exactly one solution, and you may not use the same element twice.
 * Example:
 *         Given nums = [2, 7, 11, 15], target = 9,
 *         Because nums[0] + nums[1] = 2 + 7 = 9,
 *         return [0, 1].
 *
 */

/**
 * C solution in O(n) time, using open addressing hash table.
 */
#define SIZE 50000

int hash(int key)
{
    int r = key % SIZE;
    return r < 0 ? r + SIZE : r;
}

void insert(int* keys, int* values, int key, int value)
{
    int index = hash(key);
    while (values[index]) {
        index = (index + 1) % SIZE;
    }
    keys[index] = key;
    values[index] = value;
}

int search(int* keys, int* values, int key)
{
    int index = hash(key);
    while (values[index]) {
        if (keys[index] == key) {
            return values[index];
        }
        index = (index + 1) % SIZE;
    }
    return 0;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{

    *returnSize = 2;

    int keys[SIZE];
    int values[SIZE] = { 0 };
    for (int i = 0; i < numsSize; i++) {
        int complements = target - nums[i];
        int value = search(keys, values, complements);
        if (value) {
            int* indices = (int*)malloc(sizeof(int) * 2);
            indices[0] = value - 1;
            indices[1] = i;
            return indices;
        }
        insert(keys, values, nums[i], i + 1);
    }
    return NULL;
}