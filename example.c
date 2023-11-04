#include <stdio.h>
#include "include/vector.h"

#define VEC_INFO(vec) \
	printf("[%p] SIZE: %zu\n[%p] CAPACITY: %zu\n", vec, vec->size, vec, vec->capacity);

int main() {
	vector_t* vec = vector_new();

	for(int i = 0; i < 100; i++)
		vector_push_back(vec, i);

	vector_print_like_unsigned_decimal(vec);

	vector_destroy(vec);

	return 0;
}