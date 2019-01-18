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

test: test-all-stack test-all-queue