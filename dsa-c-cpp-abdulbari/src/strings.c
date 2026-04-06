#include "../include/strings.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>

typedef int32_t i32;

char *reverse_str_im(char *src) {
    size_t i = 0;

    while(src[i] != 0) {
        i++;
    }

    char *buf = malloc(sizeof(char*) * i);
    size_t j = 0;

    while(i > 0) {
        buf[j] = src[i - 1];
        i--;
        j++;
    }

    buf[j + 1] = 0;
    return buf;
}

void reverse_str_m(char *str) {
    if (!str || str[0] == 0) return;

    size_t i = 0;
    size_t length = 0;

    while(str[length] != 0) length++;

    size_t last_idx = length - 1;

    while(i < last_idx) {

        if (str[i] != str[last_idx]) {
            char c = str[i];
            str[i] = str[last_idx];
            str[last_idx] = c;
        }
        i++;
        last_idx--;
    }
}

void print_duplicates_hashtable(char *str) {
    int ht[26] = {0};
    size_t i = 0;

    while(str[i] != 0) {
        ht[str[i] - 97]++;
        i++;
    }

    for (size_t i = 0; i < 26; i++) {
        if (ht[i] > 0) {
            printf("%c = %d\n", (char)i + 97, ht[i]);
        }
    }
}

/* This algorithm uses less space O(1) than the hash table approach
   however it only prints the duplicates, but cannot count them */
void print_duplicates_bitwise(char *str) {
    i32 bitmask = 0;
    i32 duplicates = 0;
    size_t i = 0;

    while(str[i] != 0) {
        bitmask = 1;
        bitmask = bitmask << (str[i] - 97);

        if (bitmask & duplicates) {
            printf("%c\n", str[i]);
        } else {
            duplicates = (duplicates | bitmask);
        }

        i++;
    }
}
