//Sort an array of strings so that 
//all the anagrams are next to each other

#include <iostream.h>
#include <hash_map.h>
using namespace std;

typedef struct _node{
	int data;
	struct _node* next;
}Node;

typedef struct _list{
	Node* list;
}List;

//I didn't implement these three functions.
char* sortString(char* string);
void addToLinkedList(List* list,char* string);
List* createLinkedList();

void sort(char* string[]){
	hash_map<char*,List*> set;
	int i=0;
	//group words by anagram
	while(string[i]!='\0'){
		//sort the string
		char* key=sortString(string[i]);
		//if not in the hash map
		if(set.find(key)==set.end()){
			set[key]=createLinkedList();
		}
		addToLinkedList(set[key],string[i]);
		i++;
	}
	//convert hash map to array
	i=0;
	for(hash_map<char*,List*>::iterator it=set.begin();it!=set.end();set++){
		string[i]=it->list->data;
		i++;
	}
}
