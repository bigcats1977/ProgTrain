#include <stdlib.h>
#include <memory.h>
#include "MyHashMap.h"
MyHashMap* myHashMapCreate() {
    MyHashMap* obj = (MyHashMap*)malloc(sizeof(MyHashMap));
    memset(obj->values, -1, 100000 * sizeof(int));
    return obj;
}
void myHashMapPut(MyHashMap* obj, int key, int value) {
    obj->values[key] = value;
}
int myHashMapGet(MyHashMap* obj, int key) {
    return obj->values[key];
}
void myHashMapRemove(MyHashMap* obj, int key) {
    obj->values[key] = -1;
}
void myHashMapFree(MyHashMap* obj) {
}
