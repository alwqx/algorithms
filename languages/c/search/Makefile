compile-sst:
	gcc st.h test_sequential_search_st.c sequential_search_st.c -o sst
test-sst:
	./sst
	rm sst

compile-bst:
	gcc st.h test_binary_search_st.c binary_search_st.c -o bst
test-bst:
	./bst
	rm bst

compile: compile-sst compile-bst

test: compile
	./sst
	rm sst
	./bst
	rm bst