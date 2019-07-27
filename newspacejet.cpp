#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<glut.h>

int x[1700],y[1700],z[1700];
int flag=0;
int rand();
int zinc=7;
float tyy=0;
float gx1=-0.5,gy1=1,gz1=-8.5,gx2=2,gy2=0,gz2=-16,gx3=2,gy3=0,gz3=-20,gx4=0,gy4=2,gz4=-27,gx5=-1,gy5=1,gz5=-36,gx6=-2,gy6=2,gz6=-45,gx7=-3,gy7=0,gz7=-54,gx8=-2,gy8=-1,gz8=-63,gx9=1,gy9=-2,gz9=-72,gx10=0,gy10=0,gz10=-81;

GLfloat th=0.0;
GLdouble innerRadius=0.2;
GLdouble outerRadius=0.88;
GLint sides =900;
GLint rings =50;

GLdouble innerRadius1=0.1;
GLdouble outerRadius1=0.44;
GLint sides1 =900;
GLint rings1 =50;

GLdouble innerRadius2=0.125;
GLdouble outerRadius2=0.55;
GLint sides2 =900;
GLint rings2 =50;

GLdouble innerRadius12=0.063;
GLdouble outerRadius12=0.28;
GLint sides12 =900;
GLint rings12 =50;

float cop[3]={0,0,-2};
float at[3]={0,0,-4};


float trz=0,trX=0,trY=0;
int nflag=0,n1=0,n2=0;



void light1(GLfloat x,GLfloat y,GLfloat z)
{
	GLfloat mat_ambient[]={x,y,z,1.0};
	GLfloat mat_diffuse[]={0.5,0.5,0.5,1.0};
	GLfloat mat_specular[]={1.0,1.0,1.0,1.0};
	GLfloat mat_shininess[]={80.0f};
	glMaterialfv(GL_FRONT,GL_AMBIENT,mat_ambient);
	glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diffuse);
	glMaterialfv(GL_FRONT,GL_SPECULAR,mat_specular);
	glMaterialfv(GL_FRONT,GL_SHININESS,mat_shininess);
	GLfloat light_position[]={2.0,6.0,3.0,1.0};
	GLfloat lightIntensity[]={0.7,0.7,0.7,1.0};
	glLightfv(GL_LIGHT0,GL_POSITION,light_position);
	glLightfv(GL_LIGHT0,GL_DIFFUSE,lightIntensity);
}

void rocket1()
{
	
	//th+=1;
	//glRotatef(th,0,1,0);
	light1(1,0.2,0.3);

	glPushMatrix();
	glTranslatef(0,0,-4);
    glColor3f(0,1,0);
    glScalef(.3,.3,.3);
	glRotatef(180,0,1,0);
	glRotatef(-30,1,0,0);
	glRotatef(0,0,0,1);

	glPushMatrix();
    glutSolidTorus(innerRadius,outerRadius,sides,rings);	//BIG TORUS
	glutSolidTorus(innerRadius1,outerRadius1,sides1,rings1); //SMALL TORUS
	glutSolidSphere(0.3,900,50);	//CENTRE SPHERE
	glPopMatrix();

	glPushMatrix();
	glColor3f(1,0,0);
	glTranslatef(-1.15,0,1.57);
	glScalef(0.3,.3,2.5);
	glutSolidCube(1);	
	glPopMatrix();

	glPushMatrix();
	glColor3f(47,79,79);
	glTranslatef(1.15,0,1.57);
	glScalef(0.3,.3,2.5);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(47,79,79);
	glTranslatef(0,-.001,3);
	glutSolidCone(0.999,2,900,1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0,0,0);
	GLUquadricObj *obj=gluNewQuadric();
	gluCylinder(obj,1,1,3,900,30);
	glTranslatef(3,1,0);
	glPopMatrix();
	glPopMatrix();
	
}

void rocket2()   //rightrocket
{
	
	//glRotatef(th,0,0,1);
	
	light1(1,0.5,0.5);

	glPushMatrix();
	glTranslatef(0.6,0.04,-4.1);
    glColor3f(0,1,0);
    glScalef(.2,.2,.2);
	glRotatef(180,0,1,0);
	glRotatef(-30,1,0,0);
	glRotatef(0,0,0,1);

	glPushMatrix();
    glutSolidTorus(innerRadius,outerRadius,sides,rings);
	glutSolidTorus(innerRadius1,outerRadius1,sides1,rings1);
	glutSolidSphere(0.3,900,50);
	glPopMatrix();

	glPushMatrix();
	glColor3f(47,79,79);
	glTranslatef(0,-.001,3);
	glutSolidCone(0.999,2,900,1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0,0,0);
	GLUquadricObj *obj=gluNewQuadric();
	gluCylinder(obj,1,1,3,900,30);
	glTranslatef(3,1,0);
	glPopMatrix();
	glPopMatrix();
	
}

void rocket3()  //leftrocket
{
	
	//glRotatef(th,0,0,1);
	
	light1(0.5,0.5,0.5);
	glPushMatrix();
	glTranslatef(-0.6,0.04,-4.1);
    glColor3f(0,1,0);
    glScalef(.2,.2,.2);
	glRotatef(180,0,1,0);
	glRotatef(-30,1,0,0);
	glRotatef(0,0,0,1);

	glPushMatrix();
    glutSolidTorus(innerRadius,outerRadius,sides,rings);
	glutSolidTorus(innerRadius1,outerRadius1,sides1,rings1);
	glutSolidSphere(0.3,900,50);
	glPopMatrix();


	glPushMatrix();
	glColor3f(47,79,79);
	glTranslatef(0,-.001,3);
	glutSolidCone(0.999,2,900,1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0,0,0);
	GLUquadricObj *obj=gluNewQuadric();
	gluCylinder(obj,1,1,3,900,30);
	glTranslatef(3,1,0);
	glPopMatrix();
	glPopMatrix();
	
}

void stars()
{
	
	int i;
	for(i=0;i<1700;i++)
	{
		if(flag!=1)
		{
			
			x[i]=rand()%150;
			y[i]=rand()%150;
			z[i]=rand()%21;
			z[i]=-zinc-z[i];
			x[i]=x[i]-75;
			y[i]=y[i]-75;
		}
		glEnable(GL_COLOR_MATERIAL);
		glPushMatrix();
		glColor3f(1,1,1);
		glTranslatef(x[i],y[i],z[i]);
		glutSolidSphere(0.1,15,15);
		glPopMatrix();
		glDisable(GL_COLOR_MATERIAL);
	}
	if(i==1700)
		flag=1;
}

void gems()
{
	tyy+=2.5;
	glPushMatrix();			 //1st gem
	glTranslatef(gx1,gy1,gz1);
	glutSolidTorus(0.3,2.5,sides,rings);

	glPushMatrix();
	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT,GL_AMBIENT);
	glColor3f(1,0,0);
	glDisable(GL_COLOR_MATERIAL);
	glRotatef(tyy,0,0,1);
    glutSolidIcosahedron();
	glPopMatrix();

	glPopMatrix();

	glPushMatrix();			//2nd gem
	glTranslatef(gx2,gy2,gz2);
   glutSolidTorus(0.3,2.5,sides,rings);

	glPushMatrix();
	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT,GL_AMBIENT);
	glColor3f(1,1,0);
	glDisable(GL_COLOR_MATERIAL);
	glRotatef(tyy,0,0,1);
    glutSolidIcosahedron();
	glPopMatrix();

	glPopMatrix();


	glPushMatrix();				//3rd gem
	glTranslatef(gx3,gy3,gz3);
    glutSolidTorus(0.3,2.5,sides,rings);

	glPushMatrix();
	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT,GL_AMBIENT);
	glColor3f(1,0,1);
	glDisable(GL_COLOR_MATERIAL);
	glRotatef(tyy,0,0,1);
    glutSolidIcosahedron();
	glPopMatrix();

	glPopMatrix();

	glPushMatrix();				//4th gem
	glTranslatef(gx4,gy4,gz4);
	glutSolidTorus(0.3,2.5,sides,rings);

	glPushMatrix();
	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT,GL_AMBIENT);
	glColor3f(0.4,0.4,0.4);
	glDisable(GL_COLOR_MATERIAL);
	glRotatef(tyy,0,0,1);
    glutSolidIcosahedron();
	glPopMatrix();

	glPopMatrix();


	glPushMatrix();				//5th gem
	glTranslatef(gx5,gy5,gz5);
	glutSolidTorus(0.3,2.5,sides,rings);

	glPushMatrix();
	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT,GL_AMBIENT);
	glColor3f(0.4,0.4,0.4);
	glDisable(GL_COLOR_MATERIAL);
	glRotatef(tyy,0,0,1);
    glutSolidIcosahedron();
	glPopMatrix();

	glPopMatrix();

	glPushMatrix();				//6th gem
	glTranslatef(gx6,gy6,gz6);
	glutSolidTorus(0.3,2.5,sides,rings);

	glPushMatrix();
	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT,GL_AMBIENT);
	glColor3f(0.6,0.4,0.4);
	glDisable(GL_COLOR_MATERIAL);
	glRotatef(tyy,0,0,1);
    glutSolidIcosahedron();
	glPopMatrix();

	glPopMatrix();

	glPushMatrix();				//7th gem
	glTranslatef(gx7,gy7,gz7);
	glutSolidTorus(0.3,2.5,sides,rings);

	glPushMatrix();
	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT,GL_AMBIENT);
	glColor3f(0.4,1,0.4);
	glDisable(GL_COLOR_MATERIAL);
	glRotatef(tyy,0,0,1);
    glutSolidIcosahedron();
	glPopMatrix();

	glPopMatrix();

	glPushMatrix();				//8th gem
	glTranslatef(gx8,gy8,gz8);
	glutSolidTorus(0.3,2.5,sides,rings);

	glPushMatrix();
	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT,GL_AMBIENT);
	glColor3f(0.4,0.4,1);
	glDisable(GL_COLOR_MATERIAL);
	glRotatef(tyy,0,0,1);
    glutSolidIcosahedron();
	glPopMatrix();

	glPopMatrix();

	glPushMatrix();				//9th gem
	glTranslatef(gx9,gy9,gz9);
	glutSolidTorus(0.3,2.5,sides,rings);

	glPushMatrix();
	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT,GL_AMBIENT);
	glColor3f(1,0.4,0.4);
	glDisable(GL_COLOR_MATERIAL);
	glRotatef(tyy,0,0,1);
    glutSolidIcosahedron();
	glPopMatrix();

	glPopMatrix();


	glPushMatrix();				//10th gem
	glTranslatef(gx10,gy10,gz10);
	glutSolidTorus(0.3,2.5,sides,rings);

	glPushMatrix();
	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT,GL_AMBIENT);
	glColor3f(1,0.8,0.4);
	glDisable(GL_COLOR_MATERIAL);
	glRotatef(tyy,0,0,1);
    glutSolidIcosahedron();
	glPopMatrix();

	glPopMatrix();
}

void myReshape(int x, int y)
{
	//glClearColor(0.01,0,0.18,1);
    if (y == 0 || x == 0) return;   
    glMatrixMode(GL_PROJECTION);  
    glLoadIdentity(); 
    gluPerspective(130,(GLdouble)x/(GLdouble)y,1,21.0);
	
    glMatrixMode(GL_MODELVIEW);
    glViewport(0,0,x,y); 
}

char str[100];
int count=0;
//int num,rem;
char num[20];


void bitmap_output(int x,int y,int z,char *string,void *font)
{
	int len,i;
	glRasterPos3f(x,y,z);
	len=(int)strlen(string);
	for(i=0;i<len;i++)
	{
		glutBitmapCharacter(font,string[i]);
	}
	return;
}

int flag1=0,flag2=0,flag3=0,flag4=0,flag5=0,flag6=0,flag7=0,flag8=0,flag9=0,flag10=0;
int score;


int dflag=0; 
char str0[100];
char str1[100];
char str2[100];
char str3[100];
char str4[100];
char str5[100];
char str6[100];
char str7[100];
char str8[100];
char str9[100],str11[100],str10[100],str12[100],str13[100],str14[100],str15[100],str16[100],str17[100];

float tz=0.0,tx=0.0,ty=0.0;
int start=1;


	void endscreen(void)
	{

		glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
		glLoadIdentity();
		gluLookAt(cop[0],cop[1],cop[2],at[0],at[1],at[2],0,1,0);
		
		sprintf_s(str14,"GAME OVER");
		bitmap_output(-10,2,-9+trz,str14,GLUT_BITMAP_TIMES_ROMAN_24);

		
		if(score>70)
		{
		
			sprintf_s(str,"CONGRATULATIONS YOU WON THE GAME ");
			bitmap_output(-10,1,-9+trz,str,GLUT_BITMAP_TIMES_ROMAN_24);
		}
		if(score<70)
		{
			sprintf_s(str16,"SORRY YOU LOST THE GAME ");
			bitmap_output(-10,-1,-9+trz,str16,GLUT_BITMAP_TIMES_ROMAN_24);

		}


		sprintf_s(str15,"YOUR TOTAL SCORE IS %d",score);
		bitmap_output(-10,0,-9+trz,str15,GLUT_BITMAP_TIMES_ROMAN_24);

		sprintf_s(str15,"PRESS 'Q' TO QUIT");
		bitmap_output(-10,-2,-9+trz,str15,GLUT_BITMAP_TIMES_ROMAN_24);

	}

	void display0(void)
{
	start=0;
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	printf("trx=%f\ttry=%f\ttrz=%f\n",trX,trY,trz);
	printf("copx=%f\tcopy=%f\tcopz=%f\n",cop[0],cop[1],cop[2]);
	printf("atx=%f\taty=%f\tatz=%f\n",at[0],at[1],at[2]);
	printf("%d\t\t",flag1);
	gluLookAt(cop[0],cop[1],cop[2],at[0],at[1],at[2],0,1,0);

	int zz=7,zz1=9,zz2=-9+trz,zz3=7,zz4=8,zz5=-9+trz;

	sprintf_s(str,"GEMS COLLECTED :%d",count);
	bitmap_output(zz,zz1,zz2,str,GLUT_BITMAP_TIMES_ROMAN_24);
	
	sprintf_s(str,"TOTAL SCORE :%d",score);
	bitmap_output(zz3,zz4,zz5,str,GLUT_BITMAP_TIMES_ROMAN_24);


	

	glPushMatrix();
	stars();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(trX,trY,trz);
	glPushMatrix();
	rocket1();
	rocket2();
	rocket3();
	glPopMatrix();
	glPopMatrix();
	

	
	if((trY<=0.4&&trY>=0)&&(cop[2]<-6.0&&cop[2]>-6.8)&&(!flag1))		//1ST GEM COUNT
	{
		printf("Hello1");
		gx1=10;
		gy1=10;
		gz1=10;
		flag1=1;
		count++;
		score+=10;
	}
	else if((trY>=-1.5&&trY<=0.8)&&(cop[2]<=-12.39&&cop[2]>=-13.8)&&(!flag2))		//2ND GEM COUNT
	{
		printf("Hello2");
		gx2=10;
		gy2=10;
		gz2=10;
		flag2=1;
		count++;
		score+=10;
	}
	else if((trY<=0.6&&trY>=-0.6)&&(cop[2]<=-15.5&&cop[2]>=-18.5)&&(!flag3))		//3RD GEM COUNT
	{
		printf("Hello3");
		gx3=20;
		gy3=20;
		gz3=20;
		flag3=1;
		count++;
		score+=10;
	}
	else if((trY<=2&&trY>=0)&&(cop[2]<=-23.5&&cop[2]>=-26.5)&&(!flag4))		//4TH GEM COUNT
	{
		printf("Hello");
		gx4=20;
		gy4=20;
		gz4=20;
		flag4=1;
		count++;
		score+=10;
	}
	
	else if((trY<=1.5&&trY>=-0.2)&&(cop[2]<=-29.5&&cop[2]>=-32)&&(!flag5))		//5TH GEM COUNT
	{
		printf("Hello");
		gx5=-30;
		gy5=-30;
		gz5=-30;
		flag5=1;
		count++;
		score+=10;
	}

	else if((trY<=2&&trY>=1)&&(cop[2]<=-40&&cop[2]>=-43)&&(!flag7))		//6TH GEM COUNT
	{
		printf("Hello");
		gx6=20;
		gy6=20;
		gz6=20;
		flag7=1;
		count++;
		score+=10;
	}

	else if((trY<=-0.2&&trY>=-0.6)&&(cop[2]<=-49&&cop[2]>=-52)&&(!flag8))		//7TH GEM COUNT
	{
		printf("Hello");
		gx7=20;
		gy7=20;
		gz7=20;
		flag8=1;
		count++;
		score+=10;
	}
	
	else if((trY<=-1&&trY>=-1.6)&&(cop[2]<=-58&&cop[2]>=-61)&&(!flag8))		//8TH GEM COUNT
	{
		printf("Hello");
		gx8=20;
		gy8=20;
		gz8=20;
		flag8=1;
		count++;
		score+=10;
	}

	else if((trY<=-1.5&&trY>=-2)&&(cop[2]<=-67&&cop[2]>=-70)&&(!flag9))		//9TH GEM COUNT
	{
		printf("Hello");
		gx9=20;
		gy9=20;
		gz9=20;
		flag9=1;
		count++;
		score+=10;
	}

	else if((trY<=1&&trY>=-0.9)&&(cop[2]<=-77&&cop[2]>=-80)&&(!flag10))		//10TH GEM COUNT
	{
		printf("Hello");
		gx10=20;
		gy10=20;
		gz10=20;
		flag10=1;
		count++;
		score+=10;
	}
	
	
	gems();
	glPopMatrix();


		int temp=int(cop[2]);
		cop[2]-=0.4;
		at[2]-=0.4;
		trz-=0.4;
		if(temp%12==0&&n1==0)
		{
			nflag=1;
			n1=1;
		}
		if(nflag==1)
		{
			zinc+=15;
			flag=0;
			nflag=0;
		}
		if(temp%13==0)
			n1=0;

	

	if(trz<=-80)
	{
		endscreen();

	}
}

	void startscreen(void)
	{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(cop[0],cop[1],cop[2],at[0],at[1],at[2],0,1,0);

	
	sprintf_s(str2,"WELCOME TO 3D SPACE JET GAME ");
	bitmap_output(-9,1,-9+trz,str2,GLUT_BITMAP_TIMES_ROMAN_24);

	sprintf_s(str1,"THIS IS A PROJECT ON COMPUTER GRAPHICS ");
	bitmap_output(-9,0,-9+trz,str1,GLUT_BITMAP_TIMES_ROMAN_24);
	
	sprintf_s(str2,"MADE BY ARAVIND KUMAR AND SWAROOP K.M. ");
	bitmap_output(-9,-1,-9+trz,str2,GLUT_BITMAP_TIMES_ROMAN_24);

	sprintf_s(str17,"UNDER THE GUIDANCE OF ASST. PROF ROHAN DON SALINS ");
	bitmap_output(-9,-2,-9+trz,str17,GLUT_BITMAP_TIMES_ROMAN_24);

	sprintf_s(str3,"USN:4SH15CS071 & 4SH15CS070 ");
	bitmap_output(-9,-3,-9+trz,str3,GLUT_BITMAP_TIMES_ROMAN_24);

	sprintf_s(str5,"PRESS 'I' TO DISPLAY THE INSTRUCTIONS");
	bitmap_output(-9,-4,-9+trz,str5,GLUT_BITMAP_TIMES_ROMAN_24);

	sprintf_s(str6,"PRESS 'Q' TO QUIT ");
	bitmap_output(-9,-5,-9+trz,str6,GLUT_BITMAP_TIMES_ROMAN_24);
	}

	void instructionscreen(void)
	{
		glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
		glLoadIdentity();
		gluLookAt(cop[0],cop[1],cop[2],at[0],at[1],at[2],0,1,0);
		
		sprintf_s(str13,"INSTRUCTIONS: ");
		bitmap_output(-18,3,-9+trz,str13,GLUT_BITMAP_TIMES_ROMAN_24);

		sprintf_s(str7,"PRESS LEFT AND RIGHT ARROW KEY TO MOVE THE ROCKET LEFT AND RIGHT ");
		bitmap_output(-18,1,-9+trz,str7,GLUT_BITMAP_TIMES_ROMAN_24);

		sprintf_s(str8,"TRY COLLECTING GEM BY MOVING THE ROCKET TO THE PERFECT MIDDLE OF THE GEM ");
		bitmap_output(-18,0,-9+trz,str8,GLUT_BITMAP_TIMES_ROMAN_24);

		sprintf_s(str9,"FOR EACH GEM YOU WILL GET 10 POINTS ");
		bitmap_output(-18,-1,-9+trz,str9,GLUT_BITMAP_TIMES_ROMAN_24);


		sprintf_s(str10,"TRY TO SCORE MORE THAN 70 POINTS OR ELSE YOU WILL LOOSE THE GAME ");
		bitmap_output(-18,-2,-9+trz,str10,GLUT_BITMAP_TIMES_ROMAN_24);

		sprintf_s(str4,"PRESS 'B' TO BEGIN THE GAME ");
		bitmap_output(-18,-3,-9+trz,str4,GLUT_BITMAP_TIMES_ROMAN_24);

		sprintf_s(str12,"PRESS 'Q' TO QUIT ");
		bitmap_output(-18,-4,-9+trz,str12,GLUT_BITMAP_TIMES_ROMAN_24);


	}

	

void display(void)
{

	int o,p,m,r,s,t,h;
	if(start==1)
	{
		startscreen();
	}
	if(dflag==1) 
	{
		exit(1);
	}

	if(dflag==2)
	{
		instructionscreen();
	}


	if(dflag==3)
		{
			display0();		
		}
	
	//panel();
	//panel1();
	glutSwapBuffers();
	glutPostRedisplay();
}

void keys(unsigned char key,int x,int y)
{
	if(key=='q'||key=='Q')
		dflag=1;
	if((key=='I'||key=='i')&&dflag<2)
		dflag=2;
	if((key=='b'||key=='B')&&dflag<3)
		dflag=3;
	if((key=='s'||key=='S')&&dflag<4)
		dflag=4;
	if((key=='r'||key=='R')&&dflag<5)
		dflag=5;
	if((key=='aa'||key=='aa')&&dflag<6)
		dflag=6;
	if((key=='c'||key=='C')&&dflag<7)
		dflag=7;
	
	
	
	display();
}

void skeys(int key,int x,int y)
{
	switch(key)
	{
	
	
	case GLUT_KEY_UP:
		trY+=0.1;
		break;
	case GLUT_KEY_DOWN:
		trY-=0.1;
		break;
	case GLUT_KEY_RIGHT:
		trX+=0.1;
		break;
	case GLUT_KEY_LEFT:
		trX-=0.1;
		break;

	}
	display();
}

int main (int argc, char **argv)
{
    glutInit(&argc, argv); 
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
	glutInitWindowSize(900,900);
    glutCreateWindow("3D-SPACE JET GAME");
	glutReshapeFunc(myReshape);
	glutSpecialFunc(skeys);
	glutKeyboardFunc(keys);
    glutDisplayFunc(display);
	//glutIdleFunc(draw);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_NORMALIZE);
	glEnable(GL_DEPTH_TEST);

    glutMainLoop();
    return 0;
}


