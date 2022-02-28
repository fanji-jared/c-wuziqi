#include<stdio.h>
#include<conio.h>//_getch()
#include<stdlib.h>//rand()

/**
 * @author:fanji
 * @qq:2967557176
 * @time:2021/11/6 3:53
 **/

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

static int M = 0, N = 0;
static int E = 0, F = 0;
/*ʹ��static��ֹ��ʧ*/

//չʾ�����ϵ�����
int Show(int M, int N) {
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

//�����ж�
int isOver(int M, int N, int max) {

	if ((M1(M, N) + M0(M, N)) > max || (N1(M, N) + N0(M, N)) > max || (M1N1(M, N) + M0N0(M, N)) > max || (M0N1(M, N) + M1N0(M, N)) > max) {
		if (isA) {
			printf("A���ʤ����");
			exit(0);
		} else {
			printf("B���ʤ����");
			exit(0);
		}
	}

	return 0;
}


int main() {
	//��ʼ������
	Show(M, N);
	//��������
	printf("���Ť������壨˫�˰棩\n");
	printf("Time��2021/11/6 3:53\n");
	printf("A����á�WASD�������ƶ������ո�ȷ��\n");
	printf("B����á����������������ƶ�����Enter��ȷ��");

	while (1) {
		ch = _getch();
		//�ж϶����Ⱥ�
		if (isA) {


			//����A�Ķ���
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
					arr[M][N] == 0 ? arr[M][N] = 1, Show(M, N), isOver(M, N, 5), isA = 0 : printf("��ߵ�A�����������������ˣ�");
					break;
			}


		} else {


			//����B�Ķ���
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
					arr[E][F] == 0 ?  arr[E][F] = -1, Show(E, F), isOver(E, F, 5), isA = 1 : printf("�ұߵ�B�����������������ˣ�");
					break;
			}


		}
	}

	return 0;
}
