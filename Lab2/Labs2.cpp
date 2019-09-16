#include "Lab2.h"
#include <iomanip>

using namespace std;
namespace lab2
{
	void PrintIntegers(std::istream& in, std::ostream& out)
	{
		int num;
		string trash;
		out << right;
		out << setw(13) << setfill(' ') << "oct" << setw(11) << "dec" << setw(8) << "hex" << endl << setfill('-');
		out << setw(13) << ' ' << setw(11) << ' ' << setw(8) << "" << endl << setfill(' ');
		
		while (!in.eof())
		{
			in >> num;
			if (in.fail())
			{
				in.clear();
				in >> trash;
			}
			else
				out << setw(12) << oct << num << setw(11) << dec << num << setw(8) << uppercase << hex << num << endl;
		}
		in.clear();
	}

	void PrintMaxFloat(std::istream& in, std::ostream& out)
	{
		//주의: -값이 단 하나 들어 있을 경우에는 해당 값이 최대 값
		float num, max = LLONG_MIN; 
		string trash;
		int leftColumn = 5;
		int rightColumn = 15;
		out << right << fixed << setprecision(3) << showpos << internal;

		while (!in.eof())
		{
			in >> num;
			num > max ? max = num : max = max;
			if (in.fail())
			{
				in.clear();
				in >> trash;
			}
			else
				out << setw(leftColumn) << setfill(' ') << "" << setw(rightColumn) << num << endl;
		}
		in.clear();
		out << setw(leftColumn) << setfill(' ') << "max: " << setw(rightColumn) << max << endl;
	}
}