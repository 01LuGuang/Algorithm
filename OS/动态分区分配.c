#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TOTAL_MEMORY 640

typedef enum { FIRST_FIT = 1, BEST_FIT, WORST_FIT } FitAlgorithm;

// 内存分区结构体
typedef struct Block {
    int start;              // 分区起始地址
    int size;               // 分区大小
    int is_allocated;       // 是否已分配
    struct Block *next;     // 下一个分区
} Block;

Block *free_list = NULL;     // 空闲分区表
Block *allocated_list = NULL; // 已分配分区表
FitAlgorithm current_alg = FIRST_FIT; // 默认首次适应

// 初始化内存为一个完整的空闲块
void init_memory() {
    free_list = (Block *)malloc(sizeof(Block));
    free_list->start = 0;
    free_list->size = TOTAL_MEMORY;
    free_list->is_allocated = 0;
    free_list->next = NULL;

    allocated_list = NULL;
}

// 打印分区状态
void print_memory(Block *list, const char *type) {
    printf("==========%s Table==========\n", strcmp(type, "Free") == 0 ? "Unallocated" : "Allocated");
    printf("| Index | Address | End | Size |\n");
    printf("---------------------------------\n");
    Block *cur = list;
    int index = 0;
    while (cur != NULL) {
        printf("%5d   %7d   %6d   %4d\n", index++, cur->start, cur->start + cur->size - 1, cur->size);
        cur = cur->next;
    }
    printf("\n");
}

// 插入已分配列表
void insert_allocated(Block *block) {
    Block *new_block = (Block *)malloc(sizeof(Block));
    *new_block = *block;
    new_block->next = allocated_list;
    allocated_list = new_block;
}

// 从已分配分区表中移除指定分区（按起始地址和大小）
Block* remove_allocated(int start, int size) {
    Block *prev = NULL, *cur = allocated_list;
    while (cur) {
        if (cur->start == start && cur->size == size) {
            if (prev) prev->next = cur->next;
            else allocated_list = cur->next;
            return cur;
        }
        prev = cur;
        cur = cur->next;
    }
    return NULL;
}

// 分割内存块
void split_block(Block *block, int size) {
    Block *new_free = (Block *)malloc(sizeof(Block));
    new_free->start = block->start + size;
    new_free->size = block->size - size;
    new_free->is_allocated = 0;
    new_free->next = block->next;

    block->size = size;
    block->next = new_free;
}

// 根据不同的算法来查找实现
Block* find_fit(Block **prev, int size) {
    Block *cur = free_list, *best = NULL, *worst = NULL, *prev_ptr = NULL, *best_prev = NULL, *worst_prev = NULL;

    while (cur) {
        if (!cur->is_allocated && cur->size >= size) {
            // 首次适应：找到第一个合适的空闲块
            if (current_alg == FIRST_FIT) {
                *prev = prev_ptr;
                return cur;
            // 最佳适应：找到最小且能用的空闲块
            } else if (current_alg == BEST_FIT) {
                if (!best || cur->size < best->size) {
                    best = cur;
                    best_prev = prev_ptr;
                }
            // 最坏适应：找到最大的空闲块
            } else if (current_alg == WORST_FIT) {
                if (!worst || cur->size > worst->size) {
                    worst = cur;
                    worst_prev = prev_ptr;
                }
            }
        }
        prev_ptr = cur;
        cur = cur->next;
    }

    if (current_alg == BEST_FIT && best) {
        *prev = best_prev;
        return best;
    }
    if (current_alg == WORST_FIT && worst) {
        *prev = worst_prev;
        return worst;
    }

    return NULL;
}

// 分配内存
void allocate_memory(int size) {
    Block *prev = NULL;
    Block *fit = find_fit(&prev, size);

    if (!fit) {
        printf("No suitable block found.\n");
        return;
    }
    
    // 如果空闲块大于需求，分割空闲块
    if (fit->size > size) {
        split_block(fit, size);
    }

    fit->is_allocated = 1;
    insert_allocated(fit);

    // 从空闲表中移除该块
    if (prev) prev->next = fit->next;
    else free_list = fit->next;

    printf("Allocation Success! ADDRESS= %d\n", fit->start);
}

// 合并空闲区块
void merge_free_blocks() {
    Block *cur = free_list;
    while (cur && cur->next) {
        if (cur->start + cur->size == cur->next->start) {
            cur->size += cur->next->size;
            Block *tmp = cur->next;
            cur->next = tmp->next;
            free(tmp);
        } else {
            cur = cur->next;
        }
    }
}

// 释放内存
void deallocate_memory(int address, int size) {
    // 从已分配表中移除对应分区
    Block *reclaim = remove_allocated(address, size);
    if (!reclaim) {
        printf("Block not found.\n");
        return;
    }

    reclaim->is_allocated = 0;
    reclaim->next = NULL;

    // 插入到空闲表并按起始地址排序
    if (!free_list || reclaim->start < free_list->start) {
        reclaim->next = free_list;
        free_list = reclaim;
    } else {
        Block *cur = free_list;
        while (cur->next && cur->next->start < reclaim->start) {
            cur = cur->next;
        }
        reclaim->next = cur->next;
        cur->next = reclaim;
    }

    // 合并相邻空闲块
    merge_free_blocks();
    printf("Deallocation Success! ADDRESS= %d%d\n", address, size);
}

// 设置分配算法
void set_algorithm() {
    printf("Select allocation algorithm(Enter the number): 1. First Fit  2. Best Fit  3. Worst Fit\n");
    int alg;
    scanf("%d", &alg);
    if (alg >= 1 && alg <= 3) {
        current_alg = (FitAlgorithm)alg;
        printf("Algorithm set to %s\n", alg == 1 ? "First Fit" : (alg == 2 ? "Best Fit" : "Worst Fit"));
    } else {
        printf("Invalid selection. Defaulting to First Fit.\n");
        current_alg = FIRST_FIT;
    }
}



int main() {
    init_memory();
    set_algorithm();

    char op;
    int size, addr;

    while (1) {
        print_memory(free_list, "Free");
        print_memory(allocated_list, "Allocated");

        printf("Enter the allocate or reclaim (a/r), or press other key to exit: ");
        scanf(" %c", &op);

        if (op == 'a') {
            printf("Input application: ");
            scanf("%d", &size);
            allocate_memory(size);
        } else if (op == 'r') {
            printf("Input address and size to reclaim: ");
            scanf("%d%d", &addr, &size);
            deallocate_memory(addr, size);
        } else {
            break;
        }
    }

    return 0;
}
