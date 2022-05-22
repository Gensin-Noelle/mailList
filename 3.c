#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define E sizeof(struct mailList)

struct mailList {
	int studentNO;
	char name[30];
	long telephone;
	long QQ;
	char address[50];
	struct mailList* next;
};

void menu();
struct mailList* creatList();
void print(struct mailList* head);
struct mailList* input();
struct mailList* increase(struct mailList* head);
struct mailList* delete(struct mailList* head);
struct mailList* sort(struct mailList* head);
void search(struct mailList* head);
void output(struct mailList* head,int num);

int main()
{
	struct mailList* head;
	head = NULL;
	int num;
	while (1)
	{
		menu();
		printf("\n请输入您的选择\n");
		scanf_s("%d", &num);
		switch (num)
		{
		case 1:
			print(head);
			break;
		case 2:
			search(head);
			break;
		case 3:
			head = creatList();
			break;
		case 4:
			head = delete(head);
			break;
		case 5:
			head = increase(head);
			break;
		case 6:
			head = sort(head);
			break;
		case 7:
			output(head,1);
			break;
		case 8:
			printf("欢迎再次使用！！");
			system("pause");
			return;
		default:
			printf("你输入的数字有误");
			break;
		}
		printf("\n稍后返回主菜单\n");
	}

}

struct mailList* creatList()
{
	struct mailList* head, * p1, * p2, * temp;
	int count = 0;
	printf("\n学号输入为0时结束操作\n");
	temp = input();
	head = NULL;
	p1 = p2 = (struct mailList*)malloc(E);
	while (temp->studentNO != 0)
	{
		count++;
		if (count == 1) head = temp;
		else p1->next = temp;
		p1 = temp;
		temp = (struct mailList*)malloc(E);
		temp = input();
	}
	p1->next = NULL;
	return head;
}

void output(struct mailList* head,int num)
{
	if (head == NULL) printf("通讯录为空，请先添加联系人！");
	else
	{
		printf("\n*************************************\n\n");
		while (head != NULL) {
			printf("学号:%d\n", head->studentNO);
			printf("姓名:%s\n", head->name);
			printf("电话:%d\n", head->telephone);
			printf("QQ：%d\n", head->QQ);
			printf("地址：%s\n\n", head->address);
			if (num == 0) break;
			head = head->next;
		}
		printf("\n\n*************************************\n");
	}
}

struct mailList* input()
{
	struct mailList* temp;
	temp = (struct mailList*)malloc(E);
	printf("请输入学号\n");
	scanf_s("%d", &temp->studentNO);
	if (temp->studentNO == 0) goto END3;
	printf("请输入姓名\n");
	scanf_s("%s", &temp->name, sizeof(temp->name));
	printf("请输入电话\n");
	scanf_s("%d", &temp->telephone);
	printf("请输入QQ\n");
	scanf_s("%d", &temp->QQ);
	printf("请输入地址\n");
	scanf_s("%s", &temp->address, sizeof(temp->address));
END3:;
	return temp;
}

struct mailList* increase(struct mailList* head)
{
	struct mailList* p1, * p2, * p3;
	struct mailList* temp;
	temp = input();
	p2 = (struct mailList*)malloc(E);
	p1 = p3 = head;
	if (head == NULL)
	{
		head = temp;
		head->next = NULL;
		goto END;
	}
	else
	{
		while (p1 != NULL)
		{
			if (p1->studentNO > temp->studentNO)
			{
				if (temp->studentNO < p3->studentNO)
				{
					temp->next = p1;
					head = temp;
					goto END;
				}
				else
				{
					p2->next = temp;
					temp->next = p1;
					goto END;
				}
			}
			p2 = p1;
			p1 = p1->next;
		}
		p2->next = temp;
		temp->next = NULL;
	END:;
	}
	return head;
}

struct mailList* delete(struct mailList* head)
{
	struct mailList* p1, * p2, * p3;
	int temp;
	p1 = p2 = p3 = head;
	printf("请输入你想要删除的学生的学号：");
	scanf_s("%d", &temp);
	if (head == NULL)
	{
		printf("这是空通讯录！");
		goto END2;
	}
	while (p1 != NULL)
	{
		if (p1->studentNO == temp)
		{
			if (p3 == p1)
			{
				head = head->next;
				goto END2;
			}
			else
			{
				if (p1->next == NULL)
				{
					p2->next = NULL;
					goto END2;
				}
				else
				{
					p2->next = p1->next;
					goto END2;
				}
			}
		}
		p2 = p1;
		p1 = p1->next;
	}
	printf("删除失败，您输入学号不在通讯录内！");
END2:;
	return head;

}

void search(struct mailList* head)
{
	int temp_num, count = 0;
	int temp_studentNo;
	char temp_name[20] = { '\0' }, temp_address[30] = { '\0' };
	long temp_QQ, temp_telephone;
	printf("\n*********************************\n");
	printf("1.通过学号查找\t2.通过姓名查找\n");
	printf("3.通过电话查找\t4.通过QQ查找\n");
	printf("5.通过地址查找\n");
	printf("\n*********************************\n");
	printf("请输入你的选择:\n");
	scanf_s("%d", &temp_num);
	switch (temp_num)
	{
	case 1:
		printf("请输入你想要查找到学生的学号\n");
		scanf_s("%d", &temp_studentNo);
		while (head != NULL)
		{
			if (head->studentNO == temp_studentNo) {
				output(head,0);
				break;
			}
			if (head->next == NULL) printf("该数据不在通讯录内!\n");
			head = head->next;
		}
		break;
	case 2:
		printf("请输入你想要查找到学生的姓名\n");
		scanf_s("%s", &temp_name, sizeof(temp_name));
		while (head != NULL)
		{
			if (strcmp(head->name, temp_name) == 0) {
				output(head,0);
				count++;
			}
			if (count == 0 && head->next == NULL) printf("该数据不在通讯录内!\n");
			head = head->next;
		}
		count = 0;
		break;
	case 3:
		printf("请输入你想要查找到学生的电话\n");
		scanf_s("%d", &temp_telephone);
		while (head != NULL)
		{
			if (head->telephone == temp_telephone) {
				output(head,0);
				break;
			}
			if (head->next == NULL) printf("该数据不在通讯录内!\n");
			head = head->next;
		}
		break;
	case 4:
		printf("请输入你想要查找到学生的QQ\n");
		scanf_s("%d", &temp_QQ);
		while (head != NULL)
		{
			if (head->QQ == temp_QQ) {
				output(head,0);
				break;
			}
			if (head->next == NULL) printf("该数据不在通讯录内!\n");
			head = head->next;
		}
		break;
	case 5:
		printf("请输入你想要查找到学生的地址\n");
		scanf_s("%s", &temp_address, sizeof(temp_address));
		while (head != NULL)
		{
			if (strcmp(head->address, temp_address) == 0) {
				output(head,0);
				count++;
			}
			if (count == 0 && head->next == NULL) printf("该数据不在通讯录内!\n");
			head = head->next;
		}
		count = 0;
		break;
	default:
		printf("你输入的数字有误/\n");
		break;
	}
}

struct mailList* sort(struct mailList* head)
{
	int studentNO;
	char name[30];
	long telephone;
	long QQ;
	char address[50];
	struct mailList* p1, * p2;
	int count = -1;
	int i, j;
	p1 = p2 = head;
	while (p2 != NULL)
	{
		p2 = p2->next;
		count++;
	}
	for (i = 0;i < count;i++)
		for (j = 0;j < count - i;j++)
		{
			if (p1->next == NULL) p1 = head;
			p2 = p1;
			p1 = p1->next;
			if (p2->studentNO > p1->studentNO)
			{
				studentNO = p1->studentNO;
				p1->studentNO = p2->studentNO;
				p2->studentNO = studentNO;

				strcpy_s(name, strlen(p1->name) + 1, p1->name);
				strcpy_s(p1->name, strlen(p2->name) + 1, p2->name);
				strcpy_s(p2->name, strlen(name) + 1, name);

				telephone = p1->telephone;
				p1->telephone = p2->telephone;
				p2->telephone = telephone;

				QQ = p1->QQ;
				p1->QQ = p2->QQ;
				p2->QQ = QQ;

				strcpy_s(address, strlen(p1->address) + 1, p1->address);
				strcpy_s(p1->address, strlen(p2->address) + 1, p2->address);
				strcpy_s(p2->address, strlen(address) + 1, address);
			}
		}
	return head;
}

void menu()
{
	printf("\n************旅行者的通讯录************\n\n");
	printf("\n\t1.打印\t2.查找\t3.重置\t\n");
	printf("\t4.删除\t5.插入\t6.排序\t\n");
	printf("\t7.输出\t8.退出");
	printf("\n\n*************************************\n");
}

void print(struct mailList* head)
{
	FILE* fp;
	errno_t err;
	struct mailList* p1;
	char filename[30] = {'\0'};
	p1 = head;
	printf("请输入要打印的文件名（全路径，example F://text1.txt）\n");
	scanf_s("%s", filename, sizeof(filename));
	if ((err = fopen_s(&fp, filename, "wb")) != 0) //打开文件，只写
	{
		printf("cannot open file\n");
		return;
	}
	while (head != NULL)
	{
		if (fwrite(head, sizeof(struct mailList), 1, fp) != 1)
			printf("写入出错\n");
		head = head->next;
	}
	fclose(fp); //关闭文件
	head = p1;
	if ((err = fopen_s(&fp, filename, "rb")) != 0) //再次打开文件，只读
	{
		printf("cannot open file\n");
		return;
	}
	printf("写入的内容如下：\n");
	while (head != NULL)
	{
		fread(head, sizeof(struct mailList), 1, fp);
		printf("学号:%d\n", head->studentNO);
		printf("姓名:%s\n", head->name);
		printf("电话:%d\n", head->telephone);
		printf("QQ：%d\n", head->QQ);
		printf("地址：%s\n\n", head->address);
		head = head->next;
	}
	fclose(fp); //关闭文件
}