
class Direct
{
public:
	enum direct
	{
		left=0,up=1,down=3,right=4
	};
private:
	direct d;
public:
	Direct():d(left){}
	Direct(direct di):d(di){}

	void operator=(Direct dir)
	{
		if(d != 4 - dir.d)
			d = dir.d;
	}
};

int main()
{
	Direct a;
	a = Direct::up;
	a = Direct::down;

	return 0;
}

