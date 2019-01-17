static_test:
	gcc array.h static_array.c test_static_array.c -o test_array
	./test_array
	rm test_array

dynamic_test:
	gcc array.h dynamic_array.c test_dynamic_array.c -o test_array
	./test_array
	rm test_array

test: static_test dynamic_test