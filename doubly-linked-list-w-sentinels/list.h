class List{
	public:
	virtual void print() = 0;
	virtual void addHead(int num) = 0;
	virtual void addTail(int num) = 0;
	virtual void addAt(int num,int pos) = 0;
	virtual int removeHead() = 0;
	virtual int removeTail() = 0;
	virtual int removeAt(int pos) = 0;
	virtual int removeNum(int num) = 0;
	virtual int clearList() = 0;
	virtual void rotate(int num) = 0;
};
