#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *scoreLevel[] = {
	"����",
	"����",
	"�ϸ�",
	"������"
};

struct Student{
	char name[128];
	int score; 
	struct Student *next; 
};

void showMenu();
int recChoice(int *pChoice);
int showScore(struct Student *head);
int modifyScore(struct Student *head, char *name);
struct Student *createNode();
int addStudent(struct Student **phead);
int removeStudent(struct Student **phead, char *name);
int statsScore(struct Student *head);
int saveNodes(struct Student *head);
int readNodes(struct Student **phead);
int clearAllNodes(struct Student *head);
int choiceSort(struct Student **phead);

int main(void) {
	
	int choice;
	struct Student *head = NULL;
	char name[64];
	
//  �����ݶ����ļ���ȡ��������(������bug,��û�ҵ�ԭ��)
//	if (readNodes(&head) == 0){
//		printf("��û�������ļ�,���߶�ȡ���ݳ���\n");
//	}
	
	// �����ݶ����ļ���ȡ��������
	readNodes(&head);
	
	// ѭ�������û�����
	do {
		// ��ʾ�˵�
		showMenu();
		
		// �����û�����
		if (recChoice(&choice) == 0){
			printf("��������Ч��ѡ��\n");
			continue;
		}

		switch (choice){
			case 0:
				break;
				
			case 2:
				if (showScore(head) == 0){
					printf("�ɼ��б�Ϊ��,������Ӽ�¼\n");
					continue;
				}
				break;
				
			case 3:
				printf("������ѧ������:\n");
				scanf("%s", name); 
				if (modifyScore(head, name) == 0){
					printf("ѧ������Ϊ��,���߲�����\n");
					continue;
				}
				// ���name�ַ������ֵ 
				memset(name, 0, sizeof(name)); 
				break;
				
			case 1:
				if (addStudent(&head) == 0){
					printf("���ѧ��ʧ��\n");
					continue;
				}
				break;
				
			case 4:
				printf("������ѧ������:\n");
				scanf("%s", name); 
				if (removeStudent(&head, name) == 0){
					printf("ɾ��ʧ��\n");
					continue;
				}
				// ���name�ַ������ֵ 
				memset(name, 0, sizeof(name)); 
				break;
				
			case 5:
				if (statsScore(head) != 1){
					printf("ͳ��ѧ���ɼ�����\n");
					continue;
				}
				break;

			case 6:
				if (1 != (choiceSort(&head))){
					printf("�������\n");
					continue; 
				} 
				break; 
				
			case 7:
				if (saveNodes(head) == 0){
					printf("�������ݳ���\n");
					continue;
				}
				break;
		}
	}while(choice);
	
	clearAllNodes(head);
	
	return 0;
}

void showMenu(){
	// ����:�г����ܲ˵�
	putchar('\n'); 
	printf("\t\tѧ������ϵͳ\t\t\n") ;
	printf("*****************************************************\n");
	printf("1 ¼��ɼ�\n");
	printf("2 ����ɼ�\n");
	printf("3 �޸ĳɼ�\n");
	printf("4 ɾ����¼\n");
	printf("5 ͳ�Ƴɼ�\n");
	printf("6 �ɼ�����\n");
	printf("7 �����޸�\n");
	printf("0 �˳�\n");
	printf("������ѡ��Ĺ���:\n");
	printf("*****************************************************\n");
	putchar('\n');
}

int recChoice(int *pChoice){
	// ����:�����û������ѡ��
	// ����:pChoice,�洢ѡ��ֵ�����ĵ�ַ
	// ����ֵ:������Ϸ�,����0; �Ϸ�����1
	int x;
	scanf("%d", &x);
	
	// ��ѡ��Ϸ��Խ���Ч��
	if (x<0 || x>7){
		// ���Ϸ�
		return 0;
	}
	*pChoice = x;
	return 1;
}

int showScore(struct Student *head){
	// ����:��ʾ����ѧ���ͳɼ� 
	// ����:head ����ͷָ��
	// ����ֵ:0��ʾͷָ��Ϊ��,�޷�����; 1��ʾ���Ա���
	if (head == NULL)
		return 0;
	
	struct Student *iNode;
	
	printf("---------------����ѧ���ɼ�---------------\n");
	for (iNode=head; iNode!=NULL; iNode=iNode->next){
		printf("����:%s �ɼ�%d\n", iNode->name, iNode->score);
	}
	putchar('\n');
}

int modifyScore(struct Student *head, char *name){
	// ����:�޸�ָ��ѧ���ĳɼ� 
	// ����:head ����ͷָ��
	// ����ֵ:0��ʾͷָ��Ϊ�ջ��޷��ҵ�,�޷�����; 1��ʾ�ҵ�; -1��ʾ�Ҳ���
	
	// ��־λ,���ڱ���Ƿ��ҵ���Ӧѧ�� 
	struct Student *iNode, *findNode = NULL;
	
	if (head == NULL)
		return 0;
	
	// ��������,�ҵ���Ӧ�ı���鼮
	for (iNode=head; iNode!=NULL; iNode=iNode->next){
		if (strcmp(iNode->name, name) == 0){
			findNode = iNode; 
			break; 
		}
	}
	 
	if (NULL != findNode){
		printf("�������޵ĳɼ�:\n");
		scanf("%d", &(findNode->score)); 
		return 1; 
	} 

	return 0;
}

struct Student *createNode(){
	// ����:�����½ڵ�,����ʼ��
	struct Student *newStu;
	
	// ��̬��������
	newStu = (struct Student *)malloc(sizeof(struct Student));
	
	// �������ʧ��
	if (NULL==newStu){
		return NULL;
	}
	
	// ¼��ṹ������
	printf("������ѧ������(����Ϊ��!!!):");
	scanf("%s", newStu->name);
	
	do{
		printf("������ѧ���ɼ�(0��100):");
		scanf("%d", &newStu->score);
	} while(newStu->score < 0 || newStu->score > 100); 

	return newStu;
}

int addStudent(struct Student **phead){
	struct Student *newStu = createNode();
	
	// �½�ʧ��
	if (newStu == NULL){
		return 0;
	}
	
	// ���ͷָ��ֵΪ��
	if (NULL==*phead){
		*phead = newStu;
		newStu->next = NULL;
		return 1;
	}
	
	// �������head -> newNode -> headԭ��ָ�����һ�ڵ�
	newStu->next = (*phead)->next;
	(*phead)->next = newStu;
	return 1;
}

int removeStudent(struct Student **phead, char *name){
	// ����:ɾ��ָ������
	// ��־λ,���ڱ���Ƿ��ҵ���Ӧѧ�� 
	int find = 0;
	// ����ǰһ���ڵ�͵�ǰ�ڵ�
	struct Student *curNode, *preNode = NULL;
	
	for (curNode=*phead; curNode!=NULL; preNode=curNode, curNode=curNode->next){
		// ����,�Ƚ�����
		if (strcmp(curNode->name, name) == 0){
			find = 1;
			break;
		}
	}
	
	if (find){
		// ���ɾ������ͷ�ڵ�
		if (preNode == NULL){
			*phead = (*phead)->next;
			free(curNode);
		}
		else{
		// ɾ���Ĳ���ͷ�ڵ�
			preNode->next = curNode->next;
			free(curNode);
		}
	}
	
	return find;
}

//int statsScore(){
//	// ����: ͳ�Ʒ��� 
//} 

int saveNodes(struct Student *head){
	// ����:�������������нڵ����ݵ�ָ���ļ�
	
	FILE *fp;
	struct Student *iNode;
	
	// ���ļ�
	if ((fp = fopen("StudentScoreDB", "wb")) == NULL) return 0;
	
	// ѭ������д������
	for (iNode=head; iNode!=NULL; iNode=iNode->next){
		if (fwrite(iNode, sizeof(struct Student), 1, fp) != 1) return 0;
	}
	
	// �ر��ļ�
	fclose(fp);
	
	return 1;
}

int readNodes(struct Student **phead){
	// ����:��ȡ���нڵ�����,���һ������
	
	// tailBook���ڱ���������һ���ڵ�
	FILE *fp;
	struct Student *newStu, *tailBook;
	
	//���ļ�
	if ((fp=fopen("StudentScoreDB", "rb")) == NULL) return 0;

	// ��ȡ�ļ���������
	while (feof(fp) == 0){
		
		// ��̬�����ڵ�
		if ((newStu = (struct Student *)malloc(sizeof(struct Student))) == NULL) return 0;
		
		// ���ļ��ж�ȡ�Ľṹ�����ݴ�ŵ��¿��Ľڵ���
		if (fread(newStu, sizeof(struct Student), 1, fp) != 1) return 0;
		
		// ���ڵ���ӵ�ͷָ��(�����׸��ڵ�)
		if (*phead == NULL){
			*phead = newStu;
			newStu->next = NULL;
			tailBook = newStu;
		}
		// ���ڵ���ӵ�����β��
		else{
			tailBook->next = newStu;
			tailBook = newStu;
			newStu->next = NULL;
		}
	}
	
	return 1;
}

// �ͷ���������ڵ�
int clearAllNodes(struct Student *head){
	struct Student *nextNode, *curNode;
	for (curNode=head; curNode!=NULL; curNode=nextNode){
		nextNode=curNode->next;
		free(curNode);
	}
	return 1;
}

// ѡ������ 
int choiceSort(struct Student **phead){
	// ���ͷָ��ֵΪ��
	if (*phead == NULL){
		return 0;
	}
	
	int ishead = 1; // ��־λ,���ڱ���Ƿ���ͷָ��λ��
	// iNode��jNode���ƶ�������������ʱѡ�������i��j���ͱ��� 
	// ������,Ϊ�����������ڽ������ܹ�����������,��Ҫ�ֱ��¼i��j�ڵ����һ���ڵ�
	// minNode�ڵ��minPreNode�ڵ�ֱ��¼��С�ڵ����С�ڵ����һ���ڵ�
	struct Student *iNode, *jNode, *iPreNode, *jPreNode; 
	struct Student *minPreNode, *minNode;
	struct Student *temp;
	
	for (iNode=*phead, iPreNode=NULL; iNode->next != NULL; iPreNode=minNode, iNode=minNode->next){
		minNode = iNode;
		for (jNode=iNode->next, jPreNode=iNode; jNode != NULL; jPreNode=jNode, jNode=jNode->next){
			// ��̨��,�ҵ���С�ڵ�
			if (jNode->score < minNode->score){
				minNode = jNode;
				minPreNode = jPreNode;
			}
		}
		
		// �����С�ڵ����iNode�ڵ�,������
		if (minNode == iNode){
			// ͷ�ڵ㲻�ٲ��뽻�� 
			ishead = 0;
			continue;
		}
		
		// �����ǰi�ڵ����һ���ڵ������С�ڵ�,��ô���߽���
		if (iNode->next == minNode){
			temp = minNode->next;
			minNode->next = iNode;
			iNode->next = temp;
			
			if (iPreNode != NULL){
				iPreNode->next = minNode;
			}
			
			// ���ͷָ����뽻��
			if (ishead){
				*phead = minNode;
				ishead = 0;
			}
			continue;
		}
		
		// �����ǰi�ڵ����һ���ڵ㲻����С�ڵ�,��ô�����������
		// �ڵ��Ľ���
		temp = minNode->next;
		minNode->next = iNode->next;
		minPreNode->next = iNode;
		iNode->next = temp;
		
		if (iPreNode != NULL){
			iPreNode->next = minNode;
		}
		
		// ���ͷָ����뽻��
		if (ishead){
			*phead = minNode;
			ishead = 0;
		}
	}
	
	return 1;
}

int statsScore(struct Student *head){
	// ����:ͳ��ѧ���ɼ� 
	
	// aLevel��ʾ100��90(����90)����ĸ���; bLevel89��80; cLevel79��60; dLevel���ϸ�; 
	int aLevel=0, bLevel=0, cLevel=0, dLevel=0, score; 
	struct Student *iNode; 
	
	// ͷָ��Ϊ�� 
	if (NULL == head) return 0; 

	for (iNode=head; NULL!=iNode; iNode=iNode->next){
		score = iNode->score;
		
		// ���������ȷ 
		if (0<=score && score<=100){
			// �����ȼ� 
			switch (score / 10){
				case 10:
				case 9:
					aLevel++; 
					printf("%s�ĳɼ���%s\n", iNode->name, scoreLevel[0]);
					break;
				case 8:
					bLevel++;
					printf("%s�ĳɼ���%s\n", iNode->name, scoreLevel[1]);
					break;
				case 7:
					cLevel++;
					printf("%s�ĳɼ���%s\n", iNode->name, scoreLevel[2]); 
					break;
				default:
					dLevel++;
					printf("%s�ĳɼ���%s\n", iNode->name, scoreLevel[3]);
					break; 
			}
		} 
	} 
	
	putchar('\n');
	printf("���������Ϊ:%d\n", aLevel);
	printf("���õ�����Ϊ:%d\n", bLevel);
	printf("�ϸ������Ϊ:%d\n", cLevel);
	printf("���ϸ������Ϊ:%d\n", dLevel);
	return 1; 
}
