#include <iostream>

int main()
{
	ServiceLocator locator;
	locator.RegisterService<IService>(new Service());
	IService* service = locator.GetService<IService>();
	service->DoSomething();
	return 0;
}