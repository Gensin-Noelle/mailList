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
		printf("\n����������ѡ��\n");
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
			printf("��ӭ�ٴ�ʹ�ã���");
			system("pause");
			return;
		default:
			printf("���������������");
			break;
		}
		printf("\n�Ժ󷵻����˵�\n");
	}

}

struct mailList* creatList()
{
	struct mailList* head, * p1, * p2, * temp;
	int count = 0;
	printf("\nѧ������Ϊ0ʱ��������\n");
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
	if (head == NULL) printf("ͨѶ¼Ϊ�գ����������ϵ�ˣ�");
	else
	{
		printf("\n*************************************\n\n");
		while (head != NULL) {
			printf("ѧ��:%d\n", head->studentNO);
			printf("����:%s\n", head->name);
			printf("�绰:%d\n", head->telephone);
			printf("QQ��%d\n", head->QQ);
			printf("��ַ��%s\n\n", head->address);
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
	printf("������ѧ��\n");
	scanf_s("%d", &temp->studentNO);
	if (temp->studentNO == 0) goto END3;
	printf("����������\n");
	scanf_s("%s", &temp->name, sizeof(temp->name));
	printf("������绰\n");
	scanf_s("%d", &temp->telephone);
	printf("������QQ\n");
	scanf_s("%d", &temp->QQ);
	printf("�������ַ\n");
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
	printf("����������Ҫɾ����ѧ����ѧ�ţ�");
	scanf_s("%d", &temp);
	if (head == NULL)
	{
		printf("���ǿ�ͨѶ¼��");
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
	printf("ɾ��ʧ�ܣ�������ѧ�Ų���ͨѶ¼�ڣ�");
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
	printf("1.ͨ��ѧ�Ų���\t2.ͨ����������\n");
	printf("3.ͨ���绰����\t4.ͨ��QQ����\n");
	printf("5.ͨ����ַ����\n");
	printf("\n*********************************\n");
	printf("���������ѡ��:\n");
	scanf_s("%d", &temp_num);
	switch (temp_num)
	{
	case 1:
		printf("����������Ҫ���ҵ�ѧ����ѧ��\n");
		scanf_s("%d", &temp_studentNo);
		while (head != NULL)
		{
			if (head->studentNO == temp_studentNo) {
				output(head,0);
				break;
			}
			if (head->next == NULL) printf("�����ݲ���ͨѶ¼��!\n");
			head = head->next;
		}
		break;
	case 2:
		printf("����������Ҫ���ҵ�ѧ��������\n");
		scanf_s("%s", &temp_name, sizeof(temp_name));
		while (head != NULL)
		{
			if (strcmp(head->name, temp_name) == 0) {
				output(head,0);
				count++;
			}
			if (count == 0 && head->next == NULL) printf("�����ݲ���ͨѶ¼��!\n");
			head = head->next;
		}
		count = 0;
		break;
	case 3:
		printf("����������Ҫ���ҵ�ѧ���ĵ绰\n");
		scanf_s("%d", &temp_telephone);
		while (head != NULL)
		{
			if (head->telephone == temp_telephone) {
				output(head,0);
				break;
			}
			if (head->next == NULL) printf("�����ݲ���ͨѶ¼��!\n");
			head = head->next;
		}
		break;
	case 4:
		printf("����������Ҫ���ҵ�ѧ����QQ\n");
		scanf_s("%d", &temp_QQ);
		while (head != NULL)
		{
			if (head->QQ == temp_QQ) {
				output(head,0);
				break;
			}
			if (head->next == NULL) printf("�����ݲ���ͨѶ¼��!\n");
			head = head->next;
		}
		break;
	case 5:
		printf("����������Ҫ���ҵ�ѧ���ĵ�ַ\n");
		scanf_s("%s", &temp_address, sizeof(temp_address));
		while (head != NULL)
		{
			if (strcmp(head->address, temp_address) == 0) {
				output(head,0);
				count++;
			}
			if (count == 0 && head->next == NULL) printf("�����ݲ���ͨѶ¼��!\n");
			head = head->next;
		}
		count = 0;
		break;
	default:
		printf("���������������/\n");
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
	printf("\n************�����ߵ�ͨѶ¼************\n\n");
	printf("\n\t1.��ӡ\t2.����\t3.����\t\n");
	printf("\t4.ɾ��\t5.����\t6.����\t\n");
	printf("\t7.���\t8.�˳�");
	printf("\n\n*************************************\n");
}

void print(struct mailList* head)
{
	FILE* fp;
	errno_t err;
	struct mailList* p1;
	char filename[30] = {'\0'};
	p1 = head;
	printf("������Ҫ��ӡ���ļ�����ȫ·����example F://text1.txt��\n");
	scanf_s("%s", filename, sizeof(filename));
	if ((err = fopen_s(&fp, filename, "wb")) != 0) //���ļ���ֻд
	{
		printf("cannot open file\n");
		return;
	}
	while (head != NULL)
	{
		if (fwrite(head, sizeof(struct mailList), 1, fp) != 1)
			printf("д�����\n");
		head = head->next;
	}
	fclose(fp); //�ر��ļ�
	head = p1;
	if ((err = fopen_s(&fp, filename, "rb")) != 0) //�ٴδ��ļ���ֻ��
	{
		printf("cannot open file\n");
		return;
	}
	printf("д����������£�\n");
	while (head != NULL)
	{
		fread(head, sizeof(struct mailList), 1, fp);
		printf("ѧ��:%d\n", head->studentNO);
		printf("����:%s\n", head->name);
		printf("�绰:%d\n", head->telephone);
		printf("QQ��%d\n", head->QQ);
		printf("��ַ��%s\n\n", head->address);
		head = head->next;
	}
	fclose(fp); //�ر��ļ�
}