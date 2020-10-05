#include <GL/glut.h>
#include <iostream>

using namespace std;

void init(void);
void display(void);
bool draw = false;

GLint X, Y;

void init(void) {
    glClearColor(1, 1, 1, 1);

    glMatrixMode (GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 600.0, 0.0, 600.0);
    glClear(GL_COLOR_BUFFER_BIT);
}

void display() {
    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(50);

    if (draw) {
        glBegin(GL_POINTS);
        glVertex2i(X, Y);
        glEnd();
    }
  glFlush();
}

// The point is not shown.

void handleMouse(GLint button, GLint action, GLint x, GLint y) {
    if (button == GLUT_LEFT_BUTTON and action == GLUT_UP) {
        X = x; Y = 600-y;
        draw = true;
    } else if (button == GLUT_RIGHT_BUTTON and action == GLUT_UP) {
        glClearColor(1, 1, 1, 0); 
        glClear(GL_COLOR_BUFFER_BIT);
        draw = false;
    }

    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(10, 10);
    glutCreateWindow("Tarefa 2");

    init();

    glutDisplayFunc(display);
    glutMouseFunc(handleMouse);

    glutMainLoop();

    return 0;
}