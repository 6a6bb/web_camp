#ifndef BINARYTREE_H_INCLUDED
#define BINARYTREE_H_INCLUDED
#define ok          0
#define error       1

typedef char TElemType;     // �������������Ԫ������Ϊ�ַ�


typedef struct BiTNode {
    TElemType      data;     // ������
    struct BiTNode  *lchild,*rchild;  // ���Һ���ָ��
} BiTNode, *BiTree;   // ��������

typedef enum Status{
	SUCCESS,
	ERROR
}Status;

//ջ
typedef struct
{
	float data[100];
	int top;
}DATA;


/**
 *  @name        : Status InitBiTree(BiTree T);
 *  @description : ����ն�����T
 *  @param       : �����������T
 */
Status InitBiTree(BiTree T);


/**
 *  @name        : Status DestroyBiTree(BiTree T);
 *  @description : �ݻٶ�����T
 *  @param       : �����������T
 */
Status DestroyBiTree(BiTree T);


/**
 *  @name        : BiTNode* createBiTree(BiTree T,char* definition);
 *  @description : ���������T
 *  @param       : �����������T, ��������������ַ���definition
 */
Status CreateBiTree(BiTree T, char* definition);


/**
 *  @name        : Status PreOrderTraverse(BiTree T, Status (*visit)(TElemType e));
 *  @description : �������������T
 *  @param       : �����������T, �Խ��Ĳ�������visit
 */
Status PreOrderTraverse(BiTree T, Status (*visit)(TElemType e));


/**
 *  @name        : Status InOrderTraverse(BiTree T, Status (*visit)(TElemType e));
 *  @description : �������������T
 *  @param       : �����������T, �Խ��Ĳ�������visit
 */
Status InOrderTraverse(BiTree T, Status (*visit)(TElemType e));


/**
 *  @name        : Status PostOrderTraverse(BiTree T, Status (*visit)(TElemType e)));
 *  @description : �������������T
 *  @param       : �����������T, �Խ��Ĳ�������visit
 */
Status PostOrderTraverse(BiTree T, Status (*visit)(TElemType e));


/**
 *  @name        : Status LevelOrderTraverse(BiTree T, Status (*visit)(TElemType e));
 *  @description : �������������T
 *  @param       : �����������T, �Խ��Ĳ�������visit
 */
BiTNode* createBiTree(BiTNode*node,char* definition);


/**
 *  @name        : int Value(BiTree T);
 *  @description : �Թ������ǰ׺���ʽ��������ֵ
 *  @param       : �����������T
 *  @note        : ���ڽ��ṹ�������ø�Tagֵ��־������������������������
 *                 �ɸ�����Ҫ�������Ӳ���.
 */
int Value(BiTree T);

/**
 *  @name        : Status PreOrderByLoop(BiTree T, Status (*visit)(TElemType e));
 *  @description : �������������T���ǵݹ飩
 *  @param       : �����������T, �Խ��Ĳ�������visit
 */
Status PreOrderByLoop(BiTree T, Status (*visit)(TElemType e));


/**
 *  @name        : Status InOrderByLoop(BiTree T, Status (*visit)(TElemType e));
 *  @description : �������������T���ǵݹ飩
 *  @param       : �����������T, �Խ��Ĳ�������visit
 */
Status InOrderByLoop(BiTree T, Status (*visit)(TElemType e));


/**
 *  @name        : Status InOrderByLoop(BiTree T, Status (*visit)(TElemType e));
 *  @description : �������������T���ǵݹ飩
 *  @param       : �����������T, �Խ��Ĳ�������visit
 */
Status PostOrderByLoop(BiTree T, Status (*visit)(TElemType e));



#endif // BINARYTREE_H_INCLUDED
