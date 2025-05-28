#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *scoreLevel[] = {
	"优秀",
	"良好",
	"合格",
	"不及格"
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
	
//  将数据读从文件读取到链表内(这里有bug,还没找到原因)
//	if (readNodes(&head) == 0){
//		printf("还没有数据文件,或者读取数据出错\n");
//	}
	
	// 将数据读从文件读取到链表内
	readNodes(&head);
	
	// 循环接收用户输入
	do {
		// 显示菜单
		showMenu();
		
		// 接收用户输入
		if (recChoice(&choice) == 0){
			printf("请输入有效的选项\n");
			continue;
		}

		switch (choice){
			case 0:
				break;
				
			case 2:
				if (showScore(head) == 0){
					printf("成绩列表为空,请先添加记录\n");
					continue;
				}
				break;
				
			case 3:
				printf("请输入学生姓名:\n");
				scanf("%s", name); 
				if (modifyScore(head, name) == 0){
					printf("学生姓名为空,或者不存在\n");
					continue;
				}
				// 清空name字符数组的值 
				memset(name, 0, sizeof(name)); 
				break;
				
			case 1:
				if (addStudent(&head) == 0){
					printf("添加学生失败\n");
					continue;
				}
				break;
				
			case 4:
				printf("请输入学生姓名:\n");
				scanf("%s", name); 
				if (removeStudent(&head, name) == 0){
					printf("删除失败\n");
					continue;
				}
				// 清空name字符数组的值 
				memset(name, 0, sizeof(name)); 
				break;
				
			case 5:
				if (statsScore(head) != 1){
					printf("统计学生成绩出错\n");
					continue;
				}
				break;

			case 6:
				if (1 != (choiceSort(&head))){
					printf("排序出错\n");
					continue; 
				} 
				break; 
				
			case 7:
				if (saveNodes(head) == 0){
					printf("保存数据出错\n");
					continue;
				}
				break;
		}
	}while(choice);
	
	clearAllNodes(head);
	
	return 0;
}

void showMenu(){
	// 功能:列出功能菜单
	putchar('\n'); 
	printf("\t\t学生管理系统\t\t\n") ;
	printf("*****************************************************\n");
	printf("1 录入成绩\n");
	printf("2 输出成绩\n");
	printf("3 修改成绩\n");
	printf("4 删除记录\n");
	printf("5 统计成绩\n");
	printf("6 成绩排序\n");
	printf("7 保存修改\n");
	printf("0 退出\n");
	printf("请输入选择的功能:\n");
	printf("*****************************************************\n");
	putchar('\n');
}

int recChoice(int *pChoice){
	// 功能:接收用户输入的选项
	// 参数:pChoice,存储选项值变量的地址
	// 返回值:如果不合法,返回0; 合法返回1
	int x;
	scanf("%d", &x);
	
	// 对选项合法性进行效验
	if (x<0 || x>7){
		// 不合法
		return 0;
	}
	*pChoice = x;
	return 1;
}

int showScore(struct Student *head){
	// 功能:显示所有学生和成绩 
	// 参数:head 链表头指针
	// 返回值:0表示头指针为空,无法遍历; 1表示可以遍历
	if (head == NULL)
		return 0;
	
	struct Student *iNode;
	
	printf("---------------所有学生成绩---------------\n");
	for (iNode=head; iNode!=NULL; iNode=iNode->next){
		printf("姓名:%s 成绩%d\n", iNode->name, iNode->score);
	}
	putchar('\n');
}

int modifyScore(struct Student *head, char *name){
	// 功能:修改指定学生的成绩 
	// 参数:head 链表头指针
	// 返回值:0表示头指针为空或无法找到,无法遍历; 1表示找到; -1表示找不到
	
	// 标志位,用于标记是否找到对应学生 
	struct Student *iNode, *findNode = NULL;
	
	if (head == NULL)
		return 0;
	
	// 遍历链表,找到对应的编号书籍
	for (iNode=head; iNode!=NULL; iNode=iNode->next){
		if (strcmp(iNode->name, name) == 0){
			findNode = iNode; 
			break; 
		}
	}
	 
	if (NULL != findNode){
		printf("请输入修的成绩:\n");
		scanf("%d", &(findNode->score)); 
		return 1; 
	} 

	return 0;
}

struct Student *createNode(){
	// 功能:创建新节点,并初始化
	struct Student *newStu;
	
	// 动态开辟新书
	newStu = (struct Student *)malloc(sizeof(struct Student));
	
	// 如果开辟失败
	if (NULL==newStu){
		return NULL;
	}
	
	// 录入结构体数据
	printf("请输入学生姓名(不能为空!!!):");
	scanf("%s", newStu->name);
	
	do{
		printf("请输入学生成绩(0到100):");
		scanf("%d", &newStu->score);
	} while(newStu->score < 0 || newStu->score > 100); 

	return newStu;
}

int addStudent(struct Student **phead){
	struct Student *newStu = createNode();
	
	// 新建失败
	if (newStu == NULL){
		return 0;
	}
	
	// 如果头指针值为空
	if (NULL==*phead){
		*phead = newStu;
		newStu->next = NULL;
		return 1;
	}
	
	// 否则插入head -> newNode -> head原本指向的下一节点
	newStu->next = (*phead)->next;
	(*phead)->next = newStu;
	return 1;
}

int removeStudent(struct Student **phead, char *name){
	// 功能:删除指定数据
	// 标志位,用于标记是否找到对应学生 
	int find = 0;
	// 定义前一个节点和当前节点
	struct Student *curNode, *preNode = NULL;
	
	for (curNode=*phead; curNode!=NULL; preNode=curNode, curNode=curNode->next){
		// 遍历,比较名称
		if (strcmp(curNode->name, name) == 0){
			find = 1;
			break;
		}
	}
	
	if (find){
		// 如果删除的是头节点
		if (preNode == NULL){
			*phead = (*phead)->next;
			free(curNode);
		}
		else{
		// 删除的不是头节点
			preNode->next = curNode->next;
			free(curNode);
		}
	}
	
	return find;
}

//int statsScore(){
//	// 功能: 统计分数 
//} 

int saveNodes(struct Student *head){
	// 功能:保存链表上所有节点数据到指定文件
	
	FILE *fp;
	struct Student *iNode;
	
	// 打开文件
	if ((fp = fopen("StudentScoreDB", "wb")) == NULL) return 0;
	
	// 循环链表并写入数据
	for (iNode=head; iNode!=NULL; iNode=iNode->next){
		if (fwrite(iNode, sizeof(struct Student), 1, fp) != 1) return 0;
	}
	
	// 关闭文件
	fclose(fp);
	
	return 1;
}

int readNodes(struct Student **phead){
	// 功能:读取所有节点数据,组成一个链表
	
	// tailBook用于标记链表最后一个节点
	FILE *fp;
	struct Student *newStu, *tailBook;
	
	//打开文件
	if ((fp=fopen("StudentScoreDB", "rb")) == NULL) return 0;

	// 读取文件所有内容
	while (feof(fp) == 0){
		
		// 动态创建节点
		if ((newStu = (struct Student *)malloc(sizeof(struct Student))) == NULL) return 0;
		
		// 将文件中读取的结构体数据存放到新开的节点中
		if (fread(newStu, sizeof(struct Student), 1, fp) != 1) return 0;
		
		// 将节点添加到头指针(链表首个节点)
		if (*phead == NULL){
			*phead = newStu;
			newStu->next = NULL;
			tailBook = newStu;
		}
		// 将节点添加到链表尾部
		else{
			tailBook->next = newStu;
			tailBook = newStu;
			newStu->next = NULL;
		}
	}
	
	return 1;
}

// 释放所有链表节点
int clearAllNodes(struct Student *head){
	struct Student *nextNode, *curNode;
	for (curNode=head; curNode!=NULL; curNode=nextNode){
		nextNode=curNode->next;
		free(curNode);
	}
	return 1;
}

// 选择排序 
int choiceSort(struct Student **phead){
	// 如果头指针值为空
	if (*phead == NULL){
		return 0;
	}
	
	int ishead = 1; // 标志位,用于标记是否是头指针位置
	// iNode和jNode类似对整形数据排序时选择排序的i和j整型变量 
	// 区别是,为了能让链表在交换后能够重新连接上,需要分别记录i和j节点的上一个节点
	// minNode节点和minPreNode节点分别记录最小节点和最小节点的上一个节点
	struct Student *iNode, *jNode, *iPreNode, *jPreNode; 
	struct Student *minPreNode, *minNode;
	struct Student *temp;
	
	for (iNode=*phead, iPreNode=NULL; iNode->next != NULL; iPreNode=minNode, iNode=minNode->next){
		minNode = iNode;
		for (jNode=iNode->next, jPreNode=iNode; jNode != NULL; jPreNode=jNode, jNode=jNode->next){
			// 擂台法,找到最小节点
			if (jNode->score < minNode->score){
				minNode = jNode;
				minPreNode = jPreNode;
			}
		}
		
		// 如果最小节点就是iNode节点,不交换
		if (minNode == iNode){
			// 头节点不再参与交换 
			ishead = 0;
			continue;
		}
		
		// 如果当前i节点的下一个节点就是最小节点,那么两者交换
		if (iNode->next == minNode){
			temp = minNode->next;
			minNode->next = iNode;
			iNode->next = temp;
			
			if (iPreNode != NULL){
				iPreNode->next = minNode;
			}
			
			// 如果头指针参与交换
			if (ishead){
				*phead = minNode;
				ishead = 0;
			}
			continue;
		}
		
		// 如果当前i节点的下一个节点不是最小节点,那么交换会更复杂
		// 节点间的交换
		temp = minNode->next;
		minNode->next = iNode->next;
		minPreNode->next = iNode;
		iNode->next = temp;
		
		if (iPreNode != NULL){
			iPreNode->next = minNode;
		}
		
		// 如果头指针参与交换
		if (ishead){
			*phead = minNode;
			ishead = 0;
		}
	}
	
	return 1;
}

int statsScore(struct Student *head){
	// 功能:统计学生成绩 
	
	// aLevel表示100到90(包括90)优秀的个数; bLevel89到80; cLevel79到60; dLevel不合格; 
	int aLevel=0, bLevel=0, cLevel=0, dLevel=0, score; 
	struct Student *iNode; 
	
	// 头指针为空 
	if (NULL == head) return 0; 

	for (iNode=head; NULL!=iNode; iNode=iNode->next){
		score = iNode->score;
		
		// 如果分数正确 
		if (0<=score && score<=100){
			// 分析等级 
			switch (score / 10){
				case 10:
				case 9:
					aLevel++; 
					printf("%s的成绩是%s\n", iNode->name, scoreLevel[0]);
					break;
				case 8:
					bLevel++;
					printf("%s的成绩是%s\n", iNode->name, scoreLevel[1]);
					break;
				case 7:
					cLevel++;
					printf("%s的成绩是%s\n", iNode->name, scoreLevel[2]); 
					break;
				default:
					dLevel++;
					printf("%s的成绩是%s\n", iNode->name, scoreLevel[3]);
					break; 
			}
		} 
	} 
	
	putchar('\n');
	printf("优秀的人数为:%d\n", aLevel);
	printf("良好的人数为:%d\n", bLevel);
	printf("合格的人数为:%d\n", cLevel);
	printf("不合格的人数为:%d\n", dLevel);
	return 1; 
}
