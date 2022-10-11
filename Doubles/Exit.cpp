#include"Exit.h"
#include "GameMenu.h"
#include "statistics.h"
#include "leaderscoreboard.h"

Exit::Exit() {


}

Exit::~Exit() {


}
void Exit::init() {
	glClearColor(1, 0, 0, 1);//(color,color,color alpha is intensity)
	glClear(GL_COLOR_BUFFER_BIT);// Buffer to apply the color;
	glMatrixMode(GLUT_SINGLE | GLUT_RGB);
	glLoadIdentity();
	glOrtho(-90.0, 100.0, -15.0, 100.0, 0.0, 1.0);// boundries  for my mapping
}

void renderbitmap(float x, float y, void *font, char *string) {
	char *c;
	glRasterPos2f(x, y);
	for (c = string; *c != '\0'; c++) {
		glutBitmapCharacter(font, *c);
	}
}

void exitScreen(int score) {
	glColor3f(1.f, 1.f, 1.f);
	char buf[100] = { 0 };
	sprintf_s(buf, "GAME OVER");
	renderbitmap(-20, 80, GLUT_BITMAP_TIMES_ROMAN_24, buf);// (L/R, U/D)
	sprintf_s(buf, "Your highest score was:");
	renderbitmap(-25, 70, GLUT_BITMAP_9_BY_15, buf);// (L/R, U/D)
	sprintf_s(buf, "%d", score);
	renderbitmap(-12, 65, GLUT_BITMAP_9_BY_15, buf);
	sprintf_s(buf, "Game Creators:");
	renderbitmap(-80, 58,GLUT_BITMAP_8_BY_13, buf);
	sprintf_s(buf, "TL Benjamin Cromer");
	renderbitmap(-80, 55, GLUT_BITMAP_TIMES_ROMAN_10, buf);
	sprintf_s(buf, "Ryan Enriquez");
	renderbitmap(-80, 52, GLUT_BITMAP_TIMES_ROMAN_10, buf);
	sprintf_s(buf, "Pablo Porta");
	renderbitmap(-80, 49, GLUT_BITMAP_TIMES_ROMAN_10, buf);
	sprintf_s(buf, "Arsal Oyerli");
	renderbitmap(-80, 46, GLUT_BITMAP_TIMES_ROMAN_10, buf);
	//sprintf_s(buf, "Press F for full screen");
	//renderbitmap(-20, -10, GLUT_BITMAP_TIMES_ROMAN_10, buf);// (L/R, U/D)
	sprintf_s(buf, "Press E for exit screen");
	renderbitmap(-80, -10, GLUT_BITMAP_TIMES_ROMAN_10, buf);// (L/R, U/D)
	//sprintf_s(buf, "Press M to Minimize");
	//renderbitmap(50, -10, GLUT_BITMAP_TIMES_ROMAN_10, buf);// (L/R, U/D)
	
}
/*
void My_exit()
{
	glutIdleFunc(0); // Turn off Idle function if used.
	glutDestroyWindow(0);// Close open windowsand other close down stuff
	exit;//end program
}
*/

void	keyPressed(unsigned char key, int x, int y)
{
	if (key == 'e'|| key == 'E') {
		glutLeaveMainLoop();
		//exit(0);

	}
	if (key == 'f' || key == 'F') {
		glutFullScreen();
		//glutDisplayFunc(0);
	}
	if (key == 'm' || key == 'M') {
		glutReshapeWindow(wid, hei);        /* Restore us */
		glutPositionWindow(30, 30);
	}
}

void exitDisplay(int score) {
	Exit pExit;
	exitScreen(score);
	glFlush();
	glutKeyboardFunc(keyPressed);

}


int Exit::exitProcess(int arg, char **argv, int score) {
	glutInit(&arg,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(wid, hei);
	glutInitWindowPosition(30, 30);
	glutCreateWindow("Doubles Dice Game");
	init(); //display function
	//glutDisplayFunc(NULL);
	exitDisplay(score);
		glutMainLoop();
		
		

	return 0;
}
