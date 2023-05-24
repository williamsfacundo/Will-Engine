#ifndef CUBE_H
#define CUBE_H

#include "Objects/object.h"

namespace WillEngine
{
	class Cube : public Object
	{
	protected:
		void setData();

	public:
		Cube();
		~Cube();

		int getAmountOfIndexes();
	};
}

#endif