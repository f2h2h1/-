/*
�γ��� ����������
���ṹ  �ɼ� ��ڵ� �ҽڵ� head
�����еĽڵ� ѧ�� ���� רҵ next

��ѯ
    ���γ̲�ѯ ����ÿγ����гɼ���ѧ�ţ�������רҵ
    ��ѧ�Ų�ѯ �����ѧ�����γ̳ɼ���������רҵ
    ��������ѯ �����ѧ��ѧ�ţ��γ̳ɼ���רҵ

����һ����ѧ����Ϣ ��ͷָ�����
ɾ��һ��ѧ��������Ϣ ɾ��������Ϣ
��רҵ�����γ̳ɼ����� �ߵ��� ��� �ɼ� ѧ�� ����
�������γ̳ɼ�ͳ�� ������ ����ĸ������������� ÿ10��Ϊһ���� 0-9


���������ظ���ѧ�Ų����ظ�



1. �γ���Ƶ�����Ҫ��
2. ���ݽṹ
    ������������������ݽṹ�����ø����ڵ�Ķ�����ʽ�Լ���Ӧ���ǵ�c���ԵĶ����
3. ���������ṹ���㷨����
4. �������˵��
    �ĵ�����˵������������ע��
    ���������ȫ�ֱ����ĺ���˵�������к����Ĺ���˵��
5. ������Ҫ����
6. ��Ҫ����ʵ�ֵĽ��չʾ
7. �������ۺ����

Դ��Ϳ���̨�����������ʹ��gbk����

�����γ�
    ���ݽṹ
    ����ϵͳ
    ���ݿ�ԭ��
����רҵ
    �������ѧ�뼼�� 1
    ������� 2
    ���繤�� 3
    ��Ϣ��ȫ 4
    ���������� 5
    ����ý�弼�� 6
��ʮ����ѧ��

һ���γ�����רҵ
һ��רҵʮ������ѧ��


�ṹ�壬�ṹ��֮�����ϵ����ʼ������
���Ҷ���������ڵ�
���������������
���Ҷ�������ɾ���ڵ�

��ɾ���ɼ�������������ݣ���ɾ��ѧ�������������


gcc binarytreescore.c -o binarytreescore

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

#ifndef _WIN32                   // Linux platform
    #include <termio.h>
    #ifndef STDIN_FILENO
        #define STDIN_FILENO 0
    #endif
    int getch(void) {
        struct termios tm, tm_old;
        int fd = STDIN_FILENO, c;
        if(tcgetattr(fd, &tm) < 0)
            return -1;
        tm_old = tm;
        cfmakeraw(&tm);
        if(tcsetattr(fd, TCSANOW, &tm) < 0)
            return -1;
        c = fgetc(stdin);
        if(tcsetattr(fd, TCSANOW, &tm_old) < 0)
            return -1;
        return c;
    }
#else                            // WIN32 platform
    #include <conio.h>
#endif
void sys_pause()
{
    puts("Press any key to continue ...");
    getch();
}

#ifdef _WIN32
    #include <windows.h>
#else
    #include <unistd.h>
#endif

#define STUDNET_COUNT 12 // ÿ��רҵ��ʮ����ѧ��
#define CLASS_COUNT 3 // һ���������γ�
#define SUBJECT_COUNT 6 // һ��������רҵ

char *ClassName[] = {
    "���ݽṹ",
    "����ϵͳ",
    "���ݿ�ԭ��"
};

char *Subject[] = {
    "�������ѧ�뼼��",
    "�������",
    "���繤��",
    "��Ϣ��ȫ",
    "����������",
    "����ý�弼��"
};

typedef struct Student
{
    int number; // ѧ��
    char name[10]; // ѧ��������������
    char *subject; // רҵ��
    struct Student *next;
} Student;

typedef struct Score
{
    int value; // �������
    struct Student *student; // ������Ӧ��ѧ��
    struct Score *lchild;
    struct Score *rchild;
} Score;

typedef struct Class
{
    char name[40]; // �γ������ʮ������
    struct Score *score; // �ɼ�
    struct Class *next;
} Class;

void init(); // ��ʼ������
void studentAdd(Student new); // ���ѧ��
bool studnetDel(int studentID); // ɾ��ѧ��
bool studnetIDexist(int studentID); // �ж�ѧ���Ƿ����
void classScoreAdd(Class *class, Student *student, int score); // ��ӿγ̳ɼ�
Score* scoreInit(Student *student, int score); // ��ʼ���ɼ�
void scoreAdd(Score *score, Student *student, int value); // ��ӳɼ�
void scoreDel(Class *class, int studentID); // ɾ���ɼ�

// ��Щ�����˵���ʵ�ֺ���
void queryClass(); // ���γ̲�ѯ
void queryClassByStudentNumber(); // ��ѧ�Ų�ѯ
void queryClassByStudentName(); // ��������ѯ
void addStudent(); // ����һ����ѧ����Ϣ
void delStudent(); // ɾ��һ��ѧ��������Ϣ
void showScoreBySubject(); // ��רҵ�����γ̳ɼ�����
void showScoreStatistics(); // �������γ̳ɼ�ͳ��

Class *classLink = NULL; // �γ�����
Student *studentLink = NULL; // ѧ������
char c; // ����������뻺����

Score* scoreInit(Student *student, int value) {
    Score *score = (Score*)malloc(sizeof(Score));
    score->student = student;
    score->value = value;
    score->lchild = NULL;
    score->rchild = NULL;
    return score;
}

void scoreAdd(Score *score, Student *student, int value) {
    if (score->value <= value) {
        if (score->lchild == NULL) {
            score->lchild = scoreInit(student, value);
        } else {
            scoreAdd(score->lchild, student, value);
        }
    } else {
        if (score->rchild == NULL) {
            score->rchild = scoreInit(student, value);
        } else {
            scoreAdd(score->rchild, student, value);
        }
    }
}

void scoreDel(Class *class, int studentID) {
    Score *score = class->score;
    Score *root = score;

    if (root == NULL) {
        printf("���ڵ�Ϊ��\n");
        return;
    }

    printf("���ڵ� %d %d\n", root->student->number, studentID);
    if (root->student->number == studentID) {
        printf("��Ҫɾ�����Ǹ��ڵ�\n");
        if (root->lchild == NULL) { // ���������Ϊ�գ�������������������ڵ�
            printf("������Ϊ�գ�������������������ڵ�\n");
            class->score = root->rchild;
            free(root);
            return;
        }
        if (root->rchild == NULL) { // ���������Ϊ�գ�������������������ڵ�
            printf("������Ϊ�գ�������������������ڵ�\n");
            class->score = root->lchild;
            free(root);
            return;
        }
        printf("���ڵ��������������Ϊ��\n");
        Score *current = root->lchild;
        if (current->rchild == NULL) { // ���������ҽڵ�Ϊ�գ�
            printf("���������ҽڵ�Ϊ��\n");
            class->score = root->lchild;
            class->score->rchild = root->rchild;
            free(root);
        }

        Score *pre = current;
        while (current->rchild != NULL) { // Ѱ�������������ֵ
            printf("Ѱ�������������ֵ %d %d\n", current->student->number, current->value);
            pre = current;
            current = current->rchild;
        }

        class->score = current;
        pre->rchild = current->lchild;
        current->lchild = root->lchild;
        current->rchild = root->rchild;

        free(root);
        return;
    }

    Score *stack[STUDNET_COUNT*SUBJECT_COUNT];
    int top = -1;
    // ��scoreΪNULL����ջΪ��ʱ���������������
    while (score != NULL || top  !=  -1) {
        // ���score��ΪNULL������ѹջ��������������
        if (score != NULL) {
            stack[++top] = score; // ѹջ
            score = score->lchild;
        }
        // ���score==NULL������������������ɣ���Ҫ������һ�����������
        else{
            score = stack[top]; // ��ȡջ��
            if (top != -1) { // ��ջ
                top--;
            }

            Score *parent = NULL;
            if (score->lchild != NULL && score->lchild->student->number == studentID) {
                parent = score;
                score = score->lchild;
            }

            if (score->rchild != NULL && score->rchild->student->number == studentID) {
                parent = score;
                score = score->rchild;
            }

            if (parent != NULL) {
                // Ҷ�ӽڵ㣻��ֱ��ɾ���ڵ㼴�ɣ�
                printf("�ҵ���Ҫɾ���Ľڵ� ѧ�ţ�%d �ɼ���%d\n", score->student->number, score->value);
                // printf("\nline %d\n", __LINE__);
                if (score->lchild == NULL && score->rchild == NULL) {
                    printf("Ҷ�ӽڵ�\n");
                    if (parent->lchild == score) {
                        parent->lchild = NULL;
                    } else if (parent->rchild == score) {
                        parent->rchild = NULL;
                    }
                    free(score);
                    return;
                }
                // ����������������Ľڵ㣻��ɾ���ڵ�󣬽��������������������������ƶ���ɾ���ڵ��λ�ã�
                if (score->rchild == NULL || score->rchild == NULL) {
                    printf("����������������Ľڵ�\n");
                    if (parent->lchild == score) {
                        parent->lchild = parent->rchild;
                    } else if (parent->rchild == score) {
                        parent->rchild = parent->lchild;
                    }
                    free(score);
                    return;
                }

                // �����������еĽڵ�
                // �� �����������ֵ �� ����������Сֵ �����ɾ���Ľڵ�
                printf("�����������еĽڵ�\n");
                Score *current = score->lchild;
                if (current->rchild == NULL) { // ���������ҽڵ�Ϊ�գ�
                    printf("���������ҽڵ�Ϊ��\n");
                    if (parent->lchild == score) {
                        parent->lchild = score->lchild;
                    } else if (parent->rchild == score) {
                        parent->rchild = score->lchild;
                    }
                    score->lchild->rchild = score->rchild;
                    free(score);
                    return;
                }

                Score *pre = current;
                while (current->rchild != NULL) { // Ѱ�������������ֵ
                    printf("Ѱ�������������ֵ %d %d\n", current->student->number, current->value);
                    pre = current;
                    current = current->rchild;
                }

                
                if (parent->lchild == score) {
                    parent->lchild = current;
                } else if (parent->rchild == score) {
                    parent->rchild = current;
                }
                pre->rchild = current->lchild;
                current->lchild = score->lchild;
                current->rchild = score->rchild;

                free(score);
                return;
            }
            score = score->rchild;
        }
    }

    printf("δ�ܳɹ�����ɾ������\n");
    printf("������ڵ� %d\n", studentID);

}

bool studnetDel(int studentID) {
    if (studentLink == NULL) {
        return false;
    }

    Student *current = studentLink;
    if (current->number == studentID) {
        studentLink = current->next;
        free(current);
        return true;
    }

    Student *pre = current;
    current = current->next;
    while (current != NULL) {
        if (current->number == studentID) {
            pre->next = current->next;
            free(current);
            return true;
        }
        current = current->next;
        pre = pre->next;
    }
    return false;
}

bool studnetIDexist(int studentID) {
    Student *current = studentLink;
    while (current != NULL) {
        if (current->number == studentID) {
            return true;
        }
        current = current->next;
    }
    return false;
}

void classScoreAdd(Class *class, Student *student, int score) {
    if (class->score == NULL) {
        class->score = scoreInit(student, score);
    } else {
        scoreAdd(class->score, student, score);
    }
}

void studentAdd(Student new) {
    Student *temp = (Student*)malloc(sizeof(Student));
    temp->number = new.number;
    #ifdef _MSC_VER // ����ifdef����������vc��gcc������
        strcpy_s(temp->name, _countof(temp->name), new.name);
    #else
        strcpy(temp->name, new.name);
    #endif
    temp->subject = new.subject;
    if (studentLink == NULL) {
        studentLink = temp;
        studentLink->next = NULL;
    } else {
        temp->next = studentLink;
        studentLink = temp;
    }
}

void init()
{
    // ��ʼ��ѧ������
    char *familyName[] = {
        "��", "Ҧ", "��", "��", "��", "�", "�u", "�", "��", "��", "��", "��"
    };
    char *middleName[] = {
        "��", "��", "��", "��", "��", "ѧ", "��", "��", "��", "��", "��", "ԣ"
    };
    char *lastName[] = {
        "��", "��", "��", "��", "��", "ĭ", "��", "��", "��", "��", "��", "��"
    };
    srand((unsigned)time(NULL));
    for (int i = 0; i < SUBJECT_COUNT; i++) {
        for (int j = 0; j < STUDNET_COUNT; j++) {
            Student stu1;
            stu1.number = (i + 1) * 100 + j + 10;
            stu1.subject = Subject[i];
            #ifdef _MSC_VER // ����ifdef����������vc��gcc������
                strcpy_s(stu1.name, _countof(stu1.name), familyName[rand() % 12]);
                strcat_s(stu1.name, _countof(stu1.name), middleName[rand() % 12]);
                strcat_s(stu1.name, _countof(stu1.name), lastName[rand() % 12]);
            #else
                strcpy(stu1.name, familyName[rand() % 12]);
                strcat(stu1.name, middleName[rand() % 12]);
                strcat(stu1.name, lastName[rand() % 12]);
            #endif
            studentAdd(stu1);
            // printf("%d %d ѧ�ţ�%d\t������%s\tרҵ��%s\n", i, j, stu1.number, stu1.name, stu1.subject);
        }
    }

    // ��ʼ���γ�����
    Class *class = (Class*)malloc(sizeof(Class));
    for (int i = 0; i < CLASS_COUNT; i++) {
        if (i == 0) {
            class->next = NULL;
        } else {
            Class *temp = (Class*)malloc(sizeof(Class));
            temp->next = class;
            class = temp;
        }
        #ifdef _MSC_VER // ����ifdef����������vc��gcc������
            strcpy_s(class->name, _countof(class->name), ClassName[i]);
        #else
            strcpy(class->name, ClassName[i]);
        #endif
        class->score = NULL;
    }
    classLink = class;

    // ��ʼ���ɼ�����
    srand((unsigned)time(NULL));
    Class *class5 = classLink;
    for (int i = 0; i < CLASS_COUNT; i++, class5 = class5->next) {
        Student *stuLink = studentLink;
        while (stuLink != NULL) {
            int score;
            if (rand() % 100 < 90) {
                score = rand() % 40 + 60; // ����60~99�������
            } else {
                score = rand() % 50 + 10; // ����10~59�������
            }
            // printf("ѧ�ţ�%d\t������%s\tרҵ��%s\t�γ̣�%s\t������%d\n", stuLink->number, stuLink->name, stuLink->subject, class5->name, score);
            classScoreAdd(class5, stuLink, score);
            stuLink = stuLink->next;
        }
    }
}

void queryClass() {

    Class *class = classLink;
    int i;
    for (i = 1; class != NULL; i++, class = class->next) { // ���ȫ���Ŀγ�����
        printf("%d %s\n", i, class->name);
    }
    printf("������γ̱��\n");
    int classID;
    #ifdef _MSC_VER // ����ifdef����������vc��gcc������
        scanf_s("%d", &classID);
    #else
        scanf("%d", &classID);
    #endif
    while((c = getchar()) != '\n' && c != EOF); // ��ջ���������
    if (!(classID >= 1 && classID <= CLASS_COUNT)) { // �ж�����Ŀγ̱���Ƿ���Ч
        printf("��Ч����\n");
        return;
    }

    class = classLink;
    for (i = 1; class != NULL; i++, class = class->next) { // ������������������������ǴӸߵ�������
        if (i == classID) {
            Score *score = class->score;
            Score *stack[STUDNET_COUNT*SUBJECT_COUNT];
            int top = -1;
            // ��scoreΪNULL����ջΪ��ʱ���������������
            while (score != NULL || top  !=  -1) {
                // ���score��ΪNULL������ѹջ��������������
                if (score != NULL) {
                    stack[++top] = score; // ѹջ
                    score = score->lchild;
                }
                // ���score==NULL������������������ɣ���Ҫ������һ�����������
                else{
                    score = stack[top]; // ��ȡջ��
                    if (top != -1) { // ��ջ
                        top--;
                    }

                    // ����ɼ�
                    printf("ѧ�ţ�%d\t������%s\tרҵ��%-16s\t�γ̣�%-10s\t������%d\n",
                        score->student->number, score->student->name, score->student->subject, class->name, score->value);

                    score = score->rchild;
                }
            }
            break;
        }
    }

    sys_pause();
}

void queryClassByStudentNumber() {

    printf("������ѧ��\n");
    int studentID;
    #ifdef _MSC_VER // ����ifdef����������vc��gcc������
        scanf_s("%d", &studentID);
    #else
        scanf("%d", &studentID);
    #endif
    while((c = getchar()) != '\n' && c != EOF); // ��ջ���������

    for (Class *class = classLink; class != NULL; class = class->next) { // ������������������������ǴӸߵ�������
        Score *score = class->score;
        Score *stack[STUDNET_COUNT*SUBJECT_COUNT];
        int top = -1;
        // ��scoreΪNULL����ջΪ��ʱ���������������
        while (score != NULL || top  !=  -1) {
            // ���score��ΪNULL������ѹջ��������������
            if (score != NULL) {
                stack[++top] = score; // ѹջ
                score = score->lchild;
            }
            // ���score==NULL������������������ɣ���Ҫ������һ�����������
            else{
                score = stack[top]; // ��ȡջ��
                if (top != -1) { // ��ջ
                    top--;
                }

                if (score->student->number == studentID) { // ��ѧ�����ʱ������ɼ������˳�ѭ��
                    printf("ѧ�ţ�%d\t������%s\tרҵ��%-16s\t�γ̣�%-10s\t������%d\n",
                        score->student->number, score->student->name, score->student->subject, class->name, score->value);
                    break;
                }

                score = score->rchild;
            }
        }
    }

    sys_pause();
}

void queryClassByStudentName() {

    printf("������ѧ������\n");
    char studentName[10];
    #ifdef _MSC_VER // ����ifdef����������vc��gcc������
        scanf_s("%s", studentName, _countof(studentName));
    #else
        scanf("%s", studentName);
    #endif
    while((c = getchar()) != '\n' && c != EOF); // ��ջ���������

    for (Class *class = classLink; class != NULL; class = class->next) { // ������������������������ǴӸߵ�������
        Score *score = class->score;
        Score *stack[STUDNET_COUNT*SUBJECT_COUNT];
        int top = -1;
        // ��scoreΪNULL����ջΪ��ʱ���������������
        while (score != NULL || top  !=  -1) {
            // ���score��ΪNULL������ѹջ��������������
            if (score != NULL) {
                stack[++top] = score; // ѹջ
                score = score->lchild;
            }
            // ���score==NULL������������������ɣ���Ҫ������һ�����������
            else{
                score = stack[top]; // ��ȡջ��
                if (top != -1) { // ��ջ
                    top--;
                }

                if (strcmp(score->student->name, studentName) == 0) { // ���������ʱ������ɼ�
                    printf("ѧ�ţ�%d\t������%s\tרҵ��%-16s\t�γ̣�%-10s\t������%d\n",
                        score->student->number, score->student->name, score->student->subject, class->name, score->value);
                }

                score = score->rchild;
            }
        }
    }

    sys_pause();
}

void addStudent() {

    printf("������ѧ��\n");
    int studentID;
    #ifdef _MSC_VER // ����ifdef����������vc��gcc������
        scanf_s("%d", &studentID);
    #else
        scanf("%d", &studentID);
    #endif
    while((c = getchar()) != '\n' && c != EOF); // ��ջ���������

    // �ж�ѧ���Ƿ����ظ�
    if (studnetIDexist(studentID)) {
        printf("ѧ���Ѵ���\n");
        return;
    }

    Student stu1; // ����һ���µ�ѧ�����͵ı���
    stu1.number = studentID;

    printf("��ѡ������ѧ�����ڵ�רҵ\n");
    for (int j = 0; j < SUBJECT_COUNT; j++) { // ���ȫ����רҵ����
        printf("%d. %s\n", j, Subject[j]);
    }
    int subjectIndex;
    #ifdef _MSC_VER // ����ifdef����������vc��gcc������
        scanf_s("%d", &subjectIndex);
    #else
        scanf("%d", &subjectIndex);
    #endif
    while((c = getchar()) != '\n' && c != EOF); // ��ջ���������
    stu1.subject = Subject[subjectIndex];
    if (!(subjectIndex >= 0 && subjectIndex < SUBJECT_COUNT)) { // �ж������רҵ����Ƿ���Ч
        printf("��Ч����\n");
        return;
    }

    printf("������ѧ������\n");
    char studentName[10];
    #ifdef _MSC_VER // ����ifdef����������vc��gcc������
        scanf_s("%d", studentName, _countof(studentName));
    #else
        scanf("%s", studentName);
    #endif
    while((c = getchar()) != '\n' && c != EOF); // ��ջ���������
    #ifdef _MSC_VER // ����ifdef����������vc��gcc������
        strcpy_s(stu1.name, _countof(stu1.name), studentName);
    #else
        strcpy(stu1.name, studentName);
    #endif

    studentAdd(stu1); // ���µ�ѧ�����������������

    printf("������ɼ�\n");
    Class *class = classLink;
    Student *stuLink = studentLink;
    for (; class != NULL; class = class->next) { // ���µ�ѧ������ÿһ�Ƶĳɼ�
        printf("������ %s �ĳɼ���", class->name);
        int score;
        #ifdef _MSC_VER // ����ifdef����������vc��gcc������
            scanf_s("%d", &score);
        #else
            scanf("%d", &score);
        #endif
        while((c = getchar()) != '\n' && c != EOF); // ��ջ���������
        classScoreAdd(class, stuLink, score); // �ѳɼ����뵽�ɼ��Ķ�����������
    }

    printf("�����ɹ�\n");

    sys_pause();
}

void delStudent() {

    printf("������ѧ��\n");
    int studentID;
    #ifdef _MSC_VER // ����ifdef����������vc��gcc������
        scanf_s("%d", &studentID);
    #else
        scanf("%d", &studentID);
    #endif
    while((c = getchar()) != '\n' && c != EOF);

    if (!studnetIDexist(studentID)) {
        printf("��Чѧ��\n");
        return;
    }

    Class *class = classLink;
    for (int i = 1; class != NULL; i++, class = class->next) {
        printf("ɾ�� %s �ĳɼ�\n", class->name);
        scoreDel(class, studentID);
        printf("\n");
    }

    if (!studnetDel(studentID)) {
        printf("ɾ��ѧ����Ϣʧ��\n");
        return;
    }
    printf("ɾ��ѧ����Ϣ�ɹ�\n");

    printf("ɾ���ɹ�\n");

    sys_pause();
}

void showScoreBySubject() {

    printf("��ѡ��רҵ\n");
    for (int j = 0; j < SUBJECT_COUNT; j++) { // ���ȫ����רҵ����
        printf("%d. %s\n", j, Subject[j]);
    }
    int subjectIndex;
    #ifdef _MSC_VER // ����ifdef����������vc��gcc������
        scanf_s("%d", &subjectIndex);
    #else
        scanf("%d", &subjectIndex);
    #endif
    while((c = getchar()) != '\n' && c != EOF); // ��ջ���������
    if (!(subjectIndex >= 0 && subjectIndex < SUBJECT_COUNT)) { // �ж������רҵ����Ƿ���Ч
        printf("��Ч����\n");
        return;
    }

    for (Class *class = classLink; class != NULL; class = class->next) { // ������������������������ǴӸߵ�������
        Score *score = class->score;
        Score *stack[STUDNET_COUNT*SUBJECT_COUNT];
        int top = -1;
        // ��scoreΪNULL����ջΪ��ʱ���������������
        while (score != NULL || top  !=  -1) {
            // ���score��ΪNULL������ѹջ��������������
            if (score != NULL) {
                stack[++top] = score; // ѹջ
                score = score->lchild;
            }
            // ���score==NULL������������������ɣ���Ҫ������һ�����������
            else{
                score = stack[top]; // ��ȡջ��
                if (top != -1) { // ��ջ
                    top--;
                }

                if (strcmp(score->student->subject, Subject[subjectIndex]) == 0) { // ֻ�����Ӧרҵ�ļ�¼
                    printf("ѧ�ţ�%d\t������%s\tרҵ��%-16s\t�γ̣�%-10s\t������%d\n",
                        score->student->number, score->student->name, score->student->subject, class->name, score->value);
                }

                score = score->rchild;
            }
        }
    }

    sys_pause();
}

void showScoreStatistics() {
    int section[5];  // �����������������ֳ���� ������ 60 ~ 70 70 ~ 80 80 ~ 90 90 ~ 100
    for (Class *class = classLink; class != NULL; class = class->next) {
        memset(section, 0, sizeof(int)*5);
        Score *score = class->score;
        Score *stack[STUDNET_COUNT*SUBJECT_COUNT];
        int top = -1;
        // ��scoreΪNULL����ջΪ��ʱ���������������
        while (score != NULL || top  !=  -1) {
            // ���score��ΪNULL������ѹջ��������������
            if (score != NULL) {
                stack[++top] = score; // ѹջ
                score = score->lchild;
            }
            // ���score==NULL������������������ɣ���Ҫ������һ�����������
            else{
                score = stack[top]; // ��ȡջ��
                if (top != -1) { // ��ջ
                    top--;
                }

                // ��������������
                if (score->value < 60) {
                    section[0]++;
                } else if (score->value >= 60 && score->value < 70) {
                    section[1]++;
                } else if (score->value >= 70 && score->value < 80) {
                    section[2]++;
                } else if (score->value >= 80 && score->value < 90) {
                    section[3]++;
                } else if (score->value >= 90 && score->value <= 100) {
                    section[4]++;
                }

                score = score->rchild;
            }
        }

        // ���ͳ�ƽ��
        printf("%s��\n\t������%d\n\t60 ~ 70��%d\n\t70 ~ 80��%d\n\t80 ~ 90��%d\n\t90 ~ 100��%d\n",
            class->name, section[0], section[1], section[2], section[3], section[4]);
    }

    sys_pause();
}

int main ()
{
    #ifdef _WIN32
        int chcp = GetConsoleCP(); // ��ȡ����̨��ǰ���������
        int chcpOutput = GetConsoleOutputCP(); // ��ȡ����̨��ǰ���������
        SetConsoleCP(936); // �ѿ���̨�����������Ϊ 936 ������ gbk
        SetConsoleOutputCP(936); // �ѿ���̨�����������Ϊ 936 ������ gbk
    #else
        char *LANG = getenv("LANG"); // ��ȡ��ǰ�ն˵ı���
        system("export LANG zh_CN.GBK"); // �ѵ�ǰ�ն˵ı�����Ϊ gbk
    #endif

    init(); // ��ʼ������
    while (true) {
        printf("\n--------------------------------\n");
        printf("1. ���γ̲�ѯ\n");
        printf("2. ��ѧ�Ų�ѯ\n");
        printf("3. ��������ѯ\n");
        printf("4. ����һ����ѧ����Ϣ\n");
        printf("5. ɾ��һ��ѧ��������Ϣ\n");
        printf("6. ��רҵ�����γ̳ɼ�����\n");
        printf("7. �������γ̳ɼ�ͳ��\n");
        printf("0. �˳�\n");
        printf("--------------------------------\n");

        int flg;
        #ifdef _MSC_VER // ����ifdef����������vc��gcc������
            scanf_s("%d", &flg);
        #else
            scanf("%d", &flg);
        #endif
        while((c = getchar()) != '\n' && c != EOF); // ��ջ���������

        switch (flg) {
            case 1: queryClass();
                continue;
            case 2: queryClassByStudentNumber();
                continue;
            case 3: queryClassByStudentName();
                continue;
            case 4: addStudent();
                continue;
            case 5: delStudent();
                continue;
            case 6: showScoreBySubject();
                continue;
            case 7: showScoreStatistics();
                continue;
            case 0: goto endloop;
            default: continue;
        }
    }
    endloop:;

    #ifdef _WIN32
        SetConsoleCP(chcp); // �����˳���ʱ��ѿ���̨��������뻹ԭΪԭ���ı���
        SetConsoleOutputCP(chcpOutput); // �����˳���ʱ��ѿ���̨��������뻹ԭΪԭ���ı���
    #else
        char chatset[32];
        strcpy(chatset, "export LANG ");
        strcat(chatset, LANG); // ƴ������
        system(chatset); // �ѵ�ǰ�ն˵ı��뻹ԭΪԭ���ı���
    #endif

    return 0;
}
