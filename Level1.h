#pragma once
////////////////////////////////////////////
//Include
#include "renderSystem.h"

///////////////////////////////////////////
//Constants

const int levelRows = screenRows;
const int levelColums = screemColums;

const float shipSpeed = 35.0;
const float shipFireCoolDown = 0.2;

const float bulletSpeed = 40.0;

const float alienAmplitude = 7.0;
const float alienSpeed = 0.23;

const unsigned char CellSymbol_Ship = 'S';
const unsigned char CellSymbol_Bullet = '|';
const unsigned char CellSymbol_Alien = 'X';
const unsigned char CellSymbol_Heart = 'H';
const unsigned char CellSymbol_Tank = 'T';
unsigned char levelData0[levelRows][levelColums + 1]{};

const unsigned char levelData1[levelRows][levelColums + 1] =
{
	"                                                             ",
	"                         XXXXXXX                             ",
	"                      XXX       XXX                          ",
	"                     X             X                         ",
	"                    X               X                        ",
	"                   X                 X                       ",
	"                   X  XXXX     XXXX  X                       ",
	"        HXXXX      X X  XXX   XXX  X X      XXXXH            ",
	"        XHXXX      XX     XX XX     XX      XXXHX            ",
	"        XXHXX      XX XXX       XXX XX      XXHXX            ",
	"        XXXHX    XXX XHHHHHX  XHHHHX XXX    XHXXX            ",
	"        XXXXH    X X       X  X      X X    HXXXX            ",
	"                 X X      X    X     X X                     ",
	"                  XX T    X    X   T XX                      ",
	"                   X XT    X  X   TX X                       ",
	"                   X  XTTTTTTTTTTTX  X                       ",
	"         HXXXX     X   TTTT   TTTT   X     XXXXH             ",
	"       XXXHXXXXX    X               X    XXXXXHXXX           ",
	"      XXXXXHXXXXX    X             X    XXXXXHXXXXX          ",
	"         XXXHX       X     XXX     X       XHXXX             ",
	"         XXXXH        X    XXX    X        HXXXX             ",
	"         X   X         X   XXX   X         X   X             ",
	"       XXX   XXX        X  XXX  X        XXX   XXX           ",
	"        XX   XX          XXXXXXX          XX   XX            ",
	"         X   X                             X   X             ",
	"                                                             ",
	"                                                             ",
	"                                                             ",
	"                                                             ",
	"                                                             ",
	"                                                             ",
	"                                                             ",
	"                                                             ",
	"                                                             ",
	"                                                             ",
	"                                                             ",
	"                                                             ",
	"                            S                                "
};

/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////

const unsigned char levelData2[levelRows][levelColums + 1]=
{
	"                                                             ",
	"      TTTTTTTTT        X   XX   X       TTTTTTTTT            ",
	"     TT       TT      XXXXXHHXXXXX     TT       TT           ",
	"     T         T       X  XHHX  X      T         T           ",
	"    TT         TT         X  X        TT         TT          ",
	"    T           T         X  X        T           T          ",
	"    T  XXX XXX  T     TTTTT  TTTT     T  XXX XXX  T          ",
	"    TT HHH HHH TT     X         X     TT HHH HHH TT          ",
	"     T  X   X  T      TTTT   TTTT      T  X   X  T           ",
	"     T    X    T          XHX          T    X    T           ",
	"     TT       TT      XXX XHX XXX      TTT     TTT           ",
	"   XXXXT XXX TXXXX    X X XHX X X    XXXXT XXX TXXXX         ",
	" XXX XXT     TXX XXX  X X TTT X X  XXX XXT     TXX XXX       ",
	" X    XTTTTTTTX    X  X X     X X  X    TTTTTTTTT    X       ",
	" XX       X       XX  X XXXHXXX X  XX       X       XX       ",
	"  XXXXX       XXXXX   X         X   XXXXX       XXXXX        ",
	"      XXX   XXX       XXXXXHXXXXX       XXX   XXX            ",
	"  XXXXX   X   XXXXX       XHX       XXXXX       XXXXX        ",
	" XX     XXXXX     XX  XXX XHX XXX  XX     XXXXX     XX       ",
	" X    XXX   XXX    X  X X XXX X X  X    XXX   XXX    X       ",
	" XXX XX       XX XXX  XXX  X  XXX  XXX XX       XX XXX       ",
	"   XXX         XXX       X   X       XXX         XXX         ",
	"                          X X                                ",
	"                           X                                 ",
	"                                                             ",
	"                                                             ",
	"                                                             ",
	"                                                             ",
	"                                                             ",
	"                                                             ",
	"                                                             ",
	"                                                             ",
	"                                                             ",
	"                                                             ",
	"                                                             ",
	"                                                             ",
	"                                                             ",
	"                           S                                 ",
};


//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////


const unsigned char levelData3[levelRows][levelColums + 1] =
{
	"                                                             ",
	"                                                             ",
	"                                                             ",
	"                     TT   T   T   TT                         ",
	"                    TT    TTTTT    TT                        ",
	"                   TTT    TTHTT    TTT                       ",
	"                  THHT    TTTTT    THHT                      ",
	"                 TTTTTT  TTTTTTT  TTTTTT                     ",
	"                TTTTTTTTTTTTHTTTTTTTTTTTT                    ",
	"                TTTTTTTTTTTTHTTTTTTTTTTTT                    ",
	"                TTTTTTTTTTTTHTTTTTTTTTTTT                    ",
	"                TTTT  TTTTTTTTTTTTT  TTTT                    ",
	"                 TTT   T  TTTTT  T   TTT                     ",
	"                  TTT  T   TTT   T  TTT                      ",
	"                   TTT      T      TTT                       ",
	"                     T             T                         ",
	"                                                             ",
	"                                                             ",
	"                                                             ",
	"                                                             ",
	"                                                             ",
	"                                                             ",
	"                                                             ",
	"                                                             ",
	"                                                             ",
	"                                                             ",
	"                                                             ",
	"                                                             ",
	"                                                             ",
	"                                                             ",
	"                                                             ",
	"                                                             ",
	"                                                             ",
	"                                                             ",
	"                                                             ",
	"                                                             ",
	"                                                             ",
	"                            S                                "
};

////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////
const unsigned char levelData4[levelRows][levelColums+1]=
{
	"                                                             ",
	"       XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX           ",
	"      X                                           X          ",
	"     X   TTTTT      XXXXX       XXXXX      TTTTT   X         ",
	"  XXX    THHHT     X     X     X     X     THHHT    XXX      ",
	" XXXXXX   THHT    X       X   X       X    THHT   XXXXXX     ",
	"  TTT  X   TTT    X X   X X   X X   X X    TTT   X  TTT      ",
	"   T   X          X HH HH X   X HH HH X          X   T       ",
	"       X           X     X     X     X           X           ",
	"       TTTTT   XXX  X   X       X   X  XXX   TTTTT           ",
	"       XX   X X  X   X  X XXXXX  X  X  X  X X   XX           ",
	"      XXXX   T   X   XXXX X   X  XXXX  X   T   XXXX          ",
	"     XXXXXX      X        X   X        X      XXXXXX         ",
	"      TTTT       X       X     X       X       TTTT          ",
	"                  X     X       X     X                      ",
	"                   X   X         X   X                       ",
	"                    TTT           TTT                        ",
	"                                                             ",
	"                                                             ",
	"                                                             ",
	"                                                             ",
	"                                                             ",
	"                                                             ",
	"                                                             ",
	"                                                             ",
	"                                                             ",
	"                                                             ",
	"                                                             ",
	"                                                             ",
	"                                                             ",
	"                                                             ",
	"                                                             ",
	"                                                             ",
	"                                                             ",
	"                                                             ",
	"                                                             ",
	"                                                             ",
	"                             S                               "
};



////////////////////////////////////////////////////////////////////
//Functions
unsigned char GetRenderCellSymbol(unsigned char cellSymbol) {
	switch (cellSymbol)
	{
	case CellSymbol_Ship:                     return 202;
	case CellSymbol_Bullet:                   return 179;
	case CellSymbol_Alien:                    return 2;
	case CellSymbol_Tank:                     return 2;
	case CellSymbol_Heart:                    return 3;
	}
	return '?';
}



ConsoleColor GetRenderCellSymbolColor(unsigned char cellSymbol) {
	switch (cellSymbol) {
	case CellSymbol_Ship:              return ConsoleColor_White;
	case CellSymbol_Bullet:            return ConsoleColor_Red;
	case CellSymbol_Alien:             return ConsoleColor_Green;
	case CellSymbol_Tank:              return ConsoleColor_Gray;
	case CellSymbol_Heart:             return ConsoleColor_DarkRed;
	}
	return ConsoleColor_Gray;
}



ConsoleColor GetRenderCellSymbolBackGroundColor(unsigned char cellSymbol) {
	switch (cellSymbol) {
	case CellSymbol_Ship:            return ConsoleColor_DarkGray;
	}
	return ConsoleColor_Black;
}