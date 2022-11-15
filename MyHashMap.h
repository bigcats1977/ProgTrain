#pragma once

typedef struct {
    int values[100000];
} MyHashMap;
MyHashMap* myHashMapCreate();
void myHashMapPut(MyHashMap* obj, int key, int value);
int myHashMapGet(MyHashMap* obj, int key);
void myHashMapRemove(MyHashMap* obj, int key);
void myHashMapFree(MyHashMap* obj);

