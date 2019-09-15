#include "Lab2.h"
#include <iomanip>

using namespace std;
namespace lab2
{
	void PrintIntegers(std::istream& in, std::ostream& out)
	{
		int num;
		string trash;
		int column = 12;
		out << right;
		out << setw(column) << setfill(' ') << "oct" << setw(column) << "dec" << setw(column) << "hex" << endl << setfill('-');
		out << setw(column) << ' ' << setw(column) << ' ' << setw(column) << ' ' << endl << setfill(' ');
		
		while (!in.eof())
		{
			in >> num;
			if (in.fail())
			{
				in.clear();
				in >> trash;
			}
			else
				out << setw(column) << oct << num << setw(column) << dec << num << setw(column) << uppercase << hex << num << endl;
		}
		in.clear();
	}

	void PrintMaxFloat(std::istream& in, std::ostream& out)
	{
		float num, max = 0;
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