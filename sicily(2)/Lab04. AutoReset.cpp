
AutoReset::AutoReset(int *scoped_variable, int new_value)
{
    original_value = *scoped_variable;
    scoped_variable_ = scoped_variable;
    *scoped_variable_ = new_value; 
}

AutoReset::~AutoReset()
{
    *scoped_variable_ = original_value;
}                                 
