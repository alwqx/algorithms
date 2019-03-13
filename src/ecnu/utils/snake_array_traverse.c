// 蛇形矩阵遍历（打印）
// refer https://blog.csdn.net/Echo_Ana/article/details/53411476
#include <stdio.h>
#include <stdlib.h>

#define MAXN 100

void traverse_clockwise(int n);
void traverse_anticlockwise(int n);
void traverse_z(int n);
void traverse_zb(int n);

int main() {
    int n; char c;
    scanf("%d %c", &n, &c);
    if(c=='c')      traverse_clockwise(n);
    else if(c=='a') traverse_anticlockwise(n);
    else if(c=='z') traverse_z(n);
    else            traverse_zb(n);
    // else            printf("control char is invalid.should be c or a or z.\n");
    
    return 0;
}

void traverse_clockwise(int n) {
    int (*a)[n] = calloc(n*n, sizeof(int));
    int x, y, r, start=1;

    if(n==1) a[0][0] = 1;
    else {
        for(r=0; r<=n/2; r++) {
            x = r;
            for(y=r; y<n-r; y++) {
                a[x][y] = start;
                start++;
            }

            y = n-r-1;
            for(x=r+1; x<n-r-1; x++) {
                a[x][y] = start;
                start++;
            }

            x = n-r-1;
            for(y=n-r-1; y>=r; y--) {
                a[x][y] = start;
                start++;
            }

            y = r;
            for(x=n-r-2; x>r; x--) {
                a[x][y] = start;
                start++;
            }
        }
    }

    if(n%2==1) a[n/2][n/2] = n*n;

    for(x=0; x<n; x++) {
        for(y=0; y<n; y++) printf("%10d",a[x][y]);
        printf("\n");
    }
}

void traverse_anticlockwise(int n) {
    int (*a)[n] = calloc(n*n, sizeof(int));
    int x, y, r, start=1;

    if(n==1) a[0][0] = 1;
    else {
        for(r=0; r<=n/2; r++) {
            y = r;
            for(x=r; x<n-r-1; x++) {
                a[x][y] = start;
                start++;
            }

            x = n-r-1;
            for(y=r; y<n-r-1; y++) {
                a[x][y] = start;
                start++;
            }

            y = n-r-1;
            for(x=n-r-1; x>r; x--) {
                a[x][y] = start;
                start++;
            }

            x = r;
            for(y=n-r-1; y>r; y--) {
                a[x][y] = start;
                start++;
            }
        }
    }

    if(n%2==1) a[n/2][n/2] = n*n;

    for(x=0; x<n; x++) {
        for(y=0; y<n; y++) printf("%10d",a[x][y]);
        printf("\n");
    }
}

void traverse_z(int n) {
    int (*a)[n] = calloc(n*n, sizeof(int));
    int x, y, r, start=1;
    int num;

    if(n==1) a[0][0] = 1;
    else {
        // up triangle
        for(r=1; r<=n; r++) {
            for(y=0; y<r; y++) {
                a[r-1-y][y] = start;
                start++;
            }
        }

        for(; r<=2*n-1; r++) {
            for(y=r-n; y<n; y++) {
                a[r-1-y][y] = start;
                start++;
            }
        }
    }

    for(x=0; x<n; x++) {
        for(y=0; y<n; y++) printf("%10d",a[x][y]);
        printf("\n");
    }
}

void traverse_zb(int n) {
    int (*a)[n] = calloc(n*n, sizeof(int));
    int x, y, r, start=1;
    int num;

    if(n==1) a[0][0] = 1;
    else {
        // up triangle
        for(r=1; r<=n; r++) {
            for(y=0; y<r; y++) {
                a[y][r-1-y] = start;
                start++;
            }
        }

        for(; r<=2*n-1; r++) {
            for(y=r-n; y<n; y++) {
                a[y][r-1-y] = start;
                start++;
            }
        }
    }

    for(x=0; x<n; x++) {
        for(y=0; y<n; y++) printf("%10d",a[x][y]);
        printf("\n");
    }
}