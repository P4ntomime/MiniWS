/*====================================HEADER====================================
*
*		File:		myCharSet.h
*		Author:		Laurin Heitzer
*		Created:	21.09.2019
*		
*		Info:		This file is a charset for the 128x128 OLED Display
*					containing: A,B,C,D,0,1,2,3,4,5,6,7,8,9,.,%
*					more chars can and will be added, but have to be
*					implemented in the switch-case in the CharAtXY() function
*
================================================================================*/


#ifndef MYCHARSET_H_
#define MYCHARSET_H_

#define FG 1		//just for a beter visual

const unsigned char cucA[14][11] = 
{
	{00,00,00,FG,00,00,00,00,00,00,00},
	{00,00,FG,00,FG,00,00,00,00,00,00},
	{00,00,FG,00,FG,00,00,00,00,00,00},
	{00,00,FG,00,FG,00,00,00,00,00,00},
	{00,00,FG,00,FG,00,00,00,00,00,00},
	{00,FG,00,00,00,FG,00,00,00,00,00},
	{00,FG,00,00,00,FG,00,00,00,00,00},
	{00,FG,FG,FG,FG,FG,00,00,00,00,00},
	{00,FG,00,00,00,FG,00,00,00,00,00},
	{FG,00,00,00,00,00,FG,00,00,00,00},
	{FG,00,00,00,00,00,FG,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00}		
};
const unsigned char cucB[14][11] = 
{
	{00,FG,FG,FG,FG,FG,00,00,00,00,00},
	{00,FG,00,00,00,00,FG,00,00,00,00},
	{00,FG,00,00,00,00,FG,00,00,00,00},
	{00,FG,00,00,00,00,FG,00,00,00,00},
	{00,FG,00,00,00,00,FG,00,00,00,00},
	{00,FG,FG,FG,FG,FG,00,00,00,00,00},
	{00,FG,00,00,00,00,FG,00,00,00,00},
	{00,FG,00,00,00,00,FG,00,00,00,00},
	{00,FG,00,00,00,00,FG,00,00,00,00},
	{00,FG,00,00,00,00,FG,00,00,00,00},
	{00,FG,FG,FG,FG,FG,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00}		
};

const unsigned char cucC[14][11] = 
{
	{00,00,00,FG,FG,FG,00,00,00,00,00},
	{00,00,FG,00,00,00,FG,00,00,00,00},
	{00,FG,00,00,00,00,00,FG,00,00,00},
	{00,FG,00,00,00,00,00,00,00,00,00},
	{00,FG,00,00,00,00,00,00,00,00,00},
	{00,FG,00,00,00,00,00,00,00,00,00},
	{00,FG,00,00,00,00,00,00,00,00,00},
	{00,FG,00,00,00,00,00,FG,00,00,00},
	{00,FG,00,00,00,00,00,FG,00,00,00},
	{00,00,FG,00,00,00,FG,00,00,00,00},
	{00,00,00,FG,FG,FG,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00}		
};

const unsigned char cucD[14][11] = 
{
	{00,FG,FG,FG,FG,FG,00,00,00,00,00},
	{00,FG,00,00,00,00,FG,00,00,00,00},
	{00,FG,00,00,00,00,00,FG,00,00,00},
	{00,FG,00,00,00,00,00,FG,00,00,00},
	{00,FG,00,00,00,00,00,FG,00,00,00},
	{00,FG,00,00,00,00,00,FG,00,00,00},
	{00,FG,00,00,00,00,00,FG,00,00,00},
	{00,FG,00,00,00,00,00,FG,00,00,00},
	{00,FG,00,00,00,00,00,FG,00,00,00},
	{00,FG,00,00,00,00,FG,00,00,00,00},
	{00,FG,FG,FG,FG,FG,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00}		
};

const unsigned char cucE[14][11] =
{
	{00,FG,FG,FG,FG,FG,FG,00,00,00,00},
	{00,FG,00,00,00,00,00,00,00,00,00},
	{00,FG,00,00,00,00,00,00,00,00,00},
	{00,FG,00,00,00,00,00,00,00,00,00},
	{00,FG,00,00,00,00,00,00,00,00,00},
	{00,FG,FG,FG,FG,FG,00,00,00,00,00},
	{00,FG,00,00,00,00,00,00,00,00,00},
	{00,FG,00,00,00,00,00,00,00,00,00},
	{00,FG,00,00,00,00,00,00,00,00,00},
	{00,FG,00,00,00,00,00,00,00,00,00},
	{00,FG,FG,FG,FG,FG,FG,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00}
};

const unsigned char cucF[14][11] =
{
	{00,FG,FG,FG,FG,FG,FG,00,00,00,00},
	{00,FG,00,00,00,00,00,00,00,00,00},
	{00,FG,00,00,00,00,00,00,00,00,00},
	{00,FG,00,00,00,00,00,00,00,00,00},
	{00,FG,00,00,00,00,00,00,00,00,00},
	{00,FG,FG,FG,FG,FG,00,00,00,00,00},
	{00,FG,00,00,00,00,00,00,00,00,00},
	{00,FG,00,00,00,00,00,00,00,00,00},
	{00,FG,00,00,00,00,00,00,00,00,00},
	{00,FG,00,00,00,00,00,00,00,00,00},
	{00,FG,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00}
};

const unsigned char cucG[14][11] =
{
	{00,00,00,FG,FG,FG,FG,00,00,00,00},
	{00,00,FG,00,00,00,00,FG,00,00,00},
	{00,FG,00,00,00,00,00,00,FG,00,00},
	{00,FG,00,00,00,00,00,00,00,00,00},
	{00,FG,00,00,00,00,00,00,00,00,00},
	{00,FG,00,00,00,00,00,00,00,00,00},
	{00,FG,00,00,00,FG,FG,FG,FG,00,00},
	{00,FG,00,00,00,00,00,00,FG,00,00},
	{00,FG,00,00,00,00,00,00,FG,00,00},
	{00,00,FG,00,00,00,00,00,FG,00,00},
	{00,00,00,FG,FG,FG,FG,FG,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00}
};

const unsigned char cucH[14][11] =
{
	{00,FG,00,00,00,00,00,FG,00,00,00},
	{00,FG,00,00,00,00,00,FG,00,00,00},
	{00,FG,00,00,00,00,00,FG,00,00,00},
	{00,FG,00,00,00,00,00,FG,00,00,00},
	{00,FG,00,00,00,00,00,FG,00,00,00},
	{00,FG,FG,FG,FG,FG,FG,FG,00,00,00},
	{00,FG,00,00,00,00,00,FG,00,00,00},
	{00,FG,00,00,00,00,00,FG,00,00,00},
	{00,FG,00,00,00,00,00,FG,00,00,00},
	{00,FG,00,00,00,00,00,FG,00,00,00},
	{00,FG,00,00,00,00,00,FG,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00}
};

const unsigned char cucI[14][11] =
{
	{00,FG,00,00,00,00,00,00,00,00,00},
	{00,FG,00,00,00,00,00,00,00,00,00},
	{00,FG,00,00,00,00,00,00,00,00,00},
	{00,FG,00,00,00,00,00,00,00,00,00},
	{00,FG,00,00,00,00,00,00,00,00,00},
	{00,FG,00,00,00,00,00,00,00,00,00},
	{00,FG,00,00,00,00,00,00,00,00,00},
	{00,FG,00,00,00,00,00,00,00,00,00},
	{00,FG,00,00,00,00,00,00,00,00,00},
	{00,FG,00,00,00,00,00,00,00,00,00},
	{00,FG,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00}
};

const unsigned char cucJ[14][11] =
{
	{00,00,00,00,00,FG,00,00,00,00,00},
	{00,00,00,00,00,FG,00,00,00,00,00},
	{00,00,00,00,00,FG,00,00,00,00,00},
	{00,00,00,00,00,FG,00,00,00,00,00},
	{00,00,00,00,00,FG,00,00,00,00,00},
	{00,00,00,00,00,FG,00,00,00,00,00},
	{00,00,00,00,00,FG,00,00,00,00,00},
	{00,00,00,00,00,FG,00,00,00,00,00},
	{00,FG,00,00,00,FG,00,00,00,00,00},
	{00,FG,00,00,00,FG,00,00,00,00,00},
	{00,00,FG,FG,FG,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00}
};

const unsigned char cucK[14][11] =
{
	{00,FG,00,00,00,00,FG,00,00,00,00},
	{00,FG,00,00,00,FG,00,00,00,00,00},
	{00,FG,00,00,FG,00,00,00,00,00,00},
	{00,FG,00,00,FG,00,00,00,00,00,00},
	{00,FG,00,FG,00,00,00,00,00,00,00},
	{00,FG,FG,FG,00,00,00,00,00,00,00},
	{00,FG,00,00,FG,00,00,00,00,00,00},
	{00,FG,00,00,FG,00,00,00,00,00,00},
	{00,FG,00,00,00,FG,00,00,00,00,00},
	{00,FG,00,00,00,FG,00,00,00,00,00},
	{00,FG,00,00,00,00,FG,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00}
};

const unsigned char cucL[14][11] =
{
	{00,FG,00,00,00,00,00,00,00,00,00},
	{00,FG,00,00,00,00,00,00,00,00,00},
	{00,FG,00,00,00,00,00,00,00,00,00},
	{00,FG,00,00,00,00,00,00,00,00,00},
	{00,FG,00,00,00,00,00,00,00,00,00},
	{00,FG,00,00,00,00,00,00,00,00,00},
	{00,FG,00,00,00,00,00,00,00,00,00},
	{00,FG,00,00,00,00,00,00,00,00,00},
	{00,FG,00,00,00,00,00,00,00,00,00},
	{00,FG,00,00,00,00,00,00,00,00,00},
	{00,FG,FG,FG,FG,FG,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00}
};

const unsigned char cucM[14][11] =
{
	{00,FG,00,00,00,00,00,00,00,FG,00},
	{00,FG,FG,00,00,00,00,00,FG,FG,00},
	{00,FG,FG,00,00,00,00,00,FG,FG,00},
	{00,FG,00,FG,00,00,00,FG,00,FG,00},
	{00,FG,00,FG,00,00,00,FG,00,FG,00},
	{00,FG,00,FG,00,00,00,FG,00,FG,00},
	{00,FG,00,00,FG,00,FG,00,00,FG,00},
	{00,FG,00,00,FG,00,FG,00,00,FG,00},
	{00,FG,00,00,FG,00,FG,00,00,FG,00},
	{00,FG,00,00,00,FG,00,00,00,FG,00},
	{00,FG,00,00,00,FG,00,00,00,FG,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00}
};

const unsigned char cucN[14][11] =
{
	{00,FG,00,00,00,00,00,FG,00,00,00},
	{00,FG,FG,00,00,00,00,FG,00,00,00},
	{00,FG,FG,00,00,00,00,FG,00,00,00},
	{00,FG,00,FG,00,00,00,FG,00,00,00},
	{00,FG,00,FG,00,00,00,FG,00,00,00},
	{00,FG,00,00,FG,00,00,FG,00,00,00},
	{00,FG,00,00,FG,00,00,FG,00,00,00},
	{00,FG,00,00,00,FG,00,FG,00,00,00},
	{00,FG,00,00,00,00,FG,FG,00,00,00},
	{00,FG,00,00,00,00,FG,FG,00,00,00},
	{00,FG,00,00,00,00,00,FG,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00}
};

const unsigned char cucO[14][11] =
{
	{00,00,00,FG,FG,FG,FG,00,00,00,00},
	{00,00,FG,00,00,00,00,FG,00,00,00},
	{00,FG,00,00,00,00,00,00,FG,00,00},
	{00,FG,00,00,00,00,00,00,FG,00,00},
	{00,FG,00,00,00,00,00,00,FG,00,00},
	{00,FG,00,00,00,00,00,00,FG,00,00},
	{00,FG,00,00,00,00,00,00,FG,00,00},
	{00,FG,00,00,00,00,00,00,FG,00,00},
	{00,FG,00,00,00,00,00,00,FG,00,00},
	{00,00,FG,00,00,00,00,FG,00,00,00},
	{00,00,00,FG,FG,FG,FG,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00}
};

const unsigned char cucP[14][11] =
{
	{00,FG,FG,FG,FG,FG,00,00,00,00,00},
	{00,FG,00,00,00,00,FG,00,00,00,00},
	{00,FG,00,00,00,00,FG,00,00,00,00},
	{00,FG,00,00,00,00,FG,00,00,00,00},
	{00,FG,00,00,00,00,FG,00,00,00,00},
	{00,FG,FG,FG,FG,FG,00,00,00,00,00},
	{00,FG,00,00,00,00,00,00,00,00,00},
	{00,FG,00,00,00,00,00,00,00,00,00},
	{00,FG,00,00,00,00,00,00,00,00,00},
	{00,FG,00,00,00,00,00,00,00,00,00},
	{00,FG,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00}
};

const unsigned char cucQ[14][11] =
{
	{00,00,00,FG,FG,FG,FG,00,00,00,00},
	{00,00,FG,00,00,00,00,FG,00,00,00},
	{00,FG,00,00,00,00,00,00,FG,00,00},
	{00,FG,00,00,00,00,00,00,FG,00,00},
	{00,FG,00,00,00,00,00,00,FG,00,00},
	{00,FG,00,00,00,00,00,00,FG,00,00},
	{00,FG,00,00,00,00,00,00,FG,00,00},
	{00,FG,00,00,00,00,00,00,FG,00,00},
	{00,FG,00,00,00,FG,00,FG,FG,00,00},
	{00,00,FG,00,00,00,FG,FG,00,00,00},
	{00,00,00,FG,FG,FG,00,00,FG,00,00},
	{00,00,00,00,00,00,00,00,FG,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00}
};

const unsigned char cucR[14][11] =
{
	{00,FG,FG,FG,FG,FG,FG,00,00,00,00},
	{00,FG,00,00,00,00,00,FG,00,00,00},
	{00,FG,00,00,00,00,00,FG,00,00,00},
	{00,FG,00,00,00,00,00,FG,00,00,00},
	{00,FG,00,00,00,00,00,FG,00,00,00},
	{00,FG,FG,FG,FG,FG,FG,00,00,00,00},
	{00,FG,00,00,00,FG,00,00,00,00,00},
	{00,FG,00,00,00,00,FG,00,00,00,00},
	{00,FG,00,00,00,00,FG,FG,00,00,00},
	{00,FG,00,00,00,00,00,FG,00,00,00},
	{00,FG,00,00,00,00,00,00,FG,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00}
};

const unsigned char cucS[14][11] =
{
	{00,00,FG,FG,FG,FG,00,00,00,00,00},
	{00,FG,00,00,00,00,FG,00,00,00,00},
	{00,FG,00,00,00,00,FG,00,00,00,00},
	{00,FG,00,00,00,00,00,00,00,00,00},
	{00,00,FG,00,00,00,00,00,00,00,00},
	{00,00,00,FG,FG,FG,00,00,00,00,00},
	{00,00,00,00,00,00,FG,00,00,00,00},
	{00,FG,00,00,00,00,FG,00,00,00,00},
	{00,FG,00,00,00,00,FG,00,00,00,00},
	{00,FG,00,00,00,00,FG,00,00,00,00},
	{00,00,FG,FG,FG,FG,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00}
};

const unsigned char cucT[14][11] =
{
	{00,FG,FG,FG,FG,FG,FG,FG,00,00,00},
	{00,00,00,00,FG,00,00,00,00,00,00},
	{00,00,00,00,FG,00,00,00,00,00,00},
	{00,00,00,00,FG,00,00,00,00,00,00},
	{00,00,00,00,FG,00,00,00,00,00,00},
	{00,00,00,00,FG,00,00,00,00,00,00},
	{00,00,00,00,FG,00,00,00,00,00,00},
	{00,00,00,00,FG,00,00,00,00,00,00},
	{00,00,00,00,FG,00,00,00,00,00,00},
	{00,00,00,00,FG,00,00,00,00,00,00},
	{00,00,00,00,FG,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00}
};

const unsigned char cucU[14][11] =
{
	{00,FG,00,00,00,00,00,FG,00,00,00},
	{00,FG,00,00,00,00,00,FG,00,00,00},
	{00,FG,00,00,00,00,00,FG,00,00,00},
	{00,FG,00,00,00,00,00,FG,00,00,00},
	{00,FG,00,00,00,00,00,FG,00,00,00},
	{00,FG,00,00,00,00,00,FG,00,00,00},
	{00,FG,00,00,00,00,00,FG,00,00,00},
	{00,FG,00,00,00,00,00,FG,00,00,00},
	{00,FG,00,00,00,00,00,FG,00,00,00},
	{00,00,FG,00,00,00,FG,00,00,00,00},
	{00,00,00,FG,FG,FG,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00}
};

const unsigned char cucV[14][11] =
{
	{00,FG,00,00,00,00,00,FG,00,00,00},
	{00,FG,00,00,00,00,00,FG,00,00,00},
	{00,00,FG,00,00,00,FG,00,00,00,00},
	{00,00,FG,00,00,00,FG,00,00,00,00},
	{00,00,FG,00,00,00,FG,00,00,00,00},
	{00,00,FG,00,00,00,FG,00,00,00,00},
	{00,00,00,FG,00,FG,00,00,00,00,00},
	{00,00,00,FG,00,FG,00,00,00,00,00},
	{00,00,00,FG,00,FG,00,00,00,00,00},
	{00,00,00,FG,00,FG,00,00,00,00,00},
	{00,00,00,00,FG,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00}
};

const unsigned char cucW[14][11] =
{
	{FG,00,00,00,00,FG,00,00,00,00,FG},
	{FG,00,00,00,FG,00,FG,00,00,00,FG},
	{FG,00,00,00,FG,00,FG,00,00,00,FG},
	{00,FG,00,00,FG,00,FG,00,00,FG,00},
	{00,FG,00,00,FG,00,FG,00,00,FG,00},
	{00,FG,00,FG,00,00,00,FG,00,FG,00},
	{00,FG,00,FG,00,00,00,FG,00,FG,00},
	{00,FG,00,FG,00,00,00,FG,00,FG,00},
	{00,FG,00,FG,00,00,00,FG,00,FG,00},
	{00,00,FG,00,00,00,00,00,FG,00,00},
	{00,00,FG,00,00,00,00,00,FG,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00}
};

const unsigned char cucX[14][11] =
{
	{FG,00,00,00,00,00,00,FG,00,00,00},
	{00,FG,00,00,00,00,FG,00,00,00,00},
	{00,00,FG,00,00,FG,00,00,00,00,00},
	{00,00,FG,00,00,FG,00,00,00,00,00},
	{00,00,00,FG,FG,00,00,00,00,00,00},
	{00,00,00,FG,00,00,00,00,00,00,00},
	{00,00,00,FG,FG,00,00,00,00,00,00},
	{00,00,FG,00,00,FG,00,00,00,00,00},
	{00,00,FG,00,00,FG,00,00,00,00,00},
	{00,FG,00,00,00,00,FG,00,00,00,00},
	{FG,00,00,00,00,00,00,FG,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00}
};

const unsigned char cucY[14][11] =
{
	{FG,00,00,00,00,00,FG,00,00,00,00},
	{00,FG,00,00,00,FG,00,00,00,00,00},
	{00,FG,00,00,00,FG,00,00,00,00,00},
	{00,00,FG,00,FG,00,00,00,00,00,00},
	{00,00,FG,00,FG,00,00,00,00,00,00},
	{00,00,00,FG,00,00,00,00,00,00,00},
	{00,00,00,FG,00,00,00,00,00,00,00},
	{00,00,00,FG,00,00,00,00,00,00,00},
	{00,00,00,FG,00,00,00,00,00,00,00},
	{00,00,00,FG,00,00,00,00,00,00,00},
	{00,00,00,FG,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00}
};

const unsigned char cucZ[14][11] =
{
	{FG,FG,FG,FG,FG,FG,FG,00,00,00,00},
	{00,00,00,00,00,00,FG,00,00,00,00},
	{00,00,00,00,00,FG,00,00,00,00,00},
	{00,00,00,00,FG,00,00,00,00,00,00},
	{00,00,00,00,FG,00,00,00,00,00,00},
	{00,00,00,FG,00,00,00,00,00,00,00},
	{00,00,FG,00,00,00,00,00,00,00,00},
	{00,00,FG,00,00,00,00,00,00,00,00},
	{00,FG,00,00,00,00,00,00,00,00,00},
	{FG,00,00,00,00,00,00,00,00,00,00},
	{FG,FG,FG,FG,FG,FG,FG,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00}
};

const unsigned char cuca[14][11] =
{
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,FG,FG,FG,00,00,00,00,00,00},
	{00,FG,00,00,00,FG,00,00,00,00,00},
	{00,00,00,00,FG,FG,00,00,00,00,00},
	{00,00,FG,FG,00,FG,00,00,00,00,00},
	{00,FG,00,00,00,FG,00,00,00,00,00},
	{00,FG,00,00,00,FG,00,00,00,00,00},
	{00,FG,00,00,FG,FG,00,00,00,00,00},
	{00,00,FG,FG,00,FG,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00}
};

const unsigned char cucb[14][11] =
{
	{00,FG,00,00,00,00,00,00,00,00,00},
	{00,FG,00,00,00,00,00,00,00,00,00},
	{00,FG,00,00,00,00,00,00,00,00,00},
	{00,FG,00,FG,FG,00,00,00,00,00,00},
	{00,FG,FG,00,00,FG,00,00,00,00,00},
	{00,FG,00,00,00,FG,00,00,00,00,00},
	{00,FG,00,00,00,FG,00,00,00,00,00},
	{00,FG,00,00,00,FG,00,00,00,00,00},
	{00,FG,00,00,00,FG,00,00,00,00,00},
	{00,FG,FG,00,00,FG,00,00,00,00,00},
	{00,FG,00,FG,FG,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00}
};

const unsigned char cucc[14][11] =
{
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,FG,FG,FG,00,00,00,00,00,00},
	{00,FG,00,00,00,FG,00,00,00,00,00},
	{00,FG,00,00,00,00,00,00,00,00,00},
	{00,FG,00,00,00,00,00,00,00,00,00},
	{00,FG,00,00,00,00,00,00,00,00,00},
	{00,FG,00,00,00,FG,00,00,00,00,00},
	{00,FG,00,00,00,FG,00,00,00,00,00},
	{00,00,FG,FG,FG,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00}
};

const unsigned char cucd[14][11] =
{
	{00,00,00,00,00,FG,00,00,00,00,00},
	{00,00,00,00,00,FG,00,00,00,00,00},
	{00,00,00,00,00,FG,00,00,00,00,00},
	{00,00,FG,FG,00,FG,00,00,00,00,00},
	{00,FG,00,00,FG,FG,00,00,00,00,00},
	{00,FG,00,00,00,FG,00,00,00,00,00},
	{00,FG,00,00,00,FG,00,00,00,00,00},
	{00,FG,00,00,00,FG,00,00,00,00,00},
	{00,FG,00,00,00,FG,00,00,00,00,00},
	{00,FG,00,00,FG,FG,00,00,00,00,00},
	{00,00,FG,FG,00,FG,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00}
};

const unsigned char cuce[14][11] =
{
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,FG,FG,FG,00,00,00,00,00,00},
	{00,FG,00,00,00,FG,00,00,00,00,00},
	{00,FG,00,00,00,FG,00,00,00,00,00},
	{00,FG,FG,FG,FG,FG,00,00,00,00,00},
	{00,FG,00,00,00,00,00,00,00,00,00},
	{00,FG,00,00,00,00,00,00,00,00,00},
	{00,FG,00,00,00,FG,00,00,00,00,00},
	{00,00,FG,FG,FG,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00}
};

const unsigned char cucf[14][11] =
{
	{00,FG,FG,00,00,00,00,00,00,00,00},
	{00,FG,00,00,00,00,00,00,00,00,00},
	{00,FG,00,00,00,00,00,00,00,00,00},
	{FG,FG,FG,00,00,00,00,00,00,00,00},
	{00,FG,00,00,00,00,00,00,00,00,00},
	{00,FG,00,00,00,00,00,00,00,00,00},
	{00,FG,00,00,00,00,00,00,00,00,00},
	{00,FG,00,00,00,00,00,00,00,00,00},
	{00,FG,00,00,00,00,00,00,00,00,00},
	{00,FG,00,00,00,00,00,00,00,00,00},
	{00,FG,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00}
};

const unsigned char cucg[14][11] =
{
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,FG,FG,00,FG,00,00,00,00,00},
	{00,FG,00,00,FG,FG,00,00,00,00,00},
	{00,FG,00,00,00,FG,00,00,00,00,00},
	{00,FG,00,00,00,FG,00,00,00,00,00},
	{00,FG,00,00,00,FG,00,00,00,00,00},
	{00,FG,00,00,00,FG,00,00,00,00,00},
	{00,FG,00,00,FG,FG,00,00,00,00,00},
	{00,00,FG,FG,00,FG,00,00,00,00,00},
	{00,00,00,00,00,FG,00,00,00,00,00},
	{00,FG,00,00,00,FG,00,00,00,00,00},
	{00,00,FG,FG,FG,00,00,00,00,00,00}
};

const unsigned char cuch[14][11] =
{
	{00,FG,00,00,00,00,00,00,00,00,00},
	{00,FG,00,00,00,00,00,00,00,00,00},
	{00,FG,00,00,00,00,00,00,00,00,00},
	{00,FG,00,FG,FG,00,00,00,00,00,00},
	{00,FG,FG,00,00,FG,00,00,00,00,00},
	{00,FG,00,00,00,FG,00,00,00,00,00},
	{00,FG,00,00,00,FG,00,00,00,00,00},
	{00,FG,00,00,00,FG,00,00,00,00,00},
	{00,FG,00,00,00,FG,00,00,00,00,00},
	{00,FG,00,00,00,FG,00,00,00,00,00},
	{00,FG,00,00,00,FG,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00}
};

const unsigned char cuci[14][11] =
{
	{00,FG,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,FG,00,00,00,00,00,00,00,00,00},
	{00,FG,00,00,00,00,00,00,00,00,00},
	{00,FG,00,00,00,00,00,00,00,00,00},
	{00,FG,00,00,00,00,00,00,00,00,00},
	{00,FG,00,00,00,00,00,00,00,00,00},
	{00,FG,00,00,00,00,00,00,00,00,00},
	{00,FG,00,00,00,00,00,00,00,00,00},
	{00,FG,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00}
};

const unsigned char cucj[14][11] =
{
	{00,FG,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,FG,00,00,00,00,00,00,00,00,00},
	{00,FG,00,00,00,00,00,00,00,00,00},
	{00,FG,00,00,00,00,00,00,00,00,00},
	{00,FG,00,00,00,00,00,00,00,00,00},
	{00,FG,00,00,00,00,00,00,00,00,00},
	{00,FG,00,00,00,00,00,00,00,00,00},
	{00,FG,00,00,00,00,00,00,00,00,00},
	{00,FG,00,00,00,00,00,00,00,00,00},
	{00,FG,00,00,00,00,00,00,00,00,00},
	{00,FG,00,00,00,00,00,00,00,00,00},
	{FG,FG,00,00,00,00,00,00,00,00,00}
};

const unsigned char cuck[14][11] =
{
	{00,FG,00,00,00,00,00,00,00,00,00},
	{00,FG,00,00,00,00,00,00,00,00,00},
	{00,FG,00,00,00,00,00,00,00,00,00},
	{00,FG,00,00,00,FG,00,00,00,00,00},
	{00,FG,00,00,FG,00,00,00,00,00,00},
	{00,FG,00,FG,00,00,00,00,00,00,00},
	{00,FG,FG,FG,00,00,00,00,00,00,00},
	{00,FG,00,FG,00,00,00,00,00,00,00},
	{00,FG,00,00,FG,00,00,00,00,00,00},
	{00,FG,00,00,00,FG,00,00,00,00,00},
	{00,FG,00,00,00,FG,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00}
};

const unsigned char cucl[14][11] =
{
	{00,FG,00,00,00,00,00,00,00,00,00},
	{00,FG,00,00,00,00,00,00,00,00,00},
	{00,FG,00,00,00,00,00,00,00,00,00},
	{00,FG,00,00,00,00,00,00,00,00,00},
	{00,FG,00,00,00,00,00,00,00,00,00},
	{00,FG,00,00,00,00,00,00,00,00,00},
	{00,FG,00,00,00,00,00,00,00,00,00},
	{00,FG,00,00,00,00,00,00,00,00,00},
	{00,FG,00,00,00,00,00,00,00,00,00},
	{00,FG,00,00,00,00,00,00,00,00,00},
	{00,FG,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00}
};

const unsigned char cucm[14][11] =
{
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,FG,00,FG,FG,00,FG,FG,FG,00,00},
	{00,FG,FG,00,00,FG,FG,00,00,FG,00},
	{00,FG,00,00,00,FG,00,00,00,FG,00},
	{00,FG,00,00,00,FG,00,00,00,FG,00},
	{00,FG,00,00,00,FG,00,00,00,FG,00},
	{00,FG,00,00,00,FG,00,00,00,FG,00},
	{00,FG,00,00,00,FG,00,00,00,FG,00},
	{00,FG,00,00,00,FG,00,00,00,FG,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00}
};

const unsigned char cucn[14][11] =
{
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,FG,00,FG,FG,00,00,00,00,00,00},
	{00,FG,FG,00,00,FG,00,00,00,00,00},
	{00,FG,00,00,00,FG,00,00,00,00,00},
	{00,FG,00,00,00,FG,00,00,00,00,00},
	{00,FG,00,00,00,FG,00,00,00,00,00},
	{00,FG,00,00,00,FG,00,00,00,00,00},
	{00,FG,00,00,00,FG,00,00,00,00,00},
	{00,FG,00,00,00,FG,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00}
};

const unsigned char cuco[14][11] =
{
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,FG,FG,FG,00,00,00,00,00,00},
	{00,FG,00,00,00,FG,00,00,00,00,00},
	{00,FG,00,00,00,FG,00,00,00,00,00},
	{00,FG,00,00,00,FG,00,00,00,00,00},
	{00,FG,00,00,00,FG,00,00,00,00,00},
	{00,FG,00,00,00,FG,00,00,00,00,00},
	{00,FG,00,00,00,FG,00,00,00,00,00},
	{00,00,FG,FG,FG,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00}
};

const unsigned char cucp[14][11] =
{
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,FG,00,FG,FG,00,00,00,00,00,00},
	{00,FG,FG,00,00,FG,00,00,00,00,00},
	{00,FG,00,00,00,FG,00,00,00,00,00},
	{00,FG,00,00,00,FG,00,00,00,00,00},
	{00,FG,00,00,00,FG,00,00,00,00,00},
	{00,FG,00,00,00,FG,00,00,00,00,00},
	{00,FG,FG,00,00,FG,00,00,00,00,00},
	{00,FG,00,FG,FG,00,00,00,00,00,00},
	{00,FG,00,00,00,00,00,00,00,00,00},
	{00,FG,00,00,00,00,00,00,00,00,00},
	{00,FG,00,00,00,00,00,00,00,00,00}
};

const unsigned char cucq[14][11] =
{
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,FG,FG,00,FG,00,00,00,00,00},
	{00,FG,00,00,FG,FG,00,00,00,00,00},
	{00,FG,00,00,00,FG,00,00,00,00,00},
	{00,FG,00,00,00,FG,00,00,00,00,00},
	{00,FG,00,00,00,FG,00,00,00,00,00},
	{00,FG,00,00,00,FG,00,00,00,00,00},
	{00,FG,00,00,FG,FG,00,00,00,00,00},
	{00,00,FG,FG,00,FG,00,00,00,00,00},
	{00,00,00,00,00,FG,00,00,00,00,00},
	{00,00,00,00,00,FG,00,00,00,00,00},
	{00,00,00,00,00,FG,00,00,00,00,00}
};

const unsigned char cucr[14][11] =
{
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,FG,00,FG,FG,FG,00,00,00,00,00},
	{00,FG,FG,00,00,00,00,00,00,00,00},
	{00,FG,00,00,00,00,00,00,00,00,00},
	{00,FG,00,00,00,00,00,00,00,00,00},
	{00,FG,00,00,00,00,00,00,00,00,00},
	{00,FG,00,00,00,00,00,00,00,00,00},
	{00,FG,00,00,00,00,00,00,00,00,00},
	{00,FG,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00}
};

const unsigned char cucs[14][11] =
{
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,FG,FG,FG,00,00,00,00,00,00,00},
	{FG,00,00,00,FG,00,00,00,00,00,00},
	{FG,00,00,00,00,00,00,00,00,00,00},
	{00,FG,FG,FG,00,00,00,00,00,00,00},
	{00,00,00,00,FG,00,00,00,00,00,00},
	{00,00,00,00,FG,00,00,00,00,00,00},
	{FG,00,00,00,FG,00,00,00,00,00,00},
	{00,FG,FG,FG,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00}
};

const unsigned char cuct[14][11] =
{
	{00,FG,00,00,00,00,00,00,00,00,00},
	{00,FG,00,00,00,00,00,00,00,00,00},
	{00,FG,00,00,00,00,00,00,00,00,00},
	{FG,FG,FG,00,00,00,00,00,00,00,00},
	{00,FG,00,00,00,00,00,00,00,00,00},
	{00,FG,00,00,00,00,00,00,00,00,00},
	{00,FG,00,00,00,00,00,00,00,00,00},
	{00,FG,00,00,00,00,00,00,00,00,00},
	{00,FG,00,00,00,00,00,00,00,00,00},
	{00,FG,00,00,00,00,00,00,00,00,00},
	{00,FG,FG,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00}
};

const unsigned char cucu[14][11] =
{
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,FG,00,00,00,FG,00,00,00,00,00},
	{00,FG,00,00,00,FG,00,00,00,00,00},
	{00,FG,00,00,00,FG,00,00,00,00,00},
	{00,FG,00,00,00,FG,00,00,00,00,00},
	{00,FG,00,00,00,FG,00,00,00,00,00},
	{00,FG,00,00,00,FG,00,00,00,00,00},
	{00,FG,00,00,FG,FG,00,00,00,00,00},
	{00,00,FG,FG,00,FG,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00}
};

const unsigned char cucv[14][11] =
{
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{FG,00,00,00,FG,00,00,00,00,00,00},
	{FG,00,00,00,FG,00,00,00,00,00,00},
	{00,FG,00,FG,00,00,00,00,00,00,00},
	{00,FG,00,FG,00,00,00,00,00,00,00},
	{00,FG,00,FG,00,00,00,00,00,00,00},
	{00,FG,00,FG,00,00,00,00,00,00,00},
	{00,FG,00,FG,00,00,00,00,00,00,00},
	{00,00,FG,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00}
};

const unsigned char cucw[14][11] =
{
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{FG,00,00,00,FG,00,00,00,FG,00,00},
	{FG,00,00,00,FG,00,00,00,FG,00,00},
	{00,FG,00,FG,00,FG,00,FG,00,00,00},
	{00,FG,00,FG,00,FG,00,FG,00,00,00},
	{00,FG,00,FG,00,FG,00,FG,00,00,00},
	{00,FG,00,FG,00,FG,00,FG,00,00,00},
	{00,00,FG,00,00,00,FG,00,00,00,00},
	{00,00,FG,00,00,00,FG,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00}
};

const unsigned char cucx[14][11] =
{
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{FG,00,00,00,00,FG,00,00,00,00,00},
	{00,FG,00,00,FG,00,00,00,00,00,00},
	{00,FG,00,00,FG,00,00,00,00,00,00},
	{00,00,FG,FG,00,00,00,00,00,00,00},
	{00,00,FG,FG,00,00,00,00,00,00,00},
	{00,FG,00,00,FG,00,00,00,00,00,00},
	{00,FG,00,00,FG,00,00,00,00,00,00},
	{FG,00,00,00,00,FG,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00}
};

const unsigned char cucy[14][11] =
{
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{FG,00,00,00,FG,00,00,00,00,00,00},
	{FG,00,00,00,FG,00,00,00,00,00,00},
	{00,FG,00,FG,00,00,00,00,00,00,00},
	{00,FG,00,FG,00,00,00,00,00,00,00},
	{00,FG,00,FG,00,00,00,00,00,00,00},
	{00,FG,00,FG,00,00,00,00,00,00,00},
	{00,00,FG,00,00,00,00,00,00,00,00},
	{00,00,FG,00,00,00,00,00,00,00,00},
	{00,00,FG,00,00,00,00,00,00,00,00},
	{00,00,FG,00,00,00,00,00,00,00,00},
	{FG,FG,00,00,00,00,00,00,00,00,00}
};

const unsigned char cucz[14][11] =
{
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{FG,FG,FG,FG,FG,00,00,00,00,00,00},
	{00,00,00,00,FG,00,00,00,00,00,00},
	{00,00,00,FG,00,00,00,00,00,00,00},
	{00,00,FG,00,00,00,00,00,00,00,00},
	{00,00,FG,00,00,00,00,00,00,00,00},
	{00,FG,00,00,00,00,00,00,00,00,00},
	{FG,00,00,00,00,00,00,00,00,00,00},
	{FG,FG,FG,FG,FG,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00}
};

const unsigned char cuc0[14][11] = 
{
	{00,00,FG,FG,00,00,00,00,00,00,00},
	{00,FG,00,00,FG,00,00,00,00,00,00},
	{FG,00,00,00,00,FG,00,00,00,00,00},
	{FG,00,00,00,00,FG,00,00,00,00,00},
	{FG,00,00,00,00,FG,00,00,00,00,00},
	{FG,00,00,00,00,FG,00,00,00,00,00},
	{FG,00,00,00,00,FG,00,00,00,00,00},
	{FG,00,00,00,00,FG,00,00,00,00,00},
	{FG,00,00,00,00,FG,00,00,00,00,00},
	{00,FG,00,00,FG,00,00,00,00,00,00},
	{00,00,FG,FG,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00}		
};
const unsigned char cuc1[14][11] = 
{
	{00,00,00,FG,00,00,00,00,00,00,00},
	{00,00,00,FG,00,00,00,00,00,00,00},
	{00,00,FG,FG,00,00,00,00,00,00,00},
	{00,FG,00,FG,00,00,00,00,00,00,00},
	{00,00,00,FG,00,00,00,00,00,00,00},
	{00,00,00,FG,00,00,00,00,00,00,00},
	{00,00,00,FG,00,00,00,00,00,00,00},
	{00,00,00,FG,00,00,00,00,00,00,00},
	{00,00,00,FG,00,00,00,00,00,00,00},
	{00,00,00,FG,00,00,00,00,00,00,00},
	{00,00,00,FG,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00}		
};
const unsigned char cuc2[14][11] = 
{
	{00,00,FG,FG,00,00,00,00,00,00,00},
	{00,FG,00,00,FG,00,00,00,00,00,00},
	{FG,00,00,00,00,FG,00,00,00,00,00},
	{00,00,00,00,00,FG,00,00,00,00,00},
	{00,00,00,00,00,FG,00,00,00,00,00},
	{00,00,00,00,FG,00,00,00,00,00,00},
	{00,00,00,FG,00,00,00,00,00,00,00},
	{00,00,FG,00,00,00,00,00,00,00,00},
	{00,FG,00,00,00,00,00,00,00,00,00},
	{FG,00,00,00,00,00,00,00,00,00,00},
	{FG,FG,FG,FG,FG,FG,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00}	
};
const unsigned char cuc3[14][11] = 
{
	{00,FG,FG,FG,00,00,00,00,00,00,00},
	{FG,00,00,00,FG,00,00,00,00,00,00},
	{FG,00,00,00,00,FG,00,00,00,00,00},
	{00,00,00,00,00,FG,00,00,00,00,00},
	{00,00,00,00,FG,00,00,00,00,00,00},
	{00,00,FG,FG,00,00,00,00,00,00,00},
	{00,00,00,00,FG,00,00,00,00,00,00},
	{00,00,00,00,00,FG,00,00,00,00,00},
	{FG,00,00,00,00,FG,00,00,00,00,00},
	{FG,00,00,00,FG,00,00,00,00,00,00},
	{00,FG,FG,FG,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00}	
};
const unsigned char cuc4[14][11] = 
{
	{00,00,00,00,FG,00,00,00,00,00,00},
	{00,00,00,FG,FG,00,00,00,00,00,00},
	{00,00,00,FG,FG,00,00,00,00,00,00},
	{00,00,FG,00,FG,00,00,00,00,00,00},
	{00,00,FG,00,FG,00,00,00,00,00,00},
	{00,FG,00,00,FG,00,00,00,00,00,00},
	{FG,00,00,00,FG,00,00,00,00,00,00},
	{FG,FG,FG,FG,FG,FG,00,00,00,00,00},
	{00,00,00,00,FG,00,00,00,00,00,00},
	{00,00,00,00,FG,00,00,00,00,00,00},
	{00,00,00,00,FG,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00}		
};
const unsigned char cuc5[14][11] = 
{
	{00,FG,FG,FG,FG,FG,00,00,00,00,00},
	{00,FG,00,00,00,00,00,00,00,00,00},
	{00,FG,00,00,00,00,00,00,00,00,00},
	{FG,00,00,00,00,00,00,00,00,00,00},
	{FG,00,FG,FG,00,00,00,00,00,00,00},
	{FG,FG,00,00,FG,00,00,00,00,00,00},
	{00,00,00,00,00,FG,00,00,00,00,00},
	{00,00,00,00,00,FG,00,00,00,00,00},
	{FG,00,00,00,00,FG,00,00,00,00,00},
	{FG,00,00,00,FG,00,00,00,00,00,00},
	{00,FG,FG,FG,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00}		
};
const unsigned char cuc6[14][11] = 
{
	{00,00,FG,FG,FG,00,00,00,00,00,00},
	{00,FG,00,00,00,FG,00,00,00,00,00},
	{FG,00,00,00,00,FG,00,00,00,00,00},
	{FG,00,00,00,00,00,00,00,00,00,00},
	{FG,00,FG,FG,00,00,00,00,00,00,00},
	{FG,FG,00,00,FG,00,00,00,00,00,00},
	{FG,00,00,00,00,FG,00,00,00,00,00},
	{FG,00,00,00,00,FG,00,00,00,00,00},
	{FG,00,00,00,00,FG,00,00,00,00,00},
	{00,FG,00,00,FG,00,00,00,00,00,00},
	{00,00,FG,FG,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00}	
};
const unsigned char cuc7[14][11] = 
{
	{FG,FG,FG,FG,FG,FG,00,00,00,00,00},
	{00,00,00,00,00,FG,00,00,00,00,00},
	{00,00,00,00,FG,00,00,00,00,00,00},
	{00,00,00,FG,00,00,00,00,00,00,00},
	{00,00,00,FG,00,00,00,00,00,00,00},
	{00,00,FG,00,00,00,00,00,00,00,00},
	{00,00,FG,00,00,00,00,00,00,00,00},
	{00,00,FG,00,00,00,00,00,00,00,00},
	{00,FG,00,00,00,00,00,00,00,00,00},
	{00,FG,00,00,00,00,00,00,00,00,00},
	{00,FG,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00}		
};
const unsigned char cuc8[14][11] = 
{
	{00,00,FG,FG,00,00,00,00,00,00,00},
	{00,FG,00,00,FG,00,00,00,00,00,00},
	{FG,00,00,00,00,FG,00,00,00,00,00},
	{FG,00,00,00,00,FG,00,00,00,00,00},
	{00,FG,00,00,FG,00,00,00,00,00,00},
	{00,00,FG,FG,00,00,00,00,00,00,00},
	{00,FG,00,00,FG,00,00,00,00,00,00},
	{FG,00,00,00,00,FG,00,00,00,00,00},
	{FG,00,00,00,00,FG,00,00,00,00,00},
	{00,FG,00,00,FG,00,00,00,00,00,00},
	{00,00,FG,FG,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00}		
};
const unsigned char cuc9[14][11] = 
{
	{00,00,FG,FG,00,00,00,00,00,00,00},
	{00,FG,00,00,FG,00,00,00,00,00,00},
	{FG,00,00,00,00,FG,00,00,00,00,00},
	{FG,00,00,00,00,FG,00,00,00,00,00},
	{FG,00,00,00,00,FG,00,00,00,00,00},
	{00,FG,00,00,FG,FG,00,00,00,00,00},
	{00,00,FG,FG,00,FG,00,00,00,00,00},
	{00,00,00,00,00,FG,00,00,00,00,00},
	{FG,00,00,00,00,FG,00,00,00,00,00},
	{00,FG,00,00,FG,00,00,00,00,00,00},
	{00,00,FG,FG,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00}		
};

const unsigned char cucDeg[14][11] = 
{
	{00,00,FG,FG,00,00,00,00,00,00,00},
	{00,FG,00,00,FG,00,00,00,00,00,00},
	{00,FG,00,00,FG,00,00,00,00,00,00},
	{00,00,FG,FG,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00}		
};

const unsigned char cucPC[14][11] = 
{
	{00,FG,FG,00,00,00,00,FG,00,00,00},
	{FG,00,00,FG,00,00,FG,00,00,00,00},
	{FG,00,00,FG,00,00,FG,00,00,00,00},
	{FG,00,00,FG,00,FG,00,00,00,00,00},
	{FG,00,00,FG,00,FG,00,00,00,00,00},
	{00,FG,FG,00,00,FG,00,FG,FG,00,00},
	{00,00,00,00,FG,00,FG,00,00,FG,00},
	{00,00,00,00,FG,00,FG,00,00,FG,00},
	{00,00,00,FG,00,00,FG,00,00,FG,00},
	{00,00,00,FG,00,00,FG,00,00,FG,00},
	{00,00,FG,00,00,00,00,FG,FG,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00}		
};

const unsigned char cucDot[14][11] = 
{
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{FG,FG,00,00,00,00,00,00,00,00,00},
	{FG,FG,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00},
	{00,00,00,00,00,00,00,00,00,00,00}		
};

const unsigned char cucTest[14][11] = 
{
	{FG,FG,FG,FG,FG,FG,FG,FG,FG,FG,FG},
	{FG,FG,FG,FG,FG,FG,FG,FG,FG,FG,FG},
	{FG,FG,FG,FG,FG,FG,FG,FG,FG,FG,FG},
	{FG,FG,FG,FG,FG,FG,FG,FG,FG,FG,FG},
	{FG,FG,FG,FG,FG,FG,FG,FG,FG,FG,FG},
	{FG,FG,FG,FG,FG,FG,FG,FG,FG,FG,FG},
	{FG,FG,FG,FG,FG,FG,FG,FG,FG,FG,FG},
	{FG,FG,FG,FG,FG,FG,FG,FG,FG,FG,FG},
	{FG,FG,FG,FG,FG,FG,FG,FG,FG,FG,FG},
	{FG,FG,FG,FG,FG,FG,FG,FG,FG,FG,FG},
	{FG,FG,FG,FG,FG,FG,FG,FG,FG,FG,FG},
	{FG,FG,FG,FG,FG,FG,FG,FG,FG,FG,FG},
	{FG,FG,FG,FG,FG,FG,FG,FG,FG,FG,FG},
	{FG,FG,FG,FG,FG,FG,FG,FG,FG,FG,FG}		
};

#endif