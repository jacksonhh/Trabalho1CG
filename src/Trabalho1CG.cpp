//============================================================================
// Name        : Trabalho1CG.cpp
// Author      : Jackson Henrique Hochscheidt
//			   		 : Kevin Mitchell Spiller
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <GL/glut.h>
#include <stdio.h>

#define wMaze 75
#define hMaze 45
#define X 0
#define Y 1
#define Z 2
#define CONE 2
#define TORUS 3
#define ALTURA_PAREDE 2
#define TEAPOT 4
#define DIREITA 1
#define ESQUERDA 2
#define CIMA 3
#define BAIXO 4

int labirinto[hMaze][wMaze]={
		//Linha 1
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		//linha 2
		{0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0},
		{0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0},
		{0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0},
		//linha 3
		{0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0},
		{0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0},
		{0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0},
		//linha 4
		{0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0},
		{0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0},
		{0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0},
		//linha 5
		{0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0},
		//linha 6
		{0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0},
		{0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0},
		{0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0},
		//linha 7
		{0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0},
		//linha 8
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0},
		//posicao inicial do boneco
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0},
		//posicao inicial do boneco
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0},
		//linha 9
		{0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,1,2,1,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0},
		//linha 10
		{0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0},
		{0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0},
		{0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0},
		//linha 11
		{0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0},
		{0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0},
		{0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0},
		//linha 12
		{0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0},
		{0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0},
		{0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0},
		//linha 13
		{0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0},
		//linha 14
		{0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0},
		{0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,4,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0},
		{0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0},
		//linha 15
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0}
};


int windowWidth  = 700;
int windowHeight = 700;
int windowPosX   = 0;
int windowPosY   = 0;
bool fullScreenMode = true;
//double TAM_LEG = 1.5;	 //comprimento das pernas
//double TAM_TRONCO = 1.5; //comprimeiro do tronco do boneco
//double TAM_PESCOCO = 1.5; //comprimento pescoço
double angPerspective = 45;
double rotX = 0, rotY = 0, rotZ = 0;
double rotateTORUS = 0;
double rotateTEAPOT = 0;
int lastMotion = -1;
double angleRotateRobot = 0;
double rotateRobo = 0;
double rotateArms = 0;
double rotateHead = 0;
int CAM_ATUAL = 0;
bool ROT_ARM_FRONT = true;
bool ROT_HEAD_RIGHT = true;
int posRobo[3] = {22,0,0};

#define ROBO 9
double camera[3] = {hMaze/2,wMaze/2,100};
double focus[3] = {hMaze/2,wMaze/2,0}; // para onde a camera esta olhando
int rotMaze[3] = {0,0,0};
double rotateMaze = 0;
int trMaze[3] = {0,0,0};

GLUquadricObj *novaQuadrica();
void reshapeWindow(GLsizei w, GLsizei h);
void draw();
void animate(int value);
void teclado(unsigned char key, int x, int y);
void specialKeys(int key, int x, int y);
void drawMaze( double w, double h);
void drawRobot();

GLUquadricObj *novaQuadrica(){
	GLUquadricObj *novaQuadrica = gluNewQuadric();
	gluQuadricDrawStyle(novaQuadrica, GLU_FILL);
	gluQuadricOrientation(novaQuadrica, GLU_OUTSIDE);
	gluQuadricNormals(novaQuadrica, GLU_SMOOTH);
	return novaQuadrica;
}

GLUquadricObj *neck = novaQuadrica();
GLUquadricObj *ear = novaQuadrica();
GLUquadricObj *leg = novaQuadrica();
GLUquadricObj *arm = novaQuadrica();

void reshapeWindow(GLsizei w, GLsizei h){
	if(h ==0) h = 1;
	glViewport(0,0,w,h);
	//alteracoes serao feitas na matriz de projecao
	glMatrixMode(GL_PROJECTION);
	//carrega matriz identidade
	glLoadIdentity();
	gluPerspective(45, w/h, 0.1, 300);
}

void draw(){
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	if(CAM_ATUAL == ROBO){
		camera[X] = posRobo[X];
		camera[Y] = posRobo[Y] - 10;
		camera[Z] = 15;
		gluLookAt(camera[X],camera[Y], camera[Z], posRobo[X],posRobo[Y], posRobo[Z], 0,1,0);
	}else{
		gluLookAt(camera[X],camera[Y], camera[Z], focus[X],focus[Y],focus[Z], 0,1,0);
	}

	glColor3f(0.5,0.75,0.25);

	//rotacoes com o teclado
	glRotatef(-rotX, 1,0,0);
	glRotatef(-rotY, 0,1,0);
	glRotatef(-rotZ, 0,0,1);



	//CHAO PLANO XY
	glBegin(GL_QUADS);
		glVertex3f(0,0,0);
		glVertex3f(hMaze,0,0);
		glVertex3f(hMaze,wMaze,0);
		glVertex3f(0,wMaze,0);
	glEnd();
	glBegin(GL_QUADS); //PLANO XZ
		glColor3f(1,1,0.5);
		glVertex3f(0,0,0);
		glVertex3f(0,0,10);
		glVertex3f(10,0,10);
		glVertex3f(10,0,0);
	glEnd();
	glBegin(GL_QUADS); //PLANO YZ
		glColor3f(0.5,0.5,0.5);
		glVertex3f(0,0,0);
		glVertex3f(0,10,0);
		glVertex3f(0,10,10);
		glVertex3f(0,0,10);

	glEnd();


	//LABIRINTO
	glColor3f(1,0,0);
	drawMaze(wMaze, hMaze);


	//ROBO
	drawRobot();

	glutSwapBuffers();

	glutPostRedisplay();

	//MOVIMENTOS DA CABEÇA
	if(ROT_HEAD_RIGHT == true){
		//rotaciona ate chegar no 30
		if(rotateHead < 30){
			rotateHead = rotateHead + 1;
		}else{
			ROT_HEAD_RIGHT = false;
		}
	}else if(ROT_HEAD_RIGHT == false){
		if(rotateHead > -30){
			rotateHead = rotateHead - 1;
		}else{
			ROT_HEAD_RIGHT = true;
		}
	}

	//MOVIMENTOS DOS BRAÇOS
	if(ROT_ARM_FRONT == true){
		if(rotateArms < 30){
			rotateArms = rotateArms + 0.5;
		}else{
			ROT_ARM_FRONT = false;
		}
	}else if(ROT_ARM_FRONT == false){
		if(rotateArms > -30){
			rotateArms = rotateArms - 0.5;
		}else{
			ROT_ARM_FRONT = true;
		}
	}

}

void animate(int value){

	//rotaciona o robo
	if(rotateRobo == 90 && angleRotateRobot < 90){
		angleRotateRobot+=5;
	}else if(rotateRobo == 180 && angleRotateRobot < 180){
		angleRotateRobot+=5;
	}else if(rotateRobo == -90 && angleRotateRobot > -90){
		angleRotateRobot-=5;
	}else{
		angleRotateRobot = 0;
	}

	glutPostRedisplay();
	draw();
	glutTimerFunc(250,animate,1);
}

void teclado(unsigned char key, int x, int y){
	switch(key){
		case 'q':
			exit(0);
			break;
		case 'Q':
			exit(0);
			break;
		case '2': // rotaciona -X
			rotX--;
			break;
		case '8': //rotaciona X
			rotX++;
			break;
		case '4': //rotaciona -Y
			rotY--;
			break;
		case '6': //rotaciona Y
			rotY++;
			break;
		case '-': //zoom in
			camera[Y]+=1;
			camera[Z]-=2;
			break;
		case '+': //zoom out
			camera[Y]-=1;
			camera[Z]+=2;

	}
	glutPostRedisplay();
}

void specialKeys(int key, int x, int y){
	switch (key) {
		case GLUT_KEY_F1:    // F1: Para trocar entre tela cheia e janela
			fullScreenMode = !fullScreenMode;         // Estado de troca
			if (fullScreenMode) {                     // Modo tela cheia
				windowPosX   = glutGet(GLUT_WINDOW_X); // Salva os parametros para retornar mais tarde
				windowPosY   = glutGet(GLUT_WINDOW_Y);
				windowWidth  = glutGet(GLUT_WINDOW_WIDTH);
				windowHeight = glutGet(GLUT_WINDOW_HEIGHT);
				glutFullScreen();                      // Muda para tela cheia
			}else{                                         // Modo janela
				glutReshapeWindow(windowWidth, windowHeight); // Troca para modo janela
				glutPositionWindow(windowPosX, windowPosX);   // Posição do topo canto esquerdo
			}
			break;
		case GLUT_KEY_F2: //camera atras do robo e mostrando todo o labirinto
			CAM_ATUAL = ROBO; //camera atras do robo
			break;
		case GLUT_KEY_F3: // camera lado direito labirinto
			CAM_ATUAL = DIREITA; //camera do lado direito do labirinto
			break;
		case GLUT_KEY_F4: //camera na frente do labirinto
			CAM_ATUAL = CIMA; //camera "em cima" do labirinto
			break;
		case GLUT_KEY_F5: //camera lado esquerdo labirinto
			CAM_ATUAL = ESQUERDA; //camera do lado esquerdo do labirinto
			break;

		case GLUT_KEY_DOWN: //anda pra baixo no mapa
			if(posRobo[X]+2 <= hMaze){
				if(labirinto[posRobo[X]+2][posRobo[Y]] == 1){
					if(labirinto[posRobo[X]+2][posRobo[Y]-1] == 1 && labirinto[posRobo[X]+2][posRobo[Y]+1] == 1 ){
						//se caiu aqui pode ir pra baixo
						printf("Pode BAIXO\n");
						if(lastMotion == BAIXO || lastMotion == -1){
							lastMotion = BAIXO;
							posRobo[X]++;
							rotateRobo = -90;
						}else if(lastMotion == CIMA){
							lastMotion = CIMA;
							rotateRobo = 90;
							printf("BAIXO 180\n");
						}else if(lastMotion == ESQUERDA){
							lastMotion = BAIXO;
							rotateRobo = 180;
							printf("BAIXO 90\n");
						}else if(lastMotion == DIREITA){
							lastMotion = BAIXO;
							rotateRobo = 0;
							printf("BAIXO -90\n");
						}
						lastMotion = BAIXO;
					}
				}
			}
			break;
		case GLUT_KEY_UP: //anda pra cima no mapa
			if(posRobo[X]-2 >=0){
				if(labirinto[posRobo[X]-2][posRobo[Y]] == 1){
					if(labirinto[posRobo[X]-2][posRobo[Y]-1] == 1 && labirinto[posRobo[X]-2][posRobo[Y]+1] == 1){
						printf("Pode CIMA\n");
						if(lastMotion == CIMA || lastMotion == -1){
							posRobo[X]--;
							lastMotion = CIMA;
							rotateRobo = 90;
						}else if(lastMotion == BAIXO){
							lastMotion = CIMA;
							rotateRobo = -90;
							printf("CIMA 180\n");
						}else if(lastMotion == ESQUERDA){
							lastMotion = CIMA;
							rotateRobo = 180;
							printf("CIMA -90\n");
						}else if(lastMotion == DIREITA){
							lastMotion = CIMA;
							rotateRobo = -90;
							printf("CIMA 90\n");
						}
						lastMotion = CIMA;
					}
				}
			}
			break;
		case GLUT_KEY_LEFT: //anda pra esquerda no mapa
			if(posRobo[Y]-2 >= 0){
				if(labirinto[posRobo[X]][posRobo[Y]-2] == 1){
					if(labirinto[posRobo[X]+1][posRobo[Y]-2] == 1 && labirinto[posRobo[X]-1][posRobo[Y]-2] == 1){
						printf("Pode ESQUERDA\n");
						if(lastMotion == ESQUERDA || lastMotion == -1){
							posRobo[Y]--;
							lastMotion = ESQUERDA;
							rotateRobo = 180;
						}else if(lastMotion == CIMA){
							lastMotion = ESQUERDA;
							rotateRobo = 90;
							printf("ESQUERDA 90\n");
						}else if(lastMotion == BAIXO){
							lastMotion = ESQUERDA;
							rotateRobo = -90;
//							printf("ESQUERDA -90\n");
						}else if(lastMotion == DIREITA){
							lastMotion = ESQUERDA;
							rotateRobo = 0;
//							printf("ESQUERDA 180\n");
						}
						lastMotion = ESQUERDA;
					}
				}
			}
			break;
		case GLUT_KEY_RIGHT: //anda pra direita no mapa
			//se tiver mais duas posicoes pra direita no mapa
			if(posRobo[Y]+2 < wMaze){
				if(labirinto[posRobo[X]][posRobo[Y]+2] == 1){
					if(labirinto[posRobo[X]+1][posRobo[Y]+2] == 1 && labirinto[posRobo[X]-1][posRobo[Y]+2] == 1){
						printf("Pode DIREITA\n");
						if(lastMotion == DIREITA || lastMotion == -1){
							//continua pro mesmo lado, nao precisa rotacao
							//atualiza posicao robo
							posRobo[Y]++;
							lastMotion = DIREITA;
							rotateRobo = 0;
						}else if(lastMotion == ESQUERDA){
//							posRobo[Y]++;
							lastMotion = DIREITA;
							rotateRobo = 180;
							printf("DIREITA 180\n");
						}else if(lastMotion == CIMA){
							lastMotion = DIREITA;
							rotateRobo = 90;
							printf("DIREITA -90\n");
						}else if(lastMotion == BAIXO){
							lastMotion = DIREITA;
							rotateRobo = -90;
							printf("DIREITA 90\n");
						}
						lastMotion = DIREITA;
					}
				}
			}
			break;
		case GLUT_KEY_PAGE_UP: //rotaciona Z
			rotZ++;
			break;
		case GLUT_KEY_PAGE_DOWN: //rotaciona -Z
			rotZ--;
			break;
	}
	glutPostRedisplay();
}

void drawMaze( double w, double h){
	glPushMatrix();
	glTranslatef(0,0,ALTURA_PAREDE/2);
	//para cada linha da matriz do labirinto
	for(int i = 0; i < h; i++){
		//para cada coluna da matriz do labirinto
		for(int j = 0; j < w; j++){
			//se posicao do labirinto for uma parede
			if(labirinto[i][j] == 0){
				//desenhar parede
				glPushMatrix();
					glColor3f(1,0,0);
					glScalef(1,1,ALTURA_PAREDE);
					glTranslatef(i,j,0);
					glutSolidCube(1);
				glPopMatrix();
			}else if(labirinto[i][j] == CONE){
				glPushMatrix();
					glColor3f(1,0.6,0.5);
					glTranslatef(i,j,-1.5);
					glutSolidCone(1,ALTURA_PAREDE,50,50);
				glPopMatrix();
			}else if(labirinto[i][j] == TORUS){
				glPushMatrix();
					glColor3f(1,1,0);
					glTranslatef(i,j,0);
					glRotatef(90,0,1,0);
					glRotatef(rotateTORUS++,1,0,0);
					glutSolidTorus(0.3, 0.7,50,50);
				glPopMatrix();
			}else if(labirinto[i][j] == TEAPOT){
				glPushMatrix();
					glColor3f(0.2,0.2,0.2);
					glTranslatef(i,j,0);
					glRotatef(90,1,0,0);
					glRotatef(rotateTEAPOT++,0,1,0);
					glutSolidTeapot(0.75);
				glPopMatrix();
			}
		}
	}
	glPopMatrix();
};

void drawRobot(){




	glPushMatrix();
		glTranslatef(posRobo[X],posRobo[Y],posRobo[Z]);
		//rotacoes conforme teclado
		printf("ROOOOT %f\n", rotateRobo);

		glRotatef(angleRotateRobot,0,0,1);

		//Pernas
		glColor3f(0.4f,0.4f,0.4f);
		glPushMatrix();
			glTranslatef(0.4,0,2);
			glRotatef(-rotateArms,1,0,0);
			glRotatef(-180,1,0,0);
			gluCylinder(leg, 0.15, 0.15, 2, 50,50);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(-0.4,0,2);
			glRotatef(rotateArms,1,0,0);
			glRotatef(-180,1,0,0);
			gluCylinder(leg, 0.15, 0.15, 2, 50,50);
		glPopMatrix();

//		TRONCO
		glColor3f(0.7f,0.7f,0.7f);
		glPushMatrix();
			glTranslatef(0, 0, 0.25*13);
			glScalef(2,1,3);
			glutSolidCube(1);
		glPopMatrix();

		//BRAÇOS
		glColor3f(0.2f,0.2f,0.2f);
		//BRAÇO DIREITO
		glPushMatrix();
			glTranslatef(1.125, 0, 0.25*16);
			glutSolidSphere(0.25,50,50);
			glRotatef(-4.5,0,1,0);
			glRotatef(rotateArms, 1,0,0);
			glRotatef(-180,1,0,0);
			glScalef(1,2,10);
			gluCylinder(arm,0.15,0.15, 0.25, 50,50);
		glPopMatrix();
		//BRAÇO ESQUERDO
		glPushMatrix();
			glTranslatef(-1.125, 0, 0.25*16);
			glutSolidSphere(0.25,50,50);
			glRotatef(+4.5,0,1,0);
			glRotatef(-rotateArms, 1,0,0);
			glRotatef(-180,1,0,0);
			glScalef(1,2,10);
			gluCylinder(arm,0.15,0.15, 0.25, 50,50);
		glPopMatrix();

		//PESCOÇO
		glColor3f(0.25f,0.25f,0.25f);
		glPushMatrix();
			glTranslatef(0, 0, 0.25*19);
			gluCylinder(neck,0.55,0.33,1.25,40,40);
		glPopMatrix();

		//CABEÇA
		glPushMatrix();
			glRotatef(rotateHead,0,0,1);
			glColor3f(0.65f,0.55f,0.44f);
			glPushMatrix();
				glTranslatef(0, 0, 0.25*24);
		//		glScalef(1,1,1.75);
				glutSolidSphere(0.75,50,50);
			glPopMatrix();

			//ORELHA
			glColor3f(0.25f,0.25f,0.25f);
			//ORELHA DIREITA
			glPushMatrix();
				glTranslatef(0.5, 0, 0.25*26);
				glRotatef(90,1,0,0);
				glScalef(0.75,0.75,0.75);
				glutSolidTorus(0.25,0.5,50,50);
			glPopMatrix();
			//ORELHA ESQUERDA
			glPushMatrix();
				glTranslatef(-0.5, 0, 0.25*26);
				glRotatef(90,1,0,0);
				glScalef(0.75,0.75,0.75);
				glutSolidTorus(0.25,0.5,50,50);
			glPopMatrix();

			//OLHOS
			glColor3f(1,1,1);
			//OLHO DIREITO
			glPushMatrix();
				glTranslatef(0.25, 0.45, 0.25*24.75);
				glutSolidSphere(0.25,50,50);
			glPopMatrix();
			//OLHO ESQUERDO
			glPushMatrix();
				glTranslatef(-0.25, 0.45, 0.25*24.75);
				glutSolidSphere(0.25,50,50);
			glPopMatrix();
		glPopMatrix();
	glPopMatrix();


};




//##########################//
//$$$$$$$$$$$$$$$$$$$$$$$$$$//
//			MAIN			//
//$$$$$$$$$$$$$$$$$$$$$$$$$$//
//##########################//
int main(int argc, char **argv) {

	//inicializa GLUT com parametros necessarios

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

	//cria JANELA DE VISUALIZACAO
	glutInitWindowPosition(windowPosX,windowPosY);
	glutInitWindowSize(windowWidth,windowHeight);
	glutCreateWindow("Labirinto 3D");

	glClearColor(0,0,0,1);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	//FUNCOES DE CALLBACK
	glutReshapeFunc(reshapeWindow);
	glutTimerFunc(150, animate, 1);
	glutDisplayFunc(draw);
	glutSpecialFunc(specialKeys);
	glutFullScreen();
	glutKeyboardFunc(teclado);

	glutMainLoop();
}

