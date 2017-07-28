template <typename T>
T maximumValue (const T array[], const int size)
{
	T maxn = array[0];
	for(int i = 1; i < size; i++)
	{
		if(maxn < array[i]) maxn = array[i];
	}
	return maxn;
}
 
template <typename T>
T minimumValue (const T array[], const int size)
{
	T minn = array[0];
	for(int i = 1; i < size; i++)
	{
		if(minn > array[i]) minn = array[i];
	}
	return minn;
}
 
template <typename T>
T medianValue (const T array[], const int size)
{
	T a[size];	
	for(int i = 0; i < size; i++)
		a[i] = array[i];
	
	for(int i = 0; i < size; i++)
	{
		for(int j = i+1; j < size; j++)
		{
			if(a[i] > a[j])
			{
				T t = a[j];
				a[j] = a[i];
				a[i] = t;
			}
		}
	}
	return a[int(size/2)];
}
