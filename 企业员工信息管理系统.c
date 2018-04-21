#include<stdio.h>

#include<string.h>

#include<stdlib.h>



#define STARS "*****************"

#define SIZE_W 30//定义文字型char数组最大长度

#define SIZE_N 20//定义数字型char数组最大长度



void menu(void);//菜单

void exit_system(void);//退出

struct staff * creat_link(void);//创建链表

char *creat_link_test(void);//链表-子菜单

void creat_link_next(void);//链表-检验是否继续输入

void typein(struct staff*temp);//输入

void display(struct staff *head);//读取

void save(struct staff *head);//保存

void delete_data(void);//删除

void delete_data_number(void);//删除-工号查找

void delete_data_name(void);//删除-姓名查找

void search(void);//查找

void search_number(void);//查找-按工号

void search_name(void);//查找-按姓名

void search_phone(void);//查找-按手机号码

void revise(void);//编辑

void revise_number();//编辑-查找-按工号

void revise_name(void);//编辑-查找-按姓名

void revise_phone();//编辑-查找-按手机号码

void sort(void);//排序

void sort_number(struct staff *head);//排序-工号

void sort_payment(struct staff *head);//排序-薪水



typedef struct staff

{

char name[SIZE_W];//员工姓名

char sex[SIZE_N];//员工性别

char phone[SIZE_W];//员工手机号码

char number[SIZE_W];//员工工号

char department[SIZE_W];//员工部门

char position[SIZE_W];//员工任职情况

int year;//员工入职年份

int payment;//员工薪水

struct staff *next;

}STAFF;

STAFF *head = NULL;

STAFF *p, *q, *current;



int main()

{

printf("%s%s\n", STARS, STARS);

printf(" 欢迎使用企业员工信息管理系统\n");

printf(" 制作人：殷建平 李文涛\n");

menu();

return 0;

}



void menu(void)

{

int choice;

printf("%s%s\n", STARS, STARS);

printf(" 请输入数字选择功能：\n");

printf(" 1)员工信息录入\n");//完成

printf(" 2)保存员工信息\n");//完成

printf(" 3)显示员工信息\n");//完成

printf(" 4)编辑员工信息\n");//测试***************************

printf(" 5)删除员工信息\n");//完成

printf(" 6)员工信息排序\n");//完成

printf(" 7)查找员工信息\n");//完成

printf(" 8)退出系统\n"); //完成

printf("%s%s\n", STARS, STARS);

printf("请输入数字选择");

scanf("%d", &choice);

getchar();//防止输入错误导致程序死循环

switch (choice)

{

case 1:

head = creat_link();

menu();

break;

case 2:

save(head);

menu();

break;

case 3:

display(head);

menu();

break;

case 4:

revise();

menu(); 

break;

case 5:

delete_data();

menu(); 

break;

case 6:

sort();

menu(); 

break;

case 7:

search();

menu();

break;

case 8:

exit_system();

break;

default:

printf("输入错误！请重新输入\n");

menu();

}

}



void typein(struct staff*temp)

{

printf("请输入员工姓名:");

scanf("%s", temp->name);//char类型不需要通过getchar除错

printf("请输入员工性别:");

scanf("%s", temp->sex);

printf("请输入员工手机号码:");

scanf("%s", temp->phone);

printf("请输入员工工号:");

scanf("%s", temp->number);

printf("请输入员工所属部门:");

scanf("%s", temp->department);

printf("请输入员工所在岗位:");

scanf("%s", temp->position);

printf("请输入员工入职年份:");

scanf("%d", &temp->year);

getchar();

printf("请输入员工薪水:");//防止错误输入导致程序崩溃

scanf("%d", &temp->payment);

getchar();

}



struct staff * creat_link()//特色函数

{

char test[20];

head = (STAFF*)malloc(sizeof(STAFF));

head->next = NULL;

p = head;

q = (STAFF*)malloc(sizeof(STAFF));

printf("%s%s\n", STARS, STARS);

printf("请输入员工信息：\n");

typein(q);

strcpy(test, creat_link_test());

while (strcmp(test, "y") == 0)

{

creat_link_next();

strcpy(test, creat_link_test());

}

p->next = q;//严重问题解决方案-1

p = q; //严重问题解决方案-2-分析：少指向一次

p->next = NULL;

return head;

}



void creat_link_next(void)

{

p->next = q;

p = q;

q = (STAFF*)malloc(sizeof(STAFF));

printf("请继续输入\n");

typein(q);

}



char *creat_link_test(void)//特色函数

{

char *p = (char *)malloc(sizeof(char));

printf("%s%s\n", STARS, STARS);

printf(" 是否要继续输入？\n");

printf(" 是请按'y' 否请按'n'\n");

printf("%s%s\n", STARS, STARS);

printf("请输入选择是否继续");

scanf("%s", p);

if ((strcmp(p, "n") != 0) && (strcmp(p, "y") != 0))

{

printf("输入字符错误!请重新输入\n");

creat_link_test();

}

else

return p;

}



void display(struct staff *head)//读取

{

if (head == NULL)

{

printf("系统中没有信息！\n");

menu();

}

STAFF *a;

printf("员工信息：\n");

printf("%s%s\n", STARS, STARS);

printf("员工姓名 员工性别 员工手机号码\t 员工工号 员工所属部门 员工职位 员工入职年份 员工薪水\n");

for (a = head->next; a != NULL; a = a->next)

{

printf("%s\t", a->name);

printf("%s\t", a->sex);

printf("%s\t", a->phone);

printf("%s\t", a->number);

printf("%s\t", a->department);

printf("%s\t", a->position);

printf("%d\t", a->year);

printf("%d\n", a->payment);

}

menu();

}



void save(struct staff *head)

{

if (head!= NULL)

{

FILE *fp;

STAFF *a;

fp = fopen("D\\staff.txt", "w+");

for (a = head->next; a != NULL; a = a->next)

{

fprintf("%s\t", a->name);

fprintf("%s\t", a->sex);

fprintf("%s\t", a->phone);

fprintf("%s\t", a->number);

fprintf("%s\t", a->department);

fprintf("%s\t", a->position);

fprintf("%d\t", a->year);

fprintf("%d\n",a->payment);

}

fclose(fp);

printf("保存完毕！\n");

}

else

{

printf("链表为空，保存失败！\n");

menu();

}

}



void delete_data(void)

{

if (head == NULL)

{

printf("链表为空，删除失败！\n");

menu();

}

printf("%s%s\n", STARS, STARS);

printf(" 输入数字选择功能\n");

printf(" 1)输入工号选择删除条目\n");

printf(" 2)输入姓名选择删除条目\n");

printf(" 3)取消删除返回上一级菜单");

printf("\n%s%s\n", STARS, STARS);

printf("请输入数字选择：");

int t;

scanf("%d", &t);

getchar();

switch (t)

{

case 1:

delete_data_number();

break;

case 2:

delete_data_name();

break;

case 3:

menu();

break;

default:

printf("输入错误！请重新输入\n");

delete_data();

}

}



void delete_data_number(void)

{

char number[SIZE_W];

q = head;

p = head->next;

printf("请输入员工工号:");

scanf("%s", number);

while ((p != NULL) && strcmp(p->number, number) != 0)

{

q = p;

p->next;

}

if (p == NULL)

printf("无法查找到匹配的员工工号\n");

else

{

q->next = p->next;

printf("删除成功！\n");

}

}



void delete_data_name(void)

{

char name[SIZE_W];

q = head;

p = head->next;

printf("请输入员工姓名:");

scanf("%s", name);

while ((p != NULL) && strcmp(p->name, name) != 0)

{

q = p;

p->next;

}

if (p == NULL)

printf("无法查找到匹配的员工姓名\n");

else

{

q->next = p->next;

printf("删除成功！\n");

}

}



void search(void)

{

if (head == NULL)

{

printf("链表为空，查找失败！\n");

menu();

}

printf("%s%s\n", STARS, STARS);

printf(" 请输入数字选择查询方式：\n");

printf(" 1)姓名查询\n");

printf(" 2)手机号码查询\n");

printf(" 3)工号查询\n");

printf(" 4)返回上一级菜单\n");

printf("%s%s\n", STARS, STARS);

printf("请输入数字选择");

int n;

scanf("%d", &n);

getchar();

switch (n)

{

case 1: 

search_name(); 

break;

case 2: 

search_phone(); 

break;

case 3: 

search_number(); 

break;

case 4: 

break;

default:

printf("输入错误！请重新输入\n");

search();

}

}



void search_number(void)

{

char number[SIZE_W];

int test = 0;

p = head;

printf("请输入要查找的员工的姓名:");

scanf("%s", number);

while (p!=NULL)

{

if (strcmp((p->number), number) == 0)

{

printf("员工信息：\n");

printf("%s%s\n", STARS, STARS);

printf("员工姓名 员工性别 员工手机号码\t 员工工号 员工所属部门 员工职位 员工入职年份 员工薪水\n");

printf("%s\t", p->name);

printf("%s\t", p->sex);

printf("%s\t", p->phone);

printf("%s\t", p->number);

printf("%s\t", p->department);

printf("%s\t", p->position);

printf("%d\t", p->year);

printf("%d\n", p->payment);

test++;

break;

}

p = p->next;

}

if (test == 0)

printf("不存在该信息!");

}



void search_name(void)

{

char name[SIZE_W];

int test = 0;

p = head;

printf("请输入要查找的员工的姓名:");

scanf("%s", name);

while (p!=NULL)

{

if (strcmp((p->name), name) == 0)

{

printf("员工信息：\n");

printf("%s%s\n", STARS, STARS);

printf("员工姓名 员工性别 员工手机号码\t 员工工号 员工所属部门 员工职位 员工入职年份 员工薪水\n");

printf("%s\t", p->name);

printf("%s\t", p->sex);

printf("%s\t", p->phone);

printf("%s\t", p->number);

printf("%s\t", p->department);

printf("%s\t", p->position);

printf("%d\t", p->year);

printf("%d\n",p->payment);

test++;

break;

}

p = p->next;

}

if (test==0)

printf("不存在该信息!");

}



void revise(void)

{

if (head == NULL)

{

printf("链表为空，编辑失败！\n");

menu();

}

int choice;

printf("%s%s\n", STARS, STARS);

printf(" 请输入数字选择功能\n");

printf(" 1)输入工号查找编辑对象\n");

printf(" 2)输入姓名查找编辑对象\n");

printf(" 3)输入手机号码查找编辑对象\n");

printf(" 4)返回上一级菜单\n");

printf("%s%s\n", STARS, STARS);

printf("请输入数字选择");

scanf("%d", &choice);

getchar();

switch (choice)

{

case 1: 

revise_number(); 

break;

case 2: 

revise_name(); 

break;

case 3:

revise_phone();

break;

case 4:

menu();

break;

default:

printf("输入错误！请重新输入\n");

revise();

}

}



void revise_number()

{

STAFF *q, b;

int i = 0;

q = head->next;

char number[20];

printf("请输入查询员工工号：");

scanf("%s", &number);

while (q != NULL)

{

if (strcmp((p->number), number) == 0)

{

printf("%s%s\n", STARS, STARS);

printf("请输入更改的员工姓名:");

scanf("%s", &b.name);

printf("请输入更改的员工性别:");

scanf("%s", &b.sex);

printf("请输入更改的员工手机号码:");

scanf("%s", &b.phone);

printf("请输入更改的员工工号:");

scanf("%s", &b.number);

printf("请输入更改的员工所属部门:");

scanf("%s", &b.department);

printf("请输入更改的员工所在岗位:");

scanf("%s", &b.position);

printf("请输入更改的员工入职年份:");

scanf("%d", &b.year);

getchar();

printf("请输入更改的员工薪水:");

scanf("%d", &b.payment);

getchar();

strcpy(q->name, b.name);

strcpy(q->sex, b.sex);

strcpy(q->phone, b.phone);

strcpy(q->number, b.number);

strcpy(q->department, b.department);

strcpy(q->position, b.position);

q->year = b.year;

q->payment = b.payment;

printf("%s%s", STARS, STARS);

printf("\n修改成功！\n");

i++;

break;

}

q = q->next;

}

if (i == 0)

printf("无法查找到输入的员工信息!\n");

}



void revise_name()

{

STAFF *q,b;

int i = 0;

q = head->next;

char name_test[20];

printf("请输入查询员工姓名：");

scanf("%s", &name_test);

while (q!=NULL)

{

if (strcmp((p->name), name_test) == 0)

{

printf("%s%s\n", STARS, STARS);

printf("请输入更改的员工姓名:");

scanf("%s", &b.name);

printf("请输入更改的员工性别:");

scanf("%s", &b.sex);

printf("请输入更改的员工手机号码:");

scanf("%s", &b.phone);

printf("请输入更改的员工工号:");

scanf("%s", &b.number);

printf("请输入更改的员工所属部门:");

scanf("%s", &b.department);

printf("请输入更改的员工所在岗位:");

scanf("%s", &b.position);

printf("请输入更改的员工入职年份:");

scanf("%d", &b.year);

getchar();

printf("请输入更改的员工薪水:");

scanf("%d", &b.payment);

getchar();

strcpy(q->name, b.name); 

strcpy(q->sex, b.sex);

strcpy(q->phone, b.phone);

strcpy(q->number, b.number);

strcpy(q->department, b.department);

strcpy(q->position, b.position);

q->year = b.year;

q->payment = b.payment;

printf("%s%s", STARS, STARS);

printf("\n修改成功！\n");

i++;

break;

}

q = q->next;

}

if (i==0)

printf("无法查找到输入的员工信息!\n");

}



void revise_phone()

{

STAFF *q, b;

int i = 0;

q = head->next;

char phone[20];

printf("请输入查询员工手机号码：");

scanf("%s", &phone);

while (q != NULL)

{

if (strcmp((p->phone), phone) == 0)

{

printf("%s%s\n", STARS, STARS);

printf("请输入更改的员工姓名:");

scanf("%s", &b.name);

printf("请输入更改的员工性别:");

scanf("%s", &b.sex);

printf("请输入更改的员工手机号码:");

scanf("%s", &b.phone);

printf("请输入更改的员工工号:");

scanf("%s", &b.number);

printf("请输入更改的员工所属部门:");

scanf("%s", &b.department);

printf("请输入更改的员工所在岗位:");

scanf("%s", &b.position);

printf("请输入更改的员工入职年份:");

scanf("%d", &b.year);

getchar();

printf("请输入更改的员工薪水:");

scanf("%d", &b.payment);

getchar();

strcpy(q->name, b.name);

strcpy(q->sex, b.sex);

strcpy(q->phone, b.phone);

strcpy(q->number, b.number);

strcpy(q->department, b.department);

strcpy(q->position, b.position);

q->year = b.year;

q->payment = b.payment;

printf("%s%s", STARS, STARS);

printf("\n修改成功！\n");

i++;

break;

}

q = q->next;

}

if (i == 0)

printf("无法查找到输入的员工信息!\n");

}



void sort(void)

{

if (head == NULL)

{

printf("链表为空，排序失败！\n");

menu();

}

int choice;

printf("%s%s\n", STARS, STARS);

printf(" 请输入数字选择功能\n");

printf(" 1)根据工号进行排序\n");

printf(" 2)根据薪水进行排序\n");

printf(" 3)返回上一级菜单\n");

printf("%s%s\n", STARS, STARS);

printf("请输入数字选择");

scanf("%d", &choice);

getchar();

switch (choice)

{

case 1:

sort_number(head);

break;

case 2:

sort_payment(head);

break;

case 3:

menu();

break;

default:

printf("输入错误！请重新输入\n");

sort();

}

}



void sort_number(struct staff *head)

{

STAFF *p1, *p2;

char name[20], sex[20], phone[20], number[20], department[20], position[20];

int year,payment;

for (p1 = head->next; p1 != NULL; p1 = p1->next)

{

for (p2 = p1->next; p2 != NULL; p2 = p2->next)

{

if (strcmp(p1->number, p2->number) == 1)

{

strcpy(name, p1->name);

strcpy(sex, p1->sex);

strcpy(phone, p1->phone);

strcpy(number, p1->number);

strcpy(department, p1->department);

strcpy(position, p1->position);

year = p1->year;

payment = p1->payment;//

strcpy(p1->name, p2->name);

strcpy(p1->sex, p2->sex);

strcpy(p1->phone, p2->phone);

strcpy(p1->number, p2->number);

strcpy(p1->department, p2->department);

strcpy(p1->position, p2->position);

p1->year = p2->year;

p1->payment = p2->payment;//

strcpy(p2->name, name);

strcpy(p2->sex, sex);

strcpy(p2->phone, phone);

strcpy(p2->number, number);

strcpy(p2->department, department);

strcpy(p2->position, position);

p2->year = year;

p2->payment = payment;

}

}

}

display(head);

}



void sort_payment(struct staff *head)

{

STAFF *p1, *p2;

char name[20], sex[20], phone[20], number[20], department[20], position[20];

int year,payment;

for (p1 = head->next; p1 != NULL; p1 = p1->next)

{

for (p2 = p1->next; p2 != NULL; p2 = p2->next)

{

if (p1->payment>p2->payment)

{

strcpy(name, p1->name);

strcpy(sex, p1->sex);

strcpy(phone, p1->phone);

strcpy(number, p1->number);

strcpy(department, p1->department);

strcpy(position, p1->position);

year = p1->year;

payment = p1->payment;//

strcpy(p1->name, p2->name);

strcpy(p1->sex, p2->sex);

strcpy(p1->phone, p2->phone);

strcpy(p1->number, p2->number);

strcpy(p1->department, p2->department);

strcpy(p1->position, p2->position);

p1->year = p2->year;

p1->payment = p2->payment;//

strcpy(p2->name, name);

strcpy(p2->sex, sex);

strcpy(p2->phone, phone);

strcpy(p2->number, number);

strcpy(p2->department, department);

strcpy(p2->position, position);

p2->year = year;

p2->payment = payment;//

}

}

}

display(head);

}



void search_phone(void)

{

char phone[SIZE_W];

int test = 0;

p = head;

printf("请输入要查找的员工的姓名:");

scanf("%s", phone);

while (p!=NULL)

{

if (strcmp((p->phone), phone) == 0)

{

printf("员工信息：\n");

printf("%s%s\n", STARS, STARS);

printf("员工姓名 员工性别 员工手机号码\t 员工工号 员工所属部门 员工职位 员工入职年份 员工薪水\n");

printf("%s\t", p->name);

printf("%s\t", p->sex);

printf("%s\t", p->phone);

printf("%s\t", p->number);

printf("%s\t", p->department);

printf("%s\t", p->position);

printf("%d\t", p->year);

printf("%d\n", p->payment);

test++;

break;

}

p = p->next;

}

if (test == 0)

printf("不存在该信息!");

}



void exit_system(void)

{

int choice;

printf("%s%s\n", STARS, STARS);

printf("确定要退出本系统么？\n");

printf(" 请输入数字决定是否退出\n");

printf(" 1)确认退出\n");

printf(" 2)返回上一级菜单\n");

printf("%s%s\n", STARS, STARS);

printf("请输入数字选择");

scanf("%d", &choice);

getchar();

switch (choice)

{

case 1:

printf("感谢您的使用！再见！\n");

exit(EXIT_FAILURE);

case 2:

menu();

break;

default:

printf("输入错误！请重新输入\n");

exit_system();

}

}
