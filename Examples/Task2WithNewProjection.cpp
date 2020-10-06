#include <GL/glut.h>
#include <iostream>

using namespace std;

void init(void);
void display(void);
bool draw = false;

GLint xp, yp; // Valores em pixel
GLfloat xf, yf; // valores na escala de -1 a 1
GLint width = 800;
GLint heigth = 800;

void init(void) {
    glClearColor(1, 1, 1, 1);

    glMatrixMode (GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
}

void display() {
    // Converter de pixel para nova escala
    xf = xp * (2.0/width) + (-1);
    yf = 1 - yp * (2.0/heigth);

    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(50);

    if (draw) {
        glBegin(GL_POINTS);
        glVertex3f(xf, yf, 0.0);
        glEnd();
    }
  glFlush();
}

void handleMouse(GLint button, GLint action, GLint x, GLint y) {
    if (button == GLUT_LEFT_BUTTON and action == GLUT_UP) {
        xp = x; yp = y;  // Obter os valores em pixel
        draw = true;
    } else if (button == GLUT_RIGHT_BUTTON and action == GLUT_UP) {
        glClearColor(1, 1, 1, 1); 
        glClear(GL_COLOR_BUFFER_BIT);
        draw = false;
    }

    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(width, heigth);
    glutInitWindowPosition(200, 200);
    glutCreateWindow("Tarefa 2");

    init();

    glutDisplayFunc(display);
    glutMouseFunc(handleMouse);

    glutMainLoop();

    return 0;
}