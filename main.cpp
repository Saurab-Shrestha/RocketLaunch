//Header files
#include<Windows.h>
#include<GL/glut.h>
#include<math.h>
#include<iostream>
#include<dos.h>
#include<stdlib.h>
#include<time.h>
using namespace std;
int counter = 0, launch = 0;
int star_flag = 0, p = 0, flag = 0;

// fucntion to display the text content of the home screen
void drawstring(int x, int y, char *s)
{
	char *c;
	glRasterPos2i(x, y);
	for (c = s; *c != '\0'; *c++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,*c);
}
//design of home screen
void page()
{
	glColor3f(1, 1, 1);
	drawstring(130,400,"Welcome to National Space Agency");
	drawstring(200,360,"!!!NEPAL!!!");

    glColor3f(0,1,0);
    drawstring(50,280,"Press 'S' to LAUNCH the Rocket");
    drawstring(50,260,"Press 'D' to move Right");
    drawstring(50,240,"Press 'A' to move Left");
    drawstring(50,220,"Press 'W' to move Up");
    drawstring(50,200,"Press 'Q' to Quit");

    glColor3f(1,1,0);
    drawstring(400,100,"Prepared By: ");
    drawstring(400,80,"Saurab Shrestha");

}

//Sun
void sun(int x1, int y1, int r)
{
	GLfloat theta = 0;
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1, 1, 1);
	while (theta <= 360.0)
	{
		float xc = r*sin(theta) + x1;
		float yc = r*cos(theta) + y1;
		glVertex2f(xc, yc);
		glutPostRedisplay();
		glFlush();
		theta += 0.1;
	}
	glEnd();
	glutPostRedisplay();
	glFlush();

}
//twinkling of stars after reaching the space
void stars()
{
	glColor3f(1.0, 1.0, 1.0);
	glPointSize(1.5);

	glBegin(GL_POINTS);
	glVertex2i(13, 24);
	glVertex2i(26, 120);
	glVertex2i(3, 14);
	glVertex2i(15, 350);
	glVertex2i(17, 90);
	glVertex2i(260, 300);
	glVertex2i(554, 35);
	glColor3f(0, 1.0, 1.0);
	glVertex2i(450, 320);
	glVertex2i(330, 180);
	glVertex2i(425, 69);
	glVertex2i(63, 125);
	glVertex2i(20, 10);
	glVertex2i(110, 330);
	glVertex2i(540, 130);
	glVertex2i(320, 64);
	glColor3f(1.0, 0, 1.0);
	glVertex2i(112, 410);
	glVertex2i(410, 290);
	glVertex2i(290, 390);
	glVertex2i(120, 98);
	glVertex2i(500, 422);
	glVertex2i(320, 326);
	glVertex2i(355, 200);
	glColor3f(1.0, 0.5, 0);
	glVertex2i(209, 203);
	glVertex2i(115, 140);
	glVertex2i(450, 250);
	glVertex2i(239, 305);
	glVertex2i(235, 205);
	glVertex2i(125, 390);
	glVertex2i(135, 345);
	glVertex2i(395, 490);
	glVertex2i(180, 350);
	glVertex2i(313, 100);
	glColor3f(0, 0.5, 0.5);
	glVertex2i(220, 220);
	glVertex2i(202, 110);
	glVertex2i(270, 301);
	glVertex2i(233, 40);
	glVertex2i(210, 418);
	glVertex2i(256, 12);
	glVertex2i(298, 432);
	glVertex2i(237, 396);
	glVertex2i(259, 542);
	glVertex2i(257, 547);
	glColor3f(0, 0.5, 1.0);
	glVertex2i(290, 563);
	glVertex2i(232, 572);
	glVertex2i(243, 543);
	glVertex2i(150, 500);
	glVertex2i(10, 250);
	glVertex2i(70, 225);
	glVertex2i(80, 333);
	glVertex2i(60, 550);
	glVertex2i(243, 543);
	glVertex2i(443, 143);
	glColor3f(0, 0, 1.0);
	glVertex2i(583, 143);
	glVertex2i(543, 123);
	glVertex2i(583, 183);
	glVertex2i(593, 113);
	glVertex2i(583, 573);
	glVertex2i(540, 543);
	glVertex2i(550, 523);
	glEnd();
}

//design of the rocket body
void rocket(int x, int y)
{
	glColor3f(0.75, 0.75, .75);

	glBegin(GL_QUADS);//body of rocket
	glVertex2f(x - 25, y - 75);
	glVertex2f(x - 25, y + 75);
	glVertex2f(x + 25, y + 75);
	glVertex2f(x + 25, y - 75);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glColor3f(1,1,1);
	GLfloat radius=10;
	for(int i=0;i<360;i++)
    {
      float  x1=x+sin(i)*radius;
      float  y1=y+50+cos(i)*radius;
        glVertex2f(x1,y1);
    }
    glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0,0,0);
	for(int i=0;i<360;i+=2)
    {
      float  x1=x+sin(i)*radius;
      float  y1=y+50+cos(i)*radius;
        glVertex2f(x1,y1);
    }
    glEnd();
    	glBegin(GL_LINE_LOOP);
	glColor3f(1,1,1);
	for(int i=0;i<360;i++)
    {
      float  x1=x+sin(i)*radius;
      float  y1=y+20+cos(i)*radius;
        glVertex2f(x1,y1);
    }
    glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0,0,0);
	for(int i=0;i<360;i+=2)
    {
      float  x1=x+sin(i)*radius;
      float  y1=y+20+cos(i)*radius;
        glVertex2f(x1,y1);
    }
    glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(1,0,0);
	glVertex2f(x - 25, y + 75);//Upper Triangle
	glVertex2f(x, y + 150);
	glVertex2f(x + 25, y + 75);

    glColor3f(0,1,1);
	glVertex2f(x - 25, y + 75);//left wing
	glVertex2f(x - 75, y + 25);
	glVertex2f(x - 25, y + 40);

	glVertex2f(x + 25, y + 75);//Right wing
	glVertex2f(x + 75, y + 25);
	glVertex2f(x + 25, y + 40);

	glVertex2f(x - 25, y);//left tail wing
	glVertex2f(x - 75, y - 75);
	glVertex2f(x - 25, y - 75);

	glVertex2f(x + 25, y);//Right tail wing
	glVertex2f(x + 75, y - 75);
	glVertex2f(x + 25, y - 75);

	glEnd();
//Outlines of the rocket
	glColor3f(0, 0, 0);
	glLineWidth(2);
	glBegin(GL_LINE_LOOP);//body
	glVertex2f(x - 25, y - 75);
	glVertex2f(x - 25, y + 75);
	glVertex2f(x + 25, y + 75);
	glVertex2f(x + 25, y - 75);
	glEnd();
    glColor3f(0, 0, 0);
	glLineWidth(2);
	glBegin(GL_LINE_STRIP);//upper triangle
	glVertex2f(x - 25, y + 75);
	glVertex2f(x, y + 150);
	glVertex2f(x + 25, y + 75);
	glEnd();
    glColor3f(0, 0, 0);
	glLineWidth(2);
	glBegin(GL_LINE_STRIP);//Left wing
	glVertex2f(x - 25, y + 75);
	glVertex2f(x - 75, y + 25);
	glVertex2f(x - 25, y + 40);
	glEnd();
    glColor3f(0, 0, 0);
	glLineWidth(2);
	glBegin(GL_LINE_STRIP);//Right wing
	glVertex2f(x + 25, y + 75);
	glVertex2f(x + 75, y + 25);
	glVertex2f(x + 25, y + 40);
	glEnd();
	glColor3f(0,0, 0);
	glLineWidth(2);
	glBegin(GL_LINE_STRIP);//left Tail wing
	glVertex2f(x - 25, y);
	glVertex2f(x - 75, y - 75);
	glVertex2f(x - 25, y - 75);
	glEnd();
	glColor3f(0, 0, 0);
	glLineWidth(2);
	glBegin(GL_LINE_STRIP);//Right tail wing
	glVertex2f(x + 25, y);
	glVertex2f(x + 75, y - 75);
	glVertex2f(x + 25, y - 75);
	glEnd();
}

//design of the rocket flames
void exhaust(int x, int y)
{
	//to change the color of the flame alternately
	if ((p % 2) == 0)
		glColor3f(1.0, 0.816, 0.0);
	else
		glColor3f(1.0, 0.25, 0.0);
	glBegin(GL_POLYGON);//outer flame
	glVertex2i(x - 25, y - 75);
	glVertex2i(x - 50, y - 125);
	glVertex2i(x, y - 250);
	glVertex2i(x + 50, y - 125);
	glVertex2i(x + 25, y - 75);

	glEnd();

	//alternately switch between flame colors
	if ((p % 2) == 0)
		glColor3f(1.0, 0.25, 0.0);
	else
		glColor3f(1.0, 0.816, 0.0);
	glBegin(GL_POLYGON);//inner flame
	glVertex2i(x - 25, y - 75);
	glVertex2i(x - 25, y - 125);
	glVertex2i(x, y - 200);
	glVertex2i(x + 25, y - 125);
	glVertex2i(x + 25, y - 75);
	glEnd();
	//delay
	for (int j = 1; j <= 50000000; j++)
		;

	glutSwapBuffers();
	glutPostRedisplay();
	glFlush();

}
//design of the stand object on screen
void stand()
{
	glColor3f(0, 0, 1);
	glBegin(GL_POLYGON);
	glVertex2i(50, 0);
	glVertex2i(50, 350);
	glVertex2i(100, 350);
	glVertex2i(100, 150);
	glVertex2i(150, 100);
	glVertex2i(275, 100);
	glVertex2i(235, 50);
	glVertex2i(150, 50);
	glVertex2i(150, 0);
	glEnd();

	glColor3f(1, 1, 1);
	glLineWidth(5);
	glBegin(GL_LINE_STRIP);
	glVertex2i(50, 0);
	glVertex2i(50, 350);
	glVertex2i(100, 350);
	glVertex2i(100, 150);
	glVertex2i(150, 100);
	glVertex2i(275, 100);
	glVertex2i(235, 50);
	glVertex2i(150, 50);
	glVertex2i(150, 0);
	glEnd();

	glColor3f(0, 0, 0);
	glBegin(GL_QUADS);
	glVertex2i(250, 0);
	glVertex2i(250, 25);
	glVertex2i(275, 25);
	glVertex2i(275, 0);

	glVertex2i(325, 0);
	glVertex2i(325, 25);
	glVertex2i(350, 25);
	glVertex2i(350, 0);
	glEnd();
}

//determines when the rocket is to be launched
void rocket_static()
{
	counter++;
	if (counter == 500)
		launch = 1;

	if (launch == 0)
	{
		glClearColor(0.2, 0.6, 0.8, 1.0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		sun(500, 600, 25);
		rocket(300, 100);
		stand();
		glutSwapBuffers();
		glutPostRedisplay();
		glFlush();
	}
}
//function to launch the rocket
void rocket_launch1()
{
      PlaySound("C:\\Users\\Rajan Srestha\\Desktop\\New folder\\finalProject\\sound.wav", NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
	int i, x1 = 300, y1 = 100;

	for (i = 1; i <= 90; i++)
	{
		//glClearColor(0.2, 0.6, 0.8, 1.0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		y1 = y1 + i/4;
		sun(500, 600-y1/4, 30);
		//stand
		rocket(x1, y1);
		p++;
		exhaust(x1, y1);


	}
}
void rocket_launch2()
{
      PlaySound("C:\\Users\\Rajan Srestha\\Desktop\\New folder\\finalProject\\sound.wav", NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
	int i, x1 = 300, y1 = 100;
	for (i = 1; i <= 90; i++)
	{
		glClearColor(0, 0, 0.5, 1.0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		y1 = y1 + i/4;
		sun(500, 350-y1/4, 30);
		rocket(x1, y1);
		p++;
		exhaust(x1, y1);

	}
}
//displays the rocket in outer space
void rocket_in_space()
{
	int x1 = 300, y1 =300, i;

	for (i = 1; i <=10; i++)
	{
		glClearColor(0.0, 0.0, 0.0, 1.0);

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		if (star_flag == 0)
		{
			star_flag = 1;
		}
		else
		{
			stars();
			star_flag = 0;
		}
		//y1=y1+1;
		rocket(x1, y1);
		p++;
		exhaust(x1, y1);
	}
}

// left navigation in space on mouse left click
void navigate_left()
{
	int x1 = 300, y1 = 300, i;
	for (i = 1; i <= 10; i++)
	{
		glClearColor(0.0, 0.0, 0.0, 1.0);

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		if (star_flag == 0)
		{
			star_flag = 1;
		}
		else
		{
			stars();
			star_flag = 0;
		}
		if(x1>=50)
        {
            rocket(x1-10,y1+15);
            p++;
            exhaust(x1-10,y1+15);
            x1-=20;
        }
	}

}//right navigation in space on mouse right click
void navigate_up()
{
	int x1 = 300, y1 = 300;
	int i;
	for (i = 1; i <= 30; i++)
	{
		glClearColor(0.0, 0.0, 0.0, 1.0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		if (star_flag == 0)
		{
			star_flag = 1;
		}
		else
		{
			stars();
			star_flag = 0;
		}
			if(x1>=300)
        {
            rocket(x1,y1+10);
            p++;
            exhaust(x1,y1+10);
            y1+=10;

        }
	}
}

//right navigation in space on mouse right click
void navigate_right()
{
	int x1 = 300, y1 = 300;
	int i;
	for (i = 1; i <= 30; i++)
	{
		glClearColor(0.0, 0.0, 0.0, 1.0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		if (star_flag == 0)
		{
			star_flag = 1;
		}
		else
		{
			stars();
			star_flag = 0;
		}
			if(x1>=300&&x1<=600)
        {
            rocket(x1+10,y1+15);
            p++;
            exhaust(x1+10,y1+15);
            x1+=20;

        }
	}
}
//keys that trigger manual Launch
void keyboard(unsigned char key, int x, int y)
{
	if (key == 'S' || key == 's')
		flag = 1;

	if (key == 'Q' || key == 'q')
		exit(0);

    if(key=='D'||key=='d')
        navigate_right();
    if(key=='A'||key=='a')
        navigate_left();
    if(key=='w'||key=='W')
        navigate_up();

}

//determines the state of rocket launch
void control()
{
	counter++;

	if (launch == 0)
		rocket_static();
	else if (launch == 1 && (counter == 500 || counter == 501))
		rocket_launch1();
    else if(launch==1&&(counter==5000))
        rocket_launch2();

	else if (launch == 1 && counter >= 10000)
		rocket_in_space();
}
//display all components
void display()
{
	if (flag == 0)
	{
		glClear(GL_COLOR_BUFFER_BIT);
		page();
		glutSwapBuffers();
	}
	else
		control();
	glFlush();
}

//initial settings
void myInit()
{
	glClearColor(0.2, 0.6, 0.8, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 680, 0, 700);
	glMatrixMode(GL_MODELVIEW);
	glEnd();
}

//main()
int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(680, 700);
	glutCreateWindow("ROCKET");
	myInit();
	glutKeyboardFunc(keyboard);
	glutDisplayFunc(display);

	glutIdleFunc(display);
	glutMainLoop();
}
