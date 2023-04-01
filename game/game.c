// 2020112099_SongMinJi

#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <ncurses.h>
#include <signal.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>
#include <sys/wait.h>

int row;
int col;
int dir_row; //up, down
int dir_col; //left, right
int cnt;

void execute();

void draw_feed();
void draw_rabbit();
void draw_blank();

//void crmode(void);
//void noecho(void);
int set_ticker(int);

int main()
{
	execute();

	int delay;
	int new_delay;

	int c;
	void move_rabbit(int);

	initscr(); //initialize curses library and tty
	crmode(); 
	noecho();
	clear(); //clear the screen

	row=20; //start here
	col=0;

	dir_row=0;
	dir_col=1;

	delay=70; //0.07sec delay

	move(row,col);

	draw_rabbit();
	draw_feed();

	signal(SIGALRM, move_rabbit);
	set_ticker(delay);

	while(1)
	{
		new_delay=0;
		c=getchar();

		if(c=='q')
			break;

		if(c==' ')
			dir_col=-dir_col;

		if(c=='u') //up
		{
			dir_row=dir_row-2;
			sleep(1);
			dir_row=dir_row+2;
		}
		if(c=='d') //down
		{
			dir_row=dir_row+2;
			sleep(1);
			dir_row=dir_row-2;
		}
		if(c=='f' && delay>2)
			new_delay=delay/2;

		if(c=='s')
			new_delay=delay*2;

		if(new_delay>0)
			set_ticker(delay=new_delay);
	}
	
	endwin(); //turn off curses & reset tty

	return 0;
}

void move_rabbit(int signum)
{
	signal(SIGALRM, move_rabbit);
//	signal(SIGINT, SIG_IGN);

	move(row,col);
	draw_blank();

	col+=dir_col;
	row+=dir_row;

	move(row,col);
	draw_rabbit();
	
	refresh();

	if(dir_col==-1 && col<=0)
		dir_col=1;
	else if(dir_col==1 && col+8>=COLS)
		dir_col=-1;
	
	if(dir_row==-1 && row<=0)
		dir_row=1;
	else if(dir_row==1 && row>=70)
		dir_row=-1;

}


void draw_feed()
{
	for(int i=0;i<40;i++)
	{
		move(rand()%70, rand()%COLS);
		addstr("o");

		cnt=40;
	}
}


void draw_rabbit()
{
	addstr("&    &");
	move(row+1, col);
	addstr("&    &");
	move(row+2,col);
	addstr("&&&&&&");
	move(row+3, col);
	addstr("&.&&.&");
	move(row+4, col);
	addstr("&&&&&&");
	move(row+5,col);
	addstr("  &&  ");
	move(row+6, col);
	addstr(" &&&& ");
	move(row+7, col);
	addstr("  &&  ");
	move(row+8, col);
	addstr(" &  & ");
}


void draw_blank()
{
	addstr("      ");
	move(row+1, col);
	addstr("      ");
	move(row+2, col);
	addstr("      ");
	move(row+3, col);
	addstr("      ");
	move(row+4, col);
	addstr("      ");
	move(row+5, col);
	addstr("      ");
	move(row+6, col);
	addstr("      ");
	move(row+7, col);
	addstr("      ");
	move(row+8,col);
	addstr("      ");
}


void execute()
{
	int fork_rv;
	fork_rv=fork();

	if(fork_rv==-1)
	{
		perror("fork");
		exit(1);
	}

	if(fork_rv==0) //child process
	{
		printf("I'm child process.\n");
		//execl("/SystemProgramming/project/game.c", "/SystemProgramming/project/game.c", 0);
		//perror("execlp");
		exit(1);
	}

	if(fork_rv!=0) //parent process
	{
		wait NULL;
		printf("This is Parent process. Just wait to come child process\n");
	}

}
