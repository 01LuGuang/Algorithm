#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 定义进程状态
typedef enum { READY, RUNNING, FINISHED } State;

// PCB结构体定义
typedef struct PCB {
    char name[10];         // 进程名称
    int arrival_time;      // 到达时间
    int burst_time;        // 执行时间
    int priority;          // 优先级（数值越小，优先级越高）
    int start_time;        // 开始时间
    int finish_time;       // 完成时间
    State state;           // 状态
    struct PCB* next;
} PCB;

/**
 * @brief 插入进程到链表末尾（保持简单插入顺序）
 */
void insert_process(PCB** head, PCB* new_pcb) {
    if (*head == NULL) {
        *head = new_pcb;
    } else {
        PCB* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_pcb;
    }
}

/**
 * @brief 非抢占式优先级调度算法实现
 */
void priority_schedule(PCB* head) {
    int current_time = 0;
    printf("\n=== 优先级调度（PR）开始 ===\n");

    while (1) {
        PCB* current = head;
        PCB* highest_priority_proc = NULL;

        // 寻找当前时间下 READY 且优先级最高的进程
        while (current != NULL) {
            if (current->state == READY && current->arrival_time <= current_time) {
                if (highest_priority_proc == NULL || current->priority < highest_priority_proc->priority) {
                    highest_priority_proc = current;
                }
            }
            current = current->next;
        }

        // 如果没有找到合适进程，则时间+1继续寻找
        if (highest_priority_proc == NULL) {
            current_time++;
            if (current_time > 1000) break; // 防止死循环
            continue;
        }

        // 启动该进程
        highest_priority_proc->start_time = current_time;
        highest_priority_proc->state = RUNNING;
        printf("调度进程 %s（优先级: %d）开始运行，时间: %d\n", 
            highest_priority_proc->name, highest_priority_proc->priority, current_time);

        current_time += highest_priority_proc->burst_time;
        highest_priority_proc->finish_time = current_time;
        highest_priority_proc->state = FINISHED;
        printf("进程 %s 完成运行，时间: %d\n", highest_priority_proc->name, current_time);
    }

    printf("=== 优先级调度结束 ===\n\n");
}

/**
 * @brief 输出进程调度结果
 */
void print_processes(PCB* head) {
    PCB* current = head;
    printf("进程名\t到达时间\t运行时间\t优先级\t开始时间\t结束时间\n");
    while (current != NULL) {
        printf("%s\t%d\t\t%d\t\t%d\t%d\t\t%d\n",
            current->name,
            current->arrival_time,
            current->burst_time,
            current->priority,
            current->start_time,
            current->finish_time);
        current = current->next;
    }
}

int main() {
    PCB* ready_queue = NULL;
    int n;

    printf("请输入进程数量: ");
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        PCB* new_pcb = (PCB*)malloc(sizeof(PCB));
        printf("\n输入第 %d 个进程的名称: ", i + 1);
        scanf("%s", new_pcb->name);
        printf("输入到达时间: ");
        scanf("%d", &new_pcb->arrival_time);
        printf("输入运行时间: ");
        scanf("%d", &new_pcb->burst_time);
        printf("输入优先级（数值越小优先级越高）: ");
        scanf("%d", &new_pcb->priority);

        new_pcb->state = READY;
        new_pcb->next = NULL;

        insert_process(&ready_queue, new_pcb);
    }

    priority_schedule(ready_queue);
    print_processes(ready_queue);

    // 清理内存
    PCB* current = ready_queue;
    while (current != NULL) {
        PCB* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
