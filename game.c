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
	SetConsoleTitle("나무키우기");
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
			printf("정말 종료하시겠습니까?\n이 버전은 저장과 불러오기를 지원하지 않습니다.\n\n");
			printf("y를 눌러주세요>");
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
			else if (place == 3) {//돈
				var tmp = work(v);
				v = tmp;
				//money = working(money, work_wood_Lv, work_doll_Lv, work_tool_Lv, work_furn_Lv, work_house_Lv, work_efficiency);
			}
			else if (place == 4) {//상점
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
		printf("나는 대대적으로 목재 제품 제작업을 해오는 가문의 자손이다.\n");
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

void CursorView() {
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1; //커서 굵기 (1 ~ 100)
	cursorInfo.bVisible = FALSE; //커서 Visible TRUE(보임) FALSE(숨김)
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

var start_select(int num, int num2, int cleared, int level, var a) {  //메인 인터페이스
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
		printf("들어가기\n\n종료");
		gotoxy(0, 1);
		printf("뒷마당  집  작업소  잡화점  서점  판매점");
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
			printf("뽀삐와 대화하기");
			gotoxy(2, 2);
		}
		else if (v == 2) {
			gotoxy(0, 5);
			printf("아버지와 대화하기");
			gotoxy(8, 2);
		}
		else if (v == 3) {
			gotoxy(0, 5);
			printf("동네 꼬마와 대화하기");
			gotoxy(14, 2);
		}
		else if (v == 4) {
			gotoxy(0, 5);
			printf("김 아저씨와 대화하기");
			gotoxy(22, 2);
		}
		else if (v == 5) {
			gotoxy(0, 5);
			printf("카르멘과 대화하기");
			gotoxy(29, 2);
		}
		else if (v == 6) {
			gotoxy(0, 5);
			printf("형우와 대화하기");
			gotoxy(36, 2);
		}
		printf("@");
		if (cleared == 1) {
			gotoxy(0, 20);
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
							printf("뽀삐)\n야옹~\n\n(귀엽다.)");
						}
						else if (v == 2) {
							system("cls");
							printf("\n\n\n\n");
							printf("들어가기\n\n종료");
							gotoxy(0, 1);
							printf("뒷마당  집  작업소  잡화점  서점  판매점");
							gotoxy(0, 8);
							printf("-------------------------------------------------------------");
							gotoxy(0, 5);
							printf("아버지와 대화하기 <");
							if (t.questA== 0) {

								gotoxy(0, 9);
								printf("아버지)\n하...나사가 어디있지...?");

							}
							else if (t.questA == 1) {
								gotoxy(0, 9);
								printf("아버지)\n아, 마침 잘 왔다.\n잠깐 시간 되니?\n\nz > 네 아버지 무슨일이신가요?\nx > 아뇨 바빠요.\nc > (무시한다.)\n\n");
								while (1) {
									char d = _getch();
									if (d == 'z') {
										printf("네 아버지 무슨일이신가요?\n\n아버지)\n그... 조만간 집에 출장간 네 형이 돌아올 건데, 네 형의 침대를 저번에 김씨랑 고스톱한다고 팔아버려서 말이야.\n\n아 그러게 도박좀 그만하라 했잖아요.\n\n아버지)\n흠흠; 아무튼 네 형 침대를 다시 만들려는데 내가 급하게 납품할 물품이 있어서 그런데 침대 하나만 만들어줄 수 있겠니?\n\nz > 아 네 당연하죠\nx > 어.. 저도 안될거같은데\n\n");

										while (1) {
											d = _getch();
											if (d == 'z') {
												printf("아 네 당연하죠\n\n아버지)\n아..! 한숨 놓았네. 그럼 부탁할게.\n\n(목재 가구 5개를 만들어 가져오자.)");
												t.questA = 2;
												break;
											}
											else if (d == 'x') {
												printf("어.. 저도 안될거같은데\n\n아버지)\n아아... 어떡하지...");
												break;
											}
										}
										break;
									}
									else if (d == 'x') {
										printf("아뇨 바빠요.\n\n아버지)\n음..그래..? 그럼 일 끝나고 잠깐 와주면 좋겠구나.\n\n(일이 끝나면 잠깐 찾아오자.)");
										break;
									}
									else if (d == 'c') {
										printf("아버지)\n저 저 싸가지 없는 놈이");
										break;
									}

								}
							}
							else if (t.questA == 2 && t.gD >= 5) {
								gotoxy(0, 9);
								printf("아버지)\n오, 만들어 왔니? 수고했어. 여기 집에 안쓰는 제품 가져가서 팔아가지고 너 용돈으로 써.\n\n(아빠가 뭔갈 많이 챙겨주셨다.)\n(가공된 목재 100개, 목재 도구 10개, 목재 가구 2개를 얻었다!)");
								t.gD -= 5;
								t.gA += 100;
								t.gC += 10;
								t.gD += 2;
								t.questA = 3;
							}
							else if (t.questA == 2) {
								gotoxy(0, 9);
								printf("아버지)\n하... 재섭이가 좀만 늦게 와야 할텐데... \n\n(목재 가구 5개를 만들어 가져오자.)");
							}
							else if (t.questA == 3) {
								gotoxy(0, 9);
								printf("아버지)\n드르렁....\n\n(자고 계신다. 조용히 지나가자.)");
							}

						}
						else if (v == 3) {
							system("cls");
							printf("\n\n\n\n");
							printf("들어가기\n\n종료");
							gotoxy(0, 1);
							printf("뒷마당  집  작업소  잡화점  서점  판매점");
							gotoxy(0, 8);
							printf("-------------------------------------------------------------");
							gotoxy(0, 5);
							printf("동네 꼬마와 대화하기 <");
							if (t.questB == 0) {
								
								gotoxy(0, 9);
								printf("동네 꼬마)\n흐아암...");
								
							}
							else if (t.questB == 1) {
								gotoxy(0, 9);
								printf("동네 꼬마)\n으에엥~~~~ㅠㅠㅠㅠㅠㅠ\n\n(동네 꼬마가 울고 있다.)\nz > 꼬마야 무슨 일이니?\nx > (그냥 지나간다.)\nc > 잼민아 시끄러우니 집에 가서 울렴.\n\n");
								while (1) {
									char d = _getch();
									if (d == 'z') {
										printf("꼬마야 무슨 일이니?\n\n동네 꼬마)\n제 인형을.. 어떤 고양이가 물어갔어요ㅠㅠㅠㅠㅠㅠ\n\n(이 마을에 고양이는 집에서 못나가는 우리 뽀삐밖에 없을 텐데. 그리고 그와중에 내 작업소 앞에서 이러고 있군.)\nz > 형이 인형 하나 만들어줄까?\nx > 잼민아 어린나이에 벌써 사기치지 말고 집에서 발닦고 자렴^^\n\n");

										while (1) {
											d = _getch();
											if (d == 'z') {
												printf("동네 꼬마)\n(울음기가 싹 사라지며)와!!! 감사합니다!!!!\n\n(목재 인형 한개를 가져다 주자.)");
												t.questB = 2;
												break;
											}
											else if (d == 'x') {
												printf("동네 꼬마)\n에이씨 눈치는 더럽게 빨라가지고.\n\(꼬마는 저 멀리 도망쳤다. 잼민이가 어디서 어른을 등쳐먹으려고.)");
												break;
											}
										}
										break;
									}
									else if (d == 'x') {
										printf("동네 꼬마)\n으에엥~~~~ㅠㅠㅠㅠㅠㅠ\n\n(시끄럽다.)");
										break;
									}
									else if (d == 'c') {
										printf("꼬마야 시끄러우니 집에 가서 울렴.\n\n동네 꼬마)\n후에엥ㅠㅠㅠㅠㅠㅠㅠㅠㅠㅠㅠㅠㅠㅠㅠㅠㅠㅠㅠㅠㅠㅠㅠ\n\n(혹시 당신은 쓰레기인가?)");
										break;
									}

								}
							}
							else if (t.questB == 2 && t.gB >= 1) {
								gotoxy(0, 9);
								printf("동네 꼬마)\n와!!ㅋㅋㅋㅋㅋ감사합니다ㅋㅋㅋㅋㅋㅋㅋㅋ\n\n(꼬마는 인형을 받고 저 멀리 가버렸다.)\n(여기 뭔갈 떨어트렸는데, 식물 영양제?)\n(내가 챙겨갈까?)\nz > (챙긴다.)\nx > (그냥 둔다.)\n\n");
								t.gB--;
								t.questB = 3;
								while (1) {
									char d = _getch();
									if (d == 'z') {
										t.drug++;
										printf("(영양제를 하나 얻었다!)");										
										break;
									}
									else if (d == 'x') {
										printf("(에이, 알아서 잘 찾아가겠지.)");
										break;
									}
								}
							}
							else if(t.questB == 2)  {
								gotoxy(0, 9);
								printf("동네 꼬마)\n으히히...\n\n(목재 인형 한개를 가져다 주자.)");
							}
							else if (t.questB == 3) {
								gotoxy(0, 9);
								printf("동네 꼬마)\n어딨지...?\n\n(무언갈 계속 찾고 있다.)");
							}
							
						}
						else if (v == 4) {
						system("cls");
						printf("\n\n\n\n");
						printf("들어가기\n\n종료");
						gotoxy(0, 1);
						printf("뒷마당  집  작업소  잡화점  서점  판매점");
						gotoxy(0, 8);
						printf("-------------------------------------------------------------");
						gotoxy(0, 5);
						printf("김 아저씨와 대화하기 <");
						if (t.questC == 0) {

							gotoxy(0, 9);
							printf("아저씨)\n자자, 여러분! 쌉니다 싸요! 10만원짜리 운동화가 지금 사면 8만원!\n\n아저씨 그거 옆마을에서 만원에 샀잖아요.\n\n(사람들이 욕을 하며 떠난다.)\n\n아저씨)\n(작은 목소리로)아잇..! 좀 가만히 있지!");

						}
						else if (t.questC == 1) {
							gotoxy(0, 9);
							printf("아저씨)\n야야 너 망치 좀 만들어줄 수 있냐? 급하게 한 25개정도 필요한데;\n\nz > 네 뭐 만들어 올테니 잠깐 있어봐요.\nx > 저 지금 바빠요.\n\n");
							while (1) {
								char d = _getch();
								if (d == 'z') {
									printf("네 뭐 만들어 올테니 잠깐 있어봐요.\n\n아저씨)\n아 다행이다! 좀 살겠네.\n\n(목재 도구 25개를 만들어 가져오자.)");
									t.questC = 2;
									break;
								}
								else if (d == 'x') {
									printf("저 지금 바빠요.\n\n아저씨)\n으아;;미치겠네...어떡하지..?\n\n(나였으면 저럴 시간에 옆마을 가서 사오겠다.)");
									break;
								}
							}
						}
						else if (t.questC == 2 && t.gC >= 5) {
							gotoxy(0, 9);
							printf("아저씨)\n아! 진짜 고맙다. 뭐 줄건 없고 전에 너땜에 못팔았던 운동화라도 너 가져라.\n\n(운동화를 신었다.)\n(발걸음이 가벼워졌다!)");
							t.gC -= 25;
							t.shoes = 1;
							t.questC = 3;
						}
						else if (t.questC == 2) {
							gotoxy(0, 9);
							printf("(초조한 듯 발을 구르고 있다. 굳이 말 걸진 말자.)\n\n(목재 도구 25개를 만들어 가져오자.)");
						}
						else if (t.questC == 3) {
							gotoxy(0, 9);
							printf("아저씨)\n자자, 여러분! 이번엔 진짭니다! 20만원짜리 쇠도끼가 지금 사면 12만원!\n\n(사람들이 안 믿고 욕을 하며 떠난다.)\n\n(저거 원래 30만원인데. 그러게 사기좀 그만 치지.)");
						}

						}
						else if (v == 5) {
						system("cls");
						printf("\n\n\n\n");
						printf("들어가기\n\n종료");
						gotoxy(0, 1);
						printf("뒷마당  집  작업소  잡화점  서점  판매점");
						gotoxy(0, 8);
						printf("-------------------------------------------------------------");
						gotoxy(0, 5);
						printf("카르멘과 대화하기 <");
						if (t.questD == 0) {
							gotoxy(0, 9);
							if (t.dutch == 0) {
								printf("카르멘)\nWo habe ich meinen Stift hingelegt ...\n\n(뭐라는 거지...)");
							}
							else if (t.dutch == 1) {
								printf("카르멘)\nWo habe ich meinen Stift hingelegt ...(내가 펜을 어디에 뒀더라...)\n\nDu steckst es in dein Ohr.(귀에 끼워두셨잖아요.)\n\n카르멘)\nAh, danke.(아, 고마워요.)");
							}
							

						}
						else if (t.questD == 1) {
							gotoxy(0, 9);
							if (t.dutch == 0) {
								printf("카르멘)\nOh, du bist gerade gekommen!\nBald wird mein Freund in diese Stadt kommen, um eine Weile zu leben.\nHaben Sie ein Haus, das Sie nicht nutzen?\nWenn du ein Haus mietest, gebe ich dir etwas Gutes.\n\nz > (뭐라는 거야...)\nx > (뭐라는 거야...)\nc > Uh...아임파인땡큐?\n\n");
								while (1) {
									char d = _getch();
									if (d == 'z' || d == 'x') {
										printf("카르멘)\nGeh weg, du Idiot.\n\n(진짜 뭐라는거야...)");
										break;
									}
									if (d == 'c') {
										printf("카르멘)\nWenn Sie dumm sind, bleiben Sie still.\n\n(진짜 뭐라는거야...)");
										break;
									}
								}
							}
							else if(t.dutch == 1) {
								printf("카르멘)\nOh, du bist gerade gekommen!(아, 마침 잘 왔어요!)\nBald wird mein Freund in diese Stadt kommen, um eine Weile zu leben.(조만간 내 친구가 이 마을로 와서 잠시 살 예정이에요.)\nHaben Sie ein Haus, das Sie nicht nutzen?(혹시 안쓰는 집이 하나 있을까요?)\nWenn du ein Haus mietest, gebe ich dir etwas Gutes.(집 한채만 빌려주면 내가 좋은 걸 드리죠.)\n\nz > Oh, ich werde einen machen.(아, 제가 하나 만들어드릴게요.)\nx > Nein, ich kann dir nicht helfen.(이런, 도와드릴 수가 없네요.)\nc > Wachsen Sie es auf dem Boden.(길바닥에서 자라고 하세요.)\n\n");
								while (1) {
									char d = _getch();
									if (d == 'z') {
										printf("카르멘)\nOh danke. Dann frage ich dich.(아, 고마워요. 그럼 부탁할게요.)\n\n(목재 집 한채를 지어주자.)");
										t.questD = 2;
										break;
									}
									if (d == 'x') {
										printf("카르멘)\nDas ist sehr schade. Was machen wir...(아쉽네요. 어떡하지...)");
										break;
									}
									if (d == 'c') {
										printf("카르멘)\nMein Freund ist nicht obdachlos.(내 친구는 노숙자가 아닙니다.)");
										break;
									}
								}
							}
						
						}
						else if (t.questD == 2 && t.gE >= 1) {
							gotoxy(0, 9);
							printf("카르멘)\nOh vielen Dank.(아, 정말 감사합니다. )\nAls Gegenleistung werde ich dir diese Bibel geben.(답례로 이 성경을 드리겠습니다.)\nDas ist heutzutage schwer zu finden.(요즘은 찾아보기 힘든 물건입니다.)\n\n(성경을 얻었다. 마음이 불안정할 때 마다 읽어보자.)");
							t.gE -= 1;
							t.angel = 1;
							t.questD = 3;
						}
						else if (t.questD == 2) {
							gotoxy(0, 9);
							printf("카르멘)\nDanke dir immer.(언제나 감사드립니다.)\n\n(목재 집 1채를 지어오자.)");
						}
						else if (t.questD == 3) {
							gotoxy(0, 9);
							printf("카르멘)\nGott segne dich.(당신께 신의 축복이 있기를.)\n\nDanke.(감사합니다.)");
						}

						}
						else if (v == 6) {
							system("cls");
							printf("\n\n\n\n");
							printf("들어가기\n\n종료");
							gotoxy(0, 1);
							printf("뒷마당  집  작업소  잡화점  서점  판매점");
							gotoxy(0, 8);
							printf("-------------------------------------------------------------");
							gotoxy(0, 5);
							printf("형우와 대화하기 <");
							if (t.questE == 0) {

								gotoxy(0, 9);
								printf("형우)\n어...이번에 옆마을로 가야하나..아님 저 건너편?\n\n(요즘 판매점 운영이 힘든 것 같다. 그냥 지나가야겠다.)");

							}
							else if (t.questE == 1) {
								gotoxy(0, 9);
								printf("형우)\n야야야야야야야야야야야야야야야야ㅑ\n\nz > 무언가를 잘못 먹었니?\nx > 아 꺼져;\nc > (도망친다.)\n\n");
								while (1) {
									char d = _getch();
									if (d == 'z') {
										printf("무언가를 잘못 먹었니?\n\n형우)\n아 지금 장난칠 시간 없고! 나 급헤서 그런데 니 가공목재 500개만 만들어줄수 있어?\n\nz > 뭐...그래?\nx > 맨입으로?\nc > (엿을 날리며 도망친다.)\n\n");
										while (1) {
											char d = _getch();
											if (d == 'z') {
												printf("뭐...그래?\n\n형우)\n으아ㅏㅏ 진짜 고맙다 친구야! 그럼 부탁할게.\n\n(가공된 목재 500개를 가져다 주자.)");
												t.questE = 2;
												break;
											}
											else if (d == 'x') {
												printf("맨입으로?\n\n형우)\n아 그 저번에 그거있잖아 그거...너 줄테니깐 어케 안되냐?\n\n(조금 솔깃해진다. 만들어줄까?)\nz > ㅇㅋ 만들어줌\nx > ㄴㄴ 안만들어줌\n\n");
												while (1) {
													char d = _getch();
													if (d == 'z') {
														printf("ㅇㅋ 만들어줌\n\n형우)\n으아ㅏㅏ 진짜 고맙다 친구야! 그럼 부탁할게.\n\n(가공된 목재 500개를 가져다 주자.)");
														t.questE = 2;
														break;
													}
													else if (d == 'x') {
														printf("형우)아...이거 어떡하지...");
														break;
													}
												}
												break;
											}
											else if (d == 'c') {
												printf("(무사히 도망쳤다!)");
												break;
											}
										}
										break;
									}
									else if (d == 'x') {
										printf("아 꺼져;\n\n형우)\n아 제발;; 나 급헤서 그런데 니 가공목재 500개만 만들어줄수 있어?\n\nz > 뭐...그래?\nx > 맨입으로?\nc > (엿을 날리며 도망친다.)\n\n");
										while (1) {
											char d = _getch();
											if (d == 'z') {
												printf("뭐...그래?\n\n형우)\n으아ㅏㅏ 진짜 고맙다 친구야! 그럼 부탁할게.\n\n(가공된 목재 500개를 가져다 주자.)");
												t.questE = 2;
												break;
											}
											else if (d == 'x') {
												printf("맨입으로?\n\n형우)\n아 그 저번에 그거있잖아 그거...너 줄테니깐 어케 안되냐?\n\n(조금 솔깃해진다. 만들어줄까?)\nz > ㅇㅋ 만들어줌\nx > ㄴㄴ 안만들어줌\n\n");
												while (1) {
													char d = _getch();
													if (d == 'z') {
														printf("ㅇㅋ 만들어줌\n\n형우)\n으아ㅏㅏ 진짜 고맙다 친구야! 그럼 부탁할게.\n\n(가공된 목재 500개를 가져다 주자.)");
														t.questE = 2;
														break;
													}
													else if (d == 'x') {
														printf("형우)아...이거 어떡하지...");
														break;
													}
												}
												break;
											}
											else if (d == 'c') {
												printf("(무사히 도망쳤다!)");
												break;
											}
										}
										break;
									}
									else if (d == 'c') {
										printf("(무사히 도망쳤다!)");
										break;
									}
								}
							}
							else if (t.questE == 2 && t.gA >= 500) {
								gotoxy(0, 9);
								printf("형우)\n아 진짜 고맙다. 이거 너 가져라.\n\n(빨간 책을 얻었다!)");
								t.gA -= 500;
								t.devil = 1;
								t.questE = 3;
							}
							else if (t.questE == 2) {
								gotoxy(0, 9);
								printf("(초조한 표정으로 서류더미에 파묻혀있다.)\n\n(가공된 목재 500개를 만들어 가져오자.)");
							}
							else if (t.questE == 3) {
								gotoxy(0, 9);
								printf("형우)\n야 너 건물 하나 안필요하냐?\n저 옆마을에 누가 대장간 건물이랑 물건 싸게 내놨거든?\n\n강민이네 마을 대장간 말하는거야? 거기 망했어?\n\n거기 운영하시는 아줌마가 갑자기 부동산사업 하신대.\n\n(쇠톱 부러질 때마다 항상 거기서 사왔는데. 이젠 다른 대장간 찾아봐야 하나.)");
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
	printf("뒷마당  집  작업소  잡화점  서점  판매점");
	gotoxy(0, 8);
	printf("-------------------------------------------------------------");

	gotoxy(0, 5);
	printf("이동중...");
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
				printf("뒷마당  집  작업소  잡화점  서점  판매점");
				gotoxy(0, 8);
				printf("-------------------------------------------------------------");
				gotoxy(6, 2);
				printf("@");
				gotoxy(0, 5);
				printf("이동중...");
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
					printf("뒷마당  집  작업소  잡화점  서점  판매점");
					gotoxy(0, 8);
					printf("-------------------------------------------------------------");
					gotoxy(4, 2);
					printf("@");
					gotoxy(0, 5);
					printf("이동중...");
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
					printf("뒷마당  집  작업소  잡화점  서점  판매점");
					gotoxy(0, 8);
					printf("-------------------------------------------------------------");
					gotoxy(12, 2);
					printf("@");
					gotoxy(0, 5);
					printf("이동중...");
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
					printf("뒷마당  집  작업소  잡화점  서점  판매점");
					gotoxy(0, 8);
					printf("-------------------------------------------------------------");
					gotoxy(10, 2);
					printf("@");
					gotoxy(0, 5);
					printf("이동중...");
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
					printf("뒷마당  집  작업소  잡화점  서점  판매점");
					gotoxy(0, 8);
					printf("-------------------------------------------------------------");
					gotoxy(19, 2);
					printf("@");
					gotoxy(0, 5);
					printf("이동중...");
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
					printf("뒷마당  집  작업소  잡화점  서점  판매점");
					gotoxy(0, 8);
					printf("-------------------------------------------------------------");
					gotoxy(16, 2);
					printf("@");
					gotoxy(0, 5);
					printf("이동중...");
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
					printf("뒷마당  집  작업소  잡화점  서점  판매점");
					gotoxy(0, 8);
					printf("-------------------------------------------------------------");
					gotoxy(26, 2);
					printf("@");
					gotoxy(0, 5);
					printf("이동중...");
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
					printf("뒷마당  집  작업소  잡화점  서점  판매점");
					gotoxy(0, 8);
					printf("-------------------------------------------------------------");
					gotoxy(24, 2);
					printf("@");
					gotoxy(0, 5);
					printf("이동중...");
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
					printf("뒷마당  집  작업소  잡화점  서점  판매점");
					gotoxy(0, 8);
					printf("-------------------------------------------------------------");
					gotoxy(33, 2);
					printf("@");
					gotoxy(0, 5);
					printf("이동중...");
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
		printf("이동중...");
		while (1) {
			if (_kbhit()) {
				char e = _getch();
			}
			end = clock();
			if (end - start >= speed) {

				system("cls");
				gotoxy(0, 1);
				printf("뒷마당  집  작업소  잡화점  서점  판매점");
				gotoxy(0, 8);
				printf("-------------------------------------------------------------");
				gotoxy(31, 2);
				printf("@");
				gotoxy(0, 5);
				printf("이동중...");
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
				int incomeA = 15 + v.lvB * 12;
				int incomeB = 27 + v.lvB * 12;
				if (v.lvB == 0) {
					incomeA = 0;
					incomeB = 27;
				}
				gotoxy(0, 0);
				printf("읽을 시 목재 인형을 판매했을 때의 수입이 증가합니다.\n");
				printf("* 목재 인형 판매가 %d원 > %d원\n", incomeA, incomeB);
				printf("* 개수 : %d권", v.bB);
				gotoxy(4, 4);
				printf("목재 인형 제작서");
			}
			if (p == 3) {
				int incomeA = 200 + v.lvC * 150;
				int incomeB = 350 + v.lvC * 150;
				if (v.lvB == 0) {
					incomeA = 0;
					incomeB = 350;
				}
				gotoxy(0, 0);
				printf("읽을 시 목재 도구를 판매했을 때의 수입이 증가합니다.\n");
				printf("* 목재 도구 판매가 %d원 > %d원\n", incomeA, incomeB);
				printf("* 개수 : %d권", v.bC);
				gotoxy(4, 4);
				printf("목재 도구 제작서");
			}
			if (p == 4) {
				int incomeA = 1500 + v.lvD * 1000;
				int incomeB = 2500 + v.lvD * 1000;
				if (v.lvB == 0) {
					incomeA = 0;
					incomeB = 2500;
				}
				gotoxy(0, 0);
				printf("읽을 시 목재 가구를 판매했을 때의 수입이 증가합니다.\n");
				printf("* 목재 가구 판매가 %d원 > %d원\n", incomeA, incomeB);
				printf("* 개수 : %d권", v.bD);
				gotoxy(4, 4);
				printf("목재 가구 제작서");
			}
			if (p == 5) {
				int incomeA = 8000 + v.lvE * 6000;
				int incomeB = 14000 + v.lvE * 6000;
				if (v.lvB == 0) {
					incomeA = 0;
					incomeB = 14000;
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
			if (p == 8) {
				gotoxy(0, 0);
				printf("읽을 시 독일어로 대화 할 수 있습니다.\n");
				printf("* 개수 : %d권", v.bDutch);
				gotoxy(4, 4);
				printf("당신도 할 수 있다! 독일어 회화");
			}
			if (p >= 9 && p <= 13) {
				gotoxy(0, 0);
				printf("별로 재미있을 것 같진 않은 역사책입니다.\n");
				printf("* 개수 : %d권", 1);
				gotoxy(4, 4);
				printf("잃어버리지 않은 역사 - %d권", p - 8);
			}
			if (p == 14) {
				gotoxy(0, 0);
				printf("읽을 시 불순한 마음이 정화됩니다.\n");
				printf("* 개수 : %d권", v.angel);
				gotoxy(4, 4);
				printf("성경");
			}
			if (p == 15) {
				gotoxy(0, 0);
				printf("읽을 시...\n");
				printf("* 개수 : %d권", v.devil);
				gotoxy(4, 4);
				printf("빨간 책");
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
	int level = 1 + v.shoes + v.effectB;
	if (v.effectFin == 1) {
		level = 999;
	}
	printf("\n이동 속도 Lv.%d\n", level);
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
			printf("돈이 부족합니다.     ");
			error = 0;
		}
		else if (error == 4) {
			gotoxy(0, 18);
			printf("더이상 구매할 수 없습니다.");
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

	var v = a;

	int s = 1;
	int error = 0;
	char select = NULL;
	while (1) {
		system("cls");
		printf("\n\n\n\n");
		printf("목재 가공 이론서\n목재 인형 제작서\n목재 도구 제작서\n목재 가구 제작서\n목재 집 건축 이론서\n작업 효율성 이론서\n생명과학 이론서\n당신도 할 수 있다! 독일어 회화\n잃어버리지 않은 역사 - 1권\n잃어버리지 않은 역사 - 2권\n잃어버리지 않은 역사 - 3권\n잃어버리지 않은 역사 - 4권\n잃어버리지 않은 역사 - 5권\n나가기");
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

			printf("목재 가공 이론서(재고:%d)\n목재 가공에 대한 능력을 키웁니다.\n현재 Lv.%d  필요 자금:%d원", 100 - sum, v.lvA, 10 + sum * 11);
			gotoxy(17, 4);
		}
		else if (s == 2) {
			int sum = v.lvB + v.bB;
			gotoxy(0, 0);
			printf("목재 인형 제작서(재고:%d)\n목재 인형 제작에 대한 능력을 키웁니다.\n현재 Lv.%d  필요 자금:%d원  필요 조건:목재 가공 이론 Lv.%d", 100 - sum, v.lvB, 26 + sum * 13, 50);
			gotoxy(17, 5);
		}
		else if (s == 3) {
			gotoxy(0, 0);
			int sum = v.lvC + v.bC;
			printf("목재 도구 제작서(재고:%d)\n목재 도구 제작에 대한 능력을 키웁니다.\n현재 Lv.%d  필요 자금:%d원  필요 조건:목재 인형 제작 Lv.%d", 100 - sum, v.lvC, 52 + sum * 44, 50);
			gotoxy(17, 6);
		}
		else if (s == 4) {
			gotoxy(0, 0);
			int sum = v.lvD + v.bD;
			printf("목재 가구 제작서(재고:%d)\n목재 가구 제작에 대한 능력을 키웁니다.\n현재 Lv.%d  필요 자금:%d원  필요 조건:목재 도구 제작 Lv.%d", 100 - sum, v.lvD, 189 + sum * 171, 50);
			gotoxy(17, 7);
		}
		else if (s == 5) {
			gotoxy(0, 0);
			int sum = v.lvE + v.bE;
			printf("목재 집 건축 이론서(재고:%d)\n목재 집 건축에 대한 능력을 키웁니다.\n현재 Lv.%d  필요 자금:%d원  필요 조건:목재 가구 제작 Lv.%d", 100 - sum, v.lvE, 360 + sum * 232, 50);
			gotoxy(20, 8);
		}
		else if (s == 6) {
			gotoxy(0, 0);
			int sum = v.ef + v.bEF;
			printf("작업 효율성 이론서(재고:%d)\n작업의 효율성을 키웁니다.\n현재 Lv.%d  필요 자금:%d원", 10 - sum, v.ef, 10000 + 2500 * (v.bEF + v.ef) * (v.bEF + v.ef));
			gotoxy(19, 9);
		}
		else if (s == 7) {
			gotoxy(0, 0);
			printf("생명과학 이론서(재고:%d)\n나무의 성장 효율을 높일 수 있습니다.\n성장도 증가 : x1.5  필요 자금:10500원", 1 - v.bT - v.readed);
			gotoxy(16, 10);
		}
		else if (s == 8) {
			gotoxy(0, 0);
			printf("당신도 할 수 있다! 독일어 회화(재고:%d)\n독일어를 배울 수 있습니다. 배워봤자 의미는 없을것 같지만, 여기 사장이랑 대화는 할 수 있겠네요.\n필요 자금:30000원", 1 - v.bDutch - v.dutch);
			gotoxy(31, 11);
		}
		else if (s == 9) {
			gotoxy(0, 0);
			printf("잃어버리지 않은 역사 - 1권(재고:%d)\n구석에 박혀있던 역사책입니다. 별로 재미있을 것 같지는 않네요.\n필요 자금:5000원", 1 - v.sA);
			gotoxy(27, 12);
		}
		else if (s == 10) {
			gotoxy(0, 0);
			printf("잃어버리지 않은 역사 - 2권(재고:%d)\n구석에 박혀있던 역사책입니다. 별로 재미있을 것 같지는 않네요.\n필요 자금:5000원", 1 - v.sB);
			gotoxy(27, 13);
		}
		else if (s == 11) {
			gotoxy(0, 0);
			printf("잃어버리지 않은 역사 - 3권(재고:%d)\n구석에 박혀있던 역사책입니다. 별로 재미있을 것 같지는 않네요.\n필요 자금:5000원", 1 - v.sC);
			gotoxy(27, 14);
		}
		else if (s == 12) {
			gotoxy(0, 0);
			printf("잃어버리지 않은 역사 - 4권(재고:%d)\n구석에 박혀있던 역사책입니다. 별로 재미있을 것 같지는 않네요.\n필요 자금:5000원", 1 - v.sD);
			gotoxy(27, 15);
		}
		else if (s == 13) {
			gotoxy(0, 0);
			printf("잃어버리지 않은 역사 - 5권(재고:%d)\n구석에 박혀있던 역사책입니다. 별로 재미있을 것 같지는 않네요.\n필요 자금:5000원", 1 - v.sE);
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
			printf("목재 인형\n수량 : %d  수입 : %d\na로 1개씩 판매, s로 일괄 판매", v.gB, 15 + a.lvB * 12 + a.effectD * 1000);
			gotoxy(15, 5);
		}
		else if (s == 3) {
			gotoxy(0, 0);
			printf("목재 도구\n수량 : %d  수입 : %d\na로 1개씩 판매, s로 일괄 판매", v.gC, 200 + a.lvC * 150 + a.effectD * 1000);
			gotoxy(15, 6);
		}
		else if (s == 4) {
			gotoxy(0, 0);
			printf("목재 가구\n수량 : %d  수입 : %d\na로 1개씩 판매, s로 일괄 판매", v.gD, 1500 + a.lvD * 1000 + a.effectD * 1000);
			gotoxy(15, 7);
		}
		else if (s == 5) {
			gotoxy(0, 0);
			printf("목재 집\n수량 : %d  수입 : %d\na로 1채씩 판매, s로 일괄 판매", v.gE, 8000 + a.lvE * 6000 + a.effectD * 1000);
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
	var v = a;

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
				printf("작업 효율이 2 증가합니다. 또한 마을을 이동하는 속도가 증가합니다.\n나무 성장치 Lv.40에서 해금");
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
				printf("작업 효율이 1000 증가하며 순간이동을 할 수 있습니다.\n나무 성장치 Lv.100에서 해금");
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
		printf("내가 기른 나무.. 아니 세계수가 하늘을 뚫었다.\n");
	}
	if (num > 3) {
		printf("....\n");
	}
	if (num > 4) {
		printf("아름답다.\n");
	}
	if (num > 5) {
		printf("내 앞에 선 한 그루의 세계수는 그 자체만으로도 영롱한 자태를 보이고 있었다.\n");
	}
	if (num > 6) {
		printf(".\n");
	}
	if (num > 7) {
		printf(".\n");
	}
	if (num > 8) {
		printf("세계수의 영향일까, 우리 마을은 급속도로 성장하기 시작했다.\n");
	}
	if (num > 9) {
		printf("사람들은 몸도 마음도 강해져갔고, 황폐해보였던 마을 주변 환경도 풀이 가득해 아름다워졌다.\n");
	}
	if (num > 10) {
		printf(".\n");
	}
	if (num > 11) {
		printf(".\n");
	}
	if (num > 12) {
		printf("하늘을 뚫어낸 한 그루의 세계수 앞의 나는 한 가지 느낌이 몰려왔다.\n");
	}
	if (num > 13) {
		printf("말로 표현할 수 없는 이 느낌, 마치 하나의 깨달음과도 같았다.\n");
	}
	if (num > 14) {
		printf("이 깨달음은 나의 힘이 되었고, 나는 이 세상의 모든 현상을 이해할 수 있었다.\n");
	}
	if (num > 15) {
		printf(".\n");
	}
	if (num > 16) {
		printf(".\n");
	}
	if (num > 17) {
		printf("나는 마을을 벗어나 여러 마을, 여러 국가을 찾아가며 나의 힘을 사용했다.\n");
	}
	if (num > 18) {
		printf("내가 지나간 곳은 그저 아름답고 잔잔한 자연이 펼쳐졌다.\n");
	}
	if (num > 19) {
		printf("자연이 회복된 이 세상은 전쟁 이전의 삶으로 살짝 돌아간 모습으로 변했다. 마치, 1시대와도 같았다.\n");
	}
	if (num > 20) {
		printf("그렇게 세상은 지금까지의 모습과 크게 바뀌었고, 사람들은 나의 나무가 하늘을 뚫은 날, 그 시점을 제 3시대라고 부르기 시작했다.\n");
	}
	if (num > 21) {
		printf("제 3시대의 인류는 2시대보다 훨씬 발전했고, 1시대의 실수를 반복하지 않았다.\n");
	}
	if (num > 22) {
		printf("난 매우 만족스러웠다.\n");
	}
	if (num > 23) {
		printf(".\n");
	}
	if (num > 24) {
		printf(".\n");
	}
	if (num > 25) {
		printf("이 모든 것은 당신이 만들었습니다.\n");
	}
	if (num > 26) {
		printf("네, 당신 말이에요. 이 밖의 당신.\n");
	}
	if (num > 27) {
		printf("이 공간도 언젠간 사라질 테고, 당신은 우릴 잊겠죠.\n");
	}
	if (num > 28) {
		printf("하지만 적어도 이 공간이 사라지기 전까진 여기서 잠시 즐기다 가셨으면 좋겠네요.\n");
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
		printf("~잃어버리지 않은 역사 01~\n");
	}
	if (num > 1) {
		printf(".\n");
	}
	if (num > 2) {
		printf(".\n");
	}
	if (num > 3) {
		printf("제 1시대 2043년 7월 12일\n");
	}
	if (num > 4) {
		printf("세계 3차 대전이 발발하였다.\n");
	}
	if (num > 5) {
		printf("전 세계 인구는 절반 이상 죽어나갔고,\n");
	}
	if (num > 6) {
		printf("사회 시스템은 마비된 지 오래다.\n");
	}
	if (num > 7) {
		printf("지구에서 황폐화되지 않은 곳을 찾아볼 수 없었다.\n");
	}
	if (num > 8) {
		printf("그러나 전쟁이 끝날 기미는 보이지 않았다.\n");
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
		printf("~잃어버리지 않은 역사 02~\n");
	}
	if (num > 1) {
		printf(".\n");
	}
	if (num > 2) {
		printf(".\n");
	}
	if (num > 3) {
		printf("제 1시대 2065년 2월 26일\n");
	}
	if (num > 4) {
		printf("드디어 전쟁이 끝이 났다. \n");
	}
	if (num > 5) {
		printf("전쟁을 할 군인이 모두 죽어버렸기 때문이였다.\n");
	}
	if (num > 6) {
		printf("남아있는 인류는 전쟁 이전의 20%% 뿐이였다.\n");
	}
	if (num > 7) {
		printf("이전의 역사는 유실되었다.\n");
	}
	if (num > 8) {
		printf("이미 세상은 반쯤 멸망했다.\n");
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
		printf("~잃어버리지 않은 역사 03~\n");
	}
	if (num > 1) {
		printf(".\n");
	}
	if (num > 2) {
		printf(".\n");
	}
	if (num > 3) {
		printf("제 1시대 2066년 6월 7일, 제 2시대 1년 1월 1일\n");
	}
	if (num > 4) {
		printf("그러나 인류는 강했고, 남아있는 인류는 이전으로 돌아가기 위한 체계를 확립했다.\n");
	}
	if (num > 5) {
		printf("각 국가에서 살아남은 사람들은 대표를 뽑았고,\n");
	}
	if (num > 6) {
		printf("자체적으로 마을을 만들어 어떻게든 살아나갔다.\n");
	}
	if (num > 7) {
		printf(".\n");
	}
	if (num > 8) {
		printf(".\n");
	}
	if (num > 9) {
		printf("어느 날, 모든 대표는 모여 삶을 되돌리기 위한 회의를 하였다.\n");
	}
	if (num > 10) {
		printf("그렇게 모든 대표들이 모인 첫 회의가 시작된 날, \n");
	}
	if (num > 11) {
		printf("그 날을 제 2시대의 1년 1월 1일 이라 칭하였다.\n");
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
		printf("~잃어버리지 않은 역사 04~\n");
	}
	if (num > 1) {
		printf(".\n");
	}
	if (num > 2) {
		printf(".\n");
	}
	if (num > 3) {
		printf("제 2시대 3년 6월 3일\n");
	}
	if (num > 4) {
		printf("황폐화된 자연들을 복구하기 위해 세 사람이 모였다..\n");
	}
	if (num > 5) {
		printf("한 명은 생명과학을 연구하던 교수,\n");
	}
	if (num > 6) {
		printf("다른 한 명은 유전공학 기술의 발전에 큰 기여를 했던 과학자,\n");
	}
	if (num > 7) {
		printf("나머지 한 명은 유전자 변형 기술의 개발자였다.\n");
	}
	if (num > 8) {
		printf("그들을 중심으로 많은 연구원들은 지구의 환경을 복원하기 위해 노력하였고,\n");
	}
	if (num > 9) {
		printf("그 과정에서 유전자가 개조된 묘목이 하나 만들어졌다.\n");
	}
	if (num > 10) {
		printf("세계의 중심이 될 거대한 나무, 일명 세계수를 키워냄으로서\n");
	}
	if (num > 11) {
		printf("지구 전체의 환경을 정상화하자는 취지에서 제작되었지만,\n");
	}
	if (num > 12) {
		printf("나무를 키워내는 데 들 어마무시한 자본으로 인해 무산되었다.\n");
	}
	if (num > 13) {
		printf("묘목은 이후 추가적인 연구를 위해 자료실에 보관되었다.\n");
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
		printf("~잃어버리지 않은 역사 05~\n");
	}
	if (num > 1) {
		printf(".\n");
	}
	if (num > 2) {
		printf(".\n");
	}
	if (num > 3) {
		printf("제 2시대 21년 3월 7일\n");
	}
	if (num > 4) {
		printf("묘목의 추가적인 연구를 통해 세계수 프로젝트의 재개가 논의되었다.\n");
	}
	if (num > 5) {
		printf("묘목이 보관된 자료실은 원래 식물이 자랄 수 없는 환경을 가지고 있었으나,\n");
	}
	if (num > 6) {
		printf("묘목이 있었던 지점으로부터 풀이 자라기 시작한 것이였다.\n");
	}
	if (num > 7) {
		printf("그 외에도, 그 묘목의 주변에 있던 연구원으로부터의 발언에 따르면\n");
	}
	if (num > 8) {
		printf("묘목 주변에 있는 것만으로도 정신이 맑아지고, 신체 기능이 원활해졌다고 한다.\n");
	}
	if (num > 9) {
		printf("이러한 이유들로 세계수 프로젝트는 마침내 재개되기로 결정되었다.\n");
	}
	if (num > 10) {
		printf(".\n");
	}
	if (num > 11) {
		printf(".\n");
	}
	if (num > 12) {
		printf("~제 2시대 25년 3월 25일~\n");
	}
	if (num > 13) {
		printf("세계수 프로젝트의 시작일이 다가왔다.\n");
	}
	if (num > 14) {
		printf("묘목을 심을 지점은 개발에 가장 크게 기여한 생명공학 교수의 고향인 대한민국의 서울이였던 곳으로 정해졌다.\n");
	}
	if (num > 15) {
		printf(".\n");
	}
	if (num > 16) {
		printf(".\n");
	}
	if (num > 17) {
		printf("~제 2시대 25년 4월 1일~\n");
	}
	if (num > 18) {
		printf("세계수 프로젝트가 시작될 날이였지만, 문제가 하나 생겼다.\n");
	}
	if (num > 19) {
		printf("서울에 도착하기 전까지 제자리에 있었던 묘목이 갑자기 사라진 것이다.\n");
	}
	if (num > 20) {
		printf("수많은 연구진들을 동원해 수색에 나섰으나, 결국 찾지 못했다.\n");
	}
	if (num > 21) {
		printf("결국 프로젝트는 묘목을 어떻게든 비슷하게 구현한 모조품을 사용하게 되었지만, 원래의 묘목보다는 실용성이 크게 떨어졌다.\n");
	}
	if (num > 22) {
		printf("묘목의 수색은 그 10년 후인 35년에 무산되었다.\n");
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
		printf("그 작던 묘목이 이젠 나름 나무의 모습이 되었다.\n");
	}
	if (num > 3) {
		printf("한 내 무릎정도 되려나?\n");
	}
	if (num > 4	) {
		printf("신기하게 나무 옆에만 있으면 마음이 편안해지는 듯하다.\n");
	}
	if (num > 5) {
		printf("이렇게 계속 키워보자.\n");
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
		printf("나무가 자라더니 열매를 맺었다.\n");
	}
	if (num > 3) {
		printf("왠지 모르게 기쁨이 느껴진다.\n");
	}
	if (num > 4) {
		printf("이전보다 더 체력이 좋아진 것 같기도 하다.\n");
	}
	if (num > 5) {
		printf("...계속 키워보자.\n");
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
		printf("항상 느껴져왔지만 이 나무는 정말 신비하다.\n");
	}
	if (num > 3) {
		printf("오늘따라 그 신비함이 더 크게 느껴진다.\n");
	}
	if (num > 4) {
		printf("그 많은 비료와 물을 먹고 자란 나무의 모습은 정말로 아름다웠다.\n");
	}
	if (num > 5) {
		printf(".\n");
	}
	if (num > 6) {
		printf(".\n");
	}
	if (num > 7) {
		printf("몸과 마음이 더 강해진 것 같다.\n");
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
		printf("이건 뭐지.\n");
	}
	if (num > 3) {
		printf("나무가 하루만에 이상할 정도로 커져있다.\n");
	}
	if (num > 4) {
		printf("이정도로 큰 나무는 인생에서 처음 보는 것 같다.\n");
	}
	if (num > 5) {
		printf("마치 '세계수'라고 불러야 할 것 같다.\n");
	}
	if (num > 6) {
		printf(".\n");
	}
	if (num > 7) {
		printf("왠지 모르게 마음속에서 용기와 경건함이 생겨난다.\n");
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