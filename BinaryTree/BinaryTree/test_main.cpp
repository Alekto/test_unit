#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <boost/unordered_map.hpp> //C:\Program Files\Boost\boost_1_39_0\boost\unordered

#include "binary_tree.hpp"

using namespace algoritms;

int main(int argc, char **argv)
{

	boost::unordered_map<int, int> tempUnordererMap;
	tempUnordererMap[0] = 0;

	//std::map<int, int> tempMap;
	//tempMap[5] = 5;
	//std::map<int, int>::iterator mapBeginIt = tempMap.begin();
	//std::map<int, int>::iterator mapEndIt = tempMap.end();

	//tempMap[10] = 10;
	//mapBeginIt = tempMap.begin();
	//mapEndIt = tempMap.end();

	//tempMap[6] = 6;
	//mapBeginIt = tempMap.begin();
	//mapEndIt = tempMap.end();

	//tempMap[3] = 3;
	//mapBeginIt = tempMap.begin();
	//mapEndIt = tempMap.end();

	//tempMap[4] = 4;
	//mapBeginIt = tempMap.begin();
	//mapEndIt = tempMap.end();


	{
		//algoritms::binaryTree<int, algoritms::details::node > bt;				
		//algoritms::binaryTree<int, algoritms::details::node<int> > bt;		
		algoritms::binaryTree<int> bt;											

		bt.insert(3);
		bt.insert(1);
		bt.insert(2);
		bt.insert(4);
		bt.insert(10);
		bt.insert(5);

		bt.getRoot();
	}

	{
		algoritms::binaryTree<std::string> bt;
		bt.insert("jiiu");
		bt.insert("ghfh fhh");
		bt.insert("fhhf gghfs");
		bt.insert("todo dghh");
		bt.insert("todo drty");
		bt.insert("todo eh fhdn");
		bt.insert("tudo dhgfh");

		bt.empty();
		bt.size();


		//algoritms::binaryTree<std::string>::iterator;

	}

	std::cout << "press ENTER to exit..." << std::endl;

	std::cin.sync();
	std::cin.get();
	return 0;
}
