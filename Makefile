compile-bag:
	javac -classpath src/java src/java/utils/Bag.java
test-bag: compile-bag
	java -classpath src/java utils.Bag < test_data/tobe.txt

compile-stack:
	javac -classpath src/java src/java/stack/Stack.java
compile-linked-stack:
	javac -classpath src/java src/java/stack/LinkedStack.java
compile-array-stack:
	javac -classpath src/java src/java/stack/ResizingArrayStack.java
test-stack:
	java -classpath src/java stack.Stack < test_data/tobe.txt
test-linked-stack:
	java -classpath src/java stack.LinkedStack < test_data/tobe.txt
test-array-stack:
	java -classpath src/java stack.ResizingArrayStack < test_data/tobe.txt

test-all-stack: compile-stack compile-linked-stack compile-array-stack
	java -classpath src/java stack.Stack < test_data/tobe.txt
	java -classpath src/java stack.LinkedStack < test_data/tobe.txt
	java -classpath src/java stack.ResizingArrayStack < test_data/tobe.txt
	echo "test stack success"

compile-queue:
	javac -classpath src/java src/java/queue/Queue.java
compile-linked-queue:
	javac -classpath src/java src/java/queue/LinkedQueue.java
compile-array-queue:
	javac -classpath src/java src/java/queue/ResizingArrayQueue.java
compile-minpq:
	javac -classpath src/java src/java/queue/MinPQ.java
compile-indexminpq:
	javac -classpath src/java src/java/queue/IndexMinPQ.java
test-queue:
	java -classpath src/java queue.Queue < test_data/tobe.txt
test-linked-queue:
	java -classpath src/java queue.LinkedQueue < test_data/tobe.txt
test-array-queue:
	java -classpath src/java queue.ResizingArrayQueue < test_data/tobe.txt
test-minpq:
	java -classpath src/java queue.MinPQ < test_data/tinyPQ.txt
test-indexminpq:
	java -classpath src/java queue.IndexMinPQ
test-all-queue: compile-queue compile-linked-queue compile-array-queue compile-minpq compile-indexminpq
	make test-queue
	make test-linked-queue
	make test-array-queue
	make test-minpq
	make test-indexminpq

.PHONY: compile-stack test-stack

compile-st:
	javac -classpath src/java src/java/search/ST.java
test-st:
	java -classpath src/java search.ST < test_data/tinyST.txt
compile-sst:
	javac -classpath src/java src/java/search/SequentialSearchST.java
test-sst:
	java -classpath src/java search.SequentialSearchST < test_data/tinyST.txt
compile-bsst:
	javac -classpath src/java src/java/search/BinarySearchST.java
test-bsst:
	java -classpath src/java search.BinarySearchST < test_data/tinyST.txt
compile-avltst:
	javac -classpath src/java src/java/search/AVLTreeST.java
test-avltst:
	java -classpath src/java search.AVLTreeST < test_data/tinyST.txt
test-all-st: compile-st compile-sst compile-bsst compile-avltst
	make test-st
	make test-sst
	make test-bsst
	make test-avltst

compile-lphash:
	javac -classpath src/java src/java/hash/LinearProbingHashST.java
test-lphash:
	java -classpath src/java hash.LinearProbingHashST < test_data/tinyST.txt
compile-schash:
	javac -classpath src/java src/java/hash/SeparateChainingHashST.java
test-schash:
	java -classpath src/java hash.SeparateChainingHashST < test_data/tinyST.txt
test-all-hash: compile-schash compile-lphash
	make test-schash
	make test-lphash

compile-g:
	javac -classpath src/java src/java/graph/Graph.java
test-g:
	java -classpath src/java graph.Graph test_data/tinyG.txt
compile-gdfs:
	javac -classpath src/java src/java/graph/DepthFirstSearch.java
test-gdfs:
	java -classpath src/java graph.DepthFirstSearch test_data/tinyG.txt 3
	java -classpath src/java graph.DepthFirstSearch test_data/tinyG.txt 0
compile-gdfp:
	javac -classpath src/java src/java/graph/DepthFirstPaths.java
test-gdfp:
	java -classpath src/java graph.DepthFirstPaths test_data/tinyG.txt 3
	java -classpath src/java graph.DepthFirstPaths test_data/tinyG.txt 0
compile-gbfp:
	javac -classpath src/java src/java/graph/BreadthFirstPaths.java
test-gbfp:
	java -classpath src/java graph.BreadthFirstPaths test_data/mediumG.txt 3
	java -classpath src/java graph.BreadthFirstPaths test_data/tinyG.txt 0
compile-cc:
	javac -classpath src/java src/java/graph/CC.java
test-cc:
	java -classpath src/java graph.CC test_data/mediumG.txt
	java -classpath src/java graph.CC test_data/tinyG.txt

test-all-g: compile-g compile-gdfs compile-gdfp compile-cc
	make test-g
	make test-gdfs
	make test-gdfp
	make test-cc
	

compile-dg:
	javac -classpath src/java src/java/graph/Digraph.java
test-dg:
	java -classpath src/java graph.Digraph test_data/mediumDG.txt 3
compile-dgfs:
	javac -classpath src/java src/java/graph/DirectedDFS.java
test-dgfs:
	java -classpath src/java graph.DirectedDFS test_data/mediumDG.txt 3
compile-dgcycle:
	javac -classpath src/java src/java/graph/DirectedCycle.java
test-dgcycle:
	java -classpath src/java graph.DirectedCycle test_data/tinyDAG.txt
	java -classpath src/java graph.DirectedCycle test_data/tinyDG.txt
compile-dgdfo:
	javac -classpath src/java src/java/graph/DepthFirstOrder.java
test-dgdfo:
	java -classpath src/java graph.DepthFirstOrder test_data/tinyDAG.txt
compile-dgt:
	javac -classpath src/java src/java/graph/Topological.java
test-dgt:
	java -classpath src/java graph.Topological test_data/jobs.txt "/"

test-all-dg: compile-dg compile-dgfs compile-dgcycle compile-dgdfo compile-dgt
	make test-dg
	make test-dgfs
	make test-dgcycle
	make test-dgdfo
	make test-dgt

compile-mst-lazy-prim:
	javac -classpath src/java src/java/graph/LazyPrimMST.java
test-mst-lazy-prim:
	java -classpath src/java graph.LazyPrimMST test_data/tinyEWG.txt
	java -classpath src/java graph.LazyPrimMST test_data/mediumEWG.txt
compile-mst-prim:
	javac -classpath src/java src/java/graph/PrimMST.java
test-mst-prim:
	java -classpath src/java graph.PrimMST test_data/tinyEWG.txt
	java -classpath src/java graph.PrimMST test_data/mediumEWG.txt
compile-mst-kruskal:
	javac -classpath src/java src/java/graph/KruskalMST.java
test-mst-kruskal:
	java -classpath src/java graph.KruskalMST test_data/tinyEWG.txt
	java -classpath src/java graph.KruskalMST test_data/mediumEWG.txt

test-all-mst: compile-mst-lazy-prim compile-mst-prim compile-mst-kruskal
	make test-mst-lazy-prim
	make test-mst-prim
	make test-mst-kruskal

compile-sp-di:
	javac -classpath src/java src/java/graph/DijkstraSP.java
test-sp-di:
	java -classpath src/java graph.DijkstraSP test_data/tinyEWD.txt 0
	java -classpath src/java graph.DijkstraSP test_data/mediumEWD.txt 0
compile-sp-udi:
	javac -classpath src/java src/java/graph/DijkstraUndirectedSP.java
test-sp-udi:
	java -classpath src/java graph.DijkstraUndirectedSP test_data/tinyEWD.txt 0
	java -classpath src/java graph.DijkstraUndirectedSP test_data/mediumEWD.txt 0
compile-sp-pdi:
	javac -classpath src/java src/java/graph/DijkstraAllPairsSP.java
test-sp-pdi:
	java -classpath src/java graph.DijkstraAllPairsSP test_data/tinyEWD.txt
compile-sp-adi:
	javac -classpath src/java src/java/graph/AcyclicSP.java
test-sp-adi:
	java -classpath src/java graph.AcyclicSP test_data/tinyEWDAG.txt 5

test-all-sp: compile-sp-di compile-sp-udi compile-sp-pdi compile-sp-adi
	make test-sp-di
	make test-sp-udi
	make test-sp-pdi
	make test-sp-adi

compile-lp-di:
	javac -classpath src/java src/java/graph/AcyclicLP.java
test-lp-di:
	java -classpath src/java graph.AcyclicLP test_data/tinyEWDAG.txt 5
compile-lp-cpm:
	javac -classpath src/java src/java/graph/CPM.java
test-lp-cpm:
	java -classpath src/java graph.CPM < test_data/jobsPC.txt

test-all-lp: compile-lp-di compile-lp-cpm
	make test-lp-di
	make test-lp-cpm

compile-avltree:
	javac -classpath src/java src/java/tree/AVLTree.java
test-avltree:
	java -classpath src/java tree.AVLTree < test_data/tinyST.txt
compile-btree:
	javac -classpath src/java src/java/tree/BTree.java
test-btree:
	java -classpath src/java tree.BTree
compile-rbtree:
	javac -classpath src/java src/java/tree/RedBlackBST.java
test-rbtree:
	java -classpath src/java tree.RedBlackBST < test_data/tinyST.txt
compile-bstree:
	javac -classpath src/java src/java/tree/BinarySearchTree.java
test-bstree:
	java -classpath src/java tree.BinarySearchTree < test_data/tinyST.txt

test-all-tree: compile-avltree compile-btree compile-rbtree compile-bstree
	make test-avltree
	make test-btree
	make test-rbtree
	make test-bstree

compile-sort-selection:
	javac -classpath src/java src/java/sort/Selection.java
test-sort-selection:
	java -classpath src/java sort.Selection < test_data/tiny.txt
	java -classpath src/java sort.Selection < test_data/words3.txt
compile-sort-insertion:
	javac -classpath src/java src/java/sort/Insertion.java
test-sort-insertion:
	java -classpath src/java sort.Insertion < test_data/tiny.txt
	java -classpath src/java sort.Insertion < test_data/words3.txt
compile-sort-shell:
	javac -classpath src/java src/java/sort/Shell.java
test-sort-shell:
	java -classpath src/java sort.Shell < test_data/tiny.txt
	java -classpath src/java sort.Shell < test_data/words3.txt
compile-sort-merge:
	javac -classpath src/java src/java/sort/Merge.java
test-sort-merge:
	java -classpath src/java sort.Merge < test_data/tiny.txt
	java -classpath src/java sort.Merge < test_data/words3.txt
compile-sort-quick:
	javac -classpath src/java src/java/sort/Quick.java
test-sort-quick:
	java -classpath src/java sort.Quick < test_data/tiny.txt
	java -classpath src/java sort.Quick < test_data/words3.txt

test-sort-judge: compile-sort-selection compile-sort-insertion
	javac -classpath src/java src/java/sort/SortCompare.java
	java -classpath src/java sort.SortCompare Insertion Selection 1000 10

test-all-sort: compile-sort-selection compile-sort-insertion compile-sort-shell compile-sort-merge compile-sort-quick
	make test-sort-selection
	make test-sort-insertion
	make test-sort-shell
	make test-sort-merge
	make test-sort-quick

test:
	make test-all-stack
	make test-all-queue
	make test-all-hash
	make test-all-dg
	make test-all-mst
	make test-all-sp
	make test-all-lp
	make test-all-tree
	make test-all-sort
	make test-bag
	make clean

clean:
	rm -rf src/java/graph/*.class
	rm -rf src/java/hash/*.class
	rm -rf src/java/queue/*.class
	rm -rf src/java/search/*.class
	rm -rf src/java/sort/*.class
	rm -rf src/java/stack/*.class
	rm -rf src/java/utils/*.class
	rm -rf src/java/tree/*.class