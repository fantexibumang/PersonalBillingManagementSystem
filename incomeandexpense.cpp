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

void addIncome() {//ע��1��¼��������Ϣ 
    if (incomeCount >= MAX_RECORDS) {
        printf("�����¼������\n");
        return;
    }
    
    Record newRecord;
    printf("�������������� (YYYY-MM-DD): ");
    scanf("%s", newRecord.date);
    do {
        printf("������������: ");
        scanf("%f", &newRecord.amount);
        if (newRecord.amount <= 0) {
            printf("���������Ϊ���������������롣\n");
        }
    } while (newRecord.amount <= 0);
    
    printf("�������������: ");
    scanf("%s", newRecord.category);
    
    printf("�����뱸ע: ");
    getchar(); // ������з�
    fgets(newRecord.remark, sizeof(newRecord.remark), stdin);
    newRecord.remark[strcspn(newRecord.remark, "\n")] = 0; // ȥ�����з�
    
    incomeRecords[incomeCount++] = newRecord;
    printf("�����¼����ӳɹ���\n");
}

void addExpense() {//ע��1�����֧�� 
    if (expenseCount >= MAX_RECORDS) {
        printf("֧����¼������\n");
        return;
    }
    
    Record newRecord;
    printf("������֧������ (YYYY-MM-DD): ");
    scanf("%s", newRecord.date);
    do {
        printf("������֧�����: ");
        scanf("%f", &newRecord.amount);
        if (newRecord.amount <= 0) {
            printf("֧��������Ϊ���������������롣\n");
        }
    } while (newRecord.amount <= 0);
    
    printf("������֧�����: ");
    scanf("%s", newRecord.category);
    
    printf("�����뱸ע: ");
    getchar(); // ������з�
    fgets(newRecord.remark, sizeof(newRecord.remark), stdin);
    newRecord.remark[strcspn(newRecord.remark, "\n")] = 0; // ȥ�����з�

    expenseRecords[expenseCount++] = newRecord;
    printf("֧����¼����ӳɹ���\n");
}

void displayRecords() {//ע��1��չʾ������֧����Ϣ 
    printf("\n�����¼:\n");
    for (int i = 0; i < incomeCount; i++) {
        printf("����: %s, ���: %.2f, ���: %s, ��ע: %s\n",
               incomeRecords[i].date,
               incomeRecords[i].amount,
               incomeRecords[i].category,
               incomeRecords[i].remark);
    }
    printf("\n֧����¼:\n");
    for (int i = 0; i < expenseCount; i++) {
        printf("����: %s, ���: %.2f, ���: %s, ��ע: %s\n",
               expenseRecords[i].date,
               expenseRecords[i].amount,
               expenseRecords[i].category,
               expenseRecords[i].remark);
    }
}

int main() {
    int choice;
    do {
        printf("\n�����ʵ�����ϵͳ\n");
        printf("1. ¼������\n");
        printf("2. ¼��֧��\n");
        printf("3. ��ʾ��¼\n");
        printf("0. �˳�\n");
        printf("��ѡ�����: ");
        scanf("%d", &choice);
        
        switch (choice) {//ע��1��ͨ��������������ת�������� 
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
                printf("�˳�ϵͳ��\n");
                break;
            default:
                printf("��Чѡ�����������롣\n");
        }
    } while (choice != 0);

    return 0;
}//2024.22.23
