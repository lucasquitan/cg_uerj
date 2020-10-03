#include <GL/glut.h>
#include <iostream>

using namespace std;

void init(void);
void display(void);
void drawPoint(int x, int y);

void init(void) {
    // Ligth background
    glClearColor(1, 1, 1, 1);

    // Vizualization system
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity();
    glOrtho (-1, 1, -1, 1, -1, 1);
    glClear(GL_COLOR_BUFFER_BIT);
}

void display() {
  glFlush();
}

// The point is not shown.
void drawPoint(GLint x, GLint y) {
    glBegin(GL_POINTS);
        glColor3f(0.0f, 0.0f, 0.0f);
        glPointSize(50);
        glVertex2i(x, y);
    glEnd();

    cout << "Criado em: " << x << " / " << y << "\n";
    glFlush();
}

void handleMouse(GLint button, GLint action, GLint x, GLint y) {
    switch (button) {
        case GLUT_LEFT_BUTTON: {
            if (action == GLUT_UP) drawPoint(x,y);
        }
        case GLUT_RIGHT_BUTTON: {
            break;
        }
        default: break;
    }

    display();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(200, 200);
    glutCreateWindow("Tarefa 2");

    init();

    glutDisplayFunc(display);
    glutMouseFunc(handleMouse);

    glutMainLoop();

    return 0;
}
