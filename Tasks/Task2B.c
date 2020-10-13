#include <GL/glut.h>
#include <stdlib.h>

static int shoulder = 0, elbow = 0, index = 0, middle = 0, thumb = 0, base = 0;

void init(void);
void display(void);

void reshape(int w, int h);
void keyboard(unsigned char key, int x, int y);

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1000, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}

void init(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();

    /* base rotation */    
    glRotatef((GLfloat)base, 0.0, 1.0, 0.0);    

    /* origem posicionada no ombro */
    glTranslatef(-1.0, 0.0, 0.0);
    glRotatef((GLfloat)shoulder, 0.0, 0.0, 1.0);

    /* origem posicionada no centro do braço */
    glTranslatef(2.0, 0.0, 0.0);
    glPushMatrix();
    glColor3f(1.0, 0.0, 0.0);
    glScalef(2.0, 0.4, 1.0);
    glutWireCube(1.0);
    glutSolidCube(1.0);
    glPopMatrix();

    /* origem posicionada no cotovelo */
    glTranslatef(1.0, 0.0, 0.0);
    glRotatef((GLfloat)elbow, 0.0, 0.0, 1.0);
    glTranslatef(1.0, 0.0, 0.0);
    glPushMatrix();
    glColor3f(0.0, 1.0, 0.0);
    glScalef(2.0, 0.4, 1.0);
    glutWireCube(1.0);
    glutSolidCube(1.0);
    glPopMatrix();

    /* index origin */
    glPushMatrix();
    glTranslatef(0.7, -0.1, 0);
    glRotatef((GLfloat)index, 0.0, 0.0, 0.7);
    glTranslatef(0.7, -0.1, 0.0);
    glColor3f(0.0, 0.0, 1.0);
    glScalef(0.5, 0.15, 0.3);
    glutWireCube(1.0);
    glutSolidCube(1.0);
    glPopMatrix();    

    /* middle origin*/
    glPushMatrix();
    glTranslatef(0.7, 0.1, 0);
    glRotatef((GLfloat)middle, 0.0, 0.0, 0.5);
    glTranslatef(0.6, 0.1, 0.0);
    glColor3f(1.0, 1.0, 0.0);
    glScalef(0.5, 0.15, 0.3);
    glutWireCube(1.0);
    glutSolidCube(1.0);
    glPopMatrix();

    /* thumb origin */
    glPushMatrix();
    glTranslatef(0.7, 0.0, -0.2);
    glRotatef((GLfloat)thumb, 0.0, 1.0, 0.0);
    glTranslatef(0.6, 0.0, 0.2);
    glColor3f(1.0, 0.0, 1.0);
    glScalef(0.5, 0.15, 0.3);
    glutWireCube(1.0);
    glutSolidCube(1.0);
    glPopMatrix();    

    /* origem volta para o sistema de coordenadas original */
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
    switch (key) {
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
        index = (index - 5) % 360;
        glutPostRedisplay();
        break;
    case 'I':
        index = (index + 5) % 360;
        glutPostRedisplay();
        break;
    case 'm':
        middle = (middle - 5) % 360;
        glutPostRedisplay();
        break;
    case 'M':
        middle = (middle + 5) % 360;
        glutPostRedisplay();
        break;
    case 'p':
        thumb = (thumb - 5) % 360;
        glutPostRedisplay();
        break;
    case 'P':
        thumb = (thumb + 5) % 360;
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
    default:
        break;
    }
}
