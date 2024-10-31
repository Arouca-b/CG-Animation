#include <GL/glut.h> //O arquivo glut.h inclui, além dos protótipos das funções GLUT, os arquivos gl.h e glu.h,
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int R = 158, G=0, B = 0;
float horizontal = 0, vertical = 0;

void display(void);
void keyboard(unsigned char key, int x, int y);
void Special_keyboard(GLint tecla, int x, int y);
void DesenhaTexto(char *string);
void Coqueiros();
void Mar();
void Helicoptero();
void Areia();
void Sol();
void Barco();
void nuvens();
void nuvemModel1(float posx, float posy);
void nuvemModel2(float posx, float posy);
void nuvemModel3(float posx, float posy);

void Circulo(float raio, float x, float y, float angulo);

int main(int argc, char** argv){
  glutInit(&argc, argv); //Estabelece contato com sistema de janelas
  glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB); //Cores dos pixels serão expressos em RGB
  glutInitWindowSize (900, 700); //Posição inicial do canto superior esquerdo da janela a ser criada
  glutInitWindowPosition (400, 100); //Estabelece o tamanho (em pixels) da janela a ser criada
  glutCreateWindow (argv[1]); //Cria uma nova janela com valor de retorno (não usado)
  // que a identifica, caso tenha mais de uma
  glClearColor(0.0, 0.5, 1.0, 0.0); //selecionar cor de fundo (Branco)
  glOrtho (-15, 15,-15, 15, -1 ,1); //define as coordenadas do volume de recorte (clipping volume),
  glutDisplayFunc(display); //Função callback chamada para fazer o desenho
  glutKeyboardFunc(keyboard); //Chamada sempre que uma tecla for precionada
  glutSpecialFunc(Special_keyboard); // Registra a função para tratamento das teclas NÂO ASCII
  glutMainLoop(); //Depois de registradas as callbacks, o controle é entregue ao sistema de janelas
  printf("\nTestando... \n");
  return 0;
}

void display(void) {
  glClear(GL_COLOR_BUFFER_BIT); // Limpa a janela de visualização com a cor de fundo especificada
  DesenhaTexto("Exemplo de texto para a atividade 2");

  // Primeiro polígono (retângulo)
  glBegin(GL_POLYGON);
      glColor3ub(200, 250, 255);
      glVertex2f(-15, 0.0);

      glColor3ub(100, 150, 200);
      glVertex2f(-15, 15);

      glColor3ub(150, 200, 250);
      glVertex2f(15, 15);

      glColor3ub(200, 250, 255);
      glVertex2f(15, 0);
    glEnd();
  Sol();
  nuvens();
  Mar();
  Areia();
  Barco();
  Helicoptero();
  Coqueiros();
  glFlush(); // Executa os comandos OpenGL para renderização
}

void Circulo(float raio, float x0, float y0, float angulo){
  float radiano = 360/30 * (2 * 3.14159265 / 360);
  float passo = radiano;
  float x = 0, y = 0;
  glBegin(GL_POLYGON);
    for(int i = 0; i < 30; i++){
      x = x0 + cos(passo) * raio;
      y = y0 + sin(passo) * raio;
      passo += radiano;
      glVertex2f(x, y);
    }
  glEnd();
}

void Barco(){
  glBegin(GL_POLYGON);
    glColor3ub(0,0,0);
    glVertex2d(-7.3126757626461, -0.677273224714);
    glColor3ub(0,0,0);
    glVertex2d(-7.3804796926738, 0.4075896265978);
    glColor3ub(68, 68, 68);
    glVertex2d(-6.3283587461905, 0.4441503383566);
    glColor3ub(200, 200, 200);
    glVertex2d(-6.2736663958969, -0.6350804992629);
  glEnd();
  
  glBegin(GL_POLYGON);
    glColor3ub(232, 247, 253);
    glVertex2d(-9.5, -3);
    glVertex2d(-9.6435277702278, -0.708763285476);
    glVertex2d(-5.9921937970212, -0.5394961521903);
    glVertex2d(-5.8954697182607, -2.7641499039454);
  glEnd();

  glBegin(GL_POLYGON);
    glColor3ub(233, 54, 62);
    glVertex2d(-8.0178227854477, -2.7724000620721);
    glVertex2d(-8.1207077367812, -1.5789346586498);
    glVertex2d(-7.1535891942464, -1.4966266997931);
    glVertex2d(-7.0428739102778, -2.708754561961);
  glEnd();

  glBegin(GL_POLYGON);
    glColor3ub(179, 232, 255);
    Circulo(0.35, -8.798030689, -1.955340455, 360);
  glEnd();

  glBegin(GL_POLYGON);
    glColor3ub(179, 232, 255);
    Circulo(0.35, -6.485446047, -1.699570732, 360);
  glEnd();

  glBegin(GL_POLYGON);
    glColor3ub(0,0,0);
    glVertex2d(-10.0062430655795, -2.7883309229862);
    glVertex2d(-9.909518986819, -3.4653994561291);
    glVertex2d(-9.5940331877012, -4.1288394834971);
    glVertex2d(-9.1357263567355, -4.7228124462516);
    glVertex2d(-8.7246490220036, -4.9646226366597);
    glVertex2d(-7.9992184313003, -5.3998809793944);
    glVertex2d(-7.4430549784278, -5.6900532078842);
    glVertex2d(-6.5967192892739, -5.8109583030883);
    glVertex2d(-5.6052974819794, -5.714234226925);
    glVertex2d(-4.7105997534453, -5.448243017476);
    glColor3ub(100,100,100);
    glVertex2d(-3.8642640642914, -5.1822518080271);
    glVertex2d(-3.0179283751376, -4.795355503374);
    glVertex2d(-2.4859459419552, -4.0941059511903);
    glVertex2d(-2.0748686072233, -3.1752272276393);
    glVertex2d(-1.7121533118716, -2.425615637374);
  glEnd();
}

//Função que desenha os coqueiros
void Coqueiros(){
  //Caule
  glBegin(GL_POLYGON);
    glColor3ub(115,97,84);
    glVertex2f(10.9665732022438, -6.2274131185577);
    glVertex2f(11, -6);
    glVertex2f(11.1906141806768, -5.8316076618495);
    glVertex2f(11.4290747214689, -5.7776165974595);
    glVertex2f(11.659408946775, -5.9194861292565);
    glVertex2f(12.211111484087, -7.0485517566942);
    glVertex2f(12.5318687732218, -8.9602651486058);
    glVertex2f(12.492569547532, -11.2829302020297);
    glVertex2f(12.2737013265228, -12.707806949524);
    glVertex2f(12.3273017071781, -12.8328745010282);
    glVertex2f(12.2328678333205, -13.16064704494);
    glVertex2f(11.6604714985243, -12.6616348690297);
    glVertex2f(11.3449196729315, -13.2487080171595);
    glVertex2f(11.1541208946661, -13.0138787579076);
    glVertex2f(10.6982705293742, -13.3069253738039);
    glVertex2f(10.9106500577393, -12.5807244253455);
    glVertex2f(11.1846881588554, -10.6282030073206);
    glVertex2f(11.2873304913786, -8.6523381593046);
    glVertex2f(11.2103487419862, -7.4334604933207);
  glEnd();

  //coco
  glBegin(GL_POLYGON);
  glColor3ub(64, 171, 81);
    Circulo(0.5, 11, -6.8, 360);
    Circulo(0.5, 12, -6.8, 360);
    Circulo(0.5, 11.5, -7.2, 360);
  glEnd();

  //folhagem
  glBegin(GL_POLYGON);
    glColor3ub(50, 130, 20);
    glVertex2f(10.9665732022438, -6.2274131185577);
    glVertex2f(10.2737374577125, -6.5353401078589);
    glVertex2f(9.606562296312, -7.292327289891);
    glVertex2f(9.0291991758693, -8.2289385490155);
    glVertex2f(8.6571207204729, -9.0757377695937);
    glVertex2f(8.5416480963843, -8.3829020436661);
    glVertex2f(8.6571207204729, -7.1640243776822);
    glVertex2f(9.3756170481349, -5.8296740907103);
    glVertex2f(9.7990166697929, -5.3036321506541);
    glVertex2f(9.0933506336963, -5.316462441875);
    glVertex2f(8.1952302241187, -5.6372197223971);
    glVertex2f(7.5665459374144, -6.0991102063489);
    glVertex2f(7.0918251494948, -6.5866612727424);
    glVertex2f(7.2714492314103, -5.650050013618);
    glVertex2f(8.0540970168994, -4.7904205018188);
    glVertex2f(8.9778780096077, -4.4183420564132);
    glVertex2f(9.8759984191853, -4.2900391442044);
    glVertex2f(8.6057995542113, -3.7896577865899);
    glVertex2f(7.7205094361991, -3.5458822533931);
    glVertex2f(7.0276736916679, -3.5458822533931);
    glVertex2f(7.6598474760086, -3.2531207537324);
    glVertex2f(8.4383426317865, -3.0711348780475);
    glVertex2f(9, -3);
    glVertex2f(9.5, -3);
    glVertex2f(10.0408294134852, -3.141907163036);
    glVertex2f(10.5867870551995, -3.4249963029903);
    glVertex2f(10.8092142425647, -3.5665408729674);
    glVertex2f(11.5674887449457, -2.742549269172);
    glVertex2f(12.3105977572792, -2.3482465385214);
    glVertex2f(13.2030926078487, -2.2637308479208);
    glVertex2f(13, -2.5);
    glVertex2f(12.4363384208083, -2.9785993940866);
    glVertex2f(12.0846692072033, -3.5378110793937);
    glVertex2f(11.9463075493915, -3.8433597321903);
    glVertex2f(12.0731390690524, -3.8664200078731);
    glVertex2f(12.5458747332427, -3.5781665618385);
    glVertex2f(13.301098782132, -3.3014432536453);
    glVertex2f(13.9064310350586, -3.2264973576763);
    glVertex2f(14.4368173900038, -3.3014432536453);
    glVertex2f(14.6904804293255, -3.3936843563764);
    glVertex2f(14.2984557321921, -3.6012268375213);
    glVertex2f(13.1339117789428, -4.1546734539076);
    glVertex2f(12.442056732264, -4.66211758961);
    glVertex2f(13.0128453283575, -4.6677645878492);
    glVertex2f(14.0330128863729, -5.3036321506541);
    glVertex2f(14.8284909634273, -6.1632616624533);
    glVertex2f(15.110757377866, -7.1896849601239);
    glVertex2f(15.046605920039, -7.6772360265175);
    glVertex2f(14.6616971730772, -7.2153455425657);
    glVertex2f(13.9560311369805, -6.5866612727424);
    glVertex2f(13, -6);
    glVertex2f(12.2752629419139, -5.868164964373);
    glVertex2f(11.659408946775, -5.9194861292565);
    glVertex2f(11.4290747214689, -5.8776165974595);
    glVertex2f(11.1906141806768, -5.96076618495);
    glVertex2f(10.98, -6.1);
  glEnd();

  //arbusto
  glBegin(GL_POLYGON);
    glColor3ub(1, 119, 2);  
    glVertex2f(7.7880107870749, -16.6907331606655);
    glVertex2f(7.9471408916428, -16.2670792799724);
    glVertex2f(8.7783976908206, -15.6197891668457);
    glVertex2f(9, -15.5);
    glVertex2f(8.7238890482516, -15.3813138620095);
    glVertex2f(8.7170754679304, -15.1973471982788);
    glVertex2f(9.2485347329786, -14.7749052297119);
    glVertex2f(9.5551458474294, -14.6658879475011);
    glVertex2f(9.9367063454127, -14.584124985843);
    glVertex2f(9.9419860169328, -14.5037317711983);
    glVertex2f(9.5290475713272, -14.3525466612929);
    glVertex2f(9.7050541219132, -14.2081310339207);
    glVertex2f(10.0435282576555, -14.0388939705938);
    glVertex2f(10.5399569900775, -13.7997055877584);
    glVertex2f(10.3684634279681, -13.5560042165677);
    glVertex2f(10.1913000423093, -13.4370934683389);
    glVertex2f(10.5201457636487, -13.293223469116);
    glVertex2f(10.6982705293742, -13.3069253738039);
    glVertex2f(11.1541208946661, -13.0138787579076);
    glVertex2f(11.3449196729315, -13.2487080171595);
    glVertex2f(11.6604714985243, -12.6616348690297);
    glVertex2f(12.2328678333205, -13.16064704494);
    glVertex2f(12.3273017071781, -12.8328745010282);
    glVertex2f(12.4702360555923, -12.8016076131521);
    glVertex2f(12.9392393863264, -12.5336057170717);
    glVertex2f(13.0687736395768, -12.5291390188037);
    glVertex2f(12.9169058943867, -12.9222084663883);
    glVertex2f(13.0167536798191, -12.9333060906972);
    glVertex2f(13.2883854641314, -12.7508668374758);
    glVertex2f(13.5093396767436, -12.6981621643229);
    glVertex2f(13.5924508943317, -12.7042434727636);
    glVertex2f(13.6106948201437, -12.7488397346622);
    glVertex2f(13.5194751910836, -13.3326453449708);
    glVertex2f(13.6466346196049, -13.4359675499978);
    glVertex2f(14.4561094893798, -13.1862359479431);
    glVertex2f(14.6455610546463, -13.2379045552648);
    glVertex2f(14.5938924459372, -13.5737505028556);
    glVertex2f(14.766121141634, -13.875150712232);
    glVertex2f(15.0158527503944, -13.7373677593742);
    glVertex2f(15.463647359206, -13.60819624107);
    glVertex2f(16.1870078811326, -13.7976478012495);
    glVertex2f(15.7133789679664, -14.2454423980372);
    glVertex2f(15.8167161853845, -14.3746139163414);
    glVertex2f(16.1870078811326, -14.4607282618775);
    glVertex2f(16.9017569682743, -14.6760141257178);
    glVertex2f(17.3409401423011, -14.9688029005405);
  glEnd();
}

void nuvemModel1(float posx, float posy){
  glBegin(GL_POLYGON);
    glColor3ub(255, 255, 255);
    Circulo(1.2, -6.6 + posx, 12.5 - posy, 360);
    Circulo(1.2, -5.7 + posx, 13.5 - posy, 360);
    Circulo(1.2, -4.9 + posx, 12.5 - posy, 360);
    Circulo(1.2, -4.0 + posx, 13.5 - posy, 360);
    Circulo(1.2, -3.2 + posx, 12.5 - posy, 360);
  glEnd();
}

void nuvemModel2(float posx, float posy){
  glBegin(GL_POLYGON);
    glColor3ub(255, 255, 255);
    Circulo(.7, -10 + posx, 3.5 + posy, 360);
    Circulo(.7, -11.5 + posx, 4 + posy, 360);
    Circulo(.7, -12 + posx, 3.5 + posy, 360);
    Circulo(.7, -10.5 + posx, 4 + posy, 360);
    Circulo(.7, -11 + posx, 3.5 + posy, 360);
  glEnd();
}

void nuvemModel3(float posx, float posy){
  glBegin(GL_POLYGON);
    glColor3ub(255, 255, 255);
    Circulo(.3, 12.3 + posx, 2.3 + posy, 360);
    Circulo(.2, 12.45 + posx, 2.6 + posy, 360);
    Circulo(.3, 12.6 + posx, 2.3 + posy, 360);
    Circulo(.2, 12.75 + posx, 2.6 + posy, 360);
    Circulo(.3, 13 + posx, 2.3 + posy, 360);
  glEnd();
}


void nuvens(){
  nuvemModel1(0, 0);
  nuvemModel2(0, 0);
  nuvemModel3(0, 0);
  nuvemModel1(5, 3);
  nuvemModel2(5, 1);
  nuvemModel3(-5, -1);
  nuvemModel3(-10, 3);
}

void movimento_nuvens(){
  
}

void Areia(){
  glBegin(GL_POLYGON);
    glColor3ub (206, 193, 174);
    glVertex2f(-17.1398512151135, -15.0429933771048);
    glVertex2f(-15.0031819671612, -13.7295215413454);
    glVertex2f(-14.3903388495315, -13.2491850566414);
    glVertex2f(-13.5456091468527, -13.0669884589951);
    glVertex2f(-12.9327660292229, -12.7854118989962);
    glVertex2f(-12.2702329290827, -12.5700886472324);
    glVertex2f(-11.789896431481, -12.2719487601747);
    glVertex2f(-11, -12);
    glVertex2f(-10.2495069736549, -11.7916122754708);
    glVertex2f(-9.6366638560252, -11.3775290990018);
    glVertex2f(-8.9625586214218, -11.3031104773561);
    glVertex2f(-8.2425586214218, -11.0431104773561);
    glVertex2f(-7.807965825296, -10.4344137501686);
    glVertex2f(-7.0436315484242, -10.1796356578779);
    glVertex2f(-6.2792972715523, -10.1541578486489);
    glVertex2f(-5.4828965254878, -10.0644196142994);
    glVertex2f(-4.7758229890539, -10.0505207293656);
    glVertex2f(-4.0712460896765, -10.1450853534886);
    glVertex2f(-3.44608661096, -10.104752483894);
    glVertex2f(-2.9971921024031, -9.9023014888114);
    glVertex2f(-2.3831409629641, -9.4999921215927);
    glVertex2f(-1.5785222285268, -9.2459019949283);
    glVertex2f(-0.8586002029777, -9.1400311088181);
    glVertex2f(-0.0825586214218, -8.9431104773561);
    glVertex2f(0.7296137245264, -8.9847933323074);
    glVertex2f(1.4732461676395, -9.166570151735);
    glVertex2f(1.9982684892748, -9.4706591863395);
    glVertex2f(2.902818127685, -9.6884211363271);
    glVertex2f(3.4891003007286, -10.2412014709111);
    glVertex2f(4.2428916660704, -10.4589634208988);
    glVertex2f(5.0301848698719, -10.7269781285759);
    glVertex2f(5.5829652044559, -10.8777364016442);
    glVertex2f(6.2027492159592, -10.9447400785635);
    glVertex2f(7.0570460966799, -10.8777364016442);
    glVertex2f(7.9174413785782, -10.9431104773561);
    glVertex2f(8.7153871004319, -11.0117437554828);
    glVertex2f(9.3184201927054, -11.3970148977686);
    glVertex2f(10.0554606388174, -11.732033282365);
    glVertex2f(10.9174413785782, -11.9431104773561);
    glVertex2f(11.5295415310414, -12.2345608592595);
    glVertex2f(11.9818163502465, -12.5025755669366);
    glVertex2f(12.4152291626948, -12.4788541512764);
    glVertex2f(12.9652145042092, -12.6752774822573);
    glVertex2f(13.6919808483531, -12.9109854794343);
    glVertex2f(14.1830391889909, -13.0877664773171);
    glVertex2f(14.6348128623776, -13.3234744744941);
    glVertex2f(15.0276595348879, -13.7948904688482);
    glVertex2f(15.9174413785782, -14.9431104773561);
  glEnd();
}

void Mar(){
  glBegin(GL_POLYGON);
    glColor3ub(25, 124, 251);
    glVertex2f(-15.0, -15);
    glVertex2f(-15.0, 0);
    glVertex2f(15, 0);
    glVertex2f(15, -15);
  glEnd();
}

void Sol(){
  glBegin(GL_POLYGON);
    glColor3ub (200, 200, 0);
    Circulo(6, 0, 1, 180);
  glEnd();
}

void Helicoptero(){
  glBegin(GL_POLYGON);
    glColor3ub (R, G, B);
    glVertex2f(-5.832928370436 + horizontal, 9.0401452436051 + vertical);
    glVertex2f(-5.8115850100531 + horizontal, 9.8085062173898 + vertical);
    glVertex2f(-5.9752174396554 + horizontal, 10.5128371100258 + vertical);
    glVertex2f(-6.2384522177112 + horizontal, 11.0250777592156 + vertical);
    glVertex2f(-6.7222350530572 + horizontal, 11.4234871530299 + vertical);
    glVertex2f(-7.2700479695518 + horizontal, 11.6653785707029 + vertical);
    glVertex2f(-8.0825586214218 + horizontal, 11.6568895226439 + vertical);
    glVertex2f(-8.9774372996019 + horizontal, 11.631106943557 + vertical);
    glVertex2f(-9.5552676330925 + horizontal, 11.414420568498 + vertical);
    glVertex2f(-10.2871346366497 + horizontal, 11.0714714695067 + vertical);
    glVertex2f(-10.7542655750856 + horizontal, 10.489892034913 + vertical);
    glVertex2f(-11.1443010501918 + horizontal, 9.7242668430379 + vertical);
    glVertex2f(-11.7525806223829 + horizontal, 9.4088783293972 + vertical);
    glVertex2f(-12.3866362671966 + horizontal, 9.2764483345827 + vertical);
    glVertex2f(-12.9066835673382 + horizontal, 9.2331110595709 + vertical);
    glVertex2f(-13.54414128698 + horizontal, 9.1366356960698 + vertical);
    glVertex2f(-13.8806024664937 + horizontal, 9.3201599758046 + vertical);
    glVertex2f(-14.0641267462284 + horizontal, 9.840145435053 + vertical);
    glVertex2f(-14.4617626856536 + horizontal, 9.8605370216902 + vertical);
    glVertex2f(-14.603735130515 + horizontal, 9.4042130776963 + vertical);
    glVertex2f(-14.3512594010648 + horizontal, 8.9730874095001 + vertical);
    glVertex2f(-13.9870779171056 + horizontal, 8.559164303765 + vertical);
    glVertex2f(-13.3704207036963 + horizontal, 8.559164303765 + vertical);
    glVertex2f(-12.6624068660782 + horizontal, 8.559164303765 + vertical);
    glVertex2f(-11.9543930284601 + horizontal, 8.6276817719216 + vertical);
    glVertex2f(-11.3377358150508 + horizontal, 8.6276817719216 + vertical);
    glVertex2f(-10.8124352258503 + horizontal, 8.7190383961303 + vertical);
    glVertex2f(-10.3556521048063 + horizontal, 8.6276817719216 + vertical);
    glVertex2f(-9.9453031081987 + horizontal, 8.424148592684 + vertical);
    glVertex2f(-9.6419421831161 + horizontal, 8.0918961509269 + vertical);
    glVertex2f(-9.2230151913354 + horizontal, 7.8607640175306 + vertical);
    glVertex2f(-8.7174136495311 + horizontal, 7.6874149174834 + vertical);
    glVertex2f(-8.1829205910523 + horizontal, 7.6874149174834 + vertical);
    glVertex2f(-7.6484275325735 + horizontal, 7.7451979508325 + vertical);
    glVertex2f(-7.0417056824083 + horizontal, 7.8174267425188 + vertical);
    glVertex2f(-6.4927668655922 + horizontal, 8.0052216009033 + vertical);
    glVertex2f(-6.0593941154742 + horizontal, 8.424148592684 + vertical);
    glVertex2f(-5.832928370436 + horizontal, 9.0401452436051 + vertical);
  glEnd();

  glBegin(GL_POLYGON);
    glColor3ub (0, 0, 0);
    glVertex2f(-8.0825586214218 + horizontal, 11.6568895226439 + vertical);
    glVertex2f(-8.0825853112324 + horizontal, 9.6138166626064 + vertical);
    glVertex2f(-8.0705656727889 + horizontal, 9.5906359313225 + vertical);
    glVertex2f(-8.0580155178343 + horizontal, 9.5742658955127 + vertical);
    glVertex2f(-8.0433024306799 + horizontal, 9.5655470290508 + vertical);
    glVertex2f(-8.0258646977561 + horizontal, 9.560642666666 + vertical);
    glVertex2f(-7.9825586214218 + horizontal, 9.5568895226439 + vertical);
    glVertex2f(-5.8197366354602 + horizontal, 9.56 + vertical);
    glVertex2f(-5.8115850100531 + horizontal, 9.8085062173898 + vertical);
    glVertex2f(-5.9752174396554 + horizontal, 10.5128371100258 + vertical);
    glVertex2f(-6.2384522177112 + horizontal, 11.0250777592156 + vertical);
    glVertex2f(-6.7222350530572 + horizontal, 11.4234871530299 + vertical);
    glVertex2f(-7.2700479695518 + horizontal, 11.6653785707029 + vertical);
  glEnd();

  glBegin(GL_POLYGON);
    glVertex2f(-8.3343377055376 + horizontal, 11.6568895226439 + vertical);
    glVertex2f(-8.3343377055376 + horizontal, 11.7490475001811 + vertical);
    glVertex2f(-8.2976917986704 + horizontal, 11.769705104695 + vertical);
    glVertex2f(-8.1820173228921 + horizontal, 11.7701061969863 + vertical);
    glVertex2f(-7.9825586214218 + horizontal, 11.7693515615288 + vertical);
    glVertex2f(-7.8830829565941 + horizontal, 11.7709245424658 + vertical);
    glVertex2f(-7.8538164500946 + horizontal, 11.7428774737371 + vertical);
    glVertex2f(-7.8538164500946 + horizontal, 11.6568895226439 + vertical);
  glEnd();

  glBegin(GL_POLYGON);
    glVertex2f(-8.1820173228921 + horizontal, 11.7701061969863 + vertical);
    glVertex2f(-8.1825586214218 + horizontal, 12.0568895226439 + vertical);
    glVertex2f(-8.1428465541292 + horizontal, 12.094923061773 + vertical);
    glVertex2f(-8.0826225013754 + horizontal, 12.1126633497135 + vertical);
    glVertex2f(-8.0257621940304 + horizontal, 12.0960071762184 + vertical);
    glVertex2f(-7.9825586214218 + horizontal, 12.0568895226439 + vertical);
    glVertex2f(-7.9825586214218 + horizontal, 11.7693515615288 + vertical);
  glEnd();

  glBegin(GL_POLYGON);
    glVertex2f(-8.1825586214218 + horizontal, 12.0568895226439 + vertical);
    glVertex2f(-8.2404168542116 + horizontal, 12.064567857303 + vertical);
    glVertex2f(-8.2642673720095 + horizontal, 12.0819136884287 + vertical);
    glVertex2f(-8.2534262275559 + horizontal, 12.1133530073442 + vertical);
    glVertex2f(-8.2230710230859 + horizontal, 12.1372035251421 + vertical);
    glVertex2f(-8.1825586214218 + horizontal, 12.1568895226439 + vertical);
    glVertex2f(-8.121164265222 + horizontal, 12.1664746151668 + vertical);
    glVertex2f(-8.0572015129458 + horizontal, 12.1664746151668 + vertical);
    glVertex2f(-7.9825586214218 + horizontal, 12.1568895226439 + vertical);
    glVertex2f(-7.9448957602006 + horizontal, 12.1377810320856 + vertical);
    glVertex2f(-7.913014291713 + horizontal, 12.1155212362349 + vertical);
    glVertex2f(-7.9249395506119 + horizontal, 12.0656519717483 + vertical);
    glVertex2f(-7.9249395506119 + horizontal, 12.0656519717483 + vertical);
    glVertex2f(-8.1825586214218 + horizontal, 12.0568895226439 + vertical);
    glVertex2f(-8.1428465541292 + horizontal, 12.094923061773 + vertical);
    glVertex2f(-8.0826225013754 + horizontal, 12.1126633497135 + vertical);
    glVertex2f(-8.0257621940304 + horizontal, 12.0960071762184 + vertical);
    glVertex2f(-7.9825586214218 + horizontal, 12.0568895226439 + vertical);
  glEnd();

  glBegin(GL_POLYGON);
    glVertex2f(-8.2230710230859 + horizontal, 12.1372035251421 + vertical);
    glVertex2f(-13.4828279997543 + horizontal, 12.6704440390004 + vertical);
    glVertex2f(-13.5473639725382 + horizontal, 12.6546055453838 + vertical);
    glVertex2f(-13.5962316485838 + horizontal, 12.6306508022242 + vertical);
    glVertex2f(-13.6795941547793 + horizontal, 12.5731594186411 + vertical);
    glVertex2f(-13.7227126924666 + horizontal, 12.5329154501329 + vertical);
    glVertex2f(-13.7380437280887 + horizontal, 12.4955460508039 + vertical);
    glVertex2f(-13.7639148507011 + horizontal, 12.4198490624195 + vertical);
    glVertex2f(-13.7744549376913 + horizontal, 12.3575667302045 + vertical);
    glVertex2f(-13.785953214408 + horizontal, 12.2809115520938 + vertical);
    glVertex2f(-13.7849950246816 + horizontal, 12.1927580972664 + vertical);
    glVertex2f(-13.7673373268627 + horizontal, 12.1176788772957 + vertical);
    glVertex2f(-13.7400859963752 + horizontal, 12.0642243444164 + vertical);
    glVertex2f(-13.7002571287396 + horizontal, 12.0160104520154 + vertical);
    glVertex2f(-13.6468025958603 + horizontal, 11.991903505815 + vertical);
    glVertex2f(-13.5545673234412 + horizontal, 11.9667484315188 + vertical);
    glVertex2f(-13.4825586214218 + horizontal, 11.9568895226439 + vertical);
    glVertex2f(-8.2642673720095 + horizontal, 12.0819136884287 + vertical);
    glVertex2f(-8.2534262275559 + horizontal, 12.1133530073442 + vertical);
  glEnd();

  glBegin(GL_POLYGON);
    glVertex2f(-7.9448957602006 + horizontal, 12.1377810320856 + vertical);
    glVertex2f(-7.913014291713 + horizontal, 12.1155212362349 + vertical);
    glVertex2f(-7.9066087725749 + horizontal, 12.0874407335408 + vertical);
    glVertex2f(-2.9158811413846 + horizontal, 11.9554344993213 + vertical);
    glVertex2f(-2.8617574934807 + horizontal, 11.9582954896744 + vertical);
    glVertex2f(-2.7955246707007 + horizontal, 11.9718575526314 + vertical);
    glVertex2f(-2.707701066638 + horizontal, 12.0113781744595 + vertical);
    glVertex2f(-2.667082649759 + horizontal, 12.0454098210338 + vertical);
    glVertex2f(-2.6171459956125 + horizontal, 12.0827099584177 + vertical);
    glVertex2f(-2.5847480209503 + horizontal, 12.1134731141824 + vertical);
    glVertex2f(-2.566085505087 + horizontal, 12.1442113756043 + vertical);
    glVertex2f(-2.5517756815271 + horizontal, 12.2007982677334 + vertical);
    glVertex2f(-2.5485207842745 + horizontal, 12.241915135124 + vertical);
    glVertex2f(-2.5463251941729 + horizontal, 12.2836313470538 + vertical);
    glVertex2f(-2.5441296040713 + horizontal, 12.3209563787804 + vertical);
    glVertex2f(-2.550716374376 + horizontal, 12.3769439263703 + vertical);
    glVertex2f(-2.5573031446807 + horizontal, 12.4406160393158 + vertical);
    glVertex2f(-2.5770634555948 + horizontal, 12.4987991770073 + vertical);
    glVertex2f(-2.5990193566105 + horizontal, 12.5449065691402 + vertical);
    glVertex2f(-2.6352465932863 + horizontal, 12.5833293959176 + vertical);
    glVertex2f(-2.6703760349114 + horizontal, 12.6096764771364 + vertical);
    glVertex2f(-2.707701066638 + horizontal, 12.6305345831013 + vertical);
    glVertex2f(-2.7668651020663 + horizontal, 12.652064306904 + vertical);
    glVertex2f(-2.8153656576781 + horizontal, 12.6668253455685 + vertical);
    glVertex2f(-2.8988666482607 + horizontal, 12.6700432105244 + vertical);
  glEnd();


  glBegin(GL_POLYGON);
    glVertex2f(-14.2334135422169 + horizontal, 9.0538196868763 + vertical);
    glVertex2f(-14.2464067668349 + horizontal, 9.1409466093606 + vertical);
    glVertex2f(-14.2380444127215 + horizontal, 9.2151330305986 + vertical);
    glVertex2f(-14.1681203582804 + horizontal, 9.262379013329 + vertical);
    glVertex2f(-14.0679588748919 + horizontal, 9.2756078884935 + vertical);
    glVertex2f(-14.0018144990693 + horizontal, 9.2585993347106 + vertical);
    glVertex2f(-13.9413396411743 + horizontal, 9.2132431912894 + vertical);
    glVertex2f(-13.9186615694637 + horizontal, 9.1452089761575 + vertical);
    glVertex2f(-13.9410707291296 + horizontal, 9.0679840970036 + vertical);
    glVertex2f(-13.9961449811416 + horizontal, 9.0166999031307 + vertical);
    glVertex2f(-14.0688697357434 + horizontal, 8.9836911351945 + vertical);
      glVertex2f(-14.147724441952 + horizontal, 8.9945676463957 + vertical);
  glEnd();

  glBegin(GL_POLYGON);
    glVertex2f(-14.2334135422169 + horizontal, 9.0538196868763 + vertical);
    glVertex2f(-14.7994830142892 + horizontal, 8.7576099067649 + vertical);
    glVertex2f(-14.8821037539245 + horizontal, 8.7031553283689 + vertical);
    glVertex2f(-14.9234141237422 + horizontal, 8.6299233091466 + vertical);
    glVertex2f(-14.9365583323205 + horizontal, 8.5698354985027 + vertical);
    glVertex2f(-14.9145184816347 + horizontal, 8.4996863867422 + vertical);
    glVertex2f(-14.8426711281895 + horizontal, 8.4646818298759 + vertical);
    glVertex2f(-14.7825586214218 + horizontal, 8.4568895226439 + vertical);
    glVertex2f(-14.6755519048361 + horizontal, 8.5003589674457 + vertical);
    glVertex2f(-14.147724441952 + horizontal, 8.9945676463957 + vertical);
  glEnd();

  glBegin(GL_POLYGON);
    glVertex2f(-14.0018144990693 + horizontal, 9.2585993347106 + vertical);
    glVertex2f(-13.5378361443628 + horizontal, 9.864320804921 + vertical);
    glVertex2f(-13.4625174968933 + horizontal, 9.8827951896533 + vertical);
    glVertex2f(-13.3786722100877 + horizontal, 9.8785318700997 + vertical);
    glVertex2f(-13.3104590953984 + horizontal, 9.8444253136709 + vertical);
    glVertex2f(-13.2834580708339 + horizontal, 9.789002159474 + vertical);
    glVertex2f(-13.2820369642779 + horizontal, 9.7122624075091 + vertical);
    glVertex2f(-13.3175646281786 + horizontal, 9.6241538034012 + vertical);
    glVertex2f(-13.9413396411743 + horizontal, 9.2132431912894 + vertical);
  glEnd();

  glBegin(GL_POLYGON);
    glVertex2f(-8.8097542085118 + horizontal, 8.1345310281585 + vertical);
    glVertex2f(-8.7992016306278 + horizontal, 8.1845169233986 + vertical);
    glVertex2f(-8.7653223016317 + horizontal, 8.2245056395907 + vertical);
    glVertex2f(-8.7103378168676 + horizontal, 8.2306150267867 + vertical);
    glVertex2f(-8.6448007542195 + horizontal, 8.2222840442467 + vertical);
    glVertex2f(-8.6164754135835 + horizontal, 8.1856277210706 + vertical);
    glVertex2f(-8.6114768240595 + horizontal, 8.1350864269945 + vertical);
    glVertex2f(-8.9852536375611 + horizontal, 7.3482210026817 + vertical);
    glVertex2f(-9.1911115245695 + horizontal, 7.3493710467123 + vertical);
  glEnd();

  glBegin(GL_POLYGON);
    glVertex2f(-7.7150977518009 + horizontal, 7.3551740056352 + vertical);
    glVertex2f(-7.9177763208266 + horizontal, 7.356487412193 + vertical);
    glVertex2f(-7.6881381397865 + horizontal, 8.0681298168318 + vertical);
    glVertex2f(-7.6805095592154 + horizontal, 8.1416120647248 + vertical);
    glVertex2f(-7.6302577346427 + horizontal, 8.2086144974884 + vertical);
    glVertex2f(-7.5599618512546 + horizontal, 8.2291106630463 + vertical);
    glVertex2f(-7.4897199747538 + horizontal, 8.1972115782107 + vertical);
    glVertex2f(-7.4683351887975 + horizontal, 8.138820296693 + vertical);
    glVertex2f(-7.4825586214218 + horizontal, 8.0568895226439 + vertical);
  glEnd();

  glBegin(GL_POLYGON);
    glVertex2f(-9.78232731488 + horizontal, 7.347532302294 + vertical);
    glVertex2f(-7.0751069304312 + horizontal, 7.3505639040683 + vertical);
    glVertex2f(-7.0156859367552 + horizontal, 7.3326960078534 + vertical);
    glVertex2f(-6.9748486410263 + horizontal, 7.2952618201019 + vertical);
    glVertex2f(-6.9510268851844 + horizontal, 7.2442152004407 + vertical);
    glVertex2f(-6.9747527643585 + horizontal, 7.1985973576251 + vertical);
    glVertex2f(-7.0167593851118 + horizontal, 7.1683135147564 + vertical);
    glVertex2f(-7.0729310291423 + horizontal, 7.1458448571442 + vertical);
    glVertex2f(-9.7905904161719 + horizontal, 7.1440363466046 + vertical);
    glVertex2f(-9.8298293037926 + horizontal, 7.1648753371292 + vertical);
    glVertex2f(-9.8749796705452 + horizontal, 7.1918770270499 + vertical);
    glVertex2f(-9.8972718815256 + horizontal, 7.2461679659728 + vertical);
    glVertex2f(-9.8972718815256 + horizontal, 7.2461679659728 + vertical);
    glVertex2f(-9.8825586214218 + horizontal, 7.2968895226439 + vertical);
    glVertex2f(-9.8320425570648 + horizontal, 7.3290987299252 + vertical);
  glEnd();
}

void keyboard(unsigned char key, int x, int y){
  printf("*** Tratamento de teclas comuns\n");
	printf(">>> Tecla pressionada: %c\n",key);
  switch (key) {
    case 27: exit(0);
    case 32:
            glutPostRedisplay();
    break;
  }
}

void Special_keyboard(GLint tecla, int x, int y) {
  switch (tecla) { // GLUT_KEY_RIGHT GLUT_KEY_DOWN GLUT_KEY_PAGE_UP GLUT_KEY_PAGE_DOWN GLUT_KEY_F1...
    case GLUT_KEY_F12: R = 137; G = 0; B = 206;
        glutPostRedisplay();
        break;

    case GLUT_KEY_F11: R = 158; G = 0; B = 0;
      glutPostRedisplay();
      break;
    
    case GLUT_KEY_F10: R = 109; G = 67; B = 0;
      glutPostRedisplay();
      break;

    case GLUT_KEY_RIGHT:
      horizontal+=0.8;
      glutPostRedisplay();
      break;
    
    case GLUT_KEY_LEFT:
      horizontal-=0.8;
      glutPostRedisplay();
      break;

    case GLUT_KEY_UP:
      vertical+=0.8;
      glutPostRedisplay();
      break;
    
    case GLUT_KEY_DOWN:
      vertical-=0.8;
      glutPostRedisplay();
      break;
  }
}

void DesenhaTexto(char *string) {
  	glColor3ub(150,200,250);
  	glPushMatrix();
        // Posição no universo onde o texto será colocado
        glRasterPos2f(-0.4,-0.4);
        // Exibe caracter a caracter
        while(*string)
             glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,*string++);
	glPopMatrix();
	glColor3ub(255,255,255);
}
