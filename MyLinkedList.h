#pragma once

typedef struct LinkedList{
	int val;
	struct LinkedList* next;
} MyLinkedList;


MyLinkedList* myLinkedListCreate();

MyLinkedList* GetNodeAtIndex(MyLinkedList* obj, int index);

int myLinkedListGet(MyLinkedList* obj, int index);

void myLinkedListAddAtHead(MyLinkedList* obj, int val);

void myLinkedListAddAtTail(MyLinkedList* obj, int val);

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val);

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index);

void myLinkedListFree(MyLinkedList* obj);

