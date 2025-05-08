#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define INSTRUCTION_NUM 320       // 总指令数
#define PAGE_SIZE 10              // 每页存10条指令
#define VIRTUAL_PAGE_NUM 32       // 虚拟页数
#define MAX_FRAMES 32             // 最大页框数
#define MIN_FRAMES 4              // 最小页框数

// 生成的页面序列
int page_sequence[INSTRUCTION_NUM];

// 页面队列，用于FIFO
int page_queue[MAX_FRAMES];     // FIFO队列，存放当前内存中的页面号
int queue_front, queue_rear;    // 队列头尾指针

// 判断页面是否在内存中（返回索引或-1）
int in_memory(int page, int memory[], int frame_count) {
    for (int i = 0; i < frame_count; i++) {
        if (memory[i] == page)
            return i;
    }
    return -1;
}

// 队列操作：插入页面到队尾
void enqueue(int page, int frame_count) {
    page_queue[queue_rear] = page;
    queue_rear = (queue_rear + 1) % frame_count;
}

// 队列操作：移除队头页面
int dequeue(int frame_count) {
    int removed = page_queue[queue_front];
    queue_front = (queue_front + 1) % frame_count;
    return removed;
}

// 生成指令序列并转化为页面序列（页号）
void generate_page_sequence() {
    srand(time(0));
    int instruction_count = 0;
    while (instruction_count < INSTRUCTION_NUM) {
        int m = rand() % 320;
        page_sequence[instruction_count++] = m / PAGE_SIZE;
        if (instruction_count >= INSTRUCTION_NUM) break;

        page_sequence[instruction_count++] = (m + 1) / PAGE_SIZE;
        if (instruction_count >= INSTRUCTION_NUM) break;

        int m2 = rand() % m;
        page_sequence[instruction_count++] = m2 / PAGE_SIZE;
        if (instruction_count >= INSTRUCTION_NUM) break;

        page_sequence[instruction_count++] = (m2 + 1) / PAGE_SIZE;
    }
}

// FIFO 页面置换算法
float FIFO(int frame_count) {
    int memory[frame_count];
    int page_faults = 0;
    int page_count = 0;

    for (int i = 0; i < frame_count; i++)
        memory[i] = -1;  // 初始化内存为空

    queue_front = queue_rear = 0;

    for (int i = 0; i < INSTRUCTION_NUM; i++) {
        int page = page_sequence[i];
        if (in_memory(page, memory, frame_count) != -1) {
            // 命中，跳过
            continue;
        }

        // 页面失效
        page_faults++;

        if (page_count < frame_count) {
            // 有空位，直接放入
            memory[page_count] = page;
            enqueue(page, frame_count);
            page_count++;
        } else {
            // 队列满了，替换最旧页面
            int old_page = dequeue(frame_count);
            // 找到并替换旧页面
            for (int j = 0; j < frame_count; j++) {
                if (memory[j] == old_page) {
                    memory[j] = page;
                    break;
                }
            }
            enqueue(page, frame_count);
        }
    }

    // 返回命中率
    return 1 - (float)page_faults / INSTRUCTION_NUM;
}

// 主函数
int main() {
    generate_page_sequence();

    for (int frames = MIN_FRAMES; frames <= MAX_FRAMES; frames++) {
        float hit_rate = FIFO(frames);
        printf("%2d page frames  FIFO: %.4f\n", frames, hit_rate);
    }

    return 0;
}