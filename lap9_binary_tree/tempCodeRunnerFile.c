typedef struct Treenode
{
    char data;
    struct Treenode *leftChild;
    struct Treenode *rightChild;
    struct Treenode *next;
    struct Treenode *mother;

} Treenode;