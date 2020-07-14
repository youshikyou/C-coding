void DjMinDist(graph G) {

	int s[G.vexnum] = { 0 };  //已经添加的节点,0代表未访问
	int dist[G.vexnum] = { 0 }; // 已经添加的节点能到达剩下节点的最小距离
	int path[G.vexnum] = { -1 }; //记录的是该节点的前驱节点。

	//初始化
	for (int i = 1; i < vexnum; i++) {
		int dist[i] = G.arc[0][i]; //初始化从第一个节点到其他节点的距离
		if (G.ar[0][i] <MAX) {
			path[i] = 0; // 表示如果能从节点0到达，那么它的前驱节点是0；
		}
	}
	s[0] = 1; // 节点0已经访问过置1

	for (int i = 1; i < G.vexnum; i++)
	{
		// 循环找到目前已加入的节点到另外没加入节点距离最小值
		int min_dist = MAX;
		int min_vex;
		for (int j = 1; j < G.vexnum; j++) {
			if (s[j] != 1 && dist[j] < min_dist) {
				min_vex = j;
				min_dist = dist[j];
			}
		}
		s[min_vex] = 1; //将当前能到达的最小距离的节点加入已访问。

		/*判断新加入后的节点是否可以使前一时期的最短路径的值变小*/
		for (int j = 1; j < G.vexnum; j++) {
			if (s[j] != 1 && dist[j] > G.arc[min_vex][j]+dist[min_vex]) //新加节点min_vex带入的新边权值与之前节点到min_vex的之和如果小于未加入该节点能到达其他节点
			
			{
				dist[j] = G.arc[min_vex][j] + dist[min_vex];
				path[j] = min_vex;  //对应节点的前驱节点应该修改
			}
		}

	}



}

void FloydMinDist(Graph G) {
	int A[G.vexnum][G.vexnum];
	for (int i = 0; i < G.vexnum; i++) {
		for (int j = 0; j < G.vexnum; j++) {
			A[i][j] = G.arc[i][j];
		}
	}
	for (int k = 0; k < G.vexnum; k++) {
		for (int i = 0; i < G.vexnum; i++) {
			for (int j = 0; j < G.vexnum; j++) {
				if (A[i][j] > A[i][k] + A[k][j]) {
					A[i][j] = A[i][k] + A[k][j]
				}
			}
		}
	}
}
