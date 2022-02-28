#include<stdio.h>
#include<conio.h>//_getch()
#include<stdlib.h>//rand()
#include<time.h>//time()进行奇偶简单决策 
#include<windows.h>//system("color 0A")

/**
 * @author:fanji
 * @qq:2967557176
 * @time:2022/03/01 02:44
 **/

//_getch()获取的键盘码
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

static int M = 0, N = 0;//A的坐标
static int E = 0, F = 0;//B的坐标，这里是ai

static int reM = 0, reN = 0;//【函数isFb】的端点坐标
/*使用static防止丢失*/

//展示棋盘上的棋子
void Show(int M, int N) {
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
}

int M1(int M, int N) {
	//M+ 下
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
	//N+ 右
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
	//M+N+ 下右
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
	//M- 上
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
	//N- 左
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
	//M-N- 上左
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
	//M-N+ 上右
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
	//M+N- 下左
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
void isOver(int M, int N, int max) {

	if ((M1(M, N) + M0(M, N)) > max || (N1(M, N) + N0(M, N)) > max || (M1N1(M, N) + M0N0(M, N)) > max || (M0N1(M, N) + M1N0(M, N)) > max) {

		if (isA) {
			printf("你竟然赢了！");
			exit(0);
		} else {
			printf("哈哈哈，我赢了！");
			exit(0);
		}

	}

}

//间隔1个满足num个,isA决定是计算【我方】还是【敌方】，计算敌方先isA=1，后isA=0
int jg(int M, int N, int num) {
	num++;
	for (int i = M; i < x; i++) {
		for (int j = N; j < y; j++) {

			int M01 = (M1(M, N) + M0(M, N)) > num && M1(M, N) > 1 && M0(M, N) > 1;
			int N01 = (N1(M, N) + N0(M, N)) > num && N1(M, N) > 1 && N0(M, N) > 1;
			int MN1100 = (M1N1(M, N) + M0N0(M, N)) > num && M1N1(M, N) > 1 && M0N0(M, N) > 1;
			int M01N01 = (M0N1(M, N) + M1N0(M, N)) > num && M0N1(M, N) > 1 && M1N0(M, N) > 1;

			if ( M01 || N01 || MN1100 || M01N01) {
				return 1;
			} else {
				return 0;
			}
		}
	}
	return 0;
}

//计算M,N点的权重 内圈+2，外圈+1 敌方-1
int weight(int M, int N) {
	int we = 0, M20 = M - 2, M21 = M + 2, N20 = N - 2, N21 = N + 2;
	if (M - 2 < 0) {
		M20 = 0;
	}
	if (M + 2 >= x) {
		M21 = x - 1;
	}
	if (N - 2 < 0) {
		N20 = 0;
	}
	if (N + 2 >= y) {
		N21 = y - 1;
	}
	for (int i = M20; i <= M21; i++) {
		for (int j = N20; j <= N21; j++) {
			if (isA) {
				if (arr[i][j] == 1) {
					if (M + 1 == i || M - 1 == i || N + 1 == j || N - 1 == j) {
						we += 2;
					} else {
						we++;
					}
				} else if (arr[i][j] == -1) {
					we--;
				}
			} else {
				if (arr[i][j] == -1) {
					if (M + 1 == i || M - 1 == i || N + 1 == j || N - 1 == j) {
						we += 2;
					} else {
						we++;
					}
				} else if (arr[i][j] == 1) {
					we--;
				}
			}
		}
	}
	return we;
}


//检测棋子两端是否半封闭（由于在空棋盘处检测，故无绝对封闭）,isA决定是计算【我方】还是【敌方】，计算敌方先isA=1，后isA=0
int isFb(int M, int N, int min) {
	min++;
	reM = M, reN = N;
	if (min == M1(M, N)) {
		reM = M + min;
		reN = N;
	} else if (min == M0(M, N)) {
		reM = M - min;
		reN = N;
	} else if (min == N1(M, N)) {
		reM = M;
		reN = N + min;
	} else if (min == N0(M, N)) {
		reM = M;
		reN = N - min;
	} else if (min == M1N1(M, N)) {
		reM = M + min;
		reN = N + min;
	} else if (min == M0N0(M, N)) {
		reM = M - min;
		reN = N - min;
	} else if (min == M0N1(M, N)) {
		reM = M - min;
		reN = N + min;
	} else if (min == M1N0(M, N)) {
		reM = M + min;
		reN = N - min;
	} else {
		return 3;//周围不存在
	}

	if (reM >= 0 && reN >= 0) {
		return arr[reM][reN];
	} else {
		return 4;//超出检测范围
	}
}

//我方下棋函数
void setQ(int x, int y) {
	E = x, F = y; //记录我方上一次下的棋子坐标
	arr[E][F] = -1;
	Show(E, F);
	isA = 0;
	isOver(E, F, 5);
	isA = 1;
}

int main() {
	//初始化棋盘
	Show(M, N);
	//新手引导
	printf("繁寂の五子棋-单人版\n");
	printf("Time：2022/03/01 02:44\n");
	printf("使用【WASD】控制移动，【空格】确定\n");

	while (1) {
		ch = _getch();
		//判断动作先后
		if (isA) {


			//监听A的动作
			switch (ch) {
				case 119://上
					if (M > 0) {
						M--;
					}
					Show(M, N);
					break;
				case 115://下
					if (M < x - 1) {
						M++;
					}
					Show(M, N);
					break;
				case 97://左
					if (N > 0) {
						N--;
					}
					Show(M, N);
					break;
				case 100://右
					if (N < y - 1) {
						N++;
					}
					Show(M, N);
					break;
				case 32://空格
					arr[M][N] == 0 ? arr[M][N] = 1, Show(M, N), isOver(M, N, 5), isA = 0 : printf("不好意思，这里有棋子了！");
					break;
			}


		} else {
			//思路：首先分析我方，我方无绝胜时再去检测敌方，均无操作后按权重下棋

			for (int i = 0; i < x; i++) {
				for (int j = 0; j < y; j++) {
					//1.分析我方

					/**
					 * 1.1有无绝胜，即有 4个相连 或 间隔1个后满足4个
					 *	是否绝胜：	是								否
					 *	方案：		4个相连且无死封闭，我方下棋		继续 ↓
					 **/
					if (!isA) {
						//寻找我方间隔1获胜
						isA = 0;
						if (arr[i][j] == 0) { //寻找未下的棋盘位
							if (jg(i, j, 4)) {
								setQ(i, j);
								//printf("寻找到我方间隔1获胜\n");
								goto over;
							}
						}
					}

					if (!isA) {
						//寻找我方4个相连，且无死封闭
						if (arr[i][j] == 0) { //寻找未下的棋盘位
							//检测我方
							isA = 0;
							int re4 = isFb(i, j, 4);

							if (re4 == 0) {
								//4颗未封闭
								if (weight(i, j) > weight(reM, reN)) {
									setQ(i, j);
									//printf("ij寻找到我方4个相连未封闭");
									goto over;
								} else if (weight(i, j) == weight(reM, reN)) {
									if (time(NULL) % 2) {
										setQ(i, j);
										//printf("ij寻找到我方4个相连未封闭");
										goto over;
									} else {
										setQ(reM, reN);
										//printf("reMN寻找到我方4个相连未封闭");
										goto over;
									}
								} else {
									setQ(reM, reN);
									//printf("reMN寻找到我方4个相连未封闭");
									goto over;
								}
							} else if (re4 == -1 || re4 == 4) {//4为超出范围故也是封闭
								//4颗不完全封闭
								setQ(i, j);
								//printf("reMN寻找到我方4颗不完全封闭");
								goto over;
							}
						}
					}

					if (!isA) {
						if (arr[i][j] == 0) { //寻找未下的棋盘位
							isA = 0;
							if (jg(i, j, 4)) {
								setQ(i, j);
								//printf("我方间隔1获胜\n");
								goto over;
							}
						}
					}

					//2.检测敌方
					if (!isA) {
						/**
						 * 2.1有无间隔1个后满足5个
						 *	是否间隔：	是			否
						 *	方案：		去间隔		继续 ↓
						 **/
						if (arr[i][j] == 0) { //寻找未下的棋盘位
							isA = 1;//jg计算敌方
							if (jg(i, j, 4)) {
								setQ(i, j);
								//printf("拦截敌方间隔1获胜\n");
								goto over;
							}
							isA = 0;//恢复jg
						}
					}

					if (!isA) {
						/**
						 * 2.2敌方最后一次的棋子八方的个数，【大于等于】3颗棋子时，检测两侧是否封闭（只检测空棋盘所以间接检测了封闭）
						 *
						 *	是否封闭：	不完全				否							是
						 *	方案：		3颗退出，4颗封闭	选择（按照权重）封闭其一方	退出
						 **/
						if (arr[i][j] == 0) { //寻找未下的棋盘位

							isA = 1;//检测敌方
							int re3 = isFb(i, j, 3), re4 = isFb(i, j, 4);
							isA = 0;//检测结束

							if (re4 == 0) {
								//4颗未封闭
								if (weight(i, j) > weight(reM, reN)) {
									setQ(i, j);
									//printf("ij拦截敌方4颗相连未封闭\n");
									goto over;
								} else if (weight(i, j) == weight(reM, reN)) {
									if (time(NULL) % 2) {
										setQ(i, j);
										//printf("ij拦截敌方4颗相连未封闭\n");
										goto over;
									} else {
										setQ(reM, reN);
										//printf("reMN拦截敌方4颗相连未封闭\n");
										goto over;
									}
								} else {
									setQ(reM, reN);
									//printf("reMN拦截敌方4颗相连未封闭\n");
									goto over;
								}
							} else if (re4 == -1 || re4 == 4) {
								//4颗不完全封闭
								setQ(i, j);
								//printf("ij拦截敌方4颗不完全封闭\n");
								goto over;
							}


							/**
							 * 2.3有无间隔1个后满足4个
							 *	是否间隔：	是			否
							 *	方案：		去间隔		继续 ↓
							 **/
							if (arr[i][j] == 0) { //寻找未下的棋盘位
								isA = 1;//jg计算敌方
								if (jg(i, j, 3)) {
									setQ(i, j);
									//printf("拦截敌方间隔1满足4个\n");
									goto over;
								}
								isA = 0;//恢复jg
							}


							if (re3 == 0) {
								//3颗未封闭
								if (weight(i, j) > weight(reM, reN)) {
									setQ(i, j);
									//printf("ij拦截敌方3颗相连未封闭\n");
									goto over;
								} else if (weight(i, j) == weight(reM, reN)) {
									if (time(NULL) % 2) {
										setQ(i, j);
										//printf("ij拦截敌方3颗相连未封闭\n");
										goto over;
									} else {
										setQ(reM, reN);
										//printf("reMN拦截敌方3颗相连未封闭\n");
										goto over;
									}
								} else {
									setQ(reM, reN);
									//printf("reMN拦截敌方3颗相连未封闭\n");
									goto over;
								}
							}
						}
					}
					isA = 0;//保证下次循环可进入判断
				}
			}


			if (!isA) {
				/**
				 * 2.4 搜索所有空位，获取权重最大值的坐标，下棋
				 * 步骤：计算权重数组，获取最大权重序号，解析序号为坐标，下棋
				 **/
				int wei[x * y];
				//计算所有空位置的权重
				for (int m = 0; m < x; m++) {
					for (int n = 0; n < y; n++) {
						if (arr[m][n] == 0) { //寻找未下的棋盘位
							isA = 0;
							//计算未下棋子的我方权重
							wei[m * 10 + n] = weight(m, n);
						} else {
							wei[m * 10 + n] = -66;
						}
					}
				}

				int SN = 0;//记录最大权重的序号
				int max = wei[0];//交换的比较对象
				for (int k = 0; k < (x * y); k++) {
					if (wei[k] > max) {
						SN = k;
						max = wei[k];
					}
				}

				//解析序号为坐标
				int M = SN / 10, N = SN % 10;
				setQ(M, N);
				//printf("按照最大权重【序号: %d】【max = %d】下棋\n", max, SN);

//				for (int m = 0; m < x; m++) {
//					printf("	");
//					for (int n = 0; n < y; n++) {
//						if (arr[m][n] == 0) { //寻找未下的棋盘位
//							printf("%d	", wei[m * 10 + n]);
//						} else {
//							printf("*	");
//						}
//					}
//					printf("\n\n\n");
//				}

				goto over;
			}


over:
			isA = 1;//保证回合正确
		}
	}

	return 0;
}
