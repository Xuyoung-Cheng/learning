#include "student_manager.h"

bool login_status = false;

void
login_in()
{
    char username[30] = {0};
    char passwd[30]   = {0};

    printf("======= login =======\n");
    printf("account: ");
    fgets(username, sizeof(username), stdin);
    username[strlen(username)-1] = '\0';

    printf("password: ");
    fgets(passwd, sizeof(passwd), stdin);
    passwd[strlen(passwd)-1] = '\0';

    if (strcmp(username, "root")==0
            && strcmp(passwd, "root")==0) {
        login_status = true;
        printf("login successful!\n");
    } else {
        login_status = false;
        printf("username or password is wrong!\n");
    }
}

void insert_student(linknode_t *head)
{
    struct Student st = {0};
    bool is_exist = false;
    linknode_t *p = NULL;

    printf("----------------------------------\n");
    printf("please input student info [id name sex age score] : ");
    scanf("%d %s %s %d %lf", &(st.id), st.name, st.sex, &(st.age), &(st.score));
    while (getchar() != '\n');

    p = head;
    while (p->next != NULL) {
        if (p->next->data.id == st.id) {
            is_exist = true;
            printf("student's id: %d is exist!\n", st.id);
            break;
        }
        p = p->next;
    }

    if (is_exist == false) {
        insert_tail_linklist(head, st);
        printf("insert successful\n");
    }
}

void find_student(linknode_t *head)
{
    linknode_t *p = NULL;
    int id = 0;

    printf("please input the student's id : ");
    scanf("%d", &id);

    p = head;
    while (p->next != NULL) {
        if (p->next->data.id == id) {
            printf("----------------------------------------------------\n");
            printf("| id\t| name\t| sex\t| age\t| score\t|\n");
            printf("| %d\t| %s\t| %s\t| %d\t| %lf|\n", 
                    p->next->data.id, p->next->data.name, p->next->data.sex, p->next->data.age, p->next->data.score);
            printf("----------------------------------------------------\n");
            return;
        }
        p = p->next;
    }

    if (p->next == NULL) {
        printf("----------------------------------------------------\n");
        printf("not found id: %d student\n", id);
        printf("----------------------------------------------------\n");
    }
}

void display_student(linknode_t *head)
{
    linknode_t *p = NULL;

    p = head;
    printf("================= Student table ====================\n");
    printf("----------------------------------------------------\n");
    printf("| id\t| name\t| sex\t| age\t| score\t|\n");
    while (p->next != NULL) {
         printf("| %d\t| %s\t| %s\t| %d\t| %lf|\n", 
                    p->next->data.id, p->next->data.name, p->next->data.sex, p->next->data.age, p->next->data.score);
        p = p->next;
    }
    printf("----------------------------------------------------\n");
}

void
display_update_info()
{
    printf(" ┏━━━━━━━━━━━━━━━━━━━━━━━┓ \n");
	printf(" ┃        学生信息       ┃ \n");
	printf(" ┣━━━━━━━━━━━━━━━━━━━━━━━┫ \n");
	printf(" ┃      1. 修改学号      ┃ \n");
	printf(" ┃      2. 修改姓名      ┃ \n");
	printf(" ┃      3. 修改性别      ┃ \n");
	printf(" ┃      4. 修改年龄      ┃ \n");
	printf(" ┃      5. 修改分数      ┃ \n");
	printf(" ┃      6. 退出          ┃ \n");
	printf(" ┗━━━━━━━━━━━━━━━━━━━━━━━┛\n");
}

void
user_change_data(linknode_t *p, int num)
{
    char user_data[100] = {0};
    int new_id;
    int new_age;
    double new_score;

    printf("please input new data : ");
    scanf("%s", user_data);

    switch (num) {
    case 1:
        new_id = atoi(user_data);
        if (new_id > 0) {
            p->data.id = new_id;
        }
        break;
    case 2:
        memset(p->data.name, 0, sizeof(p->data.name));
        strcpy(p->data.name, user_data);
        break;
    case 3:
        memset(p->data.sex, 0, sizeof(p->data.sex));
        strcpy(p->data.sex, user_data);
        break;
    case 4:
        new_age = atoi(user_data);
        if (new_age > 0) {
            p->data.age = new_age;
        }
        break;
    case 5:
        new_score = atof(user_data);
        if (new_score > 0) {
            p->data.score = new_score;
        }
        break;
    case 6:
        printf("exit\n");
        break;
    }

    printf("update successful\n");
}

void
update_student_info(linknode_t *p)
{
    int num = 0;

    display_update_info();

loop:
    printf("please input operator : ");
    scanf("%d", &num);
    while (getchar() != '\n');

    if (num < 1 || num > 6)
    {
        printf("input error, please input num [1~6]");
        goto loop;
    }

    user_change_data(p, num);
}

void update_student(linknode_t *head)
{
    linknode_t *p = NULL;
    int id = 0;

    printf("please input the student's id : ");
    scanf("%d", &id);

    p = head;
    while (p->next != NULL) {
        if (p->next->data.id == id) {
            update_student_info(p->next);
            break;
        }
        p = p->next;
    }

    if (p->next == NULL) {
        printf("----------------------------------------------------\n");
        printf("not found id: %d student\n", id);
        printf("----------------------------------------------------\n");
    }
}

void delete_student(linknode_t *head)
{
    int ret = 0;
    int id = 0;

loop:
    printf("please input student's id : ");
    scanf("%d", &id);

    ret = delete_data_linklist(head, id);
    if (ret == -1) {
        printf("there is no student in the table.\n");
    } else if (ret == -2) {
        printf("student not exist.\n");
        goto loop;
    } else {
        printf("delete student id: %d successful\n", id);
    }
}