#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <Windows.h>

#define VER "final"

typedef struct all_var {
	//items
	int money;
	int fer;
	int water;
	int max_water;
	int drug;
	int shoes;
	//goods
	int gA;
	int gB;
	int gC;
	int gD;
	int gE;
	//skills
	int lvA;
	int lvB;
	int lvC;
	int lvD;
	int lvE;
	int ef;
	//books : skill
	int bA;
	int bB;
	int bC;
	int bD;
	int bE;
	int bEF;
	int bDutch;
	//books : story
	int sA;
	int sB;
	int sC;
	int sD;
	int sE;
	//books : tree
	int bT;
	//tree
	int xp;
	int max_xp;
	int level;
	int readed;
	int druged;
	//treeEffect
	int effectA;
	int effectB;
	int effectC;
	int effectD;
	int effectFin;
	//quest
	int questA;
	int questB;
	int questC;
	int questD;
	int questE;
	//story
	int level20;
	int level40;
	int level60;
	int level80;
	int clear;
	//etc
	int angel;
	int devil;
	int dutch;
	int moving;
	int clean;
}var;

void intro();
void story();
void story2();
void story3(int num);
void CursorView();
void gotoxy(int x, int y);
var start_select(int num, int num2, int cleared, int level, var a);
void animation(int from, int to, int level);
var rest(var a);
var read(var a);
var status(var a);
var storage(var a);
var work(var a);
var shop_items(var a);
var shop_books(var a);
var sell(var a);
var tree(var a);
void treeName(int lv);
var effect(var a);

void ending();
void ending2();
void ending3(int num);
void bookA1();
void bookA2(int num);
void bookB1();
void bookB2(int num);
void bookC1();
void bookC2(int num);
void bookD1();
void bookD2(int num);
void bookE1();
void bookE2(int num);
void evA1();
void evA2(int num);
void evB1();
void evB2(int num);
void evC1();
void evC2(int num);
void evD1();
void evD2(int num);

int main() {

	var v;
	v.money = 0;
	v.fer = 0;
	v.water = 0;
	v.max_water = 100;
	v.drug = 0;
	v.shoes = 0;
	v.gA = 0;
	v.gB = 0;
	v.gC = 0;
	v.gD = 0;
	v.gE = 0;
	v.lvA = 1;
	v.lvB = 0;
	v.lvC = 0;
	v.lvD = 0;
	v.lvE = 0;
	v.ef = 0;
	v.bA = 0;
	v.bB = 0;
	v.bC = 0;
	v.bD = 0;
	v.bE = 0;
	v.bDutch = 0;
	v.bEF = 0;
	v.bT = 0;
	v.sA = 0;
	v.sB = 0;
	v.sC = 0;
	v.sD = 0;
	v.sE = 0;
	v.xp = 0;
	v.max_xp = 100;
	v.level = 0;
	v.readed = 0;
	v.druged = 0;
	v.effectA = 0;
	v.effectB = 0;
	v.effectC = 0;
	v.effectD = 0;
	v.effectFin = 0;
	v.clear = 0;
	v.questA = 0;
	v.questB = 0;
	v.questC = 0;
	v.questD = 0;
	v.questE = 0;
	v.dutch = 0;
	v.angel = 0;
	v.devil = 0;
	v.clean = 1;
	v.level20 = 0;
	v.level40 = 0;
	v.level60 = 0;
	v.level80 = 0;
	int place = 1;
	int select = 1;

	int cleared = 0;
	SetConsoleTitle("����Ű���");
	CursorView();
	intro();
	story();
	while (1) {
		int level = 1 + v.shoes + v.effectB;
		if (v.effectFin == 1) {
			level = 4;
		}
		var a = start_select(place, select, cleared, level, v);
		v = a;

		place = a.moving / 10;
		select = a.moving % 10;
		if (select == 3) {
			system("cls");
			printf("���� �����Ͻðڽ��ϱ�?\n�� ������ ����� �ҷ����⸦ �������� �ʽ��ϴ�.\n\n");
			printf("y�� �����ּ���>");
			char q = _getch();
			if (q == 'y') {
				break;
			}
		}
		else if (select == 2) {
			
		}
		else {
			if (place == 1) {
				var tmp = tree(v);
				v = tmp;
				if (v.clear == 1) {
					cleared = 1;
				}
			}
			else if (place == 2) {
				var tmp = rest(v);
				v = tmp;
			}
			else if (place == 3) {//��
				var tmp = work(v);
				v = tmp;
				//money = working(money, work_wood_Lv, work_doll_Lv, work_tool_Lv, work_furn_Lv, work_house_Lv, work_efficiency);
			}
			else if (place == 4) {//����
				var tmp = shop_items(v);
				v = tmp;
			}
			else if (place == 5) {
				var tmp = shop_books(v);
				v = tmp;
			}
			else {
				var tmp = sell(v);
				v = tmp;
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
	int max_pharase = 10;
	for (int i = 1; i < max_pharase + 1; i++) {

		system("cls");
		story3(i);
		y = _getch();

	}

}

void story3(int num) {
	if (num > 0) {
		printf("-�� 2�ô� 316�� 4�� 1��\n");
	}
	if (num > 1) {
		printf("�� ������ ���� ���� �߽ɿ� �־� ����� �ߴ��Ͼ���.\n");
	}
	if (num > 2) {
		printf("��κ��� �ֹε��� ���� ������ ������ ����� �԰� ��Ҵ�.\n");
	}
	if (num > 3) {
		printf("�� ���� ��� �ֹε��� ��ü������ ��ǰ�� ����� �ȱ⵵ �ߴµ�, ���� ���� �ϳ���.\n");
	}
	if (num > 4) {
		printf("���� ��������� ���� ��ǰ ���۾��� �ؿ��� ������ �ڼ��̴�.\n");
	}
	if (num > 5) {
		printf(".\n");
	}
	if (num > 6) {
		printf(".\n");
	}
	if (num > 7) {
		printf("��� ��, ���� ��ȭ���� ���� �� �������� �� ������ �ٳ���� �� �� ������ �ٴڿ� ������ �ִ� �� ���Ҵ�.\n");
	}
	if (num > 8) {
		printf("���� �� ������ �ֿ���.\n");
	}
	if (num > 9) {
		printf("����� ���� ���� �������� ����������, ���� �ɽ�Ǯ�̷� Ű������� �ߴ�.\n");
	}
	if (num > 10) {
		printf("\n");
	}
}

void gotoxy(int x, int y) { //Ŀ�� �̵�
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void CursorView() {
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1; //Ŀ�� ���� (1 ~ 100)
	cursorInfo.bVisible = FALSE; //Ŀ�� Visible TRUE(����) FALSE(����)
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

var start_select(int num, int num2, int cleared, int level, var a) {  //���� �������̽�
	var t = a;
	int s = num2;
	int v = num;
	int error = 0;
	char select = NULL;

	if (t.questA == 0 && t.lvD >= 20) {
		t.questA = 1;
	}
	if (t.questB == 0 && t.lvB >= 5) {
		t.questB = 1;
	}
	if (t.questC == 0 && t.level >= 10) {
		t.questC = 1;
	}
	if (t.questD == 0 && t.lvE >= 1 && t.level >= 20) {
		t.questD = 1;
	}
	if (t.questE == 0 && t.lvC  >= 2) {
		t.questE  = 1;
	}

	while (1) {
		system("cls");
		printf("\n\n\n\n");
		printf("����\n\n����");
		gotoxy(0, 1);
		printf("�޸���  ��  �۾���  ��ȭ��  ����  �Ǹ���");
		gotoxy(0, 8);
		printf("-------------------------------------------------------------");
		int o = 0;
		if (t.questA != 0) {
			gotoxy(8, 0);
			o = t.questA;
			if (o == 1) {
				printf("?");
			}
			if (o == 2 && t.gD >= 5) {
				printf("!");
			}
			else if (o == 2) {
				printf("~");
			}
		}
		if (t.questB != 0) {
			gotoxy(14, 0);
			o = t.questB;
			if (o == 1) {
				printf("?");
			}
			if (o == 2 && t.gB >= 1) {
				printf("!");
			}
			else if (o == 2) {
				printf("~");
			}
		}
		if (t.questC != 0) {
			gotoxy(22, 0);
			o = t.questC;
			if (o == 1) {
				printf("?");
			}
			if (o == 2 && t.gC >= 25) {
				printf("!");
			}
			else if (o == 2) {
				printf("~");
			}
		}
		if (t.questD != 0) {
			gotoxy(29, 0);
			o = t.questD;
			if (o == 1) {
				printf("?");
			}
			if (o == 2 && t.gE >= 1) {
				printf("!");
			}
			else if (o == 2) {
				printf("~");
			}
		}
		if (t.questE != 0) {
			gotoxy(36, 0);
			o = t.questE;
			if (o == 1) {
				printf("?");
			}
			if (o == 2 && t.gA >= 500) {
				printf("!");
			}
			else if (o == 2) {
				printf("~");
			}
		}

		if (v == 1) {
			gotoxy(0, 5);
			printf("�ǻ߿� ��ȭ�ϱ�");
			gotoxy(2, 2);
		}
		else if (v == 2) {
			gotoxy(0, 5);
			printf("�ƹ����� ��ȭ�ϱ�");
			gotoxy(8, 2);
		}
		else if (v == 3) {
			gotoxy(0, 5);
			printf("���� ������ ��ȭ�ϱ�");
			gotoxy(14, 2);
		}
		else if (v == 4) {
			gotoxy(0, 5);
			printf("�� �������� ��ȭ�ϱ�");
			gotoxy(22, 2);
		}
		else if (v == 5) {
			gotoxy(0, 5);
			printf("ī����� ��ȭ�ϱ�");
			gotoxy(29, 2);
		}
		else if (v == 6) {
			gotoxy(0, 5);
			printf("����� ��ȭ�ϱ�");
			gotoxy(36, 2);
		}
		printf("@");
		if (cleared == 1) {
			gotoxy(0, 20);
			printf("Ŭ��� �����մϴ�!");
		}
		if (error == 1) { //Caps Lock Ȱ��ȭ
			gotoxy(0, 12);
			printf("Caps Lock�� Ǯ���ּ���.");
			error = 0;
		}
		else if (error == 2) { //��/��Ű ��ȯ
			gotoxy(0, 12);
			printf("��/��Ű�� �ٲ��ּ���.");
			error = 0;
		}
		if (s == 1) {
			gotoxy(10, 4);
		}
		else if (s == 2) {
			if (v == 1) {
				gotoxy(16, 5);
			}
			else if (v == 2) {
				gotoxy(18, 5);
			}
			else if (v == 3) {
				gotoxy(21, 5);
			}
			else if (v == 4) {
				gotoxy(21, 5);
			}
			else if (v == 5) {
				gotoxy(18, 5);
			}
			else if (v == 6) {
				gotoxy(16, 5);
			}
		}
		else if (s == 3) {
			gotoxy(5, 6);
		}
		printf("<");

		while (1) {
			if (_kbhit()) {
				select = _getch();
				if (select == -32) {
					select = _getch();
					switch (select) {
					case 75:
						if (v != 1) {
							if (t.effectFin == 0) {
								animation(v, v - 1, level);
							}
							v--;
						}
						break;
					case 77:
						if (v != 6) {
							if (t.effectFin == 0) {
								animation(v, v + 1, level);
							}
							v++;
						}
						break;
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
					if (s != 2) {
						t.moving = s + 10 * v;
						return t;
					}
					else {
						if (v == 1) {	
							gotoxy(0, 9);
							printf("�ǻ�)\n�߿�~\n\n(�Ϳ���.)");
						}
						else if (v == 2) {
							system("cls");
							printf("\n\n\n\n");
							printf("����\n\n����");
							gotoxy(0, 1);
							printf("�޸���  ��  �۾���  ��ȭ��  ����  �Ǹ���");
							gotoxy(0, 8);
							printf("-------------------------------------------------------------");
							gotoxy(0, 5);
							printf("�ƹ����� ��ȭ�ϱ� <");
							if (t.questA== 0) {

								gotoxy(0, 9);
								printf("�ƹ���)\n��...���簡 �������...?");

							}
							else if (t.questA == 1) {
								gotoxy(0, 9);
								printf("�ƹ���)\n��, ��ħ �� �Դ�.\n��� �ð� �Ǵ�?\n\nz > �� �ƹ��� �������̽Ű���?\nx > �ƴ� �ٺ���.\nc > (�����Ѵ�.)\n\n");
								while (1) {
									char d = _getch();
									if (d == 'z') {
										printf("�� �ƹ��� �������̽Ű���?\n\n�ƹ���)\n��... ������ ���� ���尣 �� ���� ���ƿ� �ǵ�, �� ���� ħ�븦 ������ �达�� �����Ѵٰ� �Ⱦƹ����� ���̾�.\n\n�� �׷��� ������ �׸��϶� ���ݾƿ�.\n\n�ƹ���)\n����; �ƹ�ư �� �� ħ�븦 �ٽ� ������µ� ���� ���ϰ� ��ǰ�� ��ǰ�� �־ �׷��� ħ�� �ϳ��� ������� �� �ְڴ�?\n\nz > �� �� �翬����\nx > ��.. ���� �ȵɰŰ�����\n\n");

										while (1) {
											d = _getch();
											if (d == 'z') {
												printf("�� �� �翬����\n\n�ƹ���)\n��..! �Ѽ� ���ҳ�. �׷� ��Ź�Ұ�.\n\n(���� ���� 5���� ����� ��������.)");
												t.questA = 2;
												break;
											}
											else if (d == 'x') {
												printf("��.. ���� �ȵɰŰ�����\n\n�ƹ���)\n�ƾ�... �����...");
												break;
											}
										}
										break;
									}
									else if (d == 'x') {
										printf("�ƴ� �ٺ���.\n\n�ƹ���)\n��..�׷�..? �׷� �� ������ ��� ���ָ� ���ڱ���.\n\n(���� ������ ��� ã�ƿ���.)");
										break;
									}
									else if (d == 'c') {
										printf("�ƹ���)\n�� �� �ΰ��� ���� ����");
										break;
									}

								}
							}
							else if (t.questA == 2 && t.gD >= 5) {
								gotoxy(0, 9);
								printf("�ƹ���)\n��, ����� �Դ�? �����߾�. ���� ���� �Ⱦ��� ��ǰ �������� �Ⱦư����� �� �뵷���� ��.\n\n(�ƺ��� ���� ���� ì���̴ּ�.)\n(������ ���� 100��, ���� ���� 10��, ���� ���� 2���� �����!)");
								t.gD -= 5;
								t.gA += 100;
								t.gC += 10;
								t.gD += 2;
								t.questA = 3;
							}
							else if (t.questA == 2) {
								gotoxy(0, 9);
								printf("�ƹ���)\n��... �缷�̰� ���� �ʰ� �;� ���ٵ�... \n\n(���� ���� 5���� ����� ��������.)");
							}
							else if (t.questA == 3) {
								gotoxy(0, 9);
								printf("�ƹ���)\n�帣��....\n\n(�ڰ� ��Ŵ�. ������ ��������.)");
							}

						}
						else if (v == 3) {
							system("cls");
							printf("\n\n\n\n");
							printf("����\n\n����");
							gotoxy(0, 1);
							printf("�޸���  ��  �۾���  ��ȭ��  ����  �Ǹ���");
							gotoxy(0, 8);
							printf("-------------------------------------------------------------");
							gotoxy(0, 5);
							printf("���� ������ ��ȭ�ϱ� <");
							if (t.questB == 0) {
								
								gotoxy(0, 9);
								printf("���� ����)\n��ƾ�...");
								
							}
							else if (t.questB == 1) {
								gotoxy(0, 9);
								printf("���� ����)\n������~~~~�ФФФФФ�\n\n(���� ������ ��� �ִ�.)\nz > ������ ���� ���̴�?\nx > (�׳� ��������.)\nc > ��ξ� �ò������ ���� ���� ���.\n\n");
								while (1) {
									char d = _getch();
									if (d == 'z') {
										printf("������ ���� ���̴�?\n\n���� ����)\n�� ������.. � ����̰� ������ФФФФФ�\n\n(�� ������ ����̴� ������ �������� �츮 �ǻ߹ۿ� ���� �ٵ�. �׸��� �׿��߿� �� �۾��� �տ��� �̷��� �ֱ�.)\nz > ���� ���� �ϳ� ������ٱ�?\nx > ��ξ� ����̿� ���� ���ġ�� ���� ������ �ߴ۰� �ڷ�^^\n\n");

										while (1) {
											d = _getch();
											if (d == 'z') {
												printf("���� ����)\n(�����Ⱑ �� �������)��!!! �����մϴ�!!!!\n\n(���� ���� �Ѱ��� ������ ����.)");
												t.questB = 2;
												break;
											}
											else if (d == 'x') {
												printf("���� ����)\n���̾� ��ġ�� ������ ��������.\n\(������ �� �ָ� �����ƴ�. ����̰� ��� ��� ���ĸ�������.)");
												break;
											}
										}
										break;
									}
									else if (d == 'x') {
										printf("���� ����)\n������~~~~�ФФФФФ�\n\n(�ò�����.)");
										break;
									}
									else if (d == 'c') {
										printf("������ �ò������ ���� ���� ���.\n\n���� ����)\n�Ŀ����ФФФФФФФФФФФФФФФФФФФФФФ�\n\n(Ȥ�� ����� �������ΰ�?)");
										break;
									}

								}
							}
							else if (t.questB == 2 && t.gB >= 1) {
								gotoxy(0, 9);
								printf("���� ����)\n��!!���������������մϴ٤���������������\n\n(������ ������ �ް� �� �ָ� �����ȴ�.)\n(���� ���� ����Ʈ�ȴµ�, �Ĺ� ������?)\n(���� ì�ܰ���?)\nz > (ì���.)\nx > (�׳� �д�.)\n\n");
								t.gB--;
								t.questB = 3;
								while (1) {
									char d = _getch();
									if (d == 'z') {
										t.drug++;
										printf("(�������� �ϳ� �����!)");										
										break;
									}
									else if (d == 'x') {
										printf("(����, �˾Ƽ� �� ã�ư�����.)");
										break;
									}
								}
							}
							else if(t.questB == 2)  {
								gotoxy(0, 9);
								printf("���� ����)\n������...\n\n(���� ���� �Ѱ��� ������ ����.)");
							}
							else if (t.questB == 3) {
								gotoxy(0, 9);
								printf("���� ����)\n�����...?\n\n(���� ��� ã�� �ִ�.)");
							}
							
						}
						else if (v == 4) {
						system("cls");
						printf("\n\n\n\n");
						printf("����\n\n����");
						gotoxy(0, 1);
						printf("�޸���  ��  �۾���  ��ȭ��  ����  �Ǹ���");
						gotoxy(0, 8);
						printf("-------------------------------------------------------------");
						gotoxy(0, 5);
						printf("�� �������� ��ȭ�ϱ� <");
						if (t.questC == 0) {

							gotoxy(0, 9);
							printf("������)\n����, ������! �Դϴ� �ο�! 10����¥�� �ȭ�� ���� ��� 8����!\n\n������ �װ� ���������� ������ ���ݾƿ�.\n\n(������� ���� �ϸ� ������.)\n\n������)\n(���� ��Ҹ���)����..! �� ������ ����!");

						}
						else if (t.questC == 1) {
							gotoxy(0, 9);
							printf("������)\n�߾� �� ��ġ �� ������� �� �ֳ�? ���ϰ� �� 25������ �ʿ��ѵ�;\n\nz > �� �� ����� ���״� ��� �־����.\nx > �� ���� �ٺ���.\n\n");
							while (1) {
								char d = _getch();
								if (d == 'z') {
									printf("�� �� ����� ���״� ��� �־����.\n\n������)\n�� �����̴�! �� ��ڳ�.\n\n(���� ���� 25���� ����� ��������.)");
									t.questC = 2;
									break;
								}
								else if (d == 'x') {
									printf("�� ���� �ٺ���.\n\n������)\n����;;��ġ�ڳ�...�����..?\n\n(�������� ���� �ð��� ������ ���� ����ڴ�.)");
									break;
								}
							}
						}
						else if (t.questC == 2 && t.gC >= 5) {
							gotoxy(0, 9);
							printf("������)\n��! ��¥ ����. �� �ٰ� ���� ���� �ʶ��� ���ȾҴ� �ȭ�� �� ������.\n\n(�ȭ�� �ž���.)\n(�߰����� ����������!)");
							t.gC -= 25;
							t.shoes = 1;
							t.questC = 3;
						}
						else if (t.questC == 2) {
							gotoxy(0, 9);
							printf("(������ �� ���� ������ �ִ�. ���� �� ���� ����.)\n\n(���� ���� 25���� ����� ��������.)");
						}
						else if (t.questC == 3) {
							gotoxy(0, 9);
							printf("������)\n����, ������! �̹��� ��¬�ϴ�! 20����¥�� �赵���� ���� ��� 12����!\n\n(������� �� �ϰ� ���� �ϸ� ������.)\n\n(���� ���� 30�����ε�. �׷��� ����� �׸� ġ��.)");
						}

						}
						else if (v == 5) {
						system("cls");
						printf("\n\n\n\n");
						printf("����\n\n����");
						gotoxy(0, 1);
						printf("�޸���  ��  �۾���  ��ȭ��  ����  �Ǹ���");
						gotoxy(0, 8);
						printf("-------------------------------------------------------------");
						gotoxy(0, 5);
						printf("ī����� ��ȭ�ϱ� <");
						if (t.questD == 0) {
							gotoxy(0, 9);
							if (t.dutch == 0) {
								printf("ī����)\nWo habe ich meinen Stift hingelegt ...\n\n(����� ����...)");
							}
							else if (t.dutch == 1) {
								printf("ī����)\nWo habe ich meinen Stift hingelegt ...(���� ���� ��� �״���...)\n\nDu steckst es in dein Ohr.(�Ϳ� �����μ��ݾƿ�.)\n\nī����)\nAh, danke.(��, ������.)");
							}
							

						}
						else if (t.questD == 1) {
							gotoxy(0, 9);
							if (t.dutch == 0) {
								printf("ī����)\nOh, du bist gerade gekommen!\nBald wird mein Freund in diese Stadt kommen, um eine Weile zu leben.\nHaben Sie ein Haus, das Sie nicht nutzen?\nWenn du ein Haus mietest, gebe ich dir etwas Gutes.\n\nz > (����� �ž�...)\nx > (����� �ž�...)\nc > Uh...�������ζ�ť?\n\n");
								while (1) {
									char d = _getch();
									if (d == 'z' || d == 'x') {
										printf("ī����)\nGeh weg, du Idiot.\n\n(��¥ ����°ž�...)");
										break;
									}
									if (d == 'c') {
										printf("ī����)\nWenn Sie dumm sind, bleiben Sie still.\n\n(��¥ ����°ž�...)");
										break;
									}
								}
							}
							else if(t.dutch == 1) {
								printf("ī����)\nOh, du bist gerade gekommen!(��, ��ħ �� �Ծ��!)\nBald wird mein Freund in diese Stadt kommen, um eine Weile zu leben.(������ �� ģ���� �� ������ �ͼ� ��� �� �����̿���.)\nHaben Sie ein Haus, das Sie nicht nutzen?(Ȥ�� �Ⱦ��� ���� �ϳ� �������?)\nWenn du ein Haus mietest, gebe ich dir etwas Gutes.(�� ��ä�� �����ָ� ���� ���� �� �帮��.)\n\nz > Oh, ich werde einen machen.(��, ���� �ϳ� �����帱�Կ�.)\nx > Nein, ich kann dir nicht helfen.(�̷�, ���͵帱 ���� ���׿�.)\nc > Wachsen Sie es auf dem Boden.(��ٴڿ��� �ڶ�� �ϼ���.)\n\n");
								while (1) {
									char d = _getch();
									if (d == 'z') {
										printf("ī����)\nOh danke. Dann frage ich dich.(��, ������. �׷� ��Ź�ҰԿ�.)\n\n(���� �� ��ä�� ��������.)");
										t.questD = 2;
										break;
									}
									if (d == 'x') {
										printf("ī����)\nDas ist sehr schade. Was machen wir...(�ƽ��׿�. �����...)");
										break;
									}
									if (d == 'c') {
										printf("ī����)\nMein Freund ist nicht obdachlos.(�� ģ���� ����ڰ� �ƴմϴ�.)");
										break;
									}
								}
							}
						
						}
						else if (t.questD == 2 && t.gE >= 1) {
							gotoxy(0, 9);
							printf("ī����)\nOh vielen Dank.(��, ���� �����մϴ�. )\nAls Gegenleistung werde ich dir diese Bibel geben.(��ʷ� �� ������ �帮�ڽ��ϴ�.)\nDas ist heutzutage schwer zu finden.(������ ã�ƺ��� ���� �����Դϴ�.)\n\n(������ �����. ������ �Ҿ����� �� ���� �о��.)");
							t.gE -= 1;
							t.angel = 1;
							t.questD = 3;
						}
						else if (t.questD == 2) {
							gotoxy(0, 9);
							printf("ī����)\nDanke dir immer.(������ ����帳�ϴ�.)\n\n(���� �� 1ä�� �������.)");
						}
						else if (t.questD == 3) {
							gotoxy(0, 9);
							printf("ī����)\nGott segne dich.(��Ų� ���� �ູ�� �ֱ⸦.)\n\nDanke.(�����մϴ�.)");
						}

						}
						else if (v == 6) {
							system("cls");
							printf("\n\n\n\n");
							printf("����\n\n����");
							gotoxy(0, 1);
							printf("�޸���  ��  �۾���  ��ȭ��  ����  �Ǹ���");
							gotoxy(0, 8);
							printf("-------------------------------------------------------------");
							gotoxy(0, 5);
							printf("����� ��ȭ�ϱ� <");
							if (t.questE == 0) {

								gotoxy(0, 9);
								printf("����)\n��...�̹��� �������� �����ϳ�..�ƴ� �� �ǳ���?\n\n(���� �Ǹ��� ��� ���� �� ����. �׳� �������߰ڴ�.)");

							}
							else if (t.questE == 1) {
								gotoxy(0, 9);
								printf("����)\n�߾߾߾߾߾߾߾߾߾߾߾߾߾߾߾ߤ�\n\nz > ���𰡸� �߸� �Ծ���?\nx > �� ����;\nc > (����ģ��.)\n\n");
								while (1) {
									char d = _getch();
									if (d == 'z') {
										printf("���𰡸� �߸� �Ծ���?\n\n����)\n�� ���� �峭ĥ �ð� ����! �� ���켭 �׷��� �� �������� 500���� ������ټ� �־�?\n\nz > ��...�׷�?\nx > ��������?\nc > (���� ������ ����ģ��.)\n\n");
										while (1) {
											char d = _getch();
											if (d == 'z') {
												printf("��...�׷�?\n\n����)\n���Ƥ��� ��¥ ���� ģ����! �׷� ��Ź�Ұ�.\n\n(������ ���� 500���� ������ ����.)");
												t.questE = 2;
												break;
											}
											else if (d == 'x') {
												printf("��������?\n\n����)\n�� �� ������ �װ����ݾ� �װ�...�� ���״ϱ� ���� �ȵǳ�?\n\n(���� �ֱ�������. ������ٱ�?)\nz > ���� �������\nx > ���� �ȸ������\n\n");
												while (1) {
													char d = _getch();
													if (d == 'z') {
														printf("���� �������\n\n����)\n���Ƥ��� ��¥ ���� ģ����! �׷� ��Ź�Ұ�.\n\n(������ ���� 500���� ������ ����.)");
														t.questE = 2;
														break;
													}
													else if (d == 'x') {
														printf("����)��...�̰� �����...");
														break;
													}
												}
												break;
											}
											else if (d == 'c') {
												printf("(������ �����ƴ�!)");
												break;
											}
										}
										break;
									}
									else if (d == 'x') {
										printf("�� ����;\n\n����)\n�� ����;; �� ���켭 �׷��� �� �������� 500���� ������ټ� �־�?\n\nz > ��...�׷�?\nx > ��������?\nc > (���� ������ ����ģ��.)\n\n");
										while (1) {
											char d = _getch();
											if (d == 'z') {
												printf("��...�׷�?\n\n����)\n���Ƥ��� ��¥ ���� ģ����! �׷� ��Ź�Ұ�.\n\n(������ ���� 500���� ������ ����.)");
												t.questE = 2;
												break;
											}
											else if (d == 'x') {
												printf("��������?\n\n����)\n�� �� ������ �װ����ݾ� �װ�...�� ���״ϱ� ���� �ȵǳ�?\n\n(���� �ֱ�������. ������ٱ�?)\nz > ���� �������\nx > ���� �ȸ������\n\n");
												while (1) {
													char d = _getch();
													if (d == 'z') {
														printf("���� �������\n\n����)\n���Ƥ��� ��¥ ���� ģ����! �׷� ��Ź�Ұ�.\n\n(������ ���� 500���� ������ ����.)");
														t.questE = 2;
														break;
													}
													else if (d == 'x') {
														printf("����)��...�̰� �����...");
														break;
													}
												}
												break;
											}
											else if (d == 'c') {
												printf("(������ �����ƴ�!)");
												break;
											}
										}
										break;
									}
									else if (d == 'c') {
										printf("(������ �����ƴ�!)");
										break;
									}
								}
							}
							else if (t.questE == 2 && t.gA >= 500) {
								gotoxy(0, 9);
								printf("����)\n�� ��¥ ����. �̰� �� ������.\n\n(���� å�� �����!)");
								t.gA -= 500;
								t.devil = 1;
								t.questE = 3;
							}
							else if (t.questE == 2) {
								gotoxy(0, 9);
								printf("(������ ǥ������ �������̿� �Ĺ����ִ�.)\n\n(������ ���� 500���� ����� ��������.)");
							}
							else if (t.questE == 3) {
								gotoxy(0, 9);
								printf("����)\n�� �� �ǹ� �ϳ� ���ʿ��ϳ�?\n�� �������� ���� ���尣 �ǹ��̶� ���� �ΰ� �����ŵ�?\n\n�����̳� ���� ���尣 ���ϴ°ž�? �ű� ���߾�?\n\n�ű� ��Ͻô� ���ܸ��� ���ڱ� �ε����� �ϽŴ�.\n\n(���� �η��� ������ �׻� �ű⼭ ��Դµ�. ���� �ٸ� ���尣 ã�ƺ��� �ϳ�.)");
							}

						}
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

void animation(int from, int to, int level) {
	int v = from;
	int speed = (4 - level) * 111;
	system("cls");
	if (v == 1) {
		gotoxy(2, 2);
	}
	else if (v == 2) {
		gotoxy(8, 2);
	}
	else if (v == 3) {
		gotoxy(14, 2);
	}
	else if (v == 4) {
		gotoxy(22, 2);
	}
	else if (v == 5) {
		gotoxy(29, 2);
	}
	else if (v == 6) {
		gotoxy(36, 2);
	}
	int dir = to - from;
	int start = clock();
	int end = clock();
	gotoxy(0, 1);
	printf("�޸���  ��  �۾���  ��ȭ��  ����  �Ǹ���");
	gotoxy(0, 8);
	printf("-------------------------------------------------------------");

	gotoxy(0, 5);
	printf("�̵���...");
	if (from == 1) {
		gotoxy(4, 2);
		printf("@");
		while (1) {
			if (_kbhit()) {
				char e = _getch();
			}
 			end = clock();
			if (end - start >= speed) {
				system("cls");
				gotoxy(0, 1);
				printf("�޸���  ��  �۾���  ��ȭ��  ����  �Ǹ���");
				gotoxy(0, 8);
				printf("-------------------------------------------------------------");
				gotoxy(6, 2);
				printf("@");
				gotoxy(0, 5);
				printf("�̵���...");
				break;
			}
		}
		start = clock();
		while (1) {
			if (_kbhit()) {
				char e = _getch();
			}
			end = clock();
			if (end - start >= speed) {
				system("cls");
				break;
			}
		}

	}
	else if (from == 2) {
		if (dir == -1) {
			gotoxy(6, 2);
			printf("@");
			while (1) {
				if (_kbhit()) {
					char e = _getch();
				}
				end = clock();
				if (end - start >= speed) {
					system("cls");
					gotoxy(0, 1);
					printf("�޸���  ��  �۾���  ��ȭ��  ����  �Ǹ���");
					gotoxy(0, 8);
					printf("-------------------------------------------------------------");
					gotoxy(4, 2);
					printf("@");
					gotoxy(0, 5);
					printf("�̵���...");
					break;
				}
			}
			start = clock();
			while (1) {
				if (_kbhit()) {
					char e = _getch();
				}
				end = clock();
				if (end - start >= speed) {
					system("cls");
					break;
				}
			}
		}
		if (dir == 1) {
			gotoxy(10, 2);
			printf("@");
			while (1) {
				if (_kbhit()) {
					char e = _getch();
				}
				end = clock();
				if (end - start >= speed) {
					system("cls");
					gotoxy(0, 1);
					printf("�޸���  ��  �۾���  ��ȭ��  ����  �Ǹ���");
					gotoxy(0, 8);
					printf("-------------------------------------------------------------");
					gotoxy(12, 2);
					printf("@");
					gotoxy(0, 5);
					printf("�̵���...");
					break;
				}
			}
			start = clock();
			while (1) {
				if (_kbhit()) {
					char e = _getch();
				}
				end = clock();
				if (end - start >= speed) {
					system("cls");
					break;
				}
			}
		}
	}
	else if (from == 3) {
		if (dir == -1) {
			gotoxy(12, 2);
			printf("@");
			while (1) {
				if (_kbhit()) {
					char e = _getch();
				}
				end = clock();
				if (end - start >= speed) {
					system("cls");
					gotoxy(0, 1);
					printf("�޸���  ��  �۾���  ��ȭ��  ����  �Ǹ���");
					gotoxy(0, 8);
					printf("-------------------------------------------------------------");
					gotoxy(10, 2);
					printf("@");
					gotoxy(0, 5);
					printf("�̵���...");
					break;
				}
			}
			start = clock();
			while (1) {
				if (_kbhit()) {
					char e = _getch();
				}
				end = clock();
				if (end - start >= speed) {
					system("cls");
					break;
				}
			}
		}
		if (dir == 1) {
			gotoxy(16, 2);
			printf("@");
			while (1) {
				if (_kbhit()) {
					char e = _getch();
				}
				end = clock();
				if (end - start >= speed) {
					system("cls");
					gotoxy(0, 1);
					printf("�޸���  ��  �۾���  ��ȭ��  ����  �Ǹ���");
					gotoxy(0, 8);
					printf("-------------------------------------------------------------");
					gotoxy(19, 2);
					printf("@");
					gotoxy(0, 5);
					printf("�̵���...");
					break;
				}
			}
			start = clock();
			while (1) {
				if (_kbhit()) {
					char e = _getch();
				}
				end = clock();
				if (end - start >= speed) {
					system("cls");
					break;
				}
			}
		}
	}
	else if (from == 4) {
		if (dir == -1) {
			gotoxy(19, 2);
			printf("@");
			while (1) {
				if (_kbhit()) {
					char e = _getch();
				}
				end = clock();
				if (end - start >= speed) {
					system("cls");
					gotoxy(0, 1);
					printf("�޸���  ��  �۾���  ��ȭ��  ����  �Ǹ���");
					gotoxy(0, 8);
					printf("-------------------------------------------------------------");
					gotoxy(16, 2);
					printf("@");
					gotoxy(0, 5);
					printf("�̵���...");
					break;
				}
			}
			start = clock();
			while (1) {
				if (_kbhit()) {
					char e = _getch();
				}
				end = clock();
				if (end - start >= speed) {
					system("cls");
					break;
				}
			}
		}
		if (dir == 1) {
			gotoxy(24, 2);
			printf("@");
			while (1) {
				if (_kbhit()) {
					char e = _getch();
				}
				end = clock();
				if (end - start >= speed) {
					system("cls");
					gotoxy(0, 1);
					printf("�޸���  ��  �۾���  ��ȭ��  ����  �Ǹ���");
					gotoxy(0, 8);
					printf("-------------------------------------------------------------");
					gotoxy(26, 2);
					printf("@");
					gotoxy(0, 5);
					printf("�̵���...");
					break;
				}
			}
			start = clock();
			while (1) {
				if (_kbhit()) {
					char e = _getch();
				}
				end = clock();
				if (end - start >= speed) {
					system("cls");
					break;
				}
			}
		}
	}
	else if (from == 5) {
		if (dir == -1) {
			gotoxy(26, 2);
			printf("@");
			while (1) {
				if (_kbhit()) {
					char e = _getch();
				}
				end = clock();
				if (end - start >= speed) {
					system("cls");
					gotoxy(0, 1);
					printf("�޸���  ��  �۾���  ��ȭ��  ����  �Ǹ���");
					gotoxy(0, 8);
					printf("-------------------------------------------------------------");
					gotoxy(24, 2);
					printf("@");
					gotoxy(0, 5);
					printf("�̵���...");
					break;
				}
			}
			start = clock();
			while (1) {
				if (_kbhit()) {
					char e = _getch();
				}
				end = clock();
				if (end - start >= speed) {
					system("cls");
					break;
				}
			}
		}
		if (dir == 1) {
			gotoxy(31, 2);
			printf("@");
			while (1) {
				if (_kbhit()) {
					char e = _getch();
				}
				end = clock();
				if (end - start >= speed) {
					system("cls");
					gotoxy(0, 1);
					printf("�޸���  ��  �۾���  ��ȭ��  ����  �Ǹ���");
					gotoxy(0, 8);
					printf("-------------------------------------------------------------");
					gotoxy(33, 2);
					printf("@");
					gotoxy(0, 5);
					printf("�̵���...");
					break;
				}
			}
			start = clock();
			while (1) {
				if (_kbhit()) {
					char e = _getch();
				}
				end = clock();
				if (end - start >= speed) {
					system("cls");
					break;
				}
			}
		}
	}
	else if (from == 6) {
		gotoxy(33, 2);
		printf("@");
		gotoxy(0, 5);
		printf("�̵���...");
		while (1) {
			if (_kbhit()) {
				char e = _getch();
			}
			end = clock();
			if (end - start >= speed) {

				system("cls");
				gotoxy(0, 1);
				printf("�޸���  ��  �۾���  ��ȭ��  ����  �Ǹ���");
				gotoxy(0, 8);
				printf("-------------------------------------------------------------");
				gotoxy(31, 2);
				printf("@");
				gotoxy(0, 5);
				printf("�̵���...");
				break;
			}
		}
		start = clock();
		while (1) {
			if (_kbhit()) {
				char e = _getch();
			}
			end = clock();
			if (end - start >= speed) {
				system("cls");
				break;
			}
		}

	}

}

var rest(var a) {
	var v;
	v = a;
	int s = 1;
	int error = 0;

	char select = NULL;
	while (1) {
		system("cls");
		printf("����\n�������ͽ�\nâ��\n������");
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
			gotoxy(5, 0);

		}
		else if (s == 2) {
			gotoxy(11, 1);

		}
		else if (s == 3) {
			gotoxy(5, 2);

		}
		else if (s == 4) {
			gotoxy(7, 3);
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
						if (s != 4) {
							s++;
						}
						break;
					}
					break;
				}
				else if (select == 'a') {
					if (s == 1) {
						var tmp = read(v);
						v = tmp;

					}
					else if (s == 2) {
						var tmp = status(v);
					}
					else if (s == 3) {
						var tmp = storage(v);
					}
					else if (s == 4) {
						return v;
					}
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
	}
}

var read(var a) {
	var v;
	v = a;
	int s = 1;
	int error = 0;
	int p = 0; // bA / bB / bC / bD / bE / bEF / bT / bDutch / sA / sB / sC / sD / sE / angel / devil

	char select = NULL;

	int b[15] = { 0, };
	if (v.bA > 0) {
		b[0] = 1;
	}
	if (v.bB > 0) {
		b[1] = 1;
	}
	if (v.bC > 0) {
		b[2] = 1;
	}
	if (v.bD > 0) {
		b[3] = 1;
	}
	if (v.bE > 0) {
		b[4] = 1;
	}
	if (v.bEF > 0) {
		b[5] = 1;
	}
	if (v.bT > 0) {
		b[6] = 1;
	}
	if (v.bDutch > 0) {
		b[7] = 1;
	}
	if (v.sA > 0) {
		b[8] = 1;
	}
	if (v.sB > 0) {
		b[9] = 1;
	}
	if (v.sC > 0) {
		b[10] = 1;
	}
	if (v.sD > 0) {
		b[11] = 1;
	}
	if (v.sE > 0) {
		b[12] = 1;
	}
	if (v.angel > 0) {
		b[13] = 1;
	}
	if (v.devil > 0) {
		b[14] = 1;
	}
	for (int i = 0; i < 15; i++) {
		if (b[i] == 1) {
			p = i + 1;
			i = 15;
		}
	}

	while (1) {
		system("cls");
		int o = 0;
		printf("\n\n\n\n");
		if (p == 0) {
			printf("å�� �����ϴ�. �������� å�� ������ ������.");
		}
		else {
			for (int i = p - 1; i > 0; i--) {
				if (b[i - 1] == 1) {
					o = 1;
				}
			}
			if (o == 1) {
				printf(" <  ");
			}
			else {
				printf("    ");
			}

			if (p == 1) {
				gotoxy(0, 0);
				printf("���� �� ������ ���縦 �Ǹ����� ���� ������ �����մϴ�.\n");
				printf("* ������ ���� �ǸŰ� %d�� > %d��\n", v.lvA, v.lvA + 1);
				printf("* ���� : %d��", v.bA);
				gotoxy(4, 4);
				printf("���� ���� �̷м�");
			}
			if (p == 2) {
				int incomeA = 15 + v.lvB * 12;
				int incomeB = 27 + v.lvB * 12;
				if (v.lvB == 0) {
					incomeA = 0;
					incomeB = 27;
				}
				gotoxy(0, 0);
				printf("���� �� ���� ������ �Ǹ����� ���� ������ �����մϴ�.\n");
				printf("* ���� ���� �ǸŰ� %d�� > %d��\n", incomeA, incomeB);
				printf("* ���� : %d��", v.bB);
				gotoxy(4, 4);
				printf("���� ���� ���ۼ�");
			}
			if (p == 3) {
				int incomeA = 200 + v.lvC * 150;
				int incomeB = 350 + v.lvC * 150;
				if (v.lvB == 0) {
					incomeA = 0;
					incomeB = 350;
				}
				gotoxy(0, 0);
				printf("���� �� ���� ������ �Ǹ����� ���� ������ �����մϴ�.\n");
				printf("* ���� ���� �ǸŰ� %d�� > %d��\n", incomeA, incomeB);
				printf("* ���� : %d��", v.bC);
				gotoxy(4, 4);
				printf("���� ���� ���ۼ�");
			}
			if (p == 4) {
				int incomeA = 1500 + v.lvD * 1000;
				int incomeB = 2500 + v.lvD * 1000;
				if (v.lvB == 0) {
					incomeA = 0;
					incomeB = 2500;
				}
				gotoxy(0, 0);
				printf("���� �� ���� ������ �Ǹ����� ���� ������ �����մϴ�.\n");
				printf("* ���� ���� �ǸŰ� %d�� > %d��\n", incomeA, incomeB);
				printf("* ���� : %d��", v.bD);
				gotoxy(4, 4);
				printf("���� ���� ���ۼ�");
			}
			if (p == 5) {
				int incomeA = 8000 + v.lvE * 6000;
				int incomeB = 14000 + v.lvE * 6000;
				if (v.lvB == 0) {
					incomeA = 0;
					incomeB = 14000;
				}
				gotoxy(0, 0);
				printf("���� �� ���� ���� �Ǹ����� ���� ������ �����մϴ�.\n");
				printf("* ���� �� �ǸŰ� %d�� > %d��\n", incomeA, incomeB);
				printf("* ���� : %d��", v.bE);
				gotoxy(4, 4);
				printf("���� �� ���� �̷м�");
			}
			if (p == 6) {
				gotoxy(0, 0);
				printf("���� �� �۾��� ȿ���� �����մϴ�.\n");
				printf("* �۾� ȿ�� +%d > +%d\n", v.ef, v.ef + 1);
				printf("* ���� : %d��", v.bEF);
				gotoxy(4, 4);
				printf("�۾� ȿ���� �̷м�");
			}
			if (p == 7) {
				gotoxy(0, 0);
				printf("���� �� ������ ������ ȿ���� �����մϴ�.\n");
				printf("* ���� ȿ�� : x1.5\n");
				printf("* ���� : %d��", v.bT);
				gotoxy(4, 4);
				printf("������� �̷м�");
			}
			if (p == 8) {
				gotoxy(0, 0);
				printf("���� �� ���Ͼ�� ��ȭ �� �� �ֽ��ϴ�.\n");
				printf("* ���� : %d��", v.bDutch);
				gotoxy(4, 4);
				printf("��ŵ� �� �� �ִ�! ���Ͼ� ȸȭ");
			}
			if (p >= 9 && p <= 13) {
				gotoxy(0, 0);
				printf("���� ������� �� ���� ���� ����å�Դϴ�.\n");
				printf("* ���� : %d��", 1);
				gotoxy(4, 4);
				printf("�Ҿ������ ���� ���� - %d��", p - 8);
			}
			if (p == 14) {
				gotoxy(0, 0);
				printf("���� �� �Ҽ��� ������ ��ȭ�˴ϴ�.\n");
				printf("* ���� : %d��", v.angel);
				gotoxy(4, 4);
				printf("����");
			}
			if (p == 15) {
				gotoxy(0, 0);
				printf("���� ��...\n");
				printf("* ���� : %d��", v.devil);
				gotoxy(4, 4);
				printf("���� å");
			}
			o = 0;
			for (int i = p + 1; i < 16; i++) {
				if (b[i - 1] == 1) {
					o = 1;
				}
			}
			if (o == 1) {
				printf("  > ");
			}
			else {
				printf("    ");
			}
		}
		printf("\n\n�б�\n�ڷΰ���");
		if (error == 1) { //Caps Lock Ȱ��ȭ
			gotoxy(0, 20);
			printf("Caps Lock�� Ǯ���ּ���.");
			error = 0;
		}
		else if (error == 2) { //��/��Ű ��ȯ
			gotoxy(0, 20);
			printf("��/��Ű�� �ٲ��ּ���.");
			error = 0;
		}
		if (s == 1) {
			gotoxy(5, 6);

		}
		else if (s == 2) {
			gotoxy(9, 7);

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
						if (s != 2) {
							s++;
						}
						break;
					case 75:
						o = 0;
						for (int i = p - 1; i > 0; i--) {
							if (b[i - 1] == 1) {
								o = i;
								i = 0;
							}
						}
						if (o != 0) {
							p = o;
						}
						break;
					case 77:
						o = 0;
						for (int i = p + 1; i < 16; i++) {
							if (b[i - 1] == 1) {
								o = i;
								i = 16;
							}
						}
						if (o != 0) {
							p = o;
						}
						break;
					}

					break;
				}
				else if (select == 'a') {
					if (s == 1) {
						int isEmpty = 0;
						if (p == 1) {
							v.lvA++;
							v.bA--;
							if (v.bA == 0) {
								isEmpty = 1;
							}
						}
						else if (p == 2) {
							v.lvB++;
							v.bB--;
							if (v.bB == 0) {
								isEmpty = 1;
							}
						}
						else if (p == 3) {
							v.lvC++;
							v.bC--;
							if (v.bC == 0) {
								isEmpty = 1;
							}
						}
						else if (p == 4) {
							v.lvD++;
							v.bD--;
							if (v.bD == 0) {
								isEmpty = 1;
							}
						}
						else if (p == 5) {
							v.lvE++;
							v.bE--;
							if (v.bE == 0) {
								isEmpty = 1;
							}
						}
						else if (p == 6) {
							v.ef++;
							v.bEF--;
							if (v.bEF == 0) {
								isEmpty = 1;
							}
						}
						else if (p == 7) {
							v.readed = 1;
							v.bT--;
							if (v.bT == 0) {
								isEmpty = 1;
							}
						}
						else if (p == 8) {
							v.dutch= 1;
							v.bDutch--;
							if (v.bDutch == 0) {
								isEmpty = 1;
							}
						}
						else if (p == 9) {
							bookA1();
							if (v.sA == 0) {
								isEmpty = 1;
							}
						}
						else if (p == 10) {
							bookB1();
							if (v.sB == 0) {
								isEmpty = 1;
							}
						}
						else if (p == 11) {
							bookC1();
							if (v.sC == 0) {
								isEmpty = 1;
							}
						}
						else if (p == 12) {
							bookD1();
							if (v.sD == 0) {
								isEmpty = 1;
							}
						}
						else if (p == 13) {
							bookE1();
							if (v.sE == 0) {
								isEmpty = 1;
							}
						}
						else if (p == 14) {
							if (v.clean == 0) {
								v.clean = 1;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
							}
							if (v.angel == 0) {
								isEmpty = 1;
							}
						}
						else if (p == 15) {
							if (v.clean == 1) {
								v.clean = 0;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
							}
							if (v.devil == 0) {
								isEmpty = 1;
							}
						}
						if (isEmpty == 1) {
							isEmpty = 0;
							b[p - 1] = 0;
							o = 0;
							for (int i = p + 1; i < 16; i++) {
								if (b[i - 1] == 1) {
									o = i;
									i = 16;
								}
							}
							if (o >= 1) {
								p = o;
							}
							else {
								for (int i = p - 1; i > 0; i--) {
									if (b[i - 1] == 1) {
										o = i;
										i = 0;
									}
								}
								if (o >= 1) {
									p = o;
								}
								else {
									p = 0;
								}
							}


						}
						break;
					}
					else if (s == 2) {
						return v;
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

var status(var a) {
	var v;
	v = a;
	system("cls");

	printf("�۾� �ɷ�\n\n");
	printf("���� ���� Lv.%d\n", v.lvA);
	printf("���� ���� ���� Lv.%d\n", v.lvB);
	printf("���� ���� ���� Lv.%d\n", v.lvC);
	printf("���� ���� ���� Lv.%d\n", v.lvD);
	printf("���� �� ���� Lv.%d\n", v.lvE);
	printf("�۾� ȿ�� Lv.%d\n\n", v.ef + a.effectB*2 + a.effectC + a.effectFin*1000);

	printf("���� ����\n\n");
	treeName(v.level);
	printf("Lv.%d\n", v.level);
	printf("%d / %d\n", v.xp, v.max_xp);
	printf("���Ե� ������ : %d��\n", v.druged);
	printf("������� : ");
	if (v.readed == 1) {
		printf("�н���\n���� ���� ȿ�� : x%g\n", (double)(v.druged + 1) * 1.5);
	}
	else {
		printf("�н����� ����\n���� ���� ȿ�� : x%g\n", (double)(v.druged + 1));
	}
	int level = 1 + v.shoes + v.effectB;
	if (v.effectFin == 1) {
		level = 999;
	}
	printf("\n�̵� �ӵ� Lv.%d\n", level);
	printf("\n�ƹ� Ű�� ���� �ڷΰ���");
	char c = NULL;
	c = _getch();
	return v;
}

var storage(var a) {
	var v;
	v = a;
	system("cls");

	printf("�۾���\n\n");
	printf("������ ���� : %d��\n", v.gA);
	printf("���� ���� : % d��\n", v.gB);
	printf("���� ���� : % d��\n", v.gC);
	printf("���� ���� : % d��\n", v.gD);
	printf("���� �� : % dä\n\n", v.gE);

	printf("���� ����ǰ\n\n");
	printf("��� : %d��\n", v.fer);
	printf("�� : %d / %d\n", v.water, v.max_water);
	printf("������ : %d��\n\n", v.drug);

	printf("�ڱ� : %d��\n", v.money);
	printf("\n�ƹ� Ű�� ���� �ڷΰ���");
	char c = NULL;
	c = _getch();
	return v;
}

var work(var a) {
	var v = a;
	int s = 1;
	int work = 0;
	int progress = 0;
	int max_progress = 1;
	int error = 0;


	char select = NULL;
	while (1) {
		system("cls");
		if (work == 0) {
			printf("f<   j");
		}
		else if (work == 1) {
			printf("f    j<");
		}
		if (s == 1) {
			printf("\n������ ���� : %d��", v.gA);
		}
		else if (s == 2) {
			printf("\n���� ���� : %d��", v.gB);
		}
		else if (s == 3) {
			printf("\n���� ���� : %d��", v.gC);
		}
		else if (s == 4) {
			printf("\n���� ���� : %d��", v.gD);
		}
		else if (s == 5) {
			printf("\n���� �� : %dä", v.gE);
		}
		else {
			printf("\n                  ");
		}
		printf("\n�۾� ȿ���� : Lv.%d", a.ef + a.effectB*2 + a.effectC + a.effectFin * 1000);
		printf("\n�۾� ���൵ : %d/%d\n\n", progress, max_progress);


		printf("���� ���� Lv.%d\n���� ���� ���� Lv.%d\n���� ���� ���� Lv.%d\n���� ���� ���� Lv.%d\n���� �� ���� Lv.%d\n������", a.lvA, a.lvB, a.lvC, a.lvD, a.lvE);
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
			gotoxy(7, 10);
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
						return v;
					}

				}
				else if (select == 'f') {
					if (work == 0) {
						if (s == 1) {
							progress += 1 + a.ef + a.effectB * 2 + a.effectC + a.effectFin * 1000;
						}
						if (s == 2 && v.lvB > 0) {
							progress += 1 + a.ef + a.effectB * 2 + a.effectC + a.effectFin * 1000;
						}
						else if (s == 3 && v.lvC > 0) {
							progress += 1 + a.ef + a.effectB * 2 + a.effectC + a.effectFin * 1000;
						}
						else if (s == 4 && v.lvD > 0) {
							progress += 1 + a.ef + a.effectB * 2 + a.effectC + a.effectFin * 1000;
						}
						else if (s == 5 && v.lvE > 0) {
							progress += 1 + a.ef + a.effectB * 2 + a.effectC + a.effectFin * 1000;
						}
						work = 1;
						if (progress >= max_progress) {
							if (s == 1) {
								v.gA++;
							}
							else if (s == 2) {
								v.gB++;
							}
							else if (s == 3) {
								v.gC++;
							}
							else if (s == 4) {
								v.gD++;
							}
							else if (s == 5) {
								v.gE++;
							}
							progress = 0;
						}
						break;
					}
				}
				else if (select == 'j') {
					if (work == 1) {
						if (s == 1) {
							progress += 1 + a.ef + a.effectB * 2 + a.effectC + a.effectFin * 1000;
						}
						else if (s == 2 && v.lvB > 0) {
							progress += 1 + a.ef + a.effectB * 2 + a.effectC + a.effectFin * 1000;
						}
						else if (s == 3 && v.lvC > 0) {
							progress += 1 + a.ef + a.effectB * 2 + a.effectC + a.effectFin * 1000;
						}
						else if (s == 4 && v.lvD > 0) {
							progress += 1 + a.ef + a.effectB * 2 + a.effectC + a.effectFin * 1000;
						}
						else if (s == 5 && v.lvE > 0) {
							progress += 1 + a.ef + a.effectB * 2 + a.effectC + a.effectFin * 1000;
						}
						work = 0;
						if (progress >= max_progress) {
							if (s == 1) {
								v.gA++;
							}
							else if (s == 2) {
								v.gB++;
							}
							else if (s == 3) {
								v.gC++;
							}
							else if (s == 4) {
								v.gD++;
							}
							else if (s == 5) {
								v.gE++;
							}
							progress = 0;
						}
						break;
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

var shop_items(var a) {
	var v = a;

	int s = 1;
	int error = 0;
	char select = NULL;

	while (1) {
		system("cls");
		printf("\n\n\n\n");
		printf("���\n��\n���Ѹ��� ����\n������\n������");
		printf("\n\n\n���� �� : %d��", v.money);
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
			printf("���� �����մϴ�.     ");
			error = 0;
		}
		else if (error == 4) {
			gotoxy(0, 18);
			printf("���̻� ������ �� �����ϴ�.");
			error = 0;
		}
		else {
			gotoxy(0, 18);
			printf("                                  ");
			error = 0;
		}
		if (s == 1) {
			gotoxy(0, 0);
			printf("���(%d��)\n������ ���嵵�� ���� �� �ֽ��ϴ�.\n���嵵 ����:70  �ʿ� �ڱ�:50��     s�� �ϰ� ����", v.fer);
			gotoxy(5, 4);
		}
		else if (s == 2) {
			gotoxy(0, 0);
			printf("��(%d/%d)\n������ ���嵵�� ���� �� �ֽ��ϴ�.\n���嵵 ����:1  �ʿ� �ڱ�:����", v.water, v.max_water);
			gotoxy(3, 5);
		}
		else if (s == 3) {
			gotoxy(0, 0);
			printf("���Ѹ��� ����(Lv.%d)\n���� �ִ� ���差�� ���Դϴ�.\n���Ѹ��� �뷮:%d > %d  �ʿ� �ڱ�:%d��", (v.max_water - 100) / 10, v.max_water, v.max_water + 10, 10 + v.max_water * 2);
			gotoxy(14, 6);
		}
		else if (s == 4) {
			gotoxy(0, 0);
			int sum = a.druged + v.drug;
			printf("������(%d��)\n������ ���嵵 ȿ���� ���Դϴ�.\n���嵵 ȿ�� ���� : x(���Ե� ������)  �ʿ� �ڱ�:%d��", v.drug, sum * sum * 5000 + 5000);

			gotoxy(7, 7);
		}
		else if (s == 5) {
			gotoxy(7, 8);
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
						if (s != 5) {
							s++;
						}
						break;
					}
					break;
				}
				else if (select == 'a') {
					if (s == 1) {
						if (v.money < 50) {
							error = 3;
						}
						else {
							v.money -= 50;
							v.fer++;
						}
						break;

					}
					else if (s == 2) {
						v.water = v.max_water;
						break;
					}
					else if (s == 3) {
						if (v.money < 10 + v.max_water * 2) {
							error = 3;
						}
						else {
							v.money -= 10 + v.max_water * 2;
							v.max_water += 10;
						}
						break;

					}
					else if (s == 4) {
						int sum = a.druged + v.drug;
						if (v.money < sum * sum * 5000 + 5000) {
							error = 3;
						}
						else {
							v.money -= sum * sum * 5000 + 5000;
							v.drug++;
						}
						break;

					}	
					else if (s == 5) {
						return v;
					}
				}
				else if (select == 'A') {
					error = 1;
					break;
				}
				else if (select == 's') {
					if (s == 1) {
						v.fer += v.money / 50;
						v.money = v.money % 50;

					}
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

var shop_books(var a) {

	var v = a;

	int s = 1;
	int error = 0;
	char select = NULL;
	while (1) {
		system("cls");
		printf("\n\n\n\n");
		printf("���� ���� �̷м�\n���� ���� ���ۼ�\n���� ���� ���ۼ�\n���� ���� ���ۼ�\n���� �� ���� �̷м�\n�۾� ȿ���� �̷м�\n������� �̷м�\n��ŵ� �� �� �ִ�! ���Ͼ� ȸȭ\n�Ҿ������ ���� ���� - 1��\n�Ҿ������ ���� ���� - 2��\n�Ҿ������ ���� ���� - 3��\n�Ҿ������ ���� ���� - 4��\n�Ҿ������ ���� ���� - 5��\n������");
		printf("\n\n\n���� �� : %d��", v.money);
		if (error == 1) { //Caps Lock Ȱ��ȭ
			gotoxy(0, 20);
			printf("Caps Lock�� Ǯ���ּ���.");
			error = 0;
		}
		else if (error == 2) { //��/��Ű ��ȯ
			gotoxy(0, 20);
			printf("��/��Ű�� �ٲ��ּ���.");
			error = 0;
		}
		else if (error == 3) {
			gotoxy(0, 20);
			printf("���� �����մϴ�.");
			error = 0;
		}
		else if (error == 4) {
			gotoxy(0, 20);
			printf("���̻� ���� �� �� �����ϴ�.");
			error = 0;
		}
		else if (error == 5) {
			gotoxy(0, 20);
			printf("���� ���� �� �� �����ϴ�.");
			error = 0;
		}
		if (s == 1) {
			gotoxy(0, 0);
			int sum = v.lvA + v.bA;

			printf("���� ���� �̷м�(���:%d)\n���� ������ ���� �ɷ��� Ű��ϴ�.\n���� Lv.%d  �ʿ� �ڱ�:%d��", 100 - sum, v.lvA, 10 + sum * 11);
			gotoxy(17, 4);
		}
		else if (s == 2) {
			int sum = v.lvB + v.bB;
			gotoxy(0, 0);
			printf("���� ���� ���ۼ�(���:%d)\n���� ���� ���ۿ� ���� �ɷ��� Ű��ϴ�.\n���� Lv.%d  �ʿ� �ڱ�:%d��  �ʿ� ����:���� ���� �̷� Lv.%d", 100 - sum, v.lvB, 26 + sum * 13, 50);
			gotoxy(17, 5);
		}
		else if (s == 3) {
			gotoxy(0, 0);
			int sum = v.lvC + v.bC;
			printf("���� ���� ���ۼ�(���:%d)\n���� ���� ���ۿ� ���� �ɷ��� Ű��ϴ�.\n���� Lv.%d  �ʿ� �ڱ�:%d��  �ʿ� ����:���� ���� ���� Lv.%d", 100 - sum, v.lvC, 52 + sum * 44, 50);
			gotoxy(17, 6);
		}
		else if (s == 4) {
			gotoxy(0, 0);
			int sum = v.lvD + v.bD;
			printf("���� ���� ���ۼ�(���:%d)\n���� ���� ���ۿ� ���� �ɷ��� Ű��ϴ�.\n���� Lv.%d  �ʿ� �ڱ�:%d��  �ʿ� ����:���� ���� ���� Lv.%d", 100 - sum, v.lvD, 189 + sum * 171, 50);
			gotoxy(17, 7);
		}
		else if (s == 5) {
			gotoxy(0, 0);
			int sum = v.lvE + v.bE;
			printf("���� �� ���� �̷м�(���:%d)\n���� �� ���࿡ ���� �ɷ��� Ű��ϴ�.\n���� Lv.%d  �ʿ� �ڱ�:%d��  �ʿ� ����:���� ���� ���� Lv.%d", 100 - sum, v.lvE, 360 + sum * 232, 50);
			gotoxy(20, 8);
		}
		else if (s == 6) {
			gotoxy(0, 0);
			int sum = v.ef + v.bEF;
			printf("�۾� ȿ���� �̷м�(���:%d)\n�۾��� ȿ������ Ű��ϴ�.\n���� Lv.%d  �ʿ� �ڱ�:%d��", 10 - sum, v.ef, 10000 + 2500 * (v.bEF + v.ef) * (v.bEF + v.ef));
			gotoxy(19, 9);
		}
		else if (s == 7) {
			gotoxy(0, 0);
			printf("������� �̷м�(���:%d)\n������ ���� ȿ���� ���� �� �ֽ��ϴ�.\n���嵵 ���� : x1.5  �ʿ� �ڱ�:10500��", 1 - v.bT - v.readed);
			gotoxy(16, 10);
		}
		else if (s == 8) {
			gotoxy(0, 0);
			printf("��ŵ� �� �� �ִ�! ���Ͼ� ȸȭ(���:%d)\n���Ͼ ��� �� �ֽ��ϴ�. ������� �ǹ̴� ������ ������, ���� �����̶� ��ȭ�� �� �� �ְڳ׿�.\n�ʿ� �ڱ�:30000��", 1 - v.bDutch - v.dutch);
			gotoxy(31, 11);
		}
		else if (s == 9) {
			gotoxy(0, 0);
			printf("�Ҿ������ ���� ���� - 1��(���:%d)\n������ �����ִ� ����å�Դϴ�. ���� ������� �� ������ �ʳ׿�.\n�ʿ� �ڱ�:5000��", 1 - v.sA);
			gotoxy(27, 12);
		}
		else if (s == 10) {
			gotoxy(0, 0);
			printf("�Ҿ������ ���� ���� - 2��(���:%d)\n������ �����ִ� ����å�Դϴ�. ���� ������� �� ������ �ʳ׿�.\n�ʿ� �ڱ�:5000��", 1 - v.sB);
			gotoxy(27, 13);
		}
		else if (s == 11) {
			gotoxy(0, 0);
			printf("�Ҿ������ ���� ���� - 3��(���:%d)\n������ �����ִ� ����å�Դϴ�. ���� ������� �� ������ �ʳ׿�.\n�ʿ� �ڱ�:5000��", 1 - v.sC);
			gotoxy(27, 14);
		}
		else if (s == 12) {
			gotoxy(0, 0);
			printf("�Ҿ������ ���� ���� - 4��(���:%d)\n������ �����ִ� ����å�Դϴ�. ���� ������� �� ������ �ʳ׿�.\n�ʿ� �ڱ�:5000��", 1 - v.sD);
			gotoxy(27, 15);
		}
		else if (s == 13) {
			gotoxy(0, 0);
			printf("�Ҿ������ ���� ���� - 5��(���:%d)\n������ �����ִ� ����å�Դϴ�. ���� ������� �� ������ �ʳ׿�.\n�ʿ� �ڱ�:5000��", 1 - v.sE);
			gotoxy(27, 16);
		}
		else if (s == 14) {
			gotoxy(7, 17);
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
						if (s != 14) {
							s++;

						}
						break;
					}
					break;
				}
				else if (select == 'a') {
					if (s == 1) {
						if (v.lvA + v.bA == 100) {
							error = 4;
							break;
						}
						else if (v.money < 10 + (v.bA + v.lvA) * 11) {
							error = 3;
							break;
						}
						else {
							v.money -= 10 + (v.bA + v.lvA) * 11;
							v.bA++;
							break;
						}
					}
					else if (s == 2) {
						if (v.lvA < 50) {
							error = 5;
							break;
						}
						else if (v.lvB + v.bB == 100) {
							error = 4;
							break;
						}
						else if (v.money < 26 + (v.bB + v.lvB) * 13) {
							error = 3;
							break;
						}
						else {
							v.money -= 26 + (v.bB + v.lvB) * 13;
							v.bB++;
							break;
						}
					}
					else if (s == 3) {
						if (v.lvB < 50) {
							error = 5;
							break;
						}
						else if (v.lvC + v.bC == 100) {
							error = 4;
							break;
						}
						else if (v.money < 52 + (v.lvC + v.bC) * 44) {
							error = 3;
							break;
						}
						else {
							v.money -= 52 + (v.lvC + v.bC) * 44;
							v.bC++;
							break;
						}
					}
					else if (s == 4) {
						if (v.lvC < 50) {
							error = 5;
							break;
						}
						else if (v.lvD + v.bD == 100) {
							error = 4;
							break;
						}
						else if (v.money < 189 + (v.lvD + v.bD) * 171) {
							error = 3;
							break;
						}
						else {
							v.money -= 189 + (v.lvD + v.bD) * 171;
							v.bD++;
							break;
						}
					}
					else if (s == 5) {
						if (v.lvD < 50) {
							error = 5;
							break;
						}
						else if (v.lvE + v.bE == 100) {
							error = 4;
							break;
						}
						else if (v.money < 360 + (v.lvE + v.bE) * 232) {
							error = 3;
							break;
						}
						else {
							v.money -= 360 + (v.lvE + v.bE) * 232;
							v.bE++;
							break;
						}
					}
					else if (s == 6) {
						if (v.ef + v.bEF == 10) {
							error = 4;
							break;
						}
						else if (v.money < 10000 + 2500 * (v.bEF + v.ef) * (v.bEF + v.ef)) {
							error = 3;
							break;
						}
						else {
							v.money -= 10000 + 2500 * (v.bEF + v.ef) * (v.bEF + v.ef);
							v.bEF++;
							break;
						}
					}
					else if (s == 7) {
						if (v.money < 10500) {
							error = 3;
							break;
						}
						else if (v.readed + v.bT == 1) {
							error = 4;
							break;
						}
						else {
							v.money -= 10500;
							v.bT++;
							break;
						}
					}
					else if (s == 8) {
						if (v.money < 30000) {
							error = 3;
							break;
						}
						else if (v.dutch + v.bDutch == 1) {
							error = 4;
							break;
						}
						else {
							v.money -= 30000;
							v.bDutch++;
							break;
						}
					}
					else if (s == 9) {
						if (v.money < 5000) {
							error = 3;
							break;
						}
						else if (v.sA == 1) {
							error = 4;
							break;
						}
						else {
							v.money -= 5000;
							v.sA++;
							break;
						}
					}
					else if (s == 10) {
						if (v.money < 5000) {
							error = 3;
							break;
						}
						else if (v.sB == 1) {
							error = 4;
							break;
						}
						else {
							v.money -= 5000;
							v.sB++;
							break;
						}
					}
					else if (s == 11) {
						if (v.money < 5000) {
							error = 3;
							break;
						}
						else if (v.sC == 1) {
							error = 4;
							break;
						}
						else {
							v.money -= 5000;
							v.sC++;
							break;
						}
					}
					else if (s == 12) {
						if (v.money < 5000) {
							error = 3;
							break;
						}
						else if (v.sD == 1) {
							error = 4;
							break;
						}
						else {
							v.money -= 5000;
							v.sD++;
							break;
						}
					}
					else if (s == 13) {
						if (v.money < 5000) {
							error = 3;
							break;
						}
						else if (v.sE == 1) {
							error = 4;
							break;
						}
						else {
							v.money -= 5000;
							v.sE++;
							break;
						}
					}
					else if (s == 14) {
						return v;
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

var sell(var a) {
	var v = a;

	int s = 1;
	int error = 0;
	char select = NULL;

	while (1) {
		system("cls");
		printf("\n\n\n\n");
		printf("������ ���� �Ǹ�\n���� ���� �Ǹ�\n���� ���� �Ǹ�\n���� ���� �Ǹ�\n���� �� �Ǹ�\n������");
		printf("\n\n\n���� �� : %d��", v.money);
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
			printf("��ǰ�� �����ϴ�.");
			error = 0;
		}
		if (s == 1) {
			gotoxy(0, 0);
			printf("������ ����\n���� : %d  ���� : %d\na�� 1���� �Ǹ�, s�� �ϰ� �Ǹ�", v.gA, a.lvA + a.effectD * 1000);
			gotoxy(17, 4);
		}
		else if (s == 2) {
			gotoxy(0, 0);
			printf("���� ����\n���� : %d  ���� : %d\na�� 1���� �Ǹ�, s�� �ϰ� �Ǹ�", v.gB, 15 + a.lvB * 12 + a.effectD * 1000);
			gotoxy(15, 5);
		}
		else if (s == 3) {
			gotoxy(0, 0);
			printf("���� ����\n���� : %d  ���� : %d\na�� 1���� �Ǹ�, s�� �ϰ� �Ǹ�", v.gC, 200 + a.lvC * 150 + a.effectD * 1000);
			gotoxy(15, 6);
		}
		else if (s == 4) {
			gotoxy(0, 0);
			printf("���� ����\n���� : %d  ���� : %d\na�� 1���� �Ǹ�, s�� �ϰ� �Ǹ�", v.gD, 1500 + a.lvD * 1000 + a.effectD * 1000);
			gotoxy(15, 7);
		}
		else if (s == 5) {
			gotoxy(0, 0);
			printf("���� ��\n���� : %d  ���� : %d\na�� 1ä�� �Ǹ�, s�� �ϰ� �Ǹ�", v.gE, 8000 + a.lvE * 6000 + a.effectD * 1000);
			gotoxy(13, 8);
		}
		else if (s == 6) {
			gotoxy(7, 9);

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
						if (s != 6) {
							s++;
						}
						break;
					}
					break;
				}
				else if (select == 'a') {
					if (s == 1) {
						if (v.gA < 1) {
							error = 3;
						}
						else {
							v.gA--;
							v.money += a.lvA + a.effectD * 1000;
						}
						break;

					}
					else if (s == 2) {
						if (v.gB < 1) {
							error = 3;
						}
						else {
							v.gB--;
							v.money += 15 + a.lvB * 12 + a.effectD * 1000;
						}
						break;
					}
					else if (s == 3) {
						if (v.gC < 1) {
							error = 3;
						}
						else {
							v.gC--;
							v.money += 200 + a.lvC * 150 + a.effectD * 1000;
						}
						break;

					}
					else if (s == 4) {
						if (v.gD < 1) {
							error = 3;
						}
						else {
							v.gD--;
							v.money += 1500 + a.lvD * 1000 + a.effectD * 1000;
						}
						break;

					}
					else if (s == 5) {
						if (v.gE < 1) {
							error = 3;
						}
						else {
							v.gE--;
							v.money += 8000 + a.lvE * 6000 + a.effectD * 1000;
						}
						break;

					}
					else if (s == 6) {
						return v;
					}
				}
				else if (select == 'A') {
					error = 1;
					break;
				}
				else if (select == 's') {
					if (s == 1) {
						v.money += v.gA * (a.lvA);
						v.gA = 0;
					}
					else if (s == 2) {
						v.money += v.gB * (15 + a.lvB * 12);
						v.gB = 0;
					}
					else if (s == 3) {
						v.money += v.gC * (200 + a.lvC * 150);
						v.gC = 0;
					}
					else if (s == 4) {
						v.money += v.gD * (1500 + a.lvD * 1000);
						v.gD = 0;
					}
					else if (s == 5) {
						v.money += v.gE * (8000 + a.lvE * 6000);
						v.gE = 0;
					}
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

var tree(var a) {
	var v = a;

	int s = 1;
	int error = 0;
	char select = NULL;
	while (1) {
		system("cls");
		treeName(v.level);
		if (v.level >= 20 && v.level20 == 0) {
			evA1();
			v.level20 = 1;
			return v;
		}
		if (v.level >= 40 && v.level40 == 0) {
			evB1();
			v.level40 = 1;
			return v;
		}
		if (v.level >= 60 && v.level60 == 0) {
			evC1();
			v.level60 = 1;
			return v;
		}
		if (v.level >= 80 && v.level80 == 0) {
			evD1();
			v.level80 = 1;
			return v;
		}
		if (v.level >= 100 && v.clear == 0) {
			ending();
			v.clear = 1;
			return v;
		}
		printf("%d�ܰ� ����\n���嵵 %d/%d\n���� ȿ��:(������:%d, �������:", v.level, v.xp, v.max_xp, v.druged);
		if (v.readed == 1) {
			printf("�н���) x%g\n\n\n", (double)(v.druged + 1) * 1.5);
		}
		else {
			printf("�н����� ����) x%d\n\n\n", v.druged + 1);
		}
		printf("�� �ֱ�\n��� �ֱ�\n������ ����\n");
		if (v.level < 20) {
			printf("?????????\n");
		}
		else {
			printf("�ູ ����\n");
		}
		printf("������");
		if (error == 1) { //Caps Lock Ȱ��ȭ
			gotoxy(0, 20);
			printf("Caps Lock�� Ǯ���ּ���.");
			error = 0;
		}
		else if (error == 2) { //��/��Ű ��ȯ
			gotoxy(0, 20);
			printf("��/��Ű�� �ٲ��ּ���.");
			error = 0;
		}
		else if (error == 3) {
			gotoxy(0, 20);
			printf("��ᰡ �����մϴ�.");
			error = 0;
		}
		else if (error == 4) {
			gotoxy(0, 20);
			printf("���� �����մϴ�.");
			error = 0;
		}
		else if (error == 5) {
			gotoxy(0, 20);
			printf("�������� �����մϴ�.");
			error = 0;
		}
		else if (error == 6) {
			gotoxy(0, 20);
			printf("���� ������ ����� �������� �ʾҽ��ϴ�.");
		}

		if (s == 1) {
			gotoxy(0, 12);
			printf("��\n�ܿ�:%d/%d\n���嵵 ����:1\ns�� ��� �ֱ�", v.water, v.max_water);
			gotoxy(8, 6);
		}
		else if (s == 2) {
			gotoxy(0, 12);
			printf("���\n����:%d��\n���嵵 ����:70\ns�� 10���� �ֱ�\nd�� 100���� �ֱ�", v.fer);
			gotoxy(10, 7);
		}
		else if (s == 3) {
			gotoxy(0, 12);
			printf("������\n����:%d��\n���� ȿ�� ����", v.drug);
			gotoxy(12, 8);
		}
		else if (s == 4) {
			gotoxy(0, 12);
			if (v.level < 20) {
				printf("???");
			}
			else {
				printf("������ ���մ� ������ �����մϴ�.");
			}
			gotoxy(12, 9);
		}
		else if (s == 5) {
			gotoxy(7, 10);
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
						if (s != 5) {
							s++;

						}
						break;
					}
					break;
				}
				else if (select == 'a') {
					if (s == 1) {
						if (v.water == 0) {
							error = 4;
							break;
						}
						else {
							int amount = 1 * (v.druged + 1);
							if (a.readed == 1) {
								amount *= 1.5;
							}
							v.xp += amount;
							if (v.effectA == 1) {
								v.xp += 20;
							}
							if (v.effectC == 1) {
								v.xp += 20;
							}
							v.water--;
							break;
						}
					}
					else if (s == 2) {
						if (v.fer == 0) {
							error = 3;
							break;
						}
						else {
							int amount = 70 * (v.druged + 1);
							if (a.readed == 1) {
								amount *= 1.5;
							}
							v.xp += amount;
							if (v.effectA == 1) {
								v.xp += 20;
							}
							if (v.effectC == 1) {
								v.xp += 20;
							}
							v.fer--;
							break;
						}
					}
					else if (s == 3) {
						if (v.drug == 0) {
							error = 5;
							break;
						}
						else {
							v.druged++;
							v.drug--;
							break;
						}
					}
					else if (s == 4) {
						if (v.level < 20) {
							error = 6;
							break;
						}
						else {
							var tmp = effect(v);
							v.effectA = tmp.effectA;
							v.effectB = tmp.effectB;
							v.effectC = tmp.effectC;
							v.effectD = tmp.effectD;
							v.effectFin = tmp.effectFin;
							break;
						}
					}
					else if (s == 5) {
						return v;
					}
				}
				else if (select == 'A') {
					error = 1;
					break;
				}
				else if (select == 's') {
					if (s == 1) {
						if (v.water == 0) {
							error = 4;
							break;
						}
						else {
							int amount = v.water * (v.druged + 1);
							if (a.readed == 1) {
								amount *= 1.5;
							}
							v.xp += amount;
							if (v.effectA == 1) {
								v.xp += v.water * 20;
							}
							if (v.effectC == 1) {
								v.xp += v.water * 20;
							}
							v.water = 0;
							break;
						}
					}
					else if (s == 2) {
						if (v.fer < 10) {
							error = 3;
							break;
						}
						else {
							int amount = 700 * (v.druged + 1);
							if (a.readed == 1) {
								amount *= 1.5;
							}
							v.xp += amount;
							if (v.effectA == 1) {
								v.xp += 200;
							}
							if (v.effectC == 1) {
								v.xp += 200;
							}
							v.fer -= 10;
							break;
						}
					}
				}
				else if (select == 'd') {
					if (s == 2) {
						if (v.fer < 100) {
							error = 3;
							break;
						}
						else {
							int amount = 7000 * (v.druged + 1);
							if (a.readed == 1) {
								amount *= 1.5;
							}
							v.fer -= 100;
							v.xp += amount;
							if (v.effectA == 1) {
								v.xp += 2000;
							}
							if (v.effectC == 1) {
								v.xp += 2000;
							}
							break;
						}
					}
				}
				else if (select < 0 || select > 126) {
					error = 2;
					break;
				}
			}
		}
		while (v.xp >= v.max_xp) {
			v.xp -= v.max_xp;
			v.level++;
			if (v.level < 20) {
				v.max_xp += 120;
			}
			else if (v.level < 40) {
				v.max_xp += 260;
			}
			else if (v.level < 60) {
				v.max_xp += 540;
			}
			else if (v.level < 80) {
				v.max_xp += 720;
			}
			else if (v.level < 99) {
				v.max_xp += 1300;
			}
			else if (v.level == 99) {
				v.max_xp += 50000;
			}
			else {
				v.max_xp += 1000;
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
	else if (lv < 100) {
		printf("�ϴ��� �ձ� ������ �����");
	}
	else {
		printf("�ϴ��� �վ �����");
	}
	printf("\n");
}

var effect(var a) {
	var v = a;

	int s = 1;
	int error = 0;
	char select = NULL;

	while (1) {
		system("cls");
		printf("\n\n\n\n");
		if (v.level >= 20) {
			printf("������ �ູ  ");
			if (v.effectA == 1) {
				printf("Ȱ��ȭ");
			}
			else {
				printf("��Ȱ��ȭ");
			}
			printf("\n");
		}
		if (v.level >= 40) {
			printf("����� ���  ");
			if (v.effectB == 1) {
				printf("Ȱ��ȭ");
			}
			else {
				printf("��Ȱ��ȭ");
			}
			printf("\n");
		}
		else {
			printf("??????????\n");
		}
		if (v.level >= 60) {
			printf("������ �ູ 2  ");
			if (v.effectC == 1) {
				printf("Ȱ��ȭ");
			}
			else {
				printf("��Ȱ��ȭ");
			}
			printf("\n");
		}
		else {
			printf("????????????\n");
		}
		if (v.level >= 80) {
			printf("������� ��ȣ  ");
			if (v.effectD == 1) {
				printf("Ȱ��ȭ");
			}
			else {
				printf("��Ȱ��ȭ");
			}
			printf("\n");
		}
		else {
			printf("?????????????\n");
		}
		if (v.level >= 100) {
			printf("�ʿ��� ��  ");
			if (v.effectFin == 1) {
				printf("Ȱ��ȭ");
			}
			else {
				printf("��Ȱ��ȭ");
			}
			printf("\n");
		}
		else {
			printf("???????\n");
		}
		printf("������");
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
			printf("������ ���� ����� �������� �ʾҽ��ϴ�.");
			error = 0;
		}
		else if (error == 4) {
			return v;
		}
		if (s == 1) {
			gotoxy(0, 0);
			printf("������ ������ �� 20��ŭ �߰� ������ �մϴ�.(�������� ������� �̷��� ������ ���� �ʽ��ϴ�.)\n���� ����ġ Lv.20���� �ر�");
			gotoxy(22, 4);
		}
		else if (s == 2) {
			gotoxy(0, 0);
			if (v.level >= 40) {
				printf("�۾� ȿ���� 2 �����մϴ�. ���� ������ �̵��ϴ� �ӵ��� �����մϴ�.\n���� ����ġ Lv.40���� �ر�");
			}

			gotoxy(22, 5);
		}
		else if (s == 3) {
			gotoxy(0, 0);
			if (v.level >= 60) {
				printf("������ ������ �� 20��ŭ �߰� ������ �մϴ�.(�������� ������� �̷��� ������ ���� �ʽ��ϴ�.) ���� �۾� ȿ���� 1 �����մϴ�.\n���� ����ġ Lv.60���� �ر�");
			}

			gotoxy(24, 6);
		}
		else if (s == 4) {
			gotoxy(0, 0);
			if (v.level >= 80) {
				printf("���� ��ǰ �Ǹ� �� ���� 1000���� �߰��� ����ϴ�.\n���� ����ġ Lv.80���� �ر�");
			}

			gotoxy(24, 7);
		}
		else if (s == 5) {
			gotoxy(0, 0);
			if (v.level >= 100) {
				printf("�۾� ȿ���� 1000 �����ϸ� �����̵��� �� �� �ֽ��ϴ�.\n���� ����ġ Lv.100���� �ر�");
			}

			gotoxy(20, 8);
		}
		else if (s == 6) {
			gotoxy(7, 9);

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
						if (s != 6) {
							s++;
						}
						break;
					}
					break;
				}
				else if (select == 'a') {
					if (s == 1) {
						if (v.level < 20) {
							error = 3;
						}
						else {
							v.effectA = 1 - v.effectA;
						}
						break;

					}
					else if (s == 2) {
						if (v.level < 40) {
							error = 3;
						}
						else {
							v.effectB = 1 - v.effectB;
						}
						break;
					}
					else if (s == 3) {
						if (v.level < 60) {
							error = 3;
						}
						else {
							v.effectC = 1 - v.effectC;
						}
						break;

					}
					else if (s == 4) {
						if (v.level < 80) {
							error = 3;
						}
						else {
							v.effectD = 1 - v.effectD;
						}
						break;

					}
					else if (s == 5) {
						if (v.level < 100) {
							error = 3;
						}
						else {
							v.effectFin = 1 - v.effectFin;
						}
						break;

					}
					else if (s == 6) {
						return v;
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

void ending() {
	char y;
	system("cls");
	ending2();
	printf("\n�̾߱�� �������� ������ ����� �� �ֽ��ϴ�.\n�ƹ� Ű�� ���� ���");
	y = _getch();

}

void ending2() {
	char y = NULL;
	int max_pharase = 32;
	for (int i = 1; i < max_pharase + 1; i++) {

		system("cls");
		ending3(i);
		y = _getch();

	}

}
void ending3(int num) {
	if (num > 0) {
		printf(".\n");
	}
	if (num > 1) {
		printf(".\n");
	}
	if (num > 2) {
		printf("���� �⸥ ����.. �ƴ� ������� �ϴ��� �վ���.\n");
	}
	if (num > 3) {
		printf("....\n");
	}
	if (num > 4) {
		printf("�Ƹ����.\n");
	}
	if (num > 5) {
		printf("�� �տ� �� �� �׷��� ������� �� ��ü�����ε� ������ ���¸� ���̰� �־���.\n");
	}
	if (num > 6) {
		printf(".\n");
	}
	if (num > 7) {
		printf(".\n");
	}
	if (num > 8) {
		printf("������� �����ϱ�, �츮 ������ �޼ӵ��� �����ϱ� �����ߴ�.\n");
	}
	if (num > 9) {
		printf("������� ���� ������ ����������, Ȳ���غ����� ���� �ֺ� ȯ�浵 Ǯ�� ������ �Ƹ��ٿ�����.\n");
	}
	if (num > 10) {
		printf(".\n");
	}
	if (num > 11) {
		printf(".\n");
	}
	if (num > 12) {
		printf("�ϴ��� �վ �� �׷��� ����� ���� ���� �� ���� ������ �����Դ�.\n");
	}
	if (num > 13) {
		printf("���� ǥ���� �� ���� �� ����, ��ġ �ϳ��� ���������� ���Ҵ�.\n");
	}
	if (num > 14) {
		printf("�� �������� ���� ���� �Ǿ���, ���� �� ������ ��� ������ ������ �� �־���.\n");
	}
	if (num > 15) {
		printf(".\n");
	}
	if (num > 16) {
		printf(".\n");
	}
	if (num > 17) {
		printf("���� ������ ��� ���� ����, ���� ������ ã�ư��� ���� ���� ����ߴ�.\n");
	}
	if (num > 18) {
		printf("���� ������ ���� ���� �Ƹ���� ������ �ڿ��� ��������.\n");
	}
	if (num > 19) {
		printf("�ڿ��� ȸ���� �� ������ ���� ������ ������ ��¦ ���ư� ������� ���ߴ�. ��ġ, 1�ô�͵� ���Ҵ�.\n");
	}
	if (num > 20) {
		printf("�׷��� ������ ���ݱ����� ����� ũ�� �ٲ����, ������� ���� ������ �ϴ��� ���� ��, �� ������ �� 3�ô��� �θ��� �����ߴ�.\n");
	}
	if (num > 21) {
		printf("�� 3�ô��� �η��� 2�ô뺸�� �ξ� �����߰�, 1�ô��� �Ǽ��� �ݺ����� �ʾҴ�.\n");
	}
	if (num > 22) {
		printf("�� �ſ� ������������.\n");
	}
	if (num > 23) {
		printf(".\n");
	}
	if (num > 24) {
		printf(".\n");
	}
	if (num > 25) {
		printf("�� ��� ���� ����� ��������ϴ�.\n");
	}
	if (num > 26) {
		printf("��, ��� ���̿���. �� ���� ���.\n");
	}
	if (num > 27) {
		printf("�� ������ ������ ����� �װ�, ����� �츱 �ذ���.\n");
	}
	if (num > 28) {
		printf("������ ��� �� ������ ������� ������ ���⼭ ��� ���� �������� ���ڳ׿�.\n");
	}
	if (num > 29) {
		printf(".\n");
	}
	if (num > 30) {
		printf(".\n");
	}
	if (num > 31) {
		printf("~~fin~~\n");
	}
	if (num > 32) {
		printf("\n");
	}
}

void bookA1() {
	char y = NULL;
	int max_pharase = 12;
	for (int i = 1; i < max_pharase + 1; i++) {

		system("cls");
		bookA2(i);
		y = _getch();

	}

}
void bookA2(int num) {
	if (num > 0) {
		printf("~�Ҿ������ ���� ���� 01~\n");
	}
	if (num > 1) {
		printf(".\n");
	}
	if (num > 2) {
		printf(".\n");
	}
	if (num > 3) {
		printf("�� 1�ô� 2043�� 7�� 12��\n");
	}
	if (num > 4) {
		printf("���� 3�� ������ �߹��Ͽ���.\n");
	}
	if (num > 5) {
		printf("�� ���� �α��� ���� �̻� �׾����,\n");
	}
	if (num > 6) {
		printf("��ȸ �ý����� ����� �� ������.\n");
	}
	if (num > 7) {
		printf("�������� Ȳ��ȭ���� ���� ���� ã�ƺ� �� ������.\n");
	}
	if (num > 8) {
		printf("�׷��� ������ ���� ��̴� ������ �ʾҴ�.\n");
	}
	if (num > 9) {
		printf(".\n");
	}
	if (num > 10) {
		printf(".\n");
	}
	if (num > 11) {
		printf(".\n");
	}
	if (num > 12) {
		printf("\n");
	}
}

void bookB1() {
	char y = NULL;
	int max_pharase = 12;
	for (int i = 1; i < max_pharase + 1; i++) {

		system("cls");
		bookB2(i);
		y = _getch();

	}

}
void bookB2(int num) {
	if (num > 0) {
		printf("~�Ҿ������ ���� ���� 02~\n");
	}
	if (num > 1) {
		printf(".\n");
	}
	if (num > 2) {
		printf(".\n");
	}
	if (num > 3) {
		printf("�� 1�ô� 2065�� 2�� 26��\n");
	}
	if (num > 4) {
		printf("���� ������ ���� ����. \n");
	}
	if (num > 5) {
		printf("������ �� ������ ��� �׾���ȱ� �����̿���.\n");
	}
	if (num > 6) {
		printf("�����ִ� �η��� ���� ������ 20%% ���̿���.\n");
	}
	if (num > 7) {
		printf("������ ����� ���ǵǾ���.\n");
	}
	if (num > 8) {
		printf("�̹� ������ ���� ����ߴ�.\n");
	}
	if (num > 9) {
		printf(".\n");
	}
	if (num > 10) {
		printf(".\n");
	}
	if (num > 11) {
		printf(".\n");
	}
	if (num > 12) {
		printf("\n");
	}
}

void bookC1() {
	char y = NULL;
	int max_pharase = 15;
	for (int i = 1; i < max_pharase + 1; i++) {

		system("cls");
		bookC2(i);
		y = _getch();

	}

}
void bookC2(int num) {
	if (num > 0) {
		printf("~�Ҿ������ ���� ���� 03~\n");
	}
	if (num > 1) {
		printf(".\n");
	}
	if (num > 2) {
		printf(".\n");
	}
	if (num > 3) {
		printf("�� 1�ô� 2066�� 6�� 7��, �� 2�ô� 1�� 1�� 1��\n");
	}
	if (num > 4) {
		printf("�׷��� �η��� ���߰�, �����ִ� �η��� �������� ���ư��� ���� ü�踦 Ȯ���ߴ�.\n");
	}
	if (num > 5) {
		printf("�� �������� ��Ƴ��� ������� ��ǥ�� �̾Ұ�,\n");
	}
	if (num > 6) {
		printf("��ü������ ������ ����� ��Ե� ��Ƴ�����.\n");
	}
	if (num > 7) {
		printf(".\n");
	}
	if (num > 8) {
		printf(".\n");
	}
	if (num > 9) {
		printf("��� ��, ��� ��ǥ�� �� ���� �ǵ����� ���� ȸ�Ǹ� �Ͽ���.\n");
	}
	if (num > 10) {
		printf("�׷��� ��� ��ǥ���� ���� ù ȸ�ǰ� ���۵� ��, \n");
	}
	if (num > 11) {
		printf("�� ���� �� 2�ô��� 1�� 1�� 1�� �̶� Ī�Ͽ���.\n");
	}
	if (num > 12) {
		printf(".\n");
	}
	if (num > 13) {
		printf(".\n");
	}
	if (num > 14) {
		printf(".\n");
	}
	if (num > 15) {
		printf("\n");
	}
}

void bookD1() {
	char y = NULL;
	int max_pharase = 17;
	for (int i = 1; i < max_pharase + 1; i++) {

		system("cls");
		bookD2(i);
		y = _getch();

	}

}
void bookD2(int num) {
	if (num > 0) {
		printf("~�Ҿ������ ���� ���� 04~\n");
	}
	if (num > 1) {
		printf(".\n");
	}
	if (num > 2) {
		printf(".\n");
	}
	if (num > 3) {
		printf("�� 2�ô� 3�� 6�� 3��\n");
	}
	if (num > 4) {
		printf("Ȳ��ȭ�� �ڿ����� �����ϱ� ���� �� ����� �𿴴�..\n");
	}
	if (num > 5) {
		printf("�� ���� ��������� �����ϴ� ����,\n");
	}
	if (num > 6) {
		printf("�ٸ� �� ���� �������� ����� ������ ū �⿩�� �ߴ� ������,\n");
	}
	if (num > 7) {
		printf("������ �� ���� ������ ���� ����� �����ڿ���.\n");
	}
	if (num > 8) {
		printf("�׵��� �߽����� ���� ���������� ������ ȯ���� �����ϱ� ���� ����Ͽ���,\n");
	}
	if (num > 9) {
		printf("�� �������� �����ڰ� ������ ������ �ϳ� ���������.\n");
	}
	if (num > 10) {
		printf("������ �߽��� �� �Ŵ��� ����, �ϸ� ������� Ű�������μ�\n");
	}
	if (num > 11) {
		printf("���� ��ü�� ȯ���� ����ȭ���ڴ� �������� ���۵Ǿ�����,\n");
	}
	if (num > 12) {
		printf("������ Ű������ �� �� ������� �ں����� ���� ����Ǿ���.\n");
	}
	if (num > 13) {
		printf("������ ���� �߰����� ������ ���� �ڷ�ǿ� �����Ǿ���.\n");
	}
	if (num > 14) {
		printf(".\n");
	}
	if (num > 15) {
		printf(".\n");
	}
	if (num > 16) {
		printf(".\n");
	}
	if (num > 17) {
		printf("\n");
	}
}

void bookE1() {
	char y = NULL;
	int max_pharase = 26;
	for (int i = 1; i < max_pharase + 1; i++) {

		system("cls");
		bookE2(i);
		y = _getch();

	}

}
void bookE2(int num) {
	if (num > 0) {
		printf("~�Ҿ������ ���� ���� 05~\n");
	}
	if (num > 1) {
		printf(".\n");
	}
	if (num > 2) {
		printf(".\n");
	}
	if (num > 3) {
		printf("�� 2�ô� 21�� 3�� 7��\n");
	}
	if (num > 4) {
		printf("������ �߰����� ������ ���� ����� ������Ʈ�� �簳�� ���ǵǾ���.\n");
	}
	if (num > 5) {
		printf("������ ������ �ڷ���� ���� �Ĺ��� �ڶ� �� ���� ȯ���� ������ �־�����,\n");
	}
	if (num > 6) {
		printf("������ �־��� �������κ��� Ǯ�� �ڶ�� ������ ���̿���.\n");
	}
	if (num > 7) {
		printf("�� �ܿ���, �� ������ �ֺ��� �ִ� ���������κ����� �߾� ������\n");
	}
	if (num > 8) {
		printf("���� �ֺ��� �ִ� �͸����ε� ������ ��������, ��ü ����� ��Ȱ�����ٰ� �Ѵ�.\n");
	}
	if (num > 9) {
		printf("�̷��� ������� ����� ������Ʈ�� ��ħ�� �簳�Ǳ�� �����Ǿ���.\n");
	}
	if (num > 10) {
		printf(".\n");
	}
	if (num > 11) {
		printf(".\n");
	}
	if (num > 12) {
		printf("~�� 2�ô� 25�� 3�� 25��~\n");
	}
	if (num > 13) {
		printf("����� ������Ʈ�� �������� �ٰ��Դ�.\n");
	}
	if (num > 14) {
		printf("������ ���� ������ ���߿� ���� ũ�� �⿩�� ������� ������ ������ ���ѹα��� �����̿��� ������ ��������.\n");
	}
	if (num > 15) {
		printf(".\n");
	}
	if (num > 16) {
		printf(".\n");
	}
	if (num > 17) {
		printf("~�� 2�ô� 25�� 4�� 1��~\n");
	}
	if (num > 18) {
		printf("����� ������Ʈ�� ���۵� ���̿�����, ������ �ϳ� �����.\n");
	}
	if (num > 19) {
		printf("���￡ �����ϱ� ������ ���ڸ��� �־��� ������ ���ڱ� ����� ���̴�.\n");
	}
	if (num > 20) {
		printf("������ ���������� ������ ������ ��������, �ᱹ ã�� ���ߴ�.\n");
	}
	if (num > 21) {
		printf("�ᱹ ������Ʈ�� ������ ��Ե� ����ϰ� ������ ����ǰ�� ����ϰ� �Ǿ�����, ������ ���񺸴ٴ� �ǿ뼺�� ũ�� ��������.\n");
	}
	if (num > 22) {
		printf("������ ������ �� 10�� ���� 35�⿡ ����Ǿ���.\n");
	}
	if (num > 23) {
		printf(".\n");
	}
	if (num > 24) {
		printf(".\n");
	}
	if (num > 25) {
		printf(".\n");
	}
	if (num > 26) {
		printf("\n");
	}
}

void evA1() {
	char y = NULL;
	int max_pharase = 8;
	for (int i = 1; i < max_pharase + 1; i++) {

		system("cls");
		evA2(i);
		y = _getch();

	}

}
void evA2(int num) {
	if (num > 0) {
		printf(".\n");
	}
	if (num > 1) {
		printf(".\n");
	}
	if (num > 2) {
		printf("�� �۴� ������ ���� ���� ������ ����� �Ǿ���.\n");
	}
	if (num > 3) {
		printf("�� �� �������� �Ƿ���?\n");
	}
	if (num > 4	) {
		printf("�ű��ϰ� ���� ������ ������ ������ ��������� ���ϴ�.\n");
	}
	if (num > 5) {
		printf("�̷��� ��� Ű������.\n");
	}
	if (num > 6) {
		printf(".\n");
	}
	if (num > 7) {
		printf(".\n");
	}
	if (num > 8) {
		printf("\n");
	}

}

void evB1() {
	char y = NULL;
	int max_pharase = 8;
	for (int i = 1; i < max_pharase + 1; i++) {

		system("cls");
		evB2(i);
		y = _getch();

	}

}
void evB2(int num) {
	if (num > 0) {
		printf(".\n");
	}
	if (num > 1) {
		printf(".\n");
	}
	if (num > 2) {
		printf("������ �ڶ���� ���Ÿ� �ξ���.\n");
	}
	if (num > 3) {
		printf("���� �𸣰� ����� ��������.\n");
	}
	if (num > 4) {
		printf("�������� �� ü���� ������ �� ���⵵ �ϴ�.\n");
	}
	if (num > 5) {
		printf("...��� Ű������.\n");
	}
	if (num > 6) {
		printf(".\n");
	}
	if (num > 7) {
		printf(".\n");
	}
	if (num > 8) {
		printf("\n");
	}

}

void evC1() {
	char y = NULL;
	int max_pharase = 10;
	for (int i = 1; i < max_pharase + 1; i++) {

		system("cls");
		evC2(i);
		y = _getch();

	}

}
void evC2(int num) {
	if (num > 0) {
		printf(".\n");
	}
	if (num > 1) {
		printf(".\n");
	}
	if (num > 2) {
		printf("�׻� ������������ �� ������ ���� �ź��ϴ�.\n");
	}
	if (num > 3) {
		printf("���õ��� �� �ź����� �� ũ�� ��������.\n");
	}
	if (num > 4) {
		printf("�� ���� ���� ���� �԰� �ڶ� ������ ����� ������ �Ƹ��ٿ���.\n");
	}
	if (num > 5) {
		printf(".\n");
	}
	if (num > 6) {
		printf(".\n");
	}
	if (num > 7) {
		printf("���� ������ �� ������ �� ����.\n");
	}
	if (num > 8) {
		printf(".\n");
	}
	if (num > 9) {
		printf(".\n");
	}
	if (num > 10) {
		printf("\n");
	}

}

void evD1() {
	char y = NULL;
	int max_pharase = 10;
	for (int i = 1; i < max_pharase + 1; i++) {

		system("cls");
		evD2(i);
		y = _getch();

	}

}
void evD2(int num) {
	if (num > 0) {
		printf(".\n");
	}
	if (num > 1) {
		printf(".\n");
	}
	if (num > 2) {
		printf("�̰� ����.\n");
	}
	if (num > 3) {
		printf("������ �Ϸ縸�� �̻��� ������ Ŀ���ִ�.\n");
	}
	if (num > 4) {
		printf("�������� ū ������ �λ����� ó�� ���� �� ����.\n");
	}
	if (num > 5) {
		printf("��ġ '�����'��� �ҷ��� �� �� ����.\n");
	}
	if (num > 6) {
		printf(".\n");
	}
	if (num > 7) {
		printf("���� �𸣰� �����ӿ��� ���� ������� ���ܳ���.\n");
	}
	if (num > 8) {
		printf(".\n");
	}
	if (num > 9) {
		printf(".\n");
	}
	if (num > 10) {
		printf("\n");
	}

}