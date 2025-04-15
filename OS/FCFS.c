#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//进程状态枚举
typedef enum {Ready, Running, Finished} State;

//PCB进程控制块结构体
typedef struct PCB {
    char name[10]; //进程名
    int arrival_time; //到达时间
    int burst_time; //服务时间
    int start_time; //开始时间
    int finish_time; //完成时间
    State state; //进程当前状态
    struct PCB* next; //指向下一个进程的链表指针
} PCB;

//进程调度函数，使用FCFS算法
/**
 * @brief 插入新进程到就绪队列中（按到达时间排序）
 * 
 * @param head 指向就绪队列头指针的指针
 * @param new_pcb 要插入的进程指针
 */
void insert_process(PCB** head, PCB* new_pcb) {
    if (*head == NULL || new_pcb->arrival_time < (*head)->arrival_time) {
        new_pcb = *head;
        *head = new_pcb;
    }else {
        PCB* current = *head;
        while(current->next != NULL && current->next->arrival_time < new_pcb->arrival_time) {
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
    int current_time = 0; //当前时间
    PCB* current = head; //当前进程指针
    
    printf("\n==== FCFS 调度开始 ====\n");

    while(current != NULL) {
        //如果当前时间小于到达时间，需要空等
        if (current_time < current->arrival_time) {
            current_time = current->arrival_time; //更新当前时间
        }

        current->start_time = current_time; //设置开始时间
        current->state = Running;
        printf("进程 %s 开始执行， 开始时间： %d\n", current->name, current_time);

        current_time += current->burst_time; //更新当前时间
        current->finish_time = current_time; //设置完成时间
        current->state = Finished;
        printf("进程 %s 执行完成， 完成时间： %d\n", current->name, current_time);

        current = current->next; //继续调用下一个进程
    }

    printf("==== FCFS 调度结束 ====\n");
}

/**
 * @brief 打印所有进程的调度信息（包括开始时间和结束时间）
 * 
 * @param head 就绪队列头指针
 */
void print_processes(PCB** head) {
    PCB* current = *head;

    printf("\n==== 进程调度信息 ====\n");
    printf("进程名\t到达时间\t服务时间\t开始时间\t结束时间\n");
    while(current != NULL) {
        printf("%s\t%d\t\t%d\t\t%d\t\t%d\t\n",
            current->name,
            current->arrival_time,
            current->burst_time,
            current->start_time,
            current->finish_time);

        current = current->next;
    }
}


int main() {
    PCB* ready_queue = NULL; //就绪队列头指针,初始化为空

    int n;
    printf("请输入进程数量：");
    scanf("%d", &n);

    for(int i = 0; i < n; i ++) {
        PCB* new_pcb = (PCB*)malloc(sizeof(PCB)); //动态分配内存
        printf("\n请输入第 %d 个进程的名称：", i + 1);
        scanf("%s", new_pcb->name);
        printf("请输入到达时间：");
        scanf("%d", &new_pcb->arrival_time);
        printf("请输入运行时间：");
        scanf("%d", &new_pcb->burst_time);

        new_pcb->state = Ready;
        new_pcb->next = NULL;

        insert_process(&ready_queue, new_pcb); //插入新进程到就绪队列中
    }

    //调度并打印
    fcfs_schedule(ready_queue);
    print_processes(&ready_queue);

    //释放内存
    PCB* current = ready_queue;
    while(current != NULL) {
        PCB* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}