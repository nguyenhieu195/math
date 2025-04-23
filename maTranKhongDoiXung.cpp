#include <stdio.h>

int G[20][20]; // ma trận kề
int n;         // số đỉnh
int V_in[20], V_out[20]; // chứa bậc đỉnh
FILE *fptr;

//--------------------------------------------------
int Init_Graph(const char *path) {
    int i, j;
    fptr = fopen(path, "r");
    if (fptr == NULL) {
        perror("Lỗi khi mở file");
        return 1;
    }
    fscanf(fptr, "%d", &n);
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            G[i][j] = 0;
    while (fscanf(fptr, "%d%d%d", &i, &j, &G[i][j]) == 3); // đọc cho đến hết
    fclose(fptr);
    return 0;
}

//--------------------------------------------------
void View_Graph(int G[20][20], int n) {
    int i, j;
    printf("Số đỉnh: %d\n", n);
    printf("Ma trận kề:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++)
            printf("%3d ", G[i][j]);
        printf("\n");
    }
}

//--------------------------------------------------
void Vetexs(int G[20][20], int V_in[20], int V_out[20], int n) {
    int i, j;
    printf("\nNửa bậc ra:\n");
    for (i = 1; i <= n; i++) {
        V_out[i] = 0;
        for (j = 1; j <= n; j++)
            V_out[i] += G[i][j];
        printf("deg_out(%d) = %d\t", i, V_out[i]);
    }

    printf("\n\nNửa bậc vào:\n");
    for (j = 1; j <= n; j++) {
        V_in[j] = 0;
        for (i = 1; i <= n; i++)
            V_in[j] += G[i][j];
        printf("deg_in(%d) = %d\t", j, V_in[j]);
    }
    printf("\n");
}

//--------------------------------------------------
int main() {
    if (!Init_Graph("Parth2.INP")) { // ✅ Đã đổi tên file tại đây
        View_Graph(G, n);
        Vetexs(G, V_in, V_out, n);
    } else {
        printf("Không thể khởi tạo đồ thị từ file.\n");
    }
    return 0;
}
