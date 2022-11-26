#ifndef __STUDENT_MANAGER_H__
#define __STUDENT_MANAGER_H__

#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include "linklist.h"

enum option_id
{
     ADD_STUDENT = 1, //添加学生
     FIND_STUDENT,   //寻找学生
     PRINT_STUDENT,  //输出学生
     MODIFY_STUDENT, //修改学生
     DELETE_STUDENT, //删除学生
     EXIT_SYSTEM     //退出系统
};

extern bool login_status;

extern void login_in();
extern void insert_student(linknode_t *head);
extern void find_student(linknode_t *head);
extern void display_student(linknode_t *head);
extern void update_student(linknode_t *head);
extern void delete_student(linknode_t *head);

#endif