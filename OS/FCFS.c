#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 进程状态枚举
typedef enum { READY, RUNNING, FINISHED } State;

// PCB（进程控制块）结构体
typedef struct PCB {
    char name[10];       // 进程名称
    int arrival_time;    // 到达时间
    int burst_time;      // 执行时间
    int start_time;      // 实际开始执行的时间
    int finish_time;     // 完成时间
    State state;         // 当前状态
    struct PCB* next;    // 链表指针
} PCB;

// 函数声明
void insert_process(PCB** head, PCB* new_pcb);
void fcfs_schedule(PCB* head);
void print_processes(PCB* head);

/**
 * @brief 插入新进程到就绪队列中（按到达时间排序）
 * 
 * @param head 指向就绪队列头指针的指针
 * @param new_pcb 要插入的进程指针
 */
void insert_process(PCB** head, PCB* new_pcb) {
    if (*head == NULL || new_pcb->arrival_time < (*head)->arrival_time) {
        new_pcb->next = *head;
        *head = new_pcb;
    } else {
        PCB* current = *head;
        while (current->next != NULL && current->next->arrival_time <= new_pcb->arrival_time) {
            current = current->next;
        }
        new_pcb->next = current->next;
        current->next = new_pcb;
    }
}

/**
 * @brief 实现 FCFS 调度算法模拟
 * 
 * @param head 就绪队列头指针
 */
void fcfs_schedule(PCB* head) {
    int current_time = 0;
    PCB* current = head;

    printf("\n=== FCFS 调度开始 ===\n");

    while (current != NULL) {
        // 如果当前时间小于到达时间，需要空等
        if (current_time < current->arrival_time) {
            current_time = current->arrival_time;
        }

        current->start_time = current_time;                   // 设置进程开始时间
        current->state = RUNNING;
        printf("调度进程 %s 开始运行，时间: %d\n", current->name, current_time);

        current_time += current->burst_time;                  // 模拟运行
        current->finish_time = current_time;                  // 记录完成时间
        current->state = FINISHED;

        printf("进程 %s 完成运行，时间: %d\n", current->name, current_time);

        current = current->next;                              // 继续调度下一个进程
    }

    printf("=== FCFS 调度结束 ===\n\n");
}

/**
 * @brief 打印所有进程的调度信息（包括开始时间和结束时间）
 * 
 * @param head 就绪队列头指针
 */
void print_processes(PCB* head) {
    PCB* current = head;

    printf("进程名\t到达时间\t运行时间\t开始时间\t结束时间\n");
    while (current != NULL) {
        printf("%s\t%d\t\t%d\t\t%d\t\t%d\n",
            current->name,
            current->arrival_time,
            current->burst_time,
            current->start_time,
            current->finish_time);
        current = current->next;
    }
}

int main() {
    PCB* ready_queue = NULL; // 初始化就绪队列为空
    int n;

    printf("请输入进程数量: ");
    scanf("%d", &n);

    // 循环输入每个进程的信息
    for (int i = 0; i < n; ++i) {
        PCB* new_pcb = (PCB*)malloc(sizeof(PCB)); // 动态分配PCB结构
        printf("\n输入第 %d 个进程的名称: ", i + 1);
        scanf("%s", new_pcb->name);
        printf("输入到达时间: ");
        scanf("%d", &new_pcb->arrival_time);
        printf("输入运行时间: ");
        scanf("%d", &new_pcb->burst_time);

        new_pcb->state = READY;
        new_pcb->next = NULL;

        insert_process(&ready_queue, new_pcb); // 插入到就绪队列中
    }

    // 调度与打印
    fcfs_schedule(ready_queue);
    print_processes(ready_queue);

    // 释放内存
    PCB* current = ready_queue;
    while (current != NULL) {
        PCB* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
