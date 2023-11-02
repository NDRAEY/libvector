// libvector - simple dynamic array (vector) library for C by NDRAEY.

#include <stdlib.h>
#include "../include/vector.h"

vector_t* vector_new() {
	vector_t* vec = calloc(1, sizeof *vec);

	if(!vec) {
		return 0;
	}

	vec->data = calloc(1, sizeof(size_t));

	if(!vec->data) {
		free(vec);

		return 0;
	}

	vec->size = 0;
	vec->capacity = 1;

	return vec;
}

void vector_resize(vector_t* vec, size_t size) {
	if(!vec)
		return;

	void* new_buf = realloc(vec->data, sizeof(size_t) * size);

	if(!new_buf)
		return;

	vec->data = new_buf;
	vec->capacity = size;
}

void vector_push_back(vector_t* vec, size_t element) {
	if(vec->size >= vec->capacity) {

		size_t new_cap = vec->capacity * 2;

		void* new_buf = realloc(vec->data, sizeof(size_t) * new_cap);

		if(!new_buf)
			return;

		vec->data = new_buf;
		vec->capacity = new_cap;
	}

	vec->data[vec->size++] = element;
}

vector_result_t vector_pop_back(vector_t* vec) {
	if(!vec)
		return (vector_result_t){true, 0};

	if(vec->size == 0) {
		return (vector_result_t){true, 0};
	}

	return (vector_result_t){false, vec->data[(vec->size--) - 1]};
}

vector_result_t vector_get(vector_t* vec, size_t index) {
	if(!vec || index >= vec->size)
		return (vector_result_t){true, 0};

	return (vector_result_t){false, vec->data[index]};
}

void vector_destroy(vector_t* vec) {
	if(!vec)
		return;

	free(vec->data);

	free(vec);
}