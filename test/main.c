#include "criterion/criterion.h"
#include "edu_sorts.h"

#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

const size_t arr_len = 1000;
const int num_max = 1000;

// TODO: add tests for already sorted and all equals arrs

// helper funcs

static bool edu_is_sorted(void *ptr, size_t count, size_t size, edu_cmp cmp) {
    const char *arr = ptr;
    for (size_t i = 1; i < count; ++i) {
        const void *val1 = arr + (i - 1) * size;
        const void *val2 = arr + i * size;
        if (cmp(val1, val2) > 0) {
            return false;
        }
    }
    return true;
}

static int edu_cmp_int(const void *lhs, const void *rhs) {
    return *(int *) lhs - *(int *) rhs;
}

static int *edu_gen_arr(void) {
    int *arr = malloc(arr_len * sizeof(int));
    if (!arr) {
        return NULL;
    }
    for (size_t i = 0; i < arr_len; ++i) {
        arr[i] = rand() % num_max;
    }
    return arr;
}

// tests

Test(bubble_sort, basic) {
    srand(time(NULL));
    int *arr = edu_gen_arr();

    edu_bubble_sort(arr, arr_len, sizeof(int), edu_cmp_int);

    cr_assert(edu_is_sorted(arr, arr_len, sizeof(int), edu_cmp_int));
    free(arr);
}

Test(selection_sort, basic) {
    srand(time(NULL));
    int *arr = edu_gen_arr();

    edu_selection_sort(arr, arr_len, sizeof(int), edu_cmp_int);

    cr_assert(edu_is_sorted(arr, arr_len, sizeof(int), edu_cmp_int));
    free(arr);
}

Test(insertion_sort, basic) {
    srand(time(NULL));
    int *arr = edu_gen_arr();

    edu_insertion_sort(arr, arr_len, sizeof(int), edu_cmp_int);

    cr_assert(edu_is_sorted(arr, arr_len, sizeof(int), edu_cmp_int));
    free(arr);
}

Test(shell_sort, basic) {
    srand(time(NULL));
    int *arr = edu_gen_arr();

    edu_shell_sort(arr, arr_len, sizeof(int), edu_cmp_int);

    cr_assert(edu_is_sorted(arr, arr_len, sizeof(int), edu_cmp_int));
    free(arr);
}

Test(quick_sort, basic) {
    srand(time(NULL));
    int *arr = edu_gen_arr();

    edu_quick_sort(arr, arr_len, sizeof(int), edu_cmp_int);

    cr_assert(edu_is_sorted(arr, arr_len, sizeof(int), edu_cmp_int));
    free(arr);
}
