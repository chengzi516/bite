#define _CRT_SECURE_NO_WARNINGS 1
typedef struct {
    int* arr;
    int front;
    int capacity;
} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* q = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    q->arr = (int*)malloc(sizeof(int) * (k + 1));
    q->capacity = k + 1;
    q->front = 0;
    return q;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if (front % obj->capacity == 0) {
        return false;
    }
    obj->arr[obj->rear] = value;
    obj->rear = (obj->rear + 1) % obj->capacity;
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if (obj->rear == obj->front) {
        return false;
    }
    obj->front = (obj->front + 1) % obj->capacity;
    return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
    if (obj->rear == obj->front) {
        return -1;
    }
    return obj->arr[obj->front];
}

int myCircularQueueRear(MyCircularQueue* obj) {
    if (obj->rear == obj->front) {
        return -1;
    }
    // return obj->arr[(obj->rear-1+obj->capcity)%obj->capcity];
    return obj->arr[obj->rear];
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return obj->front == obj->rear;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return (obj->rear + 1) % (obj->capacity) == obj->front;
}

void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->arr);
    free(obj);
}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);

 * bool param_2 = myCircularQueueDeQueue(obj);

 * int param_3 = myCircularQueueFront(obj);

 * int param_4 = myCircularQueueRear(obj);

 * bool param_5 = myCircularQueueIsEmpty(obj);

 * bool param_6 = myCircularQueueIsFull(obj);

 * myCircularQueueFree(obj);
*/