#include <stdio.h>
#include <stdlib.h> 

int G[20][20], C[20], T[20], V[20];
int n, u = 1;
FILE *fptr;

int Init_Graph(const char *path) {
    int i, j;

    fptr = fopen(path, "r");

    if (fptr == NULL) {
        printf("Error\n");
        return 1;
    }

    fscanf(fptr, "%d", &n);

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            G[i][j] = 0;
        }
    }

    while (!feof(fptr)) {
        fscanf(fptr, "%d", &i);
        fscanf(fptr, "%d", &j);
        G[i][j] = G[j][i] = 1;  
    }

    fclose(fptr);
    return 0;
}

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

void Vetexs(int G[20][20], int V[20], int n) {
    int i, j;
    for (i = 1; i <= n; i++) {
        V[i] = 0;
        for (j = 1; j <= n; j++) {
            V[i] += G[i][j];
        }
        V[i] += G[i][i];  // Tính cả bậc riêng (loop) nếu có
        printf("deg(%d) = %d\t", i, V[i]);
    }
    printf("\n");
}
void Print(int n)
{
    for (int i = 0; i <= n; i++)
    {
        printf("%d ", C[i]);
    }
    printf("\n");
}
void Hamilton (int u){
	for (int v = 1; v <= n; v++){
		if(G[C[u-1]][v] != 0 && T[v] == 0){
			C[u] = v;
			T[v] = 1;
			if(u<n) Hamilton(u+1);
			else{
				if(C[u] == C[0]) Print(n);
			}
			T[v] = 0;
		}
	}
}

int main() {
    if (!Init_Graph("Graph.txt")) {
        View_Graph(G, n);
        printf("Bac dinh:\n");
        Vetexs(G, V, n);
        // system("pause"); // Nếu bạn muốn dừng màn hình lại, nhưng có thể không cần thiết
        return 0;
    }
    return 1;

	if(Init_Graph("Graph.txt")){
		C[0] = u;
		Hamilton(1);
	}
}