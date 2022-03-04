#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mem.h>

#define MAX_SIZE 100
#define SUBJECT 3

struct student_info{

    char name[10];
    int id;
    int gender;
    int c;
    int java;
    int kotlin;
    int total;
    double avr;
    char grade;
    int rank;

};


typedef struct student_info STUDENT;
void input_score(STUDENT*student);
void score_print(STUDENT*student,int count);
char calculate_grade(double avr);
void sort_student(STUDENT*student);
void insert_student(STUDENT*student);
int total_count = 0;

int main()
{

    int menu = 0;
    int flag = 0;

    printf("����� �ο��� �Է� : ");
    scanf("%d",&total_count);

    STUDENT student[MAX_SIZE];


    while(!flag){
         printf("1.���� �Է�(�ڵ�)\t");
         printf("2.���� ���      \t");
         printf("3.���� �˻�      \n");
         printf("4.ȭ�� �ʱ�ȭ    \t");
         printf("5.���� ����      \t");
         printf("6.���� ����      \n");
         printf("7.���� ����(����)\t");
         printf("8.���� ����(����)\t");
         printf("9.���� ����      \n");
         printf(" �޴� ����: ");
         scanf("%d",&menu);


        switch(menu){
            case 1:
                input_score(student);
                printf("�����Է� �Ϸ��߽��ϴ�.");
                getchar();
                getchar();
                system("cls");
                break;
            case 2:
                score_print(student, total_count);
                getchar();
                getchar();
                system("cls");
                break;
            case 3:
                search_score(student);
                getchar();
                getchar();
                system("cls");
                break;
            case 4:system( "cls"); break;
            case 5:
                remove_student(student);
                getchar();
                getchar();
                system("cls");
                break;
            case 6:
                update_student(student);
                getchar();
                getchar();
                system("cls");
                     break;
            case 7:
                sort_student(student);
                getchar();
                getchar();
                system("cls");
                    break;
            case 8:
                insert_student(student);
                getchar();
                getchar();
                system("cls");
                    break;
            case 9:flag = 1;("�������Ḧ �����ϼ̽��ϴ�.\n");break;
            default : printf("�ٽ� �Է��Ͻÿ� \n");


            }

    }

    printf("���� ���α׷� ���� �Ǿ���.");
    return 0;
}


void input_score(STUDENT*student){

    int i = 0;

    for(i = 0 ;i < total_count ;i++){
        student[i].name[0] = rand()%26 +'A';
        student[i].name[1] = rand()%26 +'A';
        student[i].name[2] = rand()%26 +'A';
        student[i].name[3] = 0;

        student[i].id = rand()%(9999-1000+1) +1000;
        student[i].gender = rand()%2;
        student[i].c = rand()%101;
        student[i].java = rand()%101;
        student[i].kotlin = rand()%101;

        student[i].total = student[i].c + student[i].java + student[i].kotlin;
        student[i].avr = student[i].total / (double)SUBJECT;

        student[i].grade = calculate_grade(student[i].avr);
    }
    return;
}

void score_print(STUDENT*student,int count){
    int i = 0;
    printf(" no      name   id   gender    c      java  kotiln  total  avr  grade \n");

    for(i=0 ;i<count ;i++){
        printf("%3d %8s %6d %5s %6d %6d %6d %6d %8.2lf %6c \n",
               i+1,student[i].name,student[i].id,(student[i].gender == 1)?"��":"��",
               student[i].c,student[i].java,student[i].kotlin,student[i].total,
               student[i].avr,student[i].grade);

    }

    return;

}

char calculate_grade(double avr){

    char grade = 0;

    if(avr >= 90.0){
        grade = 'A';
    }else if(avr >= 80.0){
        grade = 'B';
    }else if(avr >= 80.0){
        grade = 'C';
    }else if(avr >= 80.0){
        grade = 'D';
    }else{
        grade = 'F';
    }

    return grade;
}

void search_score(STUDENT*student){
    int find_flag = 0;
    char name[10] = {0,};
    int i = 0;

    printf("�˻��� �л� �̸�(��ҹ��� ���� ����): ");
    scanf("%s",&name[0]);

    for(i = 0 ;i < total_count ;i++){

        if(!strnicmp(&student[i].name[0],&name[0],3)){
            score_print(&student[i], 1);
            find_flag = 1;
        }

    }

    if(!find_flag){
        printf("�ش�Ǵ� �л��� �����ϴ�.\n");
    }else{
        printf("�˻� �Ϸ�. \n");
    }

    return;


}

void remove_student(STUDENT*student){

    int find_flag = 0;
    char name[10] = {0,};
    int i = 0;

    printf("������ �л� �̸� �Է�(��ҹ��� ���� ����) : ");
    scanf("%s",&name[0]);

    for(i=0 ;i<total_count ;i++){
        if(!strnicmp(student[i].name, name,3)){
            strcpy(student[i].name,"");
            student[i].id = 0;
            student[i].gender = 0;
            student[i].c = 0;
            student[i].java = 0;
            student[i].kotlin = 0;
            student[i].total = 0;
            student[i].avr = 0;
            student[i].rank = 0;

         find_flag = 1;
    }

}
    if(!find_flag){
        printf("�ش�Ǵ� �л��� �����ϴ�. \n");

    }else{
        printf("���� �Ϸ�. \n");
    }


    return 0;

  }

void update_student(STUDENT*student){

    int find_flag = 0;
    char name[10] = {0,};
    int i = 0;

    printf("������ �л� �̸� �Է�(��ҹ��� ���� ����) : ");
    scanf("%s",&name[0]);

    for(i=0 ;i<total_count ;i++){

        if(!strnicmp(student[i].name, name,3)){
            printf("%s ���� c (%d) ��������: ",student[i].name,student[i].c);
            scanf("%d",&student[i].c);

            printf("%s ���� java (%d) ��������: ",student[i].name,student[i].java);
            scanf("%d",&student[i].java);

            printf("%s ���� kotlin (%d) ��������: ",student[i].name,student[i].kotlin);
            scanf("%d",&student[i].kotlin);

            student[i].total = student[i].c + student[i].java + student[i].kotlin;
            student[i].avr = student[i].total / (double)SUBJECT;
            student[i].grade = calculate_grade(student[i].avr);

         find_flag = 1;

        }
   }
    if(!find_flag){
        printf("�ش�Ǵ� �л��� �����ϴ�. \n");

    }else{
        printf("���� �Ϸ�. \n");
    }

    return;

}

void sort_student(STUDENT*student){

    STUDENT buffer_student;
    STUDENT copy_student[total_count];
    int i,j = 0;
    int sort = 0;

    for(i=0 ;i<total_count ;i++ ){
        memcpy(&copy_student[i], &student[i], sizeof(student[i]));

    }

    printf("defalut : �������� (0), ��������(1) : ");
    scanf("%d",&sort);

    if(sort == 0){

        for(i=0 ;i<total_count-1 ;i++ ){
            for(j=i+1 ;j<total_count ;j++){
                if(copy_student[i].total > copy_student[j].total){
                    memcpy(&buffer_student, &copy_student[i], sizeof(buffer_student));
                    memcpy(&copy_student[i], &copy_student[j], sizeof(buffer_student));
                    memcpy(&copy_student[j], &buffer_student,sizeof(buffer_student));
                }
            }
        }
    }else{
                for(i=0 ;i<total_count-1 ;i++ ){
            for(j=i+1 ;j<total_count ;j++){
                if(copy_student[i].total < copy_student[j].total){
                    memcpy(&buffer_student, &copy_student[i], sizeof(buffer_student));
                    memcpy(&copy_student[i], &copy_student[j], sizeof(buffer_student));
                    memcpy(&copy_student[j], &buffer_student, sizeof(buffer_student));
                }
            }
        }

    }

    score_print(copy_student,total_count);
    return;
}


void insert_student(STUDENT*student){

    if(total_count +1 >= MAX_SIZE){
        printf("������ �ʰ��� �߰��Ҽ������ϴ�. \n");
        return;
    }

    total_count++;

    printf("������ �л� �̸�(3��(A~Z)): ");
    scanf("%s",&student[total_count-1].name[0]);

    printf("������ �л� ��ȣ(4��(1000~9999): ");
    scanf("%d",&student[total_count-1].id);

    printf("������ �л� ����(��:1,��:2): ");
    scanf("%d",&student[total_count-1].gender);

    printf("������ �л� C����(0~100): ");
    scanf("%d",&student[total_count-1].c);

    printf("������ �л� java����(0~100): ");
    scanf("%d",&student[total_count-1].java);

    printf("������ �л� kotlin����(0~100): ");
    scanf("%d",&student[total_count-1].kotlin);

    student[total_count-1].total = student[total_count-1].c + student[total_count-1].java
    + student[total_count-1].kotlin;

    student[total_count-1].avr = student[total_count-1].total / (double)SUBJECT;
    student[total_count-1].grade = calculate_grade(student[total_count-1].avr);


    printf("%s �л��� ���� �Է��� �Ϸ�Ǿ����ϴ�. \n",student[total_count-1].name);

    return;


}


