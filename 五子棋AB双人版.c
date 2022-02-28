#include<stdio.h>
#include<conio.h>//_getch()
#include<stdlib.h>//rand()

/**
 * @author:fanji
 * @qq:2967557176
 * @time:2021/11/6 3:53
 **/

int ch;
//默认A先下棋
static int isA = 1;
//初始化10*10的棋盘
static int arr[10][10];
//char **arr[10][10];
/*在C语言当中，字符串数组可以使用： char a[] [10]; 或者 char *a[]; 表示
第一种表示方式固定了每个字符串的最大大小。第二种没有字符串的大小限制。*/

int x = sizeof(arr) / sizeof(arr[0]), y = sizeof(arr[0]) / sizeof(arr[0][0]);
/*sizeof(arr[0][0])为一个元素占用的空间
sizeof(arr[0])为一行元素占用的空间
sizeof(arr)为整个数组占用的空间*/

static int M = 0, N = 0;
static int E = 0, F = 0;
/*使用static防止丢失*/

//展示棋盘上的棋子
int Show(int M, int N) {
	system("cls");//清屏
	for (int j = 0; j < x; j++) {
		printf("	");
		for (int k = 0; k < y; k++) {
			if (j == M && k == N) {
				if (isA) {
					printf("★	");
				} else {
					printf("☆	");
				}
			} else {
				switch (arr[j][k]) {
					case 0:
						printf("+	");
						break;
					case 1:
						printf("★	");
						break;
					default:
						printf("☆	");
						break;
				}
			}
		}
		printf("\n\n\n");
	}
	return 0;
}

int M1(int M, int N) {
	//M+
	int i = 1;
	for (int f = M; f + 1 < x; f++) {
		if (isA) {
			if (arr[f + 1][N] == 1) {
				i++;
			} else {
				break;
			}
		} else {
			if (arr[f + 1][N] == -1) {
				i++;
			} else {
				break;
			}
		}
	}
	return i;
}

int N1(int M, int N) {
	//N+
	int j = 1;
	for (int f = N; f + 1 < y; f++) {
		if (isA) {
			if (arr[M][f + 1] == 1) {
				j++;
			} else {
				break;
			}
		} else {
			if (arr[M][f + 1] == -1) {
				j++;
			} else {
				break;
			}
		}
	}
	return j;
}

int M1N1(int M, int N) {
	//M+N+
	int k = 1;
	for (int f = M, ff = N; f + 1 < x && ff + 1 < y; f++, ff++) {
		if (isA) {
			if (arr[f + 1][ff + 1] == 1) {
				k++;
			} else {
				break;
			}
		} else {
			if (arr[f + 1][ff + 1] == -1) {
				k++;
			} else {
				break;
			}
		}
	}
	return k;
}

int M0(int M, int N) {
	//M-
	int l = 1;
	for (int f = M; 0 < f; f--) {
		if (isA) {
			if (arr[f - 1][N] == 1) {
				l++;
			} else {
				break;
			}
		} else {
			if (arr[f - 1][N] == -1) {
				l++;
			} else {
				break;
			}
		}
	}
	return l;
}

int N0(int M, int N) {
	//N-
	int m = 1;
	for (int f = N; 0 < f; f--) {
		if (isA) {
			if (arr[M][f - 1] == 1) {
				m++;
			} else {
				break;
			}
		} else {
			if (arr[M][f - 1] == -1) {
				m++;
			} else {
				break;
			}
		}
	}
	return m;
}

int M0N0(int M, int N) {
	//M-N-
	int n = 1;
	for (int f = M, ff = N; 0 < f && 0 < ff; f--, ff--) {
		if (isA) {
			if (arr[f - 1][ff - 1] == 1) {
				n++;
			} else {
				break;
			}
		} else {
			if (arr[f - 1][ff - 1] == -1) {
				n++;
			} else {
				break;
			}
		}
	}
	return n;
}

int M0N1(int M, int N) {
	//M-N+
	int o = 1;
	for (int f = M, ff = N; 0 < f && ff + 1 < y; f--, ff++) {
		if (isA) {
			if (arr[f - 1][ff + 1] == 1) {
				o++;
			} else {
				break;
			}
		} else {
			if (arr[f - 1][ff + 1] == -1) {
				o++;
			} else {
				break;
			}
		}
	}
	return o;
}

int M1N0(int M, int N) {
	//M+N-
	int p = 1;
	for (int f = M, ff = N; f + 1 < x && 0 < ff; f++, ff--) {
		if (isA) {
			if (arr[f + 1][ff - 1] == 1) {
				p++;
			} else {
				break;
			}
		} else {
			if (arr[f + 1][ff - 1] == -1) {
				p++;
			} else {
				break;
			}
		}
	}
	return p;
}

//结束判断
int isOver(int M, int N, int max) {

	if ((M1(M, N) + M0(M, N)) > max || (N1(M, N) + N0(M, N)) > max || (M1N1(M, N) + M0N0(M, N)) > max || (M0N1(M, N) + M1N0(M, N)) > max) {
		if (isA) {
			printf("A玩家胜利！");
			exit(0);
		} else {
			printf("B玩家胜利！");
			exit(0);
		}
	}

	return 0;
}


int main() {
	//初始化棋盘
	Show(M, N);
	//新手引导
	printf("繁寂の五子棋（双人版）\n");
	printf("Time：2021/11/6 3:53\n");
	printf("A玩家用【WASD】控制移动，【空格】确定\n");
	printf("B玩家用【↑←↓→】控制移动，【Enter】确定");

	while (1) {
		ch = _getch();
		//判断动作先后
		if (isA) {


			//监听A的动作
			switch (ch) {
				case 119:
					if (M > 0) {
						M--;
					}
					Show(M, N);
					break;
				case 115:
					if (M < x - 1) {
						M++;
					}
					Show(M, N);
					break;
				case 97:
					if (N > 0) {
						N--;
					}
					Show(M, N);
					break;
				case 100:
					if (N < y - 1) {
						N++;
					}
					Show(M, N);
					break;
				case 32:
					arr[M][N] == 0 ? arr[M][N] = 1, Show(M, N), isOver(M, N, 5), isA = 0 : printf("左边的A笨蛋，这里有棋子了！");
					break;
			}


		} else {


			//监听B的动作
			switch (ch) {
				case 72:
					if (E > 0) {
						E--;
					}
					Show(E, F);
					break;
				case 80:
					if (E < x - 1) {
						E++;
					}
					Show(E, F);
					break;
				case 75:
					if (F > 0) {
						F--;
					}
					Show(E, F);
					break;
				case 77:
					if (F < y - 1) {
						F++;
					}
					Show(E, F);
					break;
				case 13:
					arr[E][F] == 0 ?  arr[E][F] = -1, Show(E, F), isOver(E, F, 5), isA = 1 : printf("右边的B笨蛋，这里有棋子了！");
					break;
			}


		}
	}

	return 0;
}
