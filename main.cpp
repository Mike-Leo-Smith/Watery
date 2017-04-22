#include <iostream>

struct Magic
{
	Magic(char ch_) : ch(ch_) {}
	~Magic()
	{
		std::cout << ch;
	}
	char ch;
};

void haha(std::unique_ptr<Magic> &ptr)
{
	std::cout << 'a';
	ptr.reset(new Magic('b'));
}

int main()
{
	auto p = std::make_unique<Magic>('c');
	haha(p);
	std::cout << 'd';
	return 0;
}


