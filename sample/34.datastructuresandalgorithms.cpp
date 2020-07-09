#include <iostream>

# define TREESIZE 100

typedef char Element;

/**
 *  孩子双亲表示法
 */

// 孩子节点
typedef struct CTNode{
    int child; // 孩子的下标
    struct CTNode *next; // 链式存储，连接兄弟节点
} *CTNodePtr;

// 父节点
typedef struct {
    Element data; // 存放的数据 A/C
    int parent; // 父节点的下标
    CTNodePtr firstChild; // 第一个自孩子的 CTNode*
} CTree;

typedef struct {
    CTree nodes[TREESIZE]; // 存放节点的数组
    int root; // 根节点的位置
    int size; // 节点的个数
};

int main(){
    // Tree tree;
    // tree.root = 0;
    // tree[0] = CTree
}

