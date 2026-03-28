#ifndef ARRAY_H
#define ARRAY_H

#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

typedef uint32_t u32;
typedef uint64_t u64;
typedef int64_t i64;
typedef int32_t i32;
typedef uint8_t u8;

typedef struct Array Array;

Array *array_create(const size_t size, const bool search_ranking, bool unique);
void array_free(Array *a);
void array_set(Array *a, const size_t idx, const i32 val);
i32 array_get(const Array *a, const size_t idx);
void array_display(const Array *a);
void array_append(Array *a, const i32 val);
void array_delete(Array *a, const size_t idx);
i32 array_max(const Array *a);
i32 array_min(const Array *a);
i32 array_head(const Array *a);
i32 array_tail(const Array *a);
i32 array_search(Array *a, const i32 val);
i32 array_bsearch(const Array *a, const i32 val);
void array_sort(Array *a);
bool array_is_sorted(const Array *a);
void array_reverse(Array *a);
void array_lshift(Array *a, size_t n);
Array *array_merge(Array *src1, Array *src2);
Array *array_union(Array *src1, Array *src2);
Array *array_intersec(Array *src1, Array *src2);
i32 array_missing(Array *a);
Array *array_missings(Array *a);
Array *array_fmissings(Array *a, i32 greater_elm);
Array *array_duplicates(Array *a, i32 greater_elm);
Array *array_sorted_duplicates(Array *a);
Array *array_min_max(Array *a);

#endif
