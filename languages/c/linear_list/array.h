#define MAXSIZE 50

// 静态分配空间，默认50个
typedef struct SqList {
    int data[MAXSIZE]; // element type
    int length;
} SqList;

// typedef sqlist SqList;

int array_insert(SqList *L, int pos, int e);
int array_remove(SqList *L, int pos);
int array_update(SqList *L, int pos, int e);
int array_min(SqList *L);
int array_max(SqList *L);
void array_display(SqList *L);

SqList * get_static_array();