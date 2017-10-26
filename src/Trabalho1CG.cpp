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
#define ALTURA_PAREDE 3
#define TEAPOT 4
#define CAM_PADRAO 2
#define CAM_TRAS 3
#define CAM_ROBO 4
#define FRENTE 1
#define TRAS 2
#define ESQUERDA 3
#define DIREITA 4

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
int CAM_ATUAL = CAM_PADRAO;
bool ROT_ARM_FRONT = true;
bool ROT_HEAD_RIGHT = true;
bool ROT_ROBO = false;
int posRobo[3] = {22,0,0};

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
	GLfloat luzAmbiente[4] = { 0.2,0.2,0.2,1.0 };
	GLfloat luzDifusa[4] = { 0.5,0.5,0.5, 1.0 };	   // "cor"
	GLfloat luzEspecular[4] = { 0.7,0.7,0.7, 1.0 };// "brilho"
	GLfloat posicaoLuz[4] = { 0.0, 50.0, 50.0, 1.0 };
	//
	// Capacidade de brilho do material
	GLfloat especularidade[4] = { 1.0,1.0,1.0,1.0 };
	GLint especMaterial = 10;


	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Habilita o modelo de coloriza��o de Gouraud
	glShadeModel(GL_SMOOTH);

	// Define a reflet�ncia do material
	glMaterialfv(GL_FRONT, GL_SPECULAR, especularidade);
	// Define a concentra��o do brilho
	glMateriali(GL_FRONT, GL_SHININESS, especMaterial);

	// Ativa o uso da luz ambiente
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente);

	// Define os par�metros da luz de n�mero 0
	glLightfv(GL_LIGHT1, GL_AMBIENT, luzAmbiente);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, luzDifusa);
	glLightfv(GL_LIGHT1, GL_SPECULAR, luzEspecular);
	glLightfv(GL_LIGHT1, GL_POSITION, posicaoLuz);

	// Habilita a defini��o da cor do material a partir da cor corrente
	glEnable(GL_COLOR_MATERIAL);
	//Habilita o uso de ilumina��o
	glEnable(GL_LIGHTING);
	// Habilita a luz de n�mero 0
	glEnable(GL_LIGHT1);
	// Habilita o depth-buffering
	glEnable(GL_DEPTH_TEST);


	switch(CAM_ATUAL){
		case CAM_PADRAO: //camera padrao olhando o labirinto de cima
			gluLookAt(camera[X],camera[Y],camera[Z], focus[X], focus[Y], focus[Z], 0,1,0);
			break;
		case CAM_ROBO: //camera que foca o robo
			gluLookAt(posRobo[X], posRobo[Y]-10, posRobo[Z]+30, posRobo[X], posRobo[Y], posRobo[Z], 0,1,0);
			break;
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

	glColor3f(1,0,0);
	drawMaze(wMaze, hMaze);
	drawRobot();
	glutSwapBuffers();
	glutPostRedisplay();

	//MOVIMENTOS DA CABEÇA
	if(ROT_HEAD_RIGHT == true){
		if(rotateHead < 30){ rotateHead = rotateHead + 1;
		}else{ ROT_HEAD_RIGHT = false; }
	}else if(ROT_HEAD_RIGHT == false){
		if(rotateHead > -30){ rotateHead = rotateHead - 1;
		}else{ ROT_HEAD_RIGHT = true; }
	}
	//MOVIMENTOS DOS BRAÇOS
	if(ROT_ARM_FRONT == true){
		if(rotateArms < 15){ rotateArms = rotateArms + 0.5;
		}else{ ROT_ARM_FRONT = false; }
	}else if(ROT_ARM_FRONT == false){
		if(rotateArms > -15){ rotateArms = rotateArms - 0.5;
		}else{ ROT_ARM_FRONT = true; }
	}

	//ROTACOES DO ROBO
	if(rotateRobo > 0){
		if(angleRotateRobot < rotateRobo){
			angleRotateRobot+=18;
		}
	}else if(rotateRobo < 0){
		if(angleRotateRobot > rotateRobo){
			angleRotateRobot-=18;
		}
	}
}

void animate(int value){
	glutPostRedisplay();
	draw();
	glutTimerFunc(60,animate,1);
}

void teclado(unsigned char key, int x, int y){
	switch(key){
		case 'q':
			exit(0);
			break;
		case 'Q':
			exit(0);
			break;
		case '-': //zoom in
			if(CAM_ATUAL == CAM_PADRAO){
				printf("Z%f Y%f\n", camera[Z], camera[Y]);
				if(camera[Y] > -30){
					camera[Z]-=0.5;
					camera[Y]--;
				}
			}
			break;
		case '+': //zoom out
			if(CAM_ATUAL == CAM_PADRAO){
				printf("Z%f Y%f\n", camera[Z], camera[Y]);
				if(camera[Z] < 100){
					camera[Z]+=0.5;
					camera[Y]++;
				}
			}
			break;
	}
	glutPostRedisplay();
}

void specialKeys(int key, int x, int y){
	printf("rotRob %f \n", rotateRobo);
	switch (key) {

	//CAMERAS
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
			CAM_ATUAL = CAM_PADRAO;
			camera[X] = hMaze/2;
			camera[Y] = wMaze/2;
			camera[Z] = 100;
			focus[X] = hMaze/2;
			focus[Y] =wMaze/2;
			focus[Z] = 0;
			break;
		case GLUT_KEY_F3: //camera padrao
//			CAM_ATUAL = CAM_TRAS;
		case GLUT_KEY_F4: //camera atras do robo estatica olhando o labirinto
			CAM_ATUAL = CAM_ROBO; //camera atras do robo
			break;
	//ROTACOES ROBO COM O MOUSE
		case GLUT_KEY_UP: //anda pra frente
			if(posRobo[Y]+2 < wMaze){
				if(labirinto[posRobo[X]-1][posRobo[Y]+2] && labirinto[posRobo[X]+1][posRobo[Y]+2]){
					if(angleRotateRobot != 0)
						angleRotateRobot = 0;
					if(lastMotion == FRENTE || lastMotion == -1){
						//ultimo movimento foi pra frente ou nao teve nenhum movimento ainda
						lastMotion = FRENTE;
						posRobo[Y]++;
						rotateRobo = 0;
						ROT_ROBO = false;
					}else if(lastMotion == TRAS){
						//ROTACIONAR 180
						lastMotion = FRENTE;
						rotateRobo = 180;
						ROT_ROBO = true;
					}else if(lastMotion == DIREITA){
						lastMotion = FRENTE;
						rotateRobo = 90;
						ROT_ROBO = true;
					}else if(lastMotion == ESQUERDA){
						lastMotion = FRENTE;
						rotateRobo = -90;
						ROT_ROBO = true;
					}
				}
			}
			break;
		case GLUT_KEY_DOWN: //anda pra tras
			if(posRobo[Y]-2 > 0){
				if(labirinto[posRobo[X]-1][posRobo[Y]-2] && labirinto[posRobo[X]+1][posRobo[Y]-2]){
					if(angleRotateRobot != 0)
						angleRotateRobot = 0;
					if(lastMotion == TRAS || lastMotion == -1){
						//ultimo movimento foi pra frente ou nao teve nenhum movimento ainda
						lastMotion = TRAS;
						posRobo[Y]--;
						rotateRobo = 0;
						ROT_ROBO = false;
					}else if(lastMotion == FRENTE){
						//ROTACIONAR 180
						lastMotion = TRAS;
						rotateRobo = 180;
						ROT_ROBO = true;
					}else if(lastMotion == DIREITA){
						lastMotion = TRAS;
						rotateRobo = -90;
						ROT_ROBO = true;
					}else if(lastMotion == ESQUERDA){
						lastMotion = TRAS;
						rotateRobo = 90;
						ROT_ROBO = true;
					}
				}
			}
	}
	glutPostRedisplay();
}

void drawMaze( double w, double h){
	glPushMatrix();
	glTranslatef(0,0,1.5);
	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++){
			if(labirinto[i][j] == 0){ //se posicao do labirinto for uma parede
				glPushMatrix();
					glColor3f(1,0,0);
					glScalef(1,1,ALTURA_PAREDE);
					glTranslatef(i,j,0);
					glutSolidCube(1);
				glPopMatrix();
			}else if(labirinto[i][j] == CONE){ //se for objeto CONE
				glPushMatrix();
					glColor3f(1,0.6,0.5);
					glTranslatef(i,j,-1.5);
					glutSolidCone(1,ALTURA_PAREDE,50,50);
				glPopMatrix();
			}else if(labirinto[i][j] == TORUS){ //se for objeto TORUS
				glPushMatrix();
					glColor3f(1,1,0);
					glTranslatef(i,j,0);
					glRotatef(90,0,1,0);
					glRotatef(rotateTORUS++,1,0,0);
					glutSolidTorus(0.3, 0.7,50,50);
				glPopMatrix();
			}else if(labirinto[i][j] == TEAPOT){ //se for objeto CHALEIRA
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
		if(ROT_ROBO == true){
			glRotatef(angleRotateRobot,0,0,1);
		}
		//PERNAS
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
		//TRONCO
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
//			glScalef(1,2,10);
			gluCylinder(arm,0.15,0.15, 2.5, 50,50);
		glPopMatrix();
		//BRAÇO ESQUERDO
		glPushMatrix();
			glTranslatef(-1.125, 0, 0.25*16);
			glutSolidSphere(0.25,50,50);
			glRotatef(+4.5,0,1,0);
			glRotatef(-rotateArms, 1,0,0);
			glRotatef(-180,1,0,0);
//			glScalef(1,2,10);
			gluCylinder(arm,0.15,0.15, 2.5, 50,50);
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
//			MAIN			//
//##########################//
int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowPosition(windowPosX,windowPosY);
	glutInitWindowSize(windowWidth,windowHeight);
	glutCreateWindow("Computação Gráfica - Trabalho 1 - Labirinto 3D");
	glClearColor(0,0,0,1);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	//FUNCOES DE CALLBACK
	glutReshapeFunc(reshapeWindow);
	glutTimerFunc(45, animate, 1);
	glutDisplayFunc(draw);
	glutSpecialFunc(specialKeys);
	glutFullScreen();
	glutKeyboardFunc(teclado);
	glutMainLoop();
}
