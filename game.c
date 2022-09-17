#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

#define VER "1.3"

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
	//treeEffect
	int effectA;
	int effectB;
	int effectC;
	int effectD;
	int effectFin;

	int clear;
}var;

void intro();
void story();
void story2();
void story3(int num);
void gotoxy(int x, int y);
int start_select(int num, int cleared);
var towm(var a);
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
	v.effectA = 0;
	v.effectB = 0;
	v.effectC = 0;
	v.effectD = 0;
	v.effectFin = 0;
	v.clear = 0;

	int place = 1;

	int cleared = 0;


	intro();
	story();
	while (1) {
		int a = start_select(place, cleared);
		place = a / 10;
		if (a % 10 == 3) {
			system("cls");
			printf("정말 종료하시겠습니까?\n이 버전은 저장과 불러오기를 지원하지 않습니다.\n\n");
			printf("y를 눌러주세요>");
			char q = _getch();
			if (q == 'y') {
				break;
			}
		}
		else if (a % 10 == 2) {

		}
		else {
			a /= 10;
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
				v.effectA = tmp.effectA;
				v.effectB = tmp.effectB;
				v.effectC = tmp.effectC;
				v.effectD = tmp.effectD;
				v.effectFin = tmp.effectFin;
			}
			else if (a == 2) {
				var tmp = rest(v);
				v.bA = tmp.bA;
				v.bB = tmp.bB;
				v.bC = tmp.bC;
				v.bD = tmp.bD;
				v.bE = tmp.bE;
				v.bEF = tmp.bEF;
				v.bT = tmp.bT;
				v.lvA = tmp.lvA;
				v.lvB = tmp.lvB;
				v.lvC = tmp.lvC;
				v.lvD = tmp.lvD;
				v.lvE = tmp.lvE;
				v.ef = tmp.ef;
				v.readed = tmp.readed;
			}
			else if (a == 3) {//돈
				var tmp = work(v);
				v.gA = tmp.gA;
				v.gB = tmp.gB;
				v.gC = tmp.gC;
				v.gD = tmp.gD;
				v.gE = tmp.gE;
				//money = working(money, work_wood_Lv, work_doll_Lv, work_tool_Lv, work_furn_Lv, work_house_Lv, work_efficiency);
			}
			else if (a == 4) {//상점
				var tmp = shop_items(v);
				v.money = tmp.money;
				v.fer = tmp.fer;
				v.water = tmp.water;
				v.max_water = tmp.max_water;
				v.drug = tmp.drug;

			}
			else if (a == 5) {
				var tmp = shop_books(v);
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
			}
			else {
				var tmp = sell(v);
				v.money = tmp.money;
				v.gA = tmp.gA;
				v.gB = tmp.gB;
				v.gC = tmp.gC;
				v.gD = tmp.gD;
				v.gE = tmp.gE;
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
	for (int i = 1; i < max_pharase + 1; i++) {

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

int start_select(int num, int cleared) {  //메인 인터페이스
	int s = 1;
	int v = num;
	int error = 0;
	char select = NULL;
	while (1) {
		system("cls");
		printf("\n\n\n\n");
		printf("들어가기\n\n종료");

		gotoxy(0, 0);
		printf("뒷마당  집  작업소  잡화점  서점  판매점");
		if (v == 1) {
			gotoxy(2, 1);
		}
		else if (v == 2) {
			gotoxy(8, 1);
		}
		else if (v == 3) {
			gotoxy(14, 1);
		}
		else if (v == 4) {
			gotoxy(22, 1);
		}
		else if (v == 5) {
			gotoxy(29, 1);
		}
		else if (v == 6) {
			gotoxy(36, 1);
		}
		printf("@");
		if (cleared == 1) {
			gotoxy(0, 10);
			printf("클리어를 축하합니다!");
		}
		if (error == 1) { //Caps Lock 활성화
			gotoxy(0, 12);
			printf("Caps Lock을 풀어주세요.");
			error = 0;
		}
		else if (error == 2) { //한/영키 전환
			gotoxy(0, 12);
			printf("한/영키를 바꿔주세요.");
			error = 0;
		}
		if (s == 1) {
			gotoxy(10, 4);
		}
		else if (s == 2) {
			gotoxy(5, 5);
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
							v--;
						}
						break;
					case 77:
						if (v != 6) {
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
					return s + 10 * v;
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
						var tmp = read(v);
						v.bA = tmp.bA;
						v.bB = tmp.bB;
						v.bC = tmp.bC;
						v.bD = tmp.bD;
						v.bE = tmp.bE;
						v.bEF = tmp.bEF;
						v.bT = tmp.bT;
						v.lvA = tmp.lvA;
						v.lvB = tmp.lvB;
						v.lvC = tmp.lvC;
						v.lvD = tmp.lvD;
						v.lvE = tmp.lvE;
						v.ef = tmp.ef;
						v.readed = tmp.readed;

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
	int p = 0; // bA / bB / bC / bD / bE / bEF / bT / sA / sB / sC / sD / sE

	char select = NULL;

	int b[12] = { 0, };
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
	if (v.sA > 0) {
		b[7] = 1;
	}
	if (v.sB > 0) {
		b[8] = 1;
	}
	if (v.sC > 0) {
		b[9] = 1;
	}
	if (v.sD > 0) {
		b[10] = 1;
	}
	if (v.sE > 0) {
		b[11] = 1;
	}
	for (int i = 0; i < 12; i++) {
		if (b[i] == 1) {
			p = i + 1;
			i = 13;
		}
	}

	while (1) {
		system("cls");
		int o = 0;
		printf("\n\n\n\n");
		if (p == 0) {
			printf("책이 없습니다. 서점에서 책을 구매해 보세요.");
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
				printf("읽을 시 가공된 목재를 판매했을 때의 수입이 증가합니다.\n");
				printf("* 가공된 목재 판매가 %d원 > %d원\n", v.lvA, v.lvA + 1);
				printf("* 개수 : %d권", v.bA);
				gotoxy(4, 4);
				printf("목재 가공 이론서");
			}
			if (p == 2) {
				int incomeA = 15 + v.lvB * 20;
				int incomeB = 35 + v.lvB * 20;
				if (v.lvB == 0) {
					incomeA = 0;
					incomeB = 35;
				}
				gotoxy(0, 0);
				printf("읽을 시 목재 인형을 판매했을 때의 수입이 증가합니다.\n");
				printf("* 목재 인형 판매가 %d원 > %d원\n", incomeA, incomeB);
				printf("* 개수 : %d권", v.bB);
				gotoxy(4, 4);
				printf("목재 인형 제작서");
			}
			if (p == 3) {
				int incomeA = 200 + v.lvC * 500;
				int incomeB = 700 + v.lvC * 500;
				if (v.lvB == 0) {
					incomeA = 0;
					incomeB = 700;
				}
				gotoxy(0, 0);
				printf("읽을 시 목재 도구를 판매했을 때의 수입이 증가합니다.\n");
				printf("* 목재 도구 판매가 %d원 > %d원\n", incomeA, incomeB);
				printf("* 개수 : %d권", v.bC);
				gotoxy(4, 4);
				printf("목재 도구 제작서");
			}
			if (p == 4) {
				int incomeA = 1500 + v.lvD * 5000;
				int incomeB = 6500 + v.lvD * 5000;
				if (v.lvB == 0) {
					incomeA = 0;
					incomeB = 6500;
				}
				gotoxy(0, 0);
				printf("읽을 시 목재 가구를 판매했을 때의 수입이 증가합니다.\n");
				printf("* 목재 가구 판매가 %d원 > %d원\n", incomeA, incomeB);
				printf("* 개수 : %d권", v.bD);
				gotoxy(4, 4);
				printf("목재 가구 제작서");
			}
			if (p == 5) {
				int incomeA = 10000 + v.lvE * 40000;
				int incomeB = 50000 + v.lvE * 40000;
				if (v.lvB == 0) {
					incomeA = 0;
					incomeB = 60000;
				}
				gotoxy(0, 0);
				printf("읽을 시 목재 집을 판매했을 때의 수입이 증가합니다.\n");
				printf("* 목재 집 판매가 %d원 > %d원\n", incomeA, incomeB);
				printf("* 개수 : %d권", v.bE);
				gotoxy(4, 4);
				printf("목재 집 건축 이론서");
			}
			if (p == 6) {
				gotoxy(0, 0);
				printf("읽을 시 작업의 효율이 증가합니다.\n");
				printf("* 작업 효율 +%d > +%d\n", v.ef, v.ef + 1);
				printf("* 개수 : %d권", v.bEF);
				gotoxy(4, 4);
				printf("작업 효율성 이론서");
			}
			if (p == 7) {
				gotoxy(0, 0);
				printf("읽을 시 나무의 성장의 효율이 증가합니다.\n");
				printf("* 성장 효율 : x1.5\n");
				printf("* 개수 : %d권", v.bT);
				gotoxy(4, 4);
				printf("생명과학 이론서");
			}
			if (p >= 8) {
				gotoxy(0, 0);
				printf("별로 재미있을 것 같진 않은 역사책입니다.\n");
				int series = 0;
				if (p == 8) {
					series = 1;
				}
				if (p == 9) {
					series = 2;
				}
				if (p == 10) {
					series = 3;
				}
				if (p == 11) {
					series = 4;
				}
				else {
					series = 5;
				}
				printf("* 개수 : %d권", 1);
				gotoxy(4, 4);
				printf("잃어버리지 않은 역사 - %d권", p - 7);
			}

			o = 0;
			for (int i = p + 1; i < 13; i++) {
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
		printf("\n\n읽기\n뒤로가기");
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
						for (int i = p + 1; i < 13; i++) {
							if (b[i - 1] == 1) {
								o = i;
								i = 13;
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
							if (v.sA == 0) {
								isEmpty = 1;
							}
						}
						else if (p == 9) {
							if (v.sB == 0) {
								isEmpty = 1;
							}
						}
						else if (p == 10) {
							if (v.sC == 0) {
								isEmpty = 1;
							}
						}
						else if (p == 11) {
							if (v.sD == 0) {
								isEmpty = 1;
							}
						}
						else if (p == 12) {
							if (v.sE == 0) {
								isEmpty = 1;
							}
						}
						if (isEmpty == 1) {
							isEmpty = 0;
							b[p - 1] = 0;
							o = 0;
							for (int i = p + 1; i < 13; i++) {
								if (b[i - 1] == 1) {
									o = i;
									i = 13;
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

	printf("작업 능력\n\n");
	printf("목재 가공 Lv.%d\n", v.lvA);
	printf("목재 인형 제작 Lv.%d\n", v.lvB);
	printf("목재 도구 제작 Lv.%d\n", v.lvC);
	printf("목재 가구 제작 Lv.%d\n", v.lvD);
	printf("목재 집 건축 Lv.%d\n", v.lvE);
	printf("작업 효율 Lv.%d\n\n", v.ef + a.effectB*2 + a.effectC + a.effectFin*1000);

	printf("나무 성장\n\n");
	treeName(v.level);
	printf("Lv.%d\n", v.level);
	printf("%d / %d\n", v.xp, v.max_xp);
	printf("주입된 영양제 : %d개\n", v.druged);
	printf("생명공학 : ");
	if (v.readed == 1) {
		printf("학습됨\n최종 성장 효율 : x%g\n", (double)(v.druged + 1) * 1.5);
	}
	else {
		printf("학습되지 않음\n최종 성장 효율 : x%g\n", (double)(v.druged + 1));
	}
	printf("\n아무 키나 눌러 뒤로가기");
	char c = NULL;
	c = _getch();
	return v;
}

var storage(var a) {
	var v;
	v = a;
	system("cls");

	printf("작업물\n\n");
	printf("가공된 목재 : %d개\n", v.gA);
	printf("목재 인형 : % d개\n", v.gB);
	printf("목재 도구 : % d개\n", v.gC);
	printf("목재 가구 : % d개\n", v.gD);
	printf("목재 집 : % d채\n\n", v.gE);

	printf("나무 성장품\n\n");
	printf("비료 : %d개\n", v.fer);
	printf("물 : %d / %d\n", v.water, v.max_water);
	printf("영양제 : %d개\n\n", v.drug);

	printf("자금 : %d원\n", v.money);
	printf("\n아무 키나 눌러 뒤로가기");
	char c = NULL;
	c = _getch();
	return v;
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
		printf("\n작업 효율성 : Lv.%d", a.ef + a.effectB*2 + a.effectC + a.effectFin * 1000);
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
						progress += 1 + a.ef + a.effectB * 2 + a.effectC + a.effectFin * 1000;
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
						progress += 1 + a.ef + a.effectB * 2 + a.effectC + a.effectFin * 1000;
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
			printf("영양제(%d개)\n나무의 성장도 효율을 높입니다.\n성장도 효율 증가 : x(주입된 영양제)  필요 자금:%d원", v.drug, sum * sum * 5000 + 5000);

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
		printf("목재 가공 이론서\n목재 인형 제작서\n목재 도구 제작서\n목재 가구 제작서\n목재 집 건축 이론서\n작업 효율성 이론서\n생명과학 이론서\n잃어버리지 않은 역사 - 1권\n잃어버리지 않은 역사 - 2권\n잃어버리지 않은 역사 - 3권\n잃어버리지 않은 역사 - 4권\n잃어버리지 않은 역사 - 5권\n나가기");
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
			int sum = v.lvD + v.bD;
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
			gotoxy(0, 0);
			printf("잃어버리지 않은 역사 - 5권(재고:%d)\n구석에 박혀있던 역사책입니다. 별로 재미있을 것 같지는 않네요.\n필요 자금:5000원", 1 - v.sE);
			gotoxy(27, 15);
		}
		else if (s == 13) {
			gotoxy(7, 16);
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
						if (s != 13) {
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
					else if (s == 13) {
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
			printf("가공된 목재\n수량 : %d  수입 : %d\na로 1개씩 판매, s로 일괄 판매", v.gA, a.lvA + a.effectD * 1000);
			gotoxy(17, 4);
		}
		else if (s == 2) {
			gotoxy(0, 0);
			printf("목재 인형\n수량 : %d  수입 : %d\na로 1개씩 판매, s로 일괄 판매", v.gB, 15 + a.lvB * 20 + a.effectD * 1000);
			gotoxy(15, 5);
		}
		else if (s == 3) {
			gotoxy(0, 0);
			printf("목재 도구\n수량 : %d  수입 : %d\na로 1개씩 판매, s로 일괄 판매", v.gC, 200 + a.lvC * 500 + a.effectD * 1000);
			gotoxy(15, 6);
		}
		else if (s == 4) {
			gotoxy(0, 0);
			printf("목재 가구\n수량 : %d  수입 : %d\na로 1개씩 판매, s로 일괄 판매", v.gD, 1500 + a.lvD * 5000 + a.effectD * 1000);
			gotoxy(15, 7);
		}
		else if (s == 5) {
			gotoxy(0, 0);
			printf("목재 집\n수량 : %d  수입 : %d\na로 1채씩 판매, s로 일괄 판매", v.gE, 10000 + a.lvE * 40000 + a.effectD * 1000);
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
							v.money += 15 + a.lvB * 20 + a.effectD * 1000;
						}
						break;
					}
					else if (s == 3) {
						if (v.gC < 1) {
							error = 3;
						}
						else {
							v.gC--;
							v.money += 200 + a.lvC * 500 + a.effectD * 1000;
						}
						break;

					}
					else if (s == 4) {
						if (v.gD < 1) {
							error = 3;
						}
						else {
							v.gD--;
							v.money += 1500 + a.lvD * 5000 + a.effectD * 1000;
						}
						break;

					}
					else if (s == 5) {
						if (v.gE < 1) {
							error = 3;
						}
						else {
							v.gE--;
							v.money += 10000 + a.lvE * 40000 + a.effectD * 1000;
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
	v.effectA = a.effectA;
	v.effectB = a.effectB;
	v.effectC = a.effectC;
	v.effectD = a.effectD;
	v.effectFin = a.effectFin;

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
			printf("학습됨) x%g\n\n\n", (double)(v.druged + 1) * 1.5);
		}
		else {
			printf("학습되지 않음) x%d\n\n\n", v.druged + 1);
		}
		printf("물 주기\n비료 주기\n영양제 주입\n");
		if (v.level < 20) {
			printf("?????????\n");
		}
		else {
			printf("축복 관리\n");
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
	else if (lv < 100) {
		printf("하늘을 뚫기 직전의 세계수");
	}
	else {
		printf("하늘을 뚫어낸 세계수");
	}
	printf("\n");
}

var effect(var a) {
	var v;
	v.level = a.level;
	v.effectA = a.effectA;
	v.effectB = a.effectB;
	v.effectC = a.effectC;
	v.effectD = a.effectD;
	v.effectFin = a.effectFin;

	int s = 1;
	int error = 0;
	char select = NULL;

	while (1) {
		system("cls");
		printf("\n\n\n\n");
		if (v.level >= 20) {
			printf("나무의 축복  ");
			if (v.effectA == 1) {
				printf("활성화");
			}
			else {
				printf("비활성화");
			}
			printf("\n");
		}
		if (v.level >= 40) {
			printf("결실의 기쁨  ");
			if (v.effectB == 1) {
				printf("활성화");
			}
			else {
				printf("비활성화");
			}
			printf("\n");
		}
		else {
			printf("??????????\n");
		}
		if (v.level >= 60) {
			printf("나무의 축복 2  ");
			if (v.effectC == 1) {
				printf("활성화");
			}
			else {
				printf("비활성화");
			}
			printf("\n");
		}
		else {
			printf("????????????\n");
		}
		if (v.level >= 80) {
			printf("세계수의 가호  ");
			if (v.effectD == 1) {
				printf("활성화");
			}
			else {
				printf("비활성화");
			}
			printf("\n");
		}
		else {
			printf("?????????????\n");
		}
		if (v.level >= 100) {
			printf("초월한 힘  ");
			if (v.effectFin == 1) {
				printf("활성화");
			}
			else {
				printf("비활성화");
			}
			printf("\n");
		}
		else {
			printf("???????\n");
		}
		printf("나가기");
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
			printf("나무가 아직 충분히 성장하지 않았습니다.");
			error = 0;
		}
		else if (error == 4) {
			return v;
		}
		if (s == 1) {
			gotoxy(0, 0);
			printf("나무가 성장할 때 20만큼 추가 성장을 합니다.(영양제와 생명과학 이론의 영향을 받지 않습니다.)\n나무 성장치 Lv.20에서 해금");
			gotoxy(22, 4);
		}
		else if (s == 2) {
			gotoxy(0, 0);
			if (v.level >= 40) {
				printf("작업 효율이 2 증가합니다.\n나무 성장치 Lv.40에서 해금");
			}

			gotoxy(22, 5);
		}
		else if (s == 3) {
			gotoxy(0, 0);
			if (v.level >= 60) {
				printf("나무가 성장할 때 20만큼 추가 성장을 합니다.(영양제와 생명과학 이론의 영향을 받지 않습니다.) 또한 작업 효율이 1 증가합니다.\n나무 성장치 Lv.60에서 해금");
			}

			gotoxy(24, 6);
		}
		else if (s == 4) {
			gotoxy(0, 0);
			if (v.level >= 80) {
				printf("나무 제품 판매 시 개당 1000원을 추가로 얻습니다.\n나무 성장치 Lv.80에서 해금");
			}

			gotoxy(24, 7);
		}
		else if (s == 5) {
			gotoxy(0, 0);
			if (v.level >= 100) {
				printf("작업 효율이 1000 증가합니다.\n나무 성장치 Lv.100에서 해금");
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