#include<iostream>

#include"Singleton/Singleton.h"
#include"Prototype/Prototype.h"
#include"FactoryMethod/FactoryMethod.h"
#include"AbstractFactory/AbstractFactory.h"
#include"Builder/Builder.h"

#include"Adapter/Adapter.h"
#include"Bridge/Bridge.h"
#include"Composite/Composite.h"
#include"Decorator/Decorator.h"
#include"Proxy/Proxy.h"
#include"Facade/Facade.h"
#include"Flyweight/Flyweight.h"

#include"Iterator/Iterator.h"
#include"Command/Command.h"
#include"ChainOfResponsibility/ChainOfResponsibility.h"
#include"Mediator/Mediator.h"

namespace SingletonNamespace {

	void ThreadFunc1()
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(900));
		Singleton* singleton = Singleton::GetInctance("Func1");
		std::cout << singleton->value() << std::endl;
	}

	void ThreadFunc2()
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		Singleton* singleton = Singleton::GetInctance("Func2");
		std::cout << singleton->value() << std::endl;
	}

	void SingletonMain()
	{
		std::cout << "Singleton Main test: \n";

		std::thread t1(ThreadFunc1);
		std::thread t2(ThreadFunc2);

		t1.join();
		t2.join();
	}
}
namespace PrototypeNamespace {
	
	void Client(PrototypeFactory& prototypeFactory)
	{
		std::cout << "Prototype Main test: \n\n";

		std::cout << "Let's create a Prortotype 1 \n";

		Prototype* prototype = prototypeFactory.CreatePrototype(Type::PROTOTYPE_1);
		prototype->Method(110);
		
		delete prototype;

		std::cout << std::endl;
		std::cout << "Let's create a Prortotype 2 \n";

		prototype = prototypeFactory.CreatePrototype(Type::PROTOTYPE_2);
		prototype->Method(30);

		delete prototype;
	}

	void PrototypeMain()
	{
		PrototypeFactory* prototypeFactory = new PrototypeFactory();
		Client(*prototypeFactory);

		delete prototypeFactory;
	}
}
namespace FactoryMethodNamespace {
	
	void ClientCode(const Creator& creator)
	{
		std::cout << "Client: I'm not aware of the creator's class, but it still work.\n"
			<< creator.SomeOperation() << std::endl;
	}

	void FactoryMethodMain() 
	{
		std::cout << "Factory Method Main test: \n\n";

		std::cout << "App : Launched with the ConcreteCreator1.\n";
		Creator* creator = new ConcreteCreator1();
		ClientCode(*creator);

		std::cout << std::endl;
		
		std::cout << "App : Launched with the ConcreteCreator2.\n";
		Creator* creator2 = new ConcreteCreator2();
		ClientCode(*creator2);

		delete creator;
		delete creator2;
	}
}
namespace AbstractFactoryNamespace {
	
	void ClientCode(const AbstractFactory &factory)
	{
		const AbstractProductA* product_a = factory.CreateProductA();
		const AbstractProductB* product_b = factory.CreateProductB();

		std::cout << product_b->UsefulFunctionB() << std::endl;
		std::cout << product_b->AnotherUsefulFunctionB(*product_a) << std::endl;
		std::cout << std::endl;

		delete product_a;
		delete product_b;
	}

	void AbstractFactoryMain() 
	{
		std::cout << "Abstract Factory Main test: \n\n";

		std::cout << "Client: Testing client code with the first factory type:\n";
		ConcreteFactory1* f1 = new ConcreteFactory1();
		ClientCode(*f1);
		delete f1;

		std::cout << "Client: Testing the same client code with second factory type:\n";
		ConcreteFactory2* f2 = new ConcreteFactory2();
		ClientCode(*f2);
		delete f2;
	}
}
namespace BuilderNamespace {
	
	void ClientCode(Director& director)
	{
		ConcreteBuilder1* builder = new ConcreteBuilder1();
		director.set_builder(builder);

		std::cout << "Standart basic product:\n";
		director.BuildMinimalViableProduct();

		Product1* p = builder->GetProduct();
		p->ListParts();
		delete p;

		std::cout << "Standart full featured product:\n";
		director.BuildFullFeaturedProduct();

		p = builder->GetProduct();
		p->ListParts();
		delete p;

		std::cout << "Custom product:\n";
		
		builder->ProducePartA();
		builder->ProducePartZ();
		p->ListParts();
		delete p;

		delete builder;
	}

	void BuilderMain()
	{
		std::cout << "Builder Main test: \n\n";

		Director* director = new Director();
		ClientCode(*director);
		delete director;
	}
}

namespace AdapterNamespace {
	
	void ClientCode(const Target *target)
	{
		std::cout << target->Request();
	}

	void AdapterMain()
	{
		std::cout << "Adapter Main test: \n\n";

		std::cout << "Client: I can work just fine with the Target objects:\n";
		
		Target* target = new Target;
		ClientCode(target);

		std::cout << "\n\n";

		Adaptee* adaptee = new Adaptee;
		std::cout << "Client: The Adaptee class gas weird interface. See, i'dont understand:\n";
		std::cout << "Adaptee: " << adaptee->SpecificRequest();
		std::cout << "\n\n";

		std::cout << "Client: But I can work with it via the Adapter:\n";
		Adapter* adapter = new Adapter(adaptee);
		ClientCode(adapter);
		std::cout << std::endl;

		delete target;
		delete adaptee;
		delete adapter;
	}
}
namespace BridgeNamespace {
	
	void ClientCode(const Abstraction& abstraction)
	{
		///...
	
		std::cout << abstraction.Operation();

		///...
	}

	void BridgeMain()
	{
		std::cout << "Bridge Main test: \n\n";

		Implementation* implementation = new ConcreteImplementationA;
		Abstraction* abstraction = new Abstraction(implementation);
		ClientCode(*abstraction);

		std::cout << std::endl;

		delete implementation;
		delete abstraction;

		implementation = new ConcreteImplementationB;
		abstraction = new ExtendAbstraction(implementation);
		ClientCode(*abstraction);

		delete implementation;
		delete abstraction;
	}
}
namespace CompositeNamespace{
	
	void ClientCode(Component* component)
	{
		///...

		std::cout << "RESULT: " << component->Operation();	

		///...
	}

	void ClientCode2(Component* component1, Component* component2)
	{
		///...

		if (component1->IsComposite())
		{
			component1->Add(component2);
		}

		std::cout << "RESULT: " << component1->Operation();

		///...
	}

	void CompositeMain()
	{
		std::cout << "Composite Main test: \n\n";

		Component* simple = new Leaf;
		std::cout << "Client: I've got a simple component: \n";
		ClientCode(simple);

		std::cout << "\n\n";

		Component* tree = new Composite;
		Component* branch1 = new Composite;

		Component* leaf_1 = new Leaf;
		Component* leaf_2 = new Leaf;
		Component* leaf_3 = new Leaf;

		branch1->Add(leaf_1);
		branch1->Add(leaf_2);

		Component* branch2 = new Composite;
		branch2->Add(leaf_3);

		tree->Add(branch1);
		tree->Add(branch2);

		std::cout << "Client: Now I've got a composite tree:\n";
		ClientCode(tree);
		std::cout << "\n\n";

		std::cout << "Client: I don't need to check the components classes even when managing\n";
		ClientCode2(tree, simple);
		std::cout << std::endl;

		delete simple;
		delete tree;
		
		delete branch1;
		delete branch2;

		delete leaf_1;
		delete leaf_2;
		delete leaf_3;
	}
}
namespace DecoratorNamespace
{
	void ClientCode(Component* component)
	{
		///...
		
		std::cout << "RESULT: " << component->Operation();

		///...
	}

	void DecoratorMain()
	{
		std::cout << "Decorator Main test: \n\n";

		Component* simple = new ConcreteComponent;
		std::cout << "Client: I've got a simple component:\n";
		
		ClientCode(simple);
		std::cout << "\n\n";

		Component* decorator1 = new ConcreteDecoratorA(simple);
		Component* decorator2 = new ConcreteDecoratorB(decorator1);

		std::cout << "Client: Now I've got a decorated component:\n";
		ClientCode(decorator2);
		std::cout << std::endl;

		delete simple;
		delete decorator1;
		delete decorator2;
	}
}
namespace ProxyNamespace {

	void ClientCode(const Subject& subject)
	{
		///...

		subject.Request();

		///...
	}

	void ProxyMain()
	{
		std::cout << "Proxy Main test: \n\n";

		std::cout << "Client: Executing the client code with a real subject:\n";
		RealSubject* realSubject = new RealSubject;
		ClientCode(*realSubject);

		std::cout << std::endl;
		std::cout << "Client: Exucting the same client code with a proxy:\n";

		Proxy* proxy = new Proxy(realSubject);
		ClientCode(*proxy);

		delete realSubject;
		delete proxy;
	}
}
namespace FacadeNamespace {
	
	void ClientCode(Facade* facade)
	{
		///...

		std::cout << facade->Operation();

		///...
	}

	void FacadeMain()
	{
		std::cout << "Facade Main test: \n\n";

		Subsystem1* subsystem1 = new Subsystem1;

		Facade* facade = new Facade(subsystem1);
		ClientCode(facade);

		delete facade;
	}
}
namespace FlyweightNamespace{

	void AddCarToPoliceDatabase( 
		FlyweightFactory& ff, 
		const std::string& plates, const std::string& owner,
		const std::string& brand , const std::string& model,
		const std::string& color)
	{
		std::cout << "\nClient: Adding a car to database.\n";
		
		const Flyweight& flyweight = ff.GetFlyweight({ brand, model, color });
		flyweight.Operation({ owner, plates });

		std::cout << "\n";
	}

	void FlyweightMain()
	{
		std::cout << "Flyweight Main test: \n\n";

		FlyweightFactory* factory = new FlyweightFactory
		(
			{
				{"Chevrolet", "Camaro228", "Pink"},
				{"Mercedec Benz", "C300", "Black"},
				{"Mercedec Benz", "C500", "White"},
				{"BMW", "M5", "Red"},
				{"BMW", "X6", "Yellow"}
			}
		);

		AddCarToPoliceDatabase(
			*factory,
			"CL243IR", "James Doe", 
			"BMW", "M5", "Red"
		);

		AddCarToPoliceDatabase(
			*factory,
			"CL243IR", "James Doe",
			"BMW", "X1", "Yellow"
		);

		
		factory->ListFlyweights();

		delete factory;
	}
}

namespace IteratorNamespace
{
	void ClientCode()
	{
		std::cout << "Iterator with int: \n";
		Container<int> cont;

		for (int i = 0; i < 10; i++)
		{
			cont.Add(i);
		}

		Iterator<int, Container<int>>* it = cont.CreateIterator();
		
		for (it->First(); !it->IsDone(); it->Next())
		{
			std::cout << *it->Current() << std::endl;
		}

		std::cout << "\nIterator with custom Class: \n";

		Container<Data> cont2;
		Data a(100), b(1000), c(10000);
		
		cont2.Add(a);
		cont2.Add(b);
		cont2.Add(c);

		Iterator<Data, Container<Data>>* it2 = cont2.CreateIterator();

		for (it2->First(); !it2->IsDone(); it2->Next())
		{
			std::cout << it2->Current()->data() << std::endl;
		}

		delete it;
		delete it2;
	}

	void IteratorMain()
	{
		std::cout << "Iterator Main test: \n\n";

		ClientCode();
	}
}
namespace CommandNamespace {
	/*
		The client code can parameterize the sender with any commands.
	*/

	void CommandMain()
	{
		std::cout << "Command Main test: \n\n";

		Invoker* invoker = new Invoker;
		invoker->SetOnStart(new SimpleCommand("Say Hi!"));

		Receiver* receiver = new Receiver;
		invoker->SetOnFinish(new ComplexCommand(receiver, "Send email", "Save report"));

		invoker->DoSomethingImportant();

		delete invoker;
		delete receiver;
	}
}
namespace ChainOfResponsibilityNamespace{
	
	#include<vector>

	void ClientCode(Handler& handler)
	{
		std::vector<std::string> food = { "Nut", "Banana", "Cup of Tea" };

		for (const std::string& f : food)
		{
			std::cout << "Client: Who wants a " << f << "?\n";

			const std::string result = handler.Handle(f);

			if (!result.empty())
			{
				std::cout << " " << result;
			}
			else
			{
				std::cout << " " << f << " was left untouched.\n";
			}
		}
	}

	void ChainOfResponsibilityMain()
	{
		std::cout << "Chain of Responsibility Main test: \n\n";

		MonkeyHandler* monkey = new MonkeyHandler;
		SquirrelHandler* squirrel = new SquirrelHandler;
		DogHandler* dog = new DogHandler;

		monkey->SetNext(squirrel)->SetNext(dog);

		std::cout << "Chain: Monkey > Squirrel > Dog\n\n";
		ClientCode(*monkey);
		
		std::cout << "\n";
		std::cout << "Subchain: Squirrel > Dog\n\n";

		ClientCode(*squirrel);

		delete monkey;
		delete squirrel;
		delete dog;
	}
}
namespace MediatorNamespace{
	
	void ClientCode()
	{
		Component1* c1 = new Component1;
		Component2* c2 = new Component2;

		ConcreteMediator* mediator = new ConcreteMediator(c1, c2);
		
		std::cout << "Client triggers operation A.\n";
		c1->DoA();

		std::cout << "\n";
		std::cout << "Client triggers operation D.\n";
		c2->DoD();

		delete c1;
		delete c2;
		delete mediator;
	}

	void MediatorMain()
	{
		std::cout << "Mediator Main test: \n\n";
		
		ClientCode();
	}
}

int main()
{
	int index;

	std::cout << "Enter index of Pattern variants':\n\n";
	
	std::cout << "Creational Design Patterns:\n";
	std::cout << "Singelton : 0 \n";
	std::cout << "Prototype : 1 \n";
	std::cout << "FactoryMethod : 2 \n";
	std::cout << "AbstractFactory : 3 \n";
	std::cout << "Builder : 4 \n\n";

	std::cout << "Structural Design Patterns:\n";
	std::cout << "Adapter : 5 \n";
	std::cout << "Bridge : 6 \n";
	std::cout << "Composite : 7 \n";
	std::cout << "Decorator : 8 \n";
	std::cout << "Proxy : 9 \n";
	std::cout << "Facade : 10 \n";
	std::cout << "Flyweight : 11 \n\n";

	std::cout << "Behavioral Design Patterns:\n";
	std::cout << "Iterator : 12 \n";
	std::cout << "Command : 13 \n";
	std::cout << "ChainOfResponsibility : 14 \n";
	std::cout << "Mediator : 15 \n";


	std::cout << std::endl;
	std::cin >> index;
	std::cout << std::endl;

	switch (index) {
		case 0 : SingletonNamespace::SingletonMain();
			break;
		case 1 : PrototypeNamespace::PrototypeMain();
			break;
		case 2: FactoryMethodNamespace::FactoryMethodMain();
			break;
		case 3: AbstractFactoryNamespace::AbstractFactoryMain();
			break;
		case 4: AbstractFactoryNamespace::AbstractFactoryMain();
			break;
		case 5: AdapterNamespace::AdapterMain();
			break;
		case 6: BridgeNamespace::BridgeMain();
			break;
		case 7: CompositeNamespace::CompositeMain();
			break;
		case 8: DecoratorNamespace::DecoratorMain();
			break;
		case 9: ProxyNamespace::ProxyMain();
			break;
		case 10: FacadeNamespace::FacadeMain();
			break;
		case 11: FlyweightNamespace::FlyweightMain();
			break;
		case 12: IteratorNamespace::IteratorMain();
			break;
		case 13: CommandNamespace::CommandMain();
			break;
		case 14: ChainOfResponsibilityNamespace::ChainOfResponsibilityMain();
			break;
		case 15: MediatorNamespace::MediatorMain();
			break;
		default :
			std::cout << "Try again encorrected index\n";
	}
	return 0;
}


