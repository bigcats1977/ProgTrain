
#include <iostream>
#include "MyLinkedList.h"

MyLinkedList* myLinkedListCreate() {
	MyLinkedList* node = (MyLinkedList*)malloc(sizeof(MyLinkedList));
	if (NULL == node)
		return NULL;
	node->next = NULL;
	node->val = -1;
	return node;
}

MyLinkedList* GetNodeAtIndex(MyLinkedList* obj, int index) {
	MyLinkedList* node = obj;
	if (NULL == obj)
		return NULL;
	while (index >= 0 && node) {
		index--;
		node = node->next;
	}
	if (index < -1)
		return NULL;

	return node;
}

int myLinkedListGet(MyLinkedList* obj, int index) {
	MyLinkedList* node = GetNodeAtIndex(obj, index);
	if (NULL == node)
		return -1;
	return node->val;
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
	if (NULL == obj)
		return;
	MyLinkedList* node = (MyLinkedList*)malloc(sizeof(MyLinkedList));
	if (NULL == node)
		return;
	node->val = val;
	node->next = obj->next;
	obj->next = node;
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
	if (NULL == obj)
		return;
	MyLinkedList* prior = obj;
	MyLinkedList* node = (MyLinkedList*)malloc(sizeof(MyLinkedList));
	if (NULL == node)
		return;
	node->val = val;
	node->next = NULL;

	while (prior->next != NULL)
		prior = prior->next;
	prior->next = node;
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
	MyLinkedList* prior = GetNodeAtIndex(obj, index-1);
	if (NULL == prior)
		return;

	MyLinkedList* node = (MyLinkedList*)malloc(sizeof(MyLinkedList));
	if (NULL == node)
		return;
	node->val = val;
	node->next = prior->next;
	prior->next = node;
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
	MyLinkedList* prior = GetNodeAtIndex(obj, index - 1);
	if (NULL == prior)
		return;
	MyLinkedList* temp = prior->next;
	if (temp == NULL)
		return;
	prior->next = temp->next;
	free(temp);
}

void myLinkedListFree(MyLinkedList* obj) {
	MyLinkedList* temp;
	if (NULL == obj)
		return;
	while(obj!=NULL) {
		temp = obj;
		obj = obj->next;
		free(temp);
	}
}