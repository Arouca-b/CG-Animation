#include <GL/glut.h> //O arquivo glut.h inclui, além dos protótipos das funções GLUT, os arquivos gl.h e glu.h,
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#define PX -9.0
#define PY 9.5

float horizontal = 0, vertical = 0, escalar=1;
float pontoMedioX = PX;
float pontoMedioY = PY;
float rotation = 0;

void display(void);
void keyboard(unsigned char key, int x, int y);
void Special_keyboard(GLint tecla, int x, int y);
void DesenhaTexto(char *string);
void Coqueiros(int bol);
void Mar();
void helice(int bol, int angle, int x, int y);
void Helicoptero();
void Areia();
void Sol();
void Barco();
void janelasCabine(); 
void janelasCasco();
void duto();
void nuvens();
void nuvemModel1(float posx, float posy);

void Tronco();
void coco();
void folhas();
void arbusto();

void Circulo(float raio, float x, float y, int numSeg);

int main(int argc, char** argv){
  glutInit(&argc, argv); //Estabelece contato com sistema de janelas
  glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB); //Cores dos pixels serão expressos em RGB
  glutInitWindowSize (1720, 1080); //Posição inicial do canto superior esquerdo da janela a ser criada
  glutInitWindowPosition (100, 100); //Estabelece o tamanho (em pixels) da janela a ser criada
  glutCreateWindow (argv[1]); //Cria uma nova janela com valor de retorno (não usado)
  // que a identifica, caso tenha mais de uma
  glClearColor(0.0, 0.5, 1.0, 0.0); //selecionar cor de fundo (Branco)
  glOrtho (-15, 15,-15, 15, -1 ,1); //define as coordenadas do volume de recorte (clipping volume),
  glutDisplayFunc(display); //Função callback chamada para fazer o desenho
  glutKeyboardFunc(keyboard); //Chamada sempre que uma tecla for precionada
  glutSpecialFunc(Special_keyboard); // Registra a função para tratamento das teclas NÂO ASCII
  glutMainLoop(); //Depois de registradas as callbacks, o controle é entregue ao sistema de janelas
  return 0;
}

void display(void) {
  glClear(GL_COLOR_BUFFER_BIT); // Limpa a tela

   // Ativa o sombreamento suave para o gradiente
  glShadeModel(GL_SMOOTH);

  // Céu com efeito de pôr do sol ajustado com azul suave no topo
  glBegin(GL_POLYGON);
    glColor3ub(255, 170, 80);    // Laranja claro próximo ao horizonte
    glVertex2f(-15, -0.18);

    glColor3ub(255, 130, 100);   // Rosa suave subindo
    glVertex2f(-15, 15);

    glColor3ub(180, 200, 255);   // Azul claro no topo direito
    glVertex2f(15, 15);

    glColor3ub(255, 170, 80);    // Laranja claro próximo ao horizonte
    glVertex2f(15, -0.18);
  glEnd();

  //Chamando as funções que vão desenhar o cenário e os objetos na tela
  Sol();
  nuvens();
  Mar();
  Areia();
  Barco();
  Helicoptero();
  Coqueiros(0);
  Coqueiros(1);
  glutSwapBuffers(); // Executa os comandos OpenGL para renderização
}
//Função responsável pela modelagem do mar
void Mar() {
  // Desenha o gradiente e ondulações suaves invertidas
  glBegin(GL_QUAD_STRIP);
  for (float x = -15.0; x <= 15.0; x += 0.2) {
      float waveTop = 0.2 * sin(x * 1.2);  // Aumenta a ondulação

      glColor3ub(60, 180, 250);  // Azul claro para a base do mar
      glVertex2f(x, -15.0);      // Base do mar (próximo à areia)

      glColor3ub(25, 120, 240);  // Azul escuro para o topo
      glVertex2f(x, waveTop);    // Superfície com leve ondulação
  }
  glEnd();

  // Quebra das ondas próximo à areia
  glBegin(GL_QUADS);
  glColor3ub(200, 220, 255);  // Azul muito claro para simular espuma das ondas
  glVertex2f(-15.0, -15.0);
  glVertex2f(15.0, -15.0);
  glVertex2f(15.0, -14.5);   // Altura ajustada para a linha de espuma
  glVertex2f(-15.0, -14.5);
  glEnd();
}

//Função responsável pela modelagem do sol
void Sol(){
  glBegin(GL_POLYGON); //Iniciando construção de um polígono
    glColor3ub (255, 185, 0);
    Circulo(4.5, 0, 0, 180);
  glEnd();
}

//Função responsável pela modelagem do helicóptero
void Helicoptero(){
  rotation = (rotation>=360) ? 0 : rotation+45;
  
  glutPostRedisplay(); // atualizar a tela

  glPushMatrix();
    // Transladar para que o ponto médio esteja na origem
    glTranslatef(pontoMedioX, pontoMedioY, 0.0);

    // Aplicar a escala
    glScalef(escalar, escalar, 1.0);

    // Transladar de volta para a posição original
    glTranslatef(-pontoMedioX, -pontoMedioY, 0.0);


    //Estrutura completo do helicóptero
    glPushMatrix();

      //movimenta o helicóptero conforme as teclas são pressionadas
      glTranslated(horizontal, vertical, 0);

      //corpo do helicóptero
      glBegin(GL_POLYGON);
        glColor3ub (158, 0, 0);

        // Definimos os vértices do polígono que forma o corpo do helicóptero
        glVertex2f(- 5.8,  9.0);
        glVertex2f(- 5.8,  9.8);
        glVertex2f(- 5.9, 10.5);
        glVertex2f(- 6.2, 11.0);
        glVertex2f(- 6.7, 11.4);
        glVertex2f(- 7.2, 11.6);
        glVertex2f(- 8.0, 11.6);
        glVertex2f(- 8.9, 11.6);
        glVertex2f(- 9.5, 11.4);
        glVertex2f(-10.2, 11.0);
        glVertex2f(-10.7, 10.4);
        glVertex2f(-11.1,  9.7);
        glVertex2f(-11.7,  9.4);
        glVertex2f(-12.3,  9.2);
        glVertex2f(-12.9,  9.2);
        glVertex2f(-13.5,  9.1);
        glVertex2f(-13.8,  9.3);
        glVertex2f(-14.0,  9.8);
        glVertex2f(-14.4,  9.8);
        glVertex2f(-14.6,  9.4);
        glVertex2f(-14.3,  8.9);
        glVertex2f(-13.9,  8.5);
        glVertex2f(-13.3,  8.5);
        glVertex2f(-12.6,  8.5);
        glVertex2f(-11.9,  8.6);
        glVertex2f(-11.3,  8.6);
        glVertex2f(-10.8,  8.7);
        glVertex2f(-10.3,  8.6);
        glVertex2f(- 9.9,  8.4);
        glVertex2f(- 9.6,  8.0);
        glVertex2f(- 9.2,  7.8);
        glVertex2f(- 8.7,  7.6);
        glVertex2f(- 8.1,  7.6);
        glVertex2f(- 7.6,  7.7);
        glVertex2f(- 7.0,  7.8);
        glVertex2f(- 6.4,  8.0);
        glVertex2f(- 6.0,  8.4);
        glVertex2f(- 5.8,  9.0); //Fechando o polígono
      glEnd(); //fim Corpo do helicóptero


      //janela do helicóptero
      glBegin(GL_POLYGON); //Iniciando construção de um polígono
        glColor3ub (0, 0, 0);
        glVertex2f(-8.0, 11.6);
        glVertex2f(-8.0,  9.6);
        glVertex2f(-8.0,  9.5);
        glVertex2f(-8.0,  9.5);
        glVertex2f(-8.0,  9.5);
        glVertex2f(-8.0,  9.5);
        glVertex2f(-7.9,  9.5);
        glVertex2f(-5.8,  9.5);
        glVertex2f(-5.8,  9.8);
        glVertex2f(-5.9, 10.5);
        glVertex2f(-6.2, 11.0);
        glVertex2f(-6.7, 11.4);
        glVertex2f(-7.2, 11.6); //Fechando o polígono
      glEnd();


      glPushMatrix();
        //base suporte hélice
        glBegin(GL_POLYGON); //Iniciando construção de um polígono
          glVertex2f(-8.3, 11.7);
          glVertex2f(-7.8, 11.7);
          glVertex2f(-7.8, 11.6);
          glVertex2f(-8.3, 11.6); //Fechando o polígono
        glEnd();


        //suporte da hélice
        glBegin(GL_POLYGON); //Iniciando construção de um polígono
          glVertex2f(-8.1, 11.7);
          glVertex2f(-8.1, 12.2);
          glVertex2f(-7.9, 12.2);
          glVertex2f(-7.9, 11.7); //Fechando o polígono
        glEnd();
        glPushMatrix();  
          helice(0, rotation,0,0); //hélice direita
          helice(1, rotation,0,0); //hélice esquerda
        glPopMatrix();

        //conjunto hélices traseiras
        glPushMatrix();
          glPushMatrix();
            glTranslatef (-11.5, 4.4, 0.0);
            glScaled(0.3, 0.4, 0);
            helice(0, 45+rotation, 0, 0);
          glPopMatrix();

          glPushMatrix();
            glTranslatef (-11.5, 4.4, 0.0);
            glScaled(0.3, 0.4, 0);
            helice(1, 45+rotation,0,0);
          glPopMatrix();

          //base helices traseiras
          Circulo(0.15, -13.95, 9.2, 100);

        glPopMatrix();        //fim hélices traseiras
      glPopMatrix();

      //sutentação de pouso
      glPushMatrix();
        Circulo(0.15, -8.65, 8.1, 100);
        glBegin(GL_POLYGON); //Iniciando construção de um polígono
          glVertex2f(-8.75, 8.1);
          glVertex2f(-8.55, 8.1);
          glVertex2f(-8.95, 7.3);
          glVertex2f(-9.15, 7.3); //Fechando o polígono
        glEnd();
      glPopMatrix();

      glPushMatrix();
        Circulo(0.15, -7.55, 8, 100);
        glBegin(GL_POLYGON); //Iniciando construção de um polígono
          glVertex2f(-7.65, 8.1);
          glVertex2f(-7.45, 8.1);
          glVertex2f(-7.85, 7.3);
          glVertex2f(-8.05, 7.3);
        glEnd();
      glPopMatrix();

      glPushMatrix();
        glBegin(GL_POLYGON); //Iniciando construção de um polígono
          glVertex2f(-9.782, 7.347);
          glVertex2f(-7.075, 7.350);
          glVertex2f(-7.015, 7.332);
          glVertex2f(-6.974, 7.295);
          glVertex2f(-6.951, 7.244);
          glVertex2f(-6.974, 7.198);
          glVertex2f(-7.016, 7.168);
          glVertex2f(-7.072, 7.145);
          glVertex2f(-9.790, 7.144);
          glVertex2f(-9.829, 7.164);
          glVertex2f(-9.874, 7.191);
          glVertex2f(-9.897, 7.246);
          glVertex2f(-9.897, 7.246);
          glVertex2f(-9.882, 7.296);
          glVertex2f(-9.832, 7.329); //Fechando o polígono
        glEnd();
      glPopMatrix();
      //fim sustentação de pouso

    glPopMatrix();
  glPopMatrix();
}

// Função responsável pela modelagem das hélices
void helice(int bol, int angle, int x, int y){
  glPushMatrix();
  glTranslatef (-7.986, 12.062, 0.0);
  (bol==1)?glRotatef (180+angle, x, y, 1.0) : glRotatef (angle, x, y, 1.0);
  
  glTranslatef (7.986, -12.062, 0.0);

  glBegin(GL_POLYGON); //Iniciando construção de um polígono
    glVertex2f(-7.98, 12.13);
    glVertex2f(-7.98, 12.06);
    glVertex2f(-7.98, 11.98);
    glVertex2f(-2.91, 11.95);
    glVertex2f(-2.86, 11.95);
    glVertex2f(-2.79, 11.97);
    glVertex2f(-2.70, 12.01);
    glVertex2f(-2.66, 12.04);
    glVertex2f(-2.61, 12.08);
    glVertex2f(-2.58, 12.11);
    glVertex2f(-2.56, 12.14);
    glVertex2f(-2.55, 12.20);
    glVertex2f(-2.54, 12.24);
    glVertex2f(-2.54, 12.28);
    glVertex2f(-2.54, 12.32);
    glVertex2f(-2.55, 12.37);
    glVertex2f(-2.55, 12.44);
    glVertex2f(-2.57, 12.49);
    glVertex2f(-2.59, 12.54);
    glVertex2f(-2.63, 12.58);
    glVertex2f(-2.67, 12.60);
    glVertex2f(-2.70, 12.63);
    glVertex2f(-2.76, 12.65);
    glVertex2f(-2.81, 12.66);
    glVertex2f(-2.89, 12.67); //Fechando o polígono
  glEnd();
  glPopMatrix();
}

// Função que esenha os coqueiros, chamando funções menores que desenham cada parte do coqueiro
void Coqueiros(int bol) {
  glPushMatrix();
  if (bol){
    glTranslated(-13.5, 0, 1);
  }else{
    glTranslated(12.5, 0, 1);
  }
  Tronco();
  coco();
  folhas();
  arbusto();
  glPopMatrix();
}

//Função responsável por chamar as funções que desenham as nuvens no céu
//Função responsável por chamar as funções que desenham as nuvens no céu
void nuvens(){
  nuvemModel1(0, 0);

  glPushMatrix();  // Salva a matriz de transformação atual
      glTranslatef(15.0, 3.0, 0.0);  // Usa uma translação menor para manter a nuvem visível
      glScalef(0.5, 0.5, 1.0);  // Redimensiona a nuvem duplicada
      glRotatef(0, 0.0, 0.0, 1.0);  // Define um ângulo de rotação mudar a inclinação da nuvem
      nuvemModel1(0.1, 3);  // Desenha a nuvem duplicada com as transformações
  glPopMatrix();  // Restaura a matriz de transformação original

  glPushMatrix();  // Salva a matriz de transformação atual
      glTranslatef(15.0, 3.5, 0.0);  // Usa uma translação menor para manter a nuvem visível
      glScalef(1, 1, 1.0);  // Redimensiona a nuvem duplicada
      glRotatef(0, 0.0, 0.0, 1.0);  // Define um ângulo de rotação mudar a inclinação da nuvem
      nuvemModel1(-5, 5.5);  // Desenha a nuvem duplicada com as transformações
  glPopMatrix();  // Restaura a matriz de transformação original

  glPushMatrix();  // Salva a matriz de transformação atual
      glTranslatef(14.5, 3.0, 0.0);  // Usa uma translação menor para manter a nuvem visível
      glScalef(0.4, 0.4, 1.0);  // Redimensiona a nuvem duplicada
      glRotatef(0, 0.0, 0.0, 1.0);  // Define um ângulo de rotação mudar a inclinação da nuvem
      nuvemModel1(-10, 10);  // Desenha a nuvem duplicada com as transformações
  glPopMatrix();  // Restaura a matriz de transformação original

  glPushMatrix();  // Salva a matriz de transformação atual
      glTranslatef(15.0, 5.0, 0.0);  // Usa uma translação menor para manter a nuvem visível
      glScalef(0.4, 0.4, 1.0);  // Redimensiona a nuvem duplicada
      glRotatef(0, 0.0, 0.0, 1.0);  // Define um ângulo de rotação mudar a inclinação da nuvem
      nuvemModel1(-40, 15);  // Desenha a nuvem duplicada com as transformações
  glPopMatrix();  // Restaura a matriz de transformação original

  glPushMatrix();  // Salva a matriz de transformação atual
      glTranslatef(15.0, 5.0, 0.0);  // Usa uma translação menor para manter a nuvem visível
      glScalef(0.6, 0.6, 1.0);  // Redimensiona a nuvem duplicada
      glRotatef(0, 0.0, 0.0, 1.0);  // Define um ângulo de rotação mudar a inclinação da nuvem
      nuvemModel1(-40, 9);  // Desenha a nuvem duplicada com as transformações
  glPopMatrix();  // Restaura a matriz de transformação original

  glPushMatrix();  // Salva a matriz de transformação atual
      glTranslatef(2.0, 2.0, 0.0);  // Usa uma translação menor para manter a nuvem visível
      glScalef(0.3, 0.3, 1.0);  // Redimensiona a nuvem duplicada
      glRotatef(0, 0.0, 0.0, 1.0);  // Define um ângulo de rotação mudar a inclinação da nuvem
      nuvemModel1(-30, 13);  // Desenha a nuvem duplicada com as transformações
  glPopMatrix();  // Restaura a matriz de transformação original

  glPushMatrix();  // Salva a matriz de transformação atual
      glRotatef(-45, 0.0, 0.0, 1.0);  // Define um ângulo de rotação mudar, nesse caso 45 graus, a inclinação da nuvem
      glTranslatef(2.0, 2.0, 0.0);  // Usa uma translação menor para manter a nuvem visível
      glScalef(0.3, 0.3, 1.0);  // Redimensiona a nuvem duplicada
      nuvemModel1(-1.5, -42);  // Desenha a nuvem duplicada com as transformações
  glPopMatrix();  // Restaura a matriz de transformação original
}

//Função responsável pela modelagem do barco
  void Barco() {
  glPushMatrix();
  glTranslated(-2, 0, 0);
    glPushMatrix();
      //casco do barco
      glBegin(GL_POLYGON); 
        glColor3ub(0,0,0); 
        glVertex2f(-5, -2);
        glVertex2f(-4.5, -4.2);
        glVertex2f(0.5, -4.2);
        glVertex2f(0.5, -2);
      glEnd();

      glBegin(GL_TRIANGLES);
        glVertex2f(0, -2);
        glVertex2f(0, -4.2);
        glVertex2f(2, -2);
      glEnd();
      Circulo(.8, 0.3, -3.4, 100);

      //cabine do barco
      glBegin(GL_POLYGON);
        glColor3ub(37, 61, 110);
        glVertex2f(-3.2, -2);
        glVertex2f(-3.2, -0.5);
        glVertex2f(0, -0.5);
        glVertex2f(0, -2);
      glEnd();

      //janelas da cabine
      glPushMatrix();
        glPushMatrix();
          glTranslated(0, -0.8, 0);
          janelasCabine();
        glPopMatrix();

        glPushMatrix();
          glTranslated(0, -1.2, 0);
          janelasCabine();
        glPopMatrix();
      glPopMatrix();
      //fim janelas da cabine

      //janelas no casco
      glPushMatrix();
        glPushMatrix();
        glTranslated(0, -2.7, 0);
          janelasCasco();
        glPopMatrix();
        glPushMatrix();
        glTranslated(0, -3.5, 0);
          janelasCasco();
        glPopMatrix();
      glPopMatrix();
      
      //????
      glBegin(GL_POLYGON);
        glColor3ub(203, 204, 206);
        glVertex2f(-5, -2);
        glVertex2f(-5.1, -1.8);
        glVertex2f(2.1, -1.8);
        glVertex2f(2, -2);
      glEnd();

      //Duto fumaça
      glPushMatrix();
        glPushMatrix();
          duto();
        glPopMatrix();

        glPushMatrix();
          glTranslated(0.74, 0, 0);
          duto();
        glPopMatrix();

        glPushMatrix();
          glTranslated(1.48, 0, 0);
          duto();
        glPopMatrix();
        
        glPushMatrix();
          glTranslated(2.22, 0, 0);
          duto();
        glPopMatrix();
      glPopMatrix();
      //fim Duto fumaça
    glPopMatrix();
  glPopMatrix();
}

void janelasCabine(){
    glPushMatrix();
      glBegin(GL_POLYGON); //Iniciando construção de um polígono
        glColor3ub(254, 254, 155);
        glVertex2f(-3.2, 0.0);
        glVertex2f(-3.2, -0.2);
        glVertex2f(0, -0.2);
        glVertex2f(0, -0);
      glEnd();

      for (float i = -0.2; i > -3.2; i-=0.2){
        glBegin(GL_LINES);
          glColor3ub(0, 0, 0);
          glVertex2f(i, 0);
          glVertex2f(i, -0.2);
        glEnd();
      }
    glPopMatrix();
}

void janelasCasco(){
    glPushMatrix();
    glColor3ub(254, 254, 155);
      for (float i = 0.6; i > -4; i-=0.15){
        Circulo(0.05, i, 0, 100);
      }
    glPopMatrix();
}

void duto(){
  glBegin(GL_POLYGON); //Iniciando construção de um polígono
    glColor3ub(230, 152, 6); // amarelo
    glVertex2f(-2.96, -0.5);
    glVertex2f(-2.46, -0.5);
    glVertex2f(-2.46, 0);
    glVertex2f(-2.96, 0);
  glEnd();

  glBegin(GL_POLYGON); //Iniciando construção de um polígono
    glColor3ub(0, 0, 0);
    glVertex2f(-2.96, 0.3);
    glVertex2f(-2.46, 0.3);
    glVertex2f(-2.46, 0);
    glVertex2f(-2.96, 0);
  glEnd();
}

//Função que desenha um círculo ou um semi-círculo
void Circulo(float raio, float x, float y, int numSeg) {
  glBegin(GL_POLYGON); //Iniciando construção de um polígono

  //Se for um semi-círculo, desenha de 0 a pi (180 graus), caso contrário, desenha de 0 a 2pi (360 graus)
  float anguloMax = 2.0f * M_PI;

  for (int i = 0; i <= numSeg; i++) {
    float angulo = anguloMax * i / numSeg; // Ângulo em radianos
    float dx = raio * cos(angulo); // Coordenada x
    float dy = raio * sin(angulo); // Coordenada y

    //Inverte a coordenada y para que o semi-círculo fique virado para cima
    glVertex2f(x + dx, y + dy); // Ponto na borda do círculo ou semi-círculo
  }

  glEnd();
}

// Função responsável pela modelagem do tronco do coqueiro
void Tronco() {
    //Formando o tronco, utilizando círculos
  glBegin(GL_POLYGON); //Iniciando construção de um polígono
    glColor3ub(115, 97, 84); //Marrom
    Circulo(0.8, 1, -6 + 2, 360);
    Circulo(0.8, 1, -7 + 2, 360);
    Circulo(0.8, 1, -8 + 2, 360);
    Circulo(0.8, 1, -9 + 2, 360);
    Circulo(0.8, 1, -10 + 2, 360);
    Circulo(0.8, 1, -11 + 2, 360);
    Circulo(0.8, 1, -12 + 2, 360);
    Circulo(0.8, 1, -13 + 2, 360);
    Circulo(0.8, 1, -14 + 2, 360);
    Circulo(0.8, 1, -15 + 2, 360);
    Circulo(0.8, 1, -16 + 2, 360);
  glEnd();
}

// Função responsável pela modelagem dos cocos pendurados
void coco() {
  //Formando os cocos através de círculos
  glBegin(GL_POLYGON); //Iniciando construção de um polígono
    glColor3ub(64, 171, 81);//Verde um pouco mais claro
    Circulo(0.5,  0.5, -4.7, 360);
    Circulo(0.5,  1.5, -4.7, 360);
    Circulo(0.5,  1.0, -5.2, 360);
  glEnd();
}

// Função responsável pela modelagem da folhagem dos coqueiros
void folhas(){
  //Desenhando cada parte que forma as folhas
  glBegin(GL_POLYGON); //Iniciando construção de um polígono
    glColor3ub(50, 130, 20);//Verde escuro
    glVertex2f( 0.9665, -4.2274);
    glVertex2f( 0.2737, -4.5353);
    glVertex2f(-0.3934, -5.2923);
    glVertex2f(-0.9708, -6.2289);
    glVertex2f(-1.3428, -7.0757);
    glVertex2f(-1.4583, -6.3829);
    glVertex2f(-1.3428, -5.1640);
    glVertex2f(-0.6243, -3.8296);
    glVertex2f(-0.2009, -3.3036);
    glVertex2f(-0.9066, -3.3164);
    glVertex2f(-1.8047, -3.6372);
    glVertex2f(-2.4334, -4.0991);
    glVertex2f(-2.9081, -4.5866);
    glVertex2f(-2.7285, -3.6500);
    glVertex2f(-1.9459, -2.7904);
    glVertex2f(-1.0221, -2.4183);
    glVertex2f(-0.1240, -2.2900);
    glVertex2f(-1.3942, -1.7896);
    glVertex2f(-2.2795, -1.5458);
    glVertex2f(-2.9723, -1.5458);
    glVertex2f(-2.3401, -1.2531);
    glVertex2f(-1.5616, -1.0711);
    glVertex2f(-1.0000, -1.0000);
    glVertex2f(-0.5000, -1.0000);
    glVertex2f( 0.0408, -1.1419);
    glVertex2f( 0.5867, -1.4249);
    glVertex2f( 0.8092, -1.5665);
    glVertex2f( 1.5674, -0.7425);
    glVertex2f( 2.3105, -0.3482);
    glVertex2f( 3.2030, -0.2637);
    glVertex2f( 3.0000, -0.5000);
    glVertex2f( 2.4363, -0.9785);
    glVertex2f( 2.0846, -1.5378);
    glVertex2f( 1.9463, -1.8433);
    glVertex2f( 2.0731, -1.8664);
    glVertex2f( 2.5458, -1.5781);
    glVertex2f( 3.3010, -1.3014);
    glVertex2f( 3.9064, -1.2264);
    glVertex2f( 4.4368, -1.3014);
    glVertex2f( 4.6904, -1.3936);
    glVertex2f( 4.2984, -1.6012);
    glVertex2f( 3.1339, -2.1546);
    glVertex2f( 2.4420, -2.6621);
    glVertex2f( 3.0128, -2.6677);
    glVertex2f( 4.0330, -3.3036);
    glVertex2f( 4.8284, -4.1632);
    glVertex2f( 5.1107, -5.1896);
    glVertex2f( 5.0466, -5.6772);
    glVertex2f( 4.6616, -5.2153);
    glVertex2f( 3.9560, -4.5866);
    glVertex2f( 3.0000, -4.0000);
    glVertex2f( 2.2752, -3.8681);
    glVertex2f( 1.6594, -3.9194);
    glVertex2f( 1.4290, -3.8776);
    glVertex2f( 1.1906, -3.9607);
    glVertex2f( 0.9800, -4.1000);
  glEnd();
}

//Função responsável pela modelagem dos arbustos que ficam debaixo dos coqueiros
void arbusto() {
  //Desenhando cada detalhe dos arbustos
  glBegin(GL_POLYGON); //Iniciando construção de um polígono
    glColor3ub(1, 119, 2);
    glVertex2f(-4.2120, -16.6907);
    glVertex2f(-4.0529, -16.2670);
    glVertex2f(-3.2217, -15.6197);
    glVertex2f(-3.0000, -15.5000);
    glVertex2f(-3.2762, -15.3813);
    glVertex2f(-3.2830, -15.1973);
    glVertex2f(-2.7515, -14.7749);
    glVertex2f(-2.4449, -14.6658);
    glVertex2f(-2.0633, -14.5841);
    glVertex2f(-2.0581, -14.5037);
    glVertex2f(-2.4710, -14.3525);
    glVertex2f(-2.2950, -14.2081);
    glVertex2f(-1.9565, -14.0388);
    glVertex2f(-1.4601, -13.7997);
    glVertex2f(-1.6316, -13.5560);
    glVertex2f(-1.8087, -13.4370);
    glVertex2f(-1.4799, -13.2932);
    glVertex2f(-1.3018, -13.3069);
    glVertex2f(-0.8459, -13.0138);
    glVertex2f(-0.6551, -13.2487);
    glVertex2f(-0.3396, -12.6616);
    glVertex2f(0.2328 , -13.1606);
    glVertex2f(0.3273 , -12.8328);
    glVertex2f(0.4702 , -12.8016);
    glVertex2f(0.9392 , -12.5336);
    glVertex2f(1.0687 , -12.5291);
    glVertex2f(0.9169 , -12.9222);
    glVertex2f(1.0167 , -12.9333);
    glVertex2f(1.2883 , -12.7508);
    glVertex2f(1.5093 , -12.6981);
    glVertex2f(1.5924 , -12.7042);
    glVertex2f(1.6106 , -12.7488);
    glVertex2f(1.5194 , -13.3326);
    glVertex2f(1.6466 , -13.4359);
    glVertex2f(2.4561 , -13.1862);
    glVertex2f(2.6455 , -13.2379);
    glVertex2f(2.5938 , -13.5737);
    glVertex2f(2.7661 , -13.8751);
    glVertex2f(3.0158 , -13.7373);
    glVertex2f(3.4636 , -13.6081);
    glVertex2f(4.1870 , -13.7976);
    glVertex2f(3.7133 , -14.2454);
    glVertex2f(3.8167 , -14.3746);
    glVertex2f(4.1870 , -14.4607);
    glVertex2f(4.9017 , -14.6760);
    glVertex2f(5.3409 , -14.9688);
  glEnd();
}

//Função responsável pela modelagem de uma nuvem
void nuvemModel1(float posx, float posy) {
    // Sombra difusa da nuvem - camada mais externa
    glColor3ub(210, 210, 210); // Cinza claro
    Circulo(1.4, -6.6 + posx + 0.15, 12.5 - posy - 0.15, 360);
    Circulo(1.4, -4.9 + posx + 0.15, 12.5 - posy - 0.15, 360);
    Circulo(1.4, -3.2 + posx + 0.15, 12.5 - posy - 0.15, 360);

    // Camada principal da nuvem em branco
    glColor3ub(255, 255, 255); // Branco para a camada superior da nuvem
    Circulo(1.3, -6.6 + posx, 12.5 - posy, 360);
    Circulo(1.3, -4.9 + posx, 12.5 - posy, 360);
    Circulo(1.3, -3.2 + posx, 12.5 - posy, 360);
    Circulo(1.3, -5.7 + posx, 13.5 - posy, 360);
    Circulo(1.3, -4.0 + posx, 13.5 - posy, 360);
}

//Função responsável pela modelagem da areia
void Areia(){
  glBegin(GL_POLYGON); //Iniciando construção de um polígono
    glColor3ub (206, 193, 174);
    glVertex2f(-17.139, -15.042);
    glVertex2f(-15.003, -13.729);
    glVertex2f(-14.390, -13.249);
    glVertex2f(-13.545, -13.066);
    glVertex2f(-12.932, -12.785);
    glVertex2f(-12.270, -12.570);
    glVertex2f(-11.789, -12.271);
    glVertex2f(-11.000, -12.000);
    glVertex2f(-10.249, -11.791);
    glVertex2f(- 9.636, -11.377);
    glVertex2f(- 8.962, -11.303);
    glVertex2f(- 8.242, -11.043);
    glVertex2f(- 7.807, -10.434);
    glVertex2f(- 7.043, -10.179);
    glVertex2f(- 6.279, -10.154);
    glVertex2f(- 5.482, -10.064);
    glVertex2f(- 4.775, -10.050);
    glVertex2f(- 4.071, -10.145);
    glVertex2f(- 3.446, -10.104);
    glVertex2f(- 2.997, - 9.902);
    glVertex2f(- 2.383, - 9.499);
    glVertex2f(- 1.578, - 9.245);
    glVertex2f(- 0.858, - 9.140);
    glVertex2f(- 0.082, - 8.943);
    glVertex2f(  0.729, - 8.984);
    glVertex2f(  1.473, - 9.166);
    glVertex2f(  1.998, - 9.470);
    glVertex2f(  2.902, - 9.688);
    glVertex2f(  3.489, -10.241);
    glVertex2f(  4.242, -10.458);
    glVertex2f(  5.030, -10.726);
    glVertex2f(  5.582, -10.877);
    glVertex2f(  6.202, -10.944);
    glVertex2f(  7.057, -10.877);
    glVertex2f(  7.917, -10.943);
    glVertex2f(  8.715, -11.011);
    glVertex2f(  9.318, -11.397);
    glVertex2f( 10.055, -11.732);
    glVertex2f( 10.917, -11.943);
    glVertex2f( 11.529, -12.234);
    glVertex2f( 11.981, -12.502);
    glVertex2f( 12.415, -12.478);
    glVertex2f( 12.965, -12.675);
    glVertex2f( 13.691, -12.910);
    glVertex2f( 14.183, -13.087);
    glVertex2f( 14.634, -13.323);
    glVertex2f( 15.027, -13.794);
    glVertex2f( 15.917, -14.943);
  glEnd();
}

//Função que trata a entrada de teclas comuns
void keyboard(unsigned char key, int x, int y) {
  //Exibe uma mensagem indicando que uma tecla foi pressionada
  printf("*** Tratamento de teclas comuns\n");
  printf(">>> Tecla pressionada: %c\n", key);

  switch (key) {
    //Se a tecla pressionada for a tecla 'ESC' (código 27), encerra o programa
    case 27:
      exit(0);
      break;

    //Se a tecla pressionada for a barra de espaço (código 32)
    case 32:
      //Ocorre a atualização da tela, através do redrawing (re-renderização)
      glutPostRedisplay();
      break;
  }
}

//Função que trata a entrada de teclas especiais (teclas de função e direcionais)
void Special_keyboard(GLint tecla, int x, int y) {
    //O parâmetro 'tecla' é o código da tecla especial pressionada
  switch (tecla) {
    
    /*Movimentação horizontal para a direita.
      Essa função move o helicóptero para direita, através da seta para a direita*/
    case GLUT_KEY_RIGHT:
      horizontal += 0.5;
      pontoMedioX = PX + horizontal;
      glutPostRedisplay(); // Atualiza a tela
      break;

    /*Movimentação horizontal para a esquerda
     Essa função move o helicóptero para direita, através da seta para a esquerda*/
    case GLUT_KEY_LEFT:
      horizontal -= 0.5; // Diminui a posição horizontal
      pontoMedioX = PX + horizontal;
      glutPostRedisplay(); // Atualiza a tela
      break;

    /*Movimentação vertical para cima
      Essa função move o helicóptero para cima, usando a seta para cima*/
    case GLUT_KEY_UP:
      vertical += 0.5; // Aumenta a posição vertical
      pontoMedioY = PY + vertical;
      glutPostRedisplay(); // Atualiza a tela
      break;

    /*Movimentação vertical para baixo
      Essa função move o helicóptero para baixo, usando a seta para baixo*/
    case GLUT_KEY_DOWN:
      vertical -= 0.5; // Diminui a posição vertical
      pontoMedioY = PY + vertical;
      glutPostRedisplay(); // Atualiza a tela
      break;
    
    case GLUT_KEY_PAGE_DOWN:
      escalar>0.1?escalar -= 0.1: 0.1;
      glutPostRedisplay();
      break;
    
    case GLUT_KEY_PAGE_UP:
      escalar<1.8?escalar += 0.1: 1.8;
      glutPostRedisplay();
      break;
  }
}

void DesenhaTexto(char *string) {
  	glColor3ub(0,0,0);
  	glPushMatrix();
        // Posição no universo onde o texto será colocado
        glRasterPos2f(5,-14.8);
        // Exibe caracter a caracter
        while(*string)
             glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,*string++);
	glPopMatrix();
	glColor3ub(255,255,255);
}