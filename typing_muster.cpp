
#include "iGraphics.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
void print_1(char *s);
void print_2(char *s);
#include <windows.h>
#include <mmsystem.h>
#include <time.h>
#pragma comment(lib, "Winmm.lib")
using namespace std;
#include <string.h>
#include <string>
#define screenHeight 600
#define screenWidth 1200

int r_color[500] = {0};
int g_color[500] = {0};
int b_color[500] = {0};

int r_color_2[500] = {0};
int g_color_2[500] = {0};
int b_color_2[500] = {0};

int color_initialize = 0;

struct buttonCordinate
{
	int x;
	int y;
} bCordinate[3];

int mposx, mposy;
char button[10][15] = {"type\\start.bmp", "type\\exit.bmp", "type\\info.bmp"};
char homemenu[15] = "type\\3.bmp";
char startPage[20] = "image\\1.bmp";
char infoPage[20] = "type\\rate.bmp";
char str[50][100] = {"I love touch typing", "I am a student of department of CSE,BUET.", "I read in 1st year", "I love to do project in iGraphics", "I love eating food and travelling.", "# Bangladesh is a coUntry in South Asia,,", "bAngladesh has 64 disTrict?", "India, is the seventh-larGest country", "India has been a federal-republic", "fgfg gffggggf fg", "jkjk kjkj lsls vbvb", "#### l;j'?\3#", "wowow owow woo", "qpqpqp pwpwpw", "1.Sri Lanka is an Island country", "In antiquity, Sri Lanka was known to travellers", "the United States ranks among the highest in the world", "February 14 is observed in as Valentine's Day.", "qpwoeiruty !1=+", "aslkdjfhg34", "What is this?MaD"};
char str1[100];
char str2[100];
char name[100];
int indexNumber_1 = 0, indexNumber_2 = 0;
int show = 0;

static int count = 0;
static int co_char = 0;
static int x_axis = 200;
int acq;
char acquracy[100];
int gameState = -1;
bool show_acquracy = false;
int count_false = 0;
int str_num;
int next_string = 0;
int nextStr = 0;
int next_line = 0;
int x = 0;

static int i = 0;
static int j = -1;

// counting wpm acquracy
int time_1 = 0;
char time_difference[200];
int start_time = 0;
float count_char = 0;
float count_correct = 0;
double wpm;
double acq_1;

// saving name
char player_name[200];
int name_index = 0;
int enter_name = 0;

// storing information for player
FILE *player_info;
int isStore = 0;
int van = 0;
int count_player = 0;

// showing score
int line_y = 600;
char show_player_name[100];
double show_player_acq;
double show_player_wpm;
char s_1[100];
char s_2[100];
char s_3[100];
int ch;
double highest_acq = 0;
double highest_wpm = 0;
char show_highest_acq[200];
char show_highest_wpm[200];
char highest_acq_name[50];
char highest_wpm_name[50];
int reset_score = 0;

// showing subscript
int string_1 = 1, string_2 = 0;
int string_1_index = 0, string_2_index = -1;

// storing time per word
FILE *bar_chart;
char word[100];
int time_2;
int word_index = 0;
int word_start_time = 1;
int write_word = 1;
char word_name[100];
int word_time;
int isClear = 0;
int reset_score_word=0;

void count_time()
{
	if (show_acquracy)
		start_time = 0;
	if (start_time)
		time_1++;
	if (word_start_time)
		time_2++;
}

void iDraw()
{
	iClear();

	if (gameState == -1)
	{
		// Homemenu
		iShowBMP(0, 0, homemenu);
		iSetColor(100, 255, 50);
		iFilledEllipse(580, 450, 70, 30, 100);
		iFilledEllipse(580, 350, 70, 30, 100);
		iFilledEllipse(580, 250, 70, 30, 100);
		iFilledEllipse(580, 150, 70, 30, 100);
		iSetColor(255, 0, 0);
		iText(547, 445, "PLAY", GLUT_BITMAP_HELVETICA_18);
		iText(547, 345, "SCORE", GLUT_BITMAP_HELVETICA_18);
		iText(547, 245, "EXIT", GLUT_BITMAP_HELVETICA_18);
		iText(547, 145, "ABOUT", GLUT_BITMAP_HELVETICA_18);
	}
	else if (gameState == 3)
	{
		iSetColor(255, 255, 0);
		iText(450, 500, "Please enter your name:", GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(0, 255, 255);
		iFilledRectangle(450, 424, 200, 40);
		iSetColor(0, 0, 0);
		iText(450, 435, player_name, GLUT_BITMAP_HELVETICA_18);
		iSetColor(0, 255, 0);
		iRectangle(677, 424, 100, 40);
		iSetColor(0, 0, 255);
		iText(693, 435, "ENTER", GLUT_BITMAP_HELVETICA_18);
	}
	else if (gameState == 0)
	{
		iSetColor(255, 255, 255);
		iFilledRectangle(0, 0, 1200, 800);
		iSetColor(200, 150, 100);
		iText(110, 550, "WELLCOME TO MY TYPING MASTER AND DON'T LOOK AT THE KEYBOARD WHILE TYPING", GLUT_BITMAP_HELVETICA_18);
		iSetColor(0, 0, 255);
		iLine(1050, 350, 1050, 200);
		iLine(1050, 350, 1150, 276);
		iLine(1050, 200, 1150, 276);

		iSetColor(0, 0, 255);
		iLine(62, 524, 62, 581);
		iLine(26, 556, 62, 524);
		iLine(26, 556, 62, 581);

		iFilledRectangle(62, 545, 36, 18);
		iRectangle(899, 474, 150, 50);
		iText(918, 494, "WORD/TIME", GLUT_BITMAP_HELVETICA_18);

		print_1(str[nextStr]);
		print_2(str[nextStr + 1]);
		iSetColor(255, 255, 0);
		iFilledRectangle(200, 250, 600, 100);
		iSetColor(0, 0, 0);
		iText(210, 320, str1, GLUT_BITMAP_HELVETICA_18);
		iSetColor(0, 0, 0);
		iText(210, 295, str2, GLUT_BITMAP_HELVETICA_18);
		iSetColor(0, 255, 0);
		iFilledRectangle(220, 100, 206, 50);
		iSetColor(255, 0, 0);
		iText(233, 123, "SHOW ACCURACY", GLUT_BITMAP_HELVETICA_18);
		iSetColor(0, 0, 0);
		wpm = count_char / (0.083 * time_1);
		acq_1 = (1.0 * (count_correct / (count_char)) * 100);
		sprintf(acquracy, "Acquracy=%.2lf %%", acq_1);
		sprintf(time_difference, "Your typing speed=%.2lf WPM", wpm);
		if (show_acquracy)
		{
			iText(200, 200, acquracy, GLUT_BITMAP_HELVETICA_18);
			iText(200, 165, time_difference, GLUT_BITMAP_HELVETICA_18);
		}
		iSetColor(0, 255, 100);
		iFilledEllipse(1028, 50, 60, 25, 100);
		iSetColor(0, 0, 0);
		iText(1005, 45, "SAVE", GLUT_BITMAP_HELVETICA_18);
		iSetColor(100, 130, 170);
		iRectangle(665, 190, 125, 48);
		iSetColor(255, 0, 0);
		if (string_1)
		{
			char s2[2] = {str[nextStr][string_1_index], 0};
			if (write_word)
			{
				word[word_index] = str[nextStr][string_1_index];
				word_index++;
				word[word_index + 1] = '\0';
				write_word = 0;
			}
			if (s2[0] == ' ')
			{
				iText(670, 215, "SPACE", GLUT_BITMAP_TIMES_ROMAN_24);
			}
			else if (string_1_index == strlen(str[nextStr]))
			{
				iText(670, 215, "ENTER", GLUT_BITMAP_TIMES_ROMAN_24);
			}
			else
				iText(670, 215, s2, GLUT_BITMAP_TIMES_ROMAN_24);
		}
		if (string_2)
		{
			char s2[2] = {str[nextStr + 1][string_2_index], 0};
			if (write_word)
			{
				word[word_index] = str[nextStr + 1][string_2_index];
				word_index++;
				word[word_index + 1] = '\0';
				write_word = 0;
			}
			if (s2[0] == ' ')
			{
				iText(670, 215, "SPACE", GLUT_BITMAP_TIMES_ROMAN_24);
			}
			else if (string_2_index == strlen(str[nextStr + 1]))
			{
				iText(670, 215, "END", GLUT_BITMAP_TIMES_ROMAN_24);
			}
			else
				iText(670, 215, s2, GLUT_BITMAP_TIMES_ROMAN_24);
		}
	}
	else if (gameState == 1)
	{
		exit(1);
		iShowBMP(0, 0, homemenu);

		iSetColor(0, 0, 255);
		iLine(62, 524, 62, 581);
		iLine(26, 556, 62, 524);
		iLine(26, 556, 62, 581);

		iFilledRectangle(62, 545, 36, 18);
	}
	else if (gameState == 2)
	{
		iSetColor(255, 255, 255);
		iFilledRectangle(0, 0, 1200, 600);
		iSetColor(0, 0, 255);
		iText(200, 550, "RULES OF TOUCH TYPING:", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(200, 500, "1)Position typing material at eye level next to your monitor. ", GLUT_BITMAP_HELVETICA_18);
		iText(200, 470, "2)Place your fingers on the center keyboard row when you start typing.", GLUT_BITMAP_HELVETICA_18);
		iText(200, 440, "3)Reach all of the keys while moving your hands as little as possible. ", GLUT_BITMAP_HELVETICA_18);
		iText(200, 410, "4)Look at the screen at all times while typing.  ", GLUT_BITMAP_HELVETICA_18);
		iText(200, 380, "5)the text carefully as you type to stay accurate. ", GLUT_BITMAP_HELVETICA_18);
		iText(200, 350, "6)Sit with your back straight and your head up. ", GLUT_BITMAP_HELVETICA_18);
		iText(200, 320, "7)Practice your technique whenever you have access to a computer.  ", GLUT_BITMAP_HELVETICA_18);
		iText(200, 290, "8)Take a typing class if you prefer to work with a tutor in person. ", GLUT_BITMAP_HELVETICA_18);

		iLine(62, 524, 62, 581);
		iLine(26, 556, 62, 524);
		iLine(26, 556, 62, 581);

		iFilledRectangle(62, 545, 36, 18);
	}
	else if (gameState == 4)
	{
		iSetColor(255, 255, 255);
		iFilledRectangle(0, 0, 1200, 600);
		iSetColor(0, 0, 0);
		line_y = 600;
		for (int i = 0; i < 12; i++)
		{
			iLine(0, line_y, 1200, line_y);
			line_y -= 50;
		}
		int line_x = 400;
		for (int i = 0; i < 3; i++)
		{
			iLine(line_x, 0, line_x, 550);
			line_x += 400;
		}
		iSetColor(200, 100, 250);
		iText(105, 510, "NAME", GLUT_BITMAP_HELVETICA_18);
		iText(475, 510, "ACQURACY", GLUT_BITMAP_HELVETICA_18);
		iText(880, 510, "WPM", GLUT_BITMAP_HELVETICA_18);
		int pos_y = 460;
		char it[100];
		player_info = fopen("player_details.txt", "r");
		while (fscanf(player_info, "%s %lf %lf", &show_player_name, &show_player_acq, &show_player_wpm) == 3)
		{
			if (show_player_acq > highest_acq)
			{
				highest_acq = show_player_acq;
				strcpy(highest_acq_name, show_player_name);
			}
			if (show_player_wpm > highest_wpm)
			{
				highest_wpm = show_player_wpm;
				strcpy(highest_wpm_name, show_player_name);
			}
			sprintf(s_1, "%.2lf", show_player_acq);
			sprintf(s_2, "%.2lf", show_player_wpm);
			sprintf(s_3, "%s", show_player_name);
			iText(105, pos_y, s_3, GLUT_BITMAP_TIMES_ROMAN_24);
			iText(475, pos_y, s_1, GLUT_BITMAP_TIMES_ROMAN_24);
			iText(880, pos_y, s_2, GLUT_BITMAP_TIMES_ROMAN_24);
			pos_y -= 50;
		}
		if (reset_score)
		{
			fclose(fopen("player_details.txt", "w"));
			highest_acq = 0;
			highest_wpm = 0;
			for (int i = 0; i < strlen(highest_acq_name); i++)
			{
				highest_acq_name[i] = ' ';
			}
			for (int i = 0; i < strlen(highest_wpm_name); i++)
			{
				highest_wpm_name[i] = ' ';
			}
			reset_score = 0;
		}
		else
			fclose(player_info);

		sprintf(show_highest_acq, "Highest Acquracy=%.2lf %% (%s)", highest_acq, highest_acq_name);
		sprintf(show_highest_wpm, "Highest wpm=%.2lf WPM (%s)", highest_wpm, highest_wpm_name);

		iText(428, 560, show_highest_acq, GLUT_BITMAP_HELVETICA_18);
		iText(854, 560, show_highest_wpm, GLUT_BITMAP_HELVETICA_18);

		iSetColor(0, 0, 255);
		iLine(62, 524, 62, 581);
		iLine(26, 556, 62, 524);
		iLine(26, 556, 62, 581);

		iFilledRectangle(62, 545, 36, 18);
		iRectangle(176, 563, 100, 30);
		iSetColor(255, 0, 0);
		iText(191, 574, "RESET", GLUT_BITMAP_HELVETICA_18);
	}

	// showing word per time
	else if (gameState == 6)
	{
	
		iSetColor(255, 255, 255);
		iFilledRectangle(0, 0, 1200, 600);
		int pos_y = 550;
		iSetColor(0, 0, 0);
		iText(105, 583, "Word", GLUT_BITMAP_HELVETICA_18);
		iText(475, 583, "Time(s)", GLUT_BITMAP_HELVETICA_18);
		int i = 1;
		bar_chart = fopen("time_word.txt", "r");
		while (fscanf(bar_chart, " %s %d", &word_name, &word_time) == 2)
		{
			sprintf(s_1, "%d", word_time);
			sprintf(s_3, "%d.%s", i, word_name);
			i++;
			iText(105, pos_y, s_3, GLUT_BITMAP_TIMES_ROMAN_10);
			iText(475, pos_y, s_1, GLUT_BITMAP_TIMES_ROMAN_10);
			pos_y -= 20;
		}
		//fclose(bar_chart);
		if (reset_score_word)
		{
			fclose(fopen("time_word.txt", "w"));
			reset_score_word = 0;
		}
		else
		{
			fclose(bar_chart);
		}
		// back button
		iLine(62, 524, 62, 581);
		iLine(26, 556, 62, 524);
		iLine(26, 556, 62, 581);

		iFilledRectangle(62, 545, 36, 18);

		iSetColor(0, 0, 255);
		iLine(1050, 350, 1050, 200);
		iLine(1050, 350, 1150, 276);
		iLine(1050, 200, 1150, 276);

			iRectangle(300, 563, 100, 30);
		iSetColor(255, 0, 0);
		iText(305, 574, "RESET", GLUT_BITMAP_HELVETICA_18);
	}
}

void print_1(char *s)
{
	x = 0;
	for (int i = 0; i < strlen(s); i++)
	{
		char s2[2] = {s[i], 0};
		iSetColor(r_color[i], g_color[i], b_color[i]);
		iText(200 + x, 400, s2, GLUT_BITMAP_HELVETICA_18);
		x += 12;
	}
}

void print_2(char *s)
{
	x = 0;
	for (int i = 0; i < strlen(s); i++)
	{
		char s2[2] = {s[i], 0};
		iSetColor(r_color_2[i], g_color_2[i], b_color_2[i]);
		iText(200 + x, 375, s2, GLUT_BITMAP_HELVETICA_18);
		x += 12;
	}
}

void iMouseMove(int mx, int my)
{
	printf("x = %d, y= %d\n", mx, my);
}

void iMouse(int button, int state, int mx, int my)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		// play button
		if (mx >= 510 && mx <= 645 && my >= 420 && my <= 480)
		{
			gameState = 3;
			start_time = 1;
			time_1 = 0;
			enter_name = 1;

			for (int i = 0; i < strlen(player_name); i++)
			{
				player_name[i] = ' ';
			}
			name_index = 0;
		}

		if (mx >= 510 && mx <= 645 && my >= 220 && my <= 280)
		{
			exit(1);
		}

		if (mx >= 510 && mx <= 645 && my >= 120 && my <= 180)
		{
			gameState = 2;
		}
		// score button
		else if (mx >= 510 && mx <= 645 && my >= 320 && my <= 380)
		{
			gameState = 4;
		}
		if (mx >= 1050 && mx <= 1150 && my >= 200 && my <= 350)
		{
			// going to next string
			for (int i = 0; i < 500; i++)
			{
				r_color[i] = 0;
				g_color[i] = 0;
				b_color[i] = 0;

				r_color_2[i] = 0;
				g_color_2[i] = 0;
				b_color_2[i] = 0;
			}

			srand(time(0));
			nextStr = rand() % 20;
			for (int i = 0; i < strlen(str1); i++)
			{
				str1[i] = ' ';
			}
			for (int i = 0; i < strlen(str2); i++)
			{
				str2[i] = ' ';
			}
			i = 0;
			j = -1;
			next_line = 0;
			indexNumber_1 = 0;
			indexNumber_2 = 0;
			count = 0;
			show_acquracy = 0;
			time_1 = 0;
			start_time = 1;
			count_char = 0;
			count_correct = 0;
			string_1 = 1;
			string_2 = 0;
			string_1_index = 0;
			string_2_index = -1;
			isClear = 1;
			gameState = 0;
			time_2 = 0;
		}
		if (mx >= 220 && mx <= 426 && my >= 100 && my <= 150)
		{
			show_acquracy = true;
		}

		if (mx >= 26 && mx <= 61 && my >= 528 && my <= 547)
		{
			// back button controlling
			isClear = 1;
			for (int i = 0; i < strlen(str1); i++)
			{
				str1[i] = ' ';
			}
			for (int i = 0; i < strlen(str2); i++)
			{
				str2[i] = ' ';
			}
			i = 0;
			j = -1;
			next_line = 0;
			indexNumber_1 = 0;
			indexNumber_2 = 0;
			show_acquracy = 0;
			gameState = -1;

			for (int i = 0; i < 500; i++)
			{
				r_color[i] = 0;
				g_color[i] = 0;
				b_color[i] = 0;

				r_color_2[i] = 0;
				g_color_2[i] = 0;
				b_color_2[i] = 0;
			}
		}
		// enter button
		if (mx >= 677 && mx <= 777 && my >= 424 && my <= 464)
		{
			gameState = 0;
			enter_name = 0;
			count_char = 0;
			count_correct = 0;
			time_1 = 0;
			string_1 = 1;
			string_2 = 0;
			string_1_index = 0;
			string_2_index = -1;
			srand(time(0));
			nextStr = rand() % 20;
		}
		// save button
		if (mx >= 970 && mx <= 1035 && my >= 27 && my <= 76)
		{
			count_player++;
			// isStore = 1;
			player_info = fopen("player_details.txt", "a");
			fprintf(player_info, "%s  %.2lf  %.2lf\n", player_name, acq_1, wpm);
			fclose(player_info);
		}
		if (mx >= 175 && mx <= 275 && my >= 563 && my <= 593)
		{
			reset_score = 1;
		}
		if (mx >= 300 && mx <= 400 && my >= 563 && my <= 593)
		{
			reset_score_word = 1;
		}
		if (mx >= 897 && mx <= 1048 && my >= 476 && my <= 524)
		{
			gameState = 6;
		}
	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
	}
}

void iKeyboard(unsigned char key)
{
	count_char++;
	// writting players name
	if (enter_name)
	{
		if (key != '\b')
		{
			player_name[name_index] = key;
			name_index++;
			player_name[name_index + 1] = '\0';
		}
		else
		{
			if (name_index < 0)
			{
				name_index = 0;
			}
			player_name[--name_index] = '\0';
		}
	}

	// working with string
	else
	{
		write_word = 1;
		if (key == '\r')
		{
			next_line = 1;
			string_1 = 0;
			string_2 = 1;
			count_char--;

			// saving word per time
			
			bar_chart = fopen("time_word.txt", "a");
			printf("%s %d\n", word, time_2);
			fseek(bar_chart,0,SEEK_CUR);
			fprintf(bar_chart, "%s %d\n", word, time_2);
			fclose(bar_chart);
			write_word = 1;
			for (int i = 0; i < strlen(word); i++)
			{
				word[i] = ' ';
			}
			word_index = 0;
			time_2 = 0;
		}

		if (key == ' ')
		{
			bar_chart = fopen("time_word.txt", "a");
			//printf("%s %d\n", word, time_2);
			fprintf(bar_chart, "%s %d\n", word, time_2);
			fclose(bar_chart);
			write_word = 1;
			for (int i = 0; i < strlen(word); i++)
			{
				word[i] = ' ';
			}
			word_index = 0;
			time_2 = 0;
		}

		if (next_line)
		{
			if (key != '\b')
			{
				string_2_index++;
				count++;
				str2[indexNumber_2] = key;
				indexNumber_2++;
				str2[indexNumber_2 + 1] = '\0';

				if (key == str[nextStr + 1][j])
				{
					PlaySound("new_sound.wav", NULL, SND_ASYNC);
					count_correct++;
					g_color_2[j] = 255;
					r_color_2[j] = 0;
					b_color_2[j] = 0;
					j++;
				}
				else
				{
					if (key != 13)
						PlaySound("wrong.wav", NULL, SND_ASYNC);
					g_color_2[j] = 0;
					r_color_2[j] = 255;
					b_color_2[j] = 0;
					j++;
					count++;
				}
			}
			else
			{
				string_2_index--;
				if (indexNumber_2 < 0)
				{
					indexNumber_2 = 0;
					next_line = 0;
					string_2_index = 0;
				}
				str2[--indexNumber_2] = '\0';
				j--;
				g_color_2[j] = 0;
				r_color_2[j] = 0;
				b_color_2[j] = 0;

				// counting time per word
			}
		}
		else
		{
			if (key != '\b')
			{
				count++;
				string_1_index++;
				str1[indexNumber_1] = key;
				indexNumber_1++;
				str1[indexNumber_1 + 1] = '\0';

				if (key == str[nextStr][i])
				{
					PlaySound("new_sound.wav", NULL, SND_ASYNC);
					count_correct++;
					g_color[i] = 255;
					r_color[i] = 0;
					b_color[i] = 0;
					i++;
				}
				else
				{
					PlaySound("wrong.wav", NULL, SND_ASYNC);
					g_color[i] = 0;
					r_color[i] = 255;
					b_color[i] = 0;
					i++;
					count++;
				}
			}
			else
			{
				string_1_index--;
				if (indexNumber_1 < 0)
				{
					indexNumber_1 = 0;
					string_1_index = 0;
				}
				str1[--indexNumber_1] = '\0';
				i--;
				g_color[i] = 0;
				r_color[i] = 0;
				b_color[i] = 0;
			}
		}
	}
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
		GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
	*/
void iSpecialKeyboard(unsigned char key)
{
	if (key == GLUT_KEY_END)
	{
		exit(0);
	}
	else if (key == GLUT_KEY_LEFT)
	{
		next_string = 1;
	}
	else if (key == GLUT_KEY_RIGHT)
	{
	}
	// place your codes for other keys here
}

int main()
{
	int sum = 50;
	for (int i = 2; i >= 0; i--)
	{
		bCordinate[i].x = 50;
		bCordinate[i].y = sum;
		sum += 150;
	}
	iSetTimer(1000, count_time);
	iInitialize(screenWidth, screenHeight, "TYPING MASTER");
	scanf("%s", &name);
	return 0;
}
