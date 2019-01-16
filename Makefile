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

test-stack: compile-stack compile-linked-stack compile-array-stack
	java -classpath src stack.Stack < test_data/tobe.txt
	java -classpath src stack.LinkedStack < test_data/tobe.txt
	java -classpath src stack.ResizingArrayStack < test_data/tobe.txt
	rm src/stack/*.class
	echo "test stack success"