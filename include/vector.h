// libvector - simple dynamic array (vector) library for C by NDRAEY.

#pragma once

#include <stdbool.h>


typedef struct vector {
	size_t* data;

	size_t size;
	size_t capacity;
} vector_t;

typedef struct vector_result {
	bool error;
	size_t element;
} vector_result_t;

#define VEC_ERR (vector_result_t){true, 0}
#define VEC_OK(value) (vector_result_t){false, value}

vector_t* vector_new();
void vector_resize(vector_t* vec, size_t size);
void vector_push_back(vector_t* vec, size_t element);
vector_result_t vector_pop_back(vector_t* vec);
vector_result_t vector_get(vector_t* vec, size_t index);
vector_result_t vector_erase_nth(vector_t* vec, size_t n);
void vector_erase_all(vector_t* vec);
void vector_shrink_fit(vector_t* original);
void vector_swap(vector_t* vec, size_t first, size_t second);
vector_t* vector_clone(vector_t* original);
void vector_destroy(vector_t* vec);

// Debug functions
#include <stdio.h>

static inline void vector_print_like_unsigned_decimal(vector_t* vec) {
	printf("[");

	for(size_t i = 0; i < vec->size; i++) {
		printf("%zu", vec->data[i]);

		if(i + 1 < vec->size)
			printf(", ");
	}

	printf("]\n");
}

static inline void vector_print_like_unsigned_hexadecimal(vector_t* vec) {
	printf("[");

	for(size_t i = 0; i < vec->size; i++) {
		printf("%zx", vec->data[i]);

		if(i + 1 < vec->size)
			printf(", ");
	}

	printf("]\n");
}
