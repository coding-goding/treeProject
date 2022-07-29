#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

#define VER "alpha 1.0"

void intro();
void story();
void story2();
void story3(int num);
void gotoxy(int x, int y);
int start_select(int money, int cleared);
int working(int money, int lvA, int lvB, int lvC, int lvD, int lvE, int ef);
int shopping(int money, int lvA, int lvB, int lvC, int lvD, int lvE, int ef, int fer, int water, int max_water, int drug, int num);
int tree(int xp, int max_xp, int level, int fer, int water, int max_water, int drug, int num);
void treeName(int lv);
void ending();
void ending2();
void ending3(int num);

int main() {
	int work_wood_Lv = 1;
	int work_doll_Lv = 0;
	int work_tool_Lv = 0;
	int work_furn_Lv = 0;
	int work_house_Lv = 0;
	int work_efficiency = 0;

	int money = 0;

	int fertilizer = 0;
	int water = 0;
	int max_water = 100;
	int drug = 0;

	int xp = 0;
	int max_xp = 100;
	int level = 0;

	int cleared = 0;

	intro();
	story();
	while (1) {
		int a = start_select(money, cleared);
		if (a == 1) {
			int num = 1;
			while (1) {
				
				int o = tree(xp, max_xp, level, fertilizer, water, max_water, drug, num);
				if (o == 1) {
					water--;
					if (drug == 1) {
						xp += 2;
					}
					else {
						xp++;
					}
					
					
				}
				else if (o == 2) {

					fertilizer--;
					if (drug == 1) {
						xp += 140;
					}
					else {
						xp += 70;
					}
				}
				else if (o == 3) {
					break;
				}
				else if (o == 10) {
					fertilizer -= 10;
					if (drug == 1) {
						xp += 1400;
					}
					else {
						xp += 700;
					}
				}
				else if (o == 11) {
					fertilizer -= 100;
					if (drug == 1) {
						xp += 14000;
					}
					else {
						xp += 7000;
					}
				}
				else if (o == 777) {
					cleared = 1;
					level++;
					break;
				}
				while (xp >= max_xp) {
					level++;
					xp = xp - max_xp;
					max_xp += level * 50;
				}
				num = o;
				if (num == 10) {
					num = 2;
				}
				else if (num == 11) {
					num = 2;
				}

			}
			
		}
		else if (a == 2) {//��
			money = working(money, work_wood_Lv, work_doll_Lv, work_tool_Lv, work_furn_Lv, work_house_Lv, work_efficiency);
		}
		else if (a == 3) {//����
			int num = 1;
			while (1) {
				int o = shopping(money, work_wood_Lv, work_doll_Lv, work_tool_Lv, work_furn_Lv, work_house_Lv, work_efficiency, fertilizer, water, max_water, drug, num);
				if (o == 1) {
					money -= 10 + work_wood_Lv * 3;
					work_wood_Lv++;
				}
				else if (o == 2) {
					money -= 50 + work_doll_Lv * 9;
					work_doll_Lv++;
				}
				else if (o == 3) {
					money -= 100 + work_tool_Lv * 23;
					work_tool_Lv++;
				}
				else if (o == 4) {
					money -= 250 + work_furn_Lv * 41;
					work_furn_Lv++;
				}
				else if (o == 5) {
					money -= 500 + work_house_Lv * 102;
					work_house_Lv++;
				}
				else if (o == 6) {
					money -= 1000 + work_efficiency * 2500;
					work_efficiency++;
				}
				else if (o == 7) {
					money -= 50;
					fertilizer++;
				}
				else if (o == 8) {
					water = max_water;
				}
				else if (o == 9) {
					money -= 10 + max_water * 2;
					max_water += 10;
				}
				else if (o == 10) {
					money -= 5000;
					drug = 1;
				}
				else if (o == 11) {
					break;
				}
				else if (o == 20) {
					int f = money / 50;
					money = money % 50;
					fertilizer += f;
				}
				num = o;
				if (num == 20) {
					num = 7;
				}
			}
		}
		else if (a == 4) {
			system("cls");
			printf("���� �����Ͻðڽ��ϱ�?\n�� ������ ����� �ҷ����⸦ �������� �ʽ��ϴ�.\n\n");
			printf("y�� �����ּ���>");
			char q = _getch();
			if (q == 'y') {
				break;
			}
			
		}
	}



}

void intro() { //��Ʈ��
	printf("����Ű��� ver.%s\n", VER);
	printf("����Ű : ����/a : ����\n");
	printf("�ƹ� Ű�� ���� ����");
	char y = _getch();
	system("cls");
}

void story() {
	char y;
	int s = 1;
	int error = 0;
	char select = NULL;
	while (1) {
		system("cls");
		printf("���丮�� ���ðڽ��ϱ�?\n��\n�ƴϿ�");
		if (error == 1) { //Caps Lock Ȱ��ȭ
			gotoxy(0, 6);
			printf("Caps Lock�� Ǯ���ּ���.");
			error = 0;
		}
		else if (error == 2) { //��/��Ű ��ȯ
			gotoxy(0, 6);
			printf("��/��Ű�� �ٲ��ּ���.");
			error = 0;
		}
		if (s == 1) {
			gotoxy(3, 1);
		}
		else if (s == 2) {
			gotoxy(7, 2);
		}
		printf("<");

		while (1) {
			if (_kbhit()) {
				select = _getch();
				if (select == -32) {
					select = _getch();
					switch (select) {
					case 72:
						if (s != 1) {
							s--;
							break;
						}
					case 80:
						if (s != 2) {
							s++;
							break;
						}
					}
					break;
				}
				else if (select == 'a') {
					if (s == 1) {
						story2();
						return 0;
					}
					else {
						return 0;
					}
				}
				else if (select == 'A') {
					error = 1;
					break;
				}
				else if (select < 0 || select > 126) {
					error = 2;
					break;
				}
			}
		}
	}
}

void story2() {
	char y = NULL;
	int max_pharase = 3;
	for (int i = 1; i < max_pharase+1; i++) {
		
			system("cls");
			story3(i);
			y = _getch();
		
	}
	
}
void story3(int num) {
	if (num > 0) {
		printf("���丮1\n");
	}
	if (num > 1) {
		printf("���丮2\n");
	}
	if (num > 2) {
		printf("���丮3\n");
	}
}
void gotoxy(int x, int y) { //Ŀ�� �̵�
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int start_select(int money, int cleared) {  //���� �������̽�
	int s = 1;
	int error = 0;
	char select = NULL;
	while (1) {
		system("cls");
		printf("���� Ű���ֱ�\n�۾�\n����\n����");
		printf("\n\n���� �� : %d��", money);
		if (cleared == 1) {
			gotoxy(0, 8);
			printf("Ŭ��� �����մϴ�!");
		}
		if (error == 1) { //Caps Lock Ȱ��ȭ
			gotoxy(0, 6);
			printf("Caps Lock�� Ǯ���ּ���.");
			error = 0;
		}
		else if (error == 2) { //��/��Ű ��ȯ
			gotoxy(0, 6);
			printf("��/��Ű�� �ٲ��ּ���.");
			error = 0;
		}
		if (s == 1) {
			gotoxy(14, 0);
		}
		else if (s == 2) {
			gotoxy(5, 1);
		}
		else if (s == 3) {
			gotoxy(5, 2);
		}
		else if (s == 4) {
			gotoxy(5, 3);
		}
		printf("<");

		while (1) {
			if (_kbhit()) {
				select = _getch();
				if (select == -32) {
					select = _getch();
					switch (select) {
					case 72:
						if (s != 1) {
							s--;
							break;
						}
					case 80:
						if (s != 4) {
							s++;
							break;
						}
					}
					break;
				}
				else if (select == 'a') {
					return s;
				}
				else if (select == 'A') {
					error = 1;
					break;
				}

				else if (select < 0 || select > 126) {
					error = 2;
					break;
				}
			}
		}
	}
}
int working(int money, int lvA, int lvB, int lvC, int lvD, int lvE, int ef) {
	int s = 1;
	int income = money;
	int work = 0;
	int progress = 0;
	int max_progress = 1;
	int error = 0;

	int lv[6] = { lvA, lvB, lvC, lvD, lvE , lvE };

	char select = NULL;
	while (1) {
		system("cls");
		if (work == 0) {
			printf("f<   j");
		}
		else if (work == 1) {
			printf("f    j<");
		}
		printf("\n���� �� : %d��", income);
		printf("\n�۾� ȿ���� : Lv.%d", ef);
		printf("\n�۾� ���൵ : %d/%d\n\n", progress, max_progress);


		printf("���� ���� Lv.%d\n���� ���� ���� Lv.%d\n���� ���� ���� Lv.%d\n���� ���� ���� Lv.%d\n���� �� ���� Lv.%d\n���ư���", lvA, lvB, lvC, lvD, lvE);
		if (error == 1) { //Caps Lock Ȱ��ȭ
			gotoxy(0, 13);
			printf("Caps Lock�� Ǯ���ּ���.");
			error = 0;
		}
		else if (error == 2) { //��/��Ű ��ȯ
			gotoxy(0, 13);
			printf("��/��Ű�� �ٲ��ּ���.");
			error = 0;
		}
		if (s == 1) {
			gotoxy(17, 5);

		}
		else if (s == 2) {
			gotoxy(22, 6);

		}
		else if (s == 3) {
			gotoxy(22, 7);

		}
		else if (s == 4) {
			gotoxy(22, 8);
		}
		else if (s == 5) {
			gotoxy(20, 9);

		}
		else if (s == 6) {
			gotoxy(9, 10);
		}
		printf("<");
		while (1) {
			if (_kbhit()) {
				select = _getch();
				if (select == -32) {
					select = _getch();
					switch (select) {
					case 72:
						if (s != 1) {
							s--;
							progress = 0;
						}
						break;
					case 80:
						if (s != 6) {
							s++;
							if (s != 5) {
								progress = 0;
							}

						}
						break;
					}
					break;
				}
				else if (select == 'a') {
					if (s == 6) {
						return income;
					}

				}
				else if (select == 'f') {
					if (work == 0) {
						progress += 1 + ef;
						work = 1;
						if (progress >= max_progress) {
							income += calIncome(s, lv[s - 1]);
							progress = 0;
						}
						break;
					}
				}
				else if (select == 'j') {
					if (work == 1) {
						progress += 1 + ef;
						work = 0;
						if (progress >= max_progress) {
							income += calIncome(s, lv[s - 1]);
							progress = 0;
						}
						break;
					}
				}
				else if (select == 'p') {
					income += 100;
					break;
				}
				else if (select == 'A') {
					error = 1;
					break;
				}
				else if (select < 0 || select > 126) {
					error = 2;
					break;
				}
			}
		}
		if (s == 1) {
			max_progress = 1;
		}
		else if (s == 2) {
			max_progress = 10;
		}
		else if (s == 3) {
			max_progress = 100;
		}
		else if (s == 4) {
			max_progress = 500;
		}
		else if (s == 5) {
			max_progress = 2000;
		}
		else if (s == 6) {
			max_progress = 2000;
		}
	}
}

int calIncome(int type, int lv) {
	if (lv == 0) {
		return 0;
	}
	if (type == 1) {
		return lv;
	}
	else if (type == 2) {
		return 15 + lv * 20;
	}
	else if (type == 3) {
		return 200 + lv * 500;
	}
	else if (type == 4) {
		return 1250 + lv * 5000;
	}
	else if (type == 5 || type == 6) {
		return 5000 + lv * 40000;
	}
}

int shopping(int money, int lvA, int lvB, int lvC, int lvD, int lvE, int ef, int fer, int water, int max_water, int drug, int num) {
	int s = num;
	int error = 0;
	char select = NULL;
	while (1) {
		system("cls");
		printf("\n\n\n\n");
		printf("���� ���� �̷м�\n���� ���� ���ۼ�\n���� ���� ���ۼ�\n���� ���� ���ۼ�\n���� �� ���� �̷м�\n�۾� ȿ���� �̷�\n���\n��\n���Ѹ��� ����\n������\n�ڷΰ���");
		printf("\n\n\n���� �� : %d��", money);
		if (error == 1) { //Caps Lock Ȱ��ȭ
			gotoxy(0, 18);
			printf("Caps Lock�� Ǯ���ּ���.");
			error = 0;
		}
		else if (error == 2) { //��/��Ű ��ȯ
			gotoxy(0, 18);
			printf("��/��Ű�� �ٲ��ּ���.");
			error = 0;
		}
		else if (error == 3) {
			gotoxy(0, 18);
			printf("���� �����մϴ�.");
			error = 0;
		}
		else if (error == 4) {
			gotoxy(0, 18);
			printf("���̻� ���� �� �� �����ϴ�.");
		}
		else if (error == 5) {
			gotoxy(0, 18);
			printf("���� ���� �� �� �����ϴ�.");
		}
		if (s == 1) {
			gotoxy(0, 0);
			int income = lvA;
			if (lvA == 0) {
				income = 0;
			}
			printf("���� ���� �̷м�(Lv.%d)\n���� ������ ���� �ɷ��� Ű��ϴ�.\n���ͷ�:%d�� > %d��  �ʿ� �ڱ�:%d��", lvA, income, lvA + 1, 10 + lvA * 3);
			gotoxy(17, 4);
		}
		else if (s == 2) {
			int income = 15+ lvB * 20;
			if (lvB == 0) {
				income = 0;
			}
			gotoxy(0, 0);
			printf("���� ���� ���ۼ�(Lv.%d)\n���� ���� ���ۿ� ���� �ɷ��� Ű��ϴ�.\n���ͷ�:%d�� > %d��  �ʿ� �ڱ�:%d��  �ʿ� ����:���� ���� �̷� Lv.%d", lvB, income, income + 20, 50 + lvB * 9, 50);
			gotoxy(17, 5);
		}
		else if (s == 3) {
			gotoxy(0, 0);
			int income = 200 + lvC * 500;
			if (lvC == 0) {
				income = 0;
			}
			printf("���� ���� ���ۼ�(Lv.%d)\n���� ���� ���ۿ� ���� �ɷ��� Ű��ϴ�.\n���ͷ�:%d�� > %d��  �ʿ� �ڱ�:%d��  �ʿ� ����:���� ���� ���� Lv.%d", lvC, income, income + 500, 100 + lvC * 23, 50);
			gotoxy(17, 6);
		}
		else if (s == 4) {
			gotoxy(0, 0);
			int income = 1500 + lvD * 5000;
			if (lvD == 0) {
				income = 0;
			}
			printf("���� ���� ���ۼ�(Lv.%d)\n���� ���� ���ۿ� ���� �ɷ��� Ű��ϴ�.\n���ͷ�:%d�� > %d��  �ʿ� �ڱ�:%d��  �ʿ� ����:���� ���� ���� Lv.%d", lvD, income, income + 5000, 250 + lvD * 41, 50);
			gotoxy(17, 7);
		}
		else if (s == 5) {
			gotoxy(0, 0);
			int income = 10000 + lvE * 40000;
			if (lvE == 0) {
				income = 0;
			}
			printf("���� �� ���� �̷м�(Lv.%d)\n���� �� ���࿡ ���� �ɷ��� Ű��ϴ�.\n���ͷ�:%d�� > %d��  �ʿ� �ڱ�:%d��  �ʿ� ����:���� ���� ���� Lv.%d", lvE, income, income + 40000, 500 + lvE * 102, 50);
			gotoxy(20, 8);
		}
		else if (s == 6) {
			gotoxy(0, 0);
			printf("�۾� ȿ���� �̷�(Lv.%d)\n�۾��� ȿ������ Ű��ϴ�.\n�۾� ȿ�� %d > %d  �ʿ� �ڱ�:%d��", ef, ef, ef + 1, 1000 + 2500 * ef);
			gotoxy(17, 9);
		}
		else if (s == 7) {
			gotoxy(0, 0);
			printf("���(%d��)\n������ ���嵵�� ���� �� �ֽ��ϴ�.\n���嵵 ����:70  �ʿ� �ڱ�:50��     s�� �ϰ� ����", fer);
			gotoxy(5, 10);
		}
		else if (s == 8) {
			gotoxy(0, 0);
			printf("��(%d/%d)\n������ ���嵵�� ���� �� �ֽ��ϴ�.\n���嵵 ����:1  �ʿ� �ڱ�:����", water, max_water);
			gotoxy(3, 11);
		}
		else if (s == 9) {
			gotoxy(0, 0);
			printf("���Ѹ��� ����(Lv.%d)\n���� �ִ� ���差�� ���Դϴ�.\n���Ѹ��� �뷮:%d > %d  �ʿ� �ڱ�:%d��", (max_water - 10) / 10, max_water, max_water + 10, 10 + max_water * 2);
			gotoxy(14, 12);
		}
		else if (s == 10) {
			gotoxy(0, 0);
			if (drug == 0) {
				printf("������(����)\n������ ���嵵 ȿ���� ���Դϴ�.\n���嵵 ȿ�� ���� : x2  �ʿ� �ڱ�:5000��");
			}
			else {
				printf("������(���Ե�)\n������ ���嵵 ȿ���� ���Դϴ�.\n���嵵 ȿ�� ���� : x2  �ʿ� �ڱ�:5000��");
			}
			gotoxy(7, 13);
		}
		else if (s == 11) {
			gotoxy(9, 14);
		}

		printf("<");

		while (1) {
			if (_kbhit()) {
				select = _getch();
				if (select == -32) {
					select = _getch();
					switch (select) {
					case 72:
						if (s != 1) {
							s--;

						}
						break;
					case 80:
						if (s != 11) {
							s++;

						}
						break;
					}
					break;
				}
				else if (select == 'a') {
					if (s == 1) {
						if (lvA == 100) {
							error = 4;
							break;
						}
						else if (money < 10 + lvA * 3) {
							error = 3;
							break;
						}
					}
					else if (s == 2) {
						if (lvA < 50) {
							error = 5;
							break;
						}
						else if (lvB == 100) {
							error = 4;
							break;
						}
						else if (money < 50 + lvB * 9) {
							error = 3;
							break;
						}
					}
					else if (s == 3) {
						if (lvB < 50) {
							error = 5;
							break;
						}
						else if (lvC == 100) {
							error = 4;
							break;
						}
						else if (money < 100 + lvC * 23) {
							error = 3;
							break;
						}
					}
					else if (s == 4) {
						if (lvC < 50) {
							error = 5;
							break;
						}
						else if (lvD == 100) {
							error = 4;
							break;
						}
						else if (money < 250 + lvD * 41) {
							error = 3;
							break;
						}
					}
					else if (s == 5) {
						if (lvD < 50) {
							error = 5;
							break;
						}
						else if (lvE == 100) {
							error = 4;
							break;
						}
						else if (money < 500 + lvE * 102) {
							error = 3;
							break;
						}
					}
					else if (s == 6) {
						if (ef == 10) {
							error = 4;
							break;
						}
						else if (money < 1000 + 2500 * ef) {
							error = 3;
							break;
						}
					}
					else if (s == 7) {
						if (money < 50) {
							error = 3;
							break;
						}
					}
					else if (s == 8) {
						if (water == max_water) {
							error = 4;
							break;
						}
					}
					else if (s == 9) {
						if (money < 10 + max_water * 2) {
							error = 3;
							break;
						}
					}
					else if (s == 10) {
						if (drug == 1) {
							error = 4;
							break;
						}
						else if (money < 5000) {
							error = 3;
							break;
						}
					}
					return s;
				}
				else if (select == 'A') {
					error = 1;
					break;
				}
				else if (select == 's') {
					if (s == 7) {
						return 20;
					}
					
				}


				else if (select < 0 || select > 126) {
					error = 2;
					break;
				}
			}
		}
	}
}
int tree(int xp, int max_xp, int level, int fer, int water, int max_water, int drug, int num) {
	int s = num;
	int error = 0;
	char select = NULL;
	while (1) {
		system("cls");
		treeName(level);
		if (level == 100) {
			ending();
			s = 777;
			return s;
		}
		printf("%d�ܰ� ����\n���嵵 %d/%d\n������:", level, xp, max_xp);
		if (drug == 0) {
			printf("����\n\n\n");
		}
		else {
			printf("���Ե�\n\n\n");
		}
		printf("�� �ֱ�\n��� �ֱ�\n�ڷΰ���");
		
		if (error == 1) { //Caps Lock Ȱ��ȭ
			gotoxy(0, 17);
			printf("Caps Lock�� Ǯ���ּ���.");
			error = 0;
		}
		else if (error == 2) { //��/��Ű ��ȯ
			gotoxy(0, 17);
			printf("��/��Ű�� �ٲ��ּ���.");
			error = 0;
		}
		else if (error == 3) {
			gotoxy(0, 17);
			printf("��ᰡ �����մϴ�.");
			error = 0;
		}
		else if (error == 4) {
			gotoxy(0, 17);
			printf("���� �����մϴ�.");
			error = 0;
		}
		if (s == 1) {
			gotoxy(0, 10);
			printf("��\n�ܿ�:%d/%d\n���嵵 ����:1", water, max_water);
			
			gotoxy(8, 6);
		}
		else if (s == 2) {
			gotoxy(0, 10);
			printf("���\n����:%d��\n���嵵 ����:70\ns�� 10���� �ֱ�\nd�� 100���� �ֱ�", fer);
			gotoxy(10, 7);
		}
		else if (s == 3) {
			gotoxy(9, 8);
		}

		printf("<");

		while (1) {
			if (_kbhit()) {
				select = _getch();
				if (select == -32) {
					select = _getch();
					switch (select) {
					case 72:
						if (s != 1) {
							s--;

						}
						break;
					case 80:
						if (s != 3) {
							s++;

						}
						break;
					}
					break;
				}
				else if (select == 'a') {
					if (s == 1) {
						if (water == 0) {
							error = 4;
							break;
						}
						
					}
					else if (s == 2) {
						if (fer == 0) {
							error = 3;
							break;
						}
						
					}
					
					return s;
				}
				else if (select == 'A') {
					error = 1;
					break;
				}
				else if (select == 's') {
					if (s == 2) {
						if (fer < 10) {
							error = 3;
							break;
						}
						else {
							return 10;
						}
					}
				}
				else if (select == 'd') {
					if (s == 2) {
						if (fer < 100) {
							error = 3;
							break;
						}
						else {
							return 11;
						}
					}
				}
				else if (select < 0 || select > 126) {
					error = 2;
					break;
				}
			}
		}
	}
}
void treeName(int lv) {
	if (lv < 5) {
		printf("����");
	}
	else if (lv < 10) {
		printf("���� ������ ����");
	}
	else if (lv < 15) {
		printf("�� ������ ����");
	}
	else if (lv < 20) {
		printf("������ �Ǳ� ���� ����");
	}
	else if (lv < 25) {
		printf("���׸��� ����");
	}
	else if (lv < 30) {
		printf("�ƴ��� ����");
	}
	else if (lv < 35) {
		printf("����");
	}
	else if (lv < 40) {
		printf("���� �Ǿ ����");
	}
	else if (lv < 45) {
		printf("�������");
	}
	else if (lv < 50) {
		printf("����⿡ ����� ����");
	}
	else if (lv < 55) {
		printf("ū ����");
	}
	else if (lv < 60) {
		printf("�Ŵ��� ����");
	}
	else if (lv < 65) {
		printf("'����'�ƹ�Ÿ��");
	}
	else if (lv < 70) {
		printf("�˹��� ���� �ܹ��� �� '����'����");
	}
	else if (lv < 75) {
		printf("������� ������ ���̴� ����");
	}
	else if (lv < 80) {
		printf("������� �Ǳ� ������ ����");
	}
	else if (lv < 85) {
		printf("�����");
	}
	else if (lv < 90) {
		printf("���� �����");
	}
	else if (lv < 95) {
		printf("���� ������ �ʱ� ������ �����");
	}
	else if (lv < 99) {
		printf("���ǿ� ������ �����");
	}
	else if(lv < 100) {
		printf("�ϴ��� �ձ� ������ �����");
	}
	else {
		printf("�ϴ��� �վ �����");
	}
	printf("\n");
}
void ending() {
	char y;
	system("cls");
	ending2();
	printf("\n�̾߱�� �������� ������ ����� �� �ֽ��ϴ�.\n�ƹ� Ű�� ���� ���");
	y = _getch();
	
}
void ending2() {
	char y = NULL;
	int max_pharase = 3;
	for (int i = 1; i < max_pharase + 1; i++) {

		system("cls");
		ending3(i);
		y = _getch();

	}

}
void ending3(int num) {
	if (num > 0) {
		printf("����1\n");
	}
	if (num > 1) {
		printf("����2\n");
	}
	if (num > 2) {
		printf("~fin~");
	}
}