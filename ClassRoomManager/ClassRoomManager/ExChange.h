#pragma once
class ExChange
{
public:
	ExChange(void);
	~ExChange(void);
	//����1�봰��2ͨ��
	static long borad;
	static long computer;
	static long ID;
	static long project;
	static long seat;
	static bool FLAG;
	
	//finder������result����ͨ��
	static long FindBorad;
	static long FindComputer;
	static long FindProject;
	static long FindSeat;

	//����
	static void Clean(); 
	static void Set(long ID,long seat,long computer,long borad,long project);
};

