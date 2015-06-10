#pragma once
class ExChange
{
public:
	ExChange(void);
	~ExChange(void);
	//窗口1与窗口2通信
	static long borad;
	static long computer;
	static long ID;
	static long project;
	static long seat;
	static bool FLAG;
	
	//finder窗口与result窗口通信
	static long FindBorad;
	static long FindComputer;
	static long FindProject;
	static long FindSeat;

	//方法
	static void Clean(); 
	static void Set(long ID,long seat,long computer,long borad,long project);
};

