
#include<fstream>
#include<iostream>
#include<stdlib.h>
#include <windows.h>
#include<glut.h>
#include<gl/glu.h>
#include <freeglut.h>
#include "Graphics.h"
#define _CRT_SECURE_NO_WARNINGS
#ifndef EXIT_H
#define EXIT_H



const int wid = 480;
const int hei = 480;

class Exit : public Graphics {
private:
	Exit* pExit;

public:
	Exit();
	~Exit();
	void init();
	int exitProcess(int arg, char **argv, int score);
};
#endif