#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define INSTRUCTIONS 320        // 总共的指令条数
#define PAGE_SIZE 10            // 每页10条指令
#define MAX_PAGES 32            // 最大虚拟页数（虚拟内存：32KB）
#define MIN_FRAMES 4            // 最小用户内存页数
#define MAX_FRAMES 32           // 最大用户内存页数

// 页面结构
typedef struct {
    int number;     // 页号
    int valid;      // 是否有效（在内存中）
} Page;

// 内存帧结构
typedef struct {
    Page *frames[MAX_FRAMES];  // 内存帧数组
    int size;                  // 当前内存大小（页数）
    int page_faults;           // 页面失效次数
} Memory;

// 检查某页是否已在内存中
int is_in_memory(Memory *mem, int page_num) {
    for (int i = 0; i < mem->size; i++) {
        if (mem->frames[i] != NULL && mem->frames[i]->number == page_num) {
            return 1;
        }
    }
    return 0;
}

// 返回该页在内存中的索引
int find_page_index(Memory *mem, int page_num) {
    for (int i = 0; i < mem->size; i++) {
        if (mem->frames[i] != NULL && mem->frames[i]->number == page_num) {
            return i;
        }
    }
    return -1;
}

// 初始化内存结构
void init_memory(Memory *mem, int size) {
    mem->size = size;
    mem->page_faults = 0;
    for (int i = 0; i < size; i++) {
        mem->frames[i] = NULL;
    }
}

// 释放内存
void free_memory(Memory *mem) {
    for (int i = 0; i < mem->size; i++) {
        if (mem->frames[i]) {
            free(mem->frames[i]);
            mem->frames[i] = NULL;
        }
    }
}

// 选择应被替换的页索引（使用OPT策略）
int find_opt_replacement(Memory *mem, int *seq, int curr_index, int total) {
    int farthest = -1;
    int index_to_replace = -1;

    for (int i = 0; i < mem->size; i++) {
        int page_num = mem->frames[i]->number;
        int j;
        for (j = curr_index + 1; j < total; j++) {
            if (seq[j] == page_num)
                break;
        }
        if (j == total) {
            return i;  // 当前页面在后续不再使用，立即返回
        }
        if (j > farthest) {
            farthest = j;
            index_to_replace = i;
        }
    }
    return index_to_replace;
}

// 模拟OPT页面置换过程
double simulate_opt(int *seq, int total_instructions, int frame_size) {
    Memory mem;
    init_memory(&mem, frame_size);

    int hits = 0;

    for (int i = 0; i < total_instructions; i++) {
        int page_num = seq[i];

        if (is_in_memory(&mem, page_num)) {
            hits++;
        } else {
            mem.page_faults++;
            int inserted = 0;

            // 找空位插入
            for (int j = 0; j < mem.size; j++) {
                if (mem.frames[j] == NULL) {
                    Page *new_page = (Page *)malloc(sizeof(Page));
                    new_page->number = page_num;
                    new_page->valid = 1;
                    mem.frames[j] = new_page;
                    inserted = 1;
                    break;
                }
            }

            // 无空位，需替换
            if (!inserted) {
                int replace_index = find_opt_replacement(&mem, seq, i, total_instructions);
                free(mem.frames[replace_index]);

                Page *new_page = (Page *)malloc(sizeof(Page));
                new_page->number = page_num;
                new_page->valid = 1;
                mem.frames[replace_index] = new_page;
            }
        }
    }

    double hit_rate = (double)hits / total_instructions;
    free_memory(&mem);
    return hit_rate;
}

// 构造320条指令序列，映射为页号序列（模拟局部性）
void generate_instruction_sequence(int *seq) {
    int i = 0;
    while (i < INSTRUCTIONS) {
        int m = rand() % 320;
        seq[i++] = m / PAGE_SIZE;
        if (i >= INSTRUCTIONS) break;
        seq[i++] = (m + 1) / PAGE_SIZE;
        if (i >= INSTRUCTIONS) break;
        m = rand() % m;
        seq[i++] = m / PAGE_SIZE;
        if (i >= INSTRUCTIONS) break;
        seq[i++] = (m + 2) / PAGE_SIZE;
    }
}

// 主函数：遍历不同内存大小，打印OPT命中率
int main() {
    srand((unsigned int)time(NULL));

    int sequence[INSTRUCTIONS];
    generate_instruction_sequence(sequence);

    for (int frame_size = MIN_FRAMES; frame_size <= MAX_FRAMES; frame_size++) {
        double hit_rate = simulate_opt(sequence, INSTRUCTIONS, frame_size);
        printf("Memory size: %2d pages, OPT: %.4f\n", frame_size, hit_rate);
    }

    return 0;
}
