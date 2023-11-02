#include <stdio.h>
#include "include/vector.h"

int main() {
	vector_t* vec = vector_new();

	vector_push_back(vec, 1);
	vector_push_back(vec, 2);
	vector_push_back(vec, 3);
	vector_push_back(vec, 4);

	size_t index = 0;
	vector_result_t res = vector_get(vec, index++);

	while(!res.error) {
		printf("%lu\n", res.element);
		res = vector_get(vec, index++);
	}

	vector_destroy(vec);

	return 0;
}