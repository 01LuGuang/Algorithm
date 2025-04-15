#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//定义进程状态
typedef enum {Ready, Running, Finished} State;

//PCB进程控制块结构体
typedef struct PCB {
    char name[10]; //进程名
    int priority; //优先级
    int arrival_time; //到达时间
    int burst_time; //服务时间
    int start_time; //开始时间
    int finish_time; //完成时间
    State state; //进程当前状态
    struct PCB* next; //指向下一个进程的链表指针
} PCB;

/**
 * @brief 插入进程到链表末尾（保持简单插入顺序）
 */
void insert_process(PCB** head, PCB* new_pcb) {
    if(*head == NULL) {
        *head = new_pcb;
    } else {
        PCB* current = *head;
        while(current->next != NULL) {
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

    printf("\n==== 优先级调度(PR)开始 ====\n");

    while(1) {
        PCB* current = head;
        PCB* highest_priority_proc = NULL; //指向优先级最高的进程

        //遍历寻找当前时间下Ready且优先级最高的进程
        while(current != NULL) {
            if(current->state == Ready && current->arrival_time <= current_time) {
                if (highest_priority_proc == NULL || current->priority < highest_priority_proc->priority) {
                    highest_priority_proc = current;
                }
            }
            current = current->next;
        }

        //如果没找到合适的进程，继续增加时间寻找
        if(highest_priority_proc == NULL) {
            current_time++;
            if(current_time > 1000) break; //防止死循环
            continue;
        }

        //启动进程
        highest_priority_proc->start_time = current_time;
        highest_priority_proc->state = Running;
        printf("调度进程 %s （优先级： %d） 开始执行， 时间： %d\n",
            highest_priority_proc->name, highest_priority_proc->priority, current_time);

        current_time += highest_priority_proc->burst_time;
        highest_priority_proc->finish_time = current_time;
        highest_priority_proc->state = Finished;
        printf("进程 %s 完成运行， 时间：%d\n", highest_priority_proc->name, current_time);
    }
    printf("==== 优先级调度(PR)结束 ====\n");
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

    printf("请输入进程数量：");
    scanf("%d", &n);

    for(int i = 0; i < n; i ++) {
        PCB* new_pcb = (PCB*)malloc(sizeof(PCB));
        printf("\n请输入第 %d 个进程的名称：", i + 1);
        scanf("%s", &new_pcb->name);
        printf("请输入到达时间：");
        scanf("%d", &new_pcb->arrival_time);
        printf("请输入服务时间：");
        scanf("%d", &new_pcb->burst_time);
        printf("请输入优先级：");
        scanf("%d", &new_pcb->priority);

        new_pcb->state = Ready; //初始状态为就绪
        new_pcb->next = NULL;

        insert_process(&ready_queue, new_pcb); //插入新进程到就绪队列中
    }

    priority_schedule(ready_queue); //调用优先级调度函数
    print_processes(ready_queue); //打印进程调度结果

    //释放内存
    PCB* current = ready_queue;
    while(current != NULL) {
        PCB* temp = current;
        current = current->next;
        free(temp); //释放每个进程的内存
    }
    return 0;
}