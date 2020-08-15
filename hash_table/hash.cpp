#include "hash.h"
#include "stdlib.h"
#include "string.h"
#include "stdio.h"

unsigned int Hash(ElementType Key,int TableSize){
	unsigned int HashValue=0;
	while(*Key!='\0'){
		HashValue=(HashValue<<5)+*Key++;
	}
	return HashValue % TableSize;
}

HashTable InitHashTable(int Size){
	HashTable H=(HashTable)malloc(sizeof(struct HashNode));
	H->TableSize=Size;
	H->TheLists=(List*)malloc(sizeof(List)*H->TableSize);
	for(int i=0;i<H->TableSize;i++){
		H->TheLists[i]=(List)malloc(sizeof(struct ListNode));
		H->TheLists[i]->Next=NULL;
		H->TheLists[i]->Element=(char*)malloc(sizeof(char)*10);
	}
	return H;
}

Position Find(ElementType Key,HashTable H){
	int Index=Hash(Key,H->TableSize);	
	List P=H->TheLists[Index]->Next;
	while(P && strcmp(Key,P->Element)!=0 )
		P=P->Next;
	return P;
}

Position Insert(ElementType Key,HashTable H){
	Position P=Find(Key,H);
	
	if(!P){
		List L=H->TheLists[Hash(Key,H->TableSize)];
		List Temp=(List)malloc(sizeof(struct ListNode));
		Temp->Element=(char*)malloc(sizeof(char)*10);
		strcpy(Temp->Element,Key);
		Temp->Next=L->Next;
		L->Next=Temp;
		return L;
	}
	return NULL;
}
