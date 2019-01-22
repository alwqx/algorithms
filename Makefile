compile-stack:
	javac -classpath src src/stack/Stack.java
compile-linked-stack:
	javac -classpath src src/stack/LinkedStack.java
compile-array-stack:
	javac -classpath src src/stack/ResizingArrayStack.java
test-stack:
	java -classpath src stack.Stack < test_data/tobe.txt
test-linked-stack:
	java -classpath src stack.LinkedStack < test_data/tobe.txt
test-array-stack:
	java -classpath src stack.ResizingArrayStack < test_data/tobe.txt

test-all-stack: compile-stack compile-linked-stack compile-array-stack
	java -classpath src stack.Stack < test_data/tobe.txt
	java -classpath src stack.LinkedStack < test_data/tobe.txt
	java -classpath src stack.ResizingArrayStack < test_data/tobe.txt
	rm src/stack/*.class
	echo "test stack success"

compile-queue:
	javac -classpath src src/queue/Queue.java
compile-linked-queue:
	javac -classpath src src/queue/LinkedQueue.java
compile-array-queue:
	javac -classpath src src/queue/ResizingArrayQueue.java
test-queue:
	java -classpath src queue.Queue < test_data/tobe.txt
test-linked-queue:
	java -classpath src queue.LinkedQueue < test_data/tobe.txt
test-array-queue:
	java -classpath src queue.ResizingArrayQueue < test_data/tobe.txt

test-all-queue: compile-queue compile-linked-queue compile-array-queue
	make test-queue
	make test-linked-queue
	make test-array-queue
	rm -rf src/queue/*.class

.PHONY: compile-stack test-stack

compile-st:
	javac -classpath src src/search/ST.java
test-st:
	java -classpath src search.ST < test_data/tinyST.txt
compile-sst:
	javac -classpath src src/search/SequentialSearchST.java
test-sst:
	java -classpath src search.SequentialSearchST < test_data/tinyST.txt
compile-bsst:
	javac -classpath src src/search/BinarySearchST.java
test-bsst:
	java -classpath src search.BinarySearchST < test_data/tinyST.txt
compile-avltst:
	javac -classpath src src/search/AVLTreeST.java
test-avltst:
	java -classpath src search.AVLTreeST < test_data/tinyST.txt
test-all-st: compile-st compile-sst compile-bsst compile-avltst
	make test-st
	make test-sst
	make test-bsst
	make test-avltst
	rm -rf src/search/*.class
	rm -rf src/queue/*.class

compile-lphash:
	javac -classpath src src/hash/LinearProbingHashST.java
test-lphash:
	java -classpath src hash.LinearProbingHashST < test_data/tinyST.txt
compile-schash:
	javac -classpath src src/hash/SeparateChainingHashST.java
test-schash:
	java -classpath src hash.SeparateChainingHashST < test_data/tinyST.txt
test-all-hash: compile-schash compile-lphash
	make test-schash
	make test-lphash
	rm -rf src/queue/*.class
	rm -rf src/utils/*.class
	rm -rf src/search/*.class

test: test-all-stack test-all-queue