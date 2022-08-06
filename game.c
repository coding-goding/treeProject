#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

#define VER "1.0"

typedef struct all_var {
	//items
	int money;
	int fer;
	int water;
	int max_water;
	int drug;
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
}var;

void intro();
void story();
void story2();
void story3(int num);
void gotoxy(int x, int y);
int start_select(int money, int cleared);
var rest(var a);
var read(var a);
var status(var a);
var work(var a);
var shop_items(var a);
var shop_books(var a);
var sell(var a);
var tree(var a);
void treeName(int lv);
void printMap(int place);
void ending();
void ending2();
void ending3(int num);


int main() {

	var v;
	v.money = 1000000;
	v.fer = 0;
	v.water = 0;
	v.max_water = 100;
	v.drug = 0;
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

	int place = 1;

	int cleared = 0;

	intro();
	story();
	while (1) {
		int a = start_select(v.money, cleared);
		if (a == 1) {
			var tmp = tree(v);
			v.level = tmp.level;
			v.xp = tmp.xp;
			v.fer = tmp.fer;
			v.water = tmp.water;
			v.drug = tmp.drug;
			v.druged = tmp.druged;
			if (v.level == 101) {
				cleared = 1;
			}

			tmp = rest(v);
		}
		else if (a == 2) {//돈
			var tmp = work(v);
			v.gA = tmp.gA;
			v.gB = tmp.gB;
			v.gC = tmp.gC;
			v.gD = tmp.gD;
			v.gE = tmp.gE;
			//money = working(money, work_wood_Lv, work_doll_Lv, work_tool_Lv, work_furn_Lv, work_house_Lv, work_efficiency);
		}
		else if (a == 3) {//상점
			var tmp = shop_items(v);
			v.money = tmp.money;
			v.fer = tmp.fer;
			v.water = tmp.water;
			v.max_water = tmp.max_water;
			v.drug = tmp.drug;

			tmp = shop_books(v);
			v.money = tmp.money;
			v.bA = tmp.bA;
			v.bB = tmp.bB;
			v.bC = tmp.bC;
			v.bD = tmp.bD;
			v.bE = tmp.bE;
			v.bT = tmp.bT;
			v.bEF = tmp.bEF;
			v.sA = tmp.sA;
			v.sB = tmp.sB;
			v.sC = tmp.sC;
			v.sD = tmp.sD;
			v.sE = tmp.sE;

			tmp = sell(v);
			v.money = tmp.money;
			v.gA = tmp.gA;
			v.gB = tmp.gB;
			v.gC = tmp.gC;
			v.gD = tmp.gD;
			v.gE = tmp.gE;
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
	int max_pharase = 10;
	for (int i = 1; i < max_pharase+1; i++) {
		
			system("cls");
			story3(i);
			y = _getch();
		
	}
	
}
void story3(int num) {
	if (num > 0) {
		printf("-제 2시대 316년 4월 1일\n");
	}
	if (num > 1) {
		printf("이 마을은 여러 마을 중심에 있어 상업이 발달하었다.\n");
	}
	if (num > 2) {
		printf("대부분의 주민들은 마을 사이의 교역을 도우며 먹고 살았다.\n");
	}
	if (num > 3) {
		printf("그 외의 몇몇 주민들은 자체적으로 제품을 만들어 팔기도 했는데, 내가 그중 하나다.\n");
	}
	if (num > 4) {
		printf("나는 대대적으로 목제 제품 제작업을 해오는 가문의 자손이다.\n");
	}
	if (num > 5) {
		printf(".\n");
	}
	if (num > 6) {
		printf(".\n");
	}
	if (num > 7) {
		printf("어느 날, 마을 잡화상점 주인 김 아저씨랑 옆 마을에 다녀오던 중 한 묘목이 바닥에 떨어져 있는 걸 보았다.\n");
	}
	if (num > 8) {
		printf("나는 그 묘목을 주웠다.\n");
	}
	if (num > 9) {
		printf("목재는 따로 숲속 마을에서 보내주지만, 그저 심심풀이로 키워보기로 했다.\n");
	}
	if (num > 10) {
		printf("\n");
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
var rest(var a) {
	var v;
	v = a;
	int s = 1;
	int error = 0;

	char select = NULL;
	while (1) {
		system("cls");
		printf("서재\n스테이터스\n창고\n나가기");
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

					}
					else if (s == 2) {

					}
					else if (s == 3) {

					}
					else if (s == 4) {
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

var read(var a) {
	var v;
	v = a;
	int s = 1;
	int error = 0;

	char select = NULL;
	while (1) {
		system("cls");
		printf("독서\n스테이터스\n창고\n나가기");
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

					}
					else if (s == 2) {

					}
					else if (s == 3) {

					}
					else if (s == 4) {
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

var work(var a) {
	var v;
	v.gA = a.gA;
	v.gB = a.gB;
	v.gC = a.gC;
	v.gD = a.gD;
	v.gE = a.gE;
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
			printf("\n가공된 목재 : %d개", v.gA);
		}
		else if (s == 2) {
			printf("\n목재 인형 : %d개", v.gB);
		}
		else if (s == 3) {
			printf("\n목재 도구 : %d개", v.gC);
		}
		else if (s == 4) {
			printf("\n목재 가구 : %d개", v.gD);
		}
		else if (s == 5) {
			printf("\n목재 집 : %d채", v.gE);
		}
		else {
			printf("\n                  ");
		}
		printf("\n작업 효율성 : Lv.%d", a.ef);
		printf("\n작업 진행도 : %d/%d\n\n", progress, max_progress);


		printf("목재 가공 Lv.%d\n목재 인형 제작 Lv.%d\n목재 도구 제작 Lv.%d\n목재 가구 제작 Lv.%d\n목재 집 건축 Lv.%d\n나가기", a.lvA, a.lvB, a.lvC, a.lvD, a.lvE);
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
						progress += 1 + a.ef;
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
						progress += 1 + a.ef;
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

var shop_items(var a) {
	var v;
	v.money = a.money;
	v.fer = a.fer;
	v.water = a.water;
	v.max_water = a.max_water;
	v.drug = a.drug;

	int s = 1;
	int error = 0;
	char select = NULL;

	while (1) {
		system("cls");
		printf("\n\n\n\n");
		printf("비료\n물\n물뿌리개 개조\n영양제\n나가기");
		printf("\n\n\n현재 돈 : %d원", v.money);
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
		else {
			gotoxy(0, 18);
			printf("                                  ");
			error = 0;
		}
		if (s == 1) {
			gotoxy(0, 0);
			printf("비료(%d개)\n나무의 성장도를 높일 수 있습니다.\n성장도 증가:70  필요 자금:50원     s로 일괄 구입", v.fer);
			gotoxy(5, 4);
		}
		else if (s == 2) {
			gotoxy(0, 0);
			printf("물(%d/%d)\n나무의 성장도를 높일 수 있습니다.\n성장도 증가:1  필요 자금:무료", v.water, v.max_water);
			gotoxy(3, 5);
		}
		else if (s == 3) {
			gotoxy(0, 0);
			printf("물뿌리개 개조(Lv.%d)\n물의 최대 저장량을 높입니다.\n물뿌리개 용량:%d > %d  필요 자금:%d원", (v.max_water - 100) / 10, v.max_water, v.max_water + 10, 10 + v.max_water * 2);
			gotoxy(14, 6);
		}
		else if (s == 4) {
			gotoxy(0, 0);
			int sum = a.druged + v.drug;
			printf("영양제(%d개)\n나무의 성장도 효율을 높입니다.\n성장도 효율 증가 : x(주입된 영양제)  필요 자금:%d원", v.drug,  sum * sum * 5000 + 5000);
			
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

	var v;
	v.money = a.money;
	v.lvA = a.lvA;
	v.lvB = a.lvB;
	v.lvC = a.lvC;
	v.lvD = a.lvD;
	v.lvE = a.lvE;
	v.ef = a.ef;
	v.bA = a.bA;
	v.bB = a.bB;
	v.bC = a.bC;
	v.bD = a.bD;
	v.bE = a.bE;
	v.bT = a.bT;
	v.bEF = a.bEF;
	v.sA = a.sA;
	v.sB = a.sB;
	v.sC = a.sC;
	v.sD = a.sD;
	v.sE = a.sE;
	v.readed = a.readed;
	int s = 1;
	int error = 0;
	char select = NULL;
	while (1) {
		system("cls");
		printf("\n\n\n\n");
		printf("목재 가공 이론서\n목재 인형 제작서\n목재 도구 제작서\n목재 가구 제작서\n목재 집 건축 이론서\n작업 효율성 이론서\n생명과학 이론서\n잃어버리지 않은 역사 - 1권\n잃어버리지 않은 역사 - 2권\n잃어버리지 않은 역사 - 3권\n잃어버리지 않은 역사 - 4권\n나가기");
		printf("\n\n\n현재 돈 : %d원", v.money);
		if (error == 1) { //Caps Lock 활성화
			gotoxy(0, 20);
			printf("Caps Lock을 풀어주세요.");
			error = 0;
		}
		else if (error == 2) { //한/영키 전환
			gotoxy(0, 20);
			printf("한/영키를 바꿔주세요.");
			error = 0;
		}
		else if (error == 3) {
			gotoxy(0, 20);
			printf("돈이 부족합니다.");
			error = 0;
		}
		else if (error == 4) {
			gotoxy(0, 20);
			printf("더이상 구매 할 수 없습니다.");
			error = 0;
		}
		else if (error == 5) {
			gotoxy(0, 20);
			printf("아직 구매 할 수 없습니다.");
			error = 0;
		}
		if (s == 1) {
			gotoxy(0, 0);
			int sum = v.lvA + v.bA;

			printf("목재 가공 이론서(재고:%d)\n목재 가공에 대한 능력을 키웁니다.\n현재 Lv.%d  필요 자금:%d원", 100 - sum, v.lvA, 10 + sum * 3);
			gotoxy(17, 4);
		}
		else if (s == 2) {
			int sum = v.lvB + v.bB;
			gotoxy(0, 0);
			printf("목재 인형 제작서(재고:%d)\n목재 인형 제작에 대한 능력을 키웁니다.\n현재 Lv.%d  필요 자금:%d원  필요 조건:목재 가공 이론 Lv.%d", 100 - sum, v.lvB, 50 + sum * 9, 50);
			gotoxy(17, 5);
		}
		else if (s == 3) {
			gotoxy(0, 0);
			int sum = v.lvC + v.bC;
			printf("목재 도구 제작서(재고:%d)\n목재 도구 제작에 대한 능력을 키웁니다.\n현재 Lv.%d  필요 자금:%d원  필요 조건:목재 인형 제작 Lv.%d", 100 - sum, v.lvC, 100 + sum * 23, 50);
			gotoxy(17, 6);
		}
		else if (s == 4) {
			gotoxy(0, 0);
			int sum = v.lvD + v.bA;
			printf("목재 가구 제작서(재고:%d)\n목재 가구 제작에 대한 능력을 키웁니다.\n현재 Lv.%d  필요 자금:%d원  필요 조건:목재 도구 제작 Lv.%d", 100 - sum, v.lvD, 250 + sum * 41, 50);
			gotoxy(17, 7);
		}
		else if (s == 5) {
			gotoxy(0, 0);
			int sum = v.lvE + v.bE;
			printf("목재 집 건축 이론서(재고:%d)\n목재 집 건축에 대한 능력을 키웁니다.\n현재 Lv.%d  필요 자금:%d원  필요 조건:목재 가구 제작 Lv.%d", 100 - sum, v.lvE, 500 + sum * 102, 50);
			gotoxy(20, 8);
		}
		else if (s == 6) {
			gotoxy(0, 0);
			int sum = v.ef + v.bEF;
			printf("작업 효율성 이론서(재고:%d)\n작업의 효율성을 키웁니다.\n현재 Lv.%d  필요 자금:%d원", 10 - sum, v.ef, 1000 + 2500 * (v.bEF + v.ef));
			gotoxy(19, 9);
		}
		else if (s == 7) {
			gotoxy(0, 0);
			printf("생명과학 이론서(재고:%d)\n나무의 성장 효율을 높일 수 있습니다.\n성장도 증가 : x1.5  필요 자금:10500원", 1 - v.bT - v.readed);
			gotoxy(16, 10);
		}
		else if (s == 8) {
			gotoxy(0, 0);
			printf("잃어버리지 않은 역사 - 1권(재고:%d)\n구석에 박혀있던 역사책입니다. 별로 재미있을 것 같지는 않네요.\n필요 자금:5000원", 1 - v.sA);
			gotoxy(27, 11);
		}
		else if (s == 9) {
			gotoxy(0, 0);
			printf("잃어버리지 않은 역사 - 2권(재고:%d)\n구석에 박혀있던 역사책입니다. 별로 재미있을 것 같지는 않네요.\n필요 자금:5000원", 1 - v.sB);
			gotoxy(27, 12);
		}
		else if (s == 10) {
			gotoxy(0, 0);
			printf("잃어버리지 않은 역사 - 3권(재고:%d)\n구석에 박혀있던 역사책입니다. 별로 재미있을 것 같지는 않네요.\n필요 자금:5000원", 1 - v.sC);
			gotoxy(27, 13);
		}
		else if (s == 11) {
			gotoxy(0, 0);
			printf("잃어버리지 않은 역사 - 4권(재고:%d)\n구석에 박혀있던 역사책입니다. 별로 재미있을 것 같지는 않네요.\n필요 자금:5000원", 1 - v.sD);
			gotoxy(27, 14);
		}
		else if (s == 12) {
			gotoxy(7, 15);
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
						if (s != 12) {
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
						else if (v.money < 10 + (v.bA + v.lvA) * 3) {
							error = 3;
							break;
						}
						else {
							v.money -= 10 + (v.bA + v.lvA) * 3;
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
						else if (v.money < 50 + (v.bB + v.lvB) * 9) {
							error = 3;
							break;
						}
						else {
							v.money -= 50 + (v.bB + v.lvB) * 9;
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
						else if (v.money < 100 + (v.lvC + v.bC) * 23) {
							error = 3;
							break;
						}
						else {
							v.money -= 100 + (v.lvC + v.bC) * 23;
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
						else if (v.money < 250 + (v.lvD + v.bD) * 41) {
							error = 3;
							break;
						}
						else {
							v.money -= 250 + (v.lvD + v.bD) * 41;
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
						else if (v.money < 500 + (v.lvE + v.bE) * 102) {
							error = 3;
							break;
						}
						else {
							v.money -= 500 + (v.lvE + v.bE) * 102;
							v.bE++;
							break;
						}
					}
					else if (s == 6) {
						if (v.ef + v.bEF == 10) {
							error = 4;
							break;
						}
						else if (v.money < 1000 + 2500 * (v.ef + v.bEF)) {
							error = 3;
							break;
						}
						else {
							v.money -= 1000 + 2500 * (v.ef + v.bEF);
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
					else if (s == 9) {
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
					else if (s == 10) {
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
					else if (s == 11) {
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
					else if (s == 12) {
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
	var v;
	v.money = a.money;
	v.gA = a.gA;
	v.gB = a.gB;
	v.gC = a.gC;
	v.gD = a.gD;
	v.gE = a.gE;

	int s = 1;
	int error = 0;
	char select = NULL;

	while (1) {
		system("cls");
		printf("\n\n\n\n");
		printf("가공된 목재 판매\n목재 인형 판매\n목재 도구 판매\n목재 가구 판매\n목재 집 판매\n나가기");
		printf("\n\n\n현재 돈 : %d원", v.money);
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
			printf("제품이 없습니다.");
			error = 0;
		}
		if (s == 1) {
			gotoxy(0, 0);
			printf("가공된 목재\n수량 : %d  수입 : %d\na로 1개씩 판매, s로 일괄 판매", v.gA, a.lvA);
			gotoxy(17, 4);
		}
		else if (s == 2) {
			gotoxy(0, 0);
			printf("목재 인형\n수량 : %d  수입 : %d\na로 1개씩 판매, s로 일괄 판매", v.gB, 15 + a.lvB * 20);
			gotoxy(15, 5);
		}
		else if (s == 3) {
			gotoxy(0, 0);
			printf("목재 도구\n수량 : %d  수입 : %d\na로 1개씩 판매, s로 일괄 판매", v.gC, 200 + a.lvC * 500);
			gotoxy(15, 6);
		}
		else if (s == 4) {
			gotoxy(0, 0);
			printf("목재 가구\n수량 : %d  수입 : %d\na로 1개씩 판매, s로 일괄 판매", v.gD, 1500 + a.lvD * 5000);
			gotoxy(15, 7);
		}
		else if (s == 5) {
			gotoxy(0, 0);
			printf("목재 집\n수량 : %d  수입 : %d\na로 1채씩 판매, s로 일괄 판매", v.gE, 10000 + a.lvE * 40000);
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
							v.money += a.lvA;
						}
						break;

					}
					else if (s == 2) {
						if (v.gB < 1) {
							error = 3;
						}
						else {
							v.gB--;
							v.money += 15 + a.lvB * 20;
						}
						break;
					}
					else if (s == 3) {
						if (v.gC < 1) {
							error = 3;
						}
						else {
							v.gC--;
							v.money += 200 + a.lvC * 500;
						}
						break;

					}
					else if (s == 4) {
						if (v.gD < 1) {
							error = 3;
						}
						else {
							v.gD--;
							v.money += 1500 + a.lvD * 5000;
						}
						break;

					}
					else if (s == 5) {
						if (v.gE < 1) {
							error = 3;
						}
						else {
							v.gE--;
							v.money += 10000 + a.lvE * 40000;
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
					else if(s == 2) {
						v.money += v.gB * (15 + a.lvB * 20);
						v.gB = 0;
					}
					else if (s == 3) {
						v.money += v.gC * (200 + a.lvC * 500);
						v.gC = 0;
					}
					else if (s == 4) {
						v.money += v.gD * (1500 + a.lvD * 5000);
						v.gD = 0;
					}
					else if (s == 5) {
						v.money += v.gE * (10000 + a.lvE * 40000);
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
	var v;
	v.fer = a.fer;
	v.water = a.water;
	v.max_water = a.max_water;
	v.drug = a.drug;
	v.xp = a.xp;
	v.max_xp = a.max_xp;
	v.level = a.level;
	v.readed = a.readed;
	v.druged = a.druged;

	int s = 1;
	int error = 0;
	char select = NULL;
	while (1) {
		system("cls");
		treeName(v.level);
		if (v.level == 100) {
			ending();
			v.level = 101;
			return v;
		}
		printf("%d단계 성장\n성장도 %d/%d\n성장 효율:(영양제:%d, 생명과학:", v.level, v.xp, v.max_xp, v.druged);
		if (v.readed == 1) {
			printf("학습됨) x%g\n\n\n", (double)(v.druged+1) * 1.5);
		}
		else {
			printf("학습되지 않음) x%d\n\n\n", v.druged + 1);
		}
		printf("물 주기\n비료 주기\n영양제 주입\n");
		if (v.level < 20) {
			printf("???????????\n");
		}
		else {
			printf("오오라 관리\n");
		}
		printf("나가기");
		if (error == 1) { //Caps Lock 활성화
			gotoxy(0, 20);
			printf("Caps Lock을 풀어주세요.");
			error = 0;
		}
		else if (error == 2) { //한/영키 전환
			gotoxy(0, 20);
			printf("한/영키를 바꿔주세요.");
			error = 0;
		}
		else if (error == 3) {
			gotoxy(0, 20);
			printf("비료가 부족합니다.");
			error = 0;
		}
		else if (error == 4) {
			gotoxy(0, 20);
			printf("물이 부족합니다.");
			error = 0;
		}
		else if (error == 5) {
			gotoxy(0, 20);
			printf("영양제가 부족합니다.");
			error = 0;
		}
		else if (error == 6) {
			gotoxy(0, 20);
			printf("아직 나무가 충분히 성장하지 않았습니다.");
		}

		if (s == 1) {
			gotoxy(0, 12);
			printf("물\n잔여:%d/%d\n성장도 증가:1\ns로 모두 주기", v.water, v.max_water);
			gotoxy(8, 6);
		}
		else if (s == 2) {
			gotoxy(0, 12);
			printf("비료\n수량:%d개\n성장도 증가:70\ns로 10개씩 주기\nd로 100개씩 주기", v.fer);
			gotoxy(10, 7);
		}
		else if (s == 3) {
			gotoxy(0, 12);
			printf("영양제\n수량:%d개\n성장 효율 증가", v.drug);
			gotoxy(12, 8);
		}
		else if (s == 4) {
			gotoxy(0, 12);
			if (v.level < 20) {
				printf("???");
			}
			else {
				printf("나무가 내뿜는 오오라를 관리합니다.");
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
							//준비중
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
			v.max_xp += 120;
			v.level++;
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
void printMap(int place) {

}// 뒷마당, 집, 작업소, 잡화점, 서점, 거래상
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