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

compile-g:
	javac -classpath src src/graph/Graph.java
test-g:
	java -classpath src graph.Graph test_data/tinyG.txt
compile-gdfs:
	javac -classpath src src/graph/DepthFirstSearch.java
test-gdfs:
	java -classpath src graph.DepthFirstSearch test_data/tinyG.txt 3
	java -classpath src graph.DepthFirstSearch test_data/tinyG.txt 0
compile-gdfp:
	javac -classpath src src/graph/DepthFirstPaths.java
test-gdfp:
	java -classpath src graph.DepthFirstPaths test_data/tinyG.txt 3
	java -classpath src graph.DepthFirstPaths test_data/tinyG.txt 0
compile-gbfp:
	javac -classpath src src/graph/BreadthFirstPaths.java
test-gbfp:
	java -classpath src graph.BreadthFirstPaths test_data/mediumG.txt 3
	java -classpath src graph.BreadthFirstPaths test_data/tinyG.txt 0
compile-cc:
	javac -classpath src src/graph/CC.java
test-cc:
	java -classpath src graph.CC test_data/mediumG.txt
	java -classpath src graph.CC test_data/tinyG.txt

test-all-g: compile-g compile-gdfs compile-gdfp compile-cc
	make test-g
	make test-gdfs
	make test-gdfp
	make test-cc
	

compile-dg:
	javac -classpath src src/graph/Digraph.java
test-dg:
	java -classpath src graph.Digraph test_data/mediumDG.txt 3
compile-dgfs:
	javac -classpath src src/graph/DirectedDFS.java
test-dgfs:
	java -classpath src graph.DirectedDFS test_data/mediumDG.txt 3
compile-dgcycle:
	javac -classpath src src/graph/DirectedCycle.java
test-dgcycle:
	java -classpath src graph.DirectedCycle test_data/tinyDAG.txt
	java -classpath src graph.DirectedCycle test_data/tinyDG.txt
compile-dgdfo:
	javac -classpath src src/graph/DepthFirstOrder.java
test-dgdfo:
	java -classpath src graph.DepthFirstOrder test_data/tinyDAG.txt
compile-dgt:
	javac -classpath src src/graph/Topological.java
test-dgt:
	java -classpath src graph.Topological test_data/jobs.txt "/"
test-all-dg: compile-dg compile-dgfs compile-dgcycle compile-dgdfo compile-dgt
	make test-dg
	make test-dgfs
	make test-dgcycle
	make test-dgdfo
	make test-dgt

test: test-all-stack test-all-queue test-all-hash test-all-dg
	make clean

clean:
	rm -rf src/graph/*.class
	rm -rf src/hash/*.class
	rm -rf src/queue/*.class
	rm -rf src/search/*.class
	rm -rf src/sort/*.class
	rm -rf src/stack/*.class
	rm -rf src/utils/*.class