#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include<time.h>
#include<math.h>

int zhucaidan = 1;//主菜单
int cuowushu = 0;//输入账户密码错误数
int xz;      //选择
int yzm = 0;//验证码
int quanjui;  //全局的数组元素下标 i 
int zhaobudao;  //找不找得到用户，找到返回 1 ，找不到返回 0 .
float shouxufei = 520 ;  //转账手续费，每次转账要5.2元
char yh[100][32];  //用户名字
int mima[100];    //用户密码
float cunkuan[100];//用户存款
int user;//用户数
char guashiyh[100][32];  //挂失用户名字
int guashimima[100];    //挂失用户密码
float guashicunkuan[100];//挂失用户存款
int guashi;//挂失用户数
int weishu;//密码位数


void xinghao()//输出星号
{
	for (int i = 0; i < 6; i++)
	{
		printf("*");
	}
	printf("\n");
}

void guanliyuanyonghu()//选择管理员或者用户登录
{
	printf("<1>管理员登陆\n");
	printf("<2>用户登陆\n");
	printf("<3>退出程序\n");
}

void guanliyuandenglu()//管理员登陆
{
	int n;
	n = 0;
	cuowushu = 0;
	while ((cuowushu < 3))//最多输入错误密码次数为3次
	{
		char i[4] = "xjw";//管理员账号密码
		char a[4];
		int j = 666;
		int b;
		xinghao();
		if (n> 0)
		{
			printf("账号或者密码错误，请重新输入\n");
		}
		printf("请输入管理员账号和密码：\n");
		scanf("%s%d", &a, &b);
		if ((strcmp(i, a) == 0) && (j == b) == 1)
		{
			printf("正在登录，请稍候......\n");
			printf("▁▁▁▂▂▂▃▃▃▄▄▄▅▅▅▆▆▆▇▇▇████\n");
			printf("登陆成功\n");
			break;
		}
		else
		{
			n++;
			cuowushu++;
		}
	}
}

void yanzhengma()     //验证码系统
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

void guanliyuan()     //管理员页面
{
	printf("<1>所有用户\n");
	printf("<2>增加用户\n");
	printf("<3>删除用户\n");
	printf("<4>挂失用户\n");
	printf("<5>解除用户\n");
	printf("<6>转账手续费\n");
	printf("<7>返回主菜单\n");
}

void suoyouyonghu()  //所有用户排列
{
	int i;
	xinghao();
	for (i = 0; i < user; i++)
	{
		printf("用户名：%5s     付款密码：%d      存款：%.2f元\n", yh[i], mima[i], cunkuan[i]);
	}
}

void zengjiayonghu()//增加用户
{
	int i;
	int n = 1;
	int mimab;//计算密码位数的
	int j = 1;
	char input[32];
	int mima1, mima2;
	printf("输入用户名: \n");
	while (j == 1)
	{
		n = 1;
		scanf("%s", &input);
		for (i = 0; i < user; i++)
		{
			while (strcmp(input, yh[i]) == 0)
			{
				printf("该用户名已存在\n");
				printf("请重新输入：\n");
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
				printf("请输入6位数字密码: ");
				scanf("%d", &mima1);


				mimab = mima1;      //计算密码位数
				while (mimab != 0)
				{
					mimab = mimab / 10;
					weishu++;
				}
				// printf("%d\n", weishu);
				if (weishu != 6)
				{
					printf("密码格式错误\n");
					continue;
				}


				printf("请再次输入确认密码: ");
				scanf("%d", &mima2);
				if (mima1 == mima2)
				{
					printf("密码设置成功\n");
					mima[user] = mima1;
					break;
				}
				else
				{
					printf("两次输入不相同,请重新输入。\n ");
				}
			}
			printf("请输入存款数：");
			scanf("%f", &cunkuan[user]);
			printf("\n增加用户成功\n");
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

void shanchuyonghu()    //删除用户系统
{
	char shanchu[32];
	int i;
	int n = 0;
	int yzm2;//验证码
	int cws2 = 0;//验证码错误数
	suoyouyonghu();
	xinghao();
	printf("\n请输入要删除的用户：");
	scanf("%s", &shanchu);
	for (i = 0; i < user; i++)
	{
		if (strcmp(shanchu, yh[i]) == 0)   //有这个账户
		{
			n = 1;
		}
	}
	if (n == 0)  //没有这个账户
	{
		printf("用户错误，请重新选择！！！\n");
	}
	while ((n == 1) && (cws2 < 2) == 1)  //2次验证码机会
	{
		printf("\n正在向管理员账号发送验证码\n");
		yanzhengma();
		printf("请输入验证码：");
		scanf("%d", &yzm2);
		if (yzm == yzm2)//验证码正确
		{
			for (int n = i; n < user; n++)
			{
				strcpy(yh[n], yh[n + 1]);
				mima[n] = mima[n + 1];
				cunkuan[n] = cunkuan[n + 1];
			}
			printf("\n删除 %s 用户成功\n", shanchu);
			user--;
			n = 0;
			break;
		}
		else    //验证码错误
		{
			printf("验证码错误，请重新验证\n");
			cws2++;
		}
	}
}

void guashiyonghu()  //所有挂失用户排列
{
	int i;
	xinghao();
	for (i = 0; i < guashi; i++)
	{
		printf("挂失用户名：%5s     付款密码：%d      存款：%.2f元\n", guashiyh[i], guashimima[i], guashicunkuan[i]);
	}
}

void jiechuguashi()     //解除挂失系统
{
	char jiechu[32];
	int i;
	int n = 0;
	int yzm2;//验证码
	int cws2 = 0;//验证码错误数
	guashiyonghu();
	xinghao();
	printf("\n请输入要解除挂失的用户：");
	scanf("%s", &jiechu);
	for (i = 0; i < guashi; i++)
	{
		if (strcmp(jiechu, guashiyh[i]) == 0)   //有这个账户
		{
			n = 1;
			break;
		}
	}
	if (n == 0)  //没有这个账户
	{
		printf("用户错误，请重新选择！！！\n");
	}
	while ((n == 1) && (cws2 < 2) == 1)  //2次验证码机会
	{
		printf("\n正在向管理员账号发送验证码\n");
		yanzhengma();
		printf("请输入验证码：");
		scanf("%d", &yzm2);
		if (yzm == yzm2)//验证码正确
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
			printf("用户 %s 解除挂失成功\n", jiechu);
			guashi--;
			n = 0;
			break;
		}
		else    //验证码错误
		{
			printf("验证码错误，请重新验证\n");
			cws2++;
		}
	}
}

void yinghangqian()    //查看银行的转账手续费所得
{
	printf("银行目前的转账营收为 %.2f 元\n", shouxufei);
}

void yonghudenglu()   //用户登录
{
	char yonghu[32];
	int yonghumima;
	int i;   //找数组元素下标
	int n = 0;   //如果有账户存在，就变n=1
	cuowushu= 0;  //决定要不要输出密码输入错误提示
	zhaobudao = 0;  //默认找到用户
	int input;
	printf("请输入您的账号： ");
	scanf("%s", &yonghu);
	for (i = 0; i < user; i++)
	{
		if (strcmp(yh[i], yonghu) == 0)   //有这个账户，得出 i 的值
		{
			n = 1;
			break;
		}
	}
	if (n == 1)
	{
		while ((cuowushu < 3))   //输入密码允许错误次数为3
		{
			if (cuowushu>0)
			{
				printf("密码输入错误，");
			}
			printf("请输入您的密码： ");
			scanf("%d", &input);
			if (input == mima[i])  //密码正确
			{
				printf("正在登陆，请稍候......\n");
				printf("▁▁▁▂▂▂▃▃▃▄▄▄▅▅▅▆▆▆▇▇▇████\n");
				printf("登陆成功，欢迎您，尊敬的 %s 用户\n", yh[i]);
				quanjui = i;      //令全局数组下标  ==  i ；
				break;
			}
			else   //密码错误
			{
				n++;
				cuowushu++;
			}
		}
	}
	else
	{
		zhaobudao = 1;
		printf("找不到这个账户，请去管理员页面查看清楚\n");
	}
}

void yonghuyemian()     //用户页面
{
	printf("<1>查看余额\n");
	printf("<2>存款\n");
	printf("<3>取款\n");
	printf("<4>转账\n");
	printf("<5>挂失\n");
	printf("<6>返回主菜单\n");
}

void chakanyuer()      //查看余额
{
	printf("用户名：%s   存款：%.2f元\n", yh[quanjui], cunkuan[quanjui]);
}

void cunqian()         //存钱
{
	float cunqian = -1;
	while (cunqian < 0)
	{
		printf("请输入存钱数额： ");
		scanf("%f", &cunqian);
		if (cunqian >= 0)
		{
			cunkuan[quanjui] = cunkuan[quanjui] + cunqian;
			printf("存款成功，您当前的余额为 %.2f 元\n",cunkuan[quanjui]);
			break;
		}
		else
		{
			printf("数据出错，请重新输入！！！\n");
		}
	}
}

void quqian()         //取钱
{
	float quqian;
	int shurumima;
	int a = 1;   //循环
	cuowushu = 0;
	while (a == 1)
	{
		printf("您的余额为 %.2f 元，请输入需要取款的数目\n", cunkuan[quanjui]);
		scanf("%f", &quqian);
		if (quqian >= 0)     //输入正数
		{
			while (cuowushu < 3)
			{
				printf("请输入您的 6 位数密码： ");
				scanf("%d", &shurumima);
				if ((shurumima == mima[quanjui]) && (cunkuan[quanjui] >= quqian) == 1) //输入密码正确并且取钱小于余额
				{
					cunkuan[quanjui] = cunkuan[quanjui] - quqian;
					printf("取款成功，请及时取走您的现金。\n");
					printf("您现在的余额为 %.2f 元\n", cunkuan[quanjui]);
					a = 0;    //结束最外面的循环
					break;
				}
				else if ((shurumima == mima[quanjui]) && (cunkuan[quanjui] < quqian) == 1) //输入密码正确但是取钱大于余额
				{
					printf("您的余额不足，取款失败，请重新输入。\n");
				}
				else           //密码错误
				{
					printf("密码输入错误，请重新输入！！！\n");
					cuowushu++;
				}
			}
			if (cuowushu == 3)
			{
				printf("密码错误次数过多，已取消取款服务。\n");
				a = 0;
			}
		}
		else     //输入负数
		{
			printf("数据出错，请重新输入。\n");
		}
	}
}

void zhuanzhang()      //转账
{
	char shuruzh[32];  //输入转账账户名字
	float zhuanqian = 0;  //转账的金额
	int shurumima;//输入密码
	int a = 1;   //循环
	cuowushu = 0;
	int i;  //  被转账的账户下标
	int zhaodaole = 0;  //  1-找到了，0-没找到，默认没找到。
	while (a == 1)
	{
		printf("请输入需要转账的账户： ");
		scanf("%s", &shuruzh);
		if (strcmp(yh[quanjui], shuruzh) == 0)   //输入账户与自己的账户相同
		{
			printf("不可以自己给自己转账噢,请重新选择。\n");
			break;
		}
		else     //输入账户与自己的账户不相同
		{
			for (i = 0; i < user; i++)
			{
				if (strcmp(yh[i], shuruzh) == 0)    //找到了，有这个人，得到下标 i 
				{
					zhaodaole = 1;
					break;
				}
			}
			if (zhaodaole == 1)     //找到了，有这个人，准备转钱
			{
				printf("请须知：您正在给用户 %s 转账，并且本行收取5.2元的手续费。\n如果确认，请输入转账金额： ", yh[i]);
				scanf("%f", &zhuanqian);
				if (zhuanqian >= 0)    //输入正数
				{
					while (cuowushu < 3)
					{
						printf("请输入您的 6 位数密码： ");
						scanf("%d", &shurumima);
						if ((shurumima == mima[quanjui]) && (cunkuan[quanjui] >= (zhuanqian + 5.2)) == 1)
							//输入密码正确并且取钱小于余额+手续费
						{
							cunkuan[quanjui] = (cunkuan[quanjui] - zhuanqian) - 2.5;
							shouxufei = shouxufei + 5.2;
							printf("转账成功，您现在的余额为 %.2f 元\n", cunkuan[quanjui]);
							a = 0;
							break;
						}
						else if ((shurumima == mima[quanjui]) && (cunkuan[quanjui] < (zhuanqian + 5.2)) == 1)
							//输入密码正确但是取钱大于余额+手续费
						{
							printf("您的余额不足，转账失败，请重新选择。\n");
							a = 0;
							break;
						}
						else           //密码错误
						{
							printf("密码输入错误，请重新输入！！！\n");
							cuowushu++;
						}
					}
					if (cuowushu == 3)
					{
						printf("密码错误次数过多，已取消转账服务。\n");
						a = 0;
					}
				}
				else     //输入负数
				{
					printf("数据出错，请重新输入。\n");
					a = 0;
					break;
				}
			}
			else                   //没找到这个人，再见
			{
				printf("输入账户错误，请核实转账用户。\n");
				break;
			}
		}
	}

}

void guashifuwu()      //挂失服务
{
	int a = 1;   //循环
	int shuruyzm; //输入验证码
	cuowushu = 0;
	while (a == 1)
	{
		printf("您正在进行挂失处理，请确认是否要继续\n");
		printf("<1>继续挂失     <2>中止挂失\n");
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
				printf("验证码已发送到您的账户，请输入验证码： ");
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
					printf("挂失成功。\n");
					zhucaidan = 0;
					a = 0;
					break;
				}
				else
				{
					printf("验证码错误，请重新输入。\n");
					cuowushu++;
				}
				if (cuowushu == 3)
				{
					printf("验证码错误次数过多，已中止挂失服务。\n");
					break;
				}
			}
			a = 0;
			break;
		}
		case 2:
		{
			printf("挂失服务已终止，请谨慎选择。\n");
			a = 0;
			break;
		}

		}
	}
}

int main()
{
	int a;    //管理员循环
	int b;     //用户循环
	user = 2;//用户数
	strcpy(yh[0], "xxx");  //设置用户起始值
	mima[0] = 123456;
	cunkuan[0] = 923499;
	strcpy(yh[1], "ss");
	mima[1] = 123455;
	cunkuan[1] = 123489;

	guashi = 2;
	strcpy(guashiyh[0], "a");  //设置挂失起始值
	guashimima[0] = 123436;
	guashicunkuan[0] = 56789;
	strcpy(guashiyh[1], "b");
	guashimima[1] = 122455;
	guashicunkuan[1] = 489;


	while (1 == zhucaidan)
	{
		a = 1;  //管理员循环
		b = 1; //用户循环
		zhucaidan = 0;
		xinghao();
		guanliyuanyonghu();
		xinghao();
		scanf("%d", &xz);
		if (1 == xz)    //管理员
		{
			xinghao();
			guanliyuandenglu();  //管理员登陆
			if (3 == cuowushu)//三次密码输入全错
			{
				zhucaidan = 1;
				continue;
			}
			else     //错误密码数 < 3 ，账号密码正确
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
				case 1:   //所有用户
				{
					suoyouyonghu();
					break;
				}
				case 2:   //增加用户
				{
					zengjiayonghu();
					break;
				}
				case 3:    //删除用户
				{
					shanchuyonghu();
					break;
				}
				case 4:    //挂失用户
				{
					guashiyonghu();
					break;
				}
				case 5:    //解除挂失
				{
					jiechuguashi();
					break;
				}
				case 6:     //查看转账手续费
				{
					yinghangqian();
					break;
				}
				case 7:     //返回主菜单
				{
					zhucaidan = 1;
					a = 0;
					break;
				}
				}
			}
		}
		else if (2 == xz)      //用户
		{
			xinghao();
			yonghudenglu();     //用户登录
			if (3 == cuowushu)//三次密码输入全错
			{
				zhucaidan = 1;
				continue;
			}
			else if(zhaobudao==1)     // 错误密码数 < 3 ，用户密码正确
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
				case 1:   //查看余额
				{
					chakanyuer();
					break;
				}
				case 2:   //存钱
				{
					cunqian();
					break;
				}
				case 3:    //取钱
				{
					quqian();
					break;
				}

				case 4:    //转账
				{
					zhuanzhang();
					break;
				}
				case 5:      //挂失
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
				case 6:     //返回主菜单
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
			printf("程序退出\n");
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