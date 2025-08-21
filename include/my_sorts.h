#pragma once

#include <stddef.h>

typedef int (*edu_cmp)(const void *, const void *);

void edu_bubble_sort(void *ptr, size_t count, size_t size, edu_cmp cmp);

void edu_selection_sort(void *ptr, size_t count, size_t size, edu_cmp cmp);

void edu_insertion_sort(void *ptr, size_t count, size_t size, edu_cmp cmp);

void edu_shell_sort(void *ptr, size_t count, size_t size, edu_cmp cmp);

void edu_quick_sort(void *ptr, size_t count, size_t size, edu_cmp cmp);
