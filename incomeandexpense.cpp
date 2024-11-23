#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100

typedef struct {
    char date[11];
    float amount;
    char category[20];
    char remark[50];
} Record;

Record incomeRecords[MAX_RECORDS];
Record expenseRecords[MAX_RECORDS];
int incomeCount = 0;
int expenseCount = 0;

void addIncome() {//注释1：录入收入信息 
    if (incomeCount >= MAX_RECORDS) {
        printf("收入记录已满！\n");
        return;
    }
    
    Record newRecord;
    printf("请输入收入日期 (YYYY-MM-DD): ");
    scanf("%s", newRecord.date);
    do {
        printf("请输入收入金额: ");
        scanf("%f", &newRecord.amount);
        if (newRecord.amount <= 0) {
            printf("收入金额必须为正数，请重新输入。\n");
        }
    } while (newRecord.amount <= 0);
    
    printf("请输入收入类别: ");
    scanf("%s", newRecord.category);
    
    printf("请输入备注: ");
    getchar(); // 清除换行符
    fgets(newRecord.remark, sizeof(newRecord.remark), stdin);
    newRecord.remark[strcspn(newRecord.remark, "\n")] = 0; // 去掉换行符
    
    incomeRecords[incomeCount++] = newRecord;
    printf("收入记录已添加成功！\n");
}

void addExpense() {//注释1：添加支出 
    if (expenseCount >= MAX_RECORDS) {
        printf("支出记录已满！\n");
        return;
    }
    
    Record newRecord;
    printf("请输入支出日期 (YYYY-MM-DD): ");
    scanf("%s", newRecord.date);
    do {
        printf("请输入支出金额: ");
        scanf("%f", &newRecord.amount);
        if (newRecord.amount <= 0) {
            printf("支出金额必须为正数，请重新输入。\n");
        }
    } while (newRecord.amount <= 0);
    
    printf("请输入支出类别: ");
    scanf("%s", newRecord.category);
    
    printf("请输入备注: ");
    getchar(); // 清除换行符
    fgets(newRecord.remark, sizeof(newRecord.remark), stdin);
    newRecord.remark[strcspn(newRecord.remark, "\n")] = 0; // 去掉换行符

    expenseRecords[expenseCount++] = newRecord;
    printf("支出记录已添加成功！\n");
}

void displayRecords() {//注释1；展示收入与支出信息 
    printf("\n收入记录:\n");
    for (int i = 0; i < incomeCount; i++) {
        printf("日期: %s, 金额: %.2f, 类别: %s, 备注: %s\n",
               incomeRecords[i].date,
               incomeRecords[i].amount,
               incomeRecords[i].category,
               incomeRecords[i].remark);
    }
    printf("\n支出记录:\n");
    for (int i = 0; i < expenseCount; i++) {
        printf("日期: %s, 金额: %.2f, 类别: %s, 备注: %s\n",
               expenseRecords[i].date,
               expenseRecords[i].amount,
               expenseRecords[i].category,
               expenseRecords[i].remark);
    }
}

int main() {
    int choice;
    do {
        printf("\n个人帐单管理系统\n");
        printf("1. 录入收入\n");
        printf("2. 录入支出\n");
        printf("3. 显示记录\n");
        printf("0. 退出\n");
        printf("请选择操作: ");
        scanf("%d", &choice);
        
        switch (choice) {//注释1：通过功能数字来跳转方法函数 
            case 1:
                addIncome();
                break;
            case 2:
                addExpense();
                break;
            case 3:
                displayRecords();
                break;
            case 0:
                printf("退出系统。\n");
                break;
            default:
                printf("无效选择，请重新输入。\n");
        }
    } while (choice != 0);

    return 0;
}//2024.22.23
