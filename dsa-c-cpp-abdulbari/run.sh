#!/bin/bash

gcc -Wall -Wextra -Wno-unused-function -g -o bin/main src/main.c $@ && bin/./main
