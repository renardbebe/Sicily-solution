template <typename T>
int binarySearch(T array[], T key, int arraySize){
	int start = 0, end = arraySize, mid;
    while (start <= end) {
        mid = (start + end)/2;
        if (key > array[mid]) {
            start = mid+1;
            continue;
        }
		else if (key < array[mid]){
            end = mid-1;
            continue;
        }
		else return mid;
    }
    return -1;
} 
