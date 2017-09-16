//Semestre 2018 - 2
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//******Reyes Aragón Aurora ******//
//*************											******//
//************************************************************//
#include "Main.h"


float transY = 0.0f;
float transZ = -15.0f;
float transX = 0.0f;
float angleX = 0.0f;
float angleY = 0.0f;
int screenW = 0.0;
int screenH = 0.0;
float angCodo = 0.0f;
float angHombro = 0.0f;
float angMano = 0.0f;
float angPulgar1 = 0.0f;
float angPulgar2 = 0.0f;
float angInd1 = 0.0f;
float angInd2 = 0.0f;
float angInd3 = 0.0f;
float angMedi1 = 0.0f;
float angMedi2 = 0.0f;
float angMedi3 = 0.0f;
float angAnu1 = 0.0f;
float angAnu2 = 0.0f;
float angAnu3 = 0.0f;
float angMen1 = 0.0f;
float angMen2 = 0.0f;
float angMen3 = 0.0f;



void InitGL(void)     // Inicializamos parametros
{

	//glShadeModel(GL_SMOOTH);							// Habilitamos Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo
	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
														//glEnable(GL_LIGHTING);
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
														//glEnable ( GL_COLOR_MATERIAL );
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void prisma(void)
{
	GLfloat vertice[8][3] = {
		{ 0.5 ,-0.5, 0.5 },    //Coordenadas Vértice 0 V0
		{ -0.5 ,-0.5, 0.5 },    //Coordenadas Vértice 1 V1
		{ -0.5 ,-0.5, -0.5 },    //Coordenadas Vértice 2 V2
		{ 0.5 ,-0.5, -0.5 },    //Coordenadas Vértice 3 V3
		{ 0.5 ,0.5, 0.5 },    //Coordenadas Vértice 4 V4
		{ 0.5 ,0.5, -0.5 },    //Coordenadas Vértice 5 V5
		{ -0.5 ,0.5, -0.5 },    //Coordenadas Vértice 6 V6
		{ -0.5 ,0.5, 0.5 },    //Coordenadas Vértice 7 V7
	};

	glBegin(GL_POLYGON);	//Front
							//glColor3f(1.0,0.0,0.0);
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[4]);
	glVertex3fv(vertice[7]);
	glVertex3fv(vertice[1]);
	glEnd();

	glBegin(GL_POLYGON);	//Right
	glColor3f(0.0, 0.0, 1.0);
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[3]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[4]);
	glEnd();

	glBegin(GL_POLYGON);	//Back
	glColor3f(0.0, 1.0, 0.0);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[3]);
	glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);  //Left
	glColor3f(1.0, 1.0, 1.0);
	glVertex3fv(vertice[1]);
	glVertex3fv(vertice[7]);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);  //Bottom
	glColor3f(0.4, 0.2, 0.6);
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[1]);
	glVertex3fv(vertice[2]);
	glVertex3fv(vertice[3]);
	glEnd();

	glBegin(GL_POLYGON);  //Top
	glColor3f(0.8, 0.2, 0.4);
	glVertex3fv(vertice[4]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[7]);
	glEnd();
}

void display(void)   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limiamos pantalla y Depth Buffer
														//glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	/*
	glTranslatef(0.0f, 0.0f, transZ);

	glPushMatrix();
	glTranslatef(-2.0, 1.0, 1.0);
	prisma();
	glPopMatrix();



	glScalef(3.0, 5.0, 2.0);
	glTranslated(0.0, 0.0, 0.0);
	glRotatef(50 * transZ, 0.0, 1.0, 0.0);
	prisma();
	*/

	glTranslatef(transX, transY, transZ);
	glRotatef(angleY, 0.0, 1.0, 0.0);
	glRotatef(angleX, 1.0, 0.0, 0.0);
	// codigo aqui


	glPushMatrix();


	//cabeza
	glPushMatrix();
	glColor3f(1.0, 0.0, 0.0);										//0,0,0 (pivote)
	prisma();
	glPopMatrix();


	//cuello
	glPushMatrix();
	glTranslatef(0.0, -0.75, 0.0);
	glScalef(0.5, 0.5, 1.0);
	glColor3f(0.0, 1.0, 0.0);
	prisma();													//0,-0.75,0 (pivote)
	glPopMatrix();


	//cuerpo
	glPushMatrix();
	glTranslatef(0.0, -2.5, 0.0);
	glScalef(3.0, 3.0, 1.0);
	glColor3f(0.0, 0.0, 1.0);									//0,-2.5,0 (pivote)
	prisma();
	glPopMatrix();


	//Brazo izquierdo

	glPushMatrix();
	glTranslatef(-2.0, -1.5, 0.0);
	glScalef(2.0, 2.0, 1.0);

	glPushMatrix();

	//hombro

	glRotatef(angHombro, 0.0, 0.0, 1.0);

	glPushMatrix();
	glColor3f(1.0, 0.0, 0.0);
	glScaled(0.5, 0.5, 1.0);
	prisma();
	glPopMatrix();
	//bicep
	glPushMatrix();
	glColor3f(0.0, 0.0, 1.0);
	glTranslatef(0.0, -0.75, 0.0);
	glScalef(0.5, 1.0, 1.0);
	prisma();
	glPopMatrix();
	//codo
	glTranslatef(0.0, -0.75, 0.0);
	glRotatef(angCodo, 0.0, 0.0, 1.0);
	glPushMatrix();
	glColor3f(1.0, 0.0, 0.0);
	glTranslatef(0.0, -0.75, 0.0);
	glScalef(0.5, 0.5, 1.0);
	prisma();
	glPopMatrix();
	//antebrazo
	glTranslatef(0.0, -0.75, 0.0);
	glPushMatrix();
	glColor3f(0.0, 0.0, 1.0);
	glTranslatef(0.0, -0.75, 0.0);
	glScalef(0.5, 1.0, 1.0);
	prisma();
	glPopMatrix();
	//mano
	glTranslatef(0.0, -0.75, 0.0);
	glRotatef(angMano, 0.0, 0.0, 1.0);
	glPushMatrix();
	glColor3f(1.0, 1.0, 0.0);
	glTranslatef(0.0, -0.75, 0.0);
	glScalef(0.5, 0.5, 1.0);
	prisma();
	glPopMatrix();

	//pulgar
	//parte 1
	glPushMatrix();
	glTranslatef(0.25, -0.75, 0.0);
	glRotatef(angPulgar1, 0.0, 0.0, 1.0);
	glTranslatef(0.1, 0.0, 0.0);
	glColor3f(1.0, 1.0, 1.0);
	glPushMatrix();
	glScalef(0.2, 0.1, 1.0);
	prisma();
	glPopMatrix();

	//parte 2
	glTranslatef(0.1, 0.0, 0.0);
	glRotatef(angPulgar2, 0.0, 0.0, 1.0);
	glTranslatef(0.1, 0.0, 0.0);
	glColor3f(1.0, 0.0, 1.0);
	glScalef(0.2, 0.1, 1.0);
	prisma();
	glPopMatrix();


	//indice
	glTranslatef(0.25, -2.0, 0.0);
	//Parte 1
	glTranslatef(0.0, -0.75, 0.0);
	glPushMatrix();
	glTranslatef(0.10, -0.175, 0.0);
	glRotatef(angInd1, 1.0, 0.0, 0.0);
	glTranslatef(0.10, -0.175, 0.0);
	glColor3f(1.0, 0.0, 0.0);
	glPushMatrix();
	glScalef(0.1, 0.2, 1.0);
	prisma();
	glPopMatrix();

	//parte2
	glTranslatef(0.0, -0.1, 0.0);
	glRotatef(angInd2, 1.0, 0.0, 0.0);
	glTranslatef(0.0, -0.1, 0.0);
	glColor3f(0.0, 0.0, 1.0);
	glPushMatrix();
	glScalef(0.1, 0.2, 1.0);
	prisma();
	glPopMatrix();
	//Parte3
	glTranslatef(0.0, -0.1, 0.0);
	glRotatef(angInd3, 1.0, 0.0, 0.0);
	glTranslatef(0.0, -0.1, 0.0);
	glColor3f(0.0, 1.0, 1.0);
	glScalef(0.1, 0.2, 1.0);
	prisma();

	glPopMatrix();


	//medio

	//Parte 1
	glPushMatrix();
	glTranslatef(0.05, -0.175, 0.0);
	glRotatef(angMedi1, 1.0, 0.0, 0.0);
	glTranslatef(0.05, -0.175, 0.0);
	glColor3f(1.0, 1.0, 0.0);
	glPushMatrix();
	glScalef(0.1, 0.2, 1.0);
	prisma();
	glPopMatrix();

	//parte2
	glTranslatef(0.0, -0.1, 0.0);
	glRotatef(angMedi2, 1.0, 0.0, 0.0);
	glTranslatef(0.0, -0.1, 0.0);
	glColor3f(1.0, 0.0, 1.0);
	glPushMatrix();
	glScalef(0.1, 0.2, 1.0);
	prisma();
	glPopMatrix();
	//Parte3
	glTranslatef(0.0, -0.1, 0.0);
	glRotatef(angMedi3, 1.0, 0.0, 0.0);
	glTranslatef(0.0, -0.1, 0.0);
	glColor3f(1.0, 1.0, 1.0);
	glScalef(0.1, 0.2, 1.0);
	prisma();

	glPopMatrix();

	//anular

	//Parte 1
	glPushMatrix();
	glTranslatef(0.00, -0.175, 0.0);
	glRotatef(angAnu1, 1.0, 0.0, 0.0);
	glTranslatef(0.00, -0.175, 0.0);
	glColor3f(1.0, 0.5, 0.0);
	glPushMatrix();
	glScalef(0.1, 0.2, 1.0);
	prisma();
	glPopMatrix();

	//parte2
	glTranslatef(0.0, -0.1, 0.0);
	glRotatef(angAnu2, 1.0, 0.0, 0.0);
	glTranslatef(0.0, -0.1, 0.0);
	glColor3f(0.5, 0.0, 1.0);
	glPushMatrix();
	glScalef(0.1, 0.2, 1.0);
	prisma();
	glPopMatrix();
	//Parte3
	glTranslatef(0.0, -0.1, 0.0);
	glRotatef(angAnu3, 1.0, 0.0, 0.0);
	glTranslatef(0.0, -0.1, 0.0);
	glColor3f(1.0, 1.0, 0.2);
	glScalef(0.1, 0.2, 1.0);
	prisma();

	glPopMatrix();

	//meñique

	//Parte 1
	glPushMatrix();
	glTranslatef(-0.05, -0.175, 0.0);
	glRotatef(angMen1, 1.0, 0.0, 0.0);
	glTranslatef(-0.05, -0.175, 0.0);
	glColor3f(0.0, 0.5, 0.0);
	glPushMatrix();
	glScalef(0.1, 0.2, 1.0);
	prisma();
	glPopMatrix();

	//parte2
	glTranslatef(0.0, -0.1, 0.0);
	glRotatef(angMen2, 1.0, 0.0, 0.0);
	glTranslatef(0.0, -0.1, 0.0);
	glColor3f(0.5, 0.7, 1.0);
	glPushMatrix();
	glScalef(0.1, 0.2, 1.0);
	prisma();
	glPopMatrix();
	//Parte3
	glTranslatef(0.0, -0.1, 0.0);
	glRotatef(angMen3, 1.0, 0.0, 0.0);
	glTranslatef(0.0, -0.1, 0.0);
	glColor3f(1.0, 1.0, 0.8);
	glScalef(0.1, 0.2, 1.0);
	prisma();

	glPopMatrix();


	glPopMatrix();



	//Brazo derecho
	glPushMatrix();
	glTranslatef(3.0, -2.0, 0.0);
	glScalef(3.0, 1.0, 1.0);
	glColor3f(1.0, 0.0, 1.0);
	prisma();
	glPopMatrix();


	//Pierna izquierda
	glPushMatrix();
	glTranslatef(-1.0, -6.5, 0.0);
	glScalef(1.0, 5.0, 1.0);
	glColor3f(1.0, 0.0, 1.0);
	prisma();
	glPopMatrix();



	//Pierna derecha
	glPushMatrix();
	glTranslatef(1.0, -6.5, 0.0);
	glScalef(1.0, 5.0, 1.0);
	glColor3f(1.0, 0.0, 1.0);
	prisma();
	glPopMatrix();

	//Pie izquerdo
	glPushMatrix();
	glTranslatef(-1.0, -10.0, 0.0);
	glScalef(2.0, 2.0, 1.0);
	glColor3f(1.0, 1.0, 2.0);
	prisma();
	glPopMatrix();


	//Pie derecho
	glPushMatrix();
	glTranslatef(1.0, -10.0, 0.0);
	glScalef(2.0, 2.0, 2.0);
	glColor3f(0.5, 1.0, 1.0);
	prisma();
	glPopMatrix();


	//mano izq
	glPushMatrix();
	glTranslatef(5.5, -2.0, 0.0);
	glScalef(2.0, 2.0, 1.0);
	glColor3f(0.5, 1.0, 1.0);
	prisma();
	glPopMatrix();

	glPopMatrix();




	glutSwapBuffers();
	// Swap The Buffers
}

void reshape(int width, int height)   // Creamos funcion Reshape
{
	if (height == 0)										// Prevenir division entre cero
	{
		height = 1;
	}

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista
	//glOrtho(-5,5,-5,5,0.2,20);	
	glFrustum(-0.1, 0.1, -0.1, 0.1, 0.1, 50.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
}

void keyboard(unsigned char key, int x, int y)  // Create Keyboard Function
{
	switch (key) {
	case 'w':
	case 'W':
		transY += 0.2f;
		break;
	case 's':
	case 'S':
		transY -= 0.2f;
		break;
	case 'a':
	case 'A':
		transX -= 0.2f;
		break;
	case 'd':
	case 'D':
		transX += 0.2f;
		break;
	case 'q':
	case 'Q':
		transZ += 0.3f;
		break;
	case 'e':
	case 'E':
		transZ -= 0.3f;
		break;

		break;
	case 27:        // Cuando Esc es presionado...
		exit(0);   // Salimos del programa
		break;
	default:        // Cualquier otra
		break;
	}
	glutPostRedisplay();
}

void arrow_keys(int a_keys, int x, int y)  // Funcion para manejo de teclas especiales (arrow keys)
{
	switch (a_keys) {
	case GLUT_KEY_UP:		// Presionamos tecla ARRIBA...
		angleX += 2.0f;
		break;
	case GLUT_KEY_DOWN:		// Presionamos tecla ABAJO...
		angleX -= 2.0f;
		break;
	case GLUT_KEY_LEFT:
		angleY += 2.0f;
		break;
	case GLUT_KEY_RIGHT:
		angleY -= 2.0f;
		break;
	default:
		break;
	}
	glutPostRedisplay();
}

int main(int argc, char** argv)   // Main Function
{
	glutInit(&argc, argv); // Inicializamos OpenGL
						   //glutInitDisplayMode (GLUT_RGBA | GLUT_SINGLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Sencillo )
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
	screenW = glutGet(GLUT_SCREEN_WIDTH);
	screenH = glutGet(GLUT_SCREEN_HEIGHT);
	glutInitWindowSize(500, 500);	// Tamaño de la Ventana
	glutInitWindowPosition(0, 0);	//Posicion de la Ventana
	glutCreateWindow("Practica 4"); // Nombre de la Ventana
	printf("Resolution H: %i \n", screenW);
	printf("Resolution V: %i \n", screenH);
	InitGL();						// Parametros iniciales de la aplicacion
	glutDisplayFunc(display);  //Indicamos a Glut función de dibujo
	glutReshapeFunc(reshape);	//Indicamos a Glut función en caso de cambio de tamano
	glutKeyboardFunc(keyboard);	//Indicamos a Glut función de manejo de teclado
	glutSpecialFunc(arrow_keys);	//Otras
	glutMainLoop();          // 

	return 0;
}