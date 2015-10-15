class SealedClass1{
public:
	static SealedClass1* GetInstance()
	{
		return new SealedClass1();
	}
	static void DeleteInstance(SealedClass1* pInstance)
	{
		delete pInstance;
	}
private:
	SealedClass1(){}
	~SealedClass1(){}
	};
