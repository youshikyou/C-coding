
typedef struct ThreadNode {
	int data;
	struct ThreadNode * lchild;
	struct ThreadNode * rchild;
	int ltag;
	int rtag;

}ThreadNode, * ThreadTree;

void InThread(ThreadTree p, ThreadTree pre) {
	if (p != NULL) {

		InThread(p->lchild, pre);
		if (p->lchild == NULL) {
			p->lchild = pre;
			p->ltag = 1;
		}
		if (pre != NULL && pre->rchild == NULL) {
			pre->rchild = p;
			pre->rtag = 1;
		}
		pre = p;  //
		InThread(p->rchild, pre);
	
	}
} 
/*中序树线索化其实就是模拟自己写中序树的过程，就是一个线性化的表达出来树的顺序。总体来说就是左/根/右。如果有左子树就有指针指向，所以能串起来。
 但是如果左指针是空时，那么代表这个节点应该指向前驱节点，只有这样才能串顺序来（记住左/根/右）。同时要考虑前驱节点是否存在右子树，如果存在，那么表明，中序中这两个
 节点并不是临近的。当该前驱节点不存在右子树的时候，才能串起来。然后该节点应该变成前驱节点，特别注意的时，InThread(p->rchild,pre)，
 这时候只是变了前驱节点，但是仍然还是搜索该节点的右子树。
 现从（子树/树）根节点开始找左子树，直到到最左的节点。
 如果lchild非空，那么代表当前节点有左子树，如果是空，那么就应该让这个节点能找到前驱节点，而前驱节点是pre。
 
 */
void CreateInThread(ThreadTree  T) {
	ThreadTree pre = NULL;
	if (T != NULL) {
		InThread(T, pre);
		pre->rchild = NULL;
		pre->rtag = 1;
	}
}

ThreadNode * FirstNode(ThreadNode *p) {
	while(p->ltag ==0){
		p->lchild;
	}
	return p;
}

ThreadNode *NextNode(ThreadNode *p) {
	if (p->rtag == 0) {
		return FirstNode(p->rchild);
	}
	else {
		return p->rchild;
	}
}

void InOrder(ThreadNode * T) {
	ThreadNode * p;
	for (p = FirstNode(T); p != NULL; p = NextNode(p)) {
		visit(p);
	}


}




