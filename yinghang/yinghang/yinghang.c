#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include<time.h>
#include<math.h>

int zhucaidan = 1;//���˵�
int cuowushu = 0;//�����˻����������
int xz;      //ѡ��
int yzm = 0;//��֤��
int quanjui;  //ȫ�ֵ�����Ԫ���±� i 
int zhaobudao;  //�Ҳ��ҵõ��û����ҵ����� 1 ���Ҳ������� 0 .
float shouxufei = 520 ;  //ת�������ѣ�ÿ��ת��Ҫ5.2Ԫ
char yh[100][32];  //�û�����
int mima[100];    //�û�����
float cunkuan[100];//�û����
int user;//�û���
char guashiyh[100][32];  //��ʧ�û�����
int guashimima[100];    //��ʧ�û�����
float guashicunkuan[100];//��ʧ�û����
int guashi;//��ʧ�û���
int weishu;//����λ��


void xinghao()//����Ǻ�
{
	for (int i = 0; i < 6; i++)
	{
		printf("*");
	}
	printf("\n");
}

void guanliyuanyonghu()//ѡ�����Ա�����û���¼
{
	printf("<1>����Ա��½\n");
	printf("<2>�û���½\n");
	printf("<3>�˳�����\n");
}

void guanliyuandenglu()//����Ա��½
{
	int n;
	n = 0;
	cuowushu = 0;
	while ((cuowushu < 3))//�����������������Ϊ3��
	{
		char i[4] = "xjw";//����Ա�˺�����
		char a[4];
		int j = 666;
		int b;
		xinghao();
		if (n> 0)
		{
			printf("�˺Ż��������������������\n");
		}
		printf("���������Ա�˺ź����룺\n");
		scanf("%s%d", &a, &b);
		if ((strcmp(i, a) == 0) && (j == b) == 1)
		{
			printf("���ڵ�¼�����Ժ�......\n");
			printf("�x�x�x�y�y�y�z�z�z�{�{�{�|�|�|�}�}�}�~�~�~��������\n");
			printf("��½�ɹ�\n");
			break;
		}
		else
		{
			n++;
			cuowushu++;
		}
	}
}

void yanzhengma()     //��֤��ϵͳ
{
	yzm = 0;
	int ret[6];
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 6; i++)
	{
		ret[i] = rand() % 10;
		yzm = yzm + ret[i] * pow(10, i);
	}
	printf("%d\n", yzm);
}

void guanliyuan()     //����Աҳ��
{
	printf("<1>�����û�\n");
	printf("<2>�����û�\n");
	printf("<3>ɾ���û�\n");
	printf("<4>��ʧ�û�\n");
	printf("<5>����û�\n");
	printf("<6>ת��������\n");
	printf("<7>�������˵�\n");
}

void suoyouyonghu()  //�����û�����
{
	int i;
	xinghao();
	for (i = 0; i < user; i++)
	{
		printf("�û�����%5s     �������룺%d      ��%.2fԪ\n", yh[i], mima[i], cunkuan[i]);
	}
}

void zengjiayonghu()//�����û�
{
	int i;
	int n = 1;
	int mimab;//��������λ����
	int j = 1;
	char input[32];
	int mima1, mima2;
	printf("�����û���: \n");
	while (j == 1)
	{
		n = 1;
		scanf("%s", &input);
		for (i = 0; i < user; i++)
		{
			while (strcmp(input, yh[i]) == 0)
			{
				printf("���û����Ѵ���\n");
				printf("���������룺\n");
				n++;
				break;
			}
		}
		if (n == 1)
		{
			strcpy(yh[user], input);
			while (1)
			{
				weishu = 0;
				printf("������6λ��������: ");
				scanf("%d", &mima1);


				mimab = mima1;      //��������λ��
				while (mimab != 0)
				{
					mimab = mimab / 10;
					weishu++;
				}
				// printf("%d\n", weishu);
				if (weishu != 6)
				{
					printf("�����ʽ����\n");
					continue;
				}


				printf("���ٴ�����ȷ������: ");
				scanf("%d", &mima2);
				if (mima1 == mima2)
				{
					printf("�������óɹ�\n");
					mima[user] = mima1;
					break;
				}
				else
				{
					printf("�������벻��ͬ,���������롣\n ");
				}
			}
			printf("������������");
			scanf("%f", &cunkuan[user]);
			printf("\n�����û��ɹ�\n");
			user++;
			j = 0;
			break;
		}
		else
		{
			continue;
		}

	}
}

void shanchuyonghu()    //ɾ���û�ϵͳ
{
	char shanchu[32];
	int i;
	int n = 0;
	int yzm2;//��֤��
	int cws2 = 0;//��֤�������
	suoyouyonghu();
	xinghao();
	printf("\n������Ҫɾ�����û���");
	scanf("%s", &shanchu);
	for (i = 0; i < user; i++)
	{
		if (strcmp(shanchu, yh[i]) == 0)   //������˻�
		{
			n = 1;
		}
	}
	if (n == 0)  //û������˻�
	{
		printf("�û�����������ѡ�񣡣���\n");
	}
	while ((n == 1) && (cws2 < 2) == 1)  //2����֤�����
	{
		printf("\n���������Ա�˺ŷ�����֤��\n");
		yanzhengma();
		printf("��������֤�룺");
		scanf("%d", &yzm2);
		if (yzm == yzm2)//��֤����ȷ
		{
			for (int n = i; n < user; n++)
			{
				strcpy(yh[n], yh[n + 1]);
				mima[n] = mima[n + 1];
				cunkuan[n] = cunkuan[n + 1];
			}
			printf("\nɾ�� %s �û��ɹ�\n", shanchu);
			user--;
			n = 0;
			break;
		}
		else    //��֤�����
		{
			printf("��֤�������������֤\n");
			cws2++;
		}
	}
}

void guashiyonghu()  //���й�ʧ�û�����
{
	int i;
	xinghao();
	for (i = 0; i < guashi; i++)
	{
		printf("��ʧ�û�����%5s     �������룺%d      ��%.2fԪ\n", guashiyh[i], guashimima[i], guashicunkuan[i]);
	}
}

void jiechuguashi()     //�����ʧϵͳ
{
	char jiechu[32];
	int i;
	int n = 0;
	int yzm2;//��֤��
	int cws2 = 0;//��֤�������
	guashiyonghu();
	xinghao();
	printf("\n������Ҫ�����ʧ���û���");
	scanf("%s", &jiechu);
	for (i = 0; i < guashi; i++)
	{
		if (strcmp(jiechu, guashiyh[i]) == 0)   //������˻�
		{
			n = 1;
			break;
		}
	}
	if (n == 0)  //û������˻�
	{
		printf("�û�����������ѡ�񣡣���\n");
	}
	while ((n == 1) && (cws2 < 2) == 1)  //2����֤�����
	{
		printf("\n���������Ա�˺ŷ�����֤��\n");
		yanzhengma();
		printf("��������֤�룺");
		scanf("%d", &yzm2);
		if (yzm == yzm2)//��֤����ȷ
		{
			strcpy(yh[user], guashiyh[i]);
			mima[user] = guashimima[i];
			cunkuan[user] = guashicunkuan[i];
			user++;
			for (int n = i; n < guashi; n++)
			{
				strcpy(guashiyh[n], guashiyh[n + 1]);
				guashimima[n] = guashimima[n + 1];
				guashicunkuan[n] = guashicunkuan[n + 1];
			}
			printf("�û� %s �����ʧ�ɹ�\n", jiechu);
			guashi--;
			n = 0;
			break;
		}
		else    //��֤�����
		{
			printf("��֤�������������֤\n");
			cws2++;
		}
	}
}

void yinghangqian()    //�鿴���е�ת������������
{
	printf("����Ŀǰ��ת��Ӫ��Ϊ %.2f Ԫ\n", shouxufei);
}

void yonghudenglu()   //�û���¼
{
	char yonghu[32];
	int yonghumima;
	int i;   //������Ԫ���±�
	int n = 0;   //������˻����ڣ��ͱ�n=1
	cuowushu= 0;  //����Ҫ��Ҫ����������������ʾ
	zhaobudao = 0;  //Ĭ���ҵ��û�
	int input;
	printf("�����������˺ţ� ");
	scanf("%s", &yonghu);
	for (i = 0; i < user; i++)
	{
		if (strcmp(yh[i], yonghu) == 0)   //������˻����ó� i ��ֵ
		{
			n = 1;
			break;
		}
	}
	if (n == 1)
	{
		while ((cuowushu < 3))   //������������������Ϊ3
		{
			if (cuowushu>0)
			{
				printf("�����������");
			}
			printf("�������������룺 ");
			scanf("%d", &input);
			if (input == mima[i])  //������ȷ
			{
				printf("���ڵ�½�����Ժ�......\n");
				printf("�x�x�x�y�y�y�z�z�z�{�{�{�|�|�|�}�}�}�~�~�~��������\n");
				printf("��½�ɹ�����ӭ�����𾴵� %s �û�\n", yh[i]);
				quanjui = i;      //��ȫ�������±�  ==  i ��
				break;
			}
			else   //�������
			{
				n++;
				cuowushu++;
			}
		}
	}
	else
	{
		zhaobudao = 1;
		printf("�Ҳ�������˻�����ȥ����Աҳ��鿴���\n");
	}
}

void yonghuyemian()     //�û�ҳ��
{
	printf("<1>�鿴���\n");
	printf("<2>���\n");
	printf("<3>ȡ��\n");
	printf("<4>ת��\n");
	printf("<5>��ʧ\n");
	printf("<6>�������˵�\n");
}

void chakanyuer()      //�鿴���
{
	printf("�û�����%s   ��%.2fԪ\n", yh[quanjui], cunkuan[quanjui]);
}

void cunqian()         //��Ǯ
{
	float cunqian = -1;
	while (cunqian < 0)
	{
		printf("�������Ǯ��� ");
		scanf("%f", &cunqian);
		if (cunqian >= 0)
		{
			cunkuan[quanjui] = cunkuan[quanjui] + cunqian;
			printf("���ɹ�������ǰ�����Ϊ %.2f Ԫ\n",cunkuan[quanjui]);
			break;
		}
		else
		{
			printf("���ݳ������������룡����\n");
		}
	}
}

void quqian()         //ȡǮ
{
	float quqian;
	int shurumima;
	int a = 1;   //ѭ��
	cuowushu = 0;
	while (a == 1)
	{
		printf("�������Ϊ %.2f Ԫ����������Ҫȡ�����Ŀ\n", cunkuan[quanjui]);
		scanf("%f", &quqian);
		if (quqian >= 0)     //��������
		{
			while (cuowushu < 3)
			{
				printf("���������� 6 λ�����룺 ");
				scanf("%d", &shurumima);
				if ((shurumima == mima[quanjui]) && (cunkuan[quanjui] >= quqian) == 1) //����������ȷ����ȡǮС�����
				{
					cunkuan[quanjui] = cunkuan[quanjui] - quqian;
					printf("ȡ��ɹ����뼰ʱȡ�������ֽ�\n");
					printf("�����ڵ����Ϊ %.2f Ԫ\n", cunkuan[quanjui]);
					a = 0;    //�����������ѭ��
					break;
				}
				else if ((shurumima == mima[quanjui]) && (cunkuan[quanjui] < quqian) == 1) //����������ȷ����ȡǮ�������
				{
					printf("�������㣬ȡ��ʧ�ܣ����������롣\n");
				}
				else           //�������
				{
					printf("��������������������룡����\n");
					cuowushu++;
				}
			}
			if (cuowushu == 3)
			{
				printf("�������������࣬��ȡ��ȡ�����\n");
				a = 0;
			}
		}
		else     //���븺��
		{
			printf("���ݳ������������롣\n");
		}
	}
}

void zhuanzhang()      //ת��
{
	char shuruzh[32];  //����ת���˻�����
	float zhuanqian = 0;  //ת�˵Ľ��
	int shurumima;//��������
	int a = 1;   //ѭ��
	cuowushu = 0;
	int i;  //  ��ת�˵��˻��±�
	int zhaodaole = 0;  //  1-�ҵ��ˣ�0-û�ҵ���Ĭ��û�ҵ���
	while (a == 1)
	{
		printf("��������Ҫת�˵��˻��� ");
		scanf("%s", &shuruzh);
		if (strcmp(yh[quanjui], shuruzh) == 0)   //�����˻����Լ����˻���ͬ
		{
			printf("�������Լ����Լ�ת����,������ѡ��\n");
			break;
		}
		else     //�����˻����Լ����˻�����ͬ
		{
			for (i = 0; i < user; i++)
			{
				if (strcmp(yh[i], shuruzh) == 0)    //�ҵ��ˣ�������ˣ��õ��±� i 
				{
					zhaodaole = 1;
					break;
				}
			}
			if (zhaodaole == 1)     //�ҵ��ˣ�������ˣ�׼��תǮ
			{
				printf("����֪�������ڸ��û� %s ת�ˣ����ұ�����ȡ5.2Ԫ�������ѡ�\n���ȷ�ϣ�������ת�˽� ", yh[i]);
				scanf("%f", &zhuanqian);
				if (zhuanqian >= 0)    //��������
				{
					while (cuowushu < 3)
					{
						printf("���������� 6 λ�����룺 ");
						scanf("%d", &shurumima);
						if ((shurumima == mima[quanjui]) && (cunkuan[quanjui] >= (zhuanqian + 5.2)) == 1)
							//����������ȷ����ȡǮС�����+������
						{
							cunkuan[quanjui] = (cunkuan[quanjui] - zhuanqian) - 2.5;
							shouxufei = shouxufei + 5.2;
							printf("ת�˳ɹ��������ڵ����Ϊ %.2f Ԫ\n", cunkuan[quanjui]);
							a = 0;
							break;
						}
						else if ((shurumima == mima[quanjui]) && (cunkuan[quanjui] < (zhuanqian + 5.2)) == 1)
							//����������ȷ����ȡǮ�������+������
						{
							printf("�������㣬ת��ʧ�ܣ�������ѡ��\n");
							a = 0;
							break;
						}
						else           //�������
						{
							printf("��������������������룡����\n");
							cuowushu++;
						}
					}
					if (cuowushu == 3)
					{
						printf("�������������࣬��ȡ��ת�˷���\n");
						a = 0;
					}
				}
				else     //���븺��
				{
					printf("���ݳ������������롣\n");
					a = 0;
					break;
				}
			}
			else                   //û�ҵ�����ˣ��ټ�
			{
				printf("�����˻��������ʵת���û���\n");
				break;
			}
		}
	}

}

void guashifuwu()      //��ʧ����
{
	int a = 1;   //ѭ��
	int shuruyzm; //������֤��
	cuowushu = 0;
	while (a == 1)
	{
		printf("�����ڽ��й�ʧ������ȷ���Ƿ�Ҫ����\n");
		printf("<1>������ʧ     <2>��ֹ��ʧ\n");
		scanf("%d", &xz);
		switch (xz)
		{
		default:
		{
			continue;
		}
		case 1:
		{
			while (cuowushu < 3)
			{
				yanzhengma();
				printf("��֤���ѷ��͵������˻�����������֤�룺 ");
				scanf("%d", &shuruyzm);
				if (yzm == shuruyzm)
				{
					strcpy(guashiyh[guashi], yh[quanjui]);
					guashimima[guashi] = mima[quanjui];
					guashicunkuan[guashi] = cunkuan[quanjui];
					guashi++;
					for (int n = quanjui; n < user; n++)
					{
						strcpy(yh[n], yh[n + 1]);
						mima[n] = mima[n + 1];
						cunkuan[n] = cunkuan[n + 1];
					}
					user--;
					printf("��ʧ�ɹ���\n");
					zhucaidan = 0;
					a = 0;
					break;
				}
				else
				{
					printf("��֤��������������롣\n");
					cuowushu++;
				}
				if (cuowushu == 3)
				{
					printf("��֤�����������࣬����ֹ��ʧ����\n");
					break;
				}
			}
			a = 0;
			break;
		}
		case 2:
		{
			printf("��ʧ��������ֹ�������ѡ��\n");
			a = 0;
			break;
		}

		}
	}
}

int main()
{
	int a;    //����Աѭ��
	int b;     //�û�ѭ��
	user = 2;//�û���
	strcpy(yh[0], "xxx");  //�����û���ʼֵ
	mima[0] = 123456;
	cunkuan[0] = 923499;
	strcpy(yh[1], "ss");
	mima[1] = 123455;
	cunkuan[1] = 123489;

	guashi = 2;
	strcpy(guashiyh[0], "a");  //���ù�ʧ��ʼֵ
	guashimima[0] = 123436;
	guashicunkuan[0] = 56789;
	strcpy(guashiyh[1], "b");
	guashimima[1] = 122455;
	guashicunkuan[1] = 489;


	while (1 == zhucaidan)
	{
		a = 1;  //����Աѭ��
		b = 1; //�û�ѭ��
		zhucaidan = 0;
		xinghao();
		guanliyuanyonghu();
		xinghao();
		scanf("%d", &xz);
		if (1 == xz)    //����Ա
		{
			xinghao();
			guanliyuandenglu();  //����Ա��½
			if (3 == cuowushu)//������������ȫ��
			{
				zhucaidan = 1;
				continue;
			}
			else     //���������� < 3 ���˺�������ȷ
			{

			}
			while (a == 1)
			{
				xinghao();
				guanliyuan();
				xinghao();
				scanf("%d", &xz);
				switch (xz)
				{
				default:
				{
					continue;
				}
				case 1:   //�����û�
				{
					suoyouyonghu();
					break;
				}
				case 2:   //�����û�
				{
					zengjiayonghu();
					break;
				}
				case 3:    //ɾ���û�
				{
					shanchuyonghu();
					break;
				}
				case 4:    //��ʧ�û�
				{
					guashiyonghu();
					break;
				}
				case 5:    //�����ʧ
				{
					jiechuguashi();
					break;
				}
				case 6:     //�鿴ת��������
				{
					yinghangqian();
					break;
				}
				case 7:     //�������˵�
				{
					zhucaidan = 1;
					a = 0;
					break;
				}
				}
			}
		}
		else if (2 == xz)      //�û�
		{
			xinghao();
			yonghudenglu();     //�û���¼
			if (3 == cuowushu)//������������ȫ��
			{
				zhucaidan = 1;
				continue;
			}
			else if(zhaobudao==1)     // ���������� < 3 ���û�������ȷ
			{
				zhucaidan = 1;
				continue;
			}
			else
			{

			}
			while (b == 1)
			{
				xinghao();
				yonghuyemian();
				xinghao();
				scanf("%d", &xz);
				switch (xz)
				{
				default:
				{
					continue;
				}
				case 1:   //�鿴���
				{
					chakanyuer();
					break;
				}
				case 2:   //��Ǯ
				{
					cunqian();
					break;
				}
				case 3:    //ȡǮ
				{
					quqian();
					break;
				}

				case 4:    //ת��
				{
					zhuanzhang();
					break;
				}
				case 5:      //��ʧ
				{
					guashifuwu();
					if (xz == 1)
					{
						b = zhucaidan;
						zhucaidan = 1;
						break;
					}
					else
					{

					}
					break;
				}
				case 6:     //�������˵�
				{
					zhucaidan = 1;
					b = 0;
					break;
				}
				}
			}
		}
		else if (3 == xz)
		{
			printf("�����˳�\n");
			break;
		}
		else
		{
			zhucaidan = 1;
			continue;
		}
	}
	return 0;
}