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

vector_t* vector_new();
void vector_resize(vector_t* vec, size_t size);
void vector_push_back(vector_t* vec, size_t element);
vector_result_t vector_pop_back(vector_t* vec);
vector_result_t vector_get(vector_t* vec, size_t index);
void vector_destroy(vector_t* vec);