#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

typedef int elementType;

struct list_el
{
	elementType element;
	struct list_el *next;
	struct list_el *prev;
};
typedef struct list_el dllist;

void makeNullList(dllist **root, dllist **cur, dllist **tail)
{
	*root = NULL;
	*cur = NULL;
	*tail = NULL;
}

dllist *makeNewNode(elementType data)
{
	dllist *New = (dllist *)malloc(sizeof(dllist));
	New->element = data;
	New->next = NULL;
	New->prev = NULL;
	return New;
}

void displayNode(dllist *p)
{
	if (p == NULL)
	{
		printf("ERROR pointer NULL\n");
		return;
	}
	printf(", %d", p->element);
}

void traversingList(dllist *root)
{
	dllist *cur;
	for (cur = root; cur != NULL; cur = cur->next)
	{
		displayNode(cur);
	}
}

void insertAtHead(elementType data, dllist **root, dllist **cur, dllist **tail)
{
	dllist *New = makeNewNode(data);
	if (*root == NULL)
	{
		*root = New;
		*tail = New;
		*cur = *root;
	}
	else
	{
		New->next = *root;
		(*root)->prev = New;
		*root = *cur = New;
	}
}

void AppendList(elementType data, dllist **root, dllist **cur, dllist **tail)
{
	dllist *New = makeNewNode(data);
	if ((*root) == NULL)
	{
		(*root) = New;
		(*tail) = New;
		(*cur) = (*root);
		New->next = New->prev = NULL;
	}
	else
	{
		New->prev = (*tail);
		(*tail)->next = New;
		(*tail) = (*cur) = New;
		New->next = NULL;
	}
}

void insertAfterCur(elementType data, dllist **root, dllist **cur, dllist **tail)
{
	dllist *New = makeNewNode(data);
	if (*root == NULL)
	{
		*root = New;
		*tail = New;
		*cur = *root;
	}
	else if (*cur == NULL)
	{
		printf("ERROR! There is no current.");
		return;
	}
	else
	{
		if (*cur == *tail)
		{
			(*cur)->next = New;
			New->prev = *cur;
			*tail = *cur = New;
		}
		else
		{
			New->next = (*cur)->next;
			New->prev = *cur;
			(*cur)->next->prev = New;
			(*cur)->next = New;
			*cur = New;
		}
	}
}

void insertBeforeCur(elementType data, dllist **root, dllist **cur, dllist **tail)
{
	dllist *New = makeNewNode(data);
	if (*root == NULL)
	{
		*root = New;
		*tail = New;
		*cur = *root;
	}
	else if (*cur == NULL)
	{
		printf("ERROR! There is no current.");
		return;
	}
	else
	{
		if (*cur == *root)
		{
			(*cur)->prev = New;
			New->next = *cur;
			*root = *cur = New;
		}
		else
		{
			New->next = *cur;
			New->prev = (*cur)->prev;
			(*cur)->prev->next = New;
			(*cur)->prev = New;
			*cur = New;
		}
	}
}

void insertAtPos(elementType data, dllist **root, dllist **cur, dllist **tail, int p)
{ // Dem tu 0
	int i;
	if (p == 0)
	{
		insertAtHead(data, root, cur, tail);
		return;
	}
	if (*root == NULL)
	{
		printf("There is no list");
		return;
	}
	for (i = 0, *cur = *root; i < p; i++)
	{
		if (*cur == *tail)
		{
			if (i == p - 1)
			{
				AppendList(data, root, cur, tail);
				return;
			}
			else
			{
				printf("Not enough element\n");
				return;
			}
		}
		*cur = (*cur)->next;
	}
	insertBeforeCur(data, root, cur, tail);
}

void deleteFirstElement(dllist **root, dllist **cur, dllist **tail)
{
	if (*root != NULL)
	{
		if (*root == *tail)
		{
			free(*root);
			makeNullList(root, cur, tail);
		}
		else
		{
			dllist *to_free;
			to_free = *root;
			*root = (*root)->next;
			(*root)->prev = NULL;
			free(to_free);
			*cur = *root;
		}
	}
}

void deleteLastElement(dllist **root, dllist **cur, dllist **tail)
{
	if (*tail != NULL)
	{
		if (*root == *tail)
		{
			free(*root);
			makeNullList(root, cur, tail);
		}
		else
		{
			dllist *to_free;
			to_free = *tail;
			*tail = (*tail)->prev;
			(*tail)->next = NULL;
			free(to_free);
			*cur = *tail;
		}
	}
}

void deleteCurElement(dllist **root, dllist **cur, dllist **tail)
{
	if (*cur != NULL)
	{
		if (*cur == *root)
		{
			deleteFirstElement(root, cur, tail);
		}
		else if (*cur == *tail)
		{
			deleteLastElement(root, cur, tail);
		}
		else
		{
			dllist *to_free;
			(*cur)->next->prev = (*cur)->prev;
			(*cur)->prev->next = (*cur)->next;
			to_free = *cur;
			*cur = (*cur)->next;
			free(to_free);
		}
	}
}

void deleteAtPos(dllist **root, dllist **cur, dllist **tail, int p)
{
	if (*root != NULL)
	{
		int i;
		for (i = 0, *cur = *root; i < p; i++)
		{
			if ((*cur)->next == NULL)
			{
				printf("Not enough element\n");
				return;
			}
			*cur = (*cur)->next;
		}
		deleteCurElement(root, cur, tail);
	}
}

void freeNode(dllist **root)
{
	dllist *to_free;
	for (to_free = *root; to_free != NULL; to_free = *root)
	{
		*root = to_free->next;
		free(to_free);
	}
}

// BST

typedef struct elm
{
	char word[50];
	int appearCount;
	dllist *rootLine, *curLine, *tailLine;
} elmType;

typedef struct node_type
{
	elmType element;
	struct node_type *left, *right;
} nodeType;

typedef nodeType *treetype; // treetype a <=> nodeType* a

void makeNullTree(treetype *N)
{
	(*N) = NULL;
}

nodeType *Create_Node(elmType data)
{
	nodeType *New = (nodeType *)malloc(sizeof(nodeType));
	if (New != NULL)
	{
		New->element = data;
		New->left = NULL;
		New->right = NULL;
	}
	return New;
}

int isEmptyTree(treetype N)
{
	return N == NULL;
}

treetype leftChild(treetype N)
{
	if (N != NULL)
		return N->left;
	else
		return NULL;
}

treetype rightChild(treetype N)
{
	if (N != NULL)
		return N->right;
	else
		return NULL;
}

int Compare(elmType a, elmType b)
{
	if (strcmp(a.word, b.word) > 0)
		return 1;
	else if (strcmp(a.word, b.word) < 0)
		return -1;
	else
		return 0;
}

void insertNode(treetype *T, elmType data)
{
	if (*T == NULL)
		(*T) = Create_Node(data);
	else
	{
		if (Compare(data, (*T)->element) == 1)
			insertNode(&(*T)->right, data);
		else
			insertNode(&(*T)->left, data);
	}
}

int isLeaf(treetype N)
{
	if (isEmptyTree(N))
	{
		return 0;
	}
	else
		return (N->left == NULL && N->right == NULL);
}

int countNode(treetype N)
{
	if (isEmptyTree(N))
		return 0;
	else
		return 1 + countNode(N->left) + countNode(N->right);
}

void inOrderLog(treetype T)
{
	if (T != NULL)
	{
		inOrderLog(T->left);
		printf("%s %d", T->element.word, T->element.appearCount);
		traversingList(T->element.rootLine);
		printf("\n");
		inOrderLog(T->right);
	}
}

int Max(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}

int treeHeight(treetype T)
{
	if (T == NULL)
	{
		return 0;
	}
	else
	{
		if (isLeaf(T))
			return 0;
		else
			return 1 + Max(treeHeight(T->left), treeHeight(T->right));
	}
}

int leafNode(treetype T)
{
	if (T == NULL)
	{
		return 0;
	}
	else
	{
		if (isLeaf(T))
			return 1;
		else
			return leafNode(T->left) + leafNode(T->right);
	}
}

int innerNode(treetype T)
{
	if (T == NULL)
	{
		return 0;
	}
	else
	{
		if (isLeaf(T))
			return 0;
		else
			return 1 + innerNode(T->left) + innerNode(T->right);
	}
}

int numRight(treetype T)
{
	if (T == NULL)
	{
		return 0;
	}
	else
	{
		if (T->right == NULL)
			return 0 + numRight(T->left);
		else
			return 1 + numRight(T->left) + numRight(T->right);
	}
}

treetype searchT(treetype T, elmType x)
{
	if (T == NULL)
		return T;
	if (Compare(x, T->element) == 0)
		return T;
	else if (isLeaf(T))
		return NULL;
	else if (Compare(x, T->element) == 1)
		return searchT(T->right, x);
	else
		return searchT(T->left, x);
}

elmType deletemin(treetype *n)
{
	elmType k;
	if ((*n)->left == NULL)
	{
		k = (*n)->element;
		(*n) = (*n)->right;
		return k;
	}
	else
		return deletemin(&(*n)->left);
}

void delete (treetype *n, elmType key)
{
	if (*n != NULL)
	{
		if (Compare(key, (*n)->element) == -1)
			delete (&(*n)->left, key);
		else if (Compare(key, (*n)->element) == 1)
			delete (&(*n)->right, key);
		else if ((*n)->left == NULL && (*n)->right == NULL)
			*n = NULL;
		else if ((*n)->left == NULL)
			*n = (*n)->right;
		else if ((*n)->right == NULL)
			*n = (*n)->left;
		else
			(*n)->element = deletemin(&(*n)->right);
	}
}

void freeTree(treetype T)
{
	if (T == NULL)
		return;
	freeTree(T->left);
	freeTree(T->right);
	freeNode(&(T->element.rootLine));
	free((void *)T);
}