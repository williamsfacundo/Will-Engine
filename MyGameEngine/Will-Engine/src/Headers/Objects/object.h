#ifndef OBJECT_H
#define OBJECT_H

namespace WillEngine
{
	class Object
	{
	private:
		unsigned int _vertexArray;

	public:
		Object();
		~Object();

		void createObject();

		void selectObject();
	};
}

#endif