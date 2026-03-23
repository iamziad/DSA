#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#include "../include/array.h"

typedef int32_t i32;

struct Array{
    i32 *data;
    size_t size;
    size_t length;
    bool search_ranking;
};

Array *array_create(const size_t size, const bool search_ranking) {
    Array *a = malloc(sizeof(Array));
    if (!a) {
        fprintf(stderr, "array_create: couldn't allocate memory for array object\n");
        exit(1);
    }

    a->data = malloc(sizeof(i32) * size);
    if (!a->data) {
        fprintf(stderr, "array_create: couldn't allocate memory for array data\n");
        free(a);
        exit(1);
    }
    
    a->length = 0;
    a->size = size;
    a->search_ranking = search_ranking;

    return a;
}

void array_free(Array *a) {
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

    a->data[idx] = val;
    a->length++;
}

i32 array_get(const Array *a, const size_t idx) {
    if (!a) {
        fprintf(stderr, "array_get: received null pointer.\n");
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

    for (size_t i = idx; i <= a->length; i++) {
        a->data[i] = a->data[i + 1];
    }

    a->length--;
}

void array_append(Array *a, const i32 val) {
    if (!a) {
        fprintf(stderr, "array_display: received null pointer.\n");
        exit(1);
    }

    a->data[a->length] = val;
    a->length++;
}

i32 array_search(Array *a, const i32 val) {
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
