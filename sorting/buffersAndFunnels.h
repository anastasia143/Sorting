#pragma once
#include <QList>

class Funnel
{

};

class Buffer
{
public:
	Buffer(Funnel* out = NULL, Funnel* in = NULL)
	{
		output = out;
		input = in;
	}
	Funnel* output;
	Funnel* input;
	QList<int> list;
};
