#include <iostream>
#include<windows.h>
#include<stdio.h>
#include<GL/glut.h>
#include<math.h>

using namespace std;

int currentSlide = 0;
int lightstate = 0;
int offset = 0;
int direction = -1;

void myInit()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 100, 0, 100, -10.0, 10.0);
}

void display_night()
{
    //Background
    glBegin(GL_QUADS);
    glColor3ub(31, 25, 27);
    glVertex2f(0, 0);
    glVertex2f(100, 0);
    glVertex2f(100, 100);
    glVertex2f(0, 100);
    glEnd();

    //Night_Back
    glBegin(GL_POLYGON);
    glColor3ub(88, 96, 103);
    glVertex2f(4, 30);
    glVertex2f(50, 5);
    glVertex2f(96, 30);
    glVertex2f(96, 66);
    glVertex2f(4, 65);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(88, 96, 103);
    glVertex2f(4, 65);
    glVertex2f(96, 66);
    glVertex2f(50, 85);
    glEnd();

    //NightWallsLeft
    glBegin(GL_POLYGON);
    glColor3ub(56, 61, 65);
    glVertex2f(5, 30);
    glVertex2f(50, 6);
    glVertex2f(95, 30);
    glVertex2f(95, 65);
    glVertex2f(5, 65);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(56, 61, 65);
    glVertex2f(5, 65);
    glVertex2f(95, 65);
    glVertex2f(50, 84);
    glEnd();

    //LeftMainwall
    glBegin(GL_QUADS); //Left
    glColor3ub(52, 38, 38);
    glVertex2f(5, 30);
    glVertex2f(50, 50);
    glVertex2f(50, 67);
    glVertex2f(5, 48);
    glEnd();

    //Night_Right Wall
    glBegin(GL_QUADS);
    glColor3ub(100, 109, 117);
    glVertex2f(50, 6);
    glVertex2f(95, 30);
    glVertex2f(95, 65);
    glVertex2f(50, 84);
    glEnd();

    //Night_IndoorWalls
    glBegin(GL_QUADS); //right
    glColor3ub(70, 86, 102);
    glVertex2f(24, 48);
    glVertex2f(37, 44);
    glColor3ub(35, 43, 51);
    glVertex2f(37, 59);
    glVertex2f(24, 53);
    glEnd();

    //InnerWall
    glBegin(GL_QUADS); //right
    glColor3ub(52, 38, 38);
    glVertex2f(50, 50);
    glVertex2f(95, 30);
    glVertex2f(95, 49);
    glVertex2f(50, 67);
    glEnd();

    //Night_Whites(FromTheLeft)
    glBegin(GL_QUADS); //1
    glColor3ub(47, 58, 68);
    glVertex2f(39, 46);
    glVertex2f(44, 48);
    glColor3ub(41, 51, 60);
    glVertex2f(44, 63);
    glVertex2f(39, 61);
    glEnd();
    glBegin(GL_QUADS); //2
    glColor3ub(47, 58, 68);
    glVertex2f(45, 48.5);
    glVertex2f(49, 50.3);
    glColor3ub(41, 51, 60);
    glVertex2f(49, 65);
    glVertex2f(45, 63.4);
    glEnd();
    glBegin(GL_QUADS); //3
    glColor3ub(47, 58, 68);
    glVertex2f(51, 50.5);
    glVertex2f(55.9, 48.5);
    glColor3ub(41, 51, 60);
    glVertex2f(56, 63);
    glVertex2f(51, 65);
    glEnd();
    glBegin(GL_QUADS); //4
    glColor3ub(47, 58, 68);
    glVertex2f(57, 48);
    glVertex2f(62, 46);
    glColor3ub(41, 51, 60);
    glVertex2f(62, 60.7);
    glVertex2f(57, 62.7);
    glEnd();
    glBegin(GL_QUADS); //5
    glColor3ub(47, 58, 68);
    glVertex2f(63, 45.4);
    glVertex2f(68, 43.4);
    glColor3ub(41, 51, 60);
    glVertex2f(68, 58.6);
    glVertex2f(63, 60.6);
    glEnd();
    glBegin(GL_QUADS); //6
    glColor3ub(47, 58, 68);
    glVertex2f(69, 43);
    glVertex2f(74, 40.8);
    glColor3ub(41, 51, 60);
    glVertex2f(74, 56);
    glVertex2f(69, 58);
    glEnd();
    glBegin(GL_QUADS); //7
    glColor3ub(47, 58, 68);
    glVertex2f(75, 40);
    glVertex2f(81, 37.6);
    glColor3ub(41, 51, 60);
    glVertex2f(81, 53);
    glVertex2f(75, 55.6);
    glEnd();
    glBegin(GL_QUADS); //8
    glColor3ub(47, 58, 68);
    glVertex2f(82, 37);
    glVertex2f(88, 34.6);
    glColor3ub(41, 51, 60);
    glVertex2f(88, 50.6);
    glVertex2f(82, 52.6);
    glEnd();
    glBegin(GL_QUADS); //9
    glColor3ub(47, 58, 68);
    glVertex2f(89, 34);
    glVertex2f(94, 31.6);
    glColor3ub(41, 51, 60);
    glVertex2f(94, 48);
    glVertex2f(89, 50);
    glEnd();

    //Night_portrait
    glBegin(GL_POLYGON); //right
    glColor3ub(55, 48, 38);
    glVertex2f(60, 53.8);
    glVertex2f(64.1, 51.4);
    glVertex2f(71, 52.4);
    glVertex2f(71, 47.9);
    glVertex2f(60, 52);
    glEnd();
    glBegin(GL_QUADS); //right
    glColor3ub(55, 48, 38);
    glVertex2f(59, 52);
    glVertex2f(72, 47);
    glColor3ub(55, 48, 38);
    glVertex2f(72, 54);
    glVertex2f(59, 59);
    glEnd();
    glBegin(GL_QUADS); //right
    glColor3ub(81, 74, 60);
    glVertex2f(59.5, 52.6);
    glVertex2f(71.5, 48);
    //glColor3ub(174, 152, 107);
    glVertex2f(71.5, 53.5);
    glVertex2f(59.5, 58);
    glEnd();
    glBegin(GL_QUADS); //right
    glColor3ub(45, 55, 25);
    glVertex2f(60, 52.6);
    glVertex2f(71.6, 52.3);
    glVertex2f(71.6, 47.9);
    glVertex2f(59.4, 52);
    glEnd();

    //Night_Ground
    glBegin(GL_TRIANGLES);//IndoorFloor
    glColor3ub(52, 33, 26);
    glVertex2f(24, 38);
    glVertex2f(37, 44);
    glVertex2f(24, 47);
    glEnd();
    glBegin(GL_QUADS); //Door_right_stump
    glColor3ub(73, 49, 36);
    glVertex2f(37, 43);
    glVertex2f(38, 43);
    glVertex2f(38, 60);
    glVertex2f(37, 59);
    glEnd();
    glBegin(GL_QUADS); //Indoor Stumps
    glColor3ub(52, 38, 38);
    glVertex2f(29, 46);
    glVertex2f(30, 45);
    glVertex2f(30, 56);
    glVertex2f(29, 55.6);
    glEnd();
    glBegin(GL_QUADS); //GroundBugFix
    glColor3ub(52, 38, 38);
    glVertex2f(24, 47);
    glVertex2f(37, 43);
    glVertex2f(37, 44);
    glVertex2f(24, 48);
    glEnd();

    glBegin(GL_QUADS);//Main Ground
    glColor3ub(52, 33, 26);
    glVertex2f(5, 30);
    glVertex2f(50, 6);
    glVertex2f(95, 30);
    glVertex2f(50, 50);
    glEnd();

    glBegin(GL_QUADS); //CornerStripLeft
    glColor3ub(80, 55, 43);
    glVertex2f(4, 30);
    glVertex2f(50, 5);
    glVertex2f(50, 6);
    glVertex2f(5, 30);
    glEnd();
    glBegin(GL_QUADS); //CornerStripright
    glColor3ub(80, 55, 43);
    glVertex2f(50, 5);
    glVertex2f(96, 30);
    glVertex2f(95, 30);
    glVertex2f(50, 6);
    glEnd();

    //Night_top wood strip
    glBegin(GL_QUADS); //left
    glColor3ub(52, 46, 46);
    glVertex2f(5, 59);
    glVertex2f(50, 78);
    glVertex2f(50, 79);
    glVertex2f(5, 60);
    glEnd();
    glBegin(GL_QUADS); //right
    glColor3ub(52, 46, 46);
    glVertex2f(50, 78);
    glVertex2f(95, 59);
    glVertex2f(95, 60);
    glVertex2f(50, 79);
    glEnd();

    //Night_bottom wood strip
    glBegin(GL_QUADS); //left
    glColor3ub(52, 46, 46);
    glVertex2f(5, 48);
    glVertex2f(50, 67);
    glVertex2f(50, 68);
    glVertex2f(5, 49);
    glEnd();
    glBegin(GL_QUADS); //right
    glColor3ub(52, 46, 46);
    glVertex2f(50, 67);
    glVertex2f(95, 49);
    glVertex2f(95, 50);
    glVertex2f(50, 68);
    glEnd();

    //Night_Shelf
    glBegin(GL_QUADS); //left
    glColor3ub(68, 43, 29);
    glVertex2f(7, 31);
    glVertex2f(10, 29);
    glVertex2f(10, 46);
    glVertex2f(7, 47);
    glEnd();
    glBegin(GL_QUADS); //front
    glColor3ub(68, 43, 29);
    glVertex2f(10, 29);
    glVertex2f(22, 34);
    glVertex2f(22, 51);
    glVertex2f(10, 46);
    glEnd();
    glBegin(GL_QUADS); //BookTopRed
    glColor3ub(101, 44, 45);
    glVertex2f(10.6, 46.9);
    glVertex2f(20.8, 51);
    glVertex2f(20.9, 46.2);
    glVertex2f(10.8, 41.9);
    glEnd();
    glBegin(GL_QUADS); //TopRedBookBugFix
    glColor3ub(101, 44, 45);
    glVertex2f(10.8, 41.9);
    glVertex2f(10.6, 46.8);
    glVertex2f(10, 46.8);
    glVertex2f(10, 42.6);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(41, 40, 39);
    glVertex2f(12.1, 47.5);
    glVertex2f(12.1, 42.4);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(41, 40, 39);
    glVertex2f(13.8, 48.1);
    glVertex2f(13.8, 43.1);
    glEnd();
    glBegin(GL_QUADS); //GreenTopBook
    glColor3ub(87, 113, 66);
    glVertex2f(15.5, 48.5);
    glVertex2f(15.5, 44);
    glVertex2f(17.3, 45);
    glVertex2f(17.3, 49);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(41, 40, 39);
    glVertex2f(15.5, 48.8);
    glVertex2f(15.5, 43.4);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(41, 40, 39);
    glVertex2f(17.3, 49.6);
    glVertex2f(17.3, 45);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(41, 40, 39);
    glVertex2f(19, 50);
    glVertex2f(19, 45.4);
    glEnd();

    glBegin(GL_QUADS); //Shelftop
    glColor3ub(68, 43, 29);
    glVertex2f(7, 47);
    glVertex2f(10, 46);
    glVertex2f(22, 51);
    glVertex2f(19.5, 52.2);
    glEnd();

    glBegin(GL_QUADS); //DeckTop
    glColor3ub(125, 84, 61);
    glVertex2f(10, 41);
    glVertex2f(22, 46);
    glVertex2f(20, 46);
    glVertex2f(10, 42);
    glEnd();
    glBegin(GL_QUADS); //DeckMid
    glColor3ub(125, 84, 61);
    glVertex2f(10, 34);
    glVertex2f(22, 39);
    glVertex2f(20, 39);
    glVertex2f(10, 35);
    glEnd();
    glBegin(GL_QUADS); //BookMidYellow
    glColor3ub(126, 81, 0);
    glVertex2f(14.5, 43);
    glVertex2f(14.5, 36);
    glVertex2f(20.8, 38.8);
    glVertex2f(20.8, 45.7);
    glEnd();
    glBegin(GL_QUADS); //BookMidBugFix
    glColor3ub(126, 81, 0);
    glVertex2f(14.5, 36);
    glVertex2f(14.5, 43);
    glVertex2f(13, 43);
    glVertex2f(13, 37);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(41, 40, 39);
    glVertex2f(14.5, 36);
    glVertex2f(14.5, 43);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(41, 40, 39);
    glVertex2f(16.7, 37);
    glVertex2f(16.7, 43.9);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(41, 40, 39);
    glVertex2f(18.9, 38.2);
    glVertex2f(18.9, 45);
    glEnd();

    glBegin(GL_QUADS); //DeckTop(2)
    glColor3ub(125, 84, 61);
    glVertex2f(10, 41);
    glVertex2f(22, 46);
    glVertex2f(20, 46);
    glVertex2f(10, 42);
    glEnd();
    glBegin(GL_QUADS); //DeckBottom
    glColor3ub(125, 84, 61);
    glVertex2f(10, 29);
    glVertex2f(22, 34);
    glVertex2f(20, 34);
    glVertex2f(10, 30);
    glEnd();
    glBegin(GL_QUADS); //BookBott
    glColor3ub(57, 71, 35);
    glVertex2f(9.9, 29.5);
    glVertex2f(17.8, 32.8);
    glVertex2f(17.8, 37.4);
    glVertex2f(9.9, 34);
    glEnd();
    glBegin(GL_QUADS); //DeckMid(2)
    glColor3ub(125, 84, 61);
    glVertex2f(10, 34);
    glVertex2f(22, 39);
    glVertex2f(20, 39);
    glVertex2f(10, 35);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(41, 40, 39);
    glVertex2f(12, 30.5);
    glVertex2f(12, 34.7);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(41, 40, 39);
    glVertex2f(14.3, 31.3);
    glVertex2f(14.3, 35.7);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(41, 40, 39);
    glVertex2f(16.3, 32);
    glVertex2f(16.3, 36.5);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(125, 84, 61);
    glVertex2f(10, 46);
    glVertex2f(10, 29);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(125, 84, 61);
    glVertex2f(22, 34);
    glVertex2f(21.9, 51);
    glEnd();

    //Night_Door
    glBegin(GL_QUADS); //left
    glColor3ub(73, 49, 36);
    glVertex2f(23, 38);
    glVertex2f(24, 38);
    glVertex2f(24, 53);
    glVertex2f(23, 53);
    glEnd();
    glBegin(GL_QUADS); //top
    glColor3ub(73, 49, 36);
    glVertex2f(23, 53);
    glVertex2f(24, 53);
    glVertex2f(37, 59);
    glVertex2f(38, 60);
    glEnd();

    //NightFloorMatt
    glBegin(GL_QUADS); //matt
    glColor3ub(71, 65, 35);
    glVertex2f(21, 31);
    glVertex2f(50, 16);
    glVertex2f(80, 31);
    glVertex2f(50, 43);
    glEnd();

    //Night_TopTable
    glBegin(GL_QUADS); //StandBack
    glColor3ub(76, 54, 52);
    glVertex2f(46, 49);
    glVertex2f(46, 45);
    glVertex2f(47, 44);
    glVertex2f(47, 49);
    glEnd();
    glBegin(GL_QUADS); //StandFront
    glColor3ub(76, 54, 52);
    glVertex2f(47, 49);
    glVertex2f(49, 50);
    glColor3ub(52, 38, 38);
    glVertex2f(49, 45);
    glVertex2f(47, 44);
    glEnd();
    glBegin(GL_QUADS); //TopFace
    glColor3ub(76, 54, 52);
    glVertex2f(39, 49);
    glVertex2f(43, 47);
    glVertex2f(55, 52);
    glVertex2f(50, 53);
    glEnd();
    glBegin(GL_QUADS); //Left
    glColor3ub(76, 54, 52);
    glVertex2f(39, 48);
    glVertex2f(43, 46);
    glVertex2f(43, 47);
    glVertex2f(39, 49);
    glEnd();
    glBegin(GL_QUADS); //Front
    glColor3ub(76, 54, 52);
    glVertex2f(43, 46);
    glVertex2f(55, 51);
    glVertex2f(55, 52);
    glVertex2f(43, 47);
    glEnd();

    //TableLines
    glBegin(GL_LINES);
    glColor3ub(52, 38, 38);
    glVertex2f(39, 48);
    glVertex2f(43, 46);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(52, 38, 38);
    glVertex2f(39, 49);
    glVertex2f(43, 47);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(52, 38, 38);
    glVertex2f(43, 46);
    glVertex2f(55, 51);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(52, 38, 38);
    glVertex2f(43, 47);
    glVertex2f(43, 46);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(52, 38, 38);
    glVertex2f(43, 47);
    glVertex2f(55, 52);
    glEnd();

    //Flower Tub
    glBegin(GL_QUADS); //TubBack
    glColor3ub(87, 86, 90);
    glVertex2f(27, 23);
    glVertex2f(30, 22);
    glVertex2f(33, 23);
    glVertex2f(30, 24);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(52, 38, 38);
    glVertex2f(28, 22);
    glVertex2f(30, 23);
    glVertex2f(32, 22);
    glEnd();

    //LeftTreeStem
    glBegin(GL_TRIANGLES);
    glColor3ub(52, 38, 38);
    glVertex2f(27, 26);
    glVertex2f(28, 26);
    glVertex2f(31, 28);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(52, 38, 38);
    glVertex2f(27, 26);
    glVertex2f(32, 23);
    glVertex2f(32, 25);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(52, 38, 38);
    glVertex2f(32, 25);
    glVertex2f(29, 22);
    glVertex2f(32, 22);
    glEnd();

    // Night_leaves_Left_Tree
    glBegin(GL_QUADS);
    glColor3ub(20, 36, 19);
    glVertex2f(32 + offset*.3, 26);
    glVertex2f(33 + offset*.3, 27);
    glVertex2f(34 + offset*.3, 27);
    glVertex2f(35 + offset*.3, 26);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(20, 36, 19);
    glVertex2f(31 + offset*.3, 24);
    glVertex2f(36 + offset*.3, 24);
    glVertex2f(34 + offset*.3, 26);
    glVertex2f(33 + offset*.3, 26);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(20, 36, 19);
    glVertex2f(34 + offset*.3, 25);
    glVertex2f(37 + offset*.3, 25);
    glVertex2f(36 + offset*.3, 26);
    glVertex2f(35 + offset*.3, 26);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(20, 36, 19);
    glVertex2f(27 - offset*.3, 27);
    glVertex2f(32 - offset*.3, 27);
    glVertex2f(30 - offset*.3, 29);
    glVertex2f(29 - offset*.3, 29);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(20, 36, 19);
    glVertex2f(28 - offset*.3, 29);
    glVertex2f(31 - offset*.3, 29);
    glVertex2f(30 - offset*.3, 30);
    glVertex2f(29 - offset*.3, 30);
    glEnd();


    //NightLeftFlowerTub
    glBegin(GL_QUADS); //LeftTub
    glColor3ub(89, 90, 94);
    glVertex2f(27, 23);
    glVertex2f(30, 22);
    glColor3ub(87, 86, 90);
    glVertex2f(30, 19);
    glVertex2f(28, 20);
    glEnd();
    glBegin(GL_QUADS); //RightTub
    glColor3ub(89, 90, 94);
    glVertex2f(30, 22);
    glVertex2f(33, 23);
    glColor3ub(87, 86, 90);
    glVertex2f(32, 20);
    glVertex2f(30, 19);
    glEnd();

    //MiddleTree
    glBegin(GL_TRIANGLES);//MiddleTreeStem
    glColor3ub(52, 38, 38);
    glVertex2f(42, 49);
    glVertex2f(44, 49);
    glVertex2f(43, 55);
    glEnd();

    //NightMiddlePot
    glBegin(GL_QUADS); //MiddleTreePot
    glColor3ub(89, 90, 94);
    glVertex2f(42, 52);
    glVertex2f(42, 49);
    glColor3ub(88, 87, 91);
    glVertex2f(44, 49);
    glVertex2f(44, 52);
    glEnd();

    //MiddleTreeLeavesNight
    glBegin(GL_QUADS); //Leaf
    glColor3ub(20, 36, 19);
    glVertex2f(42 + offset*.3, 54);
    glVertex2f(43 + offset*.3, 56);
    glVertex2f(44 + offset*.3, 56);
    glVertex2f(45 + offset*.3, 54);
    glEnd();
    glBegin(GL_QUADS); //Leaf
    glColor3ub(20, 36, 19);
    glVertex2f(41 - offset*.3, 55);
    glVertex2f(44 - offset*.3, 55);
    glVertex2f(43 - offset*.3, 57);
    glVertex2f(42 - offset*.3, 57);
    glEnd();

    //RightTree
    glBegin(GL_QUADS); //TubBack
    glColor3ub(87, 86, 90);
    glVertex2f(46, 52);
    glVertex2f(48, 51);
    glVertex2f(52, 53);
    glVertex2f(50, 54);
    glEnd();
    glBegin(GL_QUADS); //RightTreeDirt
    glColor3ub(52, 38, 38);
    glVertex2f(46.6, 51.7);
    glVertex2f(48, 51);
    glVertex2f(51.3, 52.7);
    glVertex2f(50, 53.6);
    glEnd();
    glBegin(GL_QUADS); //TubLeft
    glColor3ub(87, 86, 90);
    glVertex2f(46, 52);
    glVertex2f(46, 51);
    glVertex2f(48, 50);
    glVertex2f(48, 51);
    glEnd();
    glBegin(GL_QUADS); //TubFront
    glColor3ub(87, 86, 90);
    glVertex2f(48, 50);
    glVertex2f(52, 52);
    glVertex2f(52, 53);
    glVertex2f(48, 51);
    glEnd();
    glBegin(GL_TRIANGLES);//TreeStemLower
    glColor3ub(52, 38, 38);
    glVertex2f(46, 54);
    glVertex2f(48, 52);
    glVertex2f(50, 52);
    glEnd();
    glBegin(GL_TRIANGLES);//TreeStemUpper
    glColor3ub(52, 38, 38);
    glVertex2f(49, 56);
    glVertex2f(46, 54);
    glVertex2f(47, 53);
    glEnd();

    //TubLines
    glBegin(GL_LINES);//RightTubLine
    glColor3ub(34, 34, 34);
    glVertex2f(46, 52);
    glVertex2f(48, 51);
    glEnd();
    glBegin(GL_LINES);//RigtTubLine
    glColor3ub(34, 34, 34);
    glVertex2f(52, 53);
    glVertex2f(48, 51);
    glEnd();

    //RightTreeLeaves_Night
    glBegin(GL_QUADS); //Leaf
    glColor3ub(20, 36, 19);
    glVertex2f(46 + offset*.3, 55);
    glVertex2f(51 + offset*.3, 55);
    glVertex2f(49 + offset*.3, 57);
    glVertex2f(48 + offset*.3, 57);
    glEnd();
    glBegin(GL_QUADS); //Leaf
    glColor3ub(20, 36, 19);
    glVertex2f(47 + offset*.3, 57);
    glVertex2f(50 + offset*.3, 57);
    glVertex2f(49 + offset*.3, 58);
    glVertex2f(48 + offset*.3, 58);
    glEnd();

    //TableMiddle_Night
    glBegin(GL_QUADS); //TableTop
    glColor3ub(70, 51, 51);
    glVertex2f(46, 27);
    glVertex2f(54, 23);
    glColor3ub(125, 84, 61);
    glVertex2f(66, 29);
    glVertex2f(57, 33);
    glEnd();
    glBegin(GL_QUADS); //TableLeftSide
    glColor3ub(71, 65, 35);
    glVertex2f(46, 27);
    glVertex2f(54, 23);
    glColor3ub(109, 100, 53);
    glVertex2f(54, 19);
    glVertex2f(45, 24);
    glEnd();
    glBegin(GL_QUADS); //TableRightSide
    glColor3ub(71, 65, 35);
    glVertex2f(54, 23);
    glVertex2f(66, 29);
    glColor3ub(109, 100, 53);
    glVertex2f(68, 26);
    glVertex2f(54, 19);
    glEnd();

    //Night Book on Table
    glBegin(GL_QUADS); //Left
    glColor3ub(50, 50, 52);
    glVertex2f(54, 26);
    glVertex2f(56, 25);
    glVertex2f(58, 26);
    glVertex2f(56, 27);
    glEnd();
    glBegin(GL_LINES);//BookLine
    glColor3ub(34, 34, 34);
    glVertex2f(54, 26);
    glVertex2f(56, 25);
    glEnd();
    glBegin(GL_LINES);//BookLine
    glColor3ub(34, 34, 34);
    glVertex2f(58, 26);
    glVertex2f(56, 27);
    glEnd();

    glBegin(GL_LINES);//BookLine
    glColor3ub(34, 34, 34);
    glVertex2f(58, 26);
    glVertex2f(56, 25);
    glEnd();

    //Night_cup
    glBegin(GL_QUADS);//Bottom
    glColor3ub(89, 81, 64);
    glVertex2f(57.8, 30);
    glVertex2f(58.3, 29.1);
    glVertex2f(59.7, 29.6);
    glVertex2f(59.1, 30.4);
    glEnd();
    glBegin(GL_QUADS);//Body
    glColor3ub(89, 81, 64);
    glVertex2f(57.8, 29.9);
    glVertex2f(59.9, 29.6);
    glVertex2f(59.9, 31.5);
    glVertex2f(57.8, 32);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(10, 10, 10);
    glVertex2f(59.6, 31.2);
    glVertex2f(60.3, 31.2);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(10, 10, 10);
    glVertex2f(59.6, 29.6);
    glVertex2f(60.3, 31.2);
    glEnd();
    glBegin(GL_QUADS);//Coffee
    glColor3ub(52, 38, 38);
    glVertex2f(57.8, 31.9);
    glVertex2f(58.3, 31);
    glVertex2f(59.9, 31.5);
    glVertex2f(59.1, 32.4);
    glEnd();

    glFlush();
}

void display_day()
{

    glBegin(GL_QUADS);
    glColor3ub(31, 25, 27);
    glVertex2f(0, 0);
    glVertex2f(100, 0);
    glVertex2f(100, 100);
    glVertex2f(0, 100);
    glEnd();
    //Back
    glBegin(GL_POLYGON);
    glColor3ub(161, 135, 126);
    glVertex2f(4, 30);
    glVertex2f(50, 5);
    glVertex2f(96, 30);
    glVertex2f(96, 66);
    glVertex2f(4, 65);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(161, 135, 126);
    glVertex2f(4, 65);
    glVertex2f(96, 66);
    glVertex2f(50, 85);
    glEnd();

    //Front
    glBegin(GL_POLYGON);
    glColor3ub(172, 145, 121);
    glVertex2f(5, 30);
    glVertex2f(50, 6);
    glVertex2f(95, 30);
    glVertex2f(95, 65);
    glVertex2f(5, 65);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(172, 145, 121);
    glVertex2f(5, 65);
    glVertex2f(95, 65);
    glVertex2f(50, 84);
    glEnd();
    //wall
    glBegin(GL_QUADS); //right
    glColor3ub(52, 38, 38);
    glVertex2f(5, 30);
    glVertex2f(50, 50);
    glVertex2f(50, 67);
    glVertex2f(5, 48);
    glEnd();


    //Right Wall
    glBegin(GL_QUADS);
    glColor3ub(255, 214, 179);
    glVertex2f(50, 6);
    glVertex2f(95, 30);
    glVertex2f(95, 65);
    glVertex2f(50, 84);
    glEnd();

    glBegin(GL_QUADS); //right
    glColor3ub(247, 228, 221);
    glVertex2f(24, 48);
    glVertex2f(37, 44);
    glVertex2f(37, 59);
    glVertex2f(24, 53);
    glEnd();

    glBegin(GL_QUADS); //right
    glColor3ub(52, 38, 38);
    glVertex2f(50, 50);
    glVertex2f(95, 30);
    glVertex2f(95, 49);
    glVertex2f(50, 67);
    glEnd();

    glBegin(GL_QUADS); //right
    glColor3ub(247, 228, 221);
    glVertex2f(39, 46);
    glVertex2f(44, 48);
    glVertex2f(44, 63);
    glVertex2f(39, 61);
    glEnd();
    glBegin(GL_QUADS); //right
    glColor3ub(247, 228, 221);
    glVertex2f(45, 48.5);
    glVertex2f(49, 50.3);
    glVertex2f(49, 65);
    glVertex2f(45, 63.4);
    glEnd();
    glBegin(GL_QUADS); //right
    glColor3ub(247, 228, 221);
    glVertex2f(51, 50.5);
    glVertex2f(55.9, 48.5);
    glVertex2f(56, 63);
    glVertex2f(51, 65);
    glEnd();
    glBegin(GL_QUADS); //right
    glColor3ub(247, 228, 221);
    glVertex2f(57, 48);
    glVertex2f(62, 46);
    glVertex2f(62, 60.7);
    glVertex2f(57, 62.7);
    glEnd();
    glBegin(GL_QUADS); //right
    glColor3ub(247, 228, 221);
    glVertex2f(63, 45.4);
    glVertex2f(68, 43.4);
    glVertex2f(68, 58.6);
    glVertex2f(63, 60.6);
    glEnd();
    glBegin(GL_QUADS); //right
    glColor3ub(247, 228, 221);
    glVertex2f(69, 43);
    glVertex2f(74, 41);
    glVertex2f(74, 56);
    glVertex2f(69, 58);
    glEnd();
    glBegin(GL_QUADS); //right
    glColor3ub(247, 228, 221);
    glVertex2f(75, 40.6);
    glVertex2f(81, 37.6);
    glVertex2f(81, 53);
    glVertex2f(75, 55.6);
    glEnd();
    glBegin(GL_QUADS); //right
    glColor3ub(247, 228, 221);
    glVertex2f(82, 37);
    glVertex2f(88, 34.6);
    glVertex2f(88, 50.6);
    glVertex2f(82, 52.6);
    glEnd();
    glBegin(GL_QUADS); //right
    glColor3ub(247, 228, 221);
    glVertex2f(89, 34);
    glVertex2f(94, 31.6);
    glVertex2f(94, 48);
    glVertex2f(89, 50);
    glEnd();


    //portrait
    glBegin(GL_QUADS); //right
    glColor3ub(146, 101, 97);
    glVertex2f(59, 52);
    glVertex2f(72, 47);
    glVertex2f(72, 54);
    glVertex2f(59, 59);
    glEnd();
    glBegin(GL_QUADS); //right
    glColor3ub(174, 152, 107);
    glVertex2f(59.5, 52.6);
    glVertex2f(71.5, 48);
    glVertex2f(71.5, 53.5);
    glVertex2f(59.5, 58);
    glEnd();
    glBegin(GL_QUADS); //right
    glColor3ub(45, 55, 25);
    glVertex2f(59.4, 52.6);
    glVertex2f(71.6, 52.3);
    glVertex2f(71.6, 47.9);
    glVertex2f(59.4, 52);
    glEnd();


    //Ground
    glBegin(GL_TRIANGLES);
    glColor3ub(104, 65, 52);
    glVertex2f(24, 38);
    glVertex2f(37, 44);
    glVertex2f(24, 47);
    glEnd();
    glBegin(GL_QUADS); //Door_right_wall
    glColor3ub(125, 84, 61);
    glVertex2f(37, 43);
    glVertex2f(38, 43);
    glVertex2f(38, 60);
    glVertex2f(37, 59);
    glEnd();
    glBegin(GL_QUADS); //right
    glColor3ub(52, 38, 38);
    glVertex2f(29, 46);
    glVertex2f(30, 45);
    glVertex2f(30, 56);
    glVertex2f(29, 55.6);
    glEnd();
    glBegin(GL_QUADS); //right
    glColor3ub(52, 38, 38);
    glVertex2f(24, 47);
    glVertex2f(37, 43);
    glVertex2f(37, 44);
    glVertex2f(24, 48);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(104, 65, 52);
    glVertex2f(5, 30);
    glVertex2f(50, 6);
    glVertex2f(95, 30);
    glVertex2f(50, 50);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(157, 109, 84);
    glVertex2f(4, 30);
    glVertex2f(50, 5);
    glVertex2f(50, 6);
    glVertex2f(5, 30);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(157, 109, 84);
    glVertex2f(50, 5);
    glVertex2f(96, 30);
    glVertex2f(95, 30);
    glVertex2f(50, 6);
    glEnd();

    //top wood strip
    glBegin(GL_QUADS); //left
    glColor3ub(125, 84, 61);
    glVertex2f(5, 48);
    glVertex2f(50, 67);
    glVertex2f(50, 68);
    glVertex2f(5, 49);
    glEnd();
    glBegin(GL_QUADS); //right
    glColor3ub(125, 84, 61);
    glVertex2f(50, 67);
    glVertex2f(95, 49);
    glVertex2f(95, 50);
    glVertex2f(50, 68);
    glEnd();

    //Light_Shelf Left
    glBegin(GL_QUADS); //left
    glColor3ub(223, 165, 116);
    glVertex2f(7, 31);
    glVertex2f(10, 29);
    glVertex2f(10, 46);
    glVertex2f(7, 47);
    glEnd();
    glBegin(GL_QUADS); //front
    glColor3ub(181, 115, 78);
    glVertex2f(10, 29);
    glVertex2f(22, 34);
    glVertex2f(22, 51);
    glVertex2f(10, 46);
    glEnd();
    glBegin(GL_QUADS); //BookTopRed
    glColor3ub(178, 78, 80);
    glVertex2f(10.6, 46.9);
    glVertex2f(20.8, 51);
    glVertex2f(20.9, 46.2);
    glVertex2f(10.8, 41.9);
    glEnd();
    glBegin(GL_QUADS); //BookTopRedBugFix
    glColor3ub(178, 78, 80);
    glVertex2f(10.8, 41.9);
    glVertex2f(10.6, 46.8);
    glVertex2f(10, 46.8);
    glVertex2f(10, 42.6);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex2f(12.1, 47.5);
    glVertex2f(12.1, 42.4);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex2f(13.8, 48.1);
    glVertex2f(13.8, 43.1);
    glEnd();
    glBegin(GL_QUADS); //top
    glColor3ub(87, 113, 66);
    glVertex2f(15.5, 48.5);
    glVertex2f(15.5, 44);
    glVertex2f(17.3, 45);
    glVertex2f(17.3, 49);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex2f(15.5, 48.8);
    glVertex2f(15.5, 43.4);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex2f(17.3, 49.6);
    glVertex2f(17.3, 45);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex2f(19, 50);
    glVertex2f(19, 45.4);
    glEnd();
    glBegin(GL_QUADS); //Shelftop
    glColor3ub(181, 115, 78);
    glVertex2f(7, 47);
    glVertex2f(10, 46);
    glVertex2f(22, 51);
    glVertex2f(19.5, 52.2);
    glEnd();
    glBegin(GL_QUADS); //DeckTop
    glColor3ub(125, 84, 61);
    glVertex2f(10, 41);
    glVertex2f(22, 46);
    glVertex2f(20, 46);
    glVertex2f(10, 42);
    glEnd();
    glBegin(GL_QUADS); //DeckMid
    glColor3ub(125, 84, 61);
    glVertex2f(10, 34);
    glVertex2f(22, 39);
    glVertex2f(20, 39);
    glVertex2f(10, 35);
    glEnd();
    glBegin(GL_QUADS); //BookMidYellow
    glColor3ub(255, 180, 0);
    glVertex2f(14.5, 43);
    glVertex2f(14.5, 36);
    glVertex2f(20.8, 38.8);
    glVertex2f(20.8, 45.7);
    glEnd();
    glBegin(GL_QUADS); //BookMidBugFix
    glColor3ub(255, 180, 0);
    glVertex2f(14.5, 36);
    glVertex2f(14.5, 43);
    glVertex2f(13, 43);
    glVertex2f(13, 37);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(41, 40, 39);
    glVertex2f(14.5, 36);
    glVertex2f(14.5, 43);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(41, 40, 39);
    glVertex2f(16.7, 37);
    glVertex2f(16.7, 43.9);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(41, 40, 39);
    glVertex2f(18.9, 38.2);
    glVertex2f(18.9, 45);
    glEnd();
    glBegin(GL_QUADS); //DeckTop(2)
    glColor3ub(125, 84, 61);
    glVertex2f(10, 41);
    glVertex2f(22, 46);
    glVertex2f(20, 46);
    glVertex2f(10, 42);
    glEnd();
    glBegin(GL_QUADS); //DeckBottom
    glColor3ub(125, 84, 61);
    glVertex2f(10, 29);
    glVertex2f(22, 34);
    glVertex2f(20, 34);
    glVertex2f(10, 30);
    glEnd();
    glBegin(GL_QUADS); //BookBott
    glColor3ub(118, 147, 72);
    glVertex2f(9.9, 29.5);
    glVertex2f(17.8, 32.8);
    glVertex2f(17.8, 37.4);
    glVertex2f(9.9, 34);
    glEnd();
    glBegin(GL_QUADS); //DeckMid(2)
    glColor3ub(125, 84, 61);
    glVertex2f(10, 34);
    glVertex2f(22, 39);
    glVertex2f(20, 39);
    glVertex2f(10, 35);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(41, 40, 39);
    glVertex2f(12, 30.5);
    glVertex2f(12, 34.7);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(41, 40, 39);
    glVertex2f(14.3, 31.3);
    glVertex2f(14.3, 35.7);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(41, 40, 39);
    glVertex2f(16.3, 32);
    glVertex2f(16.3, 36.5);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(125, 84, 61);
    glVertex2f(10, 46);
    glVertex2f(10, 29);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(125, 84, 61);
    glVertex2f(22, 34);
    glVertex2f(21.9, 51);
    glEnd();
    glBegin(GL_QUADS); //DeckBottom
    glColor3ub(125, 84, 61);
    glVertex2f(10, 29);
    glVertex2f(22, 34);
    glVertex2f(20, 34);
    glVertex2f(10, 30);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(125, 84, 61);
    glVertex2f(10, 46);
    glVertex2f(10, 29);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(125, 84, 61);
    glVertex2f(22, 34);
    glVertex2f(21.9, 51);
    glEnd();

    //Door
    glBegin(GL_QUADS); //left
    glColor3ub(125, 84, 61);
    glVertex2f(23, 38);
    glVertex2f(24, 38);
    glVertex2f(24, 53);
    glVertex2f(23, 53);
    glEnd();
    glBegin(GL_QUADS); //top
    glColor3ub(125, 84, 61);
    glVertex2f(23, 53);
    glVertex2f(24, 53);
    glVertex2f(37, 59);
    glVertex2f(38, 60);
    glEnd();

    //top wood strip
    glBegin(GL_QUADS); //left
    glColor3ub(125, 84, 61);
    glVertex2f(5, 59);
    glVertex2f(50, 78);
    glVertex2f(50, 79);
    glVertex2f(5, 60);
    glEnd();
    glBegin(GL_QUADS); //right
    glColor3ub(125, 84, 61);
    glVertex2f(50, 78);
    glVertex2f(95, 59);
    glVertex2f(95, 60);
    glVertex2f(50, 79);
    glEnd();

    glBegin(GL_QUADS); //matt
    glColor3ub(174, 152, 107);
    glVertex2f(21, 31);
    glVertex2f(50, 16);
    glVertex2f(80, 31);
    glVertex2f(50, 43);
    glEnd();

    //Table
    glBegin(GL_QUADS); //matt
    glColor3ub(125, 84, 61);
    glVertex2f(46, 49);
    glVertex2f(46, 45);
    //glColor3ub(52, 38, 38);
    glVertex2f(47, 44);
    glVertex2f(47, 49);
    glEnd();

    glBegin(GL_QUADS); //matt
    glColor3ub(125, 84, 61);
    glVertex2f(47, 49);
    glVertex2f(49, 50);
    glColor3ub(52, 38, 38);
    glVertex2f(49, 45);
    glVertex2f(47, 44);
    glEnd();

    glBegin(GL_QUADS); //matt
    glColor3ub(125, 84, 61);
    glVertex2f(39, 49);
    glVertex2f(43, 47);
    glVertex2f(55, 52);
    glVertex2f(50, 53);
    glEnd();
    glBegin(GL_QUADS); //matt
    glColor3ub(125, 84, 61);
    glVertex2f(39, 48);
    glVertex2f(43, 46);
    glVertex2f(43, 47);
    glVertex2f(39, 49);
    glEnd();
    glBegin(GL_QUADS); //matt
    glColor3ub(125, 84, 61);
    glVertex2f(43, 46);
    glVertex2f(55, 51);
    glVertex2f(55, 52);
    glVertex2f(43, 47);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(52, 38, 38);
    glVertex2f(39, 48);
    glVertex2f(43, 46);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(52, 38, 38);
    glVertex2f(39, 49);
    glVertex2f(43, 47);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(52, 38, 38);
    glVertex2f(43, 46);
    glVertex2f(55, 51);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(52, 38, 38);
    glVertex2f(43, 47);
    glVertex2f(43, 46);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(52, 38, 38);
    glVertex2f(43, 47);
    glVertex2f(55, 52);
    glEnd();

    //Flower Tub
    glBegin(GL_QUADS); //matt
    glColor3ub(87, 86, 90);
    glVertex2f(27, 23);
    glVertex2f(30, 22);
    glVertex2f(33, 23);
    glVertex2f(30, 24);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(52, 38, 38);
    glVertex2f(28, 22);
    glVertex2f(30, 23);
    glVertex2f(32, 22);
    glEnd();
    //tree
    glBegin(GL_TRIANGLES);
    glColor3ub(52, 38, 38);
    glVertex2f(27, 26);
    glVertex2f(28, 26);
    glVertex2f(31, 28);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(52, 38, 38);
    glVertex2f(27, 26);
    glVertex2f(32, 23);
    glVertex2f(32, 25);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(52, 38, 38);
    glVertex2f(32, 25);
    glVertex2f(29, 22);
    glVertex2f(32, 22);
    glEnd();
    // leaves
    glBegin(GL_QUADS);
    glColor3ub(63, 113, 59);
    glVertex2f(32 + offset*.3, 26);
    glVertex2f(33 + offset*.3, 27);
    glVertex2f(34 + offset*.3, 27);
    glVertex2f(35 + offset*.3, 26);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(63 + offset*.3, 113, 59);
    glVertex2f(31 + offset*.3, 24);
    glVertex2f(36 + offset*.3, 24);
    glVertex2f(34 + offset*.3, 26);
    glVertex2f(33 + offset*.3, 26);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(63 + offset*.3, 113, 59);
    glVertex2f(34 + offset*.3, 25);
    glVertex2f(37 + offset*.3, 25);
    glVertex2f(36 + offset*.3, 26);
    glVertex2f(35 + offset*.3, 26);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(63 - offset*.3, 113, 59);
    glVertex2f(27 - offset*.3, 27);
    glVertex2f(32 - offset*.3, 27);
    glVertex2f(30 - offset*.3, 29);
    glVertex2f(29 - offset*.3, 29);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(63 - offset*.3, 113, 59);
    glVertex2f(28 - offset*.3, 29);
    glVertex2f(31 - offset*.3, 29);
    glVertex2f(30 - offset*.3, 30);
    glVertex2f(29 - offset*.3, 30);
    glEnd();

    glBegin(GL_QUADS); //matt
    glColor3ub(183, 197, 197);
    glVertex2f(27, 23);
    glVertex2f(30, 22);
    glColor3ub(87, 86, 90);
    glVertex2f(30, 19);
    glVertex2f(28, 20);
    glEnd();
    glBegin(GL_QUADS); //matt
    glColor3ub(183, 197, 197);
    glVertex2f(30, 22);
    glVertex2f(33, 23);
    glColor3ub(87, 86, 90);
    glVertex2f(32, 20);
    glVertex2f(30, 19);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(52, 38, 38);
    glVertex2f(42, 49);
    glVertex2f(44, 49);
    glVertex2f(43, 55);
    glEnd();
    glBegin(GL_QUADS); //matt
    glColor3ub(183, 197, 197);
    glVertex2f(42, 52);
    glVertex2f(42, 49);
    glColor3ub(88, 87, 91);
    glVertex2f(44, 49);
    glVertex2f(44, 52);
    glEnd();
    glBegin(GL_QUADS); //matt
    glColor3ub(63 + offset*.3, 113, 59);
    glVertex2f(42 + offset*.3, 54);
    glVertex2f(43 + offset*.3, 56);
    glVertex2f(44 + offset*.3, 56);
    glVertex2f(45 + offset*.3, 54);
    glEnd();

    glBegin(GL_QUADS); //matt
    glColor3ub(63, 113, 59);
    glVertex2f(41 - offset*.3, 55);
    glVertex2f(44 - offset*.3, 55);
    glVertex2f(43 - offset*.3, 57);
    glVertex2f(42 - offset*.3, 57);
    glEnd();

    glBegin(GL_QUADS); //matt
    glColor3ub(87, 86, 90);
    glVertex2f(46, 52);
    glVertex2f(48, 51);
    glVertex2f(52, 53);
    glVertex2f(50, 54);
    glEnd();
    glBegin(GL_QUADS); //matt
    glColor3ub(52, 38, 38);
    glVertex2f(46.6, 51.7);
    glVertex2f(48, 51);
    glVertex2f(51.3, 52.7);
    glVertex2f(50, 53.6);
    glEnd();

    glBegin(GL_QUADS); //matt
    glColor3ub(87, 86, 90);
    glVertex2f(46, 52);
    glVertex2f(46, 51);
    glVertex2f(48, 50);
    glVertex2f(48, 51);
    glEnd();
    glBegin(GL_QUADS); //matt
    glColor3ub(87, 86, 90);
    glVertex2f(48, 50);
    glVertex2f(52, 52);
    glVertex2f(52, 53);
    glVertex2f(48, 51);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(52, 38, 38);
    glVertex2f(46, 54);
    glVertex2f(48, 52);
    glVertex2f(50, 52);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(52, 38, 38);
    glVertex2f(49, 56);
    glVertex2f(46, 54);
    glVertex2f(47, 53);
    glEnd();
    glBegin(GL_QUADS); //matt
    glColor3ub(63, 113, 59);
    glVertex2f(46 + offset*.3, 55);
    glVertex2f(51 + offset*.3, 55);
    glVertex2f(49 + offset*.3, 57);
    glVertex2f(48 + offset*.3, 57);
    glEnd();
    glBegin(GL_QUADS); //matt
    glColor3ub(63, 113, 59);
    glVertex2f(47 + offset*.3, 57);
    glVertex2f(50 + offset*.3, 57);
    glVertex2f(49 + offset*.3, 58);
    glVertex2f(48 + offset*.3, 58);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(34, 34, 34);
    glVertex2f(46, 52);
    glVertex2f(48, 51);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(34, 34, 34);
    glVertex2f(52, 53);
    glVertex2f(48, 51);
    glEnd();
    glBegin(GL_QUADS); //matt
    glColor3ub(125, 84, 61);
    glVertex2f(46, 27);
    glVertex2f(54, 23);
    glVertex2f(66, 29);
    glVertex2f(57, 33);
    glEnd();
    glBegin(GL_QUADS); //matt
    glColor3ub(251, 234, 128);
    glVertex2f(46, 27);
    glVertex2f(54, 23);
    glColor3ub(198, 182, 99);
    glVertex2f(54, 19);
    glVertex2f(45, 24);
    glEnd();
    glBegin(GL_QUADS); //matt
    glColor3ub(251, 234, 128);
    glVertex2f(54, 23);
    glVertex2f(66, 29);
    glColor3ub(147, 135, 73);
    glVertex2f(68, 26);
    glVertex2f(54, 19);
    glEnd();
    glBegin(GL_QUADS); //matt
    glColor3ub(174, 152, 107);
    glVertex2f(54, 26);
    glVertex2f(56, 25);
    glVertex2f(58, 26);
    glVertex2f(56, 27);
    glEnd();
    glBegin(GL_QUADS); //matt
    glColor3ub(174, 152, 107);
    glVertex2f(57.6, 28);
    glVertex2f(59.7, 27);
    glVertex2f(58, 26);
    glVertex2f(56, 27);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(34, 34, 34);
    glVertex2f(54, 26);
    glVertex2f(56, 25);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(34, 34, 34);
    glVertex2f(58, 26);
    glVertex2f(56, 27);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(34, 34, 34);
    glVertex2f(58, 26);
    glVertex2f(56, 25);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(34, 34, 34);
    glVertex2f(58, 26);
    glVertex2f(59.7, 27);
    glEnd();


    //cup
    glBegin(GL_LINES);
    glColor3ub(10, 10, 10);
    glVertex2f(57.9, 33.8 + offset);
    glVertex2f(58.4, 33 + offset);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(10, 10, 10);
    glVertex2f(58, 31.9 + offset);
    glVertex2f(58.4, 33 + offset);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(10, 10, 10);
    glVertex2f(58.4, 34 + offset);
    glVertex2f(59, 33 + offset);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(10, 10, 10);
    glVertex2f(58.4, 32 + offset);
    glVertex2f(59, 33 + offset);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(10, 10, 10);
    glVertex2f(59.3, 33.8 + offset);
    glVertex2f(59.7, 32.7 + offset);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(10, 10, 10);
    glVertex2f(59.3, 31.9 + offset);
    glVertex2f(59.7, 33 + offset);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(219, 202, 175);
    glVertex2f(57.8, 30);
    glVertex2f(58.3, 29.1);
    glVertex2f(59.7, 29.6);
    glVertex2f(59.1, 30.4);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(219, 202, 175);
    glVertex2f(57.8, 29.9);
    glVertex2f(59.9, 29.6);
    glVertex2f(59.9, 31.5);
    glVertex2f(57.8, 32);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(52, 38, 38);
    glVertex2f(57.8, 31.9);
    glVertex2f(58.3, 31);
    glVertex2f(59.9, 31.5);
    glVertex2f(59.1, 32.4);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(10, 10, 10);
    glVertex2f(59.6, 31.2);
    glVertex2f(60.3, 31.2);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(10, 10, 10);
    glVertex2f(59.6, 29.6);
    glVertex2f(60.3, 31.2);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(150, 117, 67);
    glVertex2f(57.8, 31.9);
    glVertex2f(58.3, 31);
    glVertex2f(59.9, 31.5);
    glVertex2f(59.1, 32.4);
    glEnd();

    //Cat
    glBegin(GL_POLYGON);//Tail
    glColor3ub(255, 203, 113);
    glVertex2f(50, 35.4 - offset);
    glVertex2f(53, 36.3 - offset);
    glColor3ub(255, 255, 255);
    glVertex2f(54, 34.8 - offset);
    glVertex2f(53, 35.6 - offset);
    glVertex2f(50.2, 34.5 - offset);
    glEnd();
    glBegin(GL_POLYGON);//body
    glColor3ub(255, 203, 113);
    glVertex2f(49, 39.5);
    glVertex2f(47.8, 37.7);
    glVertex2f(48.9, 34.4);
    glVertex2f(50.4, 34.4);
    glVertex2f(50.8, 36.7);
    glEnd();
    glBegin(GL_QUADS);//Head
    glColor3ub(178, 114, 0);
    glVertex2f(48, 40.80);
    glVertex2f(50, 40.80);
    glColor3ub(255, 203, 113);
    glVertex2f(50, 38.8);
    glVertex2f(48, 38.8);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(178, 114, 0);
    glVertex2f(48.4, 40);
    glVertex2f(49, 40.6);
    glVertex2f(47.8, 41.3);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(178, 114, 0);
    glVertex2f(49.4, 40.6);
    glVertex2f(50.4, 41.2);
    glVertex2f(50, 40);
    glEnd();
    glBegin(GL_QUADS);//Legs
    glColor3ub(89, 60, 40);
    glVertex2f(48.6, 34);
    glVertex2f(49.5, 34);
    glColor3ub(255, 203, 113);
    glVertex2f(50, 37);
    glVertex2f(48, 37);
    glEnd();
    glPointSize(3);
    glBegin(GL_POINTS);
    glColor3ub(0, 0, 0);
    glVertex2f(48.4, 40);
    glEnd();
    glPointSize(3);
    glBegin(GL_POINTS);
    glColor3ub(0, 0, 0);
    glVertex2f(49.4, 40);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(17, 17, 17);
    glVertex2f(49., 36.4);
    glVertex2f(49, 34);
    glEnd();


    glFlush();
}

void lampON()
{
    glBegin(GL_QUADS); //LightRay
    glColor3ub(90, 57, 45);
    glVertex2f(67.4, 39);
    glVertex2f(69.7, 17.4);
    glColor3ub(219, 202, 175);
    glVertex2f(90, 30);
    glVertex2f(87.9, 31.3);
    glEnd();
    glBegin(GL_TRIANGLES); //LightMatt
    glColor3ub(174, 152, 107);
    glVertex2f(67.7, 35.9);
    glVertex2f(80, 31);
    glVertex2f(68.8, 25.4);
    glEnd();
    glBegin(GL_QUADS); //LampBottom
    glColor3ub(147, 155, 157);
    glVertex2f(86, 30);
    glVertex2f(88, 29);
    glVertex2f(90, 30);
    glVertex2f(87.8, 31.3);
    glEnd();
    glBegin(GL_TRIANGLES); //Lamp_Stand
    glColor3ub(147, 155, 157);
    glVertex2f(86, 30);
    glVertex2f(90, 30);
    glColor3ub(219, 202, 175);
    glVertex2f(88, 41);
    glEnd();

    glBegin(GL_QUADS); //Lamp_LeftPlate
    glColor3ub(174, 152, 107);
    glVertex2f(86, 42);
    glVertex2f(85, 38);
    glColor3ub(219, 202, 175);
    glVertex2f(88, 36);
    glVertex2f(88, 41);
    glEnd();

    glBegin(GL_LINES); //Lamp String
    glColor3ub(0,0,0);
    glVertex2f(90.1, 34.3);
    glVertex2f(90.1, 39);
    glEnd();
    glPointSize(3);
    glBegin(GL_POINTS);
    glColor3ub(0, 0, 0);
    glVertex2f(90.1, 34.3);
    glEnd();

    glBegin(GL_QUADS); //Lamp_RightPlate
    glColor3ub(174, 152, 107);
    glVertex2f(90, 42);
    glVertex2f(91, 38);
    glColor3ub(219, 202, 175);
    glVertex2f(88, 36);
    glVertex2f(88, 41);
    glEnd();
    glBegin(GL_QUADS); //Lamp Top Face
    glColor3ub(219, 202, 175);
    glVertex2f(86, 42);
    glVertex2f(88, 41);
    glVertex2f(90, 42);
    glVertex2f(88, 43);
    glEnd();
}

void lampOFF()
{
    glBegin(GL_TRIANGLES); //Lamp_Stand
    glColor3ub(88, 88, 92);
    glVertex2f(86, 30);
    glVertex2f(90, 30);
    glVertex2f(88, 41);
    glEnd();

    glBegin(GL_QUADS); //LampBottom
    glColor3ub(64, 64, 66);
    glVertex2f(86, 30);
    glVertex2f(88, 29);
    glColor3ub(88, 88, 92);
    glVertex2f(90, 30);
    glVertex2f(87.8, 31.3);
    glEnd();

    glBegin(GL_QUADS); //Lamp_LeftPlate
    glColor3ub(125, 111, 82);
    glVertex2f(86, 42);
    glVertex2f(85, 38);
    glColor3ub(80, 73, 59);
    glVertex2f(88, 36);
    glVertex2f(88, 41);
    glEnd();

    glBegin(GL_LINES); //Lamp String
    glColor3ub(0,0,0);
    glVertex2f(90.1, 35.5);
    glVertex2f(90.1, 39);
    glEnd();
    glPointSize(3);
    glBegin(GL_POINTS);
    glColor3ub(0, 0, 0);
    glVertex2f(90.1, 35.5);
    glEnd();

    glBegin(GL_QUADS); //Lamp_RightPlate
    glColor3ub(125, 111, 82);
    glVertex2f(90, 42);
    glVertex2f(91, 38);
    glColor3ub(80, 73, 59);
    glVertex2f(88, 36);
    glVertex2f(88, 41);
    glEnd();

    glBegin(GL_QUADS); //Lamp Top Face
    glColor3ub(80, 73, 59);
    glVertex2f(86, 42);
    glVertex2f(88, 41);
    glColor3ub(174, 152, 107);
    glVertex2f(90, 42);
    glVertex2f(88, 43);
    glEnd();


}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    if (currentSlide == 0)
    {
        display_day();
        if (lightstate == 1)
        {
            lampON();
        }
        else if (lightstate == 0)
        {
            lampOFF();
        }
    }
    else if (currentSlide == 1)
    {
        display_night();
        if (lightstate == 1)
        {
            lampON();
        }
        else if (lightstate == 0)
        {
            lampOFF();
        }
    }

    glFlush();
}

void handleKeypress(unsigned char key, int x, int y)
{
    if (key == 'd')
    {
        currentSlide = 0;
    }
    else if (key == 'n')
    {
        currentSlide = 1;
    }
    else if (key == 'o')
    {
        lightstate = 1;
    }
    else if (key == 'f')
    {
        lightstate = 0;
    }
    glutPostRedisplay();
}

void update(int value)
{
    offset += direction;// offset = 0, directon = -1

    if (offset <= 0 || offset >= 1)
    {
        direction *= -1;
    }

    glutPostRedisplay();

    glutTimerFunc(550, update, 0); // after 550 ms recall the update
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(800, 800);
    glutInitWindowPosition(300, 0);

    glutCreateWindow("Isometric Interior");
    myInit();

    glutDisplayFunc(display);
    glutKeyboardFunc(handleKeypress);
    glutTimerFunc(0, update, 0);// first time update call

    glutMainLoop();
}
