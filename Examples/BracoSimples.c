#include <GL/glut.h>
#include <stdlib.h>

static int shoulder = 0, elbow = 0, index = 0, middle = 0, thumb = 0, base = 0;

void init(void);
void display(void);
void reshape(int w, int h);
void keyboard(unsigned char key, int x, int y);

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(argv[0]);
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}

void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();

	/* base rotation */
	glRotatef((GLfloat)base, 0.0, 1.0, 0.0);

	glTranslatef(-1.0, 0.0, 0.0); 						/* origin shoulder (-1,0,0) */
	glRotatef((GLfloat)shoulder, 0.0, 0.0, 1.0);  		/* rotation at z-exis (all elements in stack */
	glTranslatef(1.0, 0.0, 0.0); 						/* center object to  (0,0,0) */ 
	
	/* creating shoulder */
	glPushMatrix();
	glScalef(2.0, 0.4, 1.0);
	glutWireCube(1.0);
	glPopMatrix();

	glTranslatef(1.0, 0.0, 0.0); 						/* origin elbow to (1,0,0) */
	glRotatef((GLfloat)elbow, 0.0, 0.0, 1.0);			/* rotation at z-exis (all elements in stack */
	glTranslatef(1.0, 0.0, 0.0);						/* center object to  (1,0,0) */ 		
	
	/* creating elbow */
	glPushMatrix();
	glScalef(2.0, 0.4, 1.0);
	glutWireCube(1.0);
	glPopMatrix();
	
	glPushMatrix();										/* matrix begin for first finger */
	
	glTranslatef(1.0, 0.1, 0.3);						/* origin finger at (3,0,0) */
	glRotatef((GLfloat)index, 0.0, 0.0, 1.0);			/* rotation at z-exis (all elements in stack */
	glTranslatef(0.25, 0.0, 0.0);						/* center object to  (3.25, 0.1, 0.25) */

	/* creating first finger */
	glPushMatrix();
	glScalef(0.5, 0.1, 0.25); 							/* size divided by 4 */
	glutWireCube(1.0);
	glPopMatrix();

	glPopMatrix();										/* matrix end for first finger */

	
	glPushMatrix();	
	
	glTranslatef(1.0, 0.1, -0.3);
	glRotatef((GLfloat)middle, 0.0, 0.0, 1.0);
	glTranslatef(0.25, 0.0, 0.0);

	glPushMatrix();
	glScalef(0.5, 0.1, 0.25);
	glutWireCube(1.0);
	glPopMatrix();

	glPopMatrix();


	glPushMatrix();
	glTranslatef(1.0, -0.2, 0.0);
	glRotatef((GLfloat)thumb, 0.0, 0.0, 1.0);
	glTranslatef(0.25, 0.0, 0.0);

	glPushMatrix();
	glScalef(0.5, 0.1, 0.25);
	glutWireCube(1.0);
	glPopMatrix();	
	glPopMatrix();

	glPopMatrix();
	glutSwapBuffers();
}

void reshape(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(65.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0, 0.0, -5.0);
}

void keyboard(unsigned char key, int x, int y) {
	switch (key)
	{
	case 's':
		shoulder = (shoulder + 5) % 360;
		glutPostRedisplay();
		break;
	case 'S':
		shoulder = (shoulder - 5) % 360;
		glutPostRedisplay();
		break;
	case 'e':
		elbow = (elbow + 5) % 360;
		glutPostRedisplay();
		break;
	case 'E':
		elbow = (elbow - 5) % 360;
		glutPostRedisplay();
		break;
	case 'i':
		index = (index + 5) % 360;
		glutPostRedisplay();
		break;
	case 'I':
		index = (index - 5) % 360;
		glutPostRedisplay();
		break;
	case 'm':
		middle = (middle + 5) % 360;
		glutPostRedisplay();
		break;
	case 'M':
		middle = (middle - 5) % 360;
		glutPostRedisplay();
		break;
	case 'p':
		thumb = (thumb + 5) % 360;
		glutPostRedisplay();
		break;
	case 'P':
		thumb = (thumb - 5) % 360;
		glutPostRedisplay();
		break;
	case 'b':
		base = (base - 5) % 360;
		glutPostRedisplay();
		break;
	case 'B':
		base = (base + 5) % 360;
		glutPostRedisplay();
		break;
	case 27:
		exit(0);
		break;
	default:
		break;
	}
}
