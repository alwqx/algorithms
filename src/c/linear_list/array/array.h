#define MAXSIZE 50

// 静态分配空间，默认50个
typedef struct SqList {
    int data[MAXSIZE]; // element type
    int length;
} SqList;

typedef struct DSqList {
    int *data;
    int length;
    int cap; // 数组的容量
} DSqList;
// typedef sqlist SqList;

int array_insert(SqList *L, int pos, int e);
int array_remove(SqList *L, int pos);
int array_update(SqList *L, int pos, int e);
int array_min(SqList *L);
int array_max(SqList *L);
void array_display(SqList *L);

int darray_insert(DSqList *L, int pos, int e);
int darray_remove(DSqList *L, int pos);
int darray_update(DSqList *L, int pos, int e);
int darray_min(DSqList *L);
int darray_max(DSqList *L);
void darray_display(DSqList *L);

SqList * get_static_array();
DSqList * get_dynamic_array(int cap);