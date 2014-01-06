// Filename: MethodType.cpp
#include "MethodType.h"
#include "HashGenerator.h"
#include "Parameter.h"
using namespace std;
namespace dclass   // open namespace
{


// constructor
MethodType::MethodType()
{
	m_type = METHOD;
}

// destructor
MethodType::~MethodType()
{
	for(auto it = m_parameters.begin(); it != m_parameters.end(); ++it)
	{
		delete(*it);
	}
	m_parameters.clear();
}

// as_method returns this as a MethodType if it is a method, or NULL otherwise.
MethodType* MethodType::as_method()
{
	return this;
}
const MethodType* MethodType::as_method() const
{
	return this;
}

// add_parameter adds a new parameter to the method.
bool MethodType::add_parameter(Parameter *param)
{
	// Try to add the parameter
	bool inserted = m_parameters_by_name.insert(
		unordered_map<string, Parameter*>::value_type(param->get_name(), param)).second;
	if(!inserted)
	{
		// But the parameter had a name conflict
		return false;
	}

	// Add the parameter to the main list
	param->set_method(this);
	m_parameters.push_back(param);

	// Update our size
	if(has_fixed_size() || m_parameters.size() == 1)
	{
		if(param->get_type()->has_fixed_size())
		{
			m_size += param->get_type()->get_size();
		}
		else
		{
			m_size = 0;
		}
	}
}

// generate_hash accumulates the properties of this method into the hash
void MethodType::generate_hash(HashGenerator& hashgen) const
{
	DistributedType::generate_hash(hashgen);
	hashgen.add_int(m_parameters.size());
	for(auto it = m_parameters.begin(); it != m_parameters.end(); ++it)
	{
		(*it)->generate_hash(hashgen);
	}
}


} // close namespace dclass
