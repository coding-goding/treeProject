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
		else if (a == 2) {//돈
			money = working(money, work_wood_Lv, work_doll_Lv, work_tool_Lv, work_furn_Lv, work_house_Lv, work_efficiency);
		}
		else if (a == 3) {//상점
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
			printf("정말 종료하시겠습니까?\n이 버전은 저장과 불러오기를 지원하지 않습니다.\n\n");
			printf("y를 눌러주세요>");
			char q = _getch();
			if (q == 'y') {
				break;
			}
			
		}
	}



}

void intro() { //인트로
	printf("나무키우기 ver.%s\n", VER);
	printf("방향키 : 선택/a : 결정\n");
	printf("아무 키나 눌러 시작");
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
		printf("스토리를 보시겠습니까?\n예\n아니요");
		if (error == 1) { //Caps Lock 활성화
			gotoxy(0, 6);
			printf("Caps Lock을 풀어주세요.");
			error = 0;
		}
		else if (error == 2) { //한/영키 전환
			gotoxy(0, 6);
			printf("한/영키를 바꿔주세요.");
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
		printf("스토리1\n");
	}
	if (num > 1) {
		printf("스토리2\n");
	}
	if (num > 2) {
		printf("스토리3\n");
	}
}
void gotoxy(int x, int y) { //커서 이동
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int start_select(int money, int cleared) {  //메인 인터페이스
	int s = 1;
	int error = 0;
	char select = NULL;
	while (1) {
		system("cls");
		printf("나무 키워주기\n작업\n상점\n종료");
		printf("\n\n현재 돈 : %d원", money);
		if (cleared == 1) {
			gotoxy(0, 8);
			printf("클리어를 축하합니다!");
		}
		if (error == 1) { //Caps Lock 활성화
			gotoxy(0, 6);
			printf("Caps Lock을 풀어주세요.");
			error = 0;
		}
		else if (error == 2) { //한/영키 전환
			gotoxy(0, 6);
			printf("한/영키를 바꿔주세요.");
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
		printf("\n현재 돈 : %d원", income);
		printf("\n작업 효율성 : Lv.%d", ef);
		printf("\n작업 진행도 : %d/%d\n\n", progress, max_progress);


		printf("목재 가공 Lv.%d\n목재 인형 제작 Lv.%d\n목재 도구 제작 Lv.%d\n목재 가구 제작 Lv.%d\n목재 집 건축 Lv.%d\n돌아가기", lvA, lvB, lvC, lvD, lvE);
		if (error == 1) { //Caps Lock 활성화
			gotoxy(0, 13);
			printf("Caps Lock을 풀어주세요.");
			error = 0;
		}
		else if (error == 2) { //한/영키 전환
			gotoxy(0, 13);
			printf("한/영키를 바꿔주세요.");
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
		printf("목재 가공 이론서\n목재 인형 제작서\n목재 도구 제작서\n목재 가구 제작서\n목재 집 건축 이론서\n작업 효율성 이론\n비료\n물\n물뿌리개 개조\n영양제\n뒤로가기");
		printf("\n\n\n현재 돈 : %d원", money);
		if (error == 1) { //Caps Lock 활성화
			gotoxy(0, 18);
			printf("Caps Lock을 풀어주세요.");
			error = 0;
		}
		else if (error == 2) { //한/영키 전환
			gotoxy(0, 18);
			printf("한/영키를 바꿔주세요.");
			error = 0;
		}
		else if (error == 3) {
			gotoxy(0, 18);
			printf("돈이 부족합니다.");
			error = 0;
		}
		else if (error == 4) {
			gotoxy(0, 18);
			printf("더이상 구매 할 수 없습니다.");
		}
		else if (error == 5) {
			gotoxy(0, 18);
			printf("아직 구매 할 수 없습니다.");
		}
		if (s == 1) {
			gotoxy(0, 0);
			int income = lvA;
			if (lvA == 0) {
				income = 0;
			}
			printf("목재 가공 이론서(Lv.%d)\n목재 가공에 대한 능력을 키웁니다.\n수익량:%d원 > %d원  필요 자금:%d원", lvA, income, lvA + 1, 10 + lvA * 3);
			gotoxy(17, 4);
		}
		else if (s == 2) {
			int income = 15+ lvB * 20;
			if (lvB == 0) {
				income = 0;
			}
			gotoxy(0, 0);
			printf("목재 인형 제작서(Lv.%d)\n목재 인형 제작에 대한 능력을 키웁니다.\n수익량:%d원 > %d원  필요 자금:%d원  필요 조건:목재 가공 이론 Lv.%d", lvB, income, income + 20, 50 + lvB * 9, 50);
			gotoxy(17, 5);
		}
		else if (s == 3) {
			gotoxy(0, 0);
			int income = 200 + lvC * 500;
			if (lvC == 0) {
				income = 0;
			}
			printf("목재 도구 제작서(Lv.%d)\n목재 도구 제작에 대한 능력을 키웁니다.\n수익량:%d원 > %d원  필요 자금:%d원  필요 조건:목재 인형 제작 Lv.%d", lvC, income, income + 500, 100 + lvC * 23, 50);
			gotoxy(17, 6);
		}
		else if (s == 4) {
			gotoxy(0, 0);
			int income = 1500 + lvD * 5000;
			if (lvD == 0) {
				income = 0;
			}
			printf("목재 가구 제작서(Lv.%d)\n목재 가구 제작에 대한 능력을 키웁니다.\n수익량:%d원 > %d원  필요 자금:%d원  필요 조건:목재 도구 제작 Lv.%d", lvD, income, income + 5000, 250 + lvD * 41, 50);
			gotoxy(17, 7);
		}
		else if (s == 5) {
			gotoxy(0, 0);
			int income = 10000 + lvE * 40000;
			if (lvE == 0) {
				income = 0;
			}
			printf("목재 집 건축 이론서(Lv.%d)\n목재 집 건축에 대한 능력을 키웁니다.\n수익량:%d원 > %d원  필요 자금:%d원  필요 조건:목재 가구 제작 Lv.%d", lvE, income, income + 40000, 500 + lvE * 102, 50);
			gotoxy(20, 8);
		}
		else if (s == 6) {
			gotoxy(0, 0);
			printf("작업 효율성 이론(Lv.%d)\n작업의 효율성을 키웁니다.\n작업 효율 %d > %d  필요 자금:%d원", ef, ef, ef + 1, 1000 + 2500 * ef);
			gotoxy(17, 9);
		}
		else if (s == 7) {
			gotoxy(0, 0);
			printf("비료(%d개)\n나무의 성장도를 높일 수 있습니다.\n성장도 증가:70  필요 자금:50원     s로 일괄 구입", fer);
			gotoxy(5, 10);
		}
		else if (s == 8) {
			gotoxy(0, 0);
			printf("물(%d/%d)\n나무의 성장도를 높일 수 있습니다.\n성장도 증가:1  필요 자금:무료", water, max_water);
			gotoxy(3, 11);
		}
		else if (s == 9) {
			gotoxy(0, 0);
			printf("물뿌리개 개조(Lv.%d)\n물의 최대 저장량을 높입니다.\n물뿌리개 용량:%d > %d  필요 자금:%d원", (max_water - 10) / 10, max_water, max_water + 10, 10 + max_water * 2);
			gotoxy(14, 12);
		}
		else if (s == 10) {
			gotoxy(0, 0);
			if (drug == 0) {
				printf("영양제(없음)\n나무의 성장도 효율을 높입니다.\n성장도 효율 증가 : x2  필요 자금:5000원");
			}
			else {
				printf("영양제(주입됨)\n나무의 성장도 효율을 높입니다.\n성장도 효율 증가 : x2  필요 자금:5000원");
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
		printf("%d단계 성장\n성장도 %d/%d\n영양제:", level, xp, max_xp);
		if (drug == 0) {
			printf("없음\n\n\n");
		}
		else {
			printf("주입됨\n\n\n");
		}
		printf("물 주기\n비료 주기\n뒤로가기");
		
		if (error == 1) { //Caps Lock 활성화
			gotoxy(0, 17);
			printf("Caps Lock을 풀어주세요.");
			error = 0;
		}
		else if (error == 2) { //한/영키 전환
			gotoxy(0, 17);
			printf("한/영키를 바꿔주세요.");
			error = 0;
		}
		else if (error == 3) {
			gotoxy(0, 17);
			printf("비료가 부족합니다.");
			error = 0;
		}
		else if (error == 4) {
			gotoxy(0, 17);
			printf("물이 부족합니다.");
			error = 0;
		}
		if (s == 1) {
			gotoxy(0, 10);
			printf("물\n잔여:%d/%d\n성장도 증가:1", water, max_water);
			
			gotoxy(8, 6);
		}
		else if (s == 2) {
			gotoxy(0, 10);
			printf("비료\n수량:%d개\n성장도 증가:70\ns로 10개씩 주기\nd로 100개씩 주기", fer);
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
		printf("묘목");
	}
	else if (lv < 10) {
		printf("조금 성장한 묘목");
	}
	else if (lv < 15) {
		printf("꽤 성장한 묘목");
	}
	else if (lv < 20) {
		printf("나무가 되기 전의 묘목");
	}
	else if (lv < 25) {
		printf("조그마한 나무");
	}
	else if (lv < 30) {
		printf("아담한 나무");
	}
	else if (lv < 35) {
		printf("나무");
	}
	else if (lv < 40) {
		printf("꽃이 피어난 나무");
	}
	else if (lv < 45) {
		printf("사과나무");
	}
	else if (lv < 50) {
		printf("성장기에 접어든 나무");
	}
	else if (lv < 55) {
		printf("큰 나무");
	}
	else if (lv < 60) {
		printf("거대한 나무");
	}
	else if (lv < 65) {
		printf("'나무'아미타불");
	}
	else if (lv < 70) {
		printf("똥묻은 개가 겨묻은 개 '나무'란다");
	}
	else if (lv < 75) {
		printf("세계수의 조짐이 보이는 나무");
	}
	else if (lv < 80) {
		printf("세계수가 되기 직전의 나무");
	}
	else if (lv < 85) {
		printf("세계수");
	}
	else if (lv < 90) {
		printf("비브라늄 세계수");
	}
	else if (lv < 95) {
		printf("끝이 보이지 않기 시작한 세계수");
	}
	else if (lv < 99) {
		printf("대기권에 도달한 세계수");
	}
	else if(lv < 100) {
		printf("하늘을 뚫기 직전의 세계수");
	}
	else {
		printf("하늘을 뚫어낸 세계수");
	}
	printf("\n");
}
void ending() {
	char y;
	system("cls");
	ending2();
	printf("\n이야기는 끝났지만 게임은 계속할 수 있습니다.\n아무 키나 눌러 계속");
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
		printf("엔딩1\n");
	}
	if (num > 1) {
		printf("엔딩2\n");
	}
	if (num > 2) {
		printf("~fin~");
	}
}