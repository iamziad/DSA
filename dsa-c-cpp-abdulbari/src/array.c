#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <limits.h>

#include "../include/array.h"

typedef int32_t i32;
typedef uint32_t u32;
typedef int64_t i64;
typedef uint64_t u64;

struct Array{
    i32 *data;
    size_t size;
    size_t length;
    bool search_ranking;
    bool unique;
};

Array *array_create(const size_t size, const bool search_ranking, bool unique) {
    Array *a = calloc(1, sizeof(Array));
    if (!a) {
        fprintf(stderr, "array_create: couldn't allocate memory for array object\n");
        exit(1);
    }

    a->data = calloc(size, sizeof(i32));
    if (!a->data) {
        fprintf(stderr, "array_create: couldn't allocate memory for array data\n");
        free(a);
        exit(1);
    }
    
    a->length = 0;
    a->size = size;
    a->search_ranking = search_ranking;
    a->unique = unique;

    return a;
}

void array_free(Array *a) {
    if (!a) {
        fprintf(stderr, "array_free: recieved null pointer\n");
        exit(1);
    }
    free(a->data);
    free(a);
    printf("array_free: array object is freed successfully.\n");
}

void array_set(Array *a, const size_t idx, const i32 val) {
    if (!a) {
        fprintf(stderr, "array_set: recevied null pointer.\n");
        exit(1);
    }

    if (idx >= a->size) {
        fprintf(stdout, "array_set: exceeded boundary.\n");
        exit(1);
    }

    if (a->unique) {
        for (size_t i = 0; i < a->length; i++) {
            if (a->data[i] == a->data[idx]) return;
        }
    }

    a->data[idx] = val;

    if (idx >= a->length) {
        a->length = idx + 1;
    }
}

i32 array_get(const Array *a, const size_t idx) {
    if (!a) {
        fprintf(stderr, "array_get: received null pointer.\n");
        exit(1);
    }

    if (idx >= a->size) {
        fprintf(stderr, "array_get: exceeded boundary.\n");
        exit(1);
    }

    return a->data[idx];
}

void array_display(const Array *a) {
    if (!a) {
        fprintf(stderr, "array_display: received null pointer.\n");
        exit(1);
    }

    printf("Data: {");
    for (size_t i = 0; i < a->size; i++) {
        printf(" %d ", a->data[i]);
    }
    printf("}\n");

    printf("Size: %zu\n", a->size);
    printf("Length: %zu\n", a->length);
}

void array_delete(Array *a, const size_t idx) {
    if (!a) {
        fprintf(stderr, "array_display: received null pointer.\n");
        exit(1);
    }

    for (size_t i = idx; i < a->length; i++) {
        a->data[i] = a->data[i + 1];
    }

    a->length--;
}

void array_append(Array *a, const i32 val) {
    if (!a) {
        fprintf(stderr, "array_display: received null pointer.\n");
        exit(1);
    }

    if (a->unique) {
        for (size_t i = 0; i < a->length; i++) {
            if (a->data[i] == val) return;
        }
    }

    if (a->length == a->size) {
        a->data[a->length - 1] = val;
    } else {
        a->data[a->length] = val;
        a->length++;
    }

}

i32 array_search(Array *a, const i32 val) {
    if (!a) {
        fprintf(stderr, "array_search: received null pointer.\n");
        exit(1);
    }

    if (a->length == 0) {
        fprintf(stderr, "array_search: array doesn't have elements to search for.\n");
        exit(1);
    }

    for (size_t i = 0; i < a->length; i++) {
        if (a->data[i] == val) {
            if (a->search_ranking && i > 0) {
                i32 tmp = a->data[i];
                a->data[i] = a->data[i - 1];
                a->data[i - 1] = tmp;
                return (i32)(i - 1);
            }
            return (i32)i;
        }
    }
    return -1;
}

i32 array_max(const Array *a) {
    i32 max = a->data[0];
    for (size_t i = 1; i < a->length; i++) {
        if (a->data[i] > max) {
            max = a->data[i];
        }
    }
    return max;
}


i32 array_min(const Array *a) {
    i32 min = a->data[0];
    for (size_t i = 1; i < a->length; i++) {
        if (a->data[i] < min) {
            min = a->data[i];
        }
    }
    return min;
}

i32 array_head(const Array *a) {
    if (!a) {
        fprintf(stderr, "array_head: received null pointer.\n");
        exit(1);
    }

    return a->data[0];
}

i32 array_tail(const Array *a) {
    if (!a) {
        fprintf(stderr, "array_tail: received null pointer.\n");
        exit(1);
    }

    return a->data[a->length - 1];
}

i32 array_bsearch(const Array *a, const i32 val) {
    if (!a) {
        fprintf(stderr, "array_bsearch: received null pointer.\n");
        exit(1);
    }

    if (a->length == 0) {
        fprintf(stderr, "array_bsearch: array doesn't have elements to search for.\n");
        exit(1);
    }

    i32 head = 0;
    i32 tail = (i32)a->length - 1;

    while (head <= tail) {
        i32 mid = head + (tail - head) / 2;

        if (val == a->data[mid]) {
            return mid;
        } else if (val < a->data[mid]) {
            tail = mid - 1;
        } else {
            head = mid + 1;
        }
    }

    return -1;
}

void array_sort(Array *a) {
    for (size_t i = 0; i < a->length - 1; i++) {
        size_t min = i;

        for (size_t j = i + 1; j < a->length; j++) {
            if (a->data[min] > a->data[j]) {
                min = j;
            }
        }

        if (min != i) {
            i32 tmp = a->data[i];
            a->data[i] = a->data[min];
            a->data[min] = tmp;
        }
    }
}

void array_reverse(Array *a) {
    size_t head = 0;
    size_t tail = a->length - 1;

    while(head < tail) {
        i32 tmp = a->data[head];
        a->data[head] = a->data[tail];
        a->data[tail] = tmp;

        head++;
        tail--;
    }
}

bool array_is_sorted(const Array *a) {
    for (size_t i = 0; i < a->length - 1; i++) {
        if (a->data[i] > a->data[i + 1]) {
            return false;
        }
    }
    return true;
}

void array_fill(Array *a, i32 n) {
    for (size_t i = 0; i < a->length; i++)  {
        a->data[i] = n;
    }
}

void array_lshift(Array *a, size_t n) {
    if (n >= a->length) {
        array_fill(a, 0);
    }

    for (size_t i = 0; i < a->length - n; i++) {
        a->data[i] = a->data[i + n];
    }

    for (size_t i = a->length - n; i < a->length; i++) {
        a->data[i] = 0;
    }
}

Array *array_merge(Array *src1, Array *src2) {
    Array *dest = array_create(src1->length + src2->length, false, true);

    size_t i = 0;
    size_t j = 0;
    size_t k = 0;

    while(i < src1->length && j < src2->length) {
        if (src1->data[i] < src2->data[j]) {
            dest->data[k++] = src1->data[i++];
        } else {
            dest->data[k++] = src2->data[j++];
        } 
    }

    while(i < src1->length) {
        dest->data[k++] = src1->data[i++];
    }

    while(j < src2->length) {
        dest->data[k++] = src2->data[j++];
    }

    dest->length = src1->length + src2->length;

    return dest;
}

Array *array_union(Array *src1, Array *src2) {
    Array *dest = array_create(src1->length + src2->length, false, false);

    size_t i = 0;
    size_t j = 0;
    size_t k = 0;

    while(i < src1->length && j < src2->length) {
        if (src1->data[i] < src2->data[j]) {
            dest->data[k++] = src1->data[i++];
            dest->length++;
        } else if (src1->data[i] > src2->data[j]) {
            dest->data[k++] = src2->data[j++];
            dest->length++;
        } else {
            dest->data[k++] = src1->data[i++];
            j++;
            dest->length++;
        }
    }

    while (i < src1->length) {
        dest->data[k++] = src1->data[i++];
        dest->length++;
    }

    while (j < src2->length) {
        dest->data[k++] = src2->data[j++];
        dest->length++;
    }

    return dest;

}

Array *array_intersec(Array *src1, Array *src2) {
    Array *dest = array_create(src1->length + src2->length, false, false);

    size_t i = 0;
    size_t j = 0;
    size_t k = 0;

    while(i < src1->length && j < src2->length) {
        if (src1->data[i] < src2->data[j]) {
            i++;
        } else if(src1->data[i] > src2->data[j]) {
            j++;
        } else {
            dest->data[k++] = src1->data[i++];
            dest->length++;
        }
    }

    return dest;
}

i32 array_missing(Array *a) {
    i32 expected_idx_val_diff = a->data[0] - 0;

    for (size_t i = 0; i < a->length; i++) {
        if ((size_t)a->data[i] - i != (size_t)expected_idx_val_diff) {
            return a->data[i] - 1;
        }
    }

    return 0;
}

Array *array_missings(Array *a) {
    Array *missings = array_create(a->size, false, false);

    i32 expected_diff = a->data[0] - 0;

    for (size_t i = 0; i < a->length; i++) {
        i32 curr_elm = a->data[i];
        size_t curr_diff = (size_t)curr_elm - i;

        if (curr_diff != (size_t)expected_diff) {
            while((size_t)expected_diff < curr_diff) {
                array_append(missings, i + expected_diff);
                expected_diff++;
            }
        }
    }

    return missings;
}

Array *array_fmissings(Array *a, i32 greater_elm) {
    Array *ht = array_create(greater_elm + 1, false, false);
    Array *ret = array_create(greater_elm, false, false);

    for (size_t i = 0; i < a->length; i++) {
        array_set(ht, a->data[i], 1);
    }

    for (size_t i = 1; i < ht->size; i++) {
        if (ht->data[i] == 0) {
            array_append(ret, i);
        }
    }

    return ret;
}

Array *array_duplicates(Array *a, i32 greater_elm) {
    Array *ht = array_create(greater_elm + 1, false, false);
    Array *duplicates = array_create(greater_elm, false, false);

    for (size_t i = 0; i < a->length; i++) {
        i32 key = array_get(a, i);
        i32 val = array_get(ht, key);
        array_set(ht, key, val + 1);
    }

    for (size_t i = 0; i < ht->length; i++) {
        i32 count = array_get(ht, i);
        if (count > 1) {
            array_append(duplicates, i);
        }
    }

    return duplicates;
}

Array *array_sorted_duplicates(Array *a) {
    Array *duplicates = array_create(a->length, false, false);
    i32 last_duplicate = 0;

    for (size_t i = 0; i < a->length - 1; i++) {
        if (array_get(a, i) == array_get(a, i + 1) && array_get(a, i) != last_duplicate) {
            last_duplicate = array_get(a, i);
            array_append(duplicates, last_duplicate);
        }
    }

    return duplicates;
}


Array *array_min_max(Array *a) {
    Array *min_max = array_create(2, false, false);

    i32 min = a->data[0];
    i32 max = a->data[0];

    for (size_t i = 0; i < a->length; i++) {
        if (a->data[i] < min) {
            min = a->data[i];
        } else if(a->data[i] > max) {
            max = a->data[i];
        }
    }

    array_append(min_max, min);
    array_append(min_max, max);

    return min_max;
}
