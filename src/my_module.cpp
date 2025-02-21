export module my_first_module;
import std;

export namespace something
{

std::string hello(std::string name)
{
	return "Hello, " + name + '!';
}	

} // end namespace something
