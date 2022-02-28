#include<stdio.h>
#include<conio.h>//_getch()
#include<stdlib.h>//rand()
#include<time.h>//time()������ż�򵥾��� 
#include<windows.h>//system("color 0A")

/**
 * @author:fanji
 * @qq:2967557176
 * @time:2022/03/01 02:44
 **/

//_getch()��ȡ�ļ�����
int ch;
//Ĭ��A������
static int isA = 1;
//��ʼ��10*10������
static int arr[10][10];
//char **arr[10][10];
/*��C���Ե��У��ַ����������ʹ�ã� char a[] [10]; ���� char *a[]; ��ʾ
��һ�ֱ�ʾ��ʽ�̶���ÿ���ַ���������С���ڶ���û���ַ����Ĵ�С���ơ�*/

int x = sizeof(arr) / sizeof(arr[0]), y = sizeof(arr[0]) / sizeof(arr[0][0]);
/*sizeof(arr[0][0])Ϊһ��Ԫ��ռ�õĿռ�
sizeof(arr[0])Ϊһ��Ԫ��ռ�õĿռ�
sizeof(arr)Ϊ��������ռ�õĿռ�*/

static int M = 0, N = 0;//A������
static int E = 0, F = 0;//B�����꣬������ai

static int reM = 0, reN = 0;//������isFb���Ķ˵�����
/*ʹ��static��ֹ��ʧ*/

//չʾ�����ϵ�����
void Show(int M, int N) {
	system("cls");//����
	for (int j = 0; j < x; j++) {
		printf("	");
		for (int k = 0; k < y; k++) {
			if (j == M && k == N) {
				if (isA) {
					printf("��	");
				} else {
					printf("��	");
				}
			} else {
				switch (arr[j][k]) {
					case 0:
						printf("+	");
						break;
					case 1:
						printf("��	");
						break;
					default:
						printf("��	");
						break;
				}
			}
		}
		printf("\n\n\n");
	}
}

int M1(int M, int N) {
	//M+ ��
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
	//N+ ��
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
	//M+N+ ����
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
	//M- ��
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
	//N- ��
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
	//M-N- ����
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
	//M-N+ ����
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
	//M+N- ����
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

//�����ж�
void isOver(int M, int N, int max) {

	if ((M1(M, N) + M0(M, N)) > max || (N1(M, N) + N0(M, N)) > max || (M1N1(M, N) + M0N0(M, N)) > max || (M0N1(M, N) + M1N0(M, N)) > max) {

		if (isA) {
			printf("�㾹ȻӮ�ˣ�");
			exit(0);
		} else {
			printf("����������Ӯ�ˣ�");
			exit(0);
		}

	}

}

//���1������num��,isA�����Ǽ��㡾�ҷ������ǡ��з���������з���isA=1����isA=0
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

//����M,N���Ȩ�� ��Ȧ+2����Ȧ+1 �з�-1
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


//������������Ƿ���գ������ڿ����̴���⣬���޾��Է�գ�,isA�����Ǽ��㡾�ҷ������ǡ��з���������з���isA=1����isA=0
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
		return 3;//��Χ������
	}

	if (reM >= 0 && reN >= 0) {
		return arr[reM][reN];
	} else {
		return 4;//������ⷶΧ
	}
}

//�ҷ����庯��
void setQ(int x, int y) {
	E = x, F = y; //��¼�ҷ���һ���µ���������
	arr[E][F] = -1;
	Show(E, F);
	isA = 0;
	isOver(E, F, 5);
	isA = 1;
}

int main() {
	//��ʼ������
	Show(M, N);
	//��������
	printf("���Ť�������-���˰�\n");
	printf("Time��2022/03/01 02:44\n");
	printf("ʹ�á�WASD�������ƶ������ո�ȷ��\n");

	while (1) {
		ch = _getch();
		//�ж϶����Ⱥ�
		if (isA) {


			//����A�Ķ���
			switch (ch) {
				case 119://��
					if (M > 0) {
						M--;
					}
					Show(M, N);
					break;
				case 115://��
					if (M < x - 1) {
						M++;
					}
					Show(M, N);
					break;
				case 97://��
					if (N > 0) {
						N--;
					}
					Show(M, N);
					break;
				case 100://��
					if (N < y - 1) {
						N++;
					}
					Show(M, N);
					break;
				case 32://�ո�
					arr[M][N] == 0 ? arr[M][N] = 1, Show(M, N), isOver(M, N, 5), isA = 0 : printf("������˼�������������ˣ�");
					break;
			}


		} else {
			//˼·�����ȷ����ҷ����ҷ��޾�ʤʱ��ȥ���з������޲�����Ȩ������

			for (int i = 0; i < x; i++) {
				for (int j = 0; j < y; j++) {
					//1.�����ҷ�

					/**
					 * 1.1���޾�ʤ������ 4������ �� ���1��������4��
					 *	�Ƿ��ʤ��	��								��
					 *	������		4��������������գ��ҷ�����		���� ��
					 **/
					if (!isA) {
						//Ѱ���ҷ����1��ʤ
						isA = 0;
						if (arr[i][j] == 0) { //Ѱ��δ�µ�����λ
							if (jg(i, j, 4)) {
								setQ(i, j);
								//printf("Ѱ�ҵ��ҷ����1��ʤ\n");
								goto over;
							}
						}
					}

					if (!isA) {
						//Ѱ���ҷ�4�����������������
						if (arr[i][j] == 0) { //Ѱ��δ�µ�����λ
							//����ҷ�
							isA = 0;
							int re4 = isFb(i, j, 4);

							if (re4 == 0) {
								//4��δ���
								if (weight(i, j) > weight(reM, reN)) {
									setQ(i, j);
									//printf("ijѰ�ҵ��ҷ�4������δ���");
									goto over;
								} else if (weight(i, j) == weight(reM, reN)) {
									if (time(NULL) % 2) {
										setQ(i, j);
										//printf("ijѰ�ҵ��ҷ�4������δ���");
										goto over;
									} else {
										setQ(reM, reN);
										//printf("reMNѰ�ҵ��ҷ�4������δ���");
										goto over;
									}
								} else {
									setQ(reM, reN);
									//printf("reMNѰ�ҵ��ҷ�4������δ���");
									goto over;
								}
							} else if (re4 == -1 || re4 == 4) {//4Ϊ������Χ��Ҳ�Ƿ��
								//4�Ų���ȫ���
								setQ(i, j);
								//printf("reMNѰ�ҵ��ҷ�4�Ų���ȫ���");
								goto over;
							}
						}
					}

					if (!isA) {
						if (arr[i][j] == 0) { //Ѱ��δ�µ�����λ
							isA = 0;
							if (jg(i, j, 4)) {
								setQ(i, j);
								//printf("�ҷ����1��ʤ\n");
								goto over;
							}
						}
					}

					//2.���з�
					if (!isA) {
						/**
						 * 2.1���޼��1��������5��
						 *	�Ƿ�����	��			��
						 *	������		ȥ���		���� ��
						 **/
						if (arr[i][j] == 0) { //Ѱ��δ�µ�����λ
							isA = 1;//jg����з�
							if (jg(i, j, 4)) {
								setQ(i, j);
								//printf("���صз����1��ʤ\n");
								goto over;
							}
							isA = 0;//�ָ�jg
						}
					}

					if (!isA) {
						/**
						 * 2.2�з����һ�ε����Ӱ˷��ĸ����������ڵ��ڡ�3������ʱ����������Ƿ��գ�ֻ�����������Լ�Ӽ���˷�գ�
						 *
						 *	�Ƿ��գ�	����ȫ				��							��
						 *	������		3���˳���4�ŷ��	ѡ�񣨰���Ȩ�أ������һ��	�˳�
						 **/
						if (arr[i][j] == 0) { //Ѱ��δ�µ�����λ

							isA = 1;//���з�
							int re3 = isFb(i, j, 3), re4 = isFb(i, j, 4);
							isA = 0;//������

							if (re4 == 0) {
								//4��δ���
								if (weight(i, j) > weight(reM, reN)) {
									setQ(i, j);
									//printf("ij���صз�4������δ���\n");
									goto over;
								} else if (weight(i, j) == weight(reM, reN)) {
									if (time(NULL) % 2) {
										setQ(i, j);
										//printf("ij���صз�4������δ���\n");
										goto over;
									} else {
										setQ(reM, reN);
										//printf("reMN���صз�4������δ���\n");
										goto over;
									}
								} else {
									setQ(reM, reN);
									//printf("reMN���صз�4������δ���\n");
									goto over;
								}
							} else if (re4 == -1 || re4 == 4) {
								//4�Ų���ȫ���
								setQ(i, j);
								//printf("ij���صз�4�Ų���ȫ���\n");
								goto over;
							}


							/**
							 * 2.3���޼��1��������4��
							 *	�Ƿ�����	��			��
							 *	������		ȥ���		���� ��
							 **/
							if (arr[i][j] == 0) { //Ѱ��δ�µ�����λ
								isA = 1;//jg����з�
								if (jg(i, j, 3)) {
									setQ(i, j);
									//printf("���صз����1����4��\n");
									goto over;
								}
								isA = 0;//�ָ�jg
							}


							if (re3 == 0) {
								//3��δ���
								if (weight(i, j) > weight(reM, reN)) {
									setQ(i, j);
									//printf("ij���صз�3������δ���\n");
									goto over;
								} else if (weight(i, j) == weight(reM, reN)) {
									if (time(NULL) % 2) {
										setQ(i, j);
										//printf("ij���صз�3������δ���\n");
										goto over;
									} else {
										setQ(reM, reN);
										//printf("reMN���صз�3������δ���\n");
										goto over;
									}
								} else {
									setQ(reM, reN);
									//printf("reMN���صз�3������δ���\n");
									goto over;
								}
							}
						}
					}
					isA = 0;//��֤�´�ѭ���ɽ����ж�
				}
			}


			if (!isA) {
				/**
				 * 2.4 �������п�λ����ȡȨ�����ֵ�����꣬����
				 * ���裺����Ȩ�����飬��ȡ���Ȩ����ţ��������Ϊ���꣬����
				 **/
				int wei[x * y];
				//�������п�λ�õ�Ȩ��
				for (int m = 0; m < x; m++) {
					for (int n = 0; n < y; n++) {
						if (arr[m][n] == 0) { //Ѱ��δ�µ�����λ
							isA = 0;
							//����δ�����ӵ��ҷ�Ȩ��
							wei[m * 10 + n] = weight(m, n);
						} else {
							wei[m * 10 + n] = -66;
						}
					}
				}

				int SN = 0;//��¼���Ȩ�ص����
				int max = wei[0];//�����ıȽ϶���
				for (int k = 0; k < (x * y); k++) {
					if (wei[k] > max) {
						SN = k;
						max = wei[k];
					}
				}

				//�������Ϊ����
				int M = SN / 10, N = SN % 10;
				setQ(M, N);
				//printf("�������Ȩ�ء����: %d����max = %d������\n", max, SN);

//				for (int m = 0; m < x; m++) {
//					printf("	");
//					for (int n = 0; n < y; n++) {
//						if (arr[m][n] == 0) { //Ѱ��δ�µ�����λ
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
			isA = 1;//��֤�غ���ȷ
		}
	}

	return 0;
}
