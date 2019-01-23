compile-lph:
	gcc hash.h array_hash.c test_array_hash.c -o lph
test-lph:
	./lph
	rm lph

compile-lh:
	gcc ../search/st.h hash.h ../search/sequential_search_st.c \
		linked_hash.c test_linked_hash.c -o lh
test-lh:
	./lh
	rm lh

compile: compile-lph compile-lh
test: compile
	./lph
	rm lph
	./lh
	rm lh