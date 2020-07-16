/* 首先从k开始往下调整， 将k对应的值赋给arr[0], 然后找到k对应的左孩子，完全二叉树左孩子一定存在且是2k
第一个if先判断左孩子和右孩子哪个大，然后赋值给i，然后将数值大的孩子与父节点值比较，如果父节点大于左右孩子，就跳出，
如果较大孩子数值大于父节点，则将较大孩子节点值赋给父节点，然后k记录该孩子节点序号，循环结束
将被置换的i节点赋给最开始k节点值。

*/

void adjustdown(int *arr, int k, int len) {
	int i;
	arr[0] = arr[k];
	for (i = 2 * k; i <= len; i*=2) {
		if (arr[i] < arr[i + 1] && i < len) {
			i++;
		}// find the bigger one in left child and right child.

		if (arr[0] >= arr[i]) {
			break;
		}
		else {
			arr[k] = arr[i];
			k = i;   //k就是标记最开始那个arr[0]应该去的最后树的序号位置。
		}
	}
	arr[k] = arr[0];
}

void heapsort(int *arr, int len) {
	
	int temp, i;
	for (int i = len / 2; i > 0; i--) {
		adjustdown(arr, i, len);
	} //形成一个大根堆

	for (int i = len, i > 1; i--) {
		temp = arr[i];
		arr[i] = arr[1];
		arr[1] = temp;// 因为adjustdown会把最大数字调整到树的根节点arr[1]，所以每次把arr[1]与i交换就是把目前最大值调整到最后。
		adjustdown(arr, 1, i - 1); //因为已经把当前最大值调整到堆的底部，所以排除 i-1，再调整.
	}
}


/*插入一个节点*/
void adjustup(int * arr, int len, int k) {
	arr[0] = arr[k];
	int i = k / 2; //得到父节点
	while (i > 0 && arr[i] < arr[0])//没到根节点且插入节点的值大于父节点时 
	{
		arr[k] = arr[i]; //把父节点值移到子节点
		k = i; //向上移动,k 是标记插入的节点arr[0]= arr[k],最一开始的时候的值应该去的节点位置。
		i = k / 2;
	}
   arr[k] = arr[0];
}
