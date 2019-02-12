typedef struct STNode {
    char *key;
    int value;
    struct STNode *next;
} STNode;

typedef struct SequentialSearchST {
    int size;
    STNode *first;
} SequentialSearchST;

SequentialSearchST *get_sst();
int sst_size(SequentialSearchST *);
int sst_empty(SequentialSearchST *);
int sst_contains(SequentialSearchST *, char *);
int sst_get(SequentialSearchST *, char *);
STNode *sst_get_node(SequentialSearchST *, char *);
void sst_put(SequentialSearchST *, char *, int);
void sst_delete(SequentialSearchST *, char *);
void sst_display(SequentialSearchST *);

typedef struct BinarySearchST {
    int cap;
    char **keys;
    int *values;
    int size;
} BinarySearchST;

BinarySearchST *get_bst();
int bst_size(BinarySearchST *);
int bst_empty(BinarySearchST *);
void bst_resize(BinarySearchST *, int);
int bst_rank(BinarySearchST *, char *);
int bst_contains(BinarySearchST *, char *);
int bst_get(BinarySearchST *, char *);
void bst_put(BinarySearchST *, char *, int);
void bst_delete(BinarySearchST *, char *);
void bst_display(BinarySearchST *);