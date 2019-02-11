#include <stdio.h>
#include <stdlib.h>

#define MAXV 505
#define INF 10000000

typedef struct {
	int Nv, Ne;
	int Dist[MAXV][MAXV];
	int Visited[MAXV];
	int MinDist[MAXV];
	int Team[MAXV], MaxTeam[MAXV];
	int Path[MAXV];
	int Count[MAXV];
} Graph;

void InitializeG(Graph *ptrG) {
	int i, j;

	ptrG->Nv = ptrG->Ne = 0;
	for (i = 0; i < MAXV; i++) {
		for (j = 0; j < MAXV; j++) {
			ptrG->Dist[i][j] = INF;
		}
		ptrG->MinDist[i] = INF;
		ptrG->Visited[i] = 0;
		ptrG->Team[i] = ptrG->MaxTeam[i] = 0;
		ptrG->Path[i] = -1;
		ptrG->Count[i] = 0;
	}
}

void ReadG(Graph *ptrG, int *S, int *D) {
	int i, V1, V2, W, N, M;

	scanf("%d %d %d %d", &N, &M, S, D);
	ptrG->Nv = N; ptrG->Ne = M;
	for (i = 0; i < N; i++)
		scanf("%d", &(ptrG->Team[i]));
	for (i = 0; i < M; i++) {
		scanf("%d %d %d", &V1, &V2, &W);
		ptrG->Dist[V1][V2] = ptrG->Dist[V2][V1] = W;
	}
}

void Dijkstra(Graph *ptrG, int S) {
	int i, j, minD, minV, MinDist, MaxTeam;

	ptrG->MinDist[S] = 0;
	ptrG->MaxTeam[S] = ptrG->Team[S];
	ptrG->Count[S] = 1;

	for (i = 0; i < ptrG->Nv; i++) {
		minD = INF;
		for (j = 0; j < ptrG->Nv; j++)
			if (!ptrG->Visited[j] && minD > ptrG->MinDist[j]) {
				minD = ptrG->MinDist[j];
				minV = j;
			}
		if (minD < INF)
			ptrG->Visited[minV] = 1;
		else//图不连通 
			break;

		for (j = 0; j < ptrG->Nv; j++) {
			if (!ptrG->Visited[j]) {
				int sumDist = ptrG->MinDist[minV] + ptrG->Dist[minV][j];
				int sumTeam = ptrG->MaxTeam[minV] + ptrG->Team[j];
				if (sumDist < ptrG->MinDist[j]) {
					ptrG->Count[j] = ptrG->Count[minV];//发现有更短路径：最短路径条数等于该路径上前驱结点的最短路径条数 
					ptrG->MinDist[j] = sumDist;
					ptrG->MaxTeam[j] = sumTeam;
					ptrG->Path[j] = minV;
				}
				else if ((sumDist == ptrG->MinDist[j])) {//距离相等
					if (ptrG->MaxTeam[j] < sumTeam) {//但救援队更多 
						ptrG->MaxTeam[j] = sumTeam;
						ptrG->Path[j] = minV;
					}
					ptrG->Count[j] += ptrG->Count[minV];//发现等长路径：最短路径条数等于当前条数加上前驱结点的最短路径条数 	
				}
			}
		}
	}
}

void PrintPath(int path[], int S) {
	if (path[S] >= 0) {
		PrintPath(path, path[S]);
		printf(" %d", S);
	}
	else
		printf("%d", S);
}

int main(void) {
	int S, D, Count = 0;
	Graph G;
	InitializeG(&G);
	ReadG(&G, &S, &D);
	Dijkstra(&G, S);
	printf("%d %d\n", G.Count[D], G.MaxTeam[D]);
	//PrintPath(G.Path, D);

	return 0;
}