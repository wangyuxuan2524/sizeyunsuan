/*某个小学老师请你为她编写一个能够自动生成四则运算练习题的小程序，要求输入年级和题目数量，程序根据年级输出规定数量的题目，具体要求如下：
·一年级运算数为20以内，只生成加法或减法运算式，结果小于20
·二年级运算数为50以内，生成加法和减法混合运算式，结果小于50
·三年级运算数为1000以内，生成加法、减法和乘法混合运算式
·四到六年级运算数为非负整数，生成至少带有三个运算符（从加减乘除四个符号中任选三个）和括号的混合运算式
·结果不能为负数*/
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

static void enter(int i, int j) {
	if (i % j == 0) {
		printf("\n");
	}
}//用于每行显示j个运算式
static void grade1(int i) {
	while (1) {
		int x = rand() % 2 + 1;//随机生成1或2
		int a = rand() % 20;//随机生成小于20的数字
		int b = rand() % 20;
		if (x == 1 && a + b < 20) {
			printf("%03d：%d+%d\t\t", i, a, b);
			enter(i, 5);
			break;
		}
		if (x == 2 && a - b >= 0) {
			printf("%03d：%d-%d\t\t", i, a, b);
			enter(i, 5);
			break;
		}
	}
}//一年级的题目，加法或减法，0<=运算数<20，0<=结果<20
static void grade2(int i) {
	while (1) {
		int x1 = rand() % 2 + 1;
		int x2 = rand() % 2 + 1;
		int a = rand() % 50;
		int b = rand() % 50;
		int c = rand() % 50;
		if (x1 == 1 && x2 == 2 && a + b - c >= 0 && a + b - c < 50) {
			printf("%03d：%d+%d-%d\t\t", i, a, b, c);
			enter(i, 5);
			break;
		}
		if (x1 == 2 && x2 == 1 && a - b + c >= 0 && a - b + c < 50) {
			printf("%03d：%d-%d+%d\t\t", i, a, b, c);
			enter(i, 5);
			break;
		}
	}
}//二年级的题目，加减混合，0<=运算数<50，0<=结果<50
static void grade3(int i) {
	while (1) {
		int x1 = rand() % 3 + 1;
		int x2 = rand() % 3 + 1;
		int x3 = rand() % 3 + 1;
		int a = rand() % 1000;
		int b = rand() % 1000;
		int c = rand() % 1000;
		int d = rand() % 1000;
		if (x1 == 1 && x2 == 2 && x3 == 3 && a + b - c * d >= 0) {
			printf("%03d：%d+%d-%d*%d\t\t\t", i, a, b, c, d);
			enter(i, 3);
			break;
		}//加减乘
		if (x1 == 1 && x2 == 3 && x3 == 2 && a + b * c - d >= 0) {
			printf("%03d：%d+%d*%d-%d\t\t\t", i, a, b, c, d);
			enter(i, 3);
			break;
		}//加乘减
		if (x1 == 2 && x2 == 1 && x3 == 3 && a - b + c * d >= 0) {
			printf("%03d：%d-%d+%d*%d\t\t\t", i, a, b, c, d);
			enter(i, 3);
			break;
		}//减加乘
		if (x1 == 2 && x2 == 3 && x3 == 1 && a - b * c + d >= 0) {
			printf("%03d：%d-%d*%d+%d\t\t\t", i, a, b, c, d);
			enter(i, 3);
			break;
		}//减乘加
		if (x1 == 3 && x2 == 1 && x3 == 2 && a * b + c - d >= 0) {
			printf("%03d：%d*%d+%d-%d\t\t\t", i, a, b, c, d);
			enter(i, 3);
			break;
		}//乘加减
		if (x1 == 3 && x2 == 2 && x3 == 1 && a * b - c + d >= 0) {
			printf("%03d：%d*%d-%d+%d\t\t\t", i, a, b, c, d);
			enter(i, 3);
			break;
		}//乘减加
	}
}//三年级的题目，加减乘混合，运算数<1000
static void grade456(int i) {
	while (1) {
		int x1 = rand() % 4 + 1;
		int x2 = rand() % 4 + 1;
		int x3 = rand() % 4 + 1;
		int x4 = rand() % 4 + 1;
		int o = rand() % 3 + 1;//控制括号位置
		int a = rand() % 1000;
		int b = rand() % 1000;
		int c = rand() % 1000;
		int d = rand() % 1000;
		if (x1 == 1 && x2 == 2 && x3 == 3) {
			if (o == 1 && (a + b - c) * d >= 0) {
				printf("%03d：(%d+%d-%d)*%d\t\t\t", i, a, b, c, d);
				enter(i, 3);
				break;
			}
			if (o == 2 && a + (b - c) * d >= 0) {
				printf("%03d：%d+(%d-%d)*%d\t\t\t", i, a, b, c, d);
				enter(i, 3);
				break;
			}
		}//123;
		if (x1 == 1 && x2 == 2 && x3 == 4) {
			if (d != 0) { //防止/0
				if (o == 1 && (a + b - c) / (float)d >= 0) {
					printf("%03d：(%d+%d-%d)/%d\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
				if (o == 2 && a + (b - c) / (float)d >= 0) {
					printf("%03d：%d+(%d-%d)/%d\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
			}
		}//124;
		if (x1 == 1 && x2 == 3 && x3 == 2) {
			if (o == 1 && (a + b) * c - d >= 0) {
				printf("%03d：(%d+%d)*%d-%d\t\t\t", i, a, b, c, d);
				enter(i, 3);
				break;
			}
			if (o == 2 && a + b * (c - d) >= 0) {
				printf("%03d：%d+%d*(%d-%d)\t\t\t", i, a, b, c, d);
				enter(i, 3);
				break;
			}
		}//132;
		if (x1 == 1 && x2 == 3 && x3 == 4) {
			if (d != 0) { //防止/0
				if (o == 1 && (a + b) * c / (float)d >= 0) {
					printf("%03d：(%d+%d)*%d/%d\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
				if (o == 2 && (a + b * c) / (float)d >= 0) {
					printf("%03d：(%d+%d*%d)/%d\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
			}
		}//134;
		if (x1 == 1 && x2 == 4 && x3 == 2) {
			if (c != 0 && c - d != 0) { //防止/0
				if (o == 1 && (a + b) / (float)c - d >= 0) {
					printf("%03d：(%d+%d)/%d-%d\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
				if (o == 2 && a + b / ((float)c - d) >= 0) {
					printf("%03d：%d+%d/(%d-%d)\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
			}
		}//142;
		if (x1 == 1 && x2 == 4 && x3 == 3) {
			if (c != 0 && c * d != 0) { //防止/0
				if (o == 1 && (a + b) / (float)c * d >= 0) {
					printf("%03d：(%d+%d)/%d*%d\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
				if (o == 2 && (a + b / (float)c) * d >= 0) {
					printf("%03d：(%d+%d/%d)*%d\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
				if (o == 3 && a + b / ((float)c * d) >= 0) {
					printf("%03d：%d+%d/(%d*%d)\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
			}
		}//143;
		///////////////////////////////////////////////////////////////////////////
		if (x1 == 2 && x2 == 1 && x3 == 3) {
			if (o == 1 && (a - b + c) * d >= 0) {
				printf("%03d：(%d-%d+%d)*%d\t\t\t", i, a, b, c, d);
				enter(i, 3);
				break;
			}
			if (o == 2 && a - (b + c) * d >= 0) {
				printf("%03d：%d-(%d+%d)*%d\t\t\t", i, a, b, c, d);
				enter(i, 3);
				break;
			}
			if (o == 3 && a - (b + c * d) >= 0) {
				printf("%03d：%d-(%d+%d*%d)\t\t\t", i, a, b, c, d);
				enter(i, 3);
				break;
			}
		}//213;
		if (x1 == 2 && x2 == 1 && x3 == 4) {
			if (d != 0) { //防止/0
				if (o == 1 && (a - b + c) / (float)d >= 0) {
					printf("%03d：(%d-%d+%d)/%d\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
				if (o == 2 && a - (b + c) / (float)d >= 0) {
					printf("%03d：%d-(%d+%d)/%d\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
				if (o == 3 && a - (b + c / (float)d) >= 0) {
					printf("%03d：%d-(%d+%d/%d)\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
			}
		}//214;
		if (x1 == 2 && x2 == 3 && x3 == 1) {
			if (o == 1 && (a - b) * c + d >= 0) {
				printf("%03d：(%d-%d)*%d+%d\t\t\t", i, a, b, c, d);
				enter(i, 3);
				break;
			}
			if (o == 2 && a - (b * c + d) >= 0) {
				printf("%03d：%d-(%d*%d+%d)\t\t\t", i, a, b, c, d);
				enter(i, 3);
				break;
			}
			if (o == 3 && a - b * (c + d) >= 0) {
				printf("%03d：%d-%d*(%d+%d)\t\t\t", i, a, b, c, d);
				enter(i, 3);
				break;
			}
		}//231;
		if (x1 == 2 && x2 == 3 && x3 == 4) {
			if (d != 0) { //防止/0
				if (o == 1 && (a - b) * c / (float)d >= 0) {
					printf("%03d：(%d-%d)*%d/%d\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
				if (o == 2 && (a - b * c) / (float)d >= 0) {
					printf("%03d：(%d-%d*%d)/%d\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
			}
		}//234;
		if (x1 == 2 && x2 == 4 && x3 == 1) {
			if (c != 0 && c + d != 0) { //防止/0
				if (o == 1 && (a - b) / (float)c + d >= 0) {
					printf("%03d：(%d-%d)/%d+%d\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
				if (o == 2 && a - (b / (float)c + d) >= 0) {
					printf("%03d：%d-(%d/%d+%d)\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
				if (o == 3 && a - b / ((float)c + d) >= 0) {
					printf("%03d：%d-%d/(%d+%d)\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
			}
		}//241;
		if (x1 == 2 && x2 == 4 && x3 == 3) {
			if (c != 0 && c * d != 0) { //防止/0
				if (o == 1 && (a - b) / (float)c * d >= 0) {
					printf("%03d：(%d-%d)/%d*%d\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
				if (o == 2 && (a - b / (float)c) * d >= 0) {
					printf("%03d：(%d-%d/%d)*%d\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
				if (o == 3 && a - b / ((float)c * d) >= 0) {
					printf("%03d：%d-%d/(%d*%d)\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
			}
		}//243;
		///////////////////////////////////////////////////////////////////////////
		if (x1 == 3 && x2 == 1 && x3 == 2) {
			if (o == 1 && a * (b + c) - d >= 0) {
				printf("%03d：%d*(%d+%d)-%d\t\t\t", i, a, b, c, d);
				enter(i, 3);
				break;
			}
			if (o == 2 && a * (b + c - d) >= 0) {
				printf("%03d：%d*(%d+%d-%d)\t\t\t", i, a, b, c, d);
				enter(i, 3);
				break;
			}
		}//312;
		if (x1 == 3 && x2 == 1 && x3 == 4) {
			if (d != 0) { //防止/0
				if (o == 1 && (a * b + c) / (float)d >= 0) {
					printf("%03d：(%d*%d+%d)/%d\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
				if (o == 2 && a * (b + c) / (float)d >= 0) {
					printf("%03d：%d*(%d+%d)/%d\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
				if (o == 3 && a * (b + c / (float)d) >= 0) {
					printf("%03d：%d*(%d+%d/%d)\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
			}
		}//314;
		if (x1 == 3 && x2 == 2 && x3 == 1) {
			if (o == 1 && a * (b - c) + d >= 0) {
				printf("%03d：%d*(%d-%d)+%d\t\t\t", i, a, b, c, d);
				enter(i, 3);
				break;
			}
			if (o == 2 && a * (b - c + d) >= 0) {
				printf("%03d：%d*(%d-%d+%d)\t\t\t", i, a, b, c, d);
				enter(i, 3);
				break;
			}
			if (o == 3 && a * b - (c + d) >= 0) {
				printf("%03d：%d*%d-(%d+%d)\t\t\t", i, a, b, c, d);
				enter(i, 3);
				break;
			}
		}//321;
		if (x1 == 3 && x2 == 2 && x3 == 4) {
			if (d != 0) { //防止/0
				if (o == 1 && (a * b - c) / (float)d >= 0) {
					printf("%03d：(%d*%d-%d)/%d\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
				if (o == 2 && a * (b - c) / (float)d >= 0) {
					printf("%03d：%d*(%d-%d)/%d\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
				if (o == 3 && a * (b - c / (float)d) >= 0) {
					printf("%03d：%d*(%d-%d/%d)\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
			}
		}//324;
		if (x1 == 3 && x2 == 4 && x3 == 1) {
			if (c != 0 && c + d != 0) { //防止/0
				if (o == 1 && a * (b / (float)c + d) >= 0) {
					printf("%03d：%d*(%d/%d+%d)\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
				if (o == 2 && a * b / ((float)c + d) >= 0) {
					printf("%03d：%d*%d/(%d+%d)\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
			}
		}//341;
		if (x1 == 3 && x2 == 4 && x3 == 2) {
			if (c != 0 && c - d != 0) { //防止/0
				if (o == 1 && a * (b / (float)c - d) >= 0) {
					printf("%03d：%d*(%d/%d-%d)\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
				if (o == 2 && a * b / ((float)c - d) >= 0) {
					printf("%03d：%d*%d/(%d-%d)\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
			}
		}//342;
		///////////////////////////////////////////////////////////////////////////
		if (x1 == 4 && x2 == 1 && x3 == 2) {
			if (b + c != 0 && b + c - d != 0) { //防止/0
				if (o == 1 && a / ((float)b + c) - d >= 0) {
					printf("%03d：%d/(%d+%d)-%d\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
				if (o == 2 && a / ((float)b + c - d) >= 0) {
					printf("%03d：%d/(%d+%d-%d)\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
			}
		}//412;
		if (x1 == 4 && x2 == 1 && x3 == 3) {
			if (b != 0 && b + c != 0 && b + c * d != 0) { //防止/0
				if (o == 1 && (a / (float)b + c) * d >= 0) {
					printf("%03d：(%d/%d+%d)*%d\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
				if (o == 2 && a / ((float)b + c) * d >= 0) {
					printf("%03d：%d/(%d+%d)*%d\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
				if (o == 3 && a / ((float)b + c * d) >= 0) {
					printf("%03d：%d/(%d+%d*%d)\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
			}
		}//413;
		if (x1 == 4 && x2 == 2 && x3 == 1) {
			if (b - c != 0 && b - c + d != 0 && b != 0) { //防止/0
				if (o == 1 && a / ((float)b - c) + d >= 0) {
					printf("%03d：%d/(%d-%d)+%d\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
				if (o == 2 && a / ((float)b - c + d) >= 0) {
					printf("%03d：%d/(%d-%d+%d)\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
				if (o == 3 && a / (float)b - (c + d) >= 0) {
					printf("%03d：%d/%d-(%d+%d)\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
			}
		}//421;
		if (x1 == 4 && x2 == 2 && x3 == 3) {
			if (b != 0 && b - c != 0 && b - c * d != 0) { //防止/0
				if (o == 1 && (a / (float)b - c) * d >= 0) {
					printf("%03d：(%d/%d-%d)*%d\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
				if (o == 2 && a / ((float)b - c) * d >= 0) {
					printf("%03d：%d/(%d-%d)*%d\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
				if (o == 3 && a / ((float)b - c * d) >= 0) {
					printf("%03d：%d/(%d-%d*%d)\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
			}
		}//423;
		if (x1 == 4 && x2 == 3 && x3 == 1) {
			if (b * c != 0 && b * c + d != 0 && b != 0) { //防止/0
				if (o == 1 && a / ((float)b * c) + d >= 0) {
					printf("%03d：%d/(%d*%d)+%d\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
				if (o == 2 && a / ((float)b * c + d) >= 0) {
					printf("%03d：%d/(%d*%d+%d)\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
				if (o == 3 && a / (float)b * (c + d) >= 0) {
					printf("%03d：%d/%d*(%d+%d)\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
			}
		}//431;
		if (x1 == 4 && x2 == 3 && x3 == 2) {
			if (b * c != 0 && b * c - d != 0 && b != 0) { //防止/0
				if (o == 1 && a / ((float)b * c) - d >= 0) {
					printf("%03d：%d/(%d*%d)-%d\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
				if (o == 2 && a / ((float)b * c - d) >= 0) {
					printf("%03d：%d/(%d*%d-%d)\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
				if (o == 3 && a / (float)b * (c - d) >= 0) {
					printf("%03d：%d/%d*(%d-%d)\t\t\t", i, a, b, c, d);
					enter(i, 3);
					break;
				}
			}
		}//432;
	}
}//四到六年级的题目，带有三个运算符（从加减乘除中任选三个）和括号的运算式

int main() {
	int a;//用于年级
	int b;//用于题目数量
	srand(time(NULL));//随机数种子
	while (1) {
		while (1) {
			printf("请输入年级：\n");
			if (scanf_s("%d", &a) == 1) {//输入年级
				if (a == 1 || a == 2 || a == 3 || a == 4 || a == 5 || a == 6) {
					break;
				}
				else {
					printf("错误，请重新输入年级\n");
				}
			}
			else {
				printf("错误，请重新输入年级\n");//输入非数字
				while (getchar() != '\n');
			}
		}
		while (1) {
			printf("请输入题目数量：\n");
			if (scanf_s("%d", &b)) {
				;//输入题目数量
				break;
			}
			else {
				printf("错误，请重新输入题目数量\n");
				while (getchar() != '\n');
			}
		}
		for (int i = 1; i <= b; i++) {
			if (a == 1) {
				grade1(i);
			}
			if (a == 2) {
				grade2(i);
			}
			if (a == 3) {
				grade3(i);
			}
			if (a == 4 || a == 5 || a == 6) {
				grade456(i);
			}
		}
		printf("\n");
		for (int o = 0; o < 120; o++) {
			printf("-");
		}
		printf("\n");
	}
}
