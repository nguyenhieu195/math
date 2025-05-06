#include <stdio.h>
#include <stdlib.h> 

// Khai báo ma trận kề G, các mảng C (đường đi Hamilton), T (đánh dấu đỉnh đã đi), V (bậc đỉnh)
int G[20][20], C[20], T[20], V[20];
int n, u = 1; // n là số đỉnh, u là đỉnh bắt đầu tìm Hamilton
FILE *fptr;

// Hàm đọc đồ thị từ file văn bản
int Init_Graph(const char *path) {
    int i, j;

    // Mở file để đọc
    fptr = fopen(path, "r");
    if (fptr == NULL) {
        printf("Error\n");
        return 1; // Trả về 1 nếu lỗi
    }

    // Đọc số lượng đỉnh từ dòng đầu tiên
    fscanf(fptr, "%d", &n);

    // Khởi tạo ma trận kề với tất cả giá trị bằng 0
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            G[i][j] = 0;
        }
    }

    // Đọc các cạnh của đồ thị từ file, gán 1 cho các cặp đỉnh có cạnh nối
    while (!feof(fptr)) {
        fscanf(fptr, "%d", &i);
        fscanf(fptr, "%d", &j);
        G[i][j] = G[j][i] = 1;  // Vì là đồ thị vô hướng
    }

    fclose(fptr); // Đóng file sau khi đọc xong
    return 0; // Trả về 0 nếu đọc thành công
}

// Hàm hiển thị ma trận kề
void View_Graph(int G[20][20], int n) {
    int i, j;
    printf("So dinh: %d\n", n);
    printf("Ma tran ke:\n\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            printf("%d\t", G[i][j]);
        }
        printf("\n\n");
    }
}

// Hàm tính và in bậc của từng đỉnh
void Vetexs(int G[20][20], int V[20], int n) {
    int i, j;
    for (i = 1; i <= n; i++) {
        V[i] = 0;
        for (j = 1; j <= n; j++) {
            V[i] += G[i][j]; // Cộng số cạnh nối với đỉnh i
        }
        V[i] += G[i][i];  // Nếu có khuyên (cạnh nối chính nó) thì tính thêm
        printf("deg(%d) = %d\t", i, V[i]); // In bậc của đỉnh i
    }
    printf("\n");
}
//
// Hàm in ra chu trình Hamilton tìm được
void Print(int n)
{
    for (int i = 0; i <= n; i++)
    {
        printf("%d ", C[i]);
    }
    printf("\n");
}

// Hàm tìm chu trình Hamilton bằng đệ quy quay lui (backtracking)
void Hamilton (int u){
    for (int v = 1; v <= n; v++){
        // Nếu có cạnh từ đỉnh trước đó đến v, và v chưa được thăm
        if(G[C[u-1]][v] != 0 && T[v] == 0){
            C[u] = v;    // Gán đỉnh v vào vị trí thứ u trong chu trình
            T[v] = 1;    // Đánh dấu đỉnh v đã thăm
            if(u < n) Hamilton(u + 1); // Tiếp tục đi đến đỉnh tiếp theo
            else{
                if(C[u] == C[0]) // Nếu đỉnh cuối nối lại đỉnh đầu thì là chu trình Hamilton
                    Print(n);    // In chu trình
            }
            T[v] = 0; // Quay lui: bỏ đánh dấu đỉnh v để thử đường đi khác
        }
    }
}

// Hàm main – chương trình chính
int main() {
    if (!Init_Graph("Graph.txt")) { // Nếu đọc file thành công
        View_Graph(G, n);           // In ma trận kề
        printf("Bac dinh:\n");
        Vetexs(G, V, n);            // In bậc các đỉnh

        // Gọi hàm tìm chu trình Hamilton
        C[0] = u;       // Đặt đỉnh xuất phát
        T[u] = 1;       // Đánh dấu đỉnh xuất phát đã đi
        printf("Cac chu trinh Hamilton:\n");
        Hamilton(1);    // Bắt đầu tìm từ vị trí 1 (vì vị trí 0 là đỉnh xuất phát)

        return 0; 
    }

    return 1; 
}