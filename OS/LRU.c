#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define INSTRUCTION_NUM 320     // 指令总数，共 320 条
#define PAGE_SIZE 10            // 每页存放 10 条指令
#define VIRTUAL_PAGE_NUM 32     // 虚拟页数 = 320 指令 / 每页 10 条 = 32 页
#define MAX_FRAMES 32           // 最大可用页框数
#define MIN_FRAMES 4            // 最小可用页框数


// 链表节点结构体（用于 LRU 页面管理）
typedef struct Node {
    int page;               // 页号
    struct Node* prev;      // 前驱节点
    struct Node* next;      // 后继节点
} Node;

// 指令对应的页面访问序列
int page_sequence[INSTRUCTION_NUM];

// 创建链表节点
Node* create_node(int page) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->page = page;
    node->prev = NULL;
    node->next = NULL;
    return node;
}

// 将节点插入到链表头（表示最近使用）
void insert_front(Node** head, Node** tail, Node* node) {
    node->next = *head;
    node->prev = NULL;
    if (*head != NULL) {
        (*head)->prev = node;
    } else {
        *tail = node;  // 原链表为空
    }
    *head = node;
}

// 删除链表尾节点（表示最久未使用）
void remove_tail(Node** head, Node** tail) {
    if (*tail == NULL) return;
    Node* old_tail = *tail;
    if (old_tail->prev != NULL) {
        *tail = old_tail->prev;
        (*tail)->next = NULL;
    } else {
        // 只有一个节点
        *head = *tail = NULL;
    }
    free(old_tail);
}

// 将某节点移至链表头部（最近使用）
void move_to_front(Node** head, Node** tail, Node* node) {
    if (*head == node) return;

    // 断链
    if (node->prev) node->prev->next = node->next;
    if (node->next) node->next->prev = node->prev;

    if (*tail == node) *tail = node->prev;

    // 插入头部
    node->prev = NULL;
    node->next = *head;
    if (*head) (*head)->prev = node;
    *head = node;
}

// 查找链表中是否存在某页
Node* find_node(Node* head, int page) {
    Node* curr = head;
    while (curr != NULL) {
        if (curr->page == page) return curr;
        curr = curr->next;
    }
    return NULL;
}

// 生成指令序列对应的页面访问序列
void generate_page_sequence() {
    srand(time(0));
    int count = 0;
    while (count < INSTRUCTION_NUM) {
        int m = rand() % 320;
        page_sequence[count++] = m / PAGE_SIZE;
        if (count >= INSTRUCTION_NUM) break;
        page_sequence[count++] = (m + 1) / PAGE_SIZE;
        if (count >= INSTRUCTION_NUM) break;
        int m2 = rand() % m;
        page_sequence[count++] = m2 / PAGE_SIZE;
        if (count >= INSTRUCTION_NUM) break;
        page_sequence[count++] = (m2 + 1) / PAGE_SIZE;
    }
}

// 模拟 LRU 算法，返回命中率（链表实现）
float simulate_lru_linked(int frame_count) {
    Node* head = NULL;  // 表头：最近使用
    Node* tail = NULL;  // 表尾：最久未用
    int page_faults = 0;  // 缺页次数
    int current_size = 0; // 当前页面数

    for (int i = 0; i < INSTRUCTION_NUM; i++) {
        int page = page_sequence[i];
        Node* found = find_node(head, page);

        if (found) {
            // 命中：移动到表头
            move_to_front(&head, &tail, found);
        } else {
            // 缺页：创建新节点
            page_faults++;
            Node* new_node = create_node(page);
            insert_front(&head, &tail, new_node);
            current_size++;

            // 超出内存容量：移除最久未使用页面
            if (current_size > frame_count) {
                remove_tail(&head, &tail);
                current_size--;
            }
        }
    }

    // 释放链表空间
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 1 - (float)page_faults / INSTRUCTION_NUM;
}


int main() {
    generate_page_sequence();

    for (int frames = MIN_FRAMES; frames <= MAX_FRAMES; frames++) {
        float hit_rate = simulate_lru_linked(frames);
        printf("%2d page frames  LRU : %.4f\n", frames, hit_rate);
    }

    return 0;
}
