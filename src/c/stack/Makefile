compile-array:
	gcc stack.h array_stack.c test_array_stack.c -o stack_array
compile-list:
	gcc stack.h linked_stack.c test_linked_stack.c -o stack_list
compile: compile-array compile-list

test: compile
	./stack_array
	rm stack_array
	./stack_list
	rm stack_list