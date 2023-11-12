#include <GL/glut.h>
#include <stdlib.h>

GLfloat x, y;
GLfloat scale = 1.0f;
GLfloat angle = 0.0f;
GLfloat fakeNULL;
GLfloat *pX = &fakeNULL;
GLfloat *pY = &fakeNULL;
GLfloat mirror = 1.0f;

void Inicializa(void)
{
  x = 0.0;
  y = 0.0;
  angle = 0.0;
  scale = 1.0;
  glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
  glOrtho(-50, 50, -50, 50, -10, 10);
}

void poligono()
{
  glBegin(GL_POLYGON);

  glColor3f(1.0f, 0.0f, 0.0f);
  glVertex3f(0.0, 0.0, 0);
  glVertex3f(6.0, 0.0, 0);
  glVertex3f(6.0, 3.0, 0);
  glVertex3f(4.0, 5.0, 0);
  glVertex3f(2.0, 5.0, 0);
  glVertex3f(0.0, 3.0, 0);

  glColor3f(0.0f, 1.0f, 0.0f);
  glVertex3f(0.0, 0.0, 0);
  glVertex3f(-6.0, 0.0, 0);
  glVertex3f(-6.0, 3.0, 0);
  glVertex3f(-4.0, 5.0, 0);
  glVertex3f(-2.0, 5.0, 0);
  glVertex3f(0.0, 3.0, 0);

  glEnd();
}

void DesenhaCasa(void)
{
  glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
  glClear(GL_COLOR_BUFFER_BIT);

  glPushMatrix();
  glTranslatef(x, y, 0.0f);
  glRotatef(angle, 0.0f, 0.0f, 1.0f);
  glScalef(scale, scale, 1.0f*(mirror));
  poligono();
  glPopMatrix();

  glutSwapBuffers();
}
void TeclasEspeciais(int key, int X, int Y)
{
  switch (key)
  {
  case GLUT_KEY_UP:
    *pY += 1.0;
    break;
  case GLUT_KEY_DOWN:
    *pY -= 1.0;
    break;
  case GLUT_KEY_LEFT:
    *pX -= 1.0;
    break;
  case GLUT_KEY_RIGHT:
    *pX += 1.0;
    break;
  }
  glutPostRedisplay();
}

void TeclasNormais(unsigned char key, int X, int Y)
{
  switch (key)
  {
  case 't':
    pX = &x;
    pY = &y;
    break;
  case 's':
    pY = &scale;
    pX = &fakeNULL;
    break;
  case 'r':
    pY = &angle;
    pX = &fakeNULL;
    break;
  case 'm':
    mirror *= -1.0f;
    break;
  case 'i':
    glLoadIdentity();
    Inicializa();
    pX = &fakeNULL;
    pY = &fakeNULL;
    break;
  }
  glutPostRedisplay();
}

// Programa Principal
int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutCreateWindow("Poligono");
  glutDisplayFunc(DesenhaCasa);
  glutInitWindowSize(300, 300);
  
  glutSpecialFunc(TeclasEspeciais);
  glutKeyboardFunc(TeclasNormais);

  Inicializa();
  glutMainLoop();
}
