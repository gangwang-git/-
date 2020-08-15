#ifndef HASH_H
#define HASH_H

typedef char* ElementType;
struct ListNode;
typedef struct ListNode* Position;
typedef Position List;
struct HashNode;
typedef struct HashNode* HashTable;

unsigned int Hash(ElementType Key,int TableSize);
HashTable InitHashTable(int Size);
Position Find(ElementType Key,HashTable H);
Position Insert(ElementType Key,HashTable H);
#endif

struct ListNode{
	ElementType Element;
	struct ListNode* Next;
};

struct HashNode{
	int TableSize;
	List* TheLists;
};
