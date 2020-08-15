#include "hash.h"
#include "stdio.h"

int main(){
	HashTable H=InitHashTable(11);
	char str[10][10]={"abcd","jsflkla","fngk","ashf","asjfklj","hhdg","wfeee","fjskah","jkl","bajke"};
	for(int i=0;i<10;i++){
		printf("%s  %d\n",str[i],Hash(str[i],11));
		Insert(str[i],H);
	}
	for(int i=0;i<10;i++){
		List P=Find(str[i],H);
		printf("%s\n",P->Element);
	}
	return 0;
}
