#include "../search/st.h"

#define LINKED_HASH_INIT_CAP 4

typedef struct ArrayHash {
    int cap;
    int size;
    char **keys;
    int *values;
} ArrayHash;

ArrayHash *get_lph();
ArrayHash *get_lph_cap(int);
int hash_code(char *, int);
void lph_resize(ArrayHash *, int);
int lph_size(ArrayHash *);
int lph_empty(ArrayHash *);
int lph_get(ArrayHash *, char *);
void lph_put(ArrayHash *, char *, int);
void lph_delete(ArrayHash *, char *);
int lph_contains(ArrayHash *, char *);
void lph_display(ArrayHash *);

typedef struct LinkedHash {
    int size;
    int cap;
    SequentialSearchST **st;
} LinkedHash;

LinkedHash *get_linked_hash();
LinkedHash *get_linked_hash_cap(int);
int lhash_code(char *, int);
int lh_size(LinkedHash *);
int lh_empty(LinkedHash *);
void lh_resize(LinkedHash *, int);
void lh_put(LinkedHash *, char *, int);
int lh_get(LinkedHash *, char *);
void lh_delete(LinkedHash *, char *);
int lh_contains(LinkedHash *, char *);
void lh_display(LinkedHash *);