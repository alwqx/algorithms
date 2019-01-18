compile-array:
	gcc queue.h array_queue.c test_array_queue.c -o queue_array
compile-list:
	gcc queue.h linked_queue.c test_linked_queue.c -o queue_list
compile: compile-array compile-list

test: compile
	./queue_array
	rm queue_array
	./queue_list
	rm queue_list